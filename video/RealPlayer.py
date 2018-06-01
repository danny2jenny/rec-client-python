'''
实时播放窗口
'''
from enum import Enum

import wx
import math

'''
PTZ 方向定义
'''


class PtzDir(Enum):
    UP = 1
    RIGHT = 2
    DOWN = 3
    LEFT = 4
    UP_RIGHT = 11
    DOWN_RIGHT = 12
    DOWN_LEFT = 13
    UP_LEFT = 14


'''
实时视频播放窗口
'''


class RealPlayerForm(wx.Frame):

    # 构造函数
    def __init__(self, parent, title):

        # 播放参数
        self.nvr = None
        self.nvrId = 0
        self.mgr = None
        self.previewSession = -1
        self.channel = -1

        wx.Frame.__init__(
            self,
            parent=parent,
            id=wx.ID_ANY,
            title=title,
            size=(600, 400),
            style=wx.FRAME_FLOAT_ON_PARENT | wx.DEFAULT_FRAME_STYLE
        )
        # 类变量
        self.ptzDir = PtzDir.DOWN

        # 鼠标移动事件
        self.Bind(wx.EVT_MOTION, self.OnMove)

        # 滚轮事件
        self.Bind(wx.EVT_MOUSEWHEEL, self.OnMouseWheel)

        # 鼠标左键按下
        self.Bind(wx.EVT_LEFT_DOWN, self.OnMouseLeftDown)

        # 鼠标左键释放
        self.Bind(wx.EVT_LEFT_UP, self.OnMouseLeftUp)

        # 关闭事件
        self.Bind(wx.EVT_CLOSE, self.OnClose)

    # 鼠标移动事件
    def OnMove(self, e):
        w, h = self.Size
        m_x = w / 2
        m_y = h / 2
        x, y = e.GetPosition()

        angle = 180 * math.atan2(m_y - y, x - m_x) / math.pi

        if angle >= -22.5 and angle < 22.5:
            self.ptzDir = PtzDir.RIGHT
        elif angle >= 22.5 and angle < 67.5:
            self.ptzDir = PtzDir.UP_RIGHT
        elif angle >= 67.5 and angle < 112.5:
            self.ptzDir = PtzDir.UP
        elif angle >= 112.5 and angle < 167.5:
            self.ptzDir = PtzDir.UP_LEFT
        elif angle < -22.5 and angle >= -67.5:
            self.ptzDir = PtzDir.DOWN_RIGHT
        elif angle < -67.5 and angle >= -112.5:
            self.ptzDir = PtzDir.DOWN
        elif angle < -112.5 and angle >= -167.5:
            self.ptzDir = PtzDir.DOWN_LEFT
        elif angle >= 167.5 or angle <= -167.5:
            self.ptzDir = PtzDir.LEFT

    # 鼠标滚轮事件
    def OnMouseWheel(self, e):
        self.nvr.zoom(self.channel, e.WheelRotation)

    # 鼠标左键按下
    def OnMouseLeftDown(self, e):
        self.nvr.ptz_start(self.channel, self.ptzDir)
        pass

    # 鼠标左键释放
    def OnMouseLeftUp(self, e):
        self.nvr.ptz_stop(self.channel)
        pass

    # 窗体关闭
    def OnClose(self, e):
        self.nvr.real_play_stop(self.previewSession)
        # todo 从列表中移除
        key = str(self.nvrId) + ":" + str(self.channel)
        self.mgr.windows.pop(key)
        self.Destroy()

    # 添加到窗口列表
    def AddToWindowList(self):
        key = str(self.nvrId) + ":" + str(self.channel)
        self.mgr.windows[key] = self
