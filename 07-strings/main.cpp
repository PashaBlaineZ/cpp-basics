#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

bool IsVowel(char letter);

int main() {

    ifstream fin("text.txt");
    if (!fin) {
        cout << "File \"text.txt\" not found.";
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        if (IsVowel(line[0]))
            line[0] = toupper(line[0], locale());

        for (size_t i = 1; i < line.length(); i++)
            if (IsVowel(line[i]) && line[i - 1] == ' ')
                line[i] = toupper(line[i], locale());

        cout << line << endl;
    }

    fin.close();
    return 0;
}

bool IsVowel(char letter) {
    letter = tolower(letter, locale());
    char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
    for (int i = 0; i < 5; i++)
        if (letter == vowels[i])
            return 1;
    return 0;
}