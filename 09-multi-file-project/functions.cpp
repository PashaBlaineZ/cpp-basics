#include "functions.h"

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