#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
        double x; // ������� ��������
        double y; // ��������� ���������� ������
        double A; // �������� ��������� - ������������� ����� ������� ������
        double B; // �������� ��������� - ������������� ����� ������� ������

    cout << "x = ";
    cin >> x;

    // ��������� �����
    if (x <= -1) {
        y = exp(0.4 + x);
    }
    else if (x > -1 && x < 1) {
        y = 13.5 - 2 * x - (1 - sin(x) * sin(x));
    }
    else { // x >= 1
        y = cos(x) / (1 + sin(x) * sin(x));
    }

    cout << "1) y = " << y << endl;

    // ����� �����
    if (x <= -1) {
        y = exp(0.4 + x);
    }
    else if (x >= 1) {
        y = cos(x) / (1 + sin(x) * sin(x));
    }
    else { 
        y = 13.5 - 2 * x - (1 - sin(x) * sin(x));
    }

    cout << "2) y = " << y << endl;

    return 0;
}