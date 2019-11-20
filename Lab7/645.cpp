/*

Grace Burton
Dr. Anderson
Lab 7 
October 21, 2019

*/

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <sstream>

//Hash int

size_t hash(size_t n){

	//using "multiplication method"
	int p = 13;
	int a = (1-sqrt(5));

	size_t W = (2<<31);
	size_t M = (2<<p);

	//given n, return |(an mod W)/2^w−p|
	
	//using (left) SHIFT (<<) takes two numbers, shifts bits of first opernd, the second decides # of places to shift
	//ex) x<<y == x(2^y)
	//using (right) SHIFT (>>) which does the same thing, but shifts to the right.
	//ex) x>>y == x/(2^y)

	//possible bugs: negative numbers cannot be shifted == undf
	//				 if shifted more than size of int == undf

	

	//1.) Calculate size_t sechalf = W - M (for 2^w-p)
	//2.) size_t half = (a*n)>>W;
	//3.) half>>sechalf

	//why does this function make sense?

	size_t sechalf = W - M;
	size_t half = (a*n)>>W;
	size_t answer = half>>sechalf;

	return answer;

};

//Hash string

size_t strHash(std::string str){

	long int s = 0;

	// char cstr[str.size()+1];
	// strcpy(cstr, &str[0]); //copies string into character arr, starting at first character in string

	// std::cout << cstr << std::endl;

	for(int i = 0; i < str.length(); i++){
		char h = str.at(i);
		s+=int(h);
	}

	s = hash(s);

	return s;


};

// bool isVowel(char c) 
// { 
//     return (c == 'A' || c == 'E' || c == 'I' ||  
//             c == 'O' || c == 'U' || c == 'a' ||  
//             c == 'e' || c == 'i' || c == 'o' || 
//             c == 'u'); 
// } 

// std::string pigHash(std::string str){

// 	int len = str.length(); 
//     int index = -1; 
//     for (int i = 0; i < len; i++) { 
//         if (isVowel(str[i])) { 
//             index = i; 
//             break; 
//         } 
//     } 

  
//     // Take all characters after index (including 
//     // index). Append all characters which are before 
//     // index. Finally append "ay" 
//     std::string final = str.substr(index) + str.substr(0, index) + "ay";
//     // std::cout << final;

//     std::cout << std::endl;
    
//     return final;


// };

//Convert size_t hash -> hexidec

// void IntHex(const size_t* x){
// 	//int to hex

// 	for(int i = 0; i<=4; i++){
// 		std::cout << "Array at position " << i << std::endl;
// 		std::cout << std::hex << (int)x[i] << std::endl;
// 	}

// };

// void StrHex(std::string str){

// 	//string to hex

// 	for(int i = 0; i<=str.size(); i++){
// 		std::cout << std::endl;
// 		std::cout << "Array at position " << i << std::endl;
// 		std::cout << std::hex << (int)str[i];	
// 	}


// };

std::string hex(size_t n){
	std::stringstream ss;
	ss << std::hex << n;
	return ss.str();
}

int main(){

	size_t test[5] = {24, 25, 26, 27, 28};

	std::cout << std::endl;
	std:: cout << "size_t -> hash" << std::endl;
	std::cout << std::endl;
	for(int i = 0; i < 5; i++){
		std::cout << hash(test[i]) << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std:: cout << "size_t -> hex" << std::endl;
	std::cout << std::endl;
	size_t wtf = 123;
	std::cout << "Test of hex " << hex(wtf) << " " << std::endl;
	std::cout << std::endl;

	std::string one = "hell";
	std:: cout << "hash of str" << std::endl;
	std::cout << strHash(one) << std::endl;
	std:: cout << "hex of hash of str" << std::endl;
	std::cout << hex(strHash(one)) << std::endl;
	std::cout << std::endl;


	return 0;
}


