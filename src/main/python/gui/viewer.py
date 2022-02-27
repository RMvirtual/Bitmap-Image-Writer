import wx
from src.main.python.gui.image_panel import ImagePanel

class GUI(wx.Frame):
    """Main GUI for the app."""

    def __init__(self):
        super(GUI, self).__init__(None)
        # self.SetSize(width=500,height=500)
        self.SetTitle("Win3D")

        self.sizer = wx.BoxSizer(wx.VERTICAL)

        self.imagePanel = ImagePanel(self)                
        self.sizer.Add(self.imagePanel)

        self.SetSizer(self.sizer)