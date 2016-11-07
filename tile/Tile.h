//tile header
class Tile{
	int x, y;
	char value;
	
	Tile(char val);
	//returns the value of the tile.
	char getValue();

	//sets the value of the tile.
	void setValue(char c);

	//draws rectangle with text on it at loc.
	bool drawTile();
};

