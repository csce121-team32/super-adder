#include "../std_lib_facilities_4.h"
#include "../fltk/Simple_window.h"
#include "../fltk/Graph.h"

int main()
try {
	Window window(Point(100,200),600,400,"Window");
	
	win1.wait_for_button();
	return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
