#include <iostream>
#include <cmath>
using namespace std;

double S0(const int k) {
    double s = 0;
    for (int i = k; i <= 15; i++)
        s += cos(i) / (1 + sin(i) * sin(i));
    return s;
}

double S1(const double i, const int k) {
    if (i > 15)
        return 0;
    else
        return cos(i) / (1 + sin(i) * sin(i)) + S1(i + 1, k);
}

double S2(const int i, const int k) {
    if (i < k)
        return 0;
    else
        return cos(i) / (1 + sin(i) * sin(i)) + S2(i - 1, k);
}

double S3(const int i, double t) {
    t = t + cos(i) / (1 + sin(i) * sin(i));
    if (i >= 15)
        return t;
    else
        return S3(i + 1, t);
}

double S4(const int i, const int k, double t) {
    t = t + cos(i) / (1 + sin(i) * sin(i));
    if (i <= k)
        return t;
    else
        return S4(i - 1, k, t);
}

int main() {
    int k;
    cout << "k = ";
    cin >> k;

    cout << "(iter)--------S0 = " << S0(k) << endl;
    cout << "(rec up ++)---S1 = " << S1(k, k) << endl;
    cout << "(rec up --)---S2 = " << S2(15, k) << endl;
    cout << "(rec down ++)-S3 = " << S3(k, 0) << endl;
    cout << "(rec down --)-S4 = " << S4(15, k, 0) << endl;

    return 0;
}
