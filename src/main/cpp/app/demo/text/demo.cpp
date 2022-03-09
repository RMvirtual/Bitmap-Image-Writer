#include <thread>
#include "src/main/cpp/app/demo/text/demo.h"

Demo::TextDemo::TextDemo()
{
  // pass.
}

void Demo::TextDemo::start()
{
  viewer.loadImage(
    "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/text.bmp");

  viewer.show();
  viewer.mainLoop();
}