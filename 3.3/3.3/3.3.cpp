#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x, y, R;
	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;

	if (x <= R) {
		y = R - 3;
	}
	else if (0 < x && x <= R) {
		y = R + sqrt(R * R - x * x);
	}
	else if (R <= x && x <= 6) {
		y = R - ((R * x) / 6);
	}
	else if (x > 6) {
		y = x + 6;
	}
	cout << endl;
	cout << "y = " << y << endl;
	cin.get();
	return 0;
}