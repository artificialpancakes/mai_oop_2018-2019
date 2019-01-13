FLAGS= -std=c++14
COMPILLER=g++

all: start

start: rect.o square.o triangle.o main.o queue.o tqueueitem.o
	$(COMPILLER) $(FLAGS) -o program rect.o square.o triangle.o main.o queue.o tqueueitem.o

run: program
	./program

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

triangle.o: figures/triangle.cpp
	$(COMPILLER) -c $(FLAGS) figures/triangle.cpp

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
