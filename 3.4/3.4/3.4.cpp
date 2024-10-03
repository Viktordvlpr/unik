#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double x, y, R;
    cout << "координати точки x, Y" << endl;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "радіус R: "; cin >> R;


    bool inUpperCircle = (x * x + (y - R) * (y - R) <= R * R) && (y >= -x);

    bool inLowerCircle = (x * x + (y + R) * (y + R) <= R * R) && (y <= -x);

    if (inUpperCircle || inLowerCircle) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}