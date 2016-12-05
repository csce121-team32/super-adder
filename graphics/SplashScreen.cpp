
#include "../std_lib_facilities_4.h"
#include "../fltk/Window.h"
#include "../fltk/Graph.h"
#include "SplashScreen.h"
#include "../fltk/GUI.h"
#include "../fltk/Simple_window.h"
#include "../game/game.h"

DiffWindow::DiffWindow(Point xy, int x, int y, const string& title): Graph_lib::Window{x,y,title},
difficulty1_button{Point(50,340), 100, 25, "3 tiles",cb_dif1}, 
difficulty2_button{Point(175,340), 100, 25, "4 tiles",cb_dif2},
difficulty3_button{Point(300,340), 100, 25, "5 tiles",cb_dif3},  //difficulty buttons for user to select
difficulty4_button{Point(425,340), 100, 25, "6 tiles",cb_dif4},
difficulty5_button{Point(550,340), 100, 25, "7 tiles",cb_dif5},
tt{Point{80,355},"Easy"},
tt1{Point{205,355},"Normal"},
tt2{Point{330,355},"Hard"},   //descriptions for difficulty buttons
tt3{Point{455,355},"Lunatic"},
tt4{Point{580,355},"Extra"},
r{Point{50,340}, 100, 25},
r1{Point{175,340}, 100, 25},
r2{Point{300,340}, 100, 25},  //rectangles to show where buttons are with image overlay
r3{Point{425,340}, 100, 25},
r4{Point{550,340}, 100, 25},
ii{Point{0,0},"background1.jpg"},  //image for screen
t{Point{25,50},"How to play:"},
t1{Point{250,25},"To begin the game, choose a difficulty. You will be given "},
t2{Point{250,50},"a certain amount of tiles based on the difficulty you choose."},
t3{Point{250,75},"These tiles will consist of +,-,/,* or 1-9, chosen at random."},  //text showing hwo to play the game
t4{Point{250,100},"Arrange these tiles in proper order to generate the highest"},
t5{Point{250,125},"score possible. Invalid order of tiles will result in a score "},
t6{Point{250,150},"of zero for that round."}
{ 
	//set font for instructions.
	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(40);
	t1.set_font_size(17);
	t2.set_font_size(17);
	t3.set_font_size(17);
	t4.set_font_size(17);
	t5.set_font_size(17);
	t6.set_font_size(17);
	//attach buttons, rectangles, image, and text
	attach(ii);
	attach(tt);
	attach(tt1);
	attach(tt2);
	attach(tt3);
	attach(tt4);
	attach(r);
	attach(r1);
	attach(r2);
	attach(r3);
	attach(r4);
	
	attach(t);
	attach(t1);
	attach(t2);
	attach(t3);
	attach(t4);
	attach(t5);
	attach(t6);
	attach(difficulty1_button);
	attach(difficulty2_button);
	attach(difficulty3_button);
	attach(difficulty4_button);
	attach(difficulty5_button);
	hide();
}
void DiffWindow::init(Game* g){		//init provides it with a pointer to the game class to allow it to call functions.
	game = g;
}
bool DiffWindow::disp(){   //show window based on where the user is in the game
	show();
	return true;
}
void DiffWindow::dif1(){
	game->start_game(3);
	hide();
}
void DiffWindow::dif2(){
	game->start_game(4);
	hide();
}
void DiffWindow::dif3(){  //callback function for the difficulty buttons -> starts the game
	game->start_game(5);
	hide();
}
void DiffWindow::dif4(){
	game->start_game(6);
	hide();
}
void DiffWindow::dif5(){
	game->start_game(7);
	hide();
}
void DiffWindow::cb_dif1(Address,Address pw){
reference_to<DiffWindow>(pw).dif1();
}
void DiffWindow::cb_dif2(Address,Address pw){
reference_to<DiffWindow>(pw).dif2();
}
void DiffWindow::cb_dif3(Address,Address pw){  //functions for the callbacks assigned to correct button
reference_to<DiffWindow>(pw).dif3();
}
void DiffWindow::cb_dif4(Address,Address pw){
reference_to<DiffWindow>(pw).dif4();
}
void DiffWindow::cb_dif5(Address,Address pw){
reference_to<DiffWindow>(pw).dif5();
}	



StartWindow::StartWindow(Point xy,int w,int h,const string& title):Graph_lib::Window{xy,w,h,title},
exit_button{Point(x_max()-75,0), 70, 20, "EXIT",cb_exit},  //exit button
start_button{Point(75,550), 125, 100, "START",cb_rules},   //start button
i{Point{0,0},"background.jpg"},  //image for main screen
t{Point{50,150},"SUPER"},  //
tt{Point{600,150},"ADDER"}, 
t1{Point{760,200},"Group Members:"},
t2{Point{760,240},"Kevin Etheridge"},
t3{Point{760,280},"Bo Corman"},
t4{Point{760,320},"Jose Felix"}, //text on main screen
t5{Point{100,250},"Team:"},
t6{Point{100,350},"Lich"},
t7{Point{100,450},"Kings"},
t8{Point{90,610},"Start"},
t9{Point{x_max()-50,15},"Exit"},
r{Point{75,550}, 125, 100},  //rectangles for start and exit buttons on main screen
r1{Point{x_max()-75,0}, 70, 20}
{

	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(100);
	tt.set_font(Graph_lib::Font::times_bold);
	tt.set_font_size(100); 
	t5.set_font(Graph_lib::Font::times_bold);
	t5.set_font_size(50);
	t6.set_font(Graph_lib::Font::times_bold); //customizing text
	t6.set_font_size(50); 
	t7.set_font(Graph_lib::Font::times_bold);
	t7.set_font_size(50);
	t8.set_font(Graph_lib::Font::times_bold);
	t8.set_font_size(40); 
	t9.set_font(Graph_lib::Font::times_bold);
	attach(exit_button);
	attach(start_button);
	attach(i);
	attach(t);
	attach(tt);
	attach(t1);
	attach(t2);
	attach(t3);  //attaching text, rectangles, image, and buttons
	attach(t4);
	attach(t5);
	attach(t6);
	attach(t7);
	attach(t8);
	attach(t9);
	attach(r);
	attach(r1);
	hide();
}
void StartWindow::init(Game* g){ //init provides with game pointer to call functions to show other windows and progress the game.
	game = g;
}
bool StartWindow::disp(){   
	show();
	return true;
}
void StartWindow::exit(){  //hide/show window when needed from game class.
	hide();
}
void StartWindow::rules(){
	hide();
	game->show_rules();
}
void StartWindow::cb_exit(Address,Address pw){
	reference_to<StartWindow>(pw).exit();         //callback functions assigned to correct buttons
}		
void StartWindow::cb_rules(Address,Address pw){
reference_to<StartWindow>(pw).rules();
}
