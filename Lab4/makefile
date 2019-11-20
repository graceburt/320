main: main.o
	g++ main.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

# recipe to clean up the tmp files
clean:
	rm main *.o