#include "dolphin.h"
#include <stdexcept>

using namespace std;

Dolphin::Dolphin(const string& name, int age, double weight)
	: Animal(name, age, weight), Mammal(name, age, weight, true), Aquatic(name, age, weight, 300.0) {}

string Dolphin::getSpecies() const {
	return "Dolphin";
}

double Dolphin::getDailyFood() const {
	double hrana = weight * 0.05;
	if (hrana == 0) {
		throw logic_error("Kolicina hrane ne može biti 0");
	}
	return hrana;
}