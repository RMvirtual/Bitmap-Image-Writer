import wx

from src.main.python.gui.image_conversion import toImage

class Image(wx.StaticBitmap):
    """An image to be drawn on a panel."""

    def __init__(self, parent, imagePath):
        self.__initialiseEmptyImage()

        super().__init__(
            parent=parent,
            id=wx.ID_ANY,
            bitmap=self.__bitmap
        )

    def __initialiseEmptyImage(self) -> None:
        """Initialises an empty image."""

        self.__originalImage = wx.Image(width=500, height=500)
        self.__bitmap = wx.Bitmap(img=self.__originalImage)

    def loadImage(self, filePath:str) -> None:
        """Loads a bitmap image from a file."""

        self.__originalImage = toImage(filePath)
        self.__scaleBitmapToSize()
        self.SetBitmap(self.__bitmap)

    def __scaleBitmapToSize(self) -> wx.Image:
        """Returns a scaled image based on the current size of the
        image control.
        """
        width, height = self.GetSize()
        
        scaledImage = self.__originalImage.Scale(
            width=width, height=height, quality=wx.IMAGE_QUALITY_HIGH)

        self.__bitmap = wx.Bitmap(img=scaledImage)