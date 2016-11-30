#include "../std_lib_facilities_4.h"
#include "../fltk/Window.h"
#include "../fltk/Graph.h"
#include "game.h"
#include "../fltk/GUI.h"
#include "../fltk/Simple_window.h"
#include "../graphics/SplashScreen.h"
#include "../graphics/AdderWindow.h"

Game::Game(AdderWindow* game_window, DiffWindow* diff_window, StartWindow* start_window){
	diff_win=diff_window;
	start_win = start_window;
	game_win = game_window;
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
