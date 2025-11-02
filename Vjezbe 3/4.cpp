#include <iostream>
#include <string>
using namespace std;

struct Student {
	string ime;
	string jmbag;
	int godina;
	int ects;
	double prosjek;
};

void filter_students(Student studenti[], size_t n,
	void(*akcija)(Student&),
	bool(*filter)(Student&)) {
	for (size_t i = 0; i < n; i++) {
		if (filter(studenti[i])) {
			akcija(studenti[i]);
		}
	}
}

void ispisi(Student &s) {
	cout << s.ime << " " << s.jmbag
		<< " Godina: " << s.godina
		<< " ETCS: " << s.ects
		<< " Prosjek: " << s.prosjek << endl;
}

void povecajGodinu(Student &s) {
	s.godina++;
}

int main() {
	Student studenti[] = {
		{"Ana", "534531", 1, 5, 4.0},
		{"Marko", "202325", 2, 50, 3.8},
		{"Ivana", "532002", 1, 0, 3.0},
		{"Petar", "124004", 3, 60, 4.2},
		{"Lucija", "21422", 1, 10, 3.5}
	};
	size_t n = sizeof(studenti) / sizeof(studenti[0]);

	auto uvjetPrvaGodinaPolozen = [](Student &s) {
		return s.godina == 1 && s.ects >= 1;
	};

	auto uvjetProsjek = [](Student &s) {
		return s.prosjek > 3.5;
	};

	auto ECTS = [](Student &s) {
		return s.ects >= 45;
	};

	cout << "Prva godina i barem jedan ispit:" << endl;
	filter_students(studenti, n, ispisi, uvjetPrvaGodinaPolozen);

	cout << "\nProsjek veci od 3.5:" << endl;
	filter_students(studenti, n, ispisi, uvjetProsjek);

	
	filter_students(studenti, n, povecajGodinu, ECTS);

	cout << "\nNakon povecanja godine:" << endl;
	for (size_t i = 0; i < n; i++) {
		ispisi(studenti[i]);
	}

	return 0;
}
