#ifndef TALGORITMKMP_H
#define TALGORITMKMP_H

#include <iostream>
#include <utility>
#include "tinput.h"
#include "tvector.cpp"
#include "tvector.h"

class TAlgoritmKMP {
 private:
  TVector<int32_t> pattern;
  TInput inp = TInput();

 public:
  TVector<size_t> PrefixF(TVector<int32_t> &p);
  void GerPatternFromStdin();
  TVector<std::pair<size_t, int16_t>> Kmp();
};

#endif  // TALGORITMKMP_H
