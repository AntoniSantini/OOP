#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>   
using namespace std;

void input_vector(vector<int>& v) {
	int x;
	while (true) {
		cin >> x;
		if (x == 0) break;
		v.push_back(x);
	}
}

void print_vector(const vector<int>& v) {
	for (int broj : v)
		cout << broj << " ";
	cout << endl;
}

int main() {
	vector<int> v;
	cout << "Unesite brojeve (0 za kraj): ";
	input_vector(v);

	cout << "Originalni vektor: ";
	print_vector(v);

	vector<int> jedinstveni;
	for (int broj : v) {
		if (find(jedinstveni.begin(), jedinstveni.end(), broj) == jedinstveni.end()) {
			jedinstveni.push_back(broj);
		}
	}

	cout << "Jedinstveni elementi: ";
	print_vector(jedinstveni);

	sort(jedinstveni.begin(), jedinstveni.end(), [](int a, int b) {
		return abs(a) < abs(b);
	});

	cout << "Sortirani po apsolutnoj vrijednosti: ";
	for (size_t i = 0; i < jedinstveni.size(); i++) {
		cout << jedinstveni[i];
		if (i != jedinstveni.size() - 1) cout << ", ";
	}
	cout << endl;
}
