#pragma once
#include "player.h"

class Mage : public Player {
	int mana;
public:
	Mage(const std::string& name);
	~Mage() override;

	void displayStatus() const override;
	void specialAbility() override;

	void attackEnemy(Enemy* target) override;

	int getMana() const;
};
