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

std::ostream& operator<<(std::ostream& os, const Square& obj) {
  os << "Square: a: " << obj.side_a;
  return os;
}

std::ostream& Square::Format(std::ostream& out) const {
  out << *this;
  return out;
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

std::istream& operator>>(std::istream& is,  Square& obj) {
  is >> obj.side_a;
  return is;
}

Square& Square::operator=(const Square& right) {
  if (this == &right) return *this;

  std::cout << "Square copied" << std::endl;
  side_a = right.side_a;

  return *this;
}

bool Square::operator==(const Square& right) {
  if (side_a != right.side_a) return false;
  return true;
}
