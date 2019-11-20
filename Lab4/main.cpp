/*
 * Lab 4 320
 * main.cpp
 * September 2019
 * Dr. Anderson
 * Grace Burton
*/


#include<iostream>
#include "priority.h"

int main(){

//have to change x = NUM; where NUM is testing size

	int x = 0;

	cout << "Number of nodes in heap: " << endl;
	cin >> x;

	// int start = 0;
	// int end = x;

	std::string* testArray = new string[x];

	for(int i = 0; i < x; i++){
		std::string test; 
		cout << "Fill name: " << endl;
		cin >> test;
		testArray[i] = test;
	};

	int* testP = new int[x];

	for(int j = 0; j < x; j++){
		testP[j] = j;
	};

//not sure if right syntax
	HeapQ<std::string> Trial(testArray, testP, x);

	Trial.heapSort(Trial);
	Trial.print(Trial);
	cout << endl;
	Trial.peek(Trial);
	cout << endl;
	Trial.extractmax(Trial);
	//Trial.insert(Trial, 10);
	Trial.print(Trial);


	return 0;


};