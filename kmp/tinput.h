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

 public:
  int32_t ReadInt();
  //  int32_t ReadIntFast();
  TVector<int32_t> GetString(std::istream &in);
  inline int16_t StringNumber() { return stringNumber; }
  inline bool IsEof() { return isEof; }
};

#endif  // TALGORITHMKMP_H
