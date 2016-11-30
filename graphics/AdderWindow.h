#include "../fltk/Window.h"
#include "../fltk/Graph.h"
#include "../std_lib_facilities_4.h"
#ifndef ADDER_WINDOW_H
#define ADDER_WINDOW_H
class AdderWindow : Graph_lib::Window{
	void draw();
	public:
	AdderWindow(int x, int y, string title);
};

#endif
