VERSION = -std=c++11

compile: clean main.o kernel.o edge.o iterator.o image.o
	g++ $(VERSION) main.o kernel.o edge.o iterator.o image.o -o edge

main.o: main.cpp
	g++ $(VERSION) -c main.cpp

kernel.o: kernel.cpp kernel.h
	g++ $(VERSION) -c kernel.cpp

edge.o: edge.cpp edge.h
	g++ $(VERSION) -c edge.cpp

iterator.o: iterator.cpp iterator.h
	g++ $(VERSION) -c iterator.cpp

image.o: image.cpp image.h
	g++ $(VERSION) -c image.cpp

run: edge
	./edge

valgrind: edge
	valgrind ./edge

clean:
	rm -rf *.o edge
