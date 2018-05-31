'''
视频播放管理器
nvrs 存放所有的NVR配置
'''

import json
import threading

import video

'''
线程定时器
'''


class ThreadTimer(threading.Thread):
    def __init__(self, event, func):
        threading.Thread.__init__(self)
        self.stopped = event
        self.func = func

    def run(self):
        while not self.stopped.wait(1):
            self.func()


class VideoManager:

    # app 是一个wx.App 对象
    def __init__(self, app):

        self.app = app  # wx App 对象
        self.nvrs = dict()  # nvr 列表

        # 实时播放窗口列表
        # key: "nvr+channel"
        # val: 播放窗口
        self.windows = dict()

        # 告警视频窗口列表

        # 建立一个线程定时器
        self.stopFlag = threading.Event()
        thread = ThreadTimer(self.stopFlag, self.on_timer)
        thread.start()

    # 析构函数
    def __del__(self):
        pass

    def clearUp(self):
        self.stopFlag.set()
        video.CleanDlls()

    # 定时执行函数，用于检测NVR的登录情况，每秒执行
    def on_timer(self):
        for k in self.nvrs:
            nvr = self.nvrs[k]
            if nvr.userSession <= 0:
                nvr.login()

    # 初始化
    def initConfig(self, jsonStr):
        # 首先清理Dlls
        video.CleanDlls()

        # 清理NVR列表
        self.nvrs.clear()

        # {'id': 2, 'name': '海康NVR', 'ip': '192.168.2.123', 'port': 8888, 'login': 'admin', 'pass': 'jennyzhan1', 'type': 2001, 'opt': ''}
        cfgs = json.loads(jsonStr)

        # 建立NVR的Dict
        for cfg in cfgs:
            vo = video.GreateVideoObj(cfg['type'])
            print(cfg)
            if vo is not None:
                vo.wxApp = self.app
                vo.mgr = self
                vo.nvrId = cfg['id']
                vo.nvrDll = video.GetNvrDll(cfg['type'])
                vo.nvrName = cfg['name']
                vo.nvrIp = cfg['ip']
                vo.nvrPort = cfg['port']
                vo.nvrLogin = cfg['login']
                vo.nvrPass = cfg['pass']
                self.nvrs[cfg['id']] = vo

        # 初始化 DLLs
        video.InitDlls()

    # 在Gride中进行播放
    def realPlayInGrid(self, channel, no):
        if self.nvrs.__contains__(channel):
            if self.nvrs[channel].userSession > 0:
                # 播放
                if self.windows.__len__() > 5:
                    # 最多10个窗口
                    return
                else:
                    key = str(channel) + ":" + str(no)
                    if self.windows.__contains__(key):
                        self.windows[key].Raise()
                        pass
                    else:
                        self.nvrs[channel].real_play(no)

    # 在窗体中进行播放，一般是告警
    def realPlayInForm(self, channel, no):
        self.realPlayInGrid(channel, no)

    # 预置位调用
    def goPtz(self, channel, no, ptz):
        if self.nvrs.__contains__(channel):
            if self.nvrs[channel].userSession > 0:
                self.nvrs[channel].goPtz(no, ptz)

    # 历史回放
    def playBack(self, channel, device, name):
        print("历史回放，未实现！")
