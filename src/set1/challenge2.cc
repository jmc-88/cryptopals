#include <cassert>
#include <string_view>

#include "lib/base64.hh"
#include "lib/bitwise.hh"
#include "lib/hex.hh"

// https://cryptopals.com/sets/1/challenges/2
int main() {
  using namespace std::string_view_literals;
  constexpr std::string_view kInput1 = "1c0111001f010100061a024b53535009181c"sv;
  constexpr std::string_view kInput2 = "686974207468652062756c6c277320657965"sv;
  constexpr std::string_view kExpected =
      "746865206b696420646f6e277420706c6179"sv;

  const auto bits1 = cp::hex::DecodeString(kInput1);
  const auto bits2 = cp::hex::DecodeString(kInput2);
  const auto xor_bits = cp::bitwise::Xor(bits1, bits2);
  const auto result = cp::hex::EncodeString(xor_bits);
  assert(result == kExpected);
}
