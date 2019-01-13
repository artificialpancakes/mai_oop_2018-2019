#include "tqueueitem.h"

TQueueItem::TQueueItem(const std::shared_ptr<Figure>& figure) {
  std::cout << "Queue item: constructor begin" << std::endl;
  this->figure = figure;
  this->next = nullptr;
  std::cout << "Queue item: constructor end" << std::endl;
}

void TQueueItem::SetNext(std::shared_ptr<TQueueItem> item) {
    this->next = item;
}

std::shared_ptr<TQueueItem> TQueueItem::GetNext() {
    return this->next;
}

TQueueItem::~TQueueItem() {
    std::cout << "Queue item: deleted" << std::endl;
}

std::shared_ptr<Figure> TQueueItem::Get() {
  return this->figure;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
  os << "[" << *obj.figure << "]" << std::endl;
  return os;
}
