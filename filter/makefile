compile: main.o
	g++ main.o -o filter

main.o: main.cpp
	g++ -c main.cpp

run: filter
	./filter

clean:
	rm main.o
	rm filter
