#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double x; // ������� ��������
    double a; // ������� ��������
    double b; // ������� ��������
    double c; // ������� ��������
    double F; // ��������� ���������� ������


    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "x = "; cin >> x;

    // ��������� �����
    if (x < 0 && b != 0) {
        F = (a * x * x - b * x * x);
    }
    else if (x > 0 && b == 0) {
        F = (x - a) / (x - c);
    }
    else {
        F = (x + 5) / (c * (x - 10));
    }
    cout << "1) F = " << F << endl;

    // ����� �����
    if (x < 0 && b != 0) {
        F = (a * x * x - b * x * x);
    }
    else {
        if (x > 0 && b == 0) {
            F = (x - a) / (x - c);
        }
        else {
            F = (x + 5) / (c * (x - 10));
        }
    }

    cout << "2) F = " << F << endl;

    return 0;
}