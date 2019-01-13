#ifndef TVECTOR_H
#define TVECTOR_H

#include "figures/figures.h"
#include <iostream>
#include <memory>

template <class T>
class TVector {
public:
  TVector();
  ~TVector();
  bool Insert(std::shared_ptr<T> &&item);
  template<class A> void Remove_type();
  void Remove_lesser(double area);
  std::shared_ptr<T> Remove(int i);
  std::shared_ptr<T> Get(int i) const;
  int Size();

  template <class A> friend std::ostream& operator<<(std::ostream& os, const TVector<A>& queue);
private:

  std::shared_ptr<T> arr[5];
  int size;
};

#endif
