FLAGS= -std=c++14
COMPILLER=g++

all: start

start: rect.o square.o triangle.o main.o queue.o tqueueitem.o figure.o tallocationblock.o
	$(COMPILLER) $(FLAGS) -o program rect.o square.o triangle.o main.o queue.o tqueueitem.o figure.o tallocationblock.o

run: all
	./program

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

triangle.o: figures/triangle.cpp
	$(COMPILLER) -c $(FLAGS) figures/triangle.cpp

tallocationblock.o: tallocationblock.cpp
	$(COMPILLER) -c $(FLAGS) tallocationblock.cpp

figure.o: figures/figure.cpp
	$(COMPILLER) -c $(FLAGS) figures/figure.cpp

square.o: figures/square.cpp
	$(COMPILLER) -c $(FLAGS) figures/square.cpp

rect.o: figures/rect.cpp
	$(COMPILLER) -c $(FLAGS) figures/rect.cpp

queue.o: queue.cpp
	$(COMPILLER) -c $(FLAGS) queue.cpp

tqueueitem.o: tqueueitem.cpp
	$(COMPILLER) -c $(FLAGS) tqueueitem.cpp

clean:
	-rm -f *.o
