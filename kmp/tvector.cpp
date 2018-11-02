#ifndef TVECTOR_CPP
#define TVECTOR_CPP

#include "tvector.h"

template <class T>
size_t TVector<T>::highCloseTwoPowerSystemSpecific(size_t x) const {
  const size_t X_CAPACITY = 32;
  x--;
  for (size_t p = 1; p < X_CAPACITY; p <<= 1) x |= (x >> p);
  return ++x;
}

template <class T>
size_t TVector<T>::highCloseTwoPower(size_t x) const {
  if (0 == x) {
    return x;
  }

  size_t p2 = 1;
  while (1) {
    if (p2 >= x) return p2;
    p2 <<= 1;
  }

  //   Not realy needed
  //  return size_t(0);
}

template <class T>
TVector<T>::TVector(const size_t size) {
  this->RealSize = highCloseTwoPower(size);
  this->LastIndex = 0;
  if (0 == RealSize) {
    this->Data = nullptr;
  } else {
    this->Data = (T *)malloc(this->RealSize * sizeof(T));
  }
}

template <class T>
TVector<T>::~TVector() {
  free(this->Data);
  this->Data = nullptr;
  this->LastIndex = 0;
  this->RealSize = 0;
}

template <class T>
TVector<T> &TVector<T>::operator=(TVector<T> &&other) noexcept {
  free(this->Data);

  this->Data = other.Data;
  this->RealSize = other.RealSize;
  this->LastIndex = other.LastIndex;

  other.Data = nullptr;
  return *this;
}

template <class T>
TVector<T>::TVector(TVector &&other) noexcept {
  this->Data = other.Data;
  this->LastIndex = other.LastIndex;
  this->RealSize = other.RealSize;

  other.Data = nullptr;
  other.LastIndex = 0;
  other.RealSize = 0;
}

template <class T>
void TVector<T>::PushBack(T el) {
  if (this->RealSize == this->LastIndex) {
    auto tmpData = this->Data;

    if (0 == this->RealSize)
      this->RealSize = 1;
    else
      this->RealSize *= this->STEP;

    this->Data = (T *)realloc(this->Data, this->RealSize * sizeof(T));

    if (nullptr == this->Data) {
      this->Data = tmpData;
      this->RealSize /= this->STEP;
      throw std::bad_alloc();
    }
  }
  this->Data[this->LastIndex] = el;
  this->LastIndex += 1;
}

template <class T>
T &TVector<T>::operator[](const size_t index) const {
  if (index >= this->LastIndex) this->LastIndex = index + 1;
  T &res = this->Data[index];
  return res;
}

template <class T>
size_t TVector<T>::Size() const {
  return this->LastIndex;
}

#endif  // TVECTOR_CPP
