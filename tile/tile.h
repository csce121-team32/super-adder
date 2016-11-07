//tile header
class tile{
	int x, y;
	char value;
	
	//returns the value of the tile.
	char getValue();

	//sets the value of the tile.
	char setValue();

	//draws rectangle with text on it at loc.
	bool drawTile(int x, int y);
};

