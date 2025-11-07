#include <iostream>
#include <vector>
using namespace std;

void input_vector(vector<int>& brojevi) {
	int unos;
	while (true) {
		cin >> unos;
		if (unos == 0) break;
		brojevi.push_back(unos);
	}
}

void print_vector(const vector<int>& brojevi) {
	for (int broj : brojevi)
		cout << broj << " ";
	cout << endl;
}

int main() {
	vector<int> brojevi;
	cout << "Unesi brojeve (0 za kraj): ";
	input_vector(brojevi);
	cout << "Uneseni brojevi su: ";
	print_vector(brojevi);
}
