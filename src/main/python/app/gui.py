import wx
from src.main.python.gui.viewer import GUI

def main():
    app = wx.App()

    gui = GUI()
    gui.Show()
    
    app.MainLoop()

if __name__ == "__main__":
    main()