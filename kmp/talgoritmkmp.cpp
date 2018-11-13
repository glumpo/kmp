#include "talgoritmkmp.h"

TVector<size_t> TAlgoritmKMP::PrefixF(TVector<int32_t> &p) {
  auto n = p.Size();
  auto pi = TVector<size_t>(n);
  pi[0] = 0;

  size_t k = 0;
  for (size_t q = 1; q < n; ++q) {
    while (k > 0 && p[k] != p[q]) {
      k = pi[k];
    }
    if (p[k] == p[q]) {
      ++k;
    }
    pi[q] = k;
  }
  return pi;
}

void TAlgoritmKMP::GerPatternFromStdin() { pattern = inp.GetString(std::cin); }

TVector<TPos> TAlgoritmKMP::Kmp() {
  auto pi = PrefixF(pattern);
  const auto m = pattern.Size();

  auto res = TVector<TPos>();
  size_t q = 0;
  int32_t cur;
  cur = inp.ReadInt();
  auto sn = inp.StringNumber();
  for (size_t i = 1; !inp.IsEof(); ++i, cur = inp.ReadInt()) {
    while (q > 0 && pattern[q] != cur) {
      q = pi[q];
    }

    if (pattern[q] == cur) {
      ++q;
    }
    if (m == q) {
      res.PushBack(TPos(i - m + 1, sn));
      q = pi[q];
    }
    auto sn_temp = inp.StringNumber();
    if (sn != sn_temp) {
      sn = sn_temp;
      i = 0;  // Will Be Incremented
    }
  }

  return res;
}
