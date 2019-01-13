#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H

#include "tallocationblock.h"
#include "figures/figures.h"
#include <memory>

template <class T>
class TQueueItem {
public:
  TQueueItem(const std::shared_ptr<T>& figure);
  ~TQueueItem();

  void SetNext(std::shared_ptr<TQueueItem<T>> item);
  std::shared_ptr<TQueueItem<T>> GetNext();
  std::shared_ptr<T> Get();

  void* operator new (size_t size);
  void  operator delete (void *p);

  template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);
private:
  std::shared_ptr<T> figure;
  std::shared_ptr<TQueueItem<T>> next;

  static TAllocationBlock queueitem_allocator;
};

#endif
