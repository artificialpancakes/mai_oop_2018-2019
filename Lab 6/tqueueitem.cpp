#include "tqueueitem.h"

template <class T>
TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& figure) {
  this->figure = figure;
  this->next = nullptr;
}

template <class T>  TAllocationBlock TQueueItem<T>::queueitem_allocator(sizeof(TQueueItem<T>), 100);

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
    std::cout << "Queue item: deleted" << std::endl;
}

template <class T>
std::shared_ptr<T> TQueueItem<T>::Get() {
  return this->figure;
}

template <class A>
std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
  os << "[" << *obj.figure << "]" << std::endl;
  return os;
}

template <class T> void* TQueueItem<T>::operator new(size_t size) {
	std::cout << "Allocated " << size << " bytes" << std::endl;
	return queueitem_allocator.allocate();
}

template <class T> void TQueueItem<T>::operator delete(void *p) {
	std::cout << "Deleted" << std::endl;
	queueitem_allocator.deallocate(p);
}

#include "figures/figures.h"
/*template class TQueueItem<Triangle>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Triangle> &obj);
template class TQueueItem<Rect>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Rect> &obj);
template class TQueueItem<Square>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Square> &obj);*/
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure> &obj);
