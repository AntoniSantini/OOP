#pragma once
#include "player.h"

class Warrior : public Player {
	bool shield_active;
public:
	Warrior(const std::string& name);
	~Warrior() override;

	void displayStatus() const override;
	void specialAbility() override;

	void attackEnemy(Enemy* target) override;

	void takeDamage(int amount) override;
};
