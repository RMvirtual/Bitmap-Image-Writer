import wx
from src.main.python.gui.viewer.image_panel import ImagePanel

class GUIFrame(wx.Frame):
    """Main GUI for the app."""

    def __init__(self):
        """Creates a new GUI."""

        super(GUIFrame, self).__init__(None)
        self.__toggle = False

        self.__initialiseWidgets()
        self.__initialiseSizer()

    def __initialiseWidgets(self) -> None:
        self.SetTitle("Win3D")
        self.__imagePanel = ImagePanel(self)

    def __initialiseSizer(self) -> None:
        """Initialises the dynamic sizer for the overall GUI."""

        self.__sizer = wx.BoxSizer(wx.VERTICAL)
        
        self.__sizer.Add(
            window=self.__imagePanel,
            flags=wx.SizerFlags().Expand()
        )
        
        self.__sizer.SetSizeHints(self)
        self.SetSizer(self.__sizer)
        self.SetMinSize(wx.Size(300,300))
        
    def show(self) -> None:
        self.Show()
    
    def loadImage(self, imagePath: str) -> None:
        """Loads an image onto the viewer."""

        self.__imagePath = imagePath
        self.__imagePanel.loadImageFromFile(self.__imagePath)

    def refreshImage(self) -> None:

        self.__toggle = not self.__toggle

        self.__imagePath = (
            "C:/Users/rmvir/Desktop/scc300-Win3D/resources/renderer/"
            + "images-to-load/text.bmp"
        )

        """
        if self.__toggle:
            self.__imagePath = (
                "C:/Users/rmvir/Desktop/scc300-Win3D/resources/renderer/"
                + "images-to-load/triangle.bmp"
            )
        """
        try :
            self.__imagePanel.loadImageFromFile(self.__imagePath)

        except:
            print("Error refreshing image.")
            
    def setText(self, text: str) -> None:
        """Sets the text underneat the image."""

        self.__imagePanel.setText(text)