#ifndef TALGORITHMKMP_H
#define TALGORITHMKMP_H

#include <iostream>
#include <utility>
#include "tvector.cpp"
#include "tvector.h"

class TInput {
 private:
  int16_t stringNumber = 1;
  bool isEof = false;
  TVector<size_t> stringSize = TVector<size_t>(1, 0);

 public:
  int32_t ReadInt();
  TVector<int32_t> GetString(std::istream &in);
  inline int16_t StringNumber() { return stringNumber; }
  inline bool IsEof() { return isEof; }
  inline size_t StringSize(int16_t n) { return stringSize[size_t(n - 1)]; }
};

#endif  // TALGORITHMKMP_H
