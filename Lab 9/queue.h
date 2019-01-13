#ifndef QUEUE_H
#define QUEUE_H

#include "figures/figures.h"
#include "tqueueitem.h"
#include <iostream>
#include <memory>
#include "titerator.h"
#include <cstdlib>

template <class T>
class TQueue {
public:
  TQueue();
  ~TQueue();

  void Push(std::shared_ptr<T> &&figure);
  bool IsEmpty();
  std::shared_ptr<T> Pop();

  TIterator<TQueueItem<T>,T> begin();
  TIterator<TQueueItem<T>,T> end();

  void Quicksort();
  void Quicksort_parallel();

  int Size();

  template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
  std::shared_ptr<TQueueItem<T>> first, last;
private:
  uint size;
};

#endif
