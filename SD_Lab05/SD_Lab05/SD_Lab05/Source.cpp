#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>

#define rndbracket_open ('(')
#define rndbracket_close (')')

#define sqrbracket_open ('[')
#define sqrbracket_close (']')

#define fgrbracket_open ('{')
#define fgrbracket_close ('}')

using namespace std;

bool balanced(const string s) {

    stack<char> stack;

    for (char c : s) {
        switch (c) {

        case rndbracket_open: stack.push(rndbracket_close); break;
        case sqrbracket_open: stack.push(sqrbracket_close); break;
        case fgrbracket_open: stack.push(fgrbracket_close); break;

        case rndbracket_close:
        case sqrbracket_close:
        case fgrbracket_close:
            if (stack.empty() || stack.top() != c) {
                return false;
            }
            stack.pop();
            break;
        default:
            break;
        }
    }
    return stack.empty();
}

void test(const string s) {
    cout << (balanced(s) ? "Скобки расставлены верно" : "Скобки расставлены не верно") << '\n';
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите строку: ";
    string vvod;
    cin >> vvod;

    test(vvod);
}