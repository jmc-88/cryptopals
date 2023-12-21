#include "lib/frequency.hh"

#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <string_view>

namespace {

// For reference, see:
// https://en.wikipedia.org/wiki/Letter_frequency#Relative_frequencies_of_letters_in_the_English_language
constexpr std::array<double, 26> kLetterFrequencies{
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015,
    0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749,
    0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758,
    0.00978, 0.02360, 0.00150, 0.01974, 0.00074,
};

}  // namespace

namespace cp {
namespace frequency {

std::array<std::size_t, 256> Table(std::string_view input) {
  std::array<std::size_t, 256> result;
  for (std::uint8_t c : input) {
    result[c]++;
  }
  return result;
}

std::array<double, 256> Score(std::string_view input) {
  const auto table = Table(input);

  std::array<double, 256> result;
  for (std::size_t i = 0; i < table.size(); i++) {
    result[i] =
        static_cast<double>(table[i]) / static_cast<double>(input.size());
  }
  return result;
}

std::array<double, 26> LetterScore(std::string_view input) {
  const auto score = Score(input);

  std::array<double, 26> letters;
  for (std::size_t i = 0; i < letters.size(); i++) {
    letters[i] = score[i + 'a'] + score[i + 'A'];
  }

  double sum = 0.0;
  for (double d : letters) {
    sum += d;
  }

  double k = 1.0 / sum;
  for (std::size_t i = 0; i < letters.size(); i++) {
    letters[i] = k * letters[i];
  }

  return letters;
}

double LetterDistance(std::string_view input) {
  const auto score = LetterScore(input);

  double result = 0.0;
  for (std::size_t i = 0; i < kLetterFrequencies.size(); i++) {
    result += std::fabs(score[i] - kLetterFrequencies[i]);
  }
  return result;
}

}  // namespace frequency
}  // namespace cp
