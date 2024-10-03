#include <iostream>
#include <iomanip>  
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    double a, b, c, Xstart, Xend, dX;


    cout << "������ a: "; cin >> a;
    cout << "������ b: "; cin >> b;
    cout << "������ c: "; cin >> c;
    cout << "������ Xstart: "; cin >> Xstart;
    cout << "������ Xend: "; cin >> Xend;
    cout << "������ dX: "; cin >> dX;


    cout << setw(10) << "x" << setw(20) << "F(x)" << endl;
    cout << "-------------------------------" << endl;


    for (double x = Xstart; x <= Xend; x += dX) {
        double F;


        if (x < 0 && b != 0) {
            F = a * x * x - b * x * x;
        }
        else if (x > 0 && b == 0) {
            F = (x - a) / (x - c);
        }
        else {
            F = (x + 5) / (c * (x - 10));
        }


        cout << setw(10) << x << setw(20) << F << endl;
    }

    return 0;
}