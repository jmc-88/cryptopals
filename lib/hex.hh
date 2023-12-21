#ifndef CRYPTOPALS_LIB_HEX_HH
#define CRYPTOPALS_LIB_HEX_HH

#include <array>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace cp {
namespace hex {

std::uint8_t DecodeCharacter(char);
std::vector<bool> DecodeString(std::string_view input);

char EncodeHalfByte(std::uint8_t);
std::string EncodeString(const std::vector<bool>&);

}  // namespace hex
}  // namespace cp

#endif  // CRYPTOPALS_LIB_HEX_HH
