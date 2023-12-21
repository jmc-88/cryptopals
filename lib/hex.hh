#ifndef CRYPTOPALS_LIB_HEX_HH
#define CRYPTOPALS_LIB_HEX_HH

#include <cstdint>
#include <string_view>
#include <vector>

namespace cp {
namespace hex {

uint8_t DecodeCharacter(char);
std::vector<bool> DecodeString(std::string_view input);

}  // namespace hex
}  // namespace cp

#endif  // CRYPTOPALS_LIB_HEX_HH
