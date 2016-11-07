#include "std_lib_facilities_4.h"
#include "fltk/Window.h"
#include "fltk/Graph.h"
//#include "tile/Tile.h"
#include "graphics/AdderWindow.h"
int main(){
	AdderWindow win(600,400,"super-adder");
	return Graph_lib::gui_main();
}

