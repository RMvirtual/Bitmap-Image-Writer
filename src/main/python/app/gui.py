import wx
from src.main.python.gui.viewer import GUI

def main():
    app = wx.App()

    gui = GUI()
    gui.Show()
    
    imagePath = (
        "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\resources\\test\\"
        + "correct-resources\\redFill512x512.bmp"
    )

    gui.loadImage(imagePath)
    gui.setText("Vodaphone are bumheads.")
    app.MainLoop()

if __name__ == "__main__":
    main()