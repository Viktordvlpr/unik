#include <iostream>
#include <iomanip>  
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    double a, b, c, Xstart, Xend, dX;


    cout << "¬вед≥ть a: "; cin >> a;
    cout << "¬вед≥ть b: "; cin >> b;
    cout << "¬вед≥ть c: "; cin >> c;
    cout << "¬вед≥ть Xstart: "; cin >> Xstart;
    cout << "¬вед≥ть Xend: "; cin >> Xend;
    cout << "¬вед≥ть dX: "; cin >> dX;


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