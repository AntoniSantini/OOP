#include "seaturtle.h"
#include <stdexcept>

using namespace std;

SeaTurtle::SeaTurtle(const string& name, int age, double weight)
	: Animal(name, age, weight), Aquatic(name, age, weight, 200.0) {}

string SeaTurtle::getSpecies() const {
	return "SeaTurtle";
}

double SeaTurtle::getDailyFood() const {
	double hrana = weight * 0.03;
	if (hrana == 0) {
		throw logic_error("Kolicina hrane ne može biti 0");
	}
	return hrana;
}