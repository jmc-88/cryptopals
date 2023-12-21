#include "lib/hex.hh"

#include <cassert>
#include <string_view>

static void TestDecodeCharacter() {
  assert(cp::hex::DecodeCharacter('0') == 0x0);
  assert(cp::hex::DecodeCharacter('a') == 0xA);
  assert(cp::hex::DecodeCharacter('A') == 0xA);
  assert(cp::hex::DecodeCharacter('f') == 0xF);
  assert(cp::hex::DecodeCharacter('F') == 0xF);
}

static void TestDecodeString() {
  using namespace std::string_view_literals;
  {
    const std::vector<bool> kExpected{
        0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1};
    const auto actual = cp::hex::DecodeString("4927"sv);
    assert(actual == kExpected);
  }
}

static void TestEncodeHalfByte() {
  assert(cp::hex::EncodeHalfByte(0x0) == '0');
  assert(cp::hex::EncodeHalfByte(0x7) == '7');
  assert(cp::hex::EncodeHalfByte(0x9) == '9');
  assert(cp::hex::EncodeHalfByte(0xA) == 'a');
  assert(cp::hex::EncodeHalfByte(0xF) == 'f');
}

static void TestEncodeString() {
  {
    const auto actual =
        cp::hex::EncodeString({1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
                               1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0});
    assert(actual == "babbe0");
  }
}

int main() {
  TestDecodeCharacter();
  TestDecodeString();
  TestEncodeHalfByte();
  TestEncodeString();
}
