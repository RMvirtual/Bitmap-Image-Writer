#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/rasteriser/rasteriser.h"

class RasterisationTest : public testing::Test
{
public:
  RasterisationTest();
  ~RasterisationTest();

protected:
  Rasterisation::Rasteriser rasteriser;
};