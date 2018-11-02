#include <benchmark/benchmark.h>
#include <iostream>

#include "../kmp/iomethods.h"
#include "../kmp/tkmpalgo.cpp"
#include "../kmp/tkmpalgo.h"
#include "../kmp/tvector.cpp"
#include "../kmp/tvector.h"

using namespace NInput;

static TKmpAlgo kmp;
static void initialize(int n = 2) {
  static bool initialized = false;
  if (initialized) {
    return;
  }
  initialized = true;
  char buf[100];
  sprintf(buf, "../tests/tests/%.2i.t", n);
  freopen(buf, "r", stdin);

  kmp.GetPatternAndTextFromStdin();
};

static void BM_KMP_CONCATTENATION_PREFIX(benchmark::State &state) {
  for (auto _ : state) {
    kmp.KMPConcatenationPrefix();
  }
}
BENCHMARK(BM_KMP_CONCATTENATION_PREFIX);

static void BM_KMP_CONCATTENATION_Z(benchmark::State &state) {
  for (auto _ : state) {
    kmp.KMPConcatenationZFunction();
  }
}
BENCHMARK(BM_KMP_CONCATTENATION_Z);

int main(int argc, char **argv) {
  initialize();
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
  ::benchmark::RunSpecifiedBenchmarks();
}
