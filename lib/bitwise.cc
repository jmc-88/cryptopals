#include "lib/bitwise.hh"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace cp {
namespace bitwise {

std::vector<bool> Xor(
    const std::vector<bool>& bits1, const std::vector<bool>& bits2) {
  assert(bits1.size() == bits2.size());

  std::vector<bool> result;
  result.reserve(bits1.size());
  for (std::size_t i = 0; i < bits1.size(); i++) {
    result.push_back(bits1[i] ^ bits2[i]);
  }
  return result;
}

std::vector<bool> Mask(std::uint8_t b, const std::vector<bool>& bits) {
  assert(bits.size() % 8 == 0);
  std::vector<bool> mask;
  while (mask.size() != bits.size()) {
    mask.push_back(b & 0b10000000);
    mask.push_back(b & 0b01000000);
    mask.push_back(b & 0b00100000);
    mask.push_back(b & 0b00010000);
    mask.push_back(b & 0b00001000);
    mask.push_back(b & 0b00000100);
    mask.push_back(b & 0b00000010);
    mask.push_back(b & 0b00000001);
  }
  return mask;
}

}  // namespace bitwise
}  // namespace cp
