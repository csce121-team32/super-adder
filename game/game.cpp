#include "../std_lib_facilities_4.h"
#include "../fltk/Window.h"
#include "../fltk/Graph.h"
#include "game.h"
#include "../fltk/GUI.h"
#include "../fltk/Simple_window.h"
#include "../graphics/SplashScreen.h"
#include "../graphics/AdderWindow.h"
#include "../tile/Tile.h"
#include "../scores/User_initials_difficulty.h"
#include "../scores/HS_list_manip.h"

//constructor -- gets pointers to other windows so it can show/hide them.
Game::Game(DiffWindow* diff_window, StartWindow* start_window){
	diff_win=diff_window;
	start_win = start_window;
	
}

//show difficulty select window function
bool Game::show_rules(){
	diff_win->disp();
	return true;
}

//show start screen function
bool Game::show_start(){
	start_win->disp();
	return true;
}

//show game itself function
bool Game::show_game(){
	game_win->disp();
	return true;
}

/* 
 * fill tile vector with n number of tiles using random values
*/
void Game::populate_vector(int n){
	int bracket_count = 0;
	int number_count = 0;
	int operator_count = 0;
	tile_list.clear();	//reset tile list
	for(int i = 0;i<n;i++){
		tile_list.push_back(new Tile());	//add new tiles to vector (constructor gives random values)
		if(tile_list.at(i)->getValue()=='('){
			bracket_count++; //count number of left parenthesis
		}
	}
	for(int i = 0;i<bracket_count;i++){
		int tmp = rand()%tile_list.size();
		if(tile_list.at(tmp)->getValue()!='('&&tile_list.at(tmp)->getValue()!=')'){
			tile_list.at(tmp)->setValue(')');	//for every left parenthesis add a right parenthesis somewhere, 
		}										// being sure not to replace the left parenthesis.
		else i--;	// try again if would have removed left parenthesis on accident.
	}
	for(int i = 0;i<n;i++){
		cout<<tile_list.at(i)->getValue();
		if(tile_list.at(i)->getValue()<='9'&&tile_list.at(i)->getValue()>='0'){
			number_count++;	//count number of numbers in list
		}else{
			operator_count++;	//count number of operators in list.
		}
	}
	if(number_count<operator_count){	//check more num than operators
		populate_vector(n);	//retry entire thing recursively if fails condition.
	}
}

// init begin game
void Game::start_game(int n){
	
	populate_vector(n);	//fill tile list with difficulty num of tiles
	load_file_scores();	//load leaderboard from file
	initials = initials_input();	//get player initials
	difficulty = n;	//set difficulty var
	display_scores(n,initials);	//show current leaderboard before starting.
	game_win = new AdderWindow(1500,800,"super-adder",tile_list);	//construct game window
	game_win->init(this);	//give game window the game pointer.
	game_win->start(tile_list);	//start game.
	
}

// used upon game end.
void Game::end_game(double d){
	update_scores(initials,d,difficulty);	//update leaderboard with player score
	display_scores(difficulty,initials,d);	//display new scores after.
}
