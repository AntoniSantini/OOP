#include "warrior.h"
#include "enemy.h"
#include <iostream>
using namespace std;

Warrior::Warrior(const std::string& name)
	: Player(name, 120), shield_active(false) {}

Warrior::~Warrior() {}

void Warrior::displayStatus() const {
	cout << "Conan tip: Warrior Ime: " << name << " HP: " << health << " Score: " << score << "\n";
}

void Warrior::specialAbility() {
	shield_active = true;
	cout << name << " aktivira stit\n";
}

void Warrior::attackEnemy(Enemy* target) {
	if (!target) return;
	if (!isAlive()) return;
	if (!target->isAlive()) return;

	target->takeDamage(20);
	if (!target->isAlive()) addScore(10);
}

void Warrior::takeDamage(int amount) {
	if (shield_active && amount > 0) {
		amount = (amount + 1) / 2;
		shield_active = false;
	}
	GameCharacter::takeDamage(amount);
}
