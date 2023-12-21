#include <cassert>
#include <cstdint>
#include <limits>
#include <string_view>
#include <vector>

#include "lib/ascii.hh"
#include "lib/bitwise.hh"
#include "lib/frequency.hh"
#include "lib/hex.hh"

// https://cryptopals.com/sets/1/challenges/3
int main() {
  using namespace std::string_view_literals;
  constexpr std::string_view kInput =
      "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"sv;
  constexpr std::string_view kExpected = "Cooking MC's like a pound of bacon"sv;

  double best_distance = std::numeric_limits<double>::infinity();
  std::string best_match;

  const auto bits = cp::hex::DecodeString(kInput);
  for (std::uint8_t b = 0; b < 255; b++) {
    const auto xor_data = cp::bitwise::Xor(bits, cp::bitwise::Mask(b, bits));
    const auto text = cp::ascii::EncodeString(xor_data);
    const auto delta = cp::frequency::LetterDistance(text);
    if (delta < best_distance) {
      best_match = text;
      best_distance = delta;
    }
  }
  assert(best_match == kExpected);
}
