#include "../std_lib_facilities_4.h"
#include "../fltk/Window.h"
#include "AdderWindow.h"
#include "../fltk/Graph.h"
#include "../game/game.h"

AdderWindow::AdderWindow(int x, int y, string title)
: Window(x,y,title)
{
	hide();
}
void AdderWindow::init(Game* g){
	game = g;
}
bool AdderWindow::start(vector<Tile*> v){
	tile_list = v;
	show();
	return true;
}
bool AdderWindow::disp(){
	show();
	return true;
}
void AdderWindow::draw(){
	redraw();
}
