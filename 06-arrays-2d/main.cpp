#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int** ReadMatrix(string file_name, int num_rows, int num_cols);
void PrintMatrix(int** matrix, int num_rows, int num_cols);
void SwapColumns(int** matrix, int num_rows, int col1, int col2);
void ShiftColsRight(int** matrix, int num_rows, int num_cols);
void ShiftRowsDown(int** matrix, int num_rows);

int main() {
    int num_rows = 3;
    int num_cols = 4;

    int** matrix = ReadMatrix("matrix.txt", num_rows, num_cols);
    if (!matrix) return 1;

    cout << "Initial matrix:\n";
    PrintMatrix(matrix, num_rows, num_cols);
    cout << endl;

    string choice;
    while (true) {
        cout << "\nEnter '1' to shift right, '2' to shift down or 'q' to exit -> ";
        cin >> choice;

        if (choice == "q") break;

        if (choice != "1" && choice != "2") {
            cout << "Invalid input!\n";
            continue;
        }

        int n;
        cout << "Enter number of shifts -> ";
        cin >> n;

        if (choice == "1")
            for (int i = 0; i < n; i++)
                ShiftColsRight(matrix, num_rows, num_cols);
        else if (choice == "2")
            for (int i = 0; i < n; i++)
                ShiftRowsDown(matrix, num_rows);

        PrintMatrix(matrix, num_rows, num_cols);
        cout << endl;
    }

    for (int i = 0; i < num_rows; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}

int** ReadMatrix(string file_name, int num_rows, int num_cols) {
    ifstream fin(file_name);
    if (!fin.is_open()) {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }

    int** matrix = new int*[num_rows];
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = new int[num_cols];
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
    }

    fin.close();
    return matrix;
}

void PrintMatrix(int** matrix, int num_rows, int num_cols) {
    cout << string(5 * num_cols + 1, '-');
    for (int i = 0; i < num_rows; i++) {
        cout << "\n|";
        for (int j = 0; j < num_cols; j++)
            cout << setw(3) << matrix[i][j] << setw(2) << "|";
    }
    cout << endl << string(5 * num_cols + 1, '-');
}

void SwapColumns(int** matrix, int num_rows, int col1, int col2) {
    for (int i = 0; i < num_rows; i++)
        swap(matrix[i][col1], matrix[i][col2]);
}

void ShiftColsRight(int** matrix, int num_rows, int num_cols) {
    SwapColumns(matrix, num_rows, 0, num_cols - 1);
    for (int j = num_cols - 1; j > 1; j--)
        SwapColumns(matrix, num_rows, j, j - 1);
}

void ShiftRowsDown(int** matrix, int num_rows) {
    swap(matrix[0], matrix[num_rows - 1]);
    for (int i = num_rows - 1; i > 1; i--)
        swap(matrix[i], matrix[i - 1]);
}