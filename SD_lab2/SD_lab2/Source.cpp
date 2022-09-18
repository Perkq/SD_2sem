#include<iostream>

using namespace std;

void bin();
unsigned short counter = 1;
float  N, x, expected, RBorder, LBorder = 0;
int main()
{
    setlocale(0, "");
    cout << "Введите диапазон: "; cin >> N;
    cout << "Expected: "; cin >> expected;
    RBorder = N + 1;
    x = N / 2;
    bin();


    return 0;
}

void bin()
{
    cout << x << endl;
    int choice;
    cout << "1. Мало\n2.Много\n3.Угадал\n";
    cin >> choice;
    if (x < expected) choice = 1;
    else if (x > expected) choice = 2;
    else if (x == expected) choice = 3;

    switch (choice)
    {
    case 1:
    {
        LBorder = x;
        x = floor((RBorder + LBorder) / 2);
        if (x > RBorder) x = RBorder - 1;
        counter++;
        bin();

        break;

    }
    case 2:
    {
        RBorder = x;
        x = floor((RBorder + LBorder) / 2);

        if (x < LBorder) x = LBorder + 1;
        counter++;
        bin();
        break;
    }
    case 3: {
        cout << "Число: " << x << endl << "Итераций: " << counter;
        break;
    }

    default:
        break;
    }

}