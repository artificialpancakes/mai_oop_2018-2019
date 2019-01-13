#ifndef QUEUE_H
#define QUEUE_H

#include "figures/triangle.h"
#include "tqueueitem.h"
#include <iostream>
#include <cstdlib>

/* Queue of triangles */
class TQueue {
public:
  TQueue();
  ~TQueue();

  void Push(Triangle &&triangle);
  bool IsEmpty();
  Triangle Pop();

  friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);
private:
  TQueueItem *first, *last;
  uint size;
};

#endif
