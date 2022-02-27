import wx

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