import wx

def scaleDimensionsToRatio(
        ratio:float, width:int, height:int) -> tuple[int,int]:
    """Returns as close a width and height as can be achieved whilst
    conforming to the provided ratio.
    """
    correctness = aspectRatioCorrectness(ratio, width, height)

    if correctness["too wide"]:
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
    
    return scaleDimensionsToRatio(aspectRatio, width, height)

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

def aspectRatioCorrectness(
    ratio:float, width:int, height:int) -> dict[str,bool]:
    """Returns a dictionary of reported concerning whether he new width
    and height dimensions provided will match a provided aspect ratio.
    """
    newRatio = aspectRatio(width, height)

    reports = {
        "preserved": newRatio == ratio,
        "too wide": newRatio > ratio,
        "too tall": newRatio < ratio
    }

    return reports