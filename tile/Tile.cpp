#include "../std_lib_facilities_4.h"
#include "Tile.h"

//	char value;
//	int x;
//	int y;
Tile::Tile(char val){
	value = val;
}

Tile::Tile(){
	
	value = randValue();
	//cout<<value;
}
string Tile::getString(){
	string s(1,value);
	return s;
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

char Tile::randValue(){
	int tmp = rand()%16;
	if(tmp<10){
		return '0'+tmp;
	}else if(tmp>14){
		return randValue();
	}else{
		switch(tmp){
			case 10:
				return '+';
			case 11:
				return '-';
			case 12:
				return '*';
			case 13:
				return '/';
			case 14:
				return '(';
		}
	}
}



