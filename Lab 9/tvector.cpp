#include "tvector.hpp"
#include <cstdlib>
#include "queue.h"
#include "figures/figures.h"

template <class T>
TVector<T>::TVector() : capacity(64), size(0) {
  body = new T[capacity];
}

template <class T>
TVector<T>::~TVector() {}

template <class T>
void TVector<T>::Push(T item) {
  if (size < capacity) {
    body[size] = item;
    size++;
  }
}

template <class T>
T& TVector<T>::operator[](int index) {
  return body[index];
}

template <class T>
int TVector<T>::Size() {
  return size;
}

template class TVector<void(*)(TQueue<Figure>&)>;
