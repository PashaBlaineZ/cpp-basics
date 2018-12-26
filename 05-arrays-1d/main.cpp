#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

void PrintArray(double array[], int size) {
	cout << string(61, '-') << endl;
	cout << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(2) << "[" << i << "]" << setw(2) << "|";
	}

	cout << "<- Index";
	cout << endl << string(61, '-') << endl << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(3) << array[i] << setw(3) << "|";
	}

	cout << "<- array[i]";
	cout << endl;
	cout << string(61, '-') << endl;
	cout << endl;
}

unsigned int IndexOfMaxModuloElement(double a[], int const size) {
	unsigned int index_max = 0;
	double max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (abs(max) < abs(a[i])) {
			max = a[i];
			index_max = i;
		}
	}
	return index_max;
}

double SumAfterSubzeroElement(double a[], int const size, int max) {
	double sum = 0;
	for (int i = max + 1; i < size; i++)
	{
		sum += a[i];
	}
	return sum;
}

bool InInterval(double x, double a, double b) {
	if (x >= a && x <= b)
		return true;
	else
		return false;
}

int CutArray(double ar[], double a, double b, int const size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (InInterval(ar[i], a, b)) {
			sum++;
		}
	}
	return sum;
}

void SortArray(double a[], int const size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (abs(a[j]) > abs(a[j + 1]))
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

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