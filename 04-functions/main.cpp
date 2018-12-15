#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void PrintTableHead() {
	cout << string(74, '-') << endl;
	cout << "|         x         ";
	cout << "|   arth(xn)(mine)  ";
	cout << "|  arth(xn)(cmath)  ";
	cout << "| iterations |\n";
	cout << string(74, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIters) {
	n = 1;
	double nth_term = 1;
	double my_f = 1;
	while (abs(nth_term) > eps) {
		nth_term = pow((-1), n) * ((pow(x, n * 2)) / (tgamma(n + 1)));
		my_f += nth_term;
		n++;
		if (n > kMaxIters) break;
	}
	return my_f;
}

void PrintTableRow(double x, double func, int n, const int kMaxIters) {
	const double kE = 2.71828182845904523536;
	cout << "|" << setw(13) << x << setw(7) << "|" << setw(14);
	if (n <= kMaxIters)
		cout << func << setw(6) << "|";
	else
		cout << " limit is exceeded |";
	cout << setw(14) << pow(kE, -pow(x, 2)) << setw(6) << "|";
	cout << setw(7) << n << setw(7) << "|\n";
}

int main() {
	const int kMaxIters = 100;

	double xn, xk, dx, eps;
	cout << "Enter xn -> ";
	cin >> xn;
	cout << "Enter xk (xk >= xn) -> ";
	cin >> xk;
	cout << "Enter dx (dx > 0) -> ";
	cin >> dx;
	cout << "Enter eps (eps > 0) -> ";
	cin >> eps;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0) {
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		PrintTableHead();

		cout << fixed;
		cout.precision(6);

		for (; xn <= xk; xn += dx) {
			int n;
			double my_f = ComputeSeries(xn, eps, n, kMaxIters);
			PrintTableRow(xn, my_f, n, kMaxIters);
		}
		cout << string(74, '-');
	}

	return 0;
}