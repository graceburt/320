/*
 * Lab 5 320
 * main.cpp
 * October 2019
 * Dr. Anderson
 * Grace Burton
*/

#include "matrix.cpp"

int main(){
	//each new gets a delete

	Matrix* m = new Matrix(100,100);
	m->fillMatrix();

	//dereference matrix m 
	std::cout << *m << std::endl;

	Matrix* k = new Matrix(100,100);
	k->fillMatrix();

	//dereference matrix k 
	std::cout << *k << std::endl;

	int sec = 60; 

	double start2 = double(clock())/sec;
	Matrix z = (*k) * (*m);
	double finish2 = double(clock())/sec;
	std::cout << "clocked at: " << finish2 - start2 << std::endl;

	Matrix scalar = 2 * (*m);

	std::cout << z << std::endl;
	
	std::cout << "\n";

	std::cout << scalar << std::endl;

	delete m;
	delete k;
}