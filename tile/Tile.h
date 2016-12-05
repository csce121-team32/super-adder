#include "../fltk/Simple_window.h"
#include "../fltk/Graph.h"
#ifndef Tile_H
#define Tile_H

//tile header

class Tile{
	int x, y;
	char value;
	
	

	bool drawTile();
	char randValue(); //generates a random value for the tile
	Button* button;
	bool used;
	public:
	bool is_used();
	void move(int dx, int dy); //moves the tile and keeps track of x,y (why does button not do this by itself :????)
	void setX(int n); //sets x coord -- for init
	void setY(int n); //sets y coord, -- for init
	void setButton(Button* b); //sets the button -- for init.
	char getValue(); //returns the value of the tile.
	Button* getButton(); //returns pointer to the button that this tile is on.
	int getX(); // gets the x pos of button
	int getY(); //gets the y pos of button
	string getString();  //returns the value of the tile as a string
	void setValue(char c);	//sets the value of the tile.
	
	Tile(char val);  // constructor either with set value or blank uses randValue() to set.
	Tile();
};

#endif
