#ifndef RECT_H
#define RECT_H

#include "figure.h"
#include <iostream>

class Rect : public Figure {
public:
  Rect();
  Rect(std::istream &is);
  Rect(uint a, uint b);

  double Area() override;
  void Print() override;

  virtual ~Rect();

private:
  uint side_a, side_b;
};

#endif
