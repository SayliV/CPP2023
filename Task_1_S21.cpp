#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int A, B, c;
    cout << "Введите число A:";
        cin >> A;
    cout << "Введите число B:";
        cin >> B;
    ofstream fout("check.txt"); // создаём объект класса ofstream для записи и связываем его с файлом check.txt
   
    if (A>B)
    {   cout << "Введите корректо числа A и B" << '\n';
        cout << "Введите число A:";
        cin >> A;
        cout << "Введите число B:";
        cin >> B;        
    }
    else if(B>A)
    {
        return 0;
    }

    for (A; B >= A; A++)
    {   c = A * 3;
        fout << c << '\n';
        cout << c << '\n';
    }

    fout.close(); // закрываем файл
    system("pause");
    return 0;
}
