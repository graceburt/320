main: main.o graph.o
	g++ -std=c++11 main.o graph.o -o main
main.o: main.cpp graph.cpp
	g++ -std=c++11 -c main.cpp
graph.o: graph.cpp graph.h
	g++ -std=c++11 -c graph.cpp
clean:
	rm main *.o