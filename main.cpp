#include "std_lib_facilities_4.h"
#include "fltk/Window.h"
#include "fltk/Graph.h"
#include "game/game.h"
#include "tile/Tile.h"
#include "graphics/AdderWindow.h"
#include "graphics/SplashScreen.h"

//initializes windows, and then provides the program with addresses for them, and starts the game.
int main(){
	DiffWindow win2(Point(100,100),700,500,"test");
	StartWindow win3(Point(50,50), 1000, 700, "Best Game EVER");
	Game game(&win2,&win3);
	win3.init(&game);
	win2.init(&game);
	game.show_start();
	return Graph_lib::gui_main();
}

