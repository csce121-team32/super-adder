//tile header
class Tile{
	int x, y;
	char value;
	
	

	//draws rectangle with text on it at loc.
	bool drawTile();
	char randValue();
	public:
	
	//returns the value of the tile.
	char getValue();
	string getString();
	//sets the value of the tile.
	void setValue(char c);
	
	Tile(char val);
	Tile();
};

