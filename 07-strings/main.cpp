#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool IsVowels(char s) {
	switch (s)
	{
	case 'A':
		return true;
	case 'O':
		return true;
	case 'Y':
		return true;
	case 'E':
		return true;
	case 'I':
		return true;
	case 'U':
		return true;
	default:
		return false;
	}
}

int main() {
	string s, file_name;

	cout << "Write  file name (default name 'a') -> ";
	cin >> file_name;
	file_name += ".txt";
	ifstream fin(file_name);

	if (!fin.is_open()) {
		cout << "can't open file!" << endl;
		return 1;
	}
	while (getline(fin, s, '\n')) {
		for (int i = 0; i < s.length(); i++)
		{
			if (IsVowels(s[i]))
			{
				s[i] = tolower(s[i]);
			}
		}
		cout << s << endl;
	}

	fin.close();
	return 0;
}