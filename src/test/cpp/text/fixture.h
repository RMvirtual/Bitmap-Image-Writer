#pragma once

#include <memory>

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"

class TextTest : public testing::Test
{
public:
  TextTest();
  ~TextTest();

protected:
  Rasterisation::Rasteriser rasteriser;

  std::shared_ptr<Bitmaps::Image> redImage();
};