#pragma once
#include <string>

class GameCharacter {
protected:
	int health;
	std::string name;
public:
	GameCharacter(const std::string& name, int health);
	virtual ~GameCharacter();

	virtual void displayStatus() const = 0;
	virtual void specialAbility() = 0;

	virtual void takeDamage(int amount);
	bool isAlive() const;

	const std::string& getName() const;
	int getHealth() const;
};
