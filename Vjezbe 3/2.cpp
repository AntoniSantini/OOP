#include <iostream>
#include <cstddef>
using namespace std;



inline bool uzlazno(int a, int b) {
	return a < b;
}
inline bool silazno(int a, int b) {
	return b < a;
}
inline bool uzlazno1(double a, double b) {
	return a < b;
}
inline bool silazno1(double a, double b) {
	return b < a;
}

template<typename T>
void sort(T niz[], size_t n, bool(*cmp)(T, T)) {
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = i + 1; j < n; j++)
			if (!cmp(niz[i], niz[j]))
				swap(niz[i], niz[j]);

	}
}

int main() {
	int niz[] = { 1,4,6,7,8,9 };
	double niz2[] = { 1.2,6.5,6.4,7.6,7.68,8.69 };
	size_t n = 6,n2 = 6;

	cout << "Uzlazno -> ";
	sort(niz, n, uzlazno);
	for (int a : niz)
		cout << a << " ";
	cout << endl;

	cout << "\nSilazno -> ";
	sort(niz, n, silazno);
	for (int a : niz)
		cout << a << " ";
	cout << endl;

	cout << "\nUzlazno -> ";
	sort(niz2, n2, uzlazno1);
	for (double a : niz2)
		cout << a << " ";
	cout << endl;

	cout << "\nSilazno -> ";
	sort(niz2, n2, silazno1);
	for (double a : niz2)
		cout << a << " ";
	cout << endl;
}
