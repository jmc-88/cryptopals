#include "lib/bitwise.hh"

#include <cassert>
#include <vector>

static void TestXor() {
  const std::vector<bool> kExpected = {1, 1, 0, 1};
  assert(cp::bitwise::Xor({1, 0, 1, 0}, {0, 1, 1, 1}) == kExpected);
}

static void TestMask() {
  {
    const std::vector<bool> kExpected = {
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    };
    assert(cp::bitwise::Mask(0b10101010, 4 * 8) == kExpected);
  }

  {
    const std::vector<bool> kExpected = {
        1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
        1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
    };
    assert(cp::bitwise::Mask({1, 1, 1, 1, 0, 0, 0, 0}, 4 * 8) == kExpected);
  }
}

int main() {
  TestXor();
  TestMask();
}
