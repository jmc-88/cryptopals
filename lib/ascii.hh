#ifndef CRYPTOPALS_LIB_ASCII_HH
#define CRYPTOPALS_LIB_ASCII_HH

#include <string>
#include <string_view>
#include <vector>

namespace cp {
namespace ascii {

std::vector<bool> DecodeString(std::string_view);
std::string EncodeString(const std::vector<bool>&);

}  // namespace ascii
}  // namespace cp

#endif  // CRYPTOPALS_LIB_ASCII_HH
