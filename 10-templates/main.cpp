#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

template<class T>
void ReadArray(T **a, int N, int M, string name) {
	ifstream fin(name + ".txt");
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

template<class T>
void PrintArray(T **a, int N, int M) {
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

template<class T>
void CycleDown(T **a, int N, int M, int n) {
	T *b = new T[M];
	for (int i = 0; i < n; i++)
	{
		for (int c = 0; c < M; c++)
		{
			T buf = a[N - 1][c];
			for (int r = N - 1; r > 0; r--)
			{
				a[r][c] = a[r - 1][c];
			}
			a[0][c] = buf;
		}
	}
}

template<class T>
void CycleRight(T **a, int N, int M, int n) {
	T *b = new T[M];
	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < N; r++)
		{
			T buf = a[r][M - 1];
			for (int c = M - 1; c > 0; c--)
			{
				a[r][c] = a[r][c - 1];
			}
			a[r][0] = buf;
		}
	}
}

template <class TypeAr>
void start(string name) {
	int N = 3;
	int M = 4;

	TypeAr **array = new TypeAr*[N];
	for (int i = 0; i < N; i++) {
		array[i] = new TypeAr[M];
	}

	ReadArray(array, N, M, name);
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
}

int main() {
error:
	cout << "Select the data type (0-integer, 1-double, 2-float): ";
	string select;
	cin >> select;
	if (select == "0") {
		start<int>("int");
	}
	else if (select == "1") {
		start<double>("double");
	}
	else if (select == "2") {
		start<float>("float");
	}
	else {
		cout << "Error input! (Only 0/1/2)" << endl;
		goto error;
	}
	return 0;
}