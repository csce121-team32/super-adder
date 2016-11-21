#include "std_lib_facilities_4.h"
#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"


struct Splash1_window : Graph_lib::Window 	
{
	private:
		Button difficulty1_button;
		Button difficulty2_button;
		Button difficulty3_button;
		Button difficulty4_button;
		Button difficulty5_button;
		Text tt{Point{60,355},"Easy Adder"};  
		Text tt1{Point{180,355},"Medium Adder"}; 
		Text tt2{Point{310,355},"Hard Adder"};
		Text tt3{Point{430,355},"Extra-Hard Adder"}; 
		Text tt4{Point{577,355},"Super-Hard Adder"};
		Rectangle r{Point{50,340}, 100, 25};
		Rectangle r1{Point{175,340}, 100, 25};
		Rectangle r2{Point{300,340}, 100, 25};
		Rectangle r3{Point{425,340}, 125, 25};
		Rectangle r4{Point{575,340}, 125, 25};
		Image ii{Point{0,0},"background1.jpg"};
		Text t{Point{25,50},"How to play:"};  
		Text t1{Point{250,25},"To begin the game, choose a difficulty. You will be given "}; 
		Text t2{Point{250,50},"a certain amount of tiles based on the difficulty you choose."};
		Text t3{Point{250,75},"These tiles will consist of +,-,/,* or 1-9, chosen at random."}; 
		Text t4{Point{250,100},"Arrange these tiles in proper order to generate the highest"};
		Text t5{Point{250,125},"score possible. Invalid order of tiles will result in a score "}; 
		Text t6{Point{250,150},"of zero for that round."};
		void dif1(){
		}
		void dif2(){
		}
		void dif3(){
		}
		void dif4(){
		}
		void dif5(){
		}
		static void cb_dif1(Address,Address pw){
		reference_to<Splash1_window>(pw).dif1();
		}		
		static void cb_dif2(Address,Address pw){
		reference_to<Splash1_window>(pw).dif2();
		}
		static void cb_dif3(Address,Address pw){
		reference_to<Splash1_window>(pw).dif3();
		}		
		static void cb_dif4(Address,Address pw){
		reference_to<Splash1_window>(pw).dif4();
		}
		static void cb_dif5(Address,Address pw){
		reference_to<Splash1_window>(pw).dif5();
		}		
	public:
    Splash1_window(Point xy,int w,int h,const string& title):Graph_lib::Window{xy,w,h,title},
	difficulty1_button{Point(50,340), 100, 25, "3 tiles",cb_dif1},
	difficulty2_button{Point(175,340), 100, 25, "4 tiles",cb_dif2},
	difficulty3_button{Point(300,340), 100, 25, "5 tiles",cb_dif3},
	difficulty4_button{Point(425,340), 125, 25, "6 tiles",cb_dif4},
	difficulty5_button{Point(575,340), 125, 25, "7 tiles",cb_dif5}
	{
	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(40);
	t1.set_font_size(17);
	t2.set_font_size(17);
	t3.set_font_size(17);
	t4.set_font_size(17);
	t5.set_font_size(17);
	t6.set_font_size(17);
	attach(difficulty1_button);
	attach(difficulty2_button);
	attach(difficulty3_button);
	attach(difficulty4_button);
	attach(difficulty5_button);
	attach(ii);
	attach(t);
	attach(t1);
	attach(t2);
	attach(t3);
	attach(t4);
	attach(t5);
	attach(t6);
	attach(r);
	attach(r1);
	attach(r2);
	attach(r3);
	attach(r4);
	attach(tt);
	attach(tt1);
	attach(tt2);
	attach(tt3);
	attach(tt4);
    }

			
};

Splash1_window win1(Point(100,100),700,500,"Directions");
struct Splash_window : Graph_lib::Window 	
{
	private:
		Button exit_button;
		Button start_button;
		Image i{Point{0,0},"background.jpg"};
		Text t{Point{50,150},"SUPER"};  
		Text tt{Point{600,150},"ADDER"}; 
		Text t1{Point{760,200},"Group Members:"};
		Text t2{Point{760,240},"Kevin Etheridge"};
		Text t3{Point{760,280},"Bo Corman"};
		Text t4{Point{760,320},"Unknown"};
		Text t5{Point{100,250},"Team:"};
		Text t6{Point{100,350},"Lich"};
		Text t7{Point{100,450},"Kings"};
		Text t8{Point{90,610},"Start"};
		Text t9{Point{x_max()-50,15},"Exit"};
		Rectangle r{Point{75,550}, 125, 100};
		Rectangle r1{Point{x_max()-75,0}, 70, 20};
		
		void exit(){
			hide();
		}
		void rules(){
			hide();
			win1.show();
		}
		static void cb_exit(Address,Address pw){
		reference_to<Splash_window>(pw).exit();
		}		
		static void cb_rules(Address,Address pw){
		reference_to<Splash_window>(pw).rules();}
	public:
    Splash_window(Point xy,int w,int h,const string& title):Graph_lib::Window{xy,w,h,title},
	exit_button{Point(x_max()-75,0), 70, 20, "EXIT",cb_exit},
	start_button{Point(75,550), 125, 100, "START",cb_rules}
	{
	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(100);
	tt.set_font(Graph_lib::Font::times_bold);
	tt.set_font_size(100); 
	t5.set_font(Graph_lib::Font::times_bold);
	t5.set_font_size(50);
	t6.set_font(Graph_lib::Font::times_bold);
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
	attach(t3);
	attach(t4);
	attach(t5);
	attach(t6);
	attach(t7);
	attach(t8);
	attach(t9);
	attach(r);
	attach(r1);
    }

			
};
Splash_window win(Point(50,50), 1000, 700, "Best Game EVER");
int main()
try {
	win1.hide();
	return gui_main();
   	                           
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}