#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>

class Matrix{

private:

	long unsigned int rows;
	long unsigned int columns;
	int** matrix;

public:

	Matrix();
	Matrix(long unsigned int, long unsigned int);
	Matrix(const Matrix&);
	~Matrix();
	void triangleMatrix();
	void diagonalMatrix();
	void identityMatrix();

	void fillMatrix();

	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator+=(const Matrix&, const Matrix&);
	//friend Matrix operator=(const Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);
	friend Matrix operator*(int, const Matrix&);
	friend std::ostream& operator<<(std::ostream& os, const Matrix&);



};


#endif
