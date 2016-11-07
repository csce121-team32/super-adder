#include "../std_lib_facilities_4.h"
#include "tile.h"

class tile{
	char value;
	int x;
	int y;
	tile(char val){
		value = val;
	}

public:
	char getValue(){
		return value;
	}

	void setValue(char c){
		value = c;
	}
	bool drawTile(){
		//draw the tile
		return true;
	}
};


