#ifndef FIGURE_H
#define FIGURE_H

class Figure {
  public:
    virtual double Area() = 0;
    virtual void Print() = 0;
    virtual ~Figure() {};
};

#endif
