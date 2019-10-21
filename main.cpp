/*
 * Lab 1 320
 * August 2019
 * Dr. Anderson
 * Grace Burton
*/

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>
#include<time.h>

using namespace std;

void bubbleSort(int*, int);
void selectionSort(int*, int);
void insertionSort(int*, int);


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

 void bubbleSort(int arr[], int n)  
{  
    int count = 0;
    for (int i = 0; i < n-1; i++){   
    // Last i elements are already in place  
    for (int j = 0; j < n-i-1; j++){
        if (arr[j] > arr[j+1]) {
            swap(&arr[j], &arr[j+1]);
            count++;
          }//end if 
        }//end inside for
    }//end outside for
    cout << "Number of swaps " << count << endl;
}

void selectionSort(int arr[], int n) {
    int min;
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++){
          if (arr[j] < arr[min]) {
            min = j;
      }//end if
        swap(&arr[i], &arr[min]);
            count++;
    }//end for
}//end 1 for
   cout << "Number of swaps " << count << endl;
}

void insertionSort(int arr[], int n) {
    int k;
    int count;
    for (int i = 1; i < n; i++) {
        k = arr[i]; 
        j = i - 1;
        while (int j >= 0 && arr[j] > k) {
          arr[j+1] = arr[j];
          j = j - 1;
          count++;
        }//end while

        arr[j+1] = k;

    }//end for
       cout << "Number of swaps " << count << endl;
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

// bool isSorted(int arr[], int n){

// // The "auto" type determines the correct type at compile-time
// auto start = std::chrono::system_clock::now();

// insertionSort(med, 100);

// auto end = std::chrono::system_clock::now();
// std::chrono::duration<double> elapsed_seconds = end-start;
// std::time_t end_time = std::chrono::system_clock::to_time_t(end);
// cout << "finished at " << std::ctime(&end_time)
// << "elapsed time: " << elapsed_seconds.count() << "s\n";


//   cout << "Finished checking\n";
// }


int main(){

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

cout << "This is the insertionSort: \n";

int sec = 60; 

double start = double(clock())/sec;
insertionSort(med, 100);
double finish = double(clock())/sec;
cout << "sorted" << endl;
cout << "The time taken to sort was: " << finish - start << endl;

cout << "This is the selectionSort: \n";

double start2 = double(clock())/sec;
selectionSort(med, 100);
double finish2 = double(clock())/sec;
cout << "sorted" << endl;
cout << "The time taken to sort was: " << finish2 - start2 << endl;

cout << "This is the bubbleSort: \n";

double start3 = double(clock())/sec;
bubbleSort(med, 100);
double finish3 = double(clock())/sec;
cout << "sorted" << endl;
cout << "The time taken to sort was: " << finish3 - start3 << endl;

printArray(med, 100);

//isSorted(med,100);

}




