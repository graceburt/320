/*
 * Lab 7 320
 * rand.cpp
 * October 2019
 * Dr. Anderson
 * Grace Burton
*/

#include <iostream>
#include <time.h>

void swap(int &val1, int &val2){

	  int temp;
	  temp = val1;
	  val1 = val2;
	  val2 = temp;
	  
	};

int* shuffle(int n){

	//generates an array of all numbers from 1 through n in a random order
	int* arr = new int[n];

	for(int i = 0; i < n; i++){
		arr[i] = -1;
	}

	for(int i = 1; i <= n; i++){
		srand(time(NULL));
		int j = rand() % n;
		while(arr[j] != -1){
			j = rand() % n;
			//std::cout << j << std::endl;
		}
		arr[j] = i;
	}

	// for(int i = 0; i < n; i++){
	// 	std::cout << arr[i] << std::endl;
	// }

	return arr;

};

void hireAssistant(){

	int hire = 0;
	int n = 10000;
	int ass = 0;

	int* rank;
	rank = shuffle(n);

	for(int i = 1; i <= n; i++){
		if(rank[i] > rank[hire]){
			ass++;
			hire = i;
		}
	}

	for(int i = 0; i < n; i++){
		std::cout << rank[i] << "" << std::endl;
	}

	std::cout << "We hired candidate: " << (hire+1) << " with " << ass << " swaps" << std::endl;

	delete [] rank;

};


int partition(int arr[], int left, int right){
  
  //ind
  int p = left;
  int x = right; //p
  for(int i = left; i < right; i++){
    if(arr[i] < arr[x]){
      swap(arr[i], arr[p]);
      p++;
    };
  };//end for
  
	swap(arr[x], arr[p]);

	return p;
  
  
};

void quicksort(int arr[], int start, int end){
  
  if(start < end){
    
    //std::cout << "time to pivot" << std::endl;
    int p = partition(arr, start, end);
    //std::cout << "time to recurse" << std::endl;
    quicksort(arr, start, p-1);
    quicksort(arr, p+1, end);
    
  }
};

int randoPartition(int* arr, int left, int right){

	int swaps;
	int n = rand();
	int random = left + n%(right-left+1);

	swap(arr[right], arr[random]);
	swaps++;

	return partition(arr, left, right);

};

void randoQuickSort(int* arr, int left, int right){

	if(left < right){

	int p = randoPartition(arr, left, right);
	randoQuickSort(arr, left, p-1);
	randoQuickSort(arr, p+1, right);

	}

};

// int merge(int* arr, int start, int m, int end){
// 		int p = start;
// 		int q = m + 1;
// 		int k = 0;
// 		int arr2[end+1];
// 		int counter = 0;

// 		while(p <= m && q <= end){
// 				if(arr[p] <= arr[q]){  ;
// 					arr2[k] = arr[p];
// 					k++;
// 					p++;
// 					counter++;
// 				}else{
// 					arr2[k] = arr[q];
// 					k++;
// 					p++;
// 					counter++;
// 				}//end if/else
// 		} // end while
// 		while(p <= m){
// 			arr2[k] = arr[p];
// 			k++;
// 			p++;
// 		}
// 		while(q <= end){
// 			arr2[k] = arr[q];
// 			k++;
// 			q++;
// 		}
// 		for(int i = start; i <= end; i++){
// 			arr[i] = arr2[i-start];
// 		}

// 		return counter;
// 	};//end merge

// void mergeSort(int* arr, int start, int end, int &swaps){

// 	if(start < end){
// 		int midpoint = (start+end)/2;
// 		mergeSort(arr, start, midpoint, swaps);
// 		mergeSort(arr, midpoint+1, end, swaps);
// 		swaps += merge(arr, start, midpoint, end);
// 	}

//}//end mergesort

		// void maxheapify(int* A, int i){
		// 	int l = 2*i-1;
		// 	int r = 2*i;
		// 	//find smallest node amond node i and children and swap with i
		// 	int max;

		// 	if(l <= A.heapSize && A[l] > A[i]){
		// 		max = l;
		// 	}
		// 	else{
		// 		max = i;
		// 	}//end if
		// 	if(r <= A.heapSize && A[r] > A[max]){
		// 		max = r;
		// 	}//end if
		// 	if(max != i){
		// 		//violate heap property so recurse
				  
		// 		  HeapObj<T> temp = A.A[i-1];
		// 		  A.A[i-1] = A.A[max-1];
		// 		  A.A[max-1] = temp;
		// 		  A.maxheapify(A, max);
		// 	}//end if
		// };

		// void buildmaxheap(int* A){
		// 	A.heapSize = A.length;
		// 	for(int i = (A.length/2); i >= 1; i--){
		// 		maxheapify(A, i);
		// 	}
		// };

		// void heapSort(int* heap){
		// 	cout << endl;
		// 	cout << "Heapifying..." << endl;
		// 	cout << endl;
		// 	buildmaxheap(heap);
		// 	for(int i = heap.length; i >= 2; i--){

		// 		//moves smallest A[i] to the back, consider it gone from heap
		// 		// swap(heap[1], heap[i]);
		// 		//swapped smallest w root

		// 		  HeapObj<T> temp = heap.A[0];
		// 		  heap.A[0] = heap.A[i-1];
		// 		  heap.A[i-1] = temp;
		// 		  heap.heapSize = heap.heapSize - 1; //reset root
		// 		  heap.maxheapify(heap, 1); //reheapify
		// 	};

		// 	int j = length;
		// 	int k = 1;
		// 	while(k < j){
		// 		HeapObj<T> temp2 = heap.A[j-1];
		// 		heap.A[j-1] = heap.A[k-1];
		// 		heap.A[k-1] = temp2;
		// 		k++;
		// 		j--;
		// 	}
		// };

int main(){

	int sec = 60;
	int* rank;
	rank = shuffle(1000);
	
	hireAssistant();

	double start2 = double(clock())/sec;
	hireAssistant();
	double finish2 = double(clock())/sec;
	std::cout << finish2 - start2 << std::endl;

	// int* rank;
	// rank = shuffle(600);

	// std::cout << "=======================" << std::endl;
	// std::cout << "Now we random quickSort \n";

	// double start2 = double(clock())/sec;
	// randoQuickSort(rank, 0, 600);
	// double finish2 = double(clock())/sec;
	// // for(int i = 0; i <= 10000; i++){
	// // 	std::cout << rank[i] << std::endl;
	// // }

	// std::cout << "=======================" << std::endl;
	// std::cout << "Now we quickSort \n\n";
	// double start3 = double(clock())/sec;
	// quicksort(rank, 0, 600);
	// double finish3 = double(clock())/sec;
	// // for(int i = 0; i <= 99; i++){
	// // 	std::cout << rank[i] << std::endl;
	// // }

	// std::cout << "Quick sort took: \n";
	// std::cout << finish3 - start3 << std::endl;
	// std::cout << "Randomized Quick sort took: \n";
	// std::cout << finish2 - start2 << std::endl;

	delete [] rank;

}