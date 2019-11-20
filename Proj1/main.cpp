/*
 * Proj 1 320
 * main.cpp
 * October 2019
 * Dr. Anderson
 * Grace Burton
*/

#include "matrix.h"
#include "matrix.cpp"
#include <fstream>

// int main(){

// Matrix test = Matrix(2,2);
// test.fillMatrix();

// std::cout << test;

// Matrix testT = test.transpose();

// std::cout << testT;

// std::cout << std::endl;
// std::cout << "Linear Regression Testing\n";
// std::cout << "===============================================\n";
// std::cout << std::endl;

// Matrix half = (testT * test);

// std::cout << half.rows;
// std::cout << half.columns;
// cout << half;

// std::cout << std::endl;
// std::cout << "BHAT\n";
// std::cout << "===============================================\n";
// std::cout << std::endl;

// 	Matrix invHalf = half.recursiveInverse();

// 	std::cout << "(At * A)^-1" << invHalf;

// 	std::cout << "BHat\n";

// 	std::cout << invHalf;

// 	Matrix Bhat = (invHalf * testT);

// 	Matrix final = (Bhat * B);

// }

int main(){


Matrix test = Matrix(2,2);
test.fillMatrix();

std::cout << test;
Matrix testT = test.transpose();

cout << (test*testT).recursiveInverse();



// 	std::ifstream ifile("points100.dat");

// 	Matrix A = Matrix(100,2);
// 	Matrix B = Matrix(100,1);

// 	float c1, c2;
// 	int i = 0;

// 	while(ifile >> c1 >> c2 && i < 100){

// 		//set matrix value to c1 and c2
// 		//c2 goes to B
// 		//c1 is A, (Ax1)

// 				A[i][0] = c1;
// 				A[i][1] = 1;
// 				B[i][0] = c2;
// 				i++;


// 	}//end while

// 	ifile.close();

// 	std::cout << "Main\n";


// std::cout << "Linear Regression Testing\n";
// std::cout << "===============================================\n";
// std::cout << std::endl;


// std::cout << A;
// std::cout << B;

// std::cout << ((((A.transpose() * A).recursiveInverse()) * A.transpose()) * B) << endl;

}