#include <iostream>
#include "figures/figures.h"
#include "tvector.h"
#include "queue.h"

using namespace std;

void print_usage() {
  cout << "Usage:\n";
  cout << "Figure creation:\n";
  cout << "  1 - Triangle\n";
  cout << "  2 - Rect\n";
  cout << "  3 - Square\n";
  cout << "a - Deleting all the elements which are:\n";
  cout << "  1 - Triangles\n";
  cout << "  2 - Rects\n";
  cout << "  3 - Squares\n";
  cout << "  4 - Less than specified area\n";
  cout << "s - Show queue\n";
  cout << "p - Pop from queue\n";
}

int main() {
  print_usage();
  TQueue<TVector<Figure>> q;

  char ch;
  while (scanf("%c", &ch) == 1) {
    if (ch == '1') {
      Triangle *fig = new Triangle(cin);
      Figure *f = dynamic_cast<Figure*>(fig);
      q.Insert(std::shared_ptr<Figure>(f));
    }
    else if (ch == '2') {
      Rect *fig = new Rect(cin);
      Figure *f = dynamic_cast<Figure*>(fig);
      q.Insert(std::shared_ptr<Figure>(f));
    }
    else if (ch == '3') {
      Square *fig = new Square(cin);
      Figure *f = dynamic_cast<Figure*>(fig);
      q.Insert(std::shared_ptr<Figure>(f));
    }
    else if (ch == 'a') {
      int ind;
      scanf("%d", &ind);
      if (ind == 1) {
        q.Remove_type<Triangle>();
      }
      else if (ind == 2) {
        q.Remove_type<Rect>();
      }
      else if (ind == 3) {
        q.Remove_type<Square>();
      }
      else if (ind == 4) {
        cout << "Enter area:\n";
        double a;
        scanf("%lf", &a);
        q.Remove_lesser(a);
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
        int i, j;
        scanf("%d%d", &i, &j);
        cout << "   [" << *(q.Remove(i,j)) << "]   " << endl;
      }
    }
  }

  return 0;
}
