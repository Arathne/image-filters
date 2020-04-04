compile: main.o kernel.o edge.o
	g++ main.o kernel.o edge.o -o edge

main.o: main.cpp
	g++ -c main.cpp

kernel.o: kernel.cpp kernel.h
	g++ -c kernel.cpp

edge.o: edge.cpp edge.h
	g++ -c edge.cpp

run: edge
	./edge

valgrind: edge
	valgrind ./edge

clean:
	rm -rf *.o edge
