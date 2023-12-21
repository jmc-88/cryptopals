#include "lib/ascii.hh"

#include <cassert>
#include <string_view>
#include <vector>

static void TestEncodeString() {
  const std::vector<bool> kInput = {
      0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1,
      1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0,
      1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1,
      1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0,
      1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
  };
  constexpr std::string_view kExpected = "Hello, World!";

  assert(cp::ascii::EncodeString(kInput) == kExpected);
}

int main() {
  TestEncodeString();
}
