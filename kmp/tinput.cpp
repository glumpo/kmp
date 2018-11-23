#include "tinput.h"

int32_t TInput::ReadInt() {
  int c;
  while (isspace(c = getchar()))
    ;
  int32_t res = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') {
    res = res * 10 + (c - '0');
  }

  stringSize[size_t(stringNumber - 1)] += 1;

  if ('\n' == c) {
    stringSize.PushBack(0);
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
