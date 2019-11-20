/*
* Grace Burton
* Dr. Anderson
* COSC 320
* Project 2
* diction.cpp
*/

#include "diction.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

Dictionary::Dictionary(size_t size){

	hashSize = size;
	data = new Node*[hashSize];
	for(size_t i = 0; i <= size; i++){

		data[i] = NULL;

	}


};

long Dictionary::modHash(long n){

	return n % hashSize;
};

long Dictionary::multiHash(long n){

	long w = 31;
	int p = 13;
	//hash table has 2^13 boxes, p is # of bits in hash

	//double A = 0.6180339887498949; // ~ 1 - sqrt(5)
	int s = 8;
	// ^ is the key

	return (((s*n) & ((1 << w) - 1)) >> (w - p));
};

void Dictionary::insert(std::string k){

	long h = multiHash(strToNum(k));
	// std::cout << "Hash value:" << h << "  Word: " << k << std::endl;

	Node* newNode = new Node;
	newNode->word = k;
	newNode->key = h;
	newNode->prev = NULL;
	newNode->next = NULL;

	if(data[h] != NULL){

		newNode->next = data[h];
		newNode->next->prev = newNode;
	}


	data[h] = newNode;
	numElements++;

};

void Dictionary::stats(){


	double avgBucketSize = 0;
	long minFill = -1;

	int count = 0;
	for( int i = 0; i < hashSize; i++){

		if(data[i] > 0){
			count++;
		}
	}

	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Total # of words in Hash: " << " | " << numElements << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Total # of buckets in Hash: " << " | " << hashSize << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Total # of buckets in use: " << " | " << count << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	for(int i = 1; i < hashSize; i++){

		if(data[i] > 0){

			long item = data[i]->key;
			avgBucketSize += item;
			if(minFill == -1 || item < data[minFill]->key){
				minFill = i;
			}
			if(maxFill == 0 || item > data[maxFill]->key){
				maxFill = i;
				}//end inside if
		}//end if
	}//end for

	avgBucketSize /= count;

	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Largest bucket size: " << " | " << maxFill << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Average bucket size: " << " | " << avgBucketSize << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Smallest bucket size: " << " | " << minFill << std::endl;
	std::cout << "--------------------------------------" << std::endl;

};

bool Dictionary::searchNode(std::string k) {

        long h = multiHash(strToNum(k));
        Node* findNode = data[h];
        bool found = false;
        if(findNode != NULL) {
                while(findNode != NULL) {
                        if(findNode->word == k) {
                                found = true;
                                return found;
                        }
                        if(found) {
                                return found;
                        }
                        findNode = findNode->next;
                }
        }
        // if(!found) {
        //         fixWord(key);
        //         //brute force one edit distance
        // }
};

long strToNum(std::string s){
	  long total = 0;
	  for(int i=0; i<s.length(); i++){
	    total += int(s.at(i)) * pow(128,s.length()-i-1);
	  }
	  return total;
};