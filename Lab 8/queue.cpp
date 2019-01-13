#include "queue.h"
#include <stdlib.h>
#include <future>
#include <cstdint>
#include <functional>

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
  size++;
}

template <class T>
bool TQueue<T>::IsEmpty() {
  return first == nullptr;
}

template <class T>
void TQueue<T>::Quicksort() {
  if (this->size < 2) {
    return;
  }

  TQueue<T> lesser, greater;

  std::shared_ptr<T> pivot_figure = this->Pop();
  double pivot = pivot_figure->Area();

  std::shared_ptr<T> figure;
  while (!this->IsEmpty()) {
    figure = this->Pop();
    if (figure->Area() < pivot) {
      lesser.Push(std::move(figure));
    }
    else {
      greater.Push(std::move(figure));
    }
  }

  lesser.Quicksort();
  greater.Quicksort();

  while (!lesser.IsEmpty()) {
    this->Push(lesser.Pop());
  }

  this->Push(std::move(pivot_figure));

  while (!greater.IsEmpty()) {
    this->Push(greater.Pop());
  }
}

template <class T>
void TQueue<T>::Quicksort_parallel() {
  if (this->size < 2) {
    return;
  }

  TQueue<T> lesser;
  TQueue<T> greater;

  std::shared_ptr<T> pivot_figure = this->Pop();
  double pivot = pivot_figure->Area();

  std::shared_ptr<T> figure;
  while (!this->IsEmpty()) {
    figure = this->Pop();
    if (figure->Area() < pivot) {
      lesser.Push(std::move(figure));
    }
    else {
      greater.Push(std::move(figure));
    }
  }

  std::packaged_task<void()>
    task1(std::bind(&TQueue<T>::Quicksort_parallel, &lesser));
  std::packaged_task<void()>
    task2(std::bind(&TQueue<T>::Quicksort_parallel, &greater));

  auto futureGreater = task1.get_future();
  auto futureLesser = task2.get_future();

  std::thread(std::move(task1)).join();
  std::thread(std::move(task2)).join();
  futureLesser.get();
  futureGreater.get();

  while (!lesser.IsEmpty()) {
    this->Push(lesser.Pop());
  }

  this->Push(std::move(pivot_figure));

  while (!greater.IsEmpty()) {
    this->Push(greater.Pop());
  }
}

template <class T>
std::shared_ptr<T> TQueue<T>::Pop() {
  if (first != nullptr) {
    std::shared_ptr<T> result;
    std::shared_ptr<TQueueItem<T>> old_first = first;
    first = first->GetNext();
    result = old_first->Get();
    old_first->SetNext(nullptr);
    size--;
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
    os << "Area: " << item->Get()->Area() << "; " << *item << std::endl;
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
