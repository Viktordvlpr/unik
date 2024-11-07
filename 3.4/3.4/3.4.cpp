#include <iostream> 
#include <cmath> 
using namespace std;
int main()
{
	double x;
	double y;
	double R;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "R = "; cin >> R;
	if (((x >= 0 && y >= 0 && pow(x - R, 2) + pow(y - R, 2) <= pow(R, 2) && y <= x)) ||
		(x <= 0 && y <= 0 && pow(x + R, 2) + pow(y + R, 2) <= pow(R, 2) && y >= x))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cin.get();
	return 0;
}