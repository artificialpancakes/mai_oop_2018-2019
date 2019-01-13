#ifndef QUEUE_H
#define QUEUE_H

#include "figures/figures.h"
#include "tqueueitem.h"
#include <iostream>
#include <memory>
#include <cstdlib>

template <class T>
class TQueue {
public:
  TQueue();
  ~TQueue();

  void Push(std::shared_ptr<T> &&figure);
  bool IsEmpty();
  std::shared_ptr<T> Pop();

  template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
private:
  std::shared_ptr<TQueueItem<T>> first, last;
  uint size;
};

#endif
