#include <iostream>
#include <cmath>  
using namespace std;

int main() {
    double P, numerator, denominator;
    int i, k;

    P = 1.0;
    i = 1;
    while (i <= 3) {
        k = 1;
        while (k <= 4 - i) {
            numerator = pow(sin(i * k), 2) + pow(cos(i * k), 2);
            denominator = pow(k, 2) + pow(i, 2);
            P *= numerator / denominator;
            k++;
        }
        i++;
    }
    cout << "while" << endl << P << endl;


    P = 1.0;
    i = 1;
    do {
        k = 1;
        do {
            numerator = pow(sin(i * k), 2) + pow(cos(i * k), 2);
            denominator = pow(k, 2) + pow(i, 2);
            P *= numerator / denominator;
            k++;
        } while (k <= 4 - i);
        i++;
    } while (i <= 3);
    cout << "do-while" << endl << P << endl;


    P = 1.0;
    for (i = 1; i <= 3; i++) {
        for (k = 1; k <= 4 - i; k++) {
            numerator = pow(sin(i * k), 2) + pow(cos(i * k), 2);
            denominator = pow(k, 2) + pow(i, 2);
            P *= numerator / denominator;
        }
    }
    cout << "for n++" << endl << P << endl;


    P = 1.0;
    for (i = 3; i >= 1; i--) {
        for (k = 4 - i; k >= 1; k--) {
            numerator = pow(sin(i * k), 2) + pow(cos(i * k), 2);
            denominator = pow(k, 2) + pow(i, 2);
            P *= numerator / denominator;
        }
    }
    cout << "n--" << endl << P << endl;

    return 0;
}