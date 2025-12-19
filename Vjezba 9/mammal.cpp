#include "mammal.h"
#include <iostream>

using namespace std;

Mammal::Mammal(const string& name, int age, double weight, bool hasFur)
	: Animal(name, age, weight), hasFur(hasFur) {

	if (hasFur) {
		cout << "Stvoren sisavac s dlakom" << endl;
	}
	else {
		cout << "Stvoren sisavac s malo dlake" << endl;
	}
}

bool Mammal::getHasFur() const {
	return hasFur;
}