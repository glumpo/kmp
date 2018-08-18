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

inline void write_int(size_t x) {
  char buf[10], *p = buf;
  do
  {
    *p++ = '0' + x % 10;
    x /= 10;
  } while (x);
  do
  {
    putchar(*--p);
  } while (p > buf);
}

inline bool read_int(uint32_t &res)
{
  int c;
  res = 0;

  c = getchar();
  if (EOF == c) {
    IS_EOF = true;
    return  false;
  }
  res = uint32_t(c - '0');

  while ((c = getchar()) && IS_INT(c)) {
    res = res * 10 + uint32_t(c - '0');
  }

  if (EOF == c) {
    IS_EOF = true;
  }

  if ('\n' == c) {
    IS_NL = true;
  }

  return true;
}

inline void get_inp(TVector<uint32_t> &inp,
                    TVector<size_t> &wordsCount) {
  while (!IS_EOF) {
    size_t wc = 0;
    uint32_t c;
    while (!IS_NL && read_int(c)) {
      inp.PushBack(c);
      ++wc;
    }
    IS_NL = false;
    wordsCount.PushBack(wc);
  }
}
} // namespace NInput

#endif // IOMETHODS_H
