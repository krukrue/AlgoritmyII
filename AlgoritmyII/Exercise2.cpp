#include "Exercise2.h"
#include "Components.h"
#include <cstdlib>

using namespace std;


bool Exercise2::ForwardElimination(Equation& equation)
{
	unsigned int n = equation.size - 1;
	float** A = equation.matrixA;
	float* b = equation.elementsB;

	for (unsigned int i = 0; i <= n; i++)
	{
		A[i][n + 1] = b[i];
	}

	for (unsigned int i = 0; i <= n; i++)
	{
		if (A[i][i] == 0)
		{
			std::cout << "Mathematical Error!" << std::endl;
			return false;
		}

		for (unsigned int j = i + 1; j <= n; j++)
		{
			float ratio = A[j][i] / A[i][i];
			for (unsigned int k = i; k <= n + 1; k++)
			{
				A[j][k] = A[j][k] - ratio * A[i][k];
			}
		}
	}

	return true;
}

bool Exercise2::BetterForwardElimination(Equation& equation)
{
	unsigned int n = equation.size - 1;
	float** A = equation.matrixA;
	float* b = equation.elementsB;

	for (unsigned int i = 0; i <= n; i++)
	{
		A[i][n + 1] = b[i];
	}

	for (unsigned int i = 0; i <= n; i++)
	{
		int pivotrow = i;

		for (unsigned int j = i + 1; j <= n; j++)
		{
			if (abs(A[j][i]) > abs(A[pivotrow][i]))
			{
				pivotrow = j;
			}
		}

		if (pivotrow != i)
		{
			for (unsigned int k = 0; k <= n + 1; k++)
			{
				// Debug output
				//std::cout << "i: " << i << " pivotrow: " << pivotrow << std::endl;
				//std::cout << A[i][k] << ':' << A[pivotrow][k] << std::endl;

				Components<float>::SwapValues(A[i][k], A[pivotrow][k]);
			}
		}

		for (unsigned int j = i + 1; j <= n; j++)
		{
			float temp = A[j][i] / A[i][i];
			for (unsigned int k = i; k <= n + 1; k++)
			{
				A[j][k] = A[j][k] - A[i][k] * temp;
			}
		}
	}

	return true;
}

void Exercise2::BackSubstitution(Equation& equation, float*& result)
{
	unsigned int N = equation.size;
	float* X = result;

	float** A = equation.matrixA;

	for (int i = N - 1; i >= 0; i--)
	{
		X[i] = A[i][N];

		for (unsigned int j = i + 1; j < N; j++)
		{
			X[i] -= A[i][j] * X[j];
		}

		X[i] = X[i] / A[i][i];
	}
}

bool Exercise2::LinearDecomposition(Equation& equation) {
	const unsigned  int n = equation.size;
	float** A = equation.matrixA;
	int first[3][3], second[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	memset(first, 0, sizeof(first));
	memset(second, 0, sizeof(second));

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int sum = 0;
			for (int k = 0; k < i; k++) {

				sum += (first[i][k] * second[k][j]);
			}

			second[i][j] = A[i][j] - sum;
		}

		for (int j = i; j < n; j++)
		{
			if (i == j)
				first[i][i] = 1; 
			else
			{
				int sum = 0;
				for (int k = 0; k < i; k++) {

					sum += (first[j][k] * second[k][i]);
				}

				first[j][i] = (A[j][i] - sum) / second[i][i];
			}
		}
	}



	cout << "First" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "{";

		for (int j = 0; j < n; j++) {
			cout  << first[i][j] << "\t";
		}
		cout << "}" << endl;
	}
	
	cout << "Second" << endl;
	for (int i = 0; i < n; i++) {
		cout << "{";
		for (int j = 0; j < n; j++) {
			cout << second[i][j] << "\t";

		}
		cout << "}" << endl;
	}

	int X[3];
	memset(X, 0, sizeof(X));
	for (int i = n - 1; i >= 0; i--)
	{
		X[i] = first[i][n];

		for (unsigned int j = i + 1; j < n; j++)
		{
			X[i] -= first[i][j] * X[j];
		}

		X[i] = X[i] / first[i][i];

		cout << 'X' << i << "Result: " << X[i] << endl;
 	}	

	return true;

}

