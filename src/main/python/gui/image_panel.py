import wx

from src.main.python.gui.image_conversion import toBitmap, toImage

class ImagePanel(wx.Panel):
    """The image panel of the gui viewer."""

    def __init__(self, parent: wx.Frame) -> None:
        """Creates an image panel."""

        super().__init__(parent=parent)

        self.__initialiseWidgets()
        self.__initialiseSizer()

    def __initialiseWidgets(self) -> None:
        """Initialises the panel's widgets."""

        self.originalImage = wx.Image(width=500, height=500)
        self.bitmap = wx.Bitmap(img=self.originalImage)

        self.bitmapCtrl = wx.StaticBitmap(
            parent=self,
            id=wx.ID_ANY,
            bitmap=self.bitmap
        )

        self.text = wx.StaticText(
            parent=self,
            label="Do stuff and things."
        )

    def __initialiseSizer(self) -> None:
        """Initialises the dynamic sizer for the panel."""

        self.sizer = wx.BoxSizer(wx.VERTICAL)

        self.__addSizerDefinitions({
            self.bitmapCtrl: wx.SizerFlags().Expand().Border(wx.ALL, 10),
            self.text: wx.SizerFlags().Border(wx.ALL, 10) 
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

    def loadImageFromFile(self, filePath: str) -> None:
        """Loads a bitmap image to the viewer control."""

        self.originalImage = toImage(filePath)
        self.scaleBitmapToViewer()

    def scaleBitmapToViewer(self) -> None:
        """Scales the current image's bitmap output to the current size
        of the image control.
        """
        width, height = self.bitmapCtrl.GetSize()
        
        scaledImage = self.originalImage.Scale(
            width=width, height=height, quality=wx.IMAGE_QUALITY_HIGH)
        
        self.bitmap = wx.Bitmap(img=scaledImage)
        self.__refreshBitmapImage()

    def __refreshBitmapImage(self) -> None:
        """Repaints the bitmap image."""

        self.bitmapCtrl.SetBitmap(self.bitmap)

    def setText(self, text: str) -> None:
        """Sets the text underneath the image."""

        self.text.SetLabel(text)