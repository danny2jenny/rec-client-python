'''
大华 NVR 接口
'''
from _ctypes import Structure, byref
from ctypes import c_ubyte, c_int, c_char_p, c_bool

from video.NvrBase import NvrBase
from video.RealPlayer import RealPlayerForm, PtzDir


class NET_DEVICEINFO_Ex(Structure):
    _fields_ = [
        ('sSerialNumber', c_ubyte * 48),
        ('nAlarmInPortNum', c_int),
        ('nAlarmOutPortNum', c_int),
        ('nDiskNum', c_int),
        ('nDVRType', c_int),
        ('nChanNum', c_int),
        ('byLimitLoginTime', c_ubyte),
        ('byLeftLogTimes', c_ubyte),
        ('bReserved', c_ubyte * 2),
        ('nLockLeftTime', c_int),
        ('Reserved', c_ubyte * 24),
    ]


'''
NVR 管理类
'''


class NvrDH(NvrBase):

    # 登录
    def login(self):
        loginfo = NET_DEVICEINFO_Ex()
        err = NET_DEVICEINFO_Ex()
        self.session = self.nvrDll.CLIENT_LoginEx2(
            c_char_p(self.nvrIp.encode('ascii')),
            self.nvrPort,
            c_char_p(self.nvrLogin.encode('ascii')),
            c_char_p(self.nvrPass.encode('ascii')),
            0,
            None,
            byref(loginfo),
            byref(err)
        )
        print("大华：", self.session)

    # 实时播放
    def real_play(self, cha):
        vf = RealPlayerForm(parent=self.app, title="实时预览")
        vf.Show()
        vf.nvr = self
        vf.channel = cha
        vf.session = self.nvrDll.CLIENT_RealPlay(
            self.session,
            cha - 1,
            vf.GetHandle()
        )
        print("大华实时Session：", vf.session)

    # 实时播放停止
    def real_play_stop(self, session):
        self.nvrDll.CLIENT_StopRealPlay(session)

    # 云台控制
    '''
    BOOL CLIENT_DHPTZControlEx2(  
        LLONG lLoginID,             // Long
        int   nChannelID,           // Long
        DWORD dwPTZCommand,         // Long
        LONG  lParam1,  
        LONG  lParam2,  
        LONG  lParam3,
        BOOL  dwStop,  
        void* param4 = NULL 
    );
    '''

    def ptz_start(self, cha, direction):
        dcode = 0
        if direction == PtzDir.UP:
            dcode = 0
        elif direction == PtzDir.RIGHT:
            dcode = 3
        elif direction == PtzDir.DOWN:
            dcode = 1
        elif direction == PtzDir.LEFT:
            dcode = 2
        elif direction == PtzDir.UP_RIGHT:
            dcode = 33
        elif direction == PtzDir.DOWN_RIGHT:
            dcode = 35
        elif direction == PtzDir.DOWN_LEFT:
            dcode = 34
        elif direction == PtzDir.UP_LEFT:
            dcode = 32
        self.nvrDll.CLIENT_DHPTZControlEx2(self.session, cha - 1, dcode, 0, 4, 0, bool(0), None)
        print("PTZ 控制")

    # 云台控制停止
    def ptz_stop(self, cha):
        self.nvrDll.CLIENT_DHPTZControlEx2(self.session, cha - 1, 34, 0, 4, 0, bool(1), None)

    # 变焦
    def zoom(self, cha, direction):
        if direction > 0:
            self.nvrDll.CLIENT_DHPTZControlEx2(self.session, cha - 1, 4, 0, 8, 0, bool(0), None)
        else:
            self.nvrDll.CLIENT_DHPTZControlEx2(self.session, cha - 1, 5, 0, 8, 0, bool(0), None)

        self.nvrDll.CLIENT_DHPTZControlEx2(self.session, cha - 1, 5, 0, 8, 0, bool(1), None)

    # PTZ 调用
    def goPtz(self, cha, ptz):
        self.nvrDll.CLIENT_DHPTZControlEx2(self.session, cha - 1, 10, 0, ptz, 0, bool(0), None)
