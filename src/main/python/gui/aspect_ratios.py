import wx

def aspectRatioFromImage(image:wx.Image) -> float:
    """Returns an image's aspect ratio (how many pixels wide for every
    pixel in height).
    """
    return aspectRatio(image.GetWidth(), image.GetHeight())

def aspectRatio(width:int, height:int) -> float:
    """Returns a ratio of how many pixels wide for every pixel in
    height.
    """
    return float(width) / float(height)

def isAspectRatioPreserved(
        image:wx.Image, newWidth:int, newHeight:int) -> dict[str,bool]:
    """Returns whether the new width and height dimensions provided
    will match an image's original aspect ratio.
    """
    originalRatio, newRatio = __aspectRatios(image, newWidth, newHeight)

    reports = {
        "preserved": newRatio == originalRatio,
        "too wide": newRatio > originalRatio,
        "too tall": newRatio < originalRatio
    }

    return reports

def __aspectRatios(
        image:wx.Image, newWidth:int, newHeight:int) -> tuple[float,float]:
    """Returns an image's aspect ratio as well as an aspect ratio
    formed from a potential new width and height.
    """

    originalRatio = aspectRatioFromImage(image)
    newRatio = aspectRatio(newWidth, newHeight)

    return originalRatio, newRatio