#include <string>
#include <iostream>
#include <chrono>

using namespace std;
#define INT_MAX 32767// максимальный размер ключа
#define NUM 13

struct arr
{
	string str = "\0";
	int num = 0;
	arr* next = NULL;
};

int hash_f(string str, int* rand8)
{
	int sum = 0;
	for (int i = 0; i < str.length(); i++) sum += str[i];// из лабы деда
	return sum % NUM;
}
void output(arr* tab, int size)
{
	for (int i = 0; i < size; i++)// пока не выведем весь массив
	{
		arr* ptr = &tab[i];
		cout << "level #" << i << ":\n";
		do
		{
			if (ptr->str[0] == '\0')
			{
				cout << "Empty\n";
				break;
			}
			else
			{
				cout << "string: " << ptr->str << " number: " << ptr->num << endl;
			}
		} while (ptr = ptr->next);
	}
}
void dlt(arr* tab, int size, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);//вычисляем ключ элемента
	while (k > size - 1) k -= size;//уменьшаем ключ
	arr* ptr = &tab[k];
	if (ptr->num == num)//если элемент найден
	{
		if (ptr->next)
		{
			ptr->next = ptr->next->next;//меняяем указатель на следующий элемент от удалённого
			ptr->num = ptr->num;// записываем ключ
			ptr->str = ptr->str;//Фио
		}
		else
		{
			ptr->num = 0;
			ptr->str = '\0';
		}
		return;
	}
	if (ptr->num)//если список не пуст
	{
		arr* ptr_prev = new arr;
		while (ptr->next && ptr->next->num != num)
		{
			ptr_prev = ptr;
			ptr = ptr->next;
		}
		if (ptr->num == num)
		{
			ptr_prev->next = ptr->next;
			delete ptr;
			return;
		}
		//exit(1);
	}
	cout << "Элемента нет\n";
	return;
}
void input(arr* tab, int size, string str, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);//ищем ключ для элемента в хеш-функции
	while (k > size - 1) k -= size;// уменьшаем ключ,чтобы влез в размерность
	arr* ptr = &tab[k];
	if (!ptr->num)//если элемент пуст
	{
		ptr->next = NULL;//следующий элемент NULL
		ptr->str = str;//записываем ФИО
		ptr->num = num;// записываем ключ
	}
	else
	{
		while (ptr->next) ptr = ptr->next;//устанавливаем элемент в конце односвязного списка
		arr* p = new arr;
		p->next = NULL;//для следующего элемента p установили Null
		p->str = str;//ФИО
		p->num = num;//ключ
		ptr->next = p;// для ptr установили следующим элементом p
	}
}
void search(arr* tab, int size, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);
	while (k > size - 1) k -= size;//Уменьшение ключа ддо размера массива
	arr* ptr = &tab[k];
	if (ptr->num)
	{
		while (ptr->next && ptr->num != num)
		{
			ptr = ptr->next;
		}
		if (ptr->num == num)
		{
			cout << "ключ: " << ptr->num << " ФИО: " << ptr->str << endl;
			return;
		}
		cout << "error\n";
		exit(1);
	}
	cout << "Элемента нет\n";
	return;
}
void main()
{
	setlocale(LC_ALL, "ru");
	int size = 6;
	int clearMas[256] = { 0 };
	arr* mas = new arr[size];
	int choise;
	do
	{
		system("cls");
		cout << "1 - Вывод хеш-таблицы\n2 - Добавление элемента\n3 - Поиск элемента\n4 - Удаление\n0 - Выход\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			output(mas, size);
			break;
		}
		case 2:
		{
			string str;
			int num;
			cout << "Введите ФИО: ";
			cin.ignore();
			getline(cin, str);
			cout << "Введите номер телефона: ";
			cin >> num;
			if (0 < num < INT_MAX)
			{
				input(mas, size, str, num, clearMas);
			}
			else cout << "Некорректный номер\n";
			break;
		}
		case 3:
		{
			cout << "Введите ключ: ";
			int num;
			cin >> num;
			cin.ignore();
			auto start = chrono::high_resolution_clock::now();
			search(mas, size, num, clearMas);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float>duration = end - start;
			cout << "Расчетное время: " << duration.count() << " секунд" << endl;
			break;
		}
		case 4:
		{
			cout << "Введите ключ: ";
			int num;
			cin >> num;
			dlt(mas, size, num, clearMas);
		}
		default:
			break;
		}
		system("pause");
	} while (choise);
}