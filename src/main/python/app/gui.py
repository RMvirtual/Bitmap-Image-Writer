import wx

def main():
  app = wx.App()

  frm = wx.Frame(None, title="Hello World")
  frm.Show()
  app.MainLoop()

if __name__ == "__main__":
  main()