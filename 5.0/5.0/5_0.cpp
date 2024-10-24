// Lab 5_0
#include <iostream>
#include <cmath>
using namespace std;

double g(const double x, const double y);

int main() {
    double r, s;
    cout << "r = ";
    cin >> r;
    cout << "s = ";
    cin >> s;

    double result = (pow(g(r, s * s + 1), 2) + g(1, r * r + s)) / (1 + pow(g(1, r * s), 2));
    cout << "result = " << result << endl;

    return 0;
}

double g(const double x, const double y) {
    return (pow(sin(x), 2) + pow(cos(y), 2)) / (1 + abs(x * y));
}
