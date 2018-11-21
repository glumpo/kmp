#include <inttypes.h>
#include <iostream>
#include "talgoritmkmp.h"

int main() {
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  TAlgoritmKMP kmp;
  kmp.GerPatternFromStdin();
  auto res = kmp.Kmp();

  for (size_t i = 0; i < res.Size(); ++i) {
    std::cout << res[i].pos << " " << res[i].str << std::endl;
  }

  return 0;
}
