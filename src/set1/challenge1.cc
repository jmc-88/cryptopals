#include <cassert>
#include <string_view>

#include "lib/base64.hh"
#include "lib/hex.hh"

// https://cryptopals.com/sets/1/challenges/1
int main() {
  using namespace std::string_view_literals;
  constexpr std::string_view kInput =
      "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"sv;
  constexpr std::string_view kExpected =
      "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"sv;

  const auto bits = cp::hex::DecodeString(kInput);
  const auto result = cp::base64::Encode(bits);
  assert(result == kExpected);
}
