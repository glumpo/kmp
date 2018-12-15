#include "tinput.h"

letter_t TInput::ReadInt() {
  int c;
  while (isspace(c = getchar())) {
    if ('\n' == c) {
      stringSize.PushBack(0);
      ++stringNumber;
    }
  }
  letter_t res = letter_t(c - '0');
  while (c = getchar(), c >= '0' && c <= '9') {
    res = res * 10 + letter_t(c - '0');
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

TVector<letter_t> TInput::GetString(std::istream &in) {
  TVector<letter_t> res;
  char ch = 0;
  letter_t temp;
  while (ch != '\n') {
    in >> temp;
    res.PushBack(temp);
    in.get(ch);
  }
  return res;
}
