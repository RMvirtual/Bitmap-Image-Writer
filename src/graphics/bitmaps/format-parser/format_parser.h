#include <string>
#include <vector>

#include "src/graphics/bitmaps/packet/pixel-array/format.h"
#include "src/utilities/json_reader.h"

class FormatParser : public Utilities::JSONReader
{
public:
  FormatParser();

  Pixels::Format operator [](std::string formatName);

private:
  std::vector<Pixels::Format> formats;
};