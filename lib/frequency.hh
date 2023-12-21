#ifndef CRYPTOPALS_LIB_FREQUENCY_HH
#define CRYPTOPALS_LIB_FREQUENCY_HH

#include <array>
#include <cstddef>
#include <string_view>

namespace cp {
namespace frequency {

std::array<std::size_t, 256> Table(std::string_view);
std::array<double, 256> Score(std::string_view);
std::array<double, 26> LetterScore(std::string_view);
double LetterDistance(std::string_view);

}  // namespace frequency
}  // namespace cp

#endif  // CRYPTOPALS_LIB_FREQUENCY_HH
