#ifndef TVECTOR_H
#define TVECTOR_H

template <class T>
class TVector {
public:
  TVector();
  ~TVector();

  void Push(T elem);
  T& operator [] (int index);

  int Size();
private:
  T *body;
  int size;
  int capacity;
};

#endif
