#pragma once
#include <iostream>
using namespace std;

struct UniversityConstants {
	static const int MAX_ECTS_PER_YEAR = 60;
	static const int REQUIRED_ECTS_PER_YEAR = 45;

	static void print_university_rules() {
		cout << "Maksimalno ECTS po godini: " << MAX_ECTS_PER_YEAR << "\n";
		cout << "Potrebno ECTS za prolaz godine: " << REQUIRED_ECTS_PER_YEAR << "\n";
	}
};
