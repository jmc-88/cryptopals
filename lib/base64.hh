#ifndef CRYPTOPALS_LIB_BASE64_HH
#define CRYPTOPALS_LIB_BASE64_HH

#include <string>
#include <vector>

namespace cp {
namespace base64 {

std::string Encode(const std::vector<bool>&);

}  // namespace base64
}  // namespace cp

#endif  // CRYPTOPALS_LIB_BASE64_HH
