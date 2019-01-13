#include <iostream>
#include "figures.h"

using std::cout;
using std::cin;
using std::endl;

void print_usage() {
  cout << "usage" << endl;
  cout << "0 - quit" << endl;
  cout << "1 - create triangle" << endl;
  cout << "2 - create square" << endl;
  cout << "3 - create rect" << endl;
}

int main() {
  print_usage();

  while (1) {
    Figure *ptr = nullptr;
    int arg;
    cin >> arg;
    switch (arg) {
      case 1:
        ptr = new Triangle(cin);
        break;
      case 2:
        ptr = new Square(cin);
        break;
      case 3:
        ptr = new Rect(cin);
        break;
      default:
        arg = 0;
    }

    if (arg == 0) {
      break;
    }

    ptr->Print();
    cout << "area: " << ptr->Area() << endl;
    delete ptr;
  }
  return 0;
}
