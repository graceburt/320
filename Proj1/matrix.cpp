/*
 * Proj 1 320
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

	matrix = new float*[r];
	for(int i = 0; i < rows; i++){
		matrix[i] = new float[c];
		//set all elements to 0
		for(int j = 0; j < columns; j++){
			matrix[i][j] = 0;
		}
	};
	std::cout << "Made Matrix\n";

};


void Matrix::fillMatrix(){

	unsigned int fill;

	int r = this->rows;
	std::cout << r << std::endl;
	int c = this->columns;
	std::cout << c << std::endl;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			//std::cout << "What would you like the element at position " << this->matrix[i][j] << " to be? " << std::endl;
			fill = rand() % 10;
			this->matrix[i][j] = fill;
		}
	};

};



// Matrix::~Matrix(){
// 	for(int i = 0; i < rows; i++){
// 		delete [] matrix[i];
// 	};
// 	delete[] matrix;
// 	cout << "Finished deconstructing" << endl;

// };


// Matrix::Matrix(const Matrix &m)
// {
//     std::cout<< "Called copy-constructor" << std::endl;
//     rows = m.rows;
//     columns = m.columns;
//     matrix = new float*[rows];
//     for (int i=0; i<rows; i++)
//     {
//         matrix[i] = new float[columns];
//         for(int j = 0; j < columns; j++){

//         	matrix[i][j] = m.matrix[i][j];

//         }
//     }

// };


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

Matrix Matrix::transpose(){

	Matrix transposed = Matrix(columns, rows);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			transposed[j][i] = matrix[i][j];
		}
	}

	std::cout << "transpose\n";
	return transposed;
};

Matrix& Matrix::padMatrix(){

	std::cout << "\nBeginning of pad\n\n";

	//check if needs to be padded

	int size = 2;
	while((size < rows || size < columns) && size > 0 ){
		size = size * 2; 
	} //no remainder

	float** old = matrix;
	int prevRows = rows;
	int prevCol = columns;
	

	//size is now rows and columns
	rows = columns = size;
	matrix = new float*[rows];
	for(int i = 0; i < rows; i++){
		matrix[i] = new float[columns];
		//set all elements to 0
		for(int j = 0; j < columns; j++){
			matrix[i][j] = 0;
		}
	};

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){

			if(i >= prevRows || j >= prevCol){
				if(i == j){
					matrix[i][j] = 1;
				}else{
					matrix[i][j] = 0;
				}//end of inside
			}else{
				matrix[i][j] = old[i][j];
			}
		}
	} //end for 
	
	for(int i = 0; i < prevRows; i++){
		delete [] old[i];
	}
	delete [] old;

	return *this;

};

// Matrix& Matrix::Inverse(){

// 	std::cout << "Beginning of Inverse\n";

// 	cout << *this;
// 	Matrix temp = *this;
// 	cout << temp;
// 	cout << temp.rows << " " << temp.columns << endl;

// 	bool result = true;
// 	while(rows != 1){

// 		if(rows % 2 == 0)
// 		{
// 			std::cout << "Matrix doesn't need padding\n";
// 			cout << temp.rows << " " << temp.columns << endl;
// 			break;
// 		}
// 		else{
// 			std::cout << "Matrix needs padding\n";
// 			result = false;
// 			rows = rows / 2;
// 		}
	
// 	}

// 	if (result == false){

// 		std::cout << "Inverse calling padding \n";

// 		padMatrix(*this);

// 	}


// 	return temp.recursiveInverse();

// };

Matrix& Matrix::recursiveInverse(){
	//check if matrix rows and columns are 2^n
	int count = 0;

	std::cout << "\nBeginning of Recursive Inverse\n";

		//base case 1x1, return reciprocal
	if(rows && columns == 1){
		
		std::cout << "inverse base case\n";

		cout << "Matrix at top right value (0,0) " << matrix[0][0] << endl;

		if(matrix[0][0] != 0){
			matrix[0][0] = 1/matrix[0][0];
		}

		cout << *this << endl;
		return *this;

	}


	int unpadRow = rows;
	int unpadCol = columns;

	padMatrix();

	int halfRow = rows/2;
	int halfCol = columns/2;


	std::cout << "Split the Matrix " << count++ << " times \n" << endl;

	Matrix B = Matrix(halfRow, halfCol);
	Matrix Ct = Matrix(halfRow, halfCol);
	Matrix C = Matrix(halfRow, halfCol);
	Matrix D = Matrix(halfRow, halfCol);

	//put values inside 
	//B Ct
	//C D
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){

			if(i < halfRow && j < halfCol){
				cout << endl;
				cout << "B ";
				B[i][j] = matrix[i][j];
				std::cout << B[i][j] << endl;

			}
			else if(i < halfRow && j >= halfCol){
				cout << endl;
				cout << "Ct ";
				Ct[i][j - halfCol] = matrix[i][j];
				std::cout << Ct[i][j - halfCol] << endl;

			}
			else if(i >= halfCol && j < halfCol){
				cout << endl;
				cout << "C ";
				C[i - halfRow][j] = matrix[i][j];
				std::cout << C[i - halfRow][j] << endl;

			}else if(i >= halfRow && j >= halfCol){
				cout << endl;
				cout << "D ";
				D[i - halfRow][j - halfCol] = matrix[i][j];
				std::cout << D[i - halfRow][j - halfCol] << endl;

			}
		}
	}//end fill

	cout << endl;

	cout << "Inverse functions\n\n";

	Matrix invB = B.recursiveInverse();
	cout << "Completed inverting B " << invB << endl;
	Matrix W = C*invB;
	cout << "Completed computing W " << W << endl;
	Matrix Wt = W.transpose();
	cout << "Completed transposing W " << Wt << endl;
	Matrix X = W*Ct;
	cout << "Completed computing X " << X << endl;
	Matrix S = (D - X);
	cout << "Completed computing S " << S << endl;
	Matrix V = S.recursiveInverse();
	cout << "Completed inverting S " << V << endl;
	Matrix Y = V*W;
	cout << "Completed computing Y " << S << endl;
	Matrix Yt = Y.transpose();
	cout << "Completed transposing Y " << Yt << endl;
	Matrix T = -1 * Yt;
	cout << "Completed computing T " << T << endl;
	Matrix U = -1 * Y;
	cout << "Completed computing U " << U << endl;
	Matrix Z = Wt * Y;
	cout << "Completed computing Z " << Z << endl;
	Matrix R = invB + Z;
	cout << "Completed computing R " << R << endl;

	for(int i = 0; i < rows; i++){
		delete [] matrix[i];
	};
	delete[] matrix;

	cout << "Delete check\n";

	rows = unpadRow;
	columns = unpadCol;
	matrix = new float*[rows];
	for(int i = 0; i < rows; i++){
		matrix[i] = new float[columns];
		//set all elements to 0
		for(int j = 0; j < columns; j++){
			matrix[i][j] = 0;
		}
	};

	cout << "Finishing Inverse\n";

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){

			if(i < halfRow && j < halfCol){

				cout << "R ";
				matrix[i][j] = R[i][j];
				std::cout << matrix[i][j] << endl;

			}
			else if(i < halfRow && j >= halfCol){

				cout << "T ";
				matrix[i][j] = T[i][j - halfCol];
				std::cout << matrix[i][j] << endl;
			}
			else if(i >= halfCol && j < halfCol){

				cout << "U ";
				matrix[i][j] = U[i - halfRow][j];
				std::cout << matrix[i][j] << endl;
			
			}else if(i >= halfRow && j >= halfCol){

				cout << "V ";
				matrix[i][j] = V[i - halfRow][j - halfCol];
				std::cout << matrix[i][j] << endl;
			}
		}
	}

	return *this;

};

// Matrix& Matrix::BHat(const Matrix& A, const Matrix& B){

// 	std::cout << "BHat\n";

// 	Matrix At = A;

// 	At.transpose();

// 	std::cout << At.rows;
// 	std::cout << At.columns;

// 	Matrix half = (At * A);

// 	std::cout << half.rows;
// 	std::cout << half.columns;

// 	std::cout << "BHat\n";

// 	Matrix invHalf = Inverse(half);

// 	std::cout << "BHat\n";

// 	std::cout << invHalf;

// 	Matrix Bhat = (invHalf * At);
// 	Matrix final = Bhat * B;

// 	return final;

// };

float*& Matrix::operator[](const int& i) const {

				return matrix[i]; 
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


void Matrix::operator=(Matrix& m){

	int r;
	r = m.rows;

	int c;
	c = m.columns;

	cout << "Hello\n";
	
	for (int i=0; i<rows; i++)
    {
        matrix[i] = new float[columns];
        for(int j = 0; j < columns; j++){

        	matrix[i][j] = m.matrix[i][j];

        }
    }

};

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

		for(int i = 0; i < m.rows; i++){
			for(int j = 0; j < n.columns; j++){
				for(int l = 0; l < n.rows; l++){

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

	std::cout<<" \n";

	for(int i = 0; i < m.rows; i++){

		for(int j = 0; j < m.columns; j++)
			{ 
				os << " " << m.matrix[i][j] << " "; 
			};

	std::cout<<" \n";
	
	};
	std::cout<<" \n";
	
	return os;

};