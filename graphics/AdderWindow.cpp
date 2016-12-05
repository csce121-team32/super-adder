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
	attach_push(b_tile3,2);
	attach_push(b_tile4,3);
	attach_push(b_tile5,4);
	attach_push(b_tile6,5);
	attach_push(b_tile7,6);
	attach(score_text);
	attach(time_remaining_text);
	set_score(0);
	
	show();
	time = 2*tile_list.size()*tile_list.size();
	set_time(time);
	Fl::add_timeout(1,cb_time,(void*)this);
}
void AdderWindow::set_time(double i){
	char tp[100];
	snprintf(tp,sizeof(tp),"%.1f",i);
	string s = tp;
	time_remaining_text.~Text();
	new (&time_remaining_text) Text(Point(x_max()-300,30),"Time Remaining: "+s);
}
void AdderWindow::set_score(double i){
	char tp[100];
	snprintf(tp,sizeof(tp),"%.2f",i);
	string s = tp;
	score_text.~Text();
	new (&score_text) Text(Point(50,30),"Score: "+s);
}
void AdderWindow::attach_push(Button& b,int n){
	if(tile_list.size()>=n+1){	
		attach(b);
		tile_list.at(n)->setButton(&b);
		tile_list.at(n)->setX(-100);
		tile_list.at(n)->setY(300);
	}
}

void AdderWindow::move_tile(double i){
	double currentx = tile_list.at(i-1)->getX();
	double currenty = tile_list.at(i-1)->getY();
	// char* s = tile_list.at(i-1)->getX()+"";
	// puts(s);
	if(nummap.find(i)==nummap.end()){
		nummap[i]=selected_tiles.size()-1;
	}
	double targetx = ((((x_max()/tile_list.size())*(nummap[i]))+((x_max()/tile_list.size())/2)+500)/2);
	double targety = y_max()-300;
	string s = std::to_string(selected_tiles.size());
	char const* pchar = s.c_str();
//	puts(pchar);
	string s2 = std::to_string(nummap[i]);
	char const* pchar2 = s2.c_str();
	//puts(pchar2);
	double dx = ((targetx-currentx)/10);
	double dy = ((targety-currenty)/10);
	tile_list.at(i-1)->move(dx,dy);
	
}
void AdderWindow::check(){
	if(tile_list.size()==selected_tiles.size()){
		calculate_score();
	}
}
int AdderWindow::calculate_score(){
	puts(selected_tiles.c_str());
	double n = calculator(selected_tiles);
	set_score(n);
}
void AdderWindow::select_tile1(){
	if(!tile_list.at(0)->is_used()){
		Fl::add_timeout(.1,cb_move_tile1,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(0)->getString();
		check();
	}

}
void AdderWindow::select_tile2(){
	if(!tile_list.at(1)->is_used()){
		Fl::add_timeout(.1,cb_move_tile2,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(1)->getString();
		check();
	}
}
void AdderWindow::select_tile3(){
	if(!tile_list.at(2)->is_used()){
		Fl::add_timeout(.1,cb_move_tile3,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(2)->getString();
		check();
	}
}
void AdderWindow::select_tile4(){
	if(!tile_list.at(3)->is_used()){
		Fl::add_timeout(.1,cb_move_tile4,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(3)->getString();
		check();
	}
}
void AdderWindow::select_tile5(){
	if(!tile_list.at(4)->is_used()){
		Fl::add_timeout(.1,cb_move_tile5,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(4)->getString();
		check();
	}
}
void AdderWindow::select_tile6(){
	if(!tile_list.at(5)->is_used()){
		Fl::add_timeout(.1,cb_move_tile6,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(5)->getString();
		check();
	}
}
void AdderWindow::select_tile7(){
	if(!tile_list.at(6)->is_used()){
		Fl::add_timeout(.1,cb_move_tile7,(void*)this);
		selected_tiles = selected_tiles + tile_list.at(6)->getString();
		check();
	}
}

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
void AdderWindow::changetime(){
	time = time-.1;
	set_time(time);
	redraw();
}
void AdderWindow::cb_time(void* u){
	((AdderWindow*)u)->changetime();
	Fl::repeat_timeout(.1, cb_time,u);
}
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

void AdderWindow::init(Game* g){
	game = g;
}
bool AdderWindow::start(vector<Tile*> v){
	tile_list = v;
	for(int i = 1;i<=tile_list.size();i++){
		tile_list.at(i-1)->move(((x_max()/v.size())*i)-((x_max()/v.size())/2)+50,0);
		// b_tile2.move(((x_max()/v.size())*2)-((x_max()/v.size())/2)+50,0);
		// b_tile3.move(((x_max()/v.size())*3)-((x_max()/v.size())/2)+50,0);
		// b_tile4.move(((x_max()/v.size())*4)-((x_max()/v.size())/2)+50,0);
		// b_tile5.move(((x_max()/v.size())*5)-((x_max()/v.size())/2)+50,0);
		// b_tile6.move(((x_max()/v.size())*6)-((x_max()/v.size())/2)+50,0);
		// b_tile7.move(((x_max()/v.size())*7)-((x_max()/v.size())/2)+50,0);
	}
	show();
	return true;
}
bool AdderWindow::disp(){
	show();
	return true;
}
