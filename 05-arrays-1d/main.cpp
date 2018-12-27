#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void PrintArray(double* arr, const int size);
int CountElementsInRange(double* arr, const int size, double a, double b);
int FindMaxId(double* arr, const int size);
double SumElements(double* arr, const int size, int begin);
void SortArray(double* arr, const int size);

int main() {
    int const kArraySize = 10;
    double arr[kArraySize] = { 0, 1, .2, 3, 0, .5, -6, .1, .5, .3 };

    cout << "Starting array:\n";
    PrintArray(arr, kArraySize);
    cout << endl;

    double a, b;
    cout << "\nEnter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;
    cout << "Number of elements in [" << a << ", " << b << "]: ";
    cout << CountElementsInRange(arr, kArraySize, a, b) << endl;

    int max_id = FindMaxId(arr, kArraySize);
    cout << "\nMax element index: " << max_id;
    cout << "\nSum of elements after max element: ";
    if (max_id != kArraySize - 1)
        cout << SumElements(arr, kArraySize, max_id + 1) << endl;
    else
        cout << "\nMax element is the last one.\n";


    cout << "\nSorted array (descending by absolute values):\n";
    SortArray(arr, kArraySize);
    PrintArray(arr, kArraySize);
    cout << endl;

    return 0;
}

void PrintArray(double* arr, const int size) {
    cout << string(61, '-') << endl << "|";

    for (int i = 0; i < size; i++)
        cout << setw(2) << "[" << i << "]" << setw(2) << "|";
    cout << " <- index\n" << string(61, '-') << endl << "|";

    for (int i = 0; i < size; i++)
        cout << setw(4) << arr[i] << " |";
    cout << " <- array\n" << string(61, '-');
}

int CountElementsInRange(double* arr, const int size, double a, double b) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if ((arr[i] >= a) && (arr[i] <= b))
            count++;
    return count;
}

int FindMaxId(double* arr, const int size) {
    int max_id = 0;
    for (int i = 1; i < size; i++)
        if (arr[i] > arr[max_id])
            max_id = i;
    return max_id;
}

double SumElements(double* arr, const int size, int begin) {
    double sum = 0;
    for (int i = begin; i < size; i++)
        sum += arr[i];
    return sum;
}

void SortArray(double* arr, int const size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (abs(arr[j]) < abs(arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}