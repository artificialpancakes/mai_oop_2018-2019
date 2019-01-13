#include "queue.h"
#include <stdlib.h>

TQueue::TQueue() : first(nullptr), last(nullptr), size(0) {}
TQueue::~TQueue() {
  delete first;
}

void TQueue::Push(Triangle &&triangle) {
  TQueueItem *other = new TQueueItem(triangle);
  other->SetNext(nullptr);
  if (last != nullptr) {
    last->SetNext(other);
  }
  last = other;
  if (first == nullptr) {
    first = other;
  }
}

bool TQueue::IsEmpty() {
  return first == nullptr;
}

Triangle TQueue::Pop() {
  if (first != nullptr) {
    Triangle result;
    TQueueItem *old_first = first;
    first = first->GetNext();
    result = old_first->Get();
    old_first->SetNext(nullptr);
    delete old_first;
    return result;
  }
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {
  TQueueItem *item = queue.first;

  while (item != nullptr) {
    os << *item;
    item = item->GetNext();
  }

  return os;
}
