#include "queue.h"
#include <stdlib.h>


template <class T>
TQueue<T>::TQueue() : first(nullptr), last(nullptr), size(0) {}
template <class T>
TQueue<T>::~TQueue() {}

template <class T>
void TQueue<T>::Push(std::shared_ptr<T> &&figure) {
  std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(figure));
  other->SetNext(nullptr);
  if (last != nullptr) {
    last->SetNext(other);
  }
  last = other;
  if (first == nullptr) {
    first = other;
  }
}

template <class T>
bool TQueue<T>::IsEmpty() {
  return first == nullptr;
}

template <class T>
std::shared_ptr<T> TQueue<T>::Pop() {
  if (first != nullptr) {
    std::shared_ptr<T> result;
    std::shared_ptr<TQueueItem<T>> old_first = first;
    first = first->GetNext();
    result = old_first->Get();
    old_first->SetNext(nullptr);
    return result;
  }
}

template <class T>
TIterator<TQueueItem<T>,T> TQueue<T>::begin()
{
  return TIterator<TQueueItem<T>, T>(first);
}

template <class T>
TIterator<TQueueItem<T>,T> TQueue<T>::end()
{
  return TIterator<TQueueItem<T>, T>(nullptr);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TQueue<T>& queue) {
  std::shared_ptr<TQueueItem<T>> item = queue.first;

  while (item != nullptr) {
    os << *item;
    item = item->GetNext();
  }

  return os;
}

#include "figures/figures.h"
/*template class TQueue<Triangle>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Triangle> &obj);
template class TQueue<Rect>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Rect> &obj);
template class TQueue<Square>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Square> &obj);*/
template class TQueue<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Figure> &obj);
