#include <chrono>
#include <thread>
#include <iostream>

#include "src/main/cpp/app/demo/text/demo.h"

Demo::TextDemo::TextDemo()
{
  this->viewer = new GUI::ImageViewer {};
}

Demo::TextDemo::~TextDemo()
{
  delete this->viewer;
}

void Demo::TextDemo::start()
{  
  this->viewer->loadImage(
    "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/text.bmp");

  this->viewer->show();
  // this->updateImage();
  std::thread thread {&TextDemo::updateImage, this};
  this->viewer->mainLoop();
}

void Demo::TextDemo::updateImage()
{
  while (true) {
    std::cout << "About to sleep.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Slept.\n";

    this->viewer->loadImage(
      "C:/Users/rmvir/Desktop/scc300-Win3D/resources/test/output/text.bmp");

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Slept for 5.\n";
  }
}