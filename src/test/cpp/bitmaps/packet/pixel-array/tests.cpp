#include <gtest/gtest.h>
#include "src/test/cpp/bitmaps/packet/pixel-array/fixture.h"

TEST_F(PixelArrayTest, ShouldSetPixelInPixelArray)
{
  auto green = this->greenColours();
  this->pixelArray.set(green, 1, 0);

  auto amendedColours = this->pixelArray.at(1, 0); 
  this->isGreen(*amendedColours);
}

TEST_F(PixelArrayTest, ShouldGetNumberOfPixelsInPixelArray)
{
  int correctNoOfPixels = 4;
  int actualNoOfPixels = this->pixelArray.sizeInPixels();

  EXPECT_EQ(correctNoOfPixels, actualNoOfPixels);
}

TEST_F(PixelArrayTest, ShouldFillPixelArray)
{
  this->pixelArray.fill(this->greenColours());
  int noOfPixels = this->pixelArray.sizeInPixels();

  for (int i = 0; i < noOfPixels; i++) {
    auto pixel = this->pixelArray.at(i);
    this->isGreen(*pixel);
  }
}

#include <chrono>
#include <thread>

TEST_F(PixelArrayTest, DISABLED_ShouldFillPixelsInReasonableTime)
{
  this->setupRedPixelArray(500, 500);

  auto start = std::chrono::high_resolution_clock::now();

  this->pixelArray.fill(this->greenColours());

  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
    stop - start);

  auto durationMs = duration.count();
  std::cout << "Pixel fill took " << durationMs << " milliseconds.\n";

  long fps60 = 20;

  EXPECT_LE(durationMs, fps60);
}