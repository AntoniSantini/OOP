#include <iostream>
#include <cstddef>
using namespace std;

inline bool uzlazno(int a, int b) {
	return a < b;
}

inline bool silazno(int a, int b) {
	return b < a;
}

void sort(int arr[], size_t n, bool(*cmp)(int, int)) {
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = i + 1; j < n; j++) 
			if (!cmp(arr[i], arr[j]))
				swap(arr[i], arr[j]);
		
	}
}

int main() {
	int niz[] = { 1,4,6,7,8,9 };
	size_t n = 6;

	cout << "Uzlazno -> ";
	sort(niz, n, uzlazno);
	for (int a : niz)
		cout << a << " ";

	cout << "\nSilazno -> ";
	sort(niz, n, silazno);
	for (int a : niz)
		cout << a << " ";
}
