// Assignement 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cmath>
#include <iomanip>
#include "dmatrix.h"

using std::cout;
using std::cin;
//
//int n_rows()
//{
//	int n{};
//	cout << "\nenter the number of rows: ";
//	cin >> n;
//
//	return n;
//}
//
//int m_columns()
//{
//	int m{};
//	cout << "\nenter the number of columns: ";
//	cin >> m;
//
//	return m;
//}

int main()
{
	cout << "Dynamic Matrix...\n";

	
	{
		dMatrix m1{ 3, 3 };
		dMatrix m2{ 3, 3 };
		dMatrix m3{ 3, 3 };
		cout << "m1 = \n";
		display(m1);
		cout << "m2 = \n";
		display(m2);
		cout << "m3 = \n";
		display(m3);
		add(m1, m2, m3);								//add function: C = A + B
		cout << "m3 = m1 + m2 = \n";
		display(m3);
	}

	{
		dMatrix m1{ 3, 3 };
		display(m1);
		cout << std::endl;
		m1.e(2, 2) = 10;
		m1.e(3, 3) = 9;
		double res = m1.max();								//max function
		display(m1);
		cout << "\nmax value of m1 = " << res << std::endl;

	}

	{
		char file[] = "matrix.txt";
		dMatrix m1(file);									//read file function
		cout << "\nMatrix in matrix.txt is: \n";
		display(m1);
	}

	{
		dMatrix m1{ 2, 3 };
		for (int i = 1; i <= m1.M; i++)
		{
			for (int j = 1; j <= m1.N; j++)
			{
				m1.e(i, j) = i - j + 3.0;
			}
		}

		char file[] = "matrix.bin";
		m1.save(file);										//save N, M, array in binary file function

		dMatrix m2{ 2,2 };
		m2.load(file);
		
		cout << "\nMatrix A written to binary file is: \n";
		display(m1);

		cout << "\nMatrix B retrieved from binary file is: \n";
		display(m2);
	}


	system("pause");

}


