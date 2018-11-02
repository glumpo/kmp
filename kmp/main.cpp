#include <inttypes.h>
#include <talgoritmkmp.h>
#include <iostream>

// vector<size_t> z_f(vector<int32_t> &s) {
//  size_t n = s.size();
//  auto z = vector<size_t>(n);
//  for (size_t i = 1, l = 0, r = 0; i < n; ++i) {
//    if (i <= r) {
//      z[i] = min(r - i + 1, z[i - l]);
//    }
//    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
//      ++z[i];
//    }
//    if (i + z[i] - 1 > r) {
//      l = i;
//      r = i + z[i] - 1;
//    }
//  }
//  return z;
//}

// vector<size_t> sp_strong_z(vector<int32_t> &p) {
//  size_t n = p.size();
//  auto sp = vector<size_t>(n, 0);
//  auto z = z_f(p);
//  for (size_t i = n - 1; i >= 1; --i) {
//    size_t j = i + z[i] - 1;
//    sp[j] = z[i];
//  }
//  return sp;
//}

///*
// * Needs 4*p.size() memory
// */
// vector<size_t> fail_f_strong(vector<int32_t> &p) {
//  auto sp = sp_strong_z(p);
//  auto n = sp.size() + 1;
//  auto f = vector<size_t>(n);

//  for (size_t i = 1; i < n; ++i) {
//    f[i] = sp[i - 1] + 1;
//  }
//  return f;
//}

// vector<size_t> kmp(vector<int32_t> &pattern, vector<int32_t> &text) {
//  auto f_st = fail_f_strong(pattern);
//  auto n = pattern.size();
//  auto m = text.size();
//  size_t c = 0, p = 0;

//  auto res = vector<size_t>();

//  while (c + (n - p) < m) {
//    while (p < n && pattern[p] == text[c]) {
//      ++p;
//      ++c;
//    }
//    if (n == p) {
//      res.push_back(c - n);
//    }

//    if (0 == p) {
//      ++c;
//    }

//    p = f_st[p];
//  }
//  return res;
//}

int main() {
  TAlgoritmKMP kmp;
  kmp.GerPatternFromStdin();
  auto res = kmp.Kmp();

  for (size_t i = 0; i < res.Size(); ++i) {
    std::cout << res[i].first << " " << res[i].second << std::endl;
  }

  return 0;
}
