#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"
#include <iostream>

class Square : public Figure {
public:
 Square();
 Square(std::istream &is);
 Square(uint a);

 double Area();
 void Print() override;

 virtual ~Square();
private:
 uint side_a;
};

#endif
