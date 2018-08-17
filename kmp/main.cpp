#include <inttypes.h>
#include <iostream>

#include <tvector.h>
#include <tvector.cpp>
#include <kmp.h>

#define IS_INT(c) ((c) >= '0' && (c) <= '9')

namespace {
bool IS_EOF = false;
bool IS_NL  = false;
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
}  // namespace

inline void read_input(TVector<uint32_t> &inp) {
  uint32_t tmp;
  while (void(tmp = read_int()), !IS_NL) {
    inp.PushBack(tmp);
  }
  inp.PushBack(tmp);
  IS_NL = false; // for future reading
}

int main() {
  TVector<uint32_t> text, patern;
  read_input(text);
  read_input(patern);
  auto res = NKmpAlgo::kmpConcatenation(text, patern);
  for (size_t i = 0; i < res.Size(); ++i) {
    std::cout << res[i] << " ";
  }
  return 0;
}
