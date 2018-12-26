#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b;
	cout << "Enter alpha and beta -> ";
	cin >> a >> b;

	double z1 = (sin(a) + cos(2 * b - a)) / (cos(a) - sin(2 * b - a));
	double z2 = (1 + sin(2 * b)) / (cos(2 * b));
	cout << "\nz1= " << z1 << "\nz2= " << z2 << endl;

	return 0;
}