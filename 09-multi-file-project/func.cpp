#include "func.h"

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