#ifndef PLAYER_H
#define PLAYER_H
#include "std_lib_facilities_4.h"

//Just a player class that includes initials score and difficulty
class Player {
public:
	Player(string initials, int score, int difficulty);
	Player();
	string get_initials();
	int get_score();
	int get_difficulty();

	//This part will allow to read players from file
	friend istream& operator >> (istream& is, Player& player) {
		is >> player.initials >> player.score >> player.difficulty;
		return is;
	}
	//-----------------------------------------------

private:
	string initials;
	int score;
	int difficulty;
};
#endif //PLAYER_H
