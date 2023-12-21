#include "lib/base64.hh"

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace {

constexpr std::size_t PaddingSize(
    std::size_t actual_bytes, std::size_t block_size) {
  return (block_size - actual_bytes % block_size) % block_size;
}

template <typename C, typename V>
void Pad(C* container, V padding_value, std::size_t block_size) {
  const std::size_t padding_size = PaddingSize(container->size(), block_size);
  for (std::size_t i = 0; i < padding_size; i++) {
    container->push_back(padding_value);
  }
}

}  // namespace

namespace cp {
namespace base64 {

using namespace std::string_view_literals;
constexpr std::string_view kBase64Alphabet =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="sv;

std::string Encode(const std::vector<bool>& input) {
  std::vector<bool> padded = input;
  Pad(&padded, 0, 6);

  std::string output;
  for (std::size_t i = 0; i < padded.size(); i += 6) {
    std::uint8_t b = padded[i + 0] << 5 | padded[i + 1] << 4 |
                     padded[i + 2] << 3 | padded[i + 3] << 2 |
                     padded[i + 4] << 1 | padded[i + 5] << 0;
    output.push_back(kBase64Alphabet[b]);
  }
  Pad(&output, kBase64Alphabet.back(), 4);
  return output;
}

}  // namespace base64
}  // namespace cp
