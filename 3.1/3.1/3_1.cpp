#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, A, B;
    cout << "x = ";  cin >> x;

    A = 2 * abs(x - 5);

    // спосіб 1: розгалуження в скороченій формі
    if (x < -1) {
        B = pow(sin(x), 2) / (1 + abs(cos(x)));
    }
    if (x >= -1 && x <= 1) {
        B = pow(cos(x), 2) * (1 / abs(x + 2));
    }
    if (x > 1) {
        B = log(abs(x + 2));
    }
    y = A - B;

    cout << endl;
    cout << "1)y = " << y << endl;

    // спосіб 2: розгалуження в повній формі
    if (x < -1) {
        B = pow(sin(x), 2) / (1 + abs(cos(x)));
    }
    else if (x >= -1 && x <= 1) {
        B = pow(cos(x), 2) * (1 / abs(x + 2));
    }
    else if (x > 1) {
        B = log(abs(x + 2));
    }
    y = A - B;

    cout << "2)y = " << y << endl;
    return 0;
}
