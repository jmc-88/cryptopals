#include "lib/bitwise.hh"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iterator>
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

std::vector<bool> Mask(std::uint8_t b, std::size_t bits) {
  const std::vector<bool> key = {
      static_cast<bool>(b & 0b10000000),
      static_cast<bool>(b & 0b01000000),
      static_cast<bool>(b & 0b00100000),
      static_cast<bool>(b & 0b00010000),
      static_cast<bool>(b & 0b00001000),
      static_cast<bool>(b & 0b00000100),
      static_cast<bool>(b & 0b00000010),
      static_cast<bool>(b & 0b00000001),
  };
  return Mask(key, bits);
}

std::vector<bool> Mask(const std::vector<bool>& key, std::size_t bits) {
  assert(bits % 8 == 0);

  std::vector<bool> mask;
  mask.reserve(bits);
  while (mask.size() < bits) {
    std::copy(key.cbegin(), key.cend(), std::back_inserter(mask));
  }
  mask.resize(bits);  // chop off any extra bits, if bits % key.size() != 0
  return mask;
}

}  // namespace bitwise
}  // namespace cp
