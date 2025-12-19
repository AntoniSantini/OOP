#include "elephant.h"
#include <stdexcept>

using namespace std;

Elephant::Elephant(const string& name, int age, double weight)
	: Animal(name, age, weight), Mammal(name, age, weight, false) {}

string Elephant::getSpecies() const {
	return "Elephant";
}

double Elephant::getDailyFood() const {
	double hrana = weight * 0.04;
	if (hrana == 0) {
		throw logic_error("Kolicina hrane ne moze biti 0");
	}
	return hrana;
}