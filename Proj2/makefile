main: main.o
	g++ -std=c++11 main.o -o main

main.o: main.cpp
	g++ -c -std=c++11 main.cpp -g

# recipe to clean up the tmp files
clean:
	rm main *.o