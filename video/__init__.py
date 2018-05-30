'''
全部的外部Dll 在这里加载
'''

from ctypes import WinDLL

from video.NvrDH import NvrDH
from video.NvrHK import NvrHK

_vide_dll_ = dict()


# 加载 DLL
def LoadDll():
    global _vide_dll_
    _vide_dll_[2001] = WinDLL('HCNetSDK.dll')
    _vide_dll_[2002] = WinDLL('dhnetsdk.dll')


# 返回 DLL 对象
def GetNvrDll(id):
    if _vide_dll_.__contains__(id):
        return _vide_dll_[id]
    else:
        return None


# 类工厂，返回Nvr的操作对象
def GreateVideoObj(id):
    if id == 2001:
        return NvrHK()
    elif id == 2002:
        return NvrDH()
    else:
        return None


# 初始化所有的DLL
def InitDlls():
    for k in _vide_dll_:
        if k == 2001:
            _vide_dll_[k].NET_DVR_Init()
        elif k == 2002:
            _vide_dll_[k].CLIENT_Init(None, None)


# 清理所有的DLL
def CleanDlls():
    for k in _vide_dll_:
        if k == 2001:
            _vide_dll_[k].NET_DVR_Cleanup()
        elif k == 2002:
            _vide_dll_[k].CLIENT_Cleanup()
