#include "lib/frequency.hh"

#include <array>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "lib/ascii.hh"
#include "lib/bitwise.hh"

namespace {

// For reference, see:
// https://en.wikipedia.org/wiki/Letter_frequency#Relative_frequencies_of_letters_in_the_English_language
constexpr std::array<double, 26> kLetterFrequencies{
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015,
    0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749,
    0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758,
    0.00978, 0.02360, 0.00150, 0.01974, 0.00074,
};

std::array<double, 26> LetterScore(const std::array<double, 256>& score) {
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

}  // namespace

namespace cp {
namespace frequency {

std::array<std::size_t, 256> Table(std::string_view input) {
  std::array<std::size_t, 256> result = {};
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

double LetterDistance(std::string_view input) {
  const auto score = Score(input);
  const auto letters = LetterScore(score);

  double result = 0.0;
  for (std::size_t i = 0; i < kLetterFrequencies.size(); i++) {
    result += std::fabs(letters[i] - kLetterFrequencies[i]);
  }

  // Penalize use of non-alphabetical characters, while still allowing spaces.
  double penalty = 0.0;
  for (std::size_t b = 0; b < 256; b++) {
    if (b == ' ') {
      continue;
    }
    if (!std::isalpha(b)) {
      penalty += score[b];
    }
  }

  return result + penalty;
}

std::pair<std::string, double> MostLikelyDecoding(
    const std::vector<bool>& bits) {
  double best_distance = std::numeric_limits<double>::infinity();
  std::string best_match = {};

  for (std::uint8_t b = 0; b < 255; b++) {
    const auto xor_data =
        cp::bitwise::Xor(bits, cp::bitwise::Mask(b, bits.size()));
    const auto text = cp::ascii::EncodeString(xor_data);
    const auto delta = LetterDistance(text);
    if (delta < best_distance) {
      best_match = text;
      best_distance = delta;
    }
  }
  return {best_match, best_distance};
}

}  // namespace frequency
}  // namespace cp
