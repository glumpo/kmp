#include <inttypes.h>
#include <iostream>

#include <tvector.h>
#include <tvector.cpp>
#include <kmp.h>
#include <iomethods.h>

using namespace NInput;

int main() {
  TVector<uint32_t> text, patern;
  TVector<size_t> wordsCount;

  while (!IS_NL) {
    uint32_t c = 0;
    read_int(c);
    patern.PushBack(c);
  }
  IS_NL = false;

  get_inp(text, wordsCount);

  TVector<size_t> res = NKmpAlgo::kmpConcatenation(text, patern);

  size_t pos = 0, lineNumber = 0, prevSum = 0;
  for (size_t i = 0; i < res.Size(); ++i) {
    pos = res[i] - prevSum;
    if (pos > wordsCount[lineNumber]) {
      prevSum += wordsCount[lineNumber];
      pos -= wordsCount[lineNumber];
      ++lineNumber;
    }
    std::cout << lineNumber + 1 << ", " << pos << std::endl;
    // write_int(lineNumber);
    // putchar(',');
    // putchar(' ');
    // write_int(res[i] % (allWords - lineWords));
  }
  return 0;
}
