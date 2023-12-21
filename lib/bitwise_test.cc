#include "lib/bitwise.hh"

#include <cassert>
#include <vector>

static void TestXor() {
  {
    const std::vector<bool> kExpected = {1, 1, 0, 1};
    assert(cp::bitwise::Xor({1, 0, 1, 0}, {0, 1, 1, 1}) == kExpected);
  }
}

int main() {
  TestXor();
}
