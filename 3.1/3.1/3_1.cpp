#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
        double x; // вхідний параметр
        double y; // результат обчислення виразу
        double A; // проміжний результат - функціонально стала частина виразу
        double B; // проміжний результат - функціонально змінна частина виразу

    cout << "x = ";
    cin >> x;

    // скорочена форма
    if (x <= -1) {
        y = exp(0.4 + x);
    }
    else if (x > -1 && x < 1) {
        y = 13.5 - 2 * x - (1 - sin(x) * sin(x));
    }
    else { // x >= 1
        y = cos(x) / (1 + sin(x) * sin(x));
    }

    cout << "1) y = " << y << endl;

    // повна форма
    if (x <= -1) {
        y = exp(0.4 + x);
    }
    else if (x >= 1) {
        y = cos(x) / (1 + sin(x) * sin(x));
    }
    else { 
        y = 13.5 - 2 * x - (1 - sin(x) * sin(x));
    }

    cout << "2) y = " << y << endl;

    return 0;
}