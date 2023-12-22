#ifndef CRYPTOPALS_LIB_FREQUENCY_HH
#define CRYPTOPALS_LIB_FREQUENCY_HH

#include <array>
#include <cstddef>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace cp {
namespace frequency {

std::array<std::size_t, 256> Table(std::string_view);
std::array<double, 256> Score(std::string_view);
double LetterDistance(std::string_view);
std::pair<std::string, double> MostLikelyDecoding(const std::vector<bool>&);

}  // namespace frequency
}  // namespace cp

#endif  // CRYPTOPALS_LIB_FREQUENCY_HH
