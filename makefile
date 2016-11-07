all:
	g++ -std=c++17 *.cpp game/*.cpp graphics/*.cpp scores/*.cpp tile/*.cpp fltk/*.cpp -lfltk -lfltk_images -o "super-adder.out"
