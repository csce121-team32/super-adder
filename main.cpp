#include "std_lib_facilities_4.h"
#include "fltk/Window.h"
#include "fltk/Graph.h"
//#include "tile/Tile.h"
#include "graphics/AdderWindow.h"
#include "graphics/SplashScreen.h"
int main(){
	AdderWindow win(1500,800,"super-adder");
	DiffWindow win2(Point(100,100),700,500,"test");
	StartWindow win3(Point(50,50), 1000, 700, "Best Game EVER");
	return Graph_lib::gui_main();
}

