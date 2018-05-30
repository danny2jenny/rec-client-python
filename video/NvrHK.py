from ctypes import *

from video.NvrBase import NvrBase
from video.RealPlayer import RealPlayerForm

'''
登录用的结构体
'''


class NetDvrDeviceInfoV30(Structure):
    _fields_ = [
        ('sSerialNumber', c_ubyte * 48),
        ('byAlarmInPortNum', c_ubyte),
        ('byAlarmOutPortNum', c_ubyte),
        ('byDiskNum', c_ubyte),
        ('byDVRType', c_ubyte),
        ('byChanNum', c_ubyte),
        ('byStartChan', c_ubyte),
        ('byAudioChanNum', c_ubyte),
        ('byIPChanNum', c_ubyte),
        ('byZeroChanNum', c_ubyte),
        ('byMainProto', c_ubyte),
        ('bySubProto', c_ubyte),
        ('bySupport', c_ubyte),
        ('bySupport1', c_ubyte),
        ('bySupport2', c_ubyte),
        ('wDevType', c_ushort),
        ('bySupport3', c_ubyte),
        ('byMultiStreamProto', c_ubyte),
        ('byStartDChan', c_ubyte),
        ('byStartDTalkChan', c_ubyte),
        ('byHighDChanNum', c_ubyte),
        ('bySupport4', c_ubyte),
        ('byLanguageType', c_ubyte),
        ('byVoiceInChanNum', c_ubyte),
        ('byStartVoiceInChanNo', c_ubyte),
        ('bySupport5', c_ubyte),
        ('bySupport6', c_ubyte),
        ('byMirrorChanNum', c_ubyte),
        ('wStartMirrorChanNo', c_ushort),
        ('bySupport7', c_ubyte),
        ('byRes2', c_ubyte),
    ]


'''
实时播放的数据结构
'''


class NetDvrPreviewInfo(Structure):
    _fields_ = [
        ('lChannel', c_int),
        ('dwStreamType', c_uint),
        ('dwLinkMode', c_uint),
        ('hPlayWnd', c_void_p),
        ('bBlocked', c_uint),
        ('bPassbackRecord', c_uint),
        ('byPreviewMode', c_ubyte),
        ('byStreamID', c_ubyte * 32),
        ('byProtoType', c_ubyte),
        ('byRes1', c_ubyte),
        ('byVideoCodingType', c_ubyte),
        ('dwDisplayBufNum', c_uint),
        ('byRes2', c_ubyte * 216),
    ]


'''
NVR 管理类
'''


class NvrHK(NvrBase):

    # 登录
    def login(self):
        dvrInfo = NetDvrDeviceInfoV30()
        self.session = 1 + self.nvrDll.NET_DVR_Login_V30(
            c_char_p(self.nvrIp.encode('ascii')),
            self.nvrPort,
            c_char_p(self.nvrLogin.encode('ascii')),
            c_char_p(self.nvrPass.encode('ascii')),
            byref(dvrInfo)
        )

    # 实时播放
    def real_play(self, cha):
        vf = RealPlayerForm(parent=self.app, title="实时预览")
        vf.Show()
        vf.nvr = self
        playInfo = NetDvrPreviewInfo()
        playInfo.hPlayWnd = vf.GetHandle()
        playInfo.lChannel = cha
        vf.session = 1 + self.nvrDll.NET_DVR_RealPlay_V40(self.session - 1, byref(playInfo), None, None)

    # 实时播放停止
    def real_play_stop(self, session):
        self.nvrDll.NET_DVR_StopRealPlay(session - 1)

    # 云台控制
    def ptz_start(self, cha, direction, speed):
        pass

    # 云台控制停止
    def ptz_stop(self, cha):
        pass

    # 变焦
    def zoom(self, cha, direction):
        pass
