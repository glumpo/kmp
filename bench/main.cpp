#include <iostream>
#include <benchmark/benchmark.h>


#include "../kmp/tvector.h"
#include "../kmp/tvector.cpp"
#include "../kmp/kmp.h"
#include "../kmp/kmp.cpp"
#include "../kmp/iomethods.h"

using namespace NInput;

static void BM_KMP_CONCATTENATION(benchmark::State &state) {
  TVector<uint32_t> pattern, text;
  TVector<size_t> res;

  char buf[50];
  sprintf(buf, "../tests/tests/%.2i.t", int(state.range(0)));

  freopen(buf, "r", stdin);
  read_inp(pattern);

  for (auto _ : state) {
    NKmpAlgo::kmpConcatenation(text, pattern);
  }
}
BENCHMARK(BM_KMP_CONCATTENATION)->Arg(0)->Arg(1)->Arg(2);


BENCHMARK_MAIN();
