#include <iostream>
#include <cmath>
using namespace std;
double g(const double x, const double y);
int main()
{
	double r, s;
	cout << "r = "; cin >> r;
	cout << "s = "; cin >> s;
	double T = (g(r, s * s + 1) * g(r, s * s + 1) + g(1, r * r + s)) / (1 + g(1, r * s) * g(1, r * s));
	cout << "T = " << T << endl;
	return 0;
}
double g(const double x, const double y)
{
	return ((sin(x) * sin(x) + cos(x) * cos(x)) / (1 + fabs(x * y)));
}




