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
 std::ostream& Format(std::ostream& out) const override;

 bool operator==(const Square& right);

 friend std::ostream& operator<<(std::ostream& os, const Square& obj);
 friend std::ostream& operator<<(std::ostream& os, const Square& obj);

 Square& operator=(const Square& right);

 virtual ~Square();
 uint side_a;
};

#endif
