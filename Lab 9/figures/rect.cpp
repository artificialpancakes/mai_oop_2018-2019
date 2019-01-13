#include "rect.h"
#include <iostream>
#include <cmath>

Rect::Rect() : Rect(0, 0) {}

Rect::Rect(uint a, uint b)
  :side_a(a), side_b(b)
{
  std::cout << "Triangle(" << side_a << ", " << side_b << ") created.";
}

Rect::Rect(std::istream &is) {
  std::cout << "enter 2 sides:" << std::endl;
 is >> side_a;
 is >> side_b;
}

std::ostream& operator<<(std::ostream& os, const Rect& obj) {
  os << "Rect: a: " << obj.side_a << ", b: " << obj.side_b;
  return os;
}

std::ostream& Rect::Format(std::ostream& out) const {
  out << *this;
  return out;
}

double Rect::Area() {
  return side_a * side_b;
}

void Rect::Print() {
 std::cout << "a=" << side_a << ", b=" << side_b << std::endl;
}

Rect::~Rect() {
}

std::istream& operator>>(std::istream& is,  Rect& obj) {
  is >> obj.side_a;
  is >> obj.side_b;
  return is;
}

Rect& Rect::operator=(const Rect& right) {
  if (this == &right) return *this;

  std::cout << "Rect copied" << std::endl;
  side_a = right.side_a;
  side_b = right.side_b;

  return *this;
}

bool Rect::operator==(const Rect& right) {
  if (side_a != right.side_a) return false;
  if (side_b != right.side_b) return false;
  return true;
}
