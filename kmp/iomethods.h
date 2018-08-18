#ifndef IOMETHODS_H
#define IOMETHODS_H

#include <inttypes.h>
#include <iostream>

#include "tvector.h"
#include "tvector.cpp"

namespace NInput {
#define IS_INT(c) ((c) >= '0' && (c) <= '9')

static bool IS_EOF = false;
static bool IS_NL  = false;

inline uint32_t read_int() {
  int c;
  uint32_t res = 0;
  while ((c = getchar()) != '\n' && IS_INT(c)) {
    res = res * 10 + uint32_t(c - '0');
  }

  if (EOF == c) {
    IS_EOF = true;
  }

  if ('\n' == c) {
    IS_NL = true;
  }

  return res;
}

inline void read_input(TVector<uint32_t> &inp) {
  uint32_t tmp;
  while (void(tmp = read_int()), !IS_NL) {
    inp.PushBack(tmp);
  }
  inp.PushBack(tmp);
  IS_NL = false; // for future reading
}
} // namespace NInput

#endif // IOMETHODS_H
