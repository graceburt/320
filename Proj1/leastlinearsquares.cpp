/*
 * Proj 1 320
 * main.cpp
 * October 2019
 * Dr. Anderson
 * Grace Burton
*/

//this will be where the files are read in and the vectors are converted into Matrices

#include "matrix.h"

Matrix& Matrix::BHat(Matrix& A, const Matrix& B){

	Matrix At = A.transpose();

	Matrix half = (At * A);

	std::cout << "BHat\n";

	Matrix invHalf = Inverse(half);

	std::cout << invHalf;

	Matrix Bhat = (invHalf * At);
	Matrix final = Bhat * B;

	return final;

};