#include "../std_lib_facilities_4.h"
#include "HS_list_manip.h"
#include "../fltk/Simple_window.h"
#include "../fltk/Graph.h"
#include "Player.h"

//This function creates a vector of players from a file called
//in.txt
vector<Player> load_file_scores() {
	vector<Player> Players;

	fstream iost{ "in.txt" , ios_base::in };
	if (!iost) error("can't open input file, in.txt");

	Player player("", 0, 0);

	while (iost >> player) {
		Players.push_back(player);
	}

	return Players;
}
//--------------------------------------------------------------

//This function takes the Players that were loader from the file and sorts
//all players from the indicated difficulty in the parameter then it 
//returs a sorted array of players for that difficulty
vector<Player> sort_scores(int difficulty, vector<Player> Players) {

	//This part is used to sort players by their score instead of their name
	struct {
		bool operator()(Player& a, Player& b) {
			return a.Player::get_score() > b.Player::get_score();
		}
	} customLess;
	//----------------------------------------------------------------------

	//This part makes a new vector to sort based on the difficulty
	//the player is pushed back if the players difficulty matches the 
	//difficulty from the sort_scores parameter
	vector<Player> to_sort;
	for (auto i : Players) {
		if (i.get_difficulty() == difficulty) {
			to_sort.push_back(i);
		}
	}

	//uses sort algorithm to sort the to_sort vector
	std::sort(to_sort.begin(), to_sort.end(), customLess);

	//resizes the vector to top 5 
	if (to_sort.size() > 5) {
		to_sort.resize(5);
	}
	return to_sort; // 
}
//----------------------------------------------------------------------

//This part pushes back a new player to the vector of players if the initials arent "" (blank)
//It then sorts the vector of players with the new player included and 
//updates the file that holds all the scores
void update_scores(string p_initials, double p_score, int p_difficulty, vector<Player> Players) {
	fstream iost{ "in.txt",ios_base::out };
	if (!iost) error("can't open output file, out.txt");
	if (p_initials != "") {
		Player p(p_initials, p_score, p_difficulty);
		Players.push_back(p);
	}
	for (int j = 7; j >2; j--) {
		vector<Player> temp_player = sort_scores(j, Players);
		for (auto i : temp_player) {
			string initials = i.get_initials();
			int score = i.get_score();
			int difficulty = i.get_difficulty();
			iost << initials << "\t" << score << "\t" << difficulty << "\r\n";
		}
		iost << "\r\n";
	}
	iost.close();
}
//--------------------------------------------------------------------------

//This function shows the scores for a certain difficulty followed by 
//A players initials after all the scores
void display_scores(int difficulty, string initials, double score) {
	string label = "HIGH SCORES FOR DIFFICULTY LEVEL " + to_string(difficulty);
	Simple_window w{ Point(50,50),400,600, label };
	vector<Player> list;
	list = sort_scores(difficulty);
	Vector_ref<Text> scores_out;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < list.size(); j++) {
			if (i == 0) {
				scores_out.push_back(new Text(Point(i * 50 + 100, j * 50 + 25), list[j].get_initials()));
			}
			else if (i == 1) {
				ostringstream int_string_score;
				int_string_score << list[j].get_score();
				scores_out.push_back(new Text(Point(i * 50 + 200, j * 50 + 25), int_string_score.str()));
			}
			else {};
			w.attach(scores_out[scores_out.size() - 1]);
		}
	}

	if (initials != "") {
		Text p_initials(Point(100, list.size() * 50 + 25), initials);
		w.attach(p_initials);

		if (score != -9999.0) {
			ostringstream int_to_string;
			int_to_string << score;
			Text final_score(Point(250, list.size() * 50 + 25), int_to_string.str());
			w.attach(final_score);
			w.wait_for_button();
		}
		else if (score == -9999.0) {
			Text unknown_score(Point(250, list.size() * 50 + 25), "???");
			w.attach(unknown_score);
			w.wait_for_button();
		}
		
	}
	else if (initials == "") {
		w.wait_for_button();
	}
	else {};
}
