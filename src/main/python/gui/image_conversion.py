import wx

def toBitmap(imagePath: str) -> wx.Bitmap:
    """Converts an image file to a wx Bitmap object."""
       
    return wx.Bitmap(toImage(imagePath))

def toImage(imagePath: str) -> wx.Image:
    """Converts an image file to a wx Image object."""

    return wx.Image(name=imagePath)