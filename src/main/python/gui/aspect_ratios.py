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
        originalRatio:float, newWidth:int, newHeight:int) -> dict[str,bool]:
    """Returns whether the new width and height dimensions provided
    will match an aspect ratio.
    """
    newRatio = aspectRatio(newWidth, newHeight)

    reports = {
        "preserved": newRatio == originalRatio,
        "too wide": newRatio > originalRatio,
        "too tall": newRatio < originalRatio
    }

    return reports

def newDimensionsFromRatio(
        ratio:float, width:int, height:int) -> tuple[int,int]:
    """Returns as close a width and height as can be achieved whilst
    conforming to the provided ratio.
    """
    reports = isAspectRatioPreserved(ratio, width, height)

    if reports["too wide"]:
        width = height * ratio

    else:
        height = width / ratio

    return width, height

def scaleDimensionsToImageAspectRatio(
        image:wx.Image, width:int, height:int) -> tuple[int,int]:
    """Returns as close a width and height as can be achieved whilst
    conforming to the image's aspect ratio.
    """
    aspectRatio = aspectRatioFromImage(image)
    
    return newDimensionsFromRatio(aspectRatio, width, height)