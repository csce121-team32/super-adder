#include "../std_lib_facilities_4.h"
#include "../fltk/Window.h"
#include "../fltk/Graph.h"
#include "game.h"
#include "../fltk/GUI.h"
#include "../fltk/Simple_window.h"
#include "../graphics/SplashScreen.h"
#include "../graphics/AdderWindow.h"
#include "../tile/Tile.h"

Game::Game(DiffWindow* diff_window, StartWindow* start_window){
	diff_win=diff_window;
	start_win = start_window;
	
}

bool Game::show_rules(){
	diff_win->disp();
}

bool Game::show_start(){
	start_win->disp();
}

bool Game::show_game(){
	game_win->disp();
}
/*
double Game::get_score(){
	vector<char> vc;
	for(int i = 0;i<tile_list.size();i++){
		vc.push_back(tile_list.at(i)->getValue());
	}
	return calculator->get_score(vc);
}
*/
void Game::populate_vector(int n){
	int bracket_count = 0;
	int number_count = 0;
	int operator_count = 0;
	tile_list.clear();
	for(int i = 0;i<n;i++){
		tile_list.push_back(new Tile());
		if(tile_list.at(i)->getValue()=='('){
			bracket_count++;
		}
	}
	for(int i = 0;i<bracket_count;i++){
		int tmp = rand()%tile_list.size();
		if(tile_list.at(tmp)->getValue()!='('&&tile_list.at(tmp)->getValue()!=')'){
			tile_list.at(tmp)->setValue(')');
		}
		else i--;
	}
	for(int i = 0;i<n;i++){
		
		cout<<tile_list.at(i)->getValue();
		if(tile_list.at(i)->getValue()<='9'&&tile_list.at(i)->getValue()>='0'){
			number_count++;
		}else{
			operator_count++;
		}
	}
	if(number_count<operator_count){
		populate_vector(n);
	}
}

void Game::start_game(int n){
	
	populate_vector(n);
	game_win = new AdderWindow(1500,800,"super-adder",tile_list);
	game_win->init(this);
	game_win->start(tile_list);
	
}
