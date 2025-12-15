#include "boss.h"
#include "player.h"
#include <iostream>
#include <algorithm>
using namespace std;

Boss::Boss(const std::string& name)
	: Enemy(name, 300, 8) {}

Boss::~Boss() {}

void Boss::displayStatus() const {
	cout << "Boss Ime: " << name << " HP: " << health << " Diff: " << difficulty << "\n";
}

void Boss::specialAbility() {
	if (!isAlive()) return;
	health += 50;
	if (health > 300) health = 300;
	cout << name << " regenerira\n";
}

void Boss::attackPlayer(Player* target) {
	if (!target) return;
	if (!isAlive()) return;
	if (!target->isAlive()) return;

	int dmg = 10 * difficulty;
	target->takeDamage(dmg);
}
