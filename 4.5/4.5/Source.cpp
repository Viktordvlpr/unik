#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool check_hit(double x, double y, double R) {

    if (x >= 0 && y >= 0 && (x * x + (y - R) * (y - R)) <= R * R) {
        return true;
    }
    if (x >= 0 && y <= 0 && (x * x + y * y) <= R * R) {
        return true;
    }
    return false;
}

int main() {
    double x, y, R;
    cout << "R: ";
    cin >> R;

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 10; i++) {
        cout << "x: "; cin >> x;
        cout << "y: "; cin >> y;

        if (check_hit(x, y, R)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    cout << endl << fixed;

    // рандомні попадання
    for (int i = 0; i < 10; i++) {
        x = (2.0 * R * rand() / RAND_MAX) - R;
        y = (2.0 * R * rand() / RAND_MAX) - R;

        if (check_hit(x, y, R)) {
            cout << setw(8) << setprecision(4) << x << " "
                << setw(8) << setprecision(4) << y << " " << "Yes" << endl;
        }
        else {
            cout << setw(8) << setprecision(4) << x << " "
                << setw(8) << setprecision(4) << y << " " << "No" << endl;
        }
    }

    return 0;
}
