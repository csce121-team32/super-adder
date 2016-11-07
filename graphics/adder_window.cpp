#include "../std_lib_facilities_4.h"
#include "../fltk/Window.h"
#include "../fltk/Graph.h"

class AdderWindow : Graph_lib::Window{
	void draw();

	AdderWindow(int x, int y, string title)
		:Window(x,y,title){
		
	}
};

void AdderWindow::draw(){
	redraw();
}
