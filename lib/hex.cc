#include "lib/hex.hh"

#include <cassert>
#include <cctype>
#include <cstddef>
#include <cstdint>
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

}  // namespace hex
}  // namespace cp
