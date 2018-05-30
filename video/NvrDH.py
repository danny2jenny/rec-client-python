'''
大华 NVR 接口
'''
from _ctypes import Structure, byref
from ctypes import c_ubyte, c_int, c_char_p

from video.NvrBase import NvrBase
from video.RealPlayer import RealPlayerForm


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
    def ptz_start(self, cha, direction, speed):
        pass

    # 云台控制停止
    def ptz_stop(self, cha):
        pass

    # 变焦
    def zoom(self, cha, direction):
        pass
