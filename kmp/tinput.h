#ifndef TALGORITHMKMP_H
#define TALGORITHMKMP_H

#include <iostream>
#include <utility>
#include "kmp_typedefs.h"
#include "tvector.cpp"
#include "tvector.h"

class TInput {
 private:
  str_number_t stringNumber = 1;
  bool isEof = false;
  TVector<size_t> stringSize = TVector<size_t>(1, 0);

 public:
  letter_t ReadInt();
  TVector<letter_t> GetString(std::istream &in);
  // NOTE: I should throw exception if StringNumber used befor ReadInt
  // Or (it`s better) make some buffer and read ints from string number if
  // needed
  inline str_number_t StringNumber() { return stringNumber; }
  inline bool IsEof() { return isEof; }
  inline size_t StringSize(str_number_t n) { return stringSize[size_t(n - 1)]; }
};

#endif  // TALGORITHMKMP_H
