#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void PrintTableHead() {
    cout << string(74, '-') << endl;
    cout << "|         x         ";
    cout << "|   e^(-x^2)(mine)  ";
    cout << "|  e^(-x^2))(cmath) ";
    cout << "| iterations |\n";
    cout << string(74, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIters) {
    n = 1;
    double nth_term = 1;
    double function = nth_term;
    while (abs(nth_term) > eps) {
        nth_term = pow((-1), n) * ((pow(x, n * 2)) / (tgamma(n + 1)));
        function += nth_term;
        n++;
        if (n > kMaxIters) break;
    }
    return function;
}

void PrintTableRow(double x, double func, int n, const int kMaxIters) {
    cout << "|" << setw(15) << x << setw(5) << "|" << setw(15);
    if (n <= kMaxIters)
        cout << func << setw(5) << "|";
    else
        cout << " limit is exceeded |";
    cout << setw(15) << exp(-pow(x, 2)) << setw(5) << "|";
    cout << setw(7) << n << setw(7) << "|\n";
}

int main() {
    const int kMaxIters = 1000;

    double xn, xk, dx, eps;
    cout << "use |x| < 3 for better results\n";
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
        return 1;
    }
    else if (eps <= 0) {
        cout << "\nInvalid eps. Must be: eps > 0.\n";
        return 1;
    }
    else if (xn > xk) {
        cout << "\nInvalid xk. Must be: xk >= xn.\n";
        return 1;
    }
    
    cout << fixed;
    cout.precision(9);

    PrintTableHead();

    for (; xn <= xk; xn += dx) {
        int n;
        double func = ComputeSeries(xn, eps, n, kMaxIters);
        PrintTableRow(xn, func, n, kMaxIters);
    }
    cout << string(74, '-');

    return 0;
}