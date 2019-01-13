#include "tvector.h"

template <class T> TVector<T>::TVector() : size(0) {
  std::cout << "vector constructed!" << std::endl;
}

template <class T> TVector<T>::~TVector() {
  std::cout << "vector destroyed!" << std::endl;
}

template <class T> int TVector<T>::Size() {
  return size;
}

template <class T>
void TVector<T>::Remove_lesser(double area) {
  for (int i = 0; i < size; i++) {
    std::shared_ptr<Figure> item = this->Get(i);
    if (item->Area() < area) {
      this->Remove(i);
      i--;
    }
  }
}

template <class T>
bool TVector<T>::Insert(std::shared_ptr<T> &&item) {
  if (size == 5) {
    return false;
  }
  else {
    int flag = 0;
    std::shared_ptr<T> buf;
    std::shared_ptr<T> another_buf;
    for (int i = 0; i < size; i++) {
      if (arr[i]->Area() < item->Area()) {
        flag = 1 + i;
        buf = arr[i];
        arr[i] = item;
        break;
      }
    }

    this->size++;

    if (flag) {
      for (int i = flag; i < size; i++) {
        another_buf = arr[i];
        arr[i] = buf;
        buf = another_buf;
      }
    }
    else {
      arr[size-1] = item;
    }

    return true;
  }
}

template <class T> template <class Type>
void TVector<T>::Remove_type() {
  for (int i = 0; i < size; i++) {
    std::shared_ptr<T> a = this->Get(i);
    std::shared_ptr<Type> item = std::dynamic_pointer_cast<Type>(a);

    if (item.get() != nullptr) {
      std::cout << "found: " << *item << "; deleting..." << std::endl;
      this->Remove(i);
      i--;
    }
  }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TVector<T>& vec) {
  std::shared_ptr<T> item;
  for (int i = 0; i < vec.size; i++) {
    item = vec.Get(i);
    os << "   [" << *item << "]" << std::endl;
  }

  return os;
}

template <class T>
std::shared_ptr<T> TVector<T>::Remove(int index) {
  std::shared_ptr<T> res;
  if (index < this->size) {
    res = arr[index];
    for (int i = index; i < size - 1; i++) {
      arr[i] = arr[i+1];
    }
    arr[size - 1] = nullptr;
    this->size--;
  }
  return res;
}

template <class T>
std::shared_ptr<T> TVector<T>::Get(int i) const {
  return arr[i];
}

template class TVector<Figure>;
template void TVector<Figure>::Remove_type<Triangle>();
template void TVector<Figure>::Remove_type<Rect>();
template void TVector<Figure>::Remove_type<Square>();
template std::ostream& operator<<(std::ostream& os, const TVector<Figure> &obj);
