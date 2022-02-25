import wx

class ImagePanel(wx.Panel):
    """The image panel of the gui viewer."""

    def __init__(self, parent: wx.Frame) -> None:
        super().__init__(parent=parent)

        self.startImage = wx.Bitmap(width=500, height=500)

        self.bitmapCtrl = wx.StaticBitmap(
            self, wx.ID_ANY, self.startImage)
