#include "lib/base64.hh"

#include <cassert>
#include <string_view>

static void TestEncode() {
  {
    const char kExpected[] = "TQ==";
    const auto actual = cp::base64::Encode({0, 1, 0, 0, 1, 1, 0, 1});  // "M"
    assert(actual == kExpected);
  }
}

int main() {
  TestEncode();
}