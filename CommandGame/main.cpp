#include <iostream>
#include "Game.h"

using namespace std;

int main() {
	//Game game;
	//game.start();
	
	std::string s = "go north";
	std::string delimiter = " ";

	vector<string> temp = split(s, delimiter); // ["scott", "tiger", "mushroom"]

	for (string& line : temp) {
		cout << line << " ";
	}
}