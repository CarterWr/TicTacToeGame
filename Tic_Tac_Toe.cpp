#include <iostream>
#include <vector>
#include "functions.h"
using namespace std;

int main() {

	intro();//The intro to the program
	
	
	
	if (how_many_players()) {

		game_start_players_1();//runs the game for 1 player

	}
	else if (!how_many_players()) {

		game_start_players_2();//runs the game for 2 players

	}

	


	return 0;
}