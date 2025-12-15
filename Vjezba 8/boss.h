#pragma once
#include "enemy.h"

class Boss : public Enemy {
public:
	Boss(const std::string& name);
	~Boss() override;

	void displayStatus() const override;
	void specialAbility() override;

	void attackPlayer(Player* target) override;
};
