#include <iostream>
#include <cmath>
#include <locale>

using namespace std;



int main() {
    setlocale(LC_ALL, "RU");

    double a;
    double z1;
    double z2;

    cout << "a = ";
    cin >> a;

    if (a <= 0) {
        cout << "������� �  �� ����� �� ���� 0" << endl;
        return 1;
    }

    if (a <= sqrt(2)) {
        cout << "������� � �� ���� ����� ��  sqrt(2)" << endl;
        return 1;
    }

    if (a == sqrt(2 * a)) {
        cout << "������� ������ �� 0 z1" << endl;
        return 1;
    }

    z1 = ((a + 2) / sqrt(2 * a) - a / sqrt(2 * a + 2) + 2 / (a - sqrt(2 * a))) * (sqrt(a - sqrt(2)) / (a + 2));
    z2 = 1 / (sqrt(a) + sqrt(2));

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    return 0;
}