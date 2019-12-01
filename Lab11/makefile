main: main.o Graph.o
	g++ -std=c++11 main.o Graph.o -o main
main.o: main.cpp Graph.cpp
	g++ -std=c++11 -c main.cpp
Graph.o: Graph.cpp Graph.h
	g++ -std=c++11 -c Graph.cpp
clean:
	rm main *.o