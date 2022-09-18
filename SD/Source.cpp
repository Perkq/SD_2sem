#include <iostream>
#include <ctime>

using namespace std;

int rec(int i, int n, int* k, clock_t tbegin, clock_t tend, double timeFor);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	clock_t tbegin, tend;

	cout << "Введите N\n";
	cin >> n;

	int *k = new int[n];
	k[0] = 0;
	k[1] = 1;

	cout << k[0] << " " << k[1] << " ";
	tbegin = clock();
	for (int i = 2; i < n; i++)
	{
		k[i] = k[i - 1] + k[i - 2];
		cout << k[i] << " ";
	}
	tend = clock();
	double timeFor = (double)(tend - tbegin);
	cout << "\nВремя работы цикла: " << timeFor;

	cout << "\nСпособ рекурсией:\n";
	cout << *(k) << " " << *(k + 1) << " ";
	tbegin = clock();
	rec(2, n, k, tbegin, 0, timeFor);
}

int rec(int i, int n, int* k, clock_t tbegin, clock_t tend, double timeFor)
{
	if (i < n)
	{
		*(k + i) = *(k + i - 2) + *(k + i - 1) ;
		cout << *(k + i) << " ";
		i++;
			rec(i, n, k, tbegin, 0, timeFor);
	}
	else
	{
		tend = clock();
		double timeRec = (double)(tend - tbegin);
		cout << "\nВремя работы через рекурсию: " << timeRec;
		cout << "\nРазница в скорости выполнения(цикл - рекурсия): " << timeFor - timeRec;
		delete[] k;
		return 0;
	}
}