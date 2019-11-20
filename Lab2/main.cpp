/*
 * Lab 2 320
 * August 2019
 * Dr. Anderson
 * Grace Burton
*/
#include<iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>

using namespace std;

void quicksort(int*, int, int);
int partition(int*, int, int);
void swap(int&, int&);

int merge(int* arr, int start, int m, int end){
		int p = start;
		int q = m + 1;
		int k = 0;
		int arr2[end+1];
		int counter = 0;

		while(p <= m && q <= end){
				if(arr[p] <= arr[q]){  ;
					arr2[k] = arr[p];
					k++;
					p++;
					counter++;
				}else{
					arr2[k] = arr[q];
					k++;
					p++;
					counter++;
				}//end if/else
		} // end while
		while(p <= m){
			arr2[k] = arr[p];
			k++;
			p++;
		}
		while(q <= end){
			arr2[k] = arr[q];
			k++;
			q++;
		}
		for(int i = start; i <= end; i++){
			arr[i] = arr2[i-start];
		}

		return counter;
	};//end merge

void mergeSort(int* arr, int start, int end, int &swaps){

	if(start < end){
		int midpoint = (start+end)/2;
		mergeSort(arr, start, midpoint, swaps);
		mergeSort(arr, midpoint+1, end, swaps);
		swaps += merge(arr, start, midpoint, end);
	}

}//end mergesort


int partition(int arr[], int start, int end){
  
  int x = arr[end-1]; //pivot
  int p = start - 1;
  for(int i = start; i <= end - 1; i++){
    if(arr[i] <= x){
      p++;
      swap(arr[p], arr[i]);
    };
  };
  
	swap(arr[p+1], arr[end-1]);
	for(int j = 0; j<= end - 1; j++){
	  
	  std::cout << "Pivot position " << p + 1 << endl;
	  
	}

	return (p+1);
  
  
};

void quicksort(int arr[], int start, int end){
  
  if(start < end){
    
    cout << "time to pivot" << endl;
    int p = partition(arr, start, end);
    cout << "time to recurse" << endl;
    quicksort(arr, start, p-1);
    quicksort(arr, p+1, end);
    
  }
};

 
void swap(int &val1, int &val2){
  
  int temp;
  temp = val1;
  val1 = val2;
  val2 = temp;
  
  
};


int main(){

	int start = 0;
	int end = 1000;

	 int small [100];
    for(int i = 0; i < 100; i++){
      int j = rand() % 100;
        small [i] = j;
    }

  int med [10000];
    for(int i = 0; i < 10000; i++){
      int j = rand() % 100;
      med [i] = j;
    }

  int large [100000];
    for(int i = 0; i < 100000; i++){
      int j = rand() % 100;
      large [i] = j;
    }


	cout << "This is the quickSort: \n";

	int sec = 60; 

	double start2 = double(clock())/sec;
	quicksort(large, start, end-1);
	double finish2 = double(clock())/sec;
	cout << "sorted" << endl;


	cout << "This is the mergeSort: \n";

	double start3 = double(clock())/sec;

	int mergeCount = 0;
	mergeSort(large, start, end-1, mergeCount);

	std::cout << "Swaps = " << mergeCount << '\n';

	double finish3 = double(clock())/sec;
	cout << "sorted" << endl;
	// cout << "The time taken to sort was: " << finish3 - start3 << endl;


	cout << "*********************************" << endl;
	cout << "Quick Sort" << endl;

	cout << "The time taken to sort array was: " << finish2 - start2 << endl;


	cout << "*********************************" << endl;
	cout << "Merge Sort" << endl;

	cout << "The time taken to sort array was: " << finish3 - start3 << endl;

	cout << "*********************************" << endl;
};

