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
void Tile::move(int dx, int dy){
	button->move(dx,dy);
	y = y + dy;
	x = x + dx;
}
string Tile::getString(){
	string s(1,value);
	return s;
}
char Tile::getValue(){
	return value;
}
int Tile::getX(){
	return x;
}
int Tile::getY(){
	return y;
}
Button* Tile::getButton(){
	return button;
}
void Tile::setX(int n){
	x = n;
}
void Tile::setY(int n){
	y = n;
}
void Tile::setButton(Button* b){
	button=b;
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



