#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <iostream>

class Triangle : public Figure {
public:
  Triangle();
  Triangle(std::istream &is);
  Triangle(uint a, uint b, uint c);

  double Area() override;
  void Print() override;

  virtual ~Triangle();

private:
  uint side_a, side_b, side_c;
};

#endif
