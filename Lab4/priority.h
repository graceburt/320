/*
 * Lab 4 320
 * header file
 * September 2019
 * Dr. Anderson
 * Grace Burton
*/


#ifndef priority_h 
#define priority_h




#include<iostream>
#include<stdlib.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <limits.h>

using namespace std;

template <class T>
class HeapQ{

private:

	template <class U>
	struct HeapObj{
			U data;
			int key;
		};

		int heapSize;
		int length;
		HeapObj<T>* A;

			int Parent(int i){
				if(i%2 == 0){
					return (i-1)/2;
				}else{
					return (i/2);
				}
			};

			int leftChild(int i){
				return (2*i + 1);
			};

			int rightChild(int i){
				return (2*i + 2);
			};

			void increaseKey(HeapQ A, int i, int k){
				if(k < A[i]){
					cout << "New key is smaller than old key!" << endl;
					return;
				}

				A[i] = k;

				while(i > 1 && A[i/2] < A[i]){
					HeapObj<T> temp = A.A[i-1];
					A.A[i-1] = A.A[Parent(i)-1];
					A.A[Parent(i)-1] = temp;
					i = Parent(i);
				};

			};


public:

		HeapQ<T>(T*, int*, int);
		void insert(HeapQ, int);
		int setLength(HeapQ<T>*);
		void extractmax(HeapQ<T>);
		void peek(HeapQ);
		void swap(int&, int&);
		void maxheapify(HeapQ<T>, int);
		void buildmaxheap(HeapQ<T> );
		void heapSort(HeapQ<T>);
		void print(HeapQ heap);

		int& operator[](int i){

			// good idea to also check that 1 <= i <= length;
				return A[i-1].key; 
			// so A[1] is the first and A[n] is the last

		};

		ostream& operator<<(ostream& os){
		os << (this->A).Data << " at position: " << (this->A.key) << " in heap" << endl;
	};

}; //end of class

// give the struct an [] operator to pass through access to arr
// we return an int reference so we can assign into the structure,
// otherwise it would only return a copy of the indexed element

		template <class T>
		HeapQ<T>::HeapQ(T* arr, int* p, int l){

			A = new HeapObj<T>[l];
			heapSize = l;
			length = l;

			for(int i = 0; i < l; i++){
				A[i].data = arr[i];
				A[i].key = p[i];
			};

		};

		template<class T>
		void HeapQ<T>::insert(HeapQ A, int k){//k is key

				A.heapSize = (A.heapSize + 1);
				length++;
				A[A.heapSize] = -1;
				increaseKey(A, A.heapSize, k);
		
			}; //k is position in arr

		// template<class T>
		// int HeapQ<T>::setLength(HeapQ A){

		// };

		template<class T>
		void HeapQ<T>::extractmax(HeapQ A){
				//assume A is a valid min heap
				//return & remove min element
				if(A.heapSize < 1){
					cout << "Empty heap!" << endl;
					return;
				}else{

					int tmp = A[1];
					maxheapify(A, 1); //reorders tree

					cout << "The max is: " << tmp << endl;

				}
		};

		template<class T>
		void HeapQ<T>::peek(HeapQ arr){

			cout << "Max value is " << arr.A[0].data << endl;

		};

			// void printHeap(){
			// 	//2^n depth so for 10 nodes 2^3

			// 	if(A.length == 0){

			// 		cout << "Empty array!" << endl;

			// 	}

			// 	int n = 10;

			// 	for(int i = 1; i < 1000; i++){
			// 		cout << A[i] << " ";
			// 		for(int j = 1; j <= n; j++){
			// 			if( i == (pow(2.0, j) - 1)){
			// 				cout << endl;
			// 			}
			// 		}
			// 	}
			// 	cout << endl;
			// };

		template<class T>
		void HeapQ<T>::print(HeapQ heap){
			cout << "hello" << endl;

			for(int i = 1; i <= heap.length; i++){
				if(heap[i] >= 0){
					cout << heap.A[i-1].data << " (" << heap[i] << ") ";
				}
				for(int j = 1; j <= heap.length; j++){
					if(i == (pow(2.0, j) - 1)){
						cout << endl;
					}
				}
			}
			cout << endl;
		};

		// template<class T>
		// void HeapQ<T>::swap(int &val1, int &val2){
  
		// 	  int temp;
		// 	  temp = val1;
		// 	  val1 = val2;
		// 	  val2 = temp;
			  
		// 	};

		template<class T>
		void HeapQ<T>::maxheapify(HeapQ A, int i){
			int l = 2*i-1;
			int r = 2*i;
			//find smallest node amond node i and children and swap with i
			int max;

			if(l <= A.heapSize && A[l] > A[i]){
				max = l;
			}
			else{
				max = i;
			}//end if
			if(r <= A.heapSize && A[r] > A[max]){
				max = r;
			}//end if
			if(max != i){
				//violate heap property so recurse
				  
				  HeapObj<T> temp = A.A[i-1];
				  A.A[i-1] = A.A[max-1];
				  A.A[max-1] = temp;
				  A.maxheapify(A, max);
			}//end if
		};

		template<class T>
		void HeapQ<T>::buildmaxheap(HeapQ A){
			A.heapSize = A.length;
			for(int i = (A.length/2); i >= 1; i--){
				maxheapify(A, i);
			}
		};

		template<class T>
		void HeapQ<T>::heapSort(HeapQ heap){
			cout << endl;
			cout << "Heapifying..." << endl;
			cout << endl;
			buildmaxheap(heap);
			for(int i = heap.length; i >= 2; i--){

				//moves smallest A[i] to the back, consider it gone from heap
				// swap(heap[1], heap[i]);
				//swapped smallest w root

				  HeapObj<T> temp = heap.A[0];
				  heap.A[0] = heap.A[i-1];
				  heap.A[i-1] = temp;
				  heap.heapSize = heap.heapSize - 1; //reset root
				  heap.maxheapify(heap, 1); //reheapify
			};

			int j = length;
			int k = 1;
			while(k < j){
				HeapObj<T> temp2 = heap.A[j-1];
				heap.A[j-1] = heap.A[k-1];
				heap.A[k-1] = temp2;
				k++;
				j--;
			}
		};

#endif