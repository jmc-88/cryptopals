#include "lib/hex.hh"

#include <cassert>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace cp {
namespace hex {

std::uint8_t DecodeCharacter(char c) {
  assert(isxdigit(c));

  if (c >= 'A' && c <= 'F') {
    return 0xA + c - 'A';
  }
  if (c >= 'a' && c <= 'f') {
    return 0xA + c - 'a';
  }
  return c - '0';
}

std::vector<bool> DecodeString(std::string_view input) {
  std::vector<bool> output;
  for (std::size_t i = 0; i < input.size(); i++) {
    std::uint8_t b = DecodeCharacter(input[i]);
    output.push_back(b & 0b1000);
    output.push_back(b & 0b0100);
    output.push_back(b & 0b0010);
    output.push_back(b & 0b0001);
  }
  return output;
}

char EncodeHalfByte(std::uint8_t b) {
  assert((b & 0b11110000) == 0);
  if (b < 0xA) {
    return '0' + b;
  } else {
    return 'a' + b - 0xA;
  }
}

std::string EncodeString(const std::vector<bool>& input) {
  // TODO: maybe this method should insert padding instead, but I'll defer that
  // to later if the need arises.
  assert(input.size() % 4 == 0);

  std::string result;
  for (std::size_t i = 0; i < input.size(); i += 4) {
    std::uint8_t b = input[i + 0] << 3 | input[i + 1] << 2 | input[i + 2] << 1 |
                     input[i + 3] << 0;
    result.push_back(EncodeHalfByte(b));
  }
  return result;
}

}  // namespace hex
}  // namespace cp
