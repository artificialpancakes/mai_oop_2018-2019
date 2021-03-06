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

  void Insert(std::shared_ptr<Figure> &&figure);
  std::shared_ptr<Figure> Remove(int i, int j);
  void Remove_lesser(double area);
  template <class A> void Remove_type();

  void Push(std::shared_ptr<T> &&figure);
  bool IsEmpty();
  std::shared_ptr<T> Pop();

  TIterator<TQueueItem<T>,T> begin();
  TIterator<TQueueItem<T>,T> end();

  template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
private:
  std::shared_ptr<TQueueItem<T>> first, last;
  uint size;
};

#endif
