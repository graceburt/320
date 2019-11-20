main: main.o
	g++ main.o -std=c++11 -o main

main.o: main.cpp
	g++ -c main.cpp -std=c++11

# recipe to clean up the tmp files
clean:
	rm main *.o