#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0, 0, 0) {}

Triangle::Triangle(uint a, uint b, uint c)
  :side_a(a), side_b(b), side_c(c)
{
  std::cout << "Triangle created: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

Triangle::Triangle(std::istream &is) {
 std::cout << "enter 3 sides:" << std::endl;
 is >> side_a;
 is >> side_b;
 is >> side_c;
 std::cout << "Triangle created: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

double Triangle::Area() {
    double p = double(side_a + side_b + side_c) / 2.0;
    return sqrt(p * (p - double(side_a)) * (p - double(side_b)) * (p - double(side_c)));
}

void Triangle::Print() {
    std::cout << "a=" << side_a << ", b=" << side_b << ", c=" << side_c << std::endl;
}

Triangle::~Triangle() {
    std::cout << "Triangle deleted" << std::endl;
}
