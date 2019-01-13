#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0, 0, 0) {}

Triangle::Triangle(uint a, uint b, uint c)
  :side_a(a), side_b(b), side_c(c)
{
  std::cout << "Triangle(" << side_a << ", " << side_b << ", " << side_c << ") created.";
}

Triangle::Triangle(std::istream &is) {
 std::cout << "enter 3 sides:" << std::endl;
 is >> side_a;
 is >> side_b;
 is >> side_c;
}

std::ostream& Triangle::Format(std::ostream& out) const {
  out << *this;
  return out;
}

Triangle::Triangle(Triangle &triangle) {
 Triangle(triangle.side_a, triangle.side_b, triangle.side_c);
}

double Triangle::Area() {
  double p = double(side_a + side_b + side_c) / 2.0;
  return sqrt(p * (p - double(side_a)) * (p - double(side_b)) * (p - double(side_c)));
}

void Triangle::Print() {
  std::cout << "Triangle: a: " << side_a << ", b: " << side_b << ", c: " << side_c << std::endl;
}

Triangle::~Triangle() {
}

bool Triangle::operator==(const Triangle& right) {
  if (side_a != right.side_a) return false;
  if (side_b != right.side_b) return false;
  if (side_c != right.side_c) return false;
  return true;
}

std::ostream& operator<<(std::ostream& os, const Triangle& obj) {
  os << "Triangle: a: " << obj.side_a << ", b: " << obj.side_b << ", c: " << obj.side_c;
  return os;
}

std::istream& operator>>(std::istream& is,  Triangle& obj) {
  is >> obj.side_a;
  is >> obj.side_b;
  is >> obj.side_c;
  return is;
}

Triangle& Triangle::operator=(const Triangle& right) {
  if (this == &right) return *this;

  std::cout << "Triangle copied" << std::endl;
  side_a = right.side_a;
  side_b = right.side_b;
  side_c = right.side_c;

  return *this;
}
