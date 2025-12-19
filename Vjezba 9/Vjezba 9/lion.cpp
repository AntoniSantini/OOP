#include "lion.h"
#include <stdexcept>

using namespace std;

Lion::Lion(const string& name, int age, double weight)
	: Animal(name, age, weight),
	Mammal(name, age, weight, true) {}

string Lion::getSpecies() const {
	return "Lion";
}

double Lion::getDailyFood() const {
	double hrana = getWeight() * 0.06;
	if (hrana == 0) {
		throw logic_error("Kolicina hrane ne moze biti 0");
	}
	return hrana;
}
