import wx
from src.main.python.gui.viewer.viewer import GUI

def main():
    app = wx.App()

    gui = GUI()
    gui.Show()
    
    imagePath = (
        "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\resources\\test\\"
        + "output\\text.bmp"
    )

    gui.loadImage(imagePath)
    gui.setText(imagePath)
    app.MainLoop()