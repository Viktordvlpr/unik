#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;  // вхідний аргумент
    double R1, R2;  // вхідні параметри
    double y;  // результат обчислення виразу

    cout << "R1 = ";
    cin >> R1;
    cout << "R2 = ";
    cin >> R2;
    cout << "x = ";
    cin >> x;


    if (x <= -2 * R1)
        y = -1;  // Пряма лінія на лівій стороні графіка
    else if (-2 * R1 < x && x <= 0)
        y = ((R1 - (-1)) / (0 - (-2 * R1))) * (x + 2 * R1) - 1;  // Пряма від -2R1 до 0
    else if (0 < x && x <= R1)
        y = R1 + sqrt(R1 * R1 - x * x);  // Верхня дуга кола радіуса R1
    else if (R1 < x && x <= 2 * R2)
        y = -R2 - sqrt(R2 * R2 - (x - R2) * (x - R2));  // Нижня дуга кола радіуса R2
    else if (2 * R2 < x && x <= 6)
        y = -R2;  // Пряма після нижньої дуги
    else
        y = -R2;  

    cout << endl;
    cout << "y = " << y << endl;

    return 0;
}
