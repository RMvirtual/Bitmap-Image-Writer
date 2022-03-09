#include "src/main/cpp/gui/image_viewer.h"

GUI::ImageViewer::ImageViewer()
{
  this->interface.show();
  this->interface.launchMainLoop();
}

void GUI::ImageViewer::loadImage(std::string imagePath)
{
  this->interface.loadImage(imagePath);
}

void GUI::ImageViewer::refresh()
{
  this->interface.refresh();
}

void GUI::ImageViewer::show()
{
  this->interface.show();
}