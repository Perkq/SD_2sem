#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <Windows.h>

using namespace std;

void pusir(int* A, int n);
void vstavki(int* B, int n);
void vibor(int* C, int n);
void quicksrt(int* D, int low, int n);

int main()
{
	setlocale(LC_ALL, "rus");

	clock_t start_time, end_time;

	cout << "Введите число N: ";
	int n;
	cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	int* C = new int[n];
	int* D = new int[n];
	int* E = new int[n];

	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 10000 + 1;
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
		cout << A[i] << " ";
	}

	//Сортировка пузырьком
	start_time = clock();
	pusir(A, n);
	end_time = clock();

	cout << "\nСортировка пузырьком. Затраченное время: " << end_time - start_time << endl;
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	
	delete[] A;

	//Сортировка вставкой
	start_time = clock();
	vstavki(B, n);
	end_time = clock();

	cout << "\nСортировка вставкой. Затраченное время: " << end_time - start_time << endl;
	for (int i = 0; i < n; i++)
		cout << B[i] << " ";

	delete[] B;

	//Сортировка выбором
	start_time = clock();
	vibor(C, n);
	end_time = clock();

	cout << "\nСортировка выбором. Затраченное время: " << end_time - start_time << endl;
	for (int i = 0; i < n; i++)
		cout << C[i] << " ";

	delete[] C;

	//Быстрая сортировка
	start_time = clock();
	quicksrt(D, 0, n - 1);
	end_time = clock();

	cout << "\nБыстрая сортировка. Затраченное время: " << end_time - start_time << endl;
	for (int i = 0; i < n; i++)
		cout << D[i] << " ";

	delete[] D;

	return 0;
}

void pusir(int* A, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0, b; j < n - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				b = A[j];
				A[j] = A[j + 1];
				A[j + 1] = b;
			}
		}
}

void vstavki(int* B, int n)
{
	int b, q; 
	for (int i = 1; i < n; i++)
	{
		b = B[i]; 
		q = i - 1; 
		while (q >= 0 && B[q] > b) 
		{
			B[q + 1] = B[q];
			B[q] = b;
			q--;
		}
	}
}

void vibor(int* C, int n)
{
	for (int q = 0; q < n; q++)
	{
		int b = C[0]; 
		for (int i = q + 1; i < n; i++)
		{
			if (C[q] > C[i])
			{
				b = C[q];
				C[q] = C[i];
				C[i] = b;
			}
		}
	}
}

void quicksrt(int* D, int first, int n)
{
	int mid, count;
	int f = first, l = n;
	mid = D[(f + l) / 2]; 
	do
	{
		while (D[f] < mid) f++;
		while (D[l] > mid) l--;
		if (f <= l) 
		{
			count = D[f];
			D[f] = D[l];
			D[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksrt(D, first, l);
	if (f < n) quicksrt(D, f, n);
}