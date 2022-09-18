#include <iostream>
#include <set>

using namespace std;

void first();
void second();

int main()
{
	setlocale(LC_ALL, "rus");
	
	int selector;
	cout << "Выберите задачу:\n"
		<< "1. Первая задача\n"
		<< "2. Вторая задача\n"
		<< "3. Выход\n";
	cin >> selector;

	switch (selector)
	{
	case 1: 
		first();
		break;
	case 2:
		second();
		break;
	default:
		return 0;
		break;
	}
	
	return 0;
}

void first()
{
	int n;
	cout << "Введите число товаров N: ";
	cin >> n;

	int* firstArr = new int[n];

	cout << "Исходный порядок: ";
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		firstArr[i] = rand() % 100 + 1;
		cout << firstArr[i] << " ";
	}

	for(int i = 0; i < n; i++)
		for (int j = 0, temp; j < n - 1; j++)
		{
			if (firstArr[j] > firstArr[j + 1])
			{
				temp = firstArr[j];
				firstArr[j] = firstArr[j + 1];
				firstArr[j + 1] = temp;
			}
		}

	if (n % 2 == 0)
	{
		int* small = new int[n / 2];
		int* big = new int[n / 2];
		for (int i = 0; i < n / 2; i++)
			small[i] = firstArr[i];

		for (int i = n / 2, q = 0; i < n; i++, q++)
			big[q] = firstArr[i];

		for (int i = 0, q = 0, k = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				firstArr[i] = big[q];
				q++;
			}
			else
			{
				firstArr[i] = small[k];
				k++;
			}
		}

		delete[] small, big;
	}
	else
	{
		int* small = new int[n / 2];
		int* big = new int[n / 2 + 1];
		for (int i = 0; i < n / 2; i++)
			small[i] = firstArr[i];

		for (int i = n / 2, q = 0; i < n; i++, q++)
			big[q] = firstArr[i];

		for (int i = 0, q = 0, k = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				firstArr[i] = big[q];
				q++;
			}
			else
			{
				firstArr[i] = small[k];
				k++;
			}
		}
		
		delete[] small, big;
	}

	int sum = 0;
	cout << "\nВыгодный результат: ";
	for (int i = 0; i < n; i++)
	{
		cout << firstArr[i] << " ";
		i % 2 == 0 ? sum += firstArr[i] :sum = sum ;
	}
	cout << "\nМаксимальная сумма чека: " << sum << "\n";
	
	delete[] firstArr;

	main();
}

void second()
{
	int n;
	cout << "Введите число участников N: ";
	cin >> n;

	int* firstArr = new int[n];

	cout << "Исходный порядок: ";
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		firstArr[i] = rand() % 10 + 1;
		cout << firstArr[i] << " ";
	}

	set<int> S;
	set <int>::iterator it;

	for (int i = 0; i < n; i++)
	{
		S.insert(firstArr[i]);
	}

	int count = 0;
	int* secondArr = new int[S.size()];
	for (it = S.begin(); it != S.end(); ++it, count++)
	{
		secondArr[count] = *it;
	}

	int grade1 = secondArr[count - 1],
		grade2 = secondArr[count - 2],
		grade3 = secondArr[count - 3],
		sum = 0;

	for (int i = 0; i < n; i++)
	{
		if ((firstArr[i] == grade1) || (firstArr[i] == grade2) || (firstArr[i] == grade3))
			sum++;
	}

	cout << "\nКоличество призёров: " << sum << "\n";

	delete[] firstArr;

	main();
}