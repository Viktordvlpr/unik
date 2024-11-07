#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double x; // вхідний аргумент
    double a; // вхідний параметр
    double b; // вхідний параметр
    double c; // вхідний параметр
    double F; // результат обчислення виразу


    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "x = "; cin >> x;

    // скорочена форма
    if (x < 0 && b != 0) {
        F = (a * x * x - b * x * x);
    }
    else if (x > 0 && b == 0) {
        F = (x - a) / (x - c);
    }
    else {
        F = (x + 5) / (c * (x - 10));
    }
    cout << "1) F = " << F << endl;

    // повна форма
    if (x < 0 && b != 0) {
        F = (a * x * x - b * x * x);
    }
    else {
        if (x > 0 && b == 0) {
            F = (x - a) / (x - c);
        }
        else {
            F = (x + 5) / (c * (x - 10));
        }
    }

    cout << "2) F = " << F << endl;

    return 0;
}