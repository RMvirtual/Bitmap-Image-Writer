import wx

class GUI(wx.Frame):
    """Main GUI for the app."""

    def __init__(self):
        super(GUI, self).__init__(None)
        self.SetTitle("Win3D")