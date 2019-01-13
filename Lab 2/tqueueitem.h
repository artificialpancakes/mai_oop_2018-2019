#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H

#include "figures/triangle.h"

class TQueueItem {
public:
  TQueueItem(const Triangle &triangle);
  ~TQueueItem();

  void SetNext(TQueueItem *item);
  TQueueItem* GetNext();
  Triangle Get();

  friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);
private:
  Triangle triangle;
  TQueueItem *next;
};

#endif
