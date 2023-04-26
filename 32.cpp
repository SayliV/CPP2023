#include <iostream>
#include <cstring>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    char str[100];
    cout << "Введите строку: ";
    cin >> str;

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        str[i]++;
    }

    cout << "Получившееся строка: " << str << std::endl;

    return 0;
}