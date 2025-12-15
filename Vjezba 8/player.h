#pragma once
#include "game_character.h"

class Enemy;

class Player : public GameCharacter {
protected:
	int score;
public:
	Player(const std::string& name, int health);
	virtual ~Player();

	virtual void displayStatus() const override = 0;
	virtual void specialAbility() override = 0;

	virtual void attackEnemy(Enemy* target) = 0;
	void addScore(int pts);
	int getScore() const;
};
