#include "../std_lib_facilities_4.h"
#include "Tile.h"

//constructor for tile to use preset value (not used.)
Tile::Tile(char val){
	value = val;
	used = false;
}

//constructor for tile to gen random value.
Tile::Tile(){
	value = randValue();	//gens random value.
}

//move tile function that keeps track of x and y coords
void Tile::move(int dx, int dy){
	button->move(dx,dy);	//move button
	y = y + dy;
	x = x + dx;		//update coords
}

// getter for tile value as string.
string Tile::getString(){
	string s(1,value);
	return s;
}

//return if tile has been placed on formula line or not.
bool Tile::is_used(){
	if(!used){
		used = true;
		return false;
	}
	else{
		return used;
	}
}

//return tile value as char.
char Tile::getValue(){
	return value;
}

// return x coord of button object.
int Tile::getX(){
	return x;
}

//return y coord of button object.
int Tile::getY(){
	return y;
}

//return pointer to button object.
Button* Tile::getButton(){
	return button;
}

//set x coord ov button object. (does not movebutton)
void Tile::setX(int n){
	x = n;
}

//set y coord of button obecjt. ( does not move button)
void Tile::setY(int n){
	y = n;
}

//set button object to allow using other fucntions related above and to keep track of buttons easilier.
void Tile::setButton(Button* b){
	button=b;
}

//set value of tile to char.
void Tile::setValue(char c){
	value = c;
}

// assign random value to char value.
char Tile::randValue(){
	int tmp = rand()%16;	//get num 0-15
	if(tmp<10){
		return '0'+tmp;	// set value to number if in this range.
	}else if(tmp>14){	//retry entire thing if in this range (used in place of right parenthesis
						//since it is placed afterwards to balance chance of each thing equally.
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



