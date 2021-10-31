
#ifndef dMatrix_h
#define dMatrix_h

#include <iostream>
#include <cstdlib>
#include <cstring>

const int NMAX = 2500;

class dMatrix	//class declaration
{
public:
	int N;										//rows
	int M;										//columns

	dMatrix(int n, int m);						//constructor that initializes the matrix to the identity matrix if the matrix is square and zero.
	dMatrix(char file_name[]);					//constructor that initializes the member variables from a file
	~dMatrix();									//destructor that prints out "constructor dMatrix(n,m)"

	double max();								//function that returns the maximum value of  the matrix elements
	double& e(int i, int j);					//access function that returns a reference to the(i, j) element of the matrix

private:
	double A[NMAX];								//1D array of doubles

};

#endif // !dMatrix_h

void add(dMatrix& A, dMatrix& B, dMatrix& C);
void display(dMatrix& matrix);