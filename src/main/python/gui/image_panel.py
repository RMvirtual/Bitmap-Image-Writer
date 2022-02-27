import wx

class ImagePanel(wx.Panel):
    """The image panel of the gui viewer."""

    def __init__(self, parent: wx.Frame) -> None:
        """Creates an image panel."""

        super().__init__(parent=parent)

        self.image = wx.Bitmap(width=500, height=500)

        self.bitmapCtrl = wx.StaticBitmap(
            self, wx.ID_ANY, self.image)

        self.instructLbl = wx.StaticText(
            parent=self, 
            label="Do stuff and things."
        )

        self.__initialiseSizer()

    def __initialiseSizer(self) -> None:
        """Initialises the dynamic sizer for the panel."""

        self.sizer = wx.BoxSizer(wx.VERTICAL)

        self.__addSizerDefinitions({
            self.bitmapCtrl: wx.SizerFlags().Expand().Border(wx.ALL, 10),
            self.instructLbl: wx.SizerFlags().Border(wx.ALL, 10) 
        })

        self.sizer.SetSizeHints(self)
        self.SetSizer(self.sizer)

    def __addSizerDefinitions(
            self, sizerDefinitions: dict[wx.Object, wx.SizerFlags]) -> None:
        """Adds a dictionary of wx widgets (keys) and corresponding
        sizer flags (values) to the panel's sizer.
        """

        for key, value in sizerDefinitions.items():
            self.sizer.Add(
                window = key,
                flags = value
            )

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

    def setText(self, text: str) -> None:
        """Sets the text underneat the image."""

        self.instructLbl.SetLabel(text)