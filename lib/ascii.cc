#include "lib/ascii.hh"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace cp {
namespace ascii {

std::string EncodeString(const std::vector<bool>& input) {
  assert(input.size() % 8 == 0);

  std::string result;
  for (std::size_t i = 0; i < input.size(); i += 8) {
    const std::uint8_t b = input[i + 0] << 7 | input[i + 1] << 6 |
                           input[i + 2] << 5 | input[i + 3] << 4 |
                           input[i + 4] << 3 | input[i + 5] << 2 |
                           input[i + 6] << 1 | input[i + 7] << 0;
    result.push_back(b);
  }
  return result;
}

}  // namespace ascii
}  // namespace cp
