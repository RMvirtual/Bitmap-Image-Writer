import wx
from src.main.python.gui.image_panel import ImagePanel

class GUI(wx.Frame):
    """Main GUI for the app."""

    def __init__(self):
        super(GUI, self).__init__(None)
        self.SetTitle("Win3D")

        self.sizer = wx.BoxSizer(wx.VERTICAL)
        self.imagePanel = ImagePanel(self)
        
        self.sizer.Add(
            window=self.imagePanel,
            flags=wx.SizerFlags().Expand()
        )

        self.sizer.SetSizeHints(self)
        self.SetSizer(self.sizer)

    def loadImage(self, imagePath: str) -> None:
        """Loads an image onto the viewer."""

        image = wx.Image(name=imagePath)
        bitmap = wx.Bitmap(img=image)

        self.imagePanel.loadImage(bitmap)