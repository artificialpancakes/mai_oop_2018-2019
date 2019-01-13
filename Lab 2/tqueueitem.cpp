#include "tqueueitem.h"

TQueueItem::TQueueItem(const Triangle& triangle) {
  std::cout << "Queue item: constructor begin" << std::endl;
  this->triangle = triangle;
  this->next = nullptr;
  std::cout << "Queue item: constructor end" << std::endl;
}

void TQueueItem::SetNext(TQueueItem* item) {
    this->next = item;
}

TQueueItem* TQueueItem::GetNext() {
    return this->next;
}

TQueueItem::~TQueueItem() {
    std::cout << "Queue item: deleted" << std::endl;
    delete next;
}

Triangle TQueueItem::Get() {
  return this->triangle;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
  os << "[" << obj.triangle << "]" << std::endl;
  return os;
}
