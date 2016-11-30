#include "../fltk/Window.h"
#include "../fltk/Graph.h"
#include "../std_lib_facilities_4.h"
#ifndef ADDER_WINDOW_H
#define ADDER_WINDOW_H

class Game;

class AdderWindow : Graph_lib::Window{
	void draw();
	Game* game;
	public:
	bool disp();
	void init(Game* g);
	AdderWindow(int x, int y, string title);
};

#endif
