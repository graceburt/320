/*
* Grace Burton
* Dr. Anderson
* COSC 320
* Project 2
* diction.h
*/

#ifndef diction_h
#define diction_h

#include<iostream>
#include<string>


using namespace std;

struct Node{

	Node* prev;
	Node* next;

	std::string word;
	long key;
	int size;

	// Node(){

	// 	prev = nullptr;
	// 	next = nullptr;
	// 	word = "";
	// 	key = 0;
	// }

	// Node(std::string s){

	// 	prev = nullptr;
	// 	next = nullptr;
	// 	word = s;
	// 	key = 0;
	// }
};

class Dictionary{

	//this is where hash gets stored


public:

Node** data; 

	Dictionary();
	Dictionary(size_t);
	long modHash(long);
	long multiHash(long);
	void insert(std::string);
	bool contains(std::string);
	void stats();
	bool searchNode(std::string k);

	size_t hashSize = 0;
	size_t numElements = 0;
	long maxFill = 0;

	void spellCheck(Node*);
	void spellCheck2(Node*);

	std::string& operator[](int i){
		//you cannot return a string as an int& value?

			// good idea to also check that 1 <= i <= length;
				return data[i-1]->word; 
			// so A[1] is the first and A[n] is the last

		};

};

long strToNum(std::string);
bool equalTo(Node&);
std::string toString();
Dictionary* readFile(char*);
	void userInput();

#endif