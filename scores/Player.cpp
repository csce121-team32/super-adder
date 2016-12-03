#include "std_lib_facilities_4.h"
#include"Player.h"

Player::Player(string i_initials, int i_score, int i_difficulty) {
	initials = i_initials;
	score = i_score;
	difficulty = i_difficulty;
}

Player::Player() {
}

string Player::get_initials() {
	return initials;
}

int Player::get_score() {
	return score;
}

int Player::get_difficulty() {
	return difficulty;
}