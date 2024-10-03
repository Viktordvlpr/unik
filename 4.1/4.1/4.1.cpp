#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k, i;
    double S;

    cout << "k = "; cin >> k;

    //while
    S = 0;
    i = k;
    while (i <= 15)
    {
        S += cos(1.0 * i) / (1 + pow(sin(1.0 * i), 2));
        i++;
    }
    cout <<  S << endl;

    //do-while
    S = 0;
    i = k;
    do {
        S += cos(1.0 * i) / (1 + pow(sin(1.0 * i), 2));
        i++;
    } while (i <= 15);
    cout <<  S << endl;

    // for++
    S = 0;
    for (i = k; i <= 15; i++)
    {
        S += cos(1.0 * i) / (1 + pow(sin(1.0 * i), 2));
    }
    cout << S << endl;

    // for-
    S = 0;
    for (i = 15; i >= k; i--)
    {
        S += cos(1.0 * i) / (1 + pow(sin(1.0 * i), 2));
    }
    cout << S << endl;

    return 0;
}
