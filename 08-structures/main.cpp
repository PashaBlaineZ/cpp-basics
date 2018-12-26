#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct NOTE
{
	string full_name;
	string number;
	int bern_date[3];
};

void AddNote(NOTE *M, int const size) {
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". Note\n";
		cout << "Enter FULL NAME -> ";
		getline(cin, M[i].full_name);
		cout << "Enter NUMBER -> ";
		getline(cin, M[i].number);
		cout << "Enter DATE OF BERN (dd mm yy) -> ";
		cin >> M[i].bern_date[0] >> M[i].bern_date[1] >> M[i].bern_date[2];
		cout << endl;
	}
}

void SortNote(NOTE *M, int const size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (M[j].full_name.compare(M[j + 1].full_name) > 0)
				swap(M[j], M[j + 1]);
		}
	}
}

string DateConvert(int a[]) {
	string date = "";
	for (int i = 0; i < 3; i++)
	{
		date += to_string(a[i]);
		date += ".";
	}
	date.erase(date.length() - 1);
	return date;
}

void PrintNote(NOTE M[], int const size) {
	cout << string(61, '-') << endl;
	cout << "|" << setw(21) << "Full name";
	cout << "|" << setw(21) << "number";
	cout << "|" << setw(15) << "date of bern";
	cout << "|\n";
	cout << string(61, '-') << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "|" << setw(21) << M[i].full_name;
		cout << "|" << setw(21) << M[i].number;

		cout << "|" << setw(15) << DateConvert(M[i].bern_date);
		cout << "|\n";
	}
	cout << string(61, '-') << endl;
}

void PrintFindNote(NOTE M[], int const size, string find) {
	bool finded = false;
	for (int i = 0; i < size; i++)
	{
		if (to_string(M[i].bern_date[1]) == find) {
			finded = true;
			cout << "|" << setw(21) << M[i].full_name;
			cout << "|" << setw(21) << M[i].number;
			cout << "|" << setw(15) << DateConvert(M[i].bern_date);
			cout << "|\n";
		}
	}
	if (!finded)
		cout << "No " << find << " point in NOTE!\n\n";
}

int main() {
	int const kSize = 2;
	NOTE M[kSize];

	AddNote(M, kSize);
	PrintNote(M, kSize);

	cout << "Sorted NOTE:\n";
	SortNote(M, kSize);
	PrintNote(M, kSize);

	cout << "Enter month for find ->";
	string find;
	cin >> find;
	PrintFindNote(M, kSize, find);

	return 0;
}