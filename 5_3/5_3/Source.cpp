#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(const double t);

int main() {
    double tp, tk, m;
    int n;
    cout << "tp = ";
    cin >> tp;
    cout << "tk = ";
    cin >> tk;
    cout << "n = ";
    cin >> n;
    cout << fixed;
    cout << "--------------------------------------------------------------" << endl;
    cout << "|" << setw(5) << "t" << "   |"
        << setw(25) << "m" << "                          |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    double t = tp;
    double dt = (tk - tp) / n;
    while (t <= tk) {
        m = f(1 + 2 * t) + f(f(1) + 2 * f(2 * t)) * f(f(1) + 2 * f(2 * t));
        cout << "|" << setw(7) << setprecision(2) << t
            << " |" << setw(50) << setprecision(3) << m
            << " |" << endl;
        t += dt;
    }
    cout << "--------------------------------------------------------------" << endl;
    return 0;
}

double f(const double x) {
    if (abs(x) >= 1) {
        return (sin(x) * sin(x) + sin(x * x)) / (1 + cos(x) * cos(x));
    }
    else {
        double S = 0;

        double term = x;
        for (int n = 0; n <= 6; n++)
        {
            term *= (x * x * x * x) / ((4 * n) * (4 * n + 1));
            S += term;
        }
        return 1. / (1 + x * x) * S;
    }
}