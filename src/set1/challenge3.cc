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
  constexpr auto kInput =
      "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"sv;
  constexpr auto kExpected = "Cooking MC's like a pound of bacon"sv;

  const auto bits = cp::hex::DecodeString(kInput);
  const auto [result, _] = cp::frequency::MostLikelyDecoding(bits);
  assert(result == kExpected);
}
