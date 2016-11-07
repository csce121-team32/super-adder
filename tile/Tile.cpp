#include "../std_lib_facilities_4.h"
#include "Tile.h"

//	char value;
//	int x;
//	int y;
Tile::Tile(char val){
	value = val;
}

char Tile::getValue(){
	return value;
}

void Tile::setValue(char c){
	value = c;
}

bool Tile::drawTile(){
	//draw the tile
	return true;
}



