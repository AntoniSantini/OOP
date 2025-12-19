#include "animal.h"
#include <stdexcept>

using namespace std;

Animal::Animal(const string& name, int age, double weight)
	: name(name), age(age), weight(weight) {

	if (name.empty()) {
		throw invalid_argument("Ime ne može biti prazno");
	}
	if (age < 0) {
		throw invalid_argument("Dob ne može biti negativna");
	}
	if (weight <= 0) {
		throw invalid_argument("Težina mora biti pozitivna");
	}
}

string Animal::getName() const {
	return name;
}

int Animal::getAge() const {
	return age;
}

double Animal::getWeight() const {
	return weight;
}