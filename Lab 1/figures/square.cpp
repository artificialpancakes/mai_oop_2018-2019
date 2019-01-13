#include "square.h"
#include <iostream>
#include <cmath>

Square::Square() : Square(0) {}

Square::Square(uint a) : side_a(a) {
  std::cout << "Square created: " << side_a << std::endl;
}

Square::Square(std::istream &is) {
  std::cout << "enter 1 side:" << std::endl;
  is >> side_a;
  std::cout << "Square created: " << side_a << std::endl;
}

double Square::Area() {
  return side_a * side_a;
}

void Square::Print() {
  std::cout << "a=" << side_a << std::endl;
}

Square::~Square() {
  std::cout << "Square deleted!" << std::endl;
}
