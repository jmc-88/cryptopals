#include <cassert>
#include <fstream>
#include <limits>
#include <string>
#include <string_view>

#include "lib/frequency.hh"
#include "lib/hex.hh"

// https://cryptopals.com/sets/1/challenges/4
int main() {
  using namespace std::string_view_literals;
  constexpr auto kExpected = "Now that the party is jumping\n"sv;

  std::ifstream f{_DATA_PATH "/set1/challenge4.txt"};
  assert(!f.bad());

  double best_distance = std::numeric_limits<double>::infinity();
  std::string best_match = {};

  while (!f.eof()) {
    std::string line;
    std::getline(f, line);
    assert(!f.bad());

    const auto bits = cp::hex::DecodeString(line);
    const auto [text, distance] = cp::frequency::MostLikelyDecoding(bits);
    if (distance < best_distance) {
      best_match = text;
      best_distance = distance;
    }
  }

  assert(best_match == kExpected);
}
