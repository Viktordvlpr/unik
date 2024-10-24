#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");
    double R1, R2, x_poch, x_end, dx;

    cout << "R1: "; cin >> R1;
    cout << "R2: "; cin >> R2;
    cout << "x start"; cin >> x_poch;
    cout << "x end"; cin >> x_end;
    cout << "dx"; cin >> dx;

    cout << setw(10) << "x" << setw(10) << "y" << endl;
    cout << "-------------------" << endl;

    for (double x = x_poch; x <= x_end; x += dx) {
        double y = 0;


        if (x >= -2 * R1 - R1 && x <= 0) {
            y = sqrt(R1 * R1 - pow(x + R1, 2));
        }

        else if (x >= 0 && x <= 2 * R2) {
            y = -R2 + sqrt(R2 * R2 - pow(x - R2, 2));
        }
        else if (x > 2 * R2 && x <= 6) {
            y = -R2;
        }

        cout << setw(10) << fixed << setprecision(4) << x
            << setw(10) << fixed << setprecision(4) << y << endl;
    }

    return 0;
}