#include "talgoritmkmp.h"
#include <queue>

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
  auto sn = inp.StringNumber();
  //  auto sn_res = sn;
  int32_t cur = inp.ReadInt();
  //  size_t i_res = 0;
  //  bool pattern_moved = true;
  for (size_t i = 1; !inp.IsEof(); ++i, cur = inp.ReadInt()) {
    while (q > 0 && pattern[q] != cur) {
      q = pi[q - 1];
      //      pattern_moved = true;
    }

    if (pattern[q] == cur) {
      //      if (pattern_moved) {
      //        sn_res = sn;
      //        i_res = i - q;
      //        pattern_moved = false;
      //      }
      ++q;
    }
    if (m == q) {
      decltype(i) i_res;
      decltype(sn) sn_res;
      if (inp.StringSize(sn) >= m) {
        i_res = i - m + 1;
        sn_res = sn;
      } else {
        auto m_tail = m;
        auto sn_tmp = sn;
        do {
          m_tail -= inp.StringSize(sn_tmp);
          --sn_tmp;
        } while (inp.StringSize(sn_tmp) < m_tail);

        sn_res = sn_tmp;
        i_res = inp.StringSize(sn_res) - m_tail + 1;
      }

      res.PushBack(TPos(i_res, sn_res));
      q = pi[q - 1];
      //      pattern_moved = true;
    }
    auto sn_temp = inp.StringNumber();
    if (sn != sn_temp) {
      sn = sn_temp;
      i = 0;  // Will Be Incremented
    }
  }

  return res;
}
