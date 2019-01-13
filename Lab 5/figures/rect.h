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
  std::ostream& Format(std::ostream& out) const override;

  bool operator==(const Rect& right);

  friend std::ostream& operator<<(std::ostream& os, const Rect& obj);
  friend std::ostream& operator<<(std::ostream& os, const Rect& obj);

  Rect& operator=(const Rect& right);

  virtual ~Rect();
  uint side_a, side_b;
};

#endif
