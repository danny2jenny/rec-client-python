'''
宇视接口，未完成
'''

from _ctypes import Structure, byref
from ctypes import c_int, c_ubyte, c_char_p, c_void_p

from video.NvrBase import NvrBase
from video.RealPlayer import RealPlayerForm, PtzDir


# 登录返回的结构
class tagNETDEVDeviceInfo(Structure):
    _fields_ = [
        ('dwDevType', c_int),
        ('wAlarmInPortNum', c_ubyte * 2),
        ('wAlarmOutPortNum', c_ubyte * 2),
        ('dwChannelNum', c_int),
        ('Reserved', c_ubyte * 48),
    ]


# 实时播放结构

class NETDEV_PREVIEWINFO_S(Structure):
    _fields_ = [
        ('dwChannelID', c_int),
        ('dwStreamType', c_int),
        ('dwLinkMode', c_int),
        ('hPlayWnd', c_void_p),
        ('dwFluency', c_int),
        ('Reserved', c_ubyte * 260),
    ]


class NvrYS(NvrBase):

    # 登录
    def login(self):
        loginfo = tagNETDEVDeviceInfo()
        self.nvrDll.NETDEV_Login(
            c_char_p(self.nvrIp.encode('ascii')),
            self.nvrPort,
            c_char_p(self.nvrLogin.encode('ascii')),
            c_char_p(self.nvrPass.encode('ascii')),
            byref(loginfo)
        )

        print("宇视：", self.userSession)

    # 实时播放
    def real_play(self, cha):
        vf = RealPlayerForm(parent=self.wxApp, title="实时预览")
        vf.Show()
        vf.nvr = self
        vf.channel = cha

        playInfo = NETDEV_PREVIEWINFO_S()
        playInfo.dwChannelID = cha
        playInfo.hPlayWnd = vf.GetHandle()

        vf.previewSession = self.nvrDll.NETDEV_RealPlay(
            self.userSession,
            byref(playInfo),
            None,
            None
        )

    # 实时播放停止
    def real_play_stop(self, previewSession):
        self.nvrDll.NETDEV_StopRealPlay(previewSession)

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
        self.nvrDll.NETDEV_PTZControl_Other(self.userSession, cha - 1, dcode, 0, 4, 0, bool(0), None)

    # 云台控制停止
    def ptz_stop(self, cha):
        self.nvrDll.CLIENT_DHPTZControlEx2(self.userSession, cha - 1, 34, 0, 4, 0, bool(1), None)

    # 变焦
    def zoom(self, cha, direction):
        if direction > 0:
            self.nvrDll.NETDEV_PTZSelZoomIn(self.userSession, cha - 1, 4, 0, 8, 0, bool(0), None)
        else:
            self.nvrDll.NETDEV_PTZSelZoomIn(self.userSession, cha - 1, 5, 0, 8, 0, bool(0), None)

        self.nvrDll.NETDEV_PTZSelZoomIn(self.userSession, cha - 1, 5, 0, 8, 0, bool(1), None)

    # PTZ 调用
    def goPtz(self, cha, ptz):
        self.nvrDll.NETDEV_PTZPreset_Other(self.userSession, cha - 1, 10, 0, ptz, 0, bool(0), None)
