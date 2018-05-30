'''
NVR 管理类，基类
'''


class NvrBase:
    # 初始化过程
    def __init__(self):
        self.app = None
        self.nvrDll = None
        self.session = -1
        self.nvrName = None
        self.nvrIp = None
        self.nvrPort = 0
        self.nvrLogin = None
        self.nvrPass = None

    # 登录
    def login(self):
        pass

    # 实时播放
    def real_play(self, cha):
        pass

    # 实时播放停止
    def real_play_stop(self, session):
        pass

    # 云台控制
    def ptz_start(self, cha, direction, speed):
        pass

    # 云台控制停止
    def ptz_stop(self, cha):
        pass

    # 变焦
    def zoom(self, cha, direction):
        pass
