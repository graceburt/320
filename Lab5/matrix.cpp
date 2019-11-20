/*
 * Lab 5 320
 * matrix.cpp
 * October 2019
 * Dr. Anderson
 * Grace Burton
*/

#include "matrix.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;

Matrix::Matrix(){

	rows = 0;
	columns = 0;

};

Matrix::Matrix(long unsigned int r, long unsigned int c){

	rows = r;
	cout << r <<endl;
	columns = c;
	cout << c << endl;

	matrix = new int*[r];
	for(int i = 0; i < rows; i++){
		matrix[i] = new int[c];
		//set all elements to 0
		for(int j = 0; j < columns; j++){
			matrix[i][j] = 0;
		}
	};

};


void Matrix::fillMatrix(){

	unsigned int fill;

	int r = this->rows;
	std::cout << r << std::endl;
	int c = this->columns;
	std::cout << c << std::endl;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			std::cout << "What would you like the element at position " << this->matrix[i][j] << " to be? " << std::endl;
			fill = rand() % 10;
			this->matrix[i][j] = fill;
		}
	};

};



Matrix::~Matrix(){
	for(int i = 0; i < rows; i++){
		delete [] matrix[i];
	};
	delete[] matrix;
	cout << "Finished deconstructing" << endl;

};


Matrix::Matrix(const Matrix &m)
{
    std::cout<< "Called copy-constructor" << std::endl;
    rows = m.rows;
    columns = m.columns;
    matrix = new int*[rows];
    for (int i=0; i<rows; i++)
    {
        matrix[i] = new int[columns];
        *(matrix[i]) = *(m.matrix[i]);
    }

};


void Matrix::triangleMatrix(){

	for(int i = 0; i < this->rows; i++){
		for(int j = 0; j < this->columns; j++){

			if(this->matrix[rows] == this->matrix[columns]){
				matrix[i][j] = 1;
			}
			else 
			{
				matrix[i][j] = 0;
			}

		}//end column loop
	}//end row loop

};


void Matrix::diagonalMatrix(){

	for(int i = 0; i < this->rows; i++){
		this->matrix[i][i] = 0;
	}

};

void Matrix::identityMatrix(){

	for(int i = 0; i < this->rows; i++){
		this->matrix[i][i] = 1;
	}

};


Matrix operator+(const Matrix& m, const Matrix& n){

		if(m.rows != n.rows || m.columns != n.columns){
			cout << "Matrices do not match. " << endl;
			exit(1);
		}

		int r;
		r = m.rows;

		int c;
		c = m.columns;

		Matrix answer(r, c);

		for(int i = 0; i < m.rows; i++){//rows
			for(int j = 0; j < m.columns; j++){//columns

				answer.matrix[i][j] = m.matrix[i][j] + n.matrix[i][j];
		};

	};


	return answer;

};

Matrix operator-(const Matrix& m, const Matrix& n){

	//need to check size
		if(m.rows != n.rows || m.columns != n.columns){
			cout << "Matrices do not match. " << endl;
			exit(1);
		}

		int r;
		r = m.rows;

		int c;
		c = m.columns;

		Matrix answer(r, c);

		for(int i = 0; i < m.rows; i++){//rows
			for(int j = 0; j < m.columns; j++){//columns

				
				if(m.matrix[i][j] < n.matrix[i][j]){

					answer.matrix[i][j] = m.matrix[i][j] - n.matrix[i][j];

				}else{

					answer.matrix[i][j] = n.matrix[i][j] - m.matrix[i][j];

				};
		};

	};


	return answer;

};


// Matrix operator=(const Matrix& m){


// 	int r;
// 	r = m.rows;

// 	int c;
// 	c = m.columns;

// 	Matrix copy(r, c);

// 	for(int i = 0; i < m.rows; i++){//rows
// 			for(int j = 0; j < m.columns; j++){//columns

// 				copy.matrix[i][j] = m.matrix[i][j];
// 		};
// 	};

// 	return copy;

// };

// Matrix operator+=(const Matrix& m, const Matrix& n){

// 	if(m.rows != n.rows || m.columns != n.columns){
// 			cout << "Matrices do not match. " << endl;
// 			exit(1);
// 		}

// 	int r;
// 	r = m.rows;

// 	int c;
// 	c = m.columns;

// 	Matrix answer(r, c);

// 	for(int i = 0; i < m.rows; i++){//rows
// 			for(int j = 0; j < m.columns; j++){//columns

// 				answer.matrix[i][j] = m.matrix[i][j] + n.matrix[i][j];
// 		};
// 	};

// 	return answer;

// };

Matrix operator*(const Matrix& m, const Matrix& n){

		if(m.columns != n.rows){
			cout << "Matrices do not match. " << endl;
			exit(1);
		}

		int r;
		r = m.rows;

		int c;
		c = n.columns;

		Matrix answer(r, c);

		for(int i = 0; i < m.columns; i++){
			for(int j = 0; j < n.columns; j++){
				for(int l = 0; l < m.columns; l++){

				answer.matrix[i][j] += m.matrix[i][l] * n.matrix[l][j];

			};
		};
	};


	return answer;

};


Matrix operator*(int s, const Matrix& n){

		int r;
		r = n.rows;

		int c;
		c = n.columns;

		Matrix answer(r, c);

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){

				answer.matrix[i][j] += s * n.matrix[i][j];

		};
	};


	return answer;

};

std::ostream& operator<<(std::ostream& os, const Matrix& m){

	std::cout << "printing out matrix " << std::endl;

	for(int i = 0; i < m.rows; i++){

		for(int j = 0; j < m.columns; j++)
			{ 
				os << " " << printf("%d ", m.matrix[i][j]) << " "; 
			};

	std::cout<<"\n";
	
	};

	return os;

};