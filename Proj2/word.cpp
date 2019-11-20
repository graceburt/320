/*
* Grace Burton
* Dr. Anderson 
* COSC 320
* Proj 2
* Word.cpp
*/

#include "diction.h"
#include <iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>

Word::Word(){

};

Word::Word(std::string s){

	str = s;
	heapSize = str.length();
};

long int Word::strToNum(){
	  long total = 0;
	  for(int i=0; i<s.length(); i++){
	    total += int(s.at(i)) * pow(128,s.length()-i-1);
	  }
	  return total;
};

bool Word::equalTo(Hash& h) const{

	Word& w = dynamic_cast<Word&>(h);
	//makes h a word object
	bool same = (str == w.str);
	return same;
};

std::string Word::toString(){

	return str;
}