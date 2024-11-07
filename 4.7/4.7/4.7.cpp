#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a = 0, S = 0;
    int n = 0;


    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "   |"
        << setw(10) << "ln(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    x = xp;

    while (x <= xk)
    {
        if (x <= 0 || x > 2)
        {
            cout << "Error: x must be in the range (0, 2]" << endl;
            break;
        }

        n = 0;
        a = x - 1;
        S = a;
        do {
            n++;
            double R = -1.0 * (x - 1) * n / (n + 1);
            a *= R;
            S += a;
        } while (fabs(a) >= eps);


        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << log(x) << " |"
            << setw(10) << setprecision(5) << S << " |"
            << setw(5) << n << " |" << endl;

        x += dx;
    }

    cout << "-----------------------------------------" << endl;
    return 0;
}