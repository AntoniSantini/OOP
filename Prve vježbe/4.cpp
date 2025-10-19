#include <iostream>

int& funkcija(int niz[], int pozicija) {
	return niz[pozicija];
}

int main() {
	int niz[5] = { 20, 40, 60, 80, 100};

	for (int i = 0; i < 5; i++)
		std::cout << niz[i] << " ";
	std::cout << std::endl;

	funkcija(niz, 4)++;

	for (int i = 0; i < 5; i++)
		std::cout << niz[i] << " ";
	std::cout << std::endl;

	return 0;
}
