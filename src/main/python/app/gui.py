import argparse
import wx
from src.main.python.gui.viewer import GUI

def main(args):
    app = wx.App()

    gui = GUI()
    gui.Show()
    
    imagePath = (
        "C:\\Users\\rmvir\\Desktop\\scc300-Win3D\\resources\\test\\"
        + "output\\text.bmp"
    )

    gui.loadImage(imagePath)
    gui.setText(imagePath)
    app.MainLoop()

def setupArgumentParser() -> argparse.Namespace:
    """Takes arguments from the command line to run several demoes by the
    user."""

    parser = argparse.ArgumentParser(description=(
        "A collection of demos for demonstrating Win3D."))
    
    parser.set_defaults(func=main)
    args = parser.parse_args()
    
    return args

if __name__ == "__main__":
    args = setupArgumentParser()
    args.func(args)