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
  std::thread renderingThread {&TextDemo::updateImage, this};
  this->viewer->start();
}

void Demo::TextDemo::updateImage()
{
  while (true) {
    std::cout << "About to sleep.\n";
    std::this_thread::sleep_for(std::chrono::seconds(4));

    std::cout << "Slept.\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Slept for 5.\n";
  }
}