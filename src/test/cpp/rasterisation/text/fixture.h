#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"

class TextRasterisationTest : public testing::Test
{
public:
  TextRasterisationTest();
  ~TextRasterisationTest();

protected:
  Rasterisation::Rasteriser rasteriser;
};