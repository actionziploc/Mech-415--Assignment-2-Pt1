
#ifndef dMatrix_h
#define dMatrix_h

#include <iostream>
#include <cstdlib>
#include <cstring>

class dMatrix	//class declaration
{
public:
	int N;										//rows
	int M;										//columns
	
	static int n_objects;						//variable that counts the number of instances for dMatrix class

	dMatrix(int N, int M);						//constructor that initializes the matrix to the identity matrix if the matrix is square and zero.
	dMatrix(char file_name[]);					//constructor that initializes the member variables from a file
	~dMatrix();									//destructor that prints out "constructor dMatrix(n,m)"

	double max();								//function that returns the maximum value of  the matrix elements
	double& e(int i, int j);					//access function that returns a reference to the(i, j) element of the matrix
	double save(char file_name[]);				//function that writes the dMatrix member variables to a binary file
	double load(char file_name[]);				//function that read the dMatrix member variables from a binary file with the file format.

private:
	double* A = nullptr;
	
};

void add(dMatrix& A, dMatrix& B, dMatrix& C);
void display(dMatrix& matrix);

#endif // !dMatrix_h