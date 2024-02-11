#include <cassert>
#include <iostream>
#include <string_view>

#include "lib/ascii.hh"
#include "lib/bitwise.hh"
#include "lib/hex.hh"

// https://cryptopals.com/sets/1/challenges/5
int main() {
  using namespace std::string_view_literals;
  constexpr auto kInput = R"(Burning 'em, if you ain't quick and nimble
I go crazy when I hear a cymbal)"sv;
  constexpr auto kExpected =
      "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272"sv
      "a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f"sv;

  cp::hex::EncodeString({});

  const auto bits = cp::ascii::DecodeString(kInput);
  const auto xor_data = cp::bitwise::Xor(
      bits, cp::bitwise::Mask(cp::ascii::DecodeString("ICE"), bits.size()));
  assert(cp::hex::EncodeString(xor_data) == kExpected);
}
