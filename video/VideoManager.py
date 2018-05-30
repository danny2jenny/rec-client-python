'''
视频播放管理器
nvrs 存放所有的NVR配置
'''

import json

import wx
import video


class VideoManager:

    # app 是一个wx.App 对象
    def __init__(self, app):

        self.app = app  # wx App 对象
        self.nvrs = dict()  # nvr 列表

        # 定时器初始化
        self.timer_id = -1
        self.timer = wx.Timer(app)
        app.Bind(wx.EVT_TIMER, self.on_timer, self.timer)
        self.timer.Start(1000)

    # 析构函数
    def __del__(self):
        pass

    # 定时执行函数，用于检测NVR的登录情况，每秒执行
    def on_timer(self, _):
        for k in self.nvrs:
            nvr = self.nvrs[k]
            if nvr.session <= 0:
                nvr.login()

    # 初始化
    def initConfig(self, jsonStr):
        # 首先清理Dlls
        video.CleanDlls()

        # {'id': 2, 'name': '海康NVR', 'ip': '192.168.2.123', 'port': 8888, 'login': 'admin', 'pass': 'jennyzhan1', 'type': 2001, 'opt': ''}
        cfgs = json.loads(jsonStr)

        # 建立NVR的Dict
        for cfg in cfgs:
            vo = video.GreateVideoObj(cfg['type'])
            print(cfg)
            if vo is not None:
                vo.app = self.app
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
        print("网格播放：", channel, ":", no)
        if self.nvrs.__contains__(channel):
            self.nvrs[channel].real_play(no)

    # 在窗体中进行播放
    def realPlayInForm(self, channel, no):
        self.realPlayInGrid(channel, no)

    # 历史回放
    def playBack(self, channel, device, name):
        print("历史回放，未实现！")
        pass
