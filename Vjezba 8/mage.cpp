#include "mage.h"
#include "enemy.h"
#include <iostream>
using namespace std;

Mage::Mage(const std::string& name)
	: Player(name, 80), mana(100) {}

Mage::~Mage() {}

void Mage::displayStatus() const {
	cout << "Merlin tip: Mage Ime: " << name << " HP: " << health << " Mana: " << mana << " Score: " << score << "\n";
}

void Mage::specialAbility() {
	if (health > 50) {
		cout << name << " teleportira\n";
	}
}

void Mage::attackEnemy(Enemy* target) {
	if (!target) return;
	if (!isAlive()) return;
	if (!target->isAlive()) return;

	if (mana >= 20) {
		target->takeDamage(40);
		mana -= 20;
	}
	else {
		target->takeDamage(20);
	}

	if (!target->isAlive()) addScore(10);
}

int Mage::getMana() const { return mana; }
