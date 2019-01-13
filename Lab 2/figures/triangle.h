#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <iostream>

class Triangle : public Figure {
public:
  Triangle();
  Triangle(std::istream &is);
  Triangle(Triangle &triangle);
  Triangle(uint a, uint b, uint c);

  double Area() override;
  void Print() override;

  virtual ~Triangle();

  bool operator==(const Triangle& right);

  friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);
  friend std::istream& operator>>(std::istream& is, Triangle& obj);

  Triangle& operator=(const Triangle& right);
  
  uint side_a, side_b, side_c;
};

#endif
