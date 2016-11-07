#include "../std_lib_facilities_4.h"
#include "../fltk/Window.h"
#include "AdderWindow.h"
#include "../fltk/Graph.h"

AdderWindow::AdderWindow(int x, int y, string title)
: Window(x,y,title)
{

}

void AdderWindow::draw(){
	redraw();
}
