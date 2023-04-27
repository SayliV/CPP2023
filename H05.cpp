#include <iostream> 
#include <cmath>
using namespace std;

float usain_run(float V, int N);// прототип функции
const int length_lap = 500; // длина круга 
const float presents = 0.95; // уменьшение на 5% 
const float velocity_m_per_seconds_40 = 11.11; // скорость при 40 км/ч 
const float velocity_m_per_seconds_35 = 9.72; // скорость при 35 км/ч 

int main() {
    setlocale(LC_ALL, "RUS");
    int N = 0; // количество кругов 
    cout << "Введите количество желаемых кругов (не больше 100): ";
    cin >> N;
    usain_run(velocity_m_per_seconds_40, N); // вызываем функцию для расчета времени забега 
    return 0;
}

// функция для расчета времени забега со скоростью 40 км/ч и дальнейшего расчёта при скорости 35 от того же времени
float usain_run(float V, int N) {
    cout << "Количество кругов при скорости 40км/ч " << endl;
    cout << "Номер круга   Скорость, км/ч   Время, с" << endl;
    float sum_time40 = 0; // счетчик времени 
    float speed = V; // начальная скорость 
    for (int i = 0; i < N; i++) { // цикл по количеству кругов 
        sum_time40 += length_lap / speed; // добавляем время прохождения круга 
        speed *= presents; // уменьшаем скорость на 5% после каждого круга 
        cout <<"\t" << i + 1 << "\t" << speed * 3.6 << "\t" "\t" << sum_time40 << endl; // выводим номер круга, скорость и затраченное время 
    }
    float sum_time_35 = 0; //создал переменную значения суммы времени для скорости 35км/ч
    int Laps = 1;
    float speed35 = velocity_m_per_seconds_35;
    cout << "Количество кругов при скорости 35км/ч и уже известном времени" << endl;
    cout << "Номер круга   Скорость, км/ч   Время, с" << endl;

    for (int i = 0; sum_time40 > sum_time_35; i++) {
        sum_time_35 = length_lap / speed35;
        speed35 *= presents;
        sum_time_35 = sum_time_35 + sum_time_35;
        cout << "\t" << Laps << "\t" << speed35 * 3.6 << "\t" "\t" << sum_time_35 << endl;
        Laps += 1;
    }
    return Laps;
}
