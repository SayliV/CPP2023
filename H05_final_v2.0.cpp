#include <iostream>
using namespace std;

void usain_run(float&, float& , float V, int N );// прототип функции
const int length_lap = 500; // длина круга
const float presents = 0.95; // уменьшение на 5%
const float velocity_m_per_seconds_40 = 11.11; // скорость при 40 км/ч
const float velocity_m_per_seconds_35 = 9.72; // скорость при 35 км/ч

int main() {
    setlocale(LC_ALL, "RUS");
    int N = 0; // количество кругов
    float sum_time=0, velocity_40=0;
    cout << "Введите количество желаемых кругов (не больше 100): ";
    cin >> N;
    cout << "Количество кругов при скорости 40км/ч " << endl;
    cout << "Номер круга   Скорость, км/ч   Время, с" << endl;
    usain_run (sum_time, velocity_40, velocity_m_per_seconds_40, N);
    cout << "Нажмите любую кнопку чтобы увидеть соклько пробежит усейн за то же время ос скоростью 35км/ч" << endl;//проверка что ссылка работает
    system("pause");
    float sum_time2 = 0;
    float velocity_35 = 0;
    int N_35 = 1;    
    while ( sum_time > sum_time2) {
        system("cls"); //делаю для того чтобы очистить командную строку от предыдущих попыток подсчёта
        sum_time2 = 0;
        N_35++;
        usain_run(sum_time2, velocity_35, velocity_m_per_seconds_35, N_35);
    }    
    cout << "Усейн пробежит количство кругов со скоростью 35км/ч:" << " ";
    cout << N_35 - 1 << " " << " и часть " << N_35 << " " << "круга" << endl;
    cout << "Время которое Усейн потратил на то чтоыб пробежать "<<N << " кругов со скоростью 40км/ч:" << endl;
    cout << sum_time<<endl;       
    return 0;
}

// функция для расчета времени забега со скоростью 40 км/ч и дальнейшего расчёта при скорости 35 от того же времени
void usain_run(float& sum_time, float& velocity_per_round, float V, int N) {                    
float velocity = V; // начальная скорость
velocity_per_round = velocity;
    for (int i = 0; i < N; i++) { // цикл по количеству кругов
        sum_time += length_lap / velocity_per_round; // добавляем время прохождения круга            
        if (velocity_per_round*3.6 < 4) { break; } //условие на скорость больше 4 км/ч
        cout << "\t" << i + 1 << "\t" << velocity_per_round * 3.6 << "\t" "\t" << sum_time << endl; // выводим номер круга, скорость и затраченное время
        velocity_per_round *= presents; // уменьшаем скорость на 5% после каждого круга
    }        
}