import wx

from src.main.python.gui.aspect_ratios \
    import aspectRatioFromImage, isAspectRatioPreserved

def toBitmap(imagePath:str) -> wx.Bitmap:
    """Converts an image file to a wx Bitmap object."""
       
    return wx.Bitmap(toImage(imagePath))

def toImage(imagePath:str) -> wx.Image:
    """Converts an image file to a wx Image object."""

    return wx.Image(name=imagePath)

def toScaledImage(imagePath:str, width:int, height:int) -> wx.Image:
    """Creates a bitmap image scaled to a different size."""

    image = toImage(imagePath)

    return image.Scale(
        width=width, height=height, quality=wx.IMAGE_QUALITY_HIGH)

def rescaleImagePreserveAspectRatio(image:wx.Image, width:int, height:int):
    """Rescales the image as close to the new width/height as possible
    while preserving the aspect ratio.
    """
    originalAspectRatio = aspectRatioFromImage(image)
    reports = isAspectRatioPreserved(image, width, height)

    if reports["too wide"]:
        width = height * originalAspectRatio

    else:
        height = width / originalAspectRatio

    scaledImage = image.Scale(
        width=width,
        height=height,
        quality=wx.IMAGE_QUALITY_HIGH
    )

    return scaledImage
