main: main.o
	g++ main.o -o main

main.o: main.cpp matrix.cpp
	g++ -std=c++11 -c main.cpp

matrix.o: matrix.cpp
	g++ -std=c+11 -c matrix.cpp

# recipe to clean up the tmp files
clean:
	rm main *.o