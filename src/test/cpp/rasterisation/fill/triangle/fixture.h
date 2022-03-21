#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/rasterisation/fill/triangle/filler.h"

class TriangleFillerTest : public testing::Test
{
public:
  TriangleFillerTest();
  ~TriangleFillerTest();

protected:
  Rasterisation::TriangleFiller filler;
};