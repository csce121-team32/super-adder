#include "../std_lib_facilities_4.h"
#include "../fltk/Window.h"
#include "AdderWindow.h"
#include "../fltk/Graph.h"
#include "../game/game.h"
#include "../tile/Tile.h"
#include "../game/calculator.h"

AdderWindow::AdderWindow(int x, int y, string title, vector<Tile*> t_list)
: Window(x,y,title),
b_tile1{Point{(-100),300},100,200,(t_list.size()>=1) ? t_list.at(0)->getString() : "err",cb_select_tile1},
b_tile2{Point{(-100),300},100,200,(t_list.size()>=2) ? t_list.at(1)->getString() : "err",cb_select_tile2},
b_tile3{Point{(-100),300},100,200,(t_list.size()>=3) ? t_list.at(2)->getString() : "err",cb_select_tile3},
b_tile4{Point{(-100),300},100,200,(t_list.size()>=4) ? t_list.at(3)->getString() : "err",cb_select_tile4},
b_tile5{Point{(-100),300},100,200,(t_list.size()>=5) ? t_list.at(4)->getString() : "err",cb_select_tile5},
b_tile6{Point{(-100),300},100,200,(t_list.size()>=6) ? t_list.at(5)->getString() : "err",cb_select_tile6},
b_tile7{Point{(-100),300},100,200,(t_list.size()>=7) ? t_list.at(6)->getString() : "err",cb_select_tile7},
score_text{Point{50,30},"Score: 0"},
time_remaining_text{Point{x_max()-300,30},"Time Remaining"}
{
	tile_list = t_list;
	attach_push(b_tile1,0);
	attach_push(b_tile2,1);
	attach_push(b_tile3,2);	//attach tile buttons and add them to a vector.
	attach_push(b_tile4,3);
	attach_push(b_tile5,4);
	attach_push(b_tile6,5);
	attach_push(b_tile7,6);
	attach(score_text);
	attach(time_remaining_text);
	set_score(0);	//initialize score to 0
	
	ended = false;	//game has not yet ended. (more init)
	show();	//show this window when constructed
	time = 2*tile_list.size()*tile_list.size(); //set time remaining based on formula given
	set_time(0);	//init time to time ^^
	Fl::add_timeout(1,cb_time,(void*)this);	//start counting down timer after 1 second delay.
}

/* sets the time remaining to the current time minus
 * the double argument, and updates text box on screen.
*/
void AdderWindow::set_time(double i){
	if(time>0&&!ended){	//only change time if time is left and game is running
		time = time - i;
		char tp[100];
		snprintf(tp,sizeof(tp),"%.1f",time);	//format time remaining to 1 decimal place.
		string s = tp;
		time_remaining_text.~Text();													//destroy old text object
		new (&time_remaining_text) Text(Point(x_max()-300,30),"Time Remaining: "+s);	//and reconstruct with new time remaining (could not find way to change Text objects otherwise.)
	}
	else{
		end();	//game is over if time is 0.
	}
}

/* ends the game, displaying your final score, then
 * going back to the main game class to continue program flow. 
*/
void AdderWindow::end(){
	if(!ended){	// prevent this from spamming text boxes every second from timer.
		Text scoreend{Point{30,90},"err"};
		ended = true;
		Simple_window winend{Point{x_max()/2,y_max()/2},400,400,"Game over"};
		if(time == 0){
			scoreend.~Text();
			new (&scoreend) Text{Point{10,90},"Time's Up!"};
		}
		else{
			scoreend.~Text();
			new (&scoreend) Text{Point{10,90},"Congratulations, your score was "+score_s};
		}	//^^^^ create window to display score.
		winend.attach(scoreend);
		winend.wait_for_button();	
		game->end_game(score);	//go back to game to display scores etc then
		game->show_rules();		//show the rules aka difficulty screen to allow player to play again.
		hide();
	}
}

/* sets the score display to the score as arg.
 *
*/
void AdderWindow::set_score(double i){
	score = i;
	char tp[100];
	snprintf(tp,sizeof(tp),"%.2f",i);	//format to 2 dec places
	string s = tp;
	score_s = s;
	score_text.~Text();		//destruct old text box
	new (&score_text) Text(Point(50,30),"Score: "+s);	//make new one with new score.
	if(tile_list.size()==selected_tiles.size()){
		end();	//end game if all tiles have been used
	}
}

/* used for init to shorten constructor.
 *
*/
void AdderWindow::attach_push(Button& b,int n){
	if(tile_list.size()>=(unsigned)(n+1)){	
		attach(b);
		tile_list.at(n)->setButton(&b);
		tile_list.at(n)->setX(-100);
		tile_list.at(n)->setY(300);
	}
}

/* used to move the buttons while still keeping track of coords (once again)
 * I could not find a way to get x and get y of buttons with the fltk libraries given.
*/
void AdderWindow::move_tile(double i){
	double currentx = tile_list.at(i-1)->getX();	//get stored x and y from tile object.
	double currenty = tile_list.at(i-1)->getY();
	if(nummap.find(i)==nummap.end()){
		nummap[i]=selected_tiles.size()-1;	//if tile has not been added to formula line yet, keep track of where it is on line.
	}
	double targetx = ((((x_max()/tile_list.size())*(nummap[i]))+((x_max()/tile_list.size())/2)+500)/2);	//set variable to where tile should be on formula line.
	double targety = y_max()-300;
	double dx = ((targetx-currentx)/10);	//calculate change in x and y and divide it by 10 to allow for smooth-ish animation
	double dy = ((targety-currenty)/10);
	tile_list.at(i-1)->move(dx,dy);		//call move in the tile class (not button)
	
}

/* this simply checks if all tiles have used, if they have it calculates the score with the calculator.
 * 
*/
void AdderWindow::check(){
	if(tile_list.size()==selected_tiles.size()){
		calculate_score();
	}
}

/* this simply calls the function in the calculator file to get final score and then sets it to screen. 
 * 
*/
double AdderWindow::calculate_score(){
	puts(selected_tiles.c_str());
	double n = calculator(selected_tiles);
	set_score(n);
	return n;
}

/* this is function called by button that starts moving tile with animation once every 10th of a second if it has not yet been cliceked
 * 
*/
void AdderWindow::select_tile1(){
	if(!tile_list.at(0)->is_used()){ //ensure tile has not been clicked previously.
		Fl::add_timeout(.1,cb_move_tile1,(void*)this);	//start tile animation
		selected_tiles = selected_tiles + tile_list.at(0)->getString();	//add tile to vector of formula line.
		check();	//check if all tiles are on line yet
	}

}

//same as above
void AdderWindow::select_tile2(){
	if(!tile_list.at(1)->is_used()){
		Fl::add_timeout(.1,cb_move_tile2,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(1)->getString();
		check();
	}
}

//same as above
void AdderWindow::select_tile3(){
	if(!tile_list.at(2)->is_used()){
		Fl::add_timeout(.1,cb_move_tile3,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(2)->getString();
		check();
	}
}

//same as above
void AdderWindow::select_tile4(){
	if(!tile_list.at(3)->is_used()){
		Fl::add_timeout(.1,cb_move_tile4,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(3)->getString();
		check();
	}
}

//same as above
void AdderWindow::select_tile5(){
	if(!tile_list.at(4)->is_used()){
		Fl::add_timeout(.1,cb_move_tile5,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(4)->getString();
		check();
	}
}

//same as above
void AdderWindow::select_tile6(){
	if(!tile_list.at(5)->is_used()){
		Fl::add_timeout(.1,cb_move_tile6,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(5)->getString();
		check();
	}
}

//same as above
void AdderWindow::select_tile7(){
	if(!tile_list.at(6)->is_used()){
		Fl::add_timeout(.1,cb_move_tile7,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(6)->getString();
		check();
	}
}

//callbacks for tile buttons
void AdderWindow::cb_select_tile1(Address,Address pw){
	reference_to<AdderWindow>(pw).select_tile1();
}
void AdderWindow::cb_select_tile2(Address,Address pw){
	reference_to<AdderWindow>(pw).select_tile2();
}
void AdderWindow::cb_select_tile3(Address,Address pw){
	reference_to<AdderWindow>(pw).select_tile3();
}
void AdderWindow::cb_select_tile4(Address,Address pw){
	reference_to<AdderWindow>(pw).select_tile4();
}
void AdderWindow::cb_select_tile5(Address,Address pw){
	reference_to<AdderWindow>(pw).select_tile5();
}
void AdderWindow::cb_select_tile6(Address,Address pw){
	reference_to<AdderWindow>(pw).select_tile6();
}
void AdderWindow::cb_select_tile7(Address,Address pw){
	reference_to<AdderWindow>(pw).select_tile7();
}

//just changes the time and redraws window, used to make window update at 10 fps always.
void AdderWindow::changetime(){
	set_time(.1);
	redraw();
}

//callback function for fl::addtimeout to change the time with.
void AdderWindow::cb_time(void* u){
	((AdderWindow*)u)->changetime();
	Fl::repeat_timeout(.1, cb_time,u);
}

//callback functions for fl::addtimeout for the animations of tiles.
void AdderWindow::cb_move_tile1(void* u){
	((AdderWindow*)u)->move_tile(1);
	Fl::repeat_timeout(.1, cb_move_tile1,u);
}
void AdderWindow::cb_move_tile2(void* u){
	((AdderWindow*)u)->move_tile(2);
	Fl::repeat_timeout(.1, cb_move_tile2,u);
}
void AdderWindow::cb_move_tile3(void* u){
	((AdderWindow*)u)->move_tile(3);
	Fl::repeat_timeout(.1, cb_move_tile3,u);
}
void AdderWindow::cb_move_tile4(void* u){
	((AdderWindow*)u)->move_tile(4);
	Fl::repeat_timeout(.1, cb_move_tile4,u);
}
void AdderWindow::cb_move_tile5(void* u){
	((AdderWindow*)u)->move_tile(5);
	Fl::repeat_timeout(.1, cb_move_tile5,u);
}
void AdderWindow::cb_move_tile6(void* u){
	((AdderWindow*)u)->move_tile(6);
	Fl::repeat_timeout(.1, cb_move_tile6,u);
}
void AdderWindow::cb_move_tile7(void* u){
	((AdderWindow*)u)->move_tile(7);
	Fl::repeat_timeout(.1, cb_move_tile7,u);
}

//init function to get game object pointer.
void AdderWindow::init(Game* g){
	game = g;
}

// init function called on construction to move buttons to correct locations based on num tiles.
bool AdderWindow::start(vector<Tile*> v){
	tile_list = v;
	for(int i = 1;i<=tile_list.size();i++){
		tile_list.at(i-1)->move(((x_max()/v.size())*i)-((x_max()/v.size())/2)+50,0);
	}
	show();
	return true;
}

/* function used to show adderwindow when needed 
 * (i believe this is unused as we started constructing object when needed instead.)
*/
bool AdderWindow::disp(){
	show();
	return true;
}
