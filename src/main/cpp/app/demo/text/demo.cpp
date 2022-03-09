#include <thread>
#include "src/main/cpp/app/demo/text/demo.h"

Demo::TextDemo::TextDemo()
{
  // pass.
}

void Demo::TextDemo::start()
{
  this->viewer.loadImage(
    "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/text.bmp");
  
  std::thread thread {&GUI::ImageViewer::mainLoop, &this->viewer};
  
  this->viewer.show();

  
}