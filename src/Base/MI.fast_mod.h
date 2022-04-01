#pragma once

namespace mi::internal {
template<class Ty>
size_t number_bits(Ty n) {
  size_t result = 0;

  for (size_t i = 0; n != 0; ++i) {
    result++;
    n /= 2;
  }

  return result;
}
}  // namespace mi::internal

namespace mi {
// (a^x)%p
template<class Ty>
decltype(auto) fast_mod(Ty a, Ty x, Ty p) {
}
}  // namespace mi