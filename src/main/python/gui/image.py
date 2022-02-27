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

        self.__originalImage = wx.Image(width=500, height=500)

        self.__initialiseOriginalAspectRatio()
        self.__bitmap = wx.Bitmap(img=self.__originalImage)

    def loadImage(self, filePath:str) -> None:
        """Loads a bitmap image from a file."""

        self.__originalImage = toImage(filePath)
        self.__initialiseOriginalAspectRatio()
        self.updateScaledImage()
       
    def updateScaledImage(self) -> None:
        currentAspectRatio = self.__calculateCurrentAspectRatio()

        print("Current Aspect Ratio: ", currentAspectRatio)
        print("Original Aspect Ratio: ", self.__originalAspectRatio)

        width, height = self.GetParent().GetSize()
        print(self.GetParent().GetSize())

        # If width greater than the original width, resize it as a
        # proportion of the aspect ratio.
        if currentAspectRatio > self.__originalAspectRatio:
            print("Current ratio > original ratio.")
            width = height * self.__originalAspectRatio

        # If width less than original width, recalculate height to
        # correct aspect ratio.
        else:
            print("Current ratio <= original ratio.")
            height = width / self.__originalAspectRatio

        scaledImage = self.__originalImage.Scale(
            width=width, height=height, quality=wx.IMAGE_QUALITY_HIGH)

        self.__bitmap = wx.Bitmap(img=scaledImage)
        self.SetBitmap(self.__bitmap)

    def __initialiseOriginalAspectRatio(self) -> None:
        width = float(self.__originalImage.GetWidth())
        height = float(self.__originalImage.GetHeight())

        self.__originalAspectRatio = width / height

    def __calculateCurrentAspectRatio(self) -> None:
        width, height = self.GetParent().GetSize()

        return float(width) / float(height)