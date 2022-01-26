#include <gtest/gtest.h>
#include "src/utilities/json_reader.h"

TEST(JSONReaderTests, ShouldGetFormatNameFromFirstEntry)
{
  Utilities::JSONReader reader {};
  auto formatName = reader.getFormatName(0);

  EXPECT_EQ(formatName, "RGBA");
}