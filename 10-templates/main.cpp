#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
T** ReadMatrix(string file_name, int num_rows, int num_cols);

template <typename T>
void PrintMatrix(T** matrix, int num_rows, int num_cols);

template <typename T>
void SwapColumns(T** matrix, int num_rows, int col1, int col2);

template <typename T>
void ShiftColsRight(T** matrix, int num_rows, int num_cols);

template <typename T>
void ShiftRowsDown(T** matrix, int num_rows);

template <typename T>
int Execute(string file_name);

int main() {
    string data_type;
selection:
    cout << "Select the data type (0 - integer, 1 - float, 2 - double): ";
    cin >> data_type;
    if (data_type == "0") {
        Execute<int>("int.txt");
    }
    else if (data_type == "1") {
        Execute<float>("float.txt");
    }
    else if (data_type == "2") {
        Execute<double>("double.txt");
    }
    else {
        cout << "Error input! (Only 0, 1 or 2).\n\n";
        goto selection;
    }

    return 0;
}

template <typename T>
int Execute(string file_name) {
    int num_rows = 3;
    int num_cols = 4;

    T** matrix = ReadMatrix<T>(file_name, num_rows, num_cols);
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

template <typename T>
T** ReadMatrix(string file_name, int num_rows, int num_cols) {
    ifstream fin(file_name);
    if (!fin.is_open()) {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }

    T** matrix = new T*[num_rows];
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = new T[num_cols];
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
    }

    fin.close();
    return matrix;
}

template <typename T>
void PrintMatrix(T** matrix, int num_rows, int num_cols) {
    cout << string(5 * num_cols + 1, '-');
    for (int i = 0; i < num_rows; i++) {
        cout << "\n|";
        for (int j = 0; j < num_cols; j++)
            cout << setw(3) << matrix[i][j] << setw(2) << "|";
    }
    cout << endl << string(5 * num_cols + 1, '-');
}

template <typename T>
void SwapColumns(T** matrix, int num_rows, int col1, int col2) {
    for (int i = 0; i < num_rows; i++)
        swap(matrix[i][col1], matrix[i][col2]);
}

template <typename T>
void ShiftColsRight(T** matrix, int num_rows, int num_cols) {
    SwapColumns(matrix, num_rows, 0, num_cols - 1);
    for (int j = num_cols - 1; j > 1; j--)
        SwapColumns(matrix, num_rows, j, j - 1);
}

template <typename T>
void ShiftRowsDown(T** matrix, int num_rows) {
    swap(matrix[0], matrix[num_rows - 1]);
    for (int i = num_rows - 1; i > 1; i--)
        swap(matrix[i], matrix[i - 1]);
}