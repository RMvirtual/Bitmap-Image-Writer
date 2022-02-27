import wx

class ImagePanel(wx.Panel):
    """The image panel of the gui viewer."""

    def __init__(self, parent: wx.Frame) -> None:
        super().__init__(parent=parent)

        self.sizer = wx.BoxSizer(wx.VERTICAL)
        self.startImage = wx.Bitmap(width=500, height=500)

        self.bitmapCtrl = wx.StaticBitmap(
            self, wx.ID_ANY, self.startImage)

        self.sizer.Add(
            window=self.bitmapCtrl,
            flags=wx.SizerFlags().Expand().Border(wx.ALL, 10)
        )

        self.instructLbl = wx.StaticText(
            parent=self, 
            label="Do stuff and things."
        )

        self.sizer.Add(
            window=self.instructLbl,
            flags=wx.SizerFlags().Border(wx.ALL, 10)
        )

        self.sizer.SetSizeHints(self)

        self.SetSizer(self.sizer)

    def loadImage(self, bitmap: wx.Bitmap) -> None:
        """Loads an bitmap image to the viewer control."""

        scaledBitmap = self.scaleBitmapToWidget(bitmap)
        self.bitmapCtrl.SetBitmap(scaledBitmap)

    def scaleBitmapToWidget(self, bitmap: wx.Bitmap):
        """Scales the passed bitmap to the current size of the image
        control.
        """
        width, height = self.bitmapCtrl.GetSize()

        image = bitmap.ConvertToImage()
        scaledImage = image.Scale(width, height, wx.IMAGE_QUALITY_HIGH)
        
        return wx.Bitmap(img=scaledImage)