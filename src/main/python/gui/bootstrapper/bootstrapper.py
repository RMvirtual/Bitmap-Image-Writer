import wx
from src.main.python.gui.viewer.viewer import GUI

def initialiseGUI():
    app = wx.App()
    launchGUI(app)

def launchGUI(app):
    gui = GUI()
    gui.Show()
    
    imagePath = (
        "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\resources\\test\\"
        + "output\\text.bmp"
    )

    gui.loadImage(imagePath)
    gui.setText(imagePath)
    app.MainLoop()