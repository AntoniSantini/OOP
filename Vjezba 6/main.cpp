#include <iostream>
#include "container.h"

void func(container a) {
	std::cout << "funkcija primila kopiju, velicina=" << a.size() << "\n";
}

container napravi() {
	container t;
	t.push_back(777);
	return t;
}

int main() {
	std::cout << "1) Dodavanje\n";
	container c1;
	c1.push_back(1);
	c1.push_back(2);
	c1.push_back(3);

	std::cout << "2) Kopiranje\n";
	container c2 = c1;

	std::cout << "3) Premjestanje\n";
	container c3 = std::move(c1);

	std::cout << "4) Funkcija\n";
	func(c2);

	std::cout << "5) Vracanje\n";
	container c4 = napravi();

	std::cout << "6) Ispis c2\n";
	for (size_t i = 0; i < c2.size(); i++)
		std::cout << i << ": " << c2.at(i) << "\n";

	std::cout << "Kapacitet: " << c2.capacity() << "\n";
	return 0;
}
