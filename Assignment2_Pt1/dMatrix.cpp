//This .cpp file is a function library that defines the members of dMatrix class

#include <iostream>
#include "dmatrix.h"
#include <fstream>

using namespace std;



//constructor that initializes the matrix to the identity matrix if the matrix is square and zero.
dMatrix::dMatrix(int n, int m)
{
	N = n;
	M = m;

	cout << "\nconstructor dMatrix(n, m)\n";
	if (n * m <= NMAX)
	{
		if (n == m)
		{
			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					int k = (j - 1) + (i - 1) * m;
					A[k] = i == j ? 1 : 0;
				}
			}
		}
	}
	else
	{
		cout << "Number of columns and rows too big.\n";
	}

}

//destructor that prints out "constructor dMatrix(n,m)"
dMatrix::~dMatrix()
{
	cout << "\ndestructor for dMatrix\n";
}

//constructor that initializes the member variables from a file
dMatrix::dMatrix(char file_name[])
{
	std::ifstream file = std::ifstream(file_name);
	if (file.is_open())
	{
		file >> N;
		file >> M;

		for (int i = 1; i <= N * M; i++)
		{
			file >> A[i - 1];
		}
	}
	else
	{
		cout << "Unable to open file " << file_name << "... try again chief.\n";
	}
}

//function that returns the maximum value of  the matrix elements
double dMatrix::max()
{
	double max_value = A[0];

	for (int i = 1; i <= N * M; i++)
	{
		if (A[i - 1] > max_value)
		{
			max_value = A[i - 1];
		}
	}
	return max_value;
}

//access function that returns a reference to the(i, j) element of the matrix
double& dMatrix::e(int i, int j)
{

	if (i > N or j > M)
	{
		cout << "Error! Matrix out of bounds." << endl;
		return A[0];
	}
	int k = (j - 1) + (i - 1) * M;
	return A[k];
}

//function that adds two matrices; C = A + B
void add(dMatrix& A, dMatrix& B, dMatrix& C)
{
	bool are_rows_equal = A.N == B.N and B.N == C.N;
	bool are_cols_equal = A.M == B.M and B.M == C.M;

	if (are_rows_equal and are_cols_equal) {

		for (int i = 1; i <= A.M; i++)
		{
			for (int j = 1; j <= A.N; j++)
			{
				C.e(i, j) = A.e(i, j) + B.e(i, j);
			}
		}
	}
	else
	{
		cout << "Matrix dimensions are not equal.. try again chief.\n";
	}

}

void display(dMatrix& matrix)
{
	for (int i = 1; i <= matrix.M; i++)
	{
		for (int j = 1; j <= matrix.N; j++)
		{
			cout << matrix.e(i, j) << ' ';
		}
		cout << "\n";
	}
}
