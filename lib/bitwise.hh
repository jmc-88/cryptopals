#ifndef CRYPTOPALS_LIB_BITWISE_HH
#define CRYPTOPALS_LIB_BITWISE_HH

#include <cstdint>
#include <vector>

namespace cp {
namespace bitwise {

std::vector<bool> Xor(const std::vector<bool>&, const std::vector<bool>&);
std::vector<bool> Mask(std::uint8_t, const std::vector<bool>&);

}  // namespace bitwise
}  // namespace cp

#endif  // CRYPTOPALS_LIB_BITWISE_HH
