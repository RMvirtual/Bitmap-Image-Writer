import wx
from src.main.python.gui.image_panel import ImagePanel

class GUI(wx.Frame):
    """Main GUI for the app."""

    def __init__(self):
        super(GUI, self).__init__(None)
        self.SetSize(width=500,height=500)
        self.SetTitle("Win3D")

        self.sizer = wx.BoxSizer(wx.VERTICAL)

        self.imagePanel = ImagePanel(self)

        self.sizer.Add(
            wx.StaticLine(self.imagePanel, wx.ID_ANY),
            0, wx.ALL|wx.EXPAND, 5
        )

        instructions = "Do stuff and things."
        self.instructLbl = wx.StaticText(self.imagePanel, label=instructions)
        self.sizer.Add(self.instructLbl, 0, wx.ALL, 5)

        self.imagePanel.SetSizer(self.sizer)