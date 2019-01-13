#include <iostream>
#include <cstdlib>
#include "figures/figures.h"
#include "queue.h"
#include "tvector.hpp"

using namespace std;

void Print_usage() {
  cout << "Usage:\n";
  cout << "1 - Generate pseudo-random figure,\n";
  cout << "2 - Show queue,\n";
  cout << "3 - Pop elements with lesser area.";
  cout << endl;
}

int main() {
  Print_usage();
  TVector<void(*)(TQueue<Figure>&)> commands;
  TQueue<Figure> q;

  int flag;
  while(scanf("%d", &flag) == 1) {
    switch(flag) {
      case 1:
        commands.Push(
          [](TQueue<Figure> &q) -> void {
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
            q.Push(std::move(fig));
            cout << endl;
          }
        );
        break;
      case 2:
        commands.Push(
          [](TQueue<Figure> &q) -> void {
            cout << endl;
            cout << "Queue:\n";
            for (auto i : q) {
              cout << "[" <<*i << "]" << endl;
            }
            cout << endl;
          }
        );
        break;
      case 3:
        commands.Push(
          [](TQueue<Figure> &q) -> void {
            double area;
            cout << "Enter area:\n";
            scanf("%lf", &area);

            std::shared_ptr<TQueueItem<Figure>> prev = q.first;
            std::shared_ptr<TQueueItem<Figure>> iter = q.first;

            while (iter != nullptr) {
              if (iter->Get()->Area() < area) {
                if (iter == q.first) {
                  q.first = iter->GetNext();
                  if (iter == q.last) {
                    q.last = nullptr;
                  }
                }
                else if (iter == q.last) {
                  prev->SetNext(nullptr);
                  q.last = prev;
                }
                else {
                  prev->SetNext(iter->GetNext());
                }
              }

              prev = iter;
              iter = iter->GetNext();
            }
          }
        );
        break;
    }
  }

  for (int i = 0; i < commands.Size(); i++) {
    commands[i](q);
  }
}
