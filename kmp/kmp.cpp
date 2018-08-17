#include <kmp.h>

#include <string>
namespace NKmpAlgo {
TVector<size_t> spPrefix(TVector<uint32_t> &inp) {
  size_t n = inp.Size();
  TVector<size_t> pi(n, 0);
  for (size_t i = 1; i < n; ++i) {
    size_t j = pi[i - 1];
    while (j > 0 && inp[i] != inp[j])
      j = pi[j - 1];
    if (inp[i] == inp[j])
      ++j;
    pi[i] = j;
  }
  return pi;
}

// TVector<uint32_t> spDash(TVector<uint32_t> inp) {
//   auto res = TVector<uint32_t>(inp.Size(), 0);
//
//   return res;
// }

TVector<size_t> kmpConcatenation(const TVector<uint32_t> &text,
                                 const TVector<uint32_t> &patern) {
  TVector<uint32_t> s(text.Size() + patern.Size() + 1);

  for (size_t i = 0; i < patern.Size(); ++i) {
    s.PushBack(patern[i]);
  }

  s.PushBack('#');

  for (size_t i = 0; i < text.Size(); ++i) {
    s.PushBack(text[i]);
  }

  auto pi = spPrefix(s);
  const auto n = patern.Size();
  TVector<size_t> res;
  for (size_t i = n; i < pi.Size(); ++i) {
    if (n == pi[i]) {
      res.PushBack(i - n - n + 1); // + 1 becouze indexing starts from 1
    }
  }
  return res;
}


} // namespace NKmpAlgo
