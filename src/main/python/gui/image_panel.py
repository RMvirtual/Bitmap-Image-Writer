import wx

from src.main.python.gui.image_conversion import toBitmap, toImage
from src.main.python.gui.image import Image

class ImagePanel(wx.Panel):
    """The image panel of the gui viewer."""

    def __init__(self, parent:wx.Frame) -> None:
        """Creates an image panel."""

        super().__init__(parent=parent)

        self.__initialiseWidgets()
        self.__initialiseSizer()

    def __initialiseWidgets(self) -> None:
        """Initialises the panel's widgets."""

        self.__image = Image(parent=self, imagePath=None)
        self.__text = wx.StaticText(parent=self, label="Do stuff and things.")

    def __initialiseSizer(self) -> None:
        """Initialises the dynamic sizer for the panel."""

        self.sizer = wx.BoxSizer(wx.VERTICAL)

        self.__addSizerDefinitions({
            self.__image: wx.SizerFlags().Expand().Border(wx.ALL, 10),
            self.__text: wx.SizerFlags().Border(wx.ALL, 10)
        })

        self.sizer.SetSizeHints(self)
        self.SetSizer(self.sizer)

        self.Bind(wx.EVT_SIZE, self.__resize)

    def __addSizerDefinitions(
            self, sizerDefinitions:dict[wx.Object, wx.SizerFlags]) -> None:
        """Adds a dictionary of wx widgets (keys) and corresponding
        sizer flags (values) to the panel's sizer.
        """
        definitionItems = sizerDefinitions.items()

        addToSizer = (
            lambda widget, flags : self.sizer.Add(window=widget, flags=flags))
        
        [addToSizer(widget, flags) for widget, flags in definitionItems]

    def loadImageFromFile(self, filePath:str) -> None:
        """Loads a bitmap image to the viewer control."""

        self.__image.loadImage(filePath)
        self.__refreshBitmapImage

    def __resize(self, event:wx.Event) -> None:
        """Event handler for resizing of the panel."""
        print(self.__image.GetSize())

        self.__refreshBitmapImage()

    def __refreshBitmapImage(self) -> None:
        """Repaints the bitmap image."""

        self.Refresh()

    def setText(self, text:str) -> None:
        """Sets the text underneath the image."""

        self.__text.SetLabel(text)