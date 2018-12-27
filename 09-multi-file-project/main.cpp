#include "functions.h"

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