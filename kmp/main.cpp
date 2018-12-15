#include <inttypes.h>
#include <iostream>
#include "talgoritmkmp.h"

// FIXME: ints counter
// FIXME: int32_t may be too small, uint32_t is better solution

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  TAlgoritmKMP kmp;
  kmp.GetPatternFromStdin();
  auto res = kmp.Kmp();

  for (size_t i = 0; i < res.Size(); ++i) {
    std::cout << res[i].str << ", " << res[i].pos << std::endl;
  }

  return 0;
}
