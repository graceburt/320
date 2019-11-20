/*
* Grace Burton
* Dr. Anderson
* COSC 320
* Project 2
* main.cpp
*/

#include "diction.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <bits/stdc++.h> 

std::string letters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "y", "x", "z"};

Node* HELP = new Node;


void Dictionary::spellCheck(Node* w){

	int sec = 60;
	int count = 0;
	int count2 = 0;

	Dictionary sugg(8192);

	// std::cout << "ALERT" << w->word << std::endl;

	if(!searchNode(w->word)){
		count++;
		std::cout << w->word << " is not a word in this dictionary, finding suggestions..." << std::endl;
		double start3 = double(clock())/sec;
		for(int i = 0; i < w->word.length(); i++){

			std::string tmp = w->word;
			for(int j = 0; j < 26; j++){
				std::string tmp2 = tmp.replace(i, 1, letters[j]);
				count2++;
				std::cout << "Can be replaced with: " << tmp2 << std::endl;
				if(searchNode(tmp2)){
					std::cout << "In dictionary! " << std::endl;
				}
			}//end inside for
		}//end outside for
		double finish3 = double(clock())/sec;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Time to compute suggestions: " << " | " << finish3 - start3 << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Number of incorrect words: " << " | " << count << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Number of possible words: " << " | " <<count2 << std::endl;
		std::cout << "--------------------------------------" << std::endl;

	}//end if
	else{

		std::cout << w->word << " is a word!" << std::endl;
	}
};


// void Dictionary::spellCheck2(Node* w){

// 	int sec = 60;
// 	int count = 0;
// 	int count2 = 0;

// 	Dictionary sugg(8192);

// 	std::cout << "ALERT IN 2" << w->word << std::endl;

// 	if(!searchNode(w->word)){
// 		count++;
// 		std::cout << w->word << " is not a word in this dictionary, finding suggestions..." << std::endl;
// 		double start3 = double(clock())/sec;
// 		for(int i = 0; i < w->word.length(); i++){

// 			std::string tmp = w->word;
// 			for(int j = 0; j < 26; j++){
// 				std::string tmp2 = tmp.replace(i, 1, letters[j]);
// 				count2++;
// 				std::cout << "Can be replaced with: " << tmp2 << std::endl;
// 				// if(searchNode(tmp2)){
// 				// 	count2++;
// 				// 	sugg.insert(tmp2);
// 				// }
// 			}//end inside for
// 		}//end outside for
// 		double finish3 = double(clock())/sec;
// 		std::cout << "--------------------------------------" << std::endl;
// 		std::cout << "Time to compute suggestions: " << " | " << finish3 - start3 << std::endl;
// 		std::cout << "--------------------------------------" << std::endl;
// 		std::cout << "Number of incorrect words: " << " | " << count << std::endl;
// 		std::cout << "--------------------------------------" << std::endl;
// 		std::cout << "Number of possible words: " << " | " <<count2 << std::endl;
// 		std::cout << "--------------------------------------" << std::endl;

// 	}//end if
// 	else{

// 		std::cout << w->word << " is a word!" << std::endl;
// 	}
// };


int main(){

	int sec = 60;
	std::string line; 
	int numLines = 0;
	size_t tableSize = 8192;

	ifstream words("english.txt");

	if(words.is_open()){

		std::cout << "File is inputting..." << std::endl;
		
		double start = double(clock())/sec;

		Dictionary test(tableSize);
		std::string temp;

			while(!words.eof()){
				getline(words, temp);
				test.insert(temp);
			};

		double finish = double(clock())/sec;
		std::cout << "Insertion of file into hash took: " << finish-start << " miliseconds" << std::endl;

		words.close();

		test.stats();

		// Node* w = new Node(); 
		// w->word = "tihs";

		// test.spellCheck(w);



//user input here \/\/\/

		int size = 8192;

		std::cout << "Please enter a sentence: " << std::endl;

		std::string str;
		getline(std::cin, str);
		std::string sentence;
		Node* W = new Node();
		// Dictionary words(size);
		std::cout << "You entered: " << str << std::endl;

		for(int i = 0; i < str.length()+1; i++){
			std::cout << str[i] << std::endl;
			//You can't compare a character to a string, so '' is used instead of ""
			if(!isspace(str[i])){
				std::cout << "run " << i << " " << sentence << std::endl;
				sentence = sentence + str[i];
			}//else it is a string, concatonate and enter
			else{
				std::cout << sentence << std::endl;
				W->word = sentence;
				std::cout << "ALERT " << W->word << std::endl;
				test.spellCheck(W);
				sentence = str[i+1];

				i++;
			}//end else
		}//end for
		W->word = sentence;
		test.spellCheck(W);

		// std::string wwrd;

		// std::cout << "Which is correct? " << std::endl;
		// cin >> wwrd;
		// test.insert(wwrd);
		// std::cout << "Added to dictionary. " << std::endl;

		std::cout << std::endl;


//second edit distance here \/\/\/

		// test.spellCheck2(W);


		std::cout << std::endl;


};//end if -- closes file

};