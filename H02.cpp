#include <iostream>
using namespace std;
class Complex {
public:
    double real, imag;
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    void show() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
    // перегружаем значения оператора "+"
    // const указывает, что метод не изменяет состояние текущего объекта класса Complex.
    Complex operator+(const Complex& c) {//вызываем значение комплекса 1 и передаём в него значение комплекса с2 по нижеописанным правилам перегрузки функций
        return Complex(real + c.real, imag + c.imag);
    }
    // перегружаем значения оператора "-"
    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }
    // перегружаем значения оператора "*"
    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    // перегружаем значения оператора "/"
    Complex operator/(const Complex& c) {
        double denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }
};

int main() {
    Complex c1(2, 4); // передаём значение в класс
    Complex c2(3, 1);// передаём значение в класс 

    Complex c3 = c1 + c2;
    c3.show();

    Complex c4 = c1 - c2;
    c4.show();

    Complex c5 = c1 * c2;
    c5.show();

    Complex c6 = c1 / c2;
    c6.show();

    return 0;
}

