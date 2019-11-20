#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>

class Matrix{

// private:

// 	long unsigned int rows;
// 	long unsigned int columns;
// 	float** matrix;

public:

	long unsigned int rows;
	long unsigned int columns;
	float** matrix;

	Matrix();
	Matrix(long unsigned int, long unsigned int);
	//Matrix(const Matrix&);
	//~Matrix();
	void triangleMatrix();
	void diagonalMatrix();
	void identityMatrix();

	void fillMatrix();
	Matrix& padMatrix();
	Matrix& Inverse();
	Matrix& recursiveInverse();
	Matrix transpose();
	void checkMatrix(const Matrix&);

	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator+=(const Matrix&, const Matrix&);
	void operator=(Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);
	friend Matrix operator*(int, const Matrix&);
	float*& operator[] (const int&) const;
	friend std::ostream& operator<<(std::ostream& os, const Matrix&);



};


#endif
