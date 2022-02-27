import wx

from src.main.python.gui.image_conversion import toImage

class Image(wx.StaticBitmap):
    """An image to be drawn on a panel."""

    def __init__(self, parent, imagePath=None):
        self.__initialiseEmptyImage()

        super().__init__(
            parent=parent,
            id=wx.ID_ANY,
            bitmap=self.__bitmap
        )

        if imagePath:
            self.loadImage(imagePath)

    def __initialiseEmptyImage(self) -> None:
        """Initialises an empty image."""

        self.__width = 500
        self.__height = 500

        self.__originalImage = wx.Image(
            width=self.__width, height=self.__height)
        
        self.__bitmap = wx.Bitmap(img=self.__originalImage)

    def loadImage(self, filePath:str) -> None:
        """Loads a bitmap image from a file."""

        self.__originalImage = toImage(filePath)

        self.__width = self.__originalImage.GetWidth()
        self.__height = self.__originalImage.GetHeight()

        self.resize()
       
    def resize(self) -> None:
        width, height = self.GetSize()
        
        scaledImage = self.__originalImage.Scale(
            width=width, height=height, quality=wx.IMAGE_QUALITY_HIGH)

        self.__bitmap = wx.Bitmap(img=scaledImage)
        self.SetBitmap(self.__bitmap)

