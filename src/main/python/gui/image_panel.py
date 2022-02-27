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

        self.Bind(wx.EVT_SIZE, self.__resize)

    def __addSizerDefinitions(
            self, sizerDefinitions: dict[wx.Object, wx.SizerFlags]) -> None:
        """Adds a dictionary of wx widgets (keys) and corresponding
        sizer flags (values) to the panel's sizer.
        """

        definitionItems = sizerDefinitions.items()

        addToSizer = (
            lambda widget, flags : self.sizer.Add(window=widget, flags=flags))
        
        [addToSizer(widget, flags) for widget, flags in definitionItems]

    def loadImageFromFile(self, filePath: str) -> None:
        """Loads a bitmap image to the viewer control."""

        self.originalImage = toImage(filePath)
        self.displayImage()

    def __resize(self, event:wx.Event) -> None:
        """Event handler for resizing of the panel."""

        self.displayImage()

    def displayImage(self) -> None:
        """Scales the current image's bitmap output to the current size
        of the image control.
        """
        self.__updateBitmapImage()
        self.__refreshBitmapImage()

    def __updateBitmapImage(self) -> None:
        """Updates the current bitmap as a scaled version of the
        original image based on the  current size of the image control.
        """
        scaledImage = self.__imageScaledToPanel()
        self.bitmap = wx.Bitmap(img=scaledImage)

    def __imageScaledToPanel(self) -> wx.Image:
        """Returns a scaled image based on the current size of the
        image control."""

        width, height = self.bitmapCtrl.GetSize()
        
        return self.originalImage.Scale(
            width=width, height=height, quality=wx.IMAGE_QUALITY_HIGH)

    def __refreshBitmapImage(self) -> None:
        """Repaints the bitmap image."""

        self.bitmapCtrl.SetBitmap(self.bitmap)

    def setText(self, text: str) -> None:
        """Sets the text underneath the image."""

        self.text.SetLabel(text)