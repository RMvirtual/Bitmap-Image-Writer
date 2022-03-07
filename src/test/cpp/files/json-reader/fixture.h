#pragma once

#include "gtest/gtest.h"
#include "src/main/cpp/files/json-reader/json_reader.h"

class JSONReaderTest : public testing::Test
{
public:
  JSONReaderTest();
  ~JSONReaderTest();

protected:
  Files::JSONReader reader;
  std::string filePath;

  void asArrayFile();
  void asObjectFile();
  void asNestedObjectsFile();

};