#ifndef KMP_H
#define KMP_H
#include <inttypes.h>

#include "tvector.h"
#include "tvector.cpp"

namespace NKmpAlgo {
TVector<size_t> kmpConcatenation(const TVector<uint32_t> &text,
                                 const TVector<uint32_t> &patern);
} // namespace NKmpAlgo
#endif // KMP_H
