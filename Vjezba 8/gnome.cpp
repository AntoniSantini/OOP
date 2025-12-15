#include "gnome.h"
#include "player.h"
#include <iostream>
using namespace std;

Gnome::Gnome(const std::string& name)
	: Enemy(name, 90, 3) {}

Gnome::~Gnome() {}

void Gnome::displayStatus() const {
	cout << "Gnome Ime: " << name << " HP: " << health << " Diff: " << difficulty << "\n";
}

void Gnome::specialAbility() {
	if (health > 20) cout << name << " svira trubu\n";
}

void Gnome::attackPlayer(Player* target) {
	if (!target) return;
	if (!isAlive()) return;
	if (!target->isAlive()) return;

	int dmg = 5 * difficulty;
	target->takeDamage(dmg);
}
