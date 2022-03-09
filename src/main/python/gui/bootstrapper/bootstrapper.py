import wx
from src.main.python.gui.viewer.viewer import GUI

class GUIBootstrapper():
    """Class for initialising the user interface."""

    def __init__(self) -> None:
        self.initialiseGUI()

    def initialiseGUI(self):
        self.__app = wx.App()

    def launchGUI(self):
        gui = GUI()
        gui.Show()
        
        imagePath = (
            "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\resources\\test\\"
            + "output\\text.bmp"
        )

        gui.loadImage(imagePath)
        gui.setText(imagePath)
    
    def launchMainLoop(self):
        self.__app.MainLoop()