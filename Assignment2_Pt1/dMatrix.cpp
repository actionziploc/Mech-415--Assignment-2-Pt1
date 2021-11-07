//This .cpp file is a function library that defines the members of dMatrix class

#include <iostream>
#include "dmatrix.h"
#include <fstream>


using namespace std;

int dMatrix::n_objects;

//constructor that initializes the matrix to the identity matrix if the matrix is square and zero.
dMatrix::dMatrix(int n, int m)
{

	N = n;
	M = m;
	n_objects++;

	cout << "\nCurrent instances of dMatrix Class are: " << n_objects;
	cout << "\nconstructor dMatrix(n, m)\n";

	A = new double [N * M];

	for (int i = 0; i < N * M; i++)
	{
		A[i] = 0;
	}
	
	if (n == m)
	{
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
					int k = (i - 1) + (j - 1) * n;
					A[k] = i == j ? 1 : 0;
			}
		}
	}
}


//destructor that prints out "destructor dMatrix(n,m)"
dMatrix::~dMatrix()
{
	cout << "\ndestructor for dMatrix\n";
	n_objects--;
	cout << "\nCurrent instances of dMatrix Class are: " << n_objects << "\n";
	delete A;
}

//constructor that initializes the member variables from a file
dMatrix::dMatrix(char file_name[])
{
	A = new double[N * M];

	for (int i = 0; i < N * M; i++)
	{
		A[i] = 0;
	}
	ifstream file = ifstream(file_name);
	if (file.is_open())
	{
		file >> N;
		file >> M;
		 
		for (int i = 0; i < N * M; i++)
		{
			file >> A[i];
		}
	}
	else
	{
		cout << "\nUnable to open file " << file_name << "... try again chief.\n";
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

	if (i > M or j > N)
	{
		cout << "\nError! Matrix out of bounds." << endl;
		return A[0];
	}
	int k = (i - 1) + (j - 1) * N;
	return A[k];
}

//functions that writes dMatrix member variable to a binary file.
void dMatrix::save(char file_name[])
{
	int size = 0;
	double* iterator = A;

	while (*iterator != NULL)
	{
		size++;
		iterator++;
	}

	buffer = new double[size + 2];
	buffer[0] = N;
	buffer[1] = M;

	ofstream file = ofstream(file_name, ios::binary);
	
	if (file.is_open())
	{
		for (int i = 2; i < size + 2; i++)
		{
			buffer[i] = A[i];
		}
		file << buffer;
	}
	else
	{
		cout << "\nUnable to open file " << file_name << "... try again chief.\n";
	}
}

void dMatrix::load(char file_name[])
{
	
	/*int size = 0;
	double* iterator = buffer;

	while (*iterator != NULL)
	{
		size++;
		iterator++;
	}*/

	A = new double[N*M];
	
	ifstream file = ifstream(file_name, ios::binary);
	if (file.is_open())
	{

		N = buffer[0];
		M = buffer[1];
		
		file >> N;
		file >> M;

		for (int i = 2; i < N*M +2; i++)
		{
			A[i] = buffer[i];
			file >> A[i];
		}
	}
	else
	{
		cout << "\nUnable to open file " << file_name << "... try again chief.\n";
	}

}

//function that adds two matrices; C = A + B
void add(dMatrix& A, dMatrix& B, dMatrix& C)    //when call by value is used, the function does not work as intended; the values of the matrices are not passed so we get 'garbage'
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
		cout << "\nMatrix dimensions are not equal.. try again chief.\n";
	}

}

void display(dMatrix& matrix)
{
	for (int j = 1; j <= matrix.N; j++)
	{
		for (int i = 1; i <= matrix.M; i++)
		{
			cout << matrix.e(i, j) << ' ';
		}
		cout << "\n";
	}
}
