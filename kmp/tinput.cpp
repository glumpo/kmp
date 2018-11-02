#include "tinput.h"

// int32_t TInput::ReadInt() {
//  int32_t res;
//  std::cin >> res;
//  if (std::cin.eof()) {
//    this->isEof = true;
//  }
//  return res;
//}

int32_t TInput::ReadInt() {
  int c;
  c = getchar();
  int32_t res = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') {
    res = res * 10 + (c - '0');
  }

  if ('\n' == c) {
    ++stringNumber;
  }

  if (EOF == c) {
    this->isEof = true;
  }

  return res;
}

TVector<int32_t> TInput::GetString(std::istream &in) {
  TVector<int32_t> res;
  char ch = 0;
  int32_t temp;
  while (ch != '\n') {
    in >> temp;
    res.PushBack(temp);
    in.get(ch);
  }
  return res;
}