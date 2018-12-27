#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

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

    cout << string(74, '-') << endl;
    cout << "|         x         ";
    cout << "|   e^(-x^2)(mine)  ";
    cout << "|  e^(-x^2))(cmath) ";
    cout << "| iterations |\n";
    cout << string(74, '-') << endl;

    cout << fixed;
    cout.precision(9);

    for (; xn <= xk; xn += dx) {
        int n = 1;
        double nth_term = 1;
        double function = nth_term;
        while (abs(nth_term) > eps) {
            nth_term = pow((-1), n) * ((pow(xn, n * 2)) / (tgamma(n + 1)));
            function += nth_term;
            n++;
            if (n > kMaxIters) break;
        }

        cout << "|" << setw(15) << xn << setw(5) << "|" << setw(15);
        if (n <= kMaxIters)
            cout << function << setw(5) << "|";
        else
            cout << " limit is exceeded |";
        cout << setw(15) << exp(-pow(xn, 2)) << setw(5) << "|";
        cout << setw(7) << n << setw(7) << "|\n";

    }
    cout << string(74, '-');

    return 0;
}