import wx
from src.main.python.gui.viewer.frame import GUIFrame

class ImageViewer():
    def __init__(self):
        pass

    def start(self):
        self.__app = wx.App()
        self.__gui = GUIFrame()
        self.__gui.show()
        self.timer = None

        self.refreshImage()
        self.__app.MainLoop()

    def refreshImage(self):
        wx.CallLater(16.7, self.refreshImage)

        self.__gui.refreshImage()

    def show(self):
        self.__gui.show()