#include "func.h"

int main() {
	int const kArraySize = 10;
	double array[kArraySize];

	srand((unsigned)time(NULL));

	//generation array 
	int index_max = 0;
	array[0] = int(pow(-1, rand() % 2))*(rand() % 10);
	for (int i = 1; i < kArraySize; i++) {
		array[i] = int(pow(-1, rand() % 2))*(rand() % 10); //[-9..9]
		if (abs(array[i]) > abs(array[index_max])) {
			index_max = i;
		}
	}

	cout << "Starting Array :" << endl;
	PrintArray(array, kArraySize);

	cout << "\nIndex of max modulo element -> ";
	cout << IndexOfMaxModuloElement(array, kArraySize) << endl;

	cout << "\nSum max after modulo element = ";
	if (kArraySize - index_max == 1) {
		cout << "Error! Max modulo element is last in array!\n\n";
	}
	else {
		cout << SumAfterSubzeroElement(array, kArraySize, index_max);
		cout << endl << endl;
	}

	cout << "Enter interval [a;b] (e.g. \"-3 4\" for [-3;4] interval ) -> ";
	double a, b;
	cin >> a >> b;
	if ((a == b) || (a > b))
		cout << "Invalid interval(must be a<b)!\n\n";
	else {
		cout << endl << CutArray(array, a, b, kArraySize) << " elements in ";
		cout << "[" << a << "," << b << "] interval.\n\n";
	}

	return 0;
}