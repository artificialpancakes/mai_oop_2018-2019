#include "tqueueitem.h"

template <class T>
TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& figure) {
  this->figure = figure;
  this->next = nullptr;
}

template <class T>  TAllocationBlock TQueueItem<T>::queueitem_allocator(sizeof(TQueueItem<T>), 100000);

template <class T>
void TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> item) {
    this->next = item;
}

template <class T>
std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
    return this->next;
}

template <class T>
TQueueItem<T>::~TQueueItem() {
}

template <class T>
std::shared_ptr<T> TQueueItem<T>::Get() {
  return this->figure;
}

template <class A>
std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
  os << "[" << *obj.figure << "]";
  return os;
}

template <class T> void* TQueueItem<T>::operator new(size_t size) {
	return queueitem_allocator.allocate();
}

template <class T> void TQueueItem<T>::operator delete(void *p) {
	queueitem_allocator.deallocate(p);
}

#include "figures/figures.h"
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure> &obj);
