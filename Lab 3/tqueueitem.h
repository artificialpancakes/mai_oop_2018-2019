#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H

#include "figures/figures.h"
#include <memory>

class TQueueItem {
public:
  TQueueItem(const std::shared_ptr<Figure>& figure);
  ~TQueueItem();

  void SetNext(std::shared_ptr<TQueueItem> item);
  std::shared_ptr<TQueueItem> GetNext();
  std::shared_ptr<Figure> Get();

  friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);
private:
  std::shared_ptr<Figure> figure;
  std::shared_ptr<TQueueItem> next;
};

#endif
