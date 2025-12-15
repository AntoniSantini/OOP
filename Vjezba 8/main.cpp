#include <iostream>
#include <vector>
#include "warrior.h"
#include "mage.h"
#include "gnome.h"
#include "boss.h"
using namespace std;

void printPairStatus(GameCharacter* a, GameCharacter* b) {
	if (a) a->displayStatus();
	if (b) b->displayStatus();
	cout << "\n";
}

int main() {
	vector<GameCharacter*> chars;

	Warrior* conan = new Warrior("Conan");
	Mage* merlin = new Mage("Merlin");
	Gnome* gnomeo = new Gnome("Gnomeo");
	Gnome* sneaky = new Gnome("Sneaky");
	Boss* dragon = new Boss("Dragon");

	chars.push_back(conan);
	chars.push_back(merlin);
	chars.push_back(gnomeo);
	chars.push_back(sneaky);
	chars.push_back(dragon);

	conan->attackEnemy(gnomeo);
	printPairStatus(conan, gnomeo);

	merlin->attackEnemy(sneaky);
	printPairStatus(merlin, sneaky);

	gnomeo->attackPlayer(conan);
	printPairStatus(gnomeo, conan);

	merlin->attackEnemy(gnomeo);
	printPairStatus(merlin, gnomeo);

	dragon->attackPlayer(merlin);
	printPairStatus(dragon, merlin);

	merlin->attackEnemy(gnomeo);
	printPairStatus(merlin, gnomeo);

	conan->attackEnemy(dragon);
	printPairStatus(conan, dragon);
	
	merlin->attackEnemy(dragon);
	printPairStatus(merlin, dragon);

	for (auto p : chars) {
		if (p && p->isAlive()) p->specialAbility();
	}

	cout << "\nStatus preostalih likova:\n";
	GameCharacter* maxHp = nullptr;
	for (auto p : chars) {
		if (p && p->isAlive()) {
			p->displayStatus();
			if (!maxHp || p->getHealth() > maxHp->getHealth())
				maxHp = p;
		}
	}

	if (maxHp) {
		cout << "Najvise zdravlja: " << maxHp->getName() << "\n";
	}

	for (auto p : chars) delete p;
	chars.clear();

	return 0;
}
