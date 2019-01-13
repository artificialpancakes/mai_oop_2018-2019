#include <iostream>
#include <cstdlib>
#include "figures/figures.h"
#include "queue.h"

using namespace std;

void print_usage() {
  cout << "Usage:\n";
  cout << "r - Generate pseudo-random figures\n";
  cout << "s - show queue\n";
}

std::shared_ptr<Figure> Generate_random() {
  int figure = rand() % 3;

  int size_a = rand() % 128 + 1;
  int size_b = rand() % 128 + 1;
  int size_c = rand() % (size_a + size_b - 1) + 1;

  if (size_a > size_b) {
    if (size_c < size_a - size_b + 1) {
      size_c = size_a - size_b + 1;
    }
  }
  else {
    if (size_c < size_b - size_a + 1) {
      size_c = size_b - size_a + 1;
    }
  }

  std::shared_ptr<Figure> fig;
  switch (figure) {
    case 0:
      fig = std::shared_ptr<Figure>(new Triangle(size_a, size_b, size_c));
      break;
    case 1:
      fig = std::shared_ptr<Figure>(new Rect(size_a, size_b));
      break;
    case 2:
      fig = std::shared_ptr<Figure>(new Square(size_a));
      break;
  }
  return fig;
}

int main() {
  TQueue<Figure> q;

  for (int i = 0; i < 500; i++) {
    q.Push(Generate_random());
  }

  cout << q << endl;
  cout << "Sorting...\n";
  q.Quicksort_parallel();
  cout << q << endl;

  return 0;
}
