from ctypes import *

from video.NvrBase import NvrBase
from video.RealPlayer import RealPlayerForm, PtzDir


# 登录用的结构体
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


# 实时播放的数据结构
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
        self.userSession = 1 + self.nvrDll.NET_DVR_Login_V30(
            c_char_p(self.nvrIp.encode('ascii')),
            self.nvrPort,
            c_char_p(self.nvrLogin.encode('ascii')),
            c_char_p(self.nvrPass.encode('ascii')),
            byref(dvrInfo)
        )
        return self.userSession

    # 实时播放
    def real_play(self, cha):
        vf = RealPlayerForm(parent=self.wxApp, title="实时预览")
        vf.Show()

        vf.nvr = self
        vf.channel = cha
        vf.nvrId = self.nvrId
        vf.mgr = self.mgr
        playInfo = NetDvrPreviewInfo()
        playInfo.hPlayWnd = vf.GetHandle()
        playInfo.lChannel = cha
        vf.previewSession = 1 + self.nvrDll.NET_DVR_RealPlay_V40(self.userSession - 1, byref(playInfo), None, None)
        # 添加到窗口列表
        vf.AddToWindowList()

    # 实时播放停止
    def real_play_stop(self, previewSession):
        self.nvrDll.NET_DVR_StopRealPlay(previewSession - 1)

    # 云台控制
    def ptz_start(self, cha, direction):
        dcode = 0
        if direction == PtzDir.UP:
            dcode = 21
        elif direction == PtzDir.RIGHT:
            dcode = 24
        elif direction == PtzDir.DOWN:
            dcode = 22
        elif direction == PtzDir.LEFT:
            dcode = 23
        elif direction == PtzDir.UP_RIGHT:
            dcode = 26
        elif direction == PtzDir.DOWN_RIGHT:
            dcode = 28
        elif direction == PtzDir.DOWN_LEFT:
            dcode = 27
        elif direction == PtzDir.UP_LEFT:
            dcode = 25

        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, dcode, 0, 3)

    # 云台控制停止
    def ptz_stop(self, cha):
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 21, 1, 1);
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 22, 1, 1);
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 23, 1, 1);
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 24, 1, 1);
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 25, 1, 1);
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 26, 1, 1);
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 27, 1, 1);
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 28, 1, 1);

    # 变焦
    def zoom(self, cha, direction):

        if direction > 0:
            self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 11, 0, 7)
        else:
            self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 12, 0, 7)

        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 11, 1, 7)
        self.nvrDll.NET_DVR_PTZControlWithSpeed_Other(self.userSession - 1, cha, 12, 1, 7)

    # PTZ 调用
    def goPtz(self, cha, ptz):
        self.nvrDll.NET_DVR_PTZPreset_Other(self.userSession - 1, cha, 39, ptz)
