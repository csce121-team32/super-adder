//#include "../fltk/Window.h"
#include "../fltk/Graph.h"
//#include "../fltk/GUI.h"
#include "../fltk/Simple_window.h"
#include "../std_lib_facilities_4.h"

#ifndef ADDER_SPLASH
#define ADDER_SPLASH
class Game;

struct DiffWindow : Graph_lib::Window{
	DiffWindow(Point xy,int x, int y, const string& title);
	bool disp();
	void init(Game* g);
	
	private:
	Button difficulty1_button;
	Button difficulty2_button;
	Button difficulty3_button;
	Button difficulty4_button;
	Button difficulty5_button;
	Text tt;  
	Text tt1; 
	Text tt2;
	Text tt3; 
	Text tt4;
	Rectangle r;
	Rectangle r1;
	Rectangle r2;
	Rectangle r3;
	Rectangle r4;
	Image ii;
	Text t;  
	Text t1; 
	Text t2;
	Text t3; 
	Text t4;
	Text t5; 
	Text t6;
	
	Game* game;
	
	void dif1();
	void dif2();
	void dif3();
	void dif4();
	void dif5();
	static void cb_dif1(Address,Address pw);
	static void cb_dif2(Address,Address pw);
	static void cb_dif3(Address,Address pw);
	static void cb_dif4(Address,Address pw);
	static void cb_dif5(Address,Address pw);
	
};

struct StartWindow : Graph_lib::Window{
	StartWindow(Point xy,int x, int y, const string& title);
	bool disp();
	void init(Game* g);
	
	private:
	Button exit_button;
	Button start_button;
	Image i;
	Text t;  
	Text tt; 
	Text t1;
	Text t2;
	Text t3;
	Text t4;
	Text t5;
	Text t6;
	Text t7;
	Text t8;
	Text t9;
	Rectangle r;
	Rectangle r1;
	
	Game* game;
	
	void exit();
	void rules();
	static void cb_exit(Address,Address pw);
	static void cb_rules(Address,Address pw);
};

#endif
