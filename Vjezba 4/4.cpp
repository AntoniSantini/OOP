#include <iostream>
#include <string>

std::string word_to_pig_latin(std::string w) {
	if (w[0] == 'a' || w[0] == 'e' || w[0] == 'i' || w[0] == 'o' || w[0] == 'u') {
		w += "hay";
	}
	else {
		char c = w[0];
		w.erase(w.begin());
		w.push_back(c);
		w += "ay";
	}
	return w;
}

int main() {
	std::cout << word_to_pig_latin("apple") << "\n";
	std::cout << word_to_pig_latin("hello") << "\n";
}
