#include "aquatic.h"
#include <iostream>

using namespace std;

Aquatic::Aquatic(const string& name, int age, double weight, double maxDiveDepth)
	: Animal(name, age, weight), maxDiveDepth(maxDiveDepth) {

	cout << "Stvorena vodena zivotinja koja roni do "
		<< maxDiveDepth << "m" << endl;
}

double Aquatic::getMaxDiveDepth() const {
	return maxDiveDepth;
}