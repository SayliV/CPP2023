﻿#include <iostream>
using namespace std;

void print(int num) {
    cout << num << std::endl;
}

void print(float num) {
    cout << num << std::endl;
}

void print(char c) {
    cout << c << std::endl;
}

void print(int num1, int num2) {
    cout << num1 << ", " << num2 << std::endl;
}

int main() {
    print(10), print(3.14f), print('q'), print(5, 7);
    return 0;
}