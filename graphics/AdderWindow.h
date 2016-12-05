#include "../fltk/Simple_window.h"
#include "../fltk/Graph.h"
#include "../std_lib_facilities_4.h"
#ifndef ADDER_WINDOW_H
#define ADDER_WINDOW_H

class Game;
class Tile;

class AdderWindow : Graph_lib::Window{
	private:
	Button b_tile1;
	Button b_tile2;
	Button b_tile3;
	Button b_tile4;
	Button b_tile5;
	Button b_tile6;
	Button b_tile7;
	Text score_text;
	Text time_remaining_text;
	
	int time;
	
	std::map<int,int> nummap;
	void attach_push(Button& b, int n);
	void check();
	int calculate_score();
	void set_score(int i);
	void set_time(int i);
	void move_tile(int i);
//	void move_tile2();
//	void move_tile3();
//	void move_tile4();
//	void move_tile5();
//	void move_tile6();
//	void move_tile7();
	void changetime();
	static void cb_time(void* u);
	static void cb_move_tile1(void* u);
	static void cb_move_tile2(void* u);
	static void cb_move_tile3(void* u);
	static void cb_move_tile4(void* u);
	static void cb_move_tile5(void* u);
	static void cb_move_tile6(void* u);
	static void cb_move_tile7(void* u);
	void select_tile1();
	void select_tile2();
	void select_tile3();
	void select_tile4();
	void select_tile5();
	void select_tile6();
	void select_tile7();
	static void cb_select_tile1(Address,Address pw);
	static void cb_select_tile2(Address,Address pw);
	static void cb_select_tile3(Address,Address pw);
	static void cb_select_tile4(Address,Address pw);
	static void cb_select_tile5(Address,Address pw);
	static void cb_select_tile6(Address,Address pw);
	static void cb_select_tile7(Address,Address pw);
	
	
	Game* game;
	string selected_tiles;
	vector<Tile*> tile_list;
	vector<Button*> button_list;
	public:
	bool disp();
	bool start(vector<Tile*>);
	void init(Game* g);
	AdderWindow(int x, int y, string title, vector<Tile*> tile_list);
};

#endif
