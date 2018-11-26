#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b;
	double z1, z2;
	cout << "enter a:";
	cin >> a;
	cout << "enter b:";
	cin >> b;
	z1 = (sin(a) + cos(2 * b - a)) / (cos(a) - sin(2 * b - a));
	z2 = (1 + sin(2 * b)) / (cos(2 * b));
		cout << "z1 = " << z1 << "\nz2 = " << z2;
	return 0;
}
