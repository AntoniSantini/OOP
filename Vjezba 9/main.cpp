#include <iostream>
#include <memory>
#include "lion.h"
#include "elephant.h"
#include "dolphin.h"
#include "seaturtle.h"
#include "zoo_section.h"
#include "zoo_keeper.h"

using namespace std;

int main() {
	try {
		ZooSection<Animal> zoo;
		ZooKeeper keeper;

		auto lav = make_unique<Lion>("Simba", 5, 180.0);
		auto slon = make_unique<Elephant>("Dambo", 10, 4000.0);
		auto dupin = make_unique<Dolphin>("Flipper", 8, 200.0);
		auto kornjaca = make_unique<SeaTurtle>("Shelly", 40, 120.0);

		zoo.addAnimal(move(lav));
		zoo.addAnimal(move(slon));
		zoo.addAnimal(move(dupin));
		zoo.addAnimal(move(kornjaca));

		cout << "\nHranjenje zivotinja:\n";
		for (size_t i = 0; i < zoo.size(); i++) {
			keeper.processAnimal(zoo.getAnimal(i));
		}

		cout << "\nUkupna hrana: " << zoo.totalFood() << "kg\n";
		cout << "Broj zivotinja: " << ZooKeeper::getTotalAnimalsServed() << endl;

	}
	catch (const exception& e) {
		cout << "Greska: " << e.what() << endl;
	}

	return 0;
}