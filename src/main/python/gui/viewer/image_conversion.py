import wx

from src.main.python.gui.viewer.aspect_ratios import scaleDimensionsToImageAspectRatio

def toBitmap(imagePath:str) -> wx.Bitmap:
    """Converts an image file to a wx Bitmap object."""
       
    return wx.Bitmap(toImage(imagePath))

def toImage(imagePath:str) -> wx.Image:
    """Converts an image file to a wx Image object."""

    return wx.Image(name=imagePath)

def toScaledImage(imagePath:str, width:int, height:int) -> wx.Image:
    """Creates a bitmap image scaled to a different size."""

    image = toImage(imagePath)

    return __scaledImage(image, width, height)

def toScaledImagePreserveAspectRatio(image:wx.Image, width:int, height:int):
    """Rescales the image as close to the new width/height as possible
    while preserving the aspect ratio.
    """
    width, height = scaleDimensionsToImageAspectRatio(image, width, height)

    return __scaledImage(image, width, height)

def __scaledImage(image:wx.Image, width:int, height:int) -> wx.Image:
    """Returns a scaled image to new width and height dimensions."""

    return image.Scale(
        width=width, height=height, quality=wx.IMAGE_QUALITY_HIGH)