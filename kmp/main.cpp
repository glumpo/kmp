#include <inttypes.h>
#include <iostream>

#include <tvector.h>
#include <tvector.cpp>
#include <kmp.h>
#include <iomethods.h>

using namespace NInput;

int main() {
  TVector<uint32_t> text, patern;
  read_input(patern);
  read_input(text);
  auto res = NKmpAlgo::kmpConcatenation(text, patern);
  for (size_t i = 0; i < res.Size(); ++i) {
    std::cout << res[i] << " ";
  }
  return 0;
}
