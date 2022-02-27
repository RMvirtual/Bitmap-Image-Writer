import wx

class ImagePanel(wx.Panel):
    """The image panel of the gui viewer."""

    def __init__(self, parent: wx.Frame) -> None:
        super().__init__(parent=parent)

        self.sizer = wx.BoxSizer(wx.VERTICAL)

        self.startImage = wx.Bitmap(width=400, height=400)

        self.bitmapCtrl = wx.StaticBitmap(
            self, wx.ID_ANY, self.startImage)

        self.sizer.Add(
            window=self.bitmapCtrl,
            flags=wx.SizerFlags(1).Expand().Border(wx.ALL, 10)
        )

        self.instructLbl = wx.StaticText(
            parent=self, 
            label="Do stuff and things."
        )

        self.sizer.Add(
            window=self.instructLbl,
            flags=wx.SizerFlags(1).Expand().Border(wx.ALL, 10)
        )

        self.SetSizer(self.sizer)