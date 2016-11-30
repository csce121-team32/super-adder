//#include "../fltk/Window.h"
#include "../fltk/Graph.h"
//#include "../fltk/GUI.h"
//#include "../graphics/SplashScreen.h"
//#include "../graphics/AdderWindow.h"
#include "../fltk/Simple_window.h"
#include "../std_lib_facilities_4.h"
#ifndef ADDER_GAME
#define ADDER_GAME

class AdderWindow;
class DiffWindow;
class StartWindow;

struct Game {
	Game(AdderWindow* game_window, DiffWindow* diff_window, StartWindow* start_window);
	DiffWindow* diff_win;
	AdderWindow* game_win;
	StartWindow* start_win;
	
	bool show_rules();
	bool show_start();
	bool show_game();
};

#endif