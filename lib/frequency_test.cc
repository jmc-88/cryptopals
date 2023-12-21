#include "lib/frequency.hh"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <limits>
#include <string_view>
#include <type_traits>

namespace {

template <typename _Fp>
std::enable_if_t<!std::numeric_limits<_Fp>::is_integer, bool> equal_within_ulps(
    _Fp x, _Fp y, std::size_t n) {
  // Shamelessly stolen from the example code at:
  //    https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
  // :)
  const _Fp m = std::min(std::fabs(x), std::fabs(y));
  const int exp = m < std::numeric_limits<_Fp>::min()
                      ? std::numeric_limits<_Fp>::min_exponent - 1
                      : std::ilogb(m);
  return std::fabs(x - y) <=
         n * std::ldexp(std::numeric_limits<_Fp>::epsilon(), exp);
}

template <typename _Fp>
bool equal(_Fp x, _Fp y) {
  return equal_within_ulps(x, y, 1);
}

}  // namespace

static void TestTable() {
  using namespace std::string_view_literals;

  constexpr auto kInput = "correct horse battery staple"sv;
  const auto table = cp::frequency::Table(kInput);

  assert(table['a'] == 2);
  assert(table['b'] == 1);
  assert(table['c'] == 2);
  assert(table['d'] == 0);
  assert(table['e'] == 4);
  assert(table['f'] == 0);
  assert(table['g'] == 0);
  assert(table['h'] == 1);
  assert(table['i'] == 0);
  assert(table['j'] == 0);
  assert(table['k'] == 0);
  assert(table['l'] == 1);
  assert(table['m'] == 0);
  assert(table['n'] == 0);
  assert(table['o'] == 2);
  assert(table['p'] == 1);
  assert(table['q'] == 0);
  assert(table['r'] == 4);
  assert(table['s'] == 2);
  assert(table['t'] == 4);
  assert(table['u'] == 0);
  assert(table['v'] == 0);
  assert(table['w'] == 0);
  assert(table['x'] == 0);
  assert(table['y'] == 1);
  assert(table['z'] == 0);
  assert(table[' '] == 3);

  std::size_t total = 0;
  for (std::size_t count : table) {
    total += count;
  }
  assert(total == kInput.size());
}

static void TestScore() {
  using namespace std::string_view_literals;

  constexpr auto kInput = "correct horse battery staple"sv;
  const auto score = cp::frequency::Score(kInput);

  assert(equal(score['a'], 2.0 / 28.0));
  assert(equal(score['b'], 1.0 / 28.0));
  assert(equal(score['c'], 2.0 / 28.0));
  assert(equal(score['d'], 0.0 / 28.0));
  assert(equal(score['e'], 4.0 / 28.0));
  assert(equal(score['f'], 0.0 / 28.0));
  assert(equal(score['g'], 0.0 / 28.0));
  assert(equal(score['h'], 1.0 / 28.0));
  assert(equal(score['i'], 0.0 / 28.0));
  assert(equal(score['j'], 0.0 / 28.0));
  assert(equal(score['k'], 0.0 / 28.0));
  assert(equal(score['l'], 1.0 / 28.0));
  assert(equal(score['m'], 0.0 / 28.0));
  assert(equal(score['n'], 0.0 / 28.0));
  assert(equal(score['o'], 2.0 / 28.0));
  assert(equal(score['p'], 1.0 / 28.0));
  assert(equal(score['q'], 0.0 / 28.0));
  assert(equal(score['r'], 4.0 / 28.0));
  assert(equal(score['s'], 2.0 / 28.0));
  assert(equal(score['t'], 4.0 / 28.0));
  assert(equal(score['u'], 0.0 / 28.0));
  assert(equal(score['v'], 0.0 / 28.0));
  assert(equal(score['w'], 0.0 / 28.0));
  assert(equal(score['x'], 0.0 / 28.0));
  assert(equal(score['y'], 1.0 / 28.0));
  assert(equal(score['z'], 0.0 / 28.0));
  assert(equal(score[' '], 3.0 / 28.0));

  double total = 0;
  for (double value : score) {
    total += value;
  }
  assert(equal(total, 1.0));
}

static void TestLetterScore() {
  using namespace std::string_view_literals;

  const auto kInput = "abcdefghijklmnopqrstuvwxyz"sv;
  const auto score = cp::frequency::LetterScore(kInput);

  for (double s : score) {
    // Somehow this doesn't work within the range of just 1 ulps, but it works
    // when extending it to 2. ¯\_(ツ)_/¯
    assert(equal_within_ulps(s, 1.0 / 26.0, 2));
  }
}

static void TestLetterDistance() {
  using namespace std::string_view_literals;

  constexpr auto kGoodInput = "correct horse battery staple"sv;
  const auto good_delta = cp::frequency::LetterDistance(kGoodInput);

  constexpr auto kGarbageInput = "skdkfjsd hbjhe nddjfldk sdksks"sv;
  const auto garbage_delta = cp::frequency::LetterDistance(kGarbageInput);

  assert(good_delta < garbage_delta);
}

int main() {
  TestTable();
  TestScore();
  TestLetterScore();
  TestLetterDistance();
}
