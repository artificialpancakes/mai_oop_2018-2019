#include "queue.h"
#include <stdlib.h>

TQueue::TQueue() : first(nullptr), last(nullptr), size(0) {}
TQueue::~TQueue() {}

void TQueue::Push(std::shared_ptr<Figure> &&figure) {
  std::shared_ptr<TQueueItem> other(new TQueueItem(figure));
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

std::shared_ptr<Figure> TQueue::Pop() {
  if (first != nullptr) {
    std::shared_ptr<Figure> result;
    std::shared_ptr<TQueueItem> old_first = first;
    first = first->GetNext();
    result = old_first->Get();
    old_first->SetNext(nullptr);
    return result;
  }
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {
  std::shared_ptr<TQueueItem> item = queue.first;

  while (item != nullptr) {
    os << *item;
    item = item->GetNext();
  }

  return os;
}
