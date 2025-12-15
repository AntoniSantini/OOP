#pragma once
#include "enemy.h"

class Gnome : public Enemy {
public:
	Gnome(const std::string& name);
	~Gnome() override;

	void displayStatus() const override;
	void specialAbility() override;

	void attackPlayer(Player* target) override;
};
