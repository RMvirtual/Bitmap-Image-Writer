import wx

from src.main.python.gui.image_conversion \
    import toImage, rescaleImagePreserveAspectRatio

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

        self.__originalImage = wx.Image(width=500, height=500)
        self.__bitmap = wx.Bitmap(img=self.__originalImage)

    def loadImage(self, filePath:str) -> None:
        """Loads a bitmap image from a file."""

        self.__originalImage = toImage(filePath)
        self.refresh()
       
    def refresh(self) -> None:
        width, height = self.GetParent().GetSize()

        scaledImage = rescaleImagePreserveAspectRatio(
            self.__originalImage, width, height)

        self.__bitmap = wx.Bitmap(img=scaledImage)
        self.SetBitmap(self.__bitmap)