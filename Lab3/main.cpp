/*
 * Lab 3 320
 * September 2019
 * Dr. Anderson
 * Grace Burton
*/

#include<iostream>
#include<stdlib.h>
#include <math.h>
#include <time.h>
#include <ctime>

using namespace std;

struct Heap {
		int* arr; // the underlying array
		int length; // should always be the size of arr int 
		int heap_size; // will change based on which portion of arr is a valid heap

	//1 is A[0]!!!!!!!!


		int& operator[](int i){

			// good idea to also check that 1 <= i <= length;
				return arr[i-1]; 
			// so A[1] is the first and A[n] is the last

		};
};

// give the struct an [] operator to pass through access to arr
// we return an int reference so we can assign into the structure,
// otherwise it would only return a copy of the indexed element


void swap(int &val1, int &val2){
  
  int temp;
  temp = val1;
  val1 = val2;
  val2 = temp;
  
  
};

void maxheapify(Heap A, int i){
	int l = 2*i-1;
	int r = 2*i;
	//find smallest node amond node i and children and swap with i
	int max;

	if(l <= A.heap_size && A[l] > A[i]){
		max = l;
	}
	else{
		max = i;
	}//end if
	if(r <= A.heap_size && A[r] > A[max]){
		max = r;
	}//end if
	if(max != i){
		//violate heap property so recurse
		swap(A[i], A[max]);
		maxheapify(A, max);
	}//end if
};

void buildmaxheap(Heap A){
	A.heap_size = A.length;
	for(int i = (A.length/2); i >= 1; i--){
		maxheapify(A, i);
	}
};

// void extractmax(Heap A){
// 	//assume A is a valid min heap
// 	//return & remove min element
// 	int tmp = A[1];
// 	maxheapify(A, 1); //reorders tree

// 	cout << "The max is: " << tmp << endl;
// };

void heapSort(Heap A){
	cout << endl;
	cout << "Heapifying..." << endl;
	cout << endl;
	buildmaxheap(A);
	for(int i = A.length; i >= 2; i--){
		//moves smallest A[i] to the back, consider it gone from heap
		swap(A[1], A[i]); //swapped smallest w root
		A.heap_size = A.heap_size - 1; //reset root
		maxheapify(A, 1); //reheapify
	};
};

void printHeap(Heap A){
	//2^n depth so for 10 nodes 2^3
	int n = 10;

	for(int i = 1; i < 1000; i++){
		cout << A[i] << " ";
		for(int j = 1; j <= n; j++){
			if( i == (pow(2.0, j) - 1)){
				cout << endl;
			}
		}
	}
	cout << endl;
};

int main(){

//have to change x = NUM; where NUM is testing size

	int x = 1000;

	int start = 0;
	int end = x;

	Heap Trial;

	Trial.arr = new int[x];

	for(int i = 1; i <= x; i++){
      int j = rand()%20;
      Trial[i] = j;
      cout << " " << Trial[i] << " " << endl;
    };

	Trial.length = x;


	int sec = 60; 

	double start2 = double(clock())/sec;
	heapSort(Trial);
	double finish2 = double(clock())/sec;
	cout << "sorted" << endl;

	printHeap(Trial);


	cout << "*********************************" << endl;
	cout << "Heap Sort" << endl;

	cout << "The time taken to sort array was: " << finish2 - start2 << endl;

};