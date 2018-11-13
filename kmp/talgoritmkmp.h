#ifndef TALGORITMKMP_H
#define TALGORITMKMP_H

#include <iostream>
#include "tinput.h"
#include "tvector.cpp"
#include "tvector.h"

struct TPos {
  TPos(size_t p, int16_t s) : pos(p), str(s) {}
  size_t pos;
  int16_t str;
};

class TAlgoritmKMP {
 private:
  TVector<int32_t> pattern;
  TInput inp = TInput();

 public:
  TVector<size_t> PrefixF(TVector<int32_t> &p);
  void GerPatternFromStdin();
  TVector<TPos> Kmp();
};

#endif  // TALGORITMKMP_H
