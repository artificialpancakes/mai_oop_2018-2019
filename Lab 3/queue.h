#ifndef QUEUE_H
#define QUEUE_H

#include "figures/figures.h"
#include "tqueueitem.h"
#include <iostream>
#include <memory>
#include <cstdlib>

/* Queue of triangles */
class TQueue {
public:
  TQueue();
  ~TQueue();

  void Push(std::shared_ptr<Figure> &&figure);
  bool IsEmpty();
  std::shared_ptr<Figure> Pop();

  friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);
private:
  std::shared_ptr<TQueueItem> first, last;
  uint size;
};

#endif
