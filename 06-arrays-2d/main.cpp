#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void ReadArray(int **a, int N, int M) {
	ifstream fin("file.txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
	}
	else
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				fin >> a[i][j];
			}
		}
	}
	fin.close();
}

void PrintArray(int **a, int N, int M) {
	cout << "Array: " << endl;
	cout << string(21, '-') << endl;
	for (int i = 0; i < N; i++) {
		cout << "|";
		for (int j = 0; j < M; j++) {
			cout << setw(3) << a[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << string(21, '-') << endl << endl;
}

void CycleDown(int **a, int N, int M, int n) {
	int *b = new int[M];
	for (int i = 0; i < n; i++)
	{
		for (int c = 0; c < M; c++)
		{
			int buf = a[N - 1][c];
			for (int r = N - 1; r > 0; r--)
			{
				a[r][c] = a[r - 1][c];
			}
			a[0][c] = buf;
		}
	}
}

void CycleRight(int **a, int N, int M, int n) {
	int *b = new int[M];
	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < N; r++)
		{
			int buf = a[r][M - 1];
			for (int c = M - 1; c > 0; c--)
			{
				a[r][c] = a[r][c - 1];
			}
			a[r][0] = buf;
		}
	}
}

int main() {

	int N = 3;
	int M = 4;

	int **array = new int*[N];
	for (int i = 0; i < N; i++) {
		array[i] = new int[M];
	}

	ReadArray(array, N, M);
	PrintArray(array, N, M);

	while (true)
	{
		cout << "\nEnter \"1\" for down cycle of \"2\" for right cyle -> ";
		string select;
		cin >> select;
		if (select == "2") {
			cout << "Enter n - number of cycle spin -> ";
			int n;
			cin >> n;
			CycleRight(array, N, M, n);
			PrintArray(array, N, M);
			break;
		}
		else if (select == "1") {
			cout << "Enter n - number of cycle spin -> ";
			int n;
			cin >> n;
			CycleDown(array, N, M, n);
			PrintArray(array, N, M);
			break;
		}
		else {
			cout << "\n" << string(17, '-');
			cout << "\n Invalid input!\n";
			cout << string(17, '-') << "\n";
		}
	}

	return 0;
}