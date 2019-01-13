#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
  public:
    virtual double Area() = 0;
    virtual void Print() = 0;
    virtual ~Figure() {};
    virtual std::ostream& Format(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& obj);
};

#endif
