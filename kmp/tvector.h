#ifndef TVECTOR_H
#define TVECTOR_H

#include <cstdlib>
#include <exception>
#include <new>

template <class T>
class TVector {
public:
  TVector(const size_t size);
  TVector(const size_t size, T x)
    : TVector(size) {
    for (size_t i = 0; i < size; ++i) {
      Data[i] = x;
    }
  }
  TVector() : TVector(0) {}

  virtual ~TVector();
  TVector(TVector<T> &&other) noexcept;
  TVector<T> &operator=(TVector<T> &&other) noexcept;

  void PushBack(T el);
  T &operator[](const size_t index) const;
  size_t Size() const;

protected:
  TVector(const TVector &) = delete;
  void operator=(const TVector &) = delete;

  T *Data;
  size_t RealSize;
  mutable size_t LastIndex;
  static const size_t STEP = 2;

  size_t highCloseTwoPower(size_t x) const;
  size_t highCloseTwoPowerSystemSpecific(size_t x) const;
};

#endif  // TVECTOR_H
