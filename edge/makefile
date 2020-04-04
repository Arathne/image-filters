VERSION = -std=c++11

compile: clean main.o kernel.o edge.o iterator.o
	g++ $(VERSION) main.o kernel.o edge.o iterator.o -o edge

main.o: main.cpp
	g++ $(VERSION) -c main.cpp

kernel.o: kernel.cpp kernel.h
	g++ $(VERSION) -c kernel.cpp

edge.o: edge.cpp edge.h
	g++ $(VERSION) -c edge.cpp

iterator.o: iterator.cpp iterator.h
	g++ $(VERSION) -c iterator.cpp

run: edge
	./edge

valgrind: edge
	valgrind ./edge

clean:
	rm -rf *.o edge
