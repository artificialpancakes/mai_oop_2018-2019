#include <iostream>
#include "figures/triangle.h"
#include "queue.h"

using std::cout;
using std::cin;
using std::endl;

void print_usage() {
  cout << "Usage:\n";
  cout << "s - Show queue\n";
  cout << "a - Create a triangle and add it to the queue\n";
  cout << "p - Pop from queue\n";
}

int main() {
  print_usage();
  TQueue q;

  char ch;
  while (scanf("%c", &ch) == 1) {
    if (ch == 's') {
      cout << q << endl;
    }
    else if (ch == 'a') {
      q.Push(Triangle(std::cin));
      cout << endl;
    }
    else if (ch == 'p') {
      if (q.IsEmpty()) {
        cout << "   empty!" << endl;
      }
      else {
        Triangle tri; tri = q.Pop();
        cout << "   [" << tri << "]   " << endl;
      }
    }
  }

  return 0;
}
