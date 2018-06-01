import wx
from cefpython3 import cefpython as cef
import platform
import sys
import os
import json

# Fix for PyCharm hints warnings when using static methods
import video
from video.VideoManager import VideoManager

WindowUtils = cef.WindowUtils()

# Configuration
WIDTH = 800
HEIGHT = 600

# Globals
g_count_windows = 0
cfg = None

'''
添加Dll的搜索路径
'''


def envSetup():
    if getattr(sys, 'frozen', False):
        baseDir = sys._MEIPASS
    else:
        # we are running in a normal Python environment
        baseDir = os.path.dirname(os.path.abspath(__file__))
    # 添加 plugin 目录
    os.environ['PATH'] = baseDir + '\\plugin' + ';' + os.environ['PATH']
    # 添加 plugin 中的第一级子目录
    files = os.listdir(baseDir + '\\plugin')
    for file in files:
        if os.path.isdir(baseDir + "\\plugin\\" + file):
            os.environ['PATH'] = baseDir + "\\plugin\\" + file + ';' + os.environ['PATH']


'''
主函数
'''


def main():
    # 读取配置
    envSetup()
    video.LoadDll()

    # 读取配置文件
    cfg_file = os.path.join(os.path.abspath(os.path.dirname(__file__)), "resources/config.json")
    f = open(cfg_file, encoding='utf-8')
    global cfg
    cfg = json.load(f)
    f.close()

    # 开始
    check_versions()
    sys.excepthook = cef.ExceptHook  # To shutdown all CEF processes on error
    settings = {
        "remote_debugging_port": 4444
    }

    # noinspection PyUnresolvedReferences, PyArgumentList
    cef.DpiAware.EnableHighDpiSupport()
    cef.Initialize(settings=settings)
    app = CefApp(False)
    app.MainLoop()
    del app  # Must destroy before calling Shutdown
    # On Mac shutdown is called in OnClose
    cef.Shutdown()


'''
检查版本
'''


def check_versions():
    print("[rec-client.py] CEF Python {ver}".format(ver=cef.__version__))
    print("[rec-client.py] Python {ver} {arch}".format(
        ver=platform.python_version(), arch=platform.architecture()[0]))
    print("[rec-client.py] wxPython {ver}".format(ver=wx.version()))
    # CEF Python version requirement
    assert cef.__version__ >= "55.3", "CEF Python v55.3+ required to run this"


'''
快捷键的对象
'''


class KeyboardHandler(object):
    def OnKeyEvent(self, browser, event, **_):
        if (event['type'] == 2):
            if (event['windows_key_code'] == 116):  # F5
                browser.Reload()
            elif (event['windows_key_code'] == 117):  # F6
                browser.ReloadIgnoreCache()
            elif (event['windows_key_code'] == 123):  # F12
                browser.ShowDevTools()


'''
WX 框架，主界面
'''


class MainFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, parent=None, id=wx.ID_ANY, title=cfg["company"] + '-' + cfg["appName"],
                          size=(WIDTH, HEIGHT), style=wx.DEFAULT_FRAME_STYLE | wx.MAXIMIZE)
        self.browser = None
        self.javascriptExternal = None

        global g_count_windows
        g_count_windows += 1

        self.setup_icon()
        self.Bind(wx.EVT_CLOSE, self.OnClose)

        # Set wx.WANTS_CHARS style for the keyboard to work.
        # This style also needs to be set for all parent controls.
        self.browser_panel = wx.Panel(self, style=wx.WANTS_CHARS)
        self.browser_panel.Bind(wx.EVT_SET_FOCUS, self.OnSetFocus)
        self.browser_panel.Bind(wx.EVT_SIZE, self.OnSize)

        self.embed_browser()
        self.Show()

    def setup_icon(self):
        icon_file = os.path.join(os.path.abspath(os.path.dirname(__file__)), "resources", "rec.ico")
        # wx.IconFromBitmap is not available on Linux in wxPython 3.0/4.0
        if os.path.exists(icon_file):
            icon = wx.Icon()
            icon.LoadFile(icon_file, wx.BITMAP_TYPE_ICO)
            self.SetIcon(icon)

    def embed_browser(self):
        window_info = cef.WindowInfo()
        (width, height) = self.browser_panel.GetClientSize().Get()
        assert self.browser_panel.GetHandle(), "Window handle not available yet"
        window_info.SetAsChild(self.browser_panel.GetHandle(), [0, 0, width, height])
        self.browser = cef.CreateBrowserSync(window_info, url=cfg["url"])
        self.browser.SetClientHandler(FocusHandler())
        self.browser.SetClientHandler(KeyboardHandler())

        # JavaScript 回调注册
        bindings = cef.JavascriptBindings(bindToFrames=False, bindToPopups=False)
        self.javascriptExternal = VideoManager(self, cfg["url"])
        bindings.SetObject("videoPlayer", self.javascriptExternal)
        self.browser.SetJavascriptBindings(bindings)

    def OnSetFocus(self, _):
        if not self.browser:
            return
        WindowUtils.OnSetFocus(self.browser_panel.GetHandle(), 0, 0, 0)
        self.browser.SetFocus(True)

    def OnSize(self, _):
        if not self.browser:
            return
        WindowUtils.OnSize(self.browser_panel.GetHandle(), 0, 0, 0)
        self.browser.NotifyMoveOrResizeStarted()

    def OnClose(self, event):
        print("[rec-client.py] OnClose called")
        self.javascriptExternal.clearUp()
        if not self.browser:
            # May already be closing, may be called multiple times on Mac
            return

        # Calling browser.CloseBrowser() and/or self.Destroy()
        # in OnClose may cause app crash on some paltforms in
        # some use cases, details in Issue #107.
        self.browser.ParentWindowWillClose()
        event.Skip()
        self.clear_browser_references()

    def clear_browser_references(self):
        # Clear browser references that you keep anywhere in your
        # code. All references must be cleared for CEF to shutdown cleanly.
        self.browser = None


class FocusHandler(object):
    def OnGotFocus(self, browser, **_):
        # Temporary fix for focus issues on Linux (Issue #284).
        pass


'''
应用程序入口
'''


class CefApp(wx.App):
    def __init__(self, redirect):
        self.timer = None
        self.timer_id = 1
        self.is_initialized = False
        super(CefApp, self).__init__(redirect=redirect)

    def OnPreInit(self):
        super(CefApp, self).OnPreInit()
        # On Mac with wxPython 4.0 the OnInit() event never gets
        # called. Doing wx window creation in OnPreInit() seems to
        # resolve the problem (Issue #350).

    def OnInit(self):
        self.initialize()
        return True

    def initialize(self):
        if self.is_initialized:
            return
        self.is_initialized = True
        self.create_timer()
        frame = MainFrame()
        self.SetTopWindow(frame)
        frame.Show()

    def create_timer(self):
        # See also "Making a render loop":
        # http://wiki.wxwidgets.org/Making_a_render_loop
        # Another way would be to use EVT_IDLE in MainFrame.
        self.timer = wx.Timer(self

                              , self.timer_id)
        self.Bind(wx.EVT_TIMER, self.on_timer, self.timer)
        self.timer.Start(10)  # 10ms timer

    def on_timer(self, _):
        cef.MessageLoopWork()

    def OnExit(self):
        self.timer.Stop()
        return 0


if __name__ == '__main__':
    main()
