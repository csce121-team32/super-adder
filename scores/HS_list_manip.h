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
void update_scores(string p_initials = "", int p_score = 0, int p_difficulty = 0, vector<Player> Players = load_file_scores());
//------------------------------------------------------------

//This part shows high scores for a certain difficulty if you leave second 
//Parameter blank
//If you include the initials then it will show initials after the high scores
void display_scores(int difficulty, string initials = "");
//------------------------------------------------------------------------

#endif