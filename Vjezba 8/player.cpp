#include "player.h"

Player::Player(const std::string& name, int health)
	: GameCharacter(name, health), score(0) {}

Player::~Player() {}

void Player::addScore(int pts) {
	score += pts;
}

int Player::getScore() const {
	return score;
}
