import wx
from src.main.python.gui.viewer.frame import GUIFrame

class ImageViewer():
    def __init__(self):
        self.__app = wx.App()

    def start(self):
        self.__gui = GUIFrame()
        self.__gui.show()
        self.__app.MainLoop()

    def loadImage(self, imagePath:str):
        wx.CallAfter(self.__gui, self.__gui.loadImage, imagePath)

    def show(self):
        wx.CallAfter(self.__gui, self.__gui.show, None)