import wx
from src.main.python.gui.viewer.image_panel import ImagePanel

class GUI(wx.Frame):
    """Main GUI for the app."""

    def __init__(self):
        """Creates a new GUI."""

        super(GUI, self).__init__(None)
        self.__initialiseWidgets()
        self.__initialiseSizer()

    def __initialiseWidgets(self) -> None:
        self.SetTitle("Win3D")
        self.imagePanel = ImagePanel(self)

    def __initialiseSizer(self) -> None:
        """Initialises the dynamic sizer for the overall GUI."""

        self.sizer = wx.BoxSizer(wx.VERTICAL)
        
        self.sizer.Add(
            window=self.imagePanel,
            flags=wx.SizerFlags().Expand()
        )
        
        self.sizer.SetSizeHints(self)
        self.SetSizer(self.sizer)
        self.SetMinSize(wx.Size(300,300))
        
    def loadImage(self, imagePath: str) -> None:
        """Loads an image onto the viewer."""

        self.imagePanel.loadImageFromFile(imagePath)

    def setText(self, text: str) -> None:
        """Sets the text underneat the image."""

        self.imagePanel.setText(text)