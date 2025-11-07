#include <iostream>
#include <string>
using namespace std;

void fix_spaces(string& text) {
	size_t i = 0;
	while (i < text.size()) {
		if (text[i] == ' ' && i + 1 < text.size() && text[i + 1] == ' ') {
			text.erase(i, 1);
		}
		else {
			i++;
		}
	}

	for (i = 1; i < text.size(); i++) {
		if ((text[i] == ',' || text[i] == '.') && text[i - 1] == ' ') {
			text.erase(i - 1, 1);
			i--;
		}
	}

	for (i = 0; i < text.size(); i++) {
		if (text[i] == ',') {
			if (i + 1 < text.size() && text[i + 1] != ' ') {
				text.insert(i + 1, " ");
			}
		}
	}
}

int main() {
	string s = "Puno   razmaka ,i tocka .";
	fix_spaces(s);
	cout << s << endl;
