#include "../fltk/Window.h"
#include "../fltk/Graph.h"
#include "../std_lib_facilities_4.h"
#ifndef ADDER_WINDOW_H
#define ADDER_WINDOW_H

class Game;
class Tile;

class AdderWindow : Graph_lib::Window{
	void draw();
	Game* game;
	vector<Tile*> tile_list;
	public:
	bool disp();
	bool start(vector<Tile*>);
	void init(Game* g);
	AdderWindow(int x, int y, string title);
};

#endif
