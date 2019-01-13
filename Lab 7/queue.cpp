#include "queue.h"
#include <stdlib.h>
#include "tvector.h"

template <class T>
TQueue<T>::TQueue() : first(nullptr), last(nullptr), size(0) {}
template <class T>
TQueue<T>::~TQueue() {}

template <class T>
void TQueue<T>::Insert(std::shared_ptr<Figure> &&figure) {
  if (last == nullptr) {
    this->Push(std::shared_ptr<T>(new T()));
  }
  if (last->Get()->Size() == 5) {
    this->Push(std::shared_ptr<T>(new T()));
    this->Insert(std::forward<std::shared_ptr<Figure>>(figure));
  }
  else {
    last->Get()->Insert(std::forward<std::shared_ptr<Figure>>(figure));
  }
}

template <class T>
std::shared_ptr<Figure> TQueue<T>::Remove(int i, int j) {
  std::shared_ptr<TQueueItem<T>> ptr = first;
  std::cout << first << std::endl;
  int counter = 0;
  while (counter != i && ptr != nullptr) {
    ptr = ptr->GetNext();
    counter++;
  }

  if (counter == i) {
    return ptr->Get()->Remove(j);
  }
  else {
    std::cout << "Error, no such index!" << std::endl;
  }
}

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

template <class T> template<class A>
void TQueue<T>::Remove_type() {
  std::shared_ptr< TQueueItem<T> > ptr = this->first;

  while (ptr != nullptr) {
    std::shared_ptr<TVector<Figure>> cont = ptr->Get();
    cont->Remove_type<A>();

    if (cont->Size() == 0) {
      std::shared_ptr<TQueueItem<T>> ptr_prev = this->first;
      std::shared_ptr<TQueueItem<T>> ptr_iter = this->first;

      while (ptr_iter != ptr) {
        ptr_prev = ptr_iter;
        ptr_iter = ptr_iter->GetNext();
      }

      if (ptr_iter == this->first) {
        // deleting first
        this->first = ptr_iter->GetNext();
        if (this->last == ptr_iter) {
          this->last = nullptr;
        }
      }
      else if (ptr_iter == this->last) {
        ptr_prev->SetNext(nullptr);
        this->last = ptr_prev;
      }
      else {
        ptr_prev->SetNext(ptr_iter->GetNext());
      }
    }

    ptr = ptr->GetNext();
  }
}

template <class T>
void TQueue<T>::Remove_lesser(double area) {
  std::shared_ptr< TQueueItem<T> > ptr = this->first;

  while (ptr != nullptr) {
    std::shared_ptr<TVector<Figure>> cont = ptr->Get();
    cont->Remove_lesser(area);

    if (cont->Size() == 0) {
      std::shared_ptr<TQueueItem<T>> ptr_prev = this->first;
      std::shared_ptr<TQueueItem<T>> ptr_iter = this->first;

      while (ptr_iter != ptr) {
        ptr_prev = ptr_iter;
        ptr_iter = ptr_iter->GetNext();
      }

      if (ptr_iter == this->first) {
        // deleting first
        this->first = ptr_iter->GetNext();
        if (this->last == ptr_iter) {
          this->last = nullptr;
        }
      }
      else if (ptr_iter == this->last) {
        ptr_prev->SetNext(nullptr);
        this->last = ptr_prev;
      }
      else {
        ptr_prev->SetNext(ptr_iter->GetNext());
      }
    }

    ptr = ptr->GetNext();
  }
}

#include "figures/figures.h"
/*template class TQueue<Triangle>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Triangle> &obj);
template class TQueue<Rect>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Rect> &obj);
template class TQueue<Square>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Square> &obj);*/
template void TQueue<TVector<Figure>>::Remove_type<Triangle>();
template void TQueue<TVector<Figure>>::Remove_type<Rect>();
template void TQueue<TVector<Figure>>::Remove_type<Square>();
template class TQueue<TVector<Figure>>;
template std::ostream& operator<<(std::ostream& os, const TQueue<TVector<Figure>> &obj);
