#pragma once
#include "game_character.h"

class Player;

class Enemy : public GameCharacter {
protected:
	int difficulty;
public:
	Enemy(const std::string& name, int health, int difficulty);
	virtual ~Enemy();

	virtual void displayStatus() const override = 0;
	virtual void specialAbility() override = 0;

	virtual void attackPlayer(Player* target) = 0;
	int getDifficulty() const;
};
