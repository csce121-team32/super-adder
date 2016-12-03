//User_initials_difficulty.cpp
#include "std_lib_facilities_4.h"
#include "Player.h"
#include "Simple_window.h"

//This function creates an input box for user to enter a number 3-7 
//to select difficulty and returns that difficulty
int difficulty_input() {
	Simple_window win{ Point(50,50),400,600,"Give Initials" };
	Text instructions(Point(75, 45), "Enter a number 3-7 to select difficulty");
	In_box difficulty_box(Point(175, 50), 20, 20, "");

	win.attach(difficulty_box);
	win.attach(instructions);
	win.wait_for_button();
	win.detach(difficulty_box);
	win.detach(instructions);
	return difficulty_box.get_int();
}

//-----------------------------------------------------------------

//This function makes an input box for user to enter his initials
//then it returns the string of initials
string initials_input() {
	Simple_window win{ Point(50,50),400,600,"Give Initials" };
	Text instructions(Point(150, 45), "Enter Initials");
	In_box initials_box(Point(150, 50), 80, 20, "");
	win.attach(initials_box);
	win.attach(instructions);
	win.wait_for_button();
	win.detach(initials_box);
	win.detach(instructions);
	return initials_box.get_string();
}
//--------------------------------------------------------------