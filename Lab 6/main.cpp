#include <iostream>
#include "figures/figures.h"
#include "queue.h"

using namespace std;

void print_usage() {
  cout << "Usage:\n";
  cout << "Figure creation:\n";
  cout << "  1 - Triangle\n";
  cout << "  2 - Rect\n";
  cout << "  3 - Square\n";
  cout << "s - Show queue\n";
  cout << "a - Show queue using iterators\n";
  cout << "p - Pop from queue\n";
}

int main() {
  print_usage();
  TQueue<Figure> q;

  char ch;
  while (scanf("%c", &ch) == 1) {
    if (ch == '1') {
      Triangle *fig = new Triangle(cin);
      Figure *f = dynamic_cast<Figure*>(fig);
      q.Push(std::shared_ptr<Figure>(f));
    }
    else if (ch == '2') {
      Rect *fig = new Rect(cin);
      Figure *f = dynamic_cast<Figure*>(fig);
      q.Push(std::shared_ptr<Figure>(f));
    }
    else if (ch == '3') {
      Square *fig = new Square(cin);
      Figure *f = dynamic_cast<Figure*>(fig);
      q.Push(std::shared_ptr<Figure>(f));
    }
    else if (ch == 'a') {
      for(auto i : q) {
        std::cout << *i << std::endl;
      }
    }
    else if (ch == 's') {
      cout << q << endl;
    }
    else if (ch == 'p') {
      if (q.IsEmpty()) {
        cout << "   empty!" << endl;
      }
      else {
        std::shared_ptr<Figure> figure; figure = q.Pop();
        cout << "   [" << *figure << "]   " << endl;
      }
    }
  }

  return 0;
}
