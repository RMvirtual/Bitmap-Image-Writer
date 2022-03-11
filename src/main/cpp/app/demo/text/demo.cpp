#include <chrono>
#include <thread>
#include <iostream>

#include "src/main/cpp/files/alphabet-2d/file.h"
#include "src/main/cpp/bitmaps/formats/formats.h"
#include "src/main/cpp/bitmaps/image/image.h"
#include "src/main/cpp/bitmaps/writer/image/writer.h"
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
  this->updateImage();
  // std::thread renderingThread {&TextDemo::updateImage, this};
  // this->viewer->start();
}

void Demo::TextDemo::updateImage()
{
  auto format = Bitmaps::format("RGB24");
  format.setHeightInPixels(500);
  format.setWidthInPixels(500);

  auto redColours = format.colours();
  redColours["red"] = 255;
  redColours["green"] = 0;
  redColours["blue"] = 0;

  auto textBox = this->textBox();
  auto image = this->redImage();

  Rasterisation::Rasteriser rasteriser {image};
  Bitmaps::ImageWriter writer;

  Maths::Vector negativeTranslation {-1, 0.0};
  Maths::Vector positiveTranslation {1.5, 0.0};
  Maths::Vector* translation = &positiveTranslation;

  int renderNo = 0;

  while (true) {
    auto start = std::chrono::high_resolution_clock::now();
    
    image->fill(redColours);
    
    bool boundaryReached = (
      textBox.xLowerBound() <= 0 ||
      textBox.xUpperBound() >= 500
    );

    if (boundaryReached) {
      if ((*translation)["x"] == 1)
        translation = &negativeTranslation;

      else
        translation = &positiveTranslation;
    }

    textBox.translate(*translation);
    rasteriser.draw(textBox);
    
    try {
      writer.writeToFile(
        image,
        "C:/Users/rmvir/Desktop/scc300-Win3D/resources/renderer/images-to-load/text.bmp"
      );
    }

    catch (std::exception e) {
      std::cout << "Exception" << std::endl;
    }
    
    renderNo++;
    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
      stop - start);

    std::cout << "It takes " << duration.count() 
      << " milliseconds to process instead of 17 ms.\n";
  }
}

std::shared_ptr<Bitmaps::Image> Demo::TextDemo::redImage()
{
  auto format = Bitmaps::format("RGB24");
  format.setHeightInPixels(500);
  format.setWidthInPixels(500);

  auto redColours = format.colours();
  redColours["red"] = 255;
  redColours["green"] = 0;
  redColours["blue"] = 0;

  auto image = std::make_shared<Bitmaps::Image>(format);
  image->fill(redColours);

  return image;
}

Text::Text2D Demo::TextDemo::textBox()
{
  Text::Text2D text {"helloworld"};
  text.setPadding(0.25, 0.0);
  text.scale(20);
  text.translate({1, 200});

  return text;
}