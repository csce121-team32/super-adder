#ifndef HS_list_manip_H
#define HS_list_manip_H

#include "../std_lib_facilities_4.h"
#include "Player.h"
#include "../fltk/Simple_window.h"

vector<Player> load_file_scores();

//This function sorts players based on difficulty
vector<Player> sort_scores(int difficulty, vector<Player> Players = load_file_scores());
//---------------------------------------

//This function is used to add a new player to high score file
//call it with (initials, score, difficulty)
void update_scores(string p_initials = "", double p_score = 0, int p_difficulty = 0, vector<Player> Players = load_file_scores());
//------------------------------------------------------------

//(difficulty) top 5 high scores for that difficulty
//(difficulty,initials) top 5 followed by players initials with ??? score
//(difficulty, initials, score) top 5 then players initials and their score
void display_scores(int difficulty, string initials = "", double score = -9999.0);
//------------------------------------------------------------------------

#endif
