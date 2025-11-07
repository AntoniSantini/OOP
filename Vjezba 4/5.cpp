#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void reverse_strings(std::vector<std::string>& r) {
	for (auto& word : r) {
		std::reverse(word.begin(), word.end());
	}
}

int main() {
	std::vector<std::string> r = { "hello", "world", "c++" };

	for (const auto& i : r) std::cout << i << " ";
	std::cout << "\n";

	reverse_strings(r);

	for (const auto& i : r) std::cout << i << " ";
	std::cout << "\n";

	return 0;
}
