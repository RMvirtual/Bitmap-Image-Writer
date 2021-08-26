#include <cstdint>
#include <string>

using namespace std;

class BytesConverter
{
public:
  uint32_t getFourBytesFromSubstring(string stringToIndex, int startingIndex);
  uint16_t getTwoBytesFromSubstring(string stringToIndex, int startingIndex);

  uint32_t convertFourCharactersTo32bitInteger(string stringToConvert);
  uint16_t convertTwoCharactersTo16bitInteger(string stringToConvert);

};