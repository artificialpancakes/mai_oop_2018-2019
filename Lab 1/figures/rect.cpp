#include "rect.h"
#include <iostream>
#include <cmath>

Rect::Rect() : Rect(0, 0) {}

Rect::Rect(uint a, uint b)
  :side_a(a), side_b(b)
{
  std::cout << "Rect created: " << side_a << ", " << side_b << std::endl;
}

Rect::Rect(std::istream &is) {
  std::cout << "enter 2 sides:" << std::endl;
 is >> side_a;
 is >> side_b;
 std::cout << "Rect created: " << side_a << ", " << side_b << std::endl;
}

double Rect::Area() {
  return side_a * side_b;
}

void Rect::Print() {
 std::cout << "a=" << side_a << ", b=" << side_b << std::endl;
}

Rect::~Rect() {
 std::cout << "Rect deleted" << std::endl;
}
