#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int i, k;
    double P, E;
    P = 1;
    i = 1;

    while (i <= 3) {
        k = 1;
        while (k <= 4 - i) {
            E = (sin(i * k * k) + cos(k * i * i)) / (k * k + i * i);
            P *= E;
            k++;
        }
        i++;
    }
    cout << "P = " << P << endl;


    P = 1;
    i = 1;
    do {
        k = 1;
        do {
            E = (sin(i * k * k) + cos(k * i * i)) / (k * k + i * i);
            P *= E;
            k++;
        } while (k <= 4 - i);
        i++;
    } while (i <= 3);
    cout << "P = " << P << endl;


    P = 1;
    for (i = 1; i <= 3; i++) {
        for (k = 1; k <= 4 - i; k++) {
            E = (sin(i * k * k) + cos(k * i * i)) / (k * k + i * i);
            P *= E;
        }
    }
    cout << "P = " << P << endl;


    P = 1;
    for (i = 3; i >= 1; i--) {
        for (k = 4 - i; k >= 1; k--) {
            E = (sin(i * k * k) + cos(k * i * i)) / (k * k + i * i);
            P *= E;
        }
    }
    cout << "P = " << P << endl;

    return 0;
}