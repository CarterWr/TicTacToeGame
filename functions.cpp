#include "functions.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

bool singlePlayer = false;
string playersAmount;

vector<string> player_icons = { "X", "O" };
vector<string> grid = { " ", " ", " ", " ", " ", " ", " ", " ", " " };

int player1 = 0;
int player2 = 0;

string who_Won1 = "Player 1";
string who_Won2 = "Player 2";

bool winner = false;
bool bFilled = false;

int computer;



void intro() {//The intro sequence to game
	cout << "Press 'Enter' to start.\n";
	cin.ignore();

	

	cout << "==================\n";
	cout << " Tic Tac Toe Game \n";
	cout << "==================\n";
	cout << "\n";

	cout << "Instructions: This game will require 2 players.\n";
	cout << "To win you need to match 3 in a row of the same icon.\n";
	cout << "\n";

	cout << "Player 1: X\n";
	cout << "Player 2: O\n";
	cout << "\n";

	cout << "     |     |       \n";
	cout << "  1  |  2  |  3    \n";
	cout << "_____|_____|_____  \n";
	cout << "     |     |       \n";
	cout << "  4  |  5  |  6    \n";
	cout << "_____|_____|_____  \n";
	cout << "     |     |       \n";
	cout << "  7  |  8  |  9    \n";
	cout << "     |     |       \n";
	cout << "\n";

	cout << "Above is the example of what the grid is going to look like when you play\n";
	cout << "Each player must select a numer 1-9 to put there X when its player 1's turn and a O for player 2's turn.\n";

	cout << "\n";

	

	cout << "Press 'Enter' to move on to the game.\n";
	cin.ignore();

	new_line();

	cout << "Before we start this game how many players are there 1 or 2: "; cin >> playersAmount; cout << "\n";

	while (playersAmount != "1" && playersAmount != "2") {
		cout << "Please select 1 or 2 for the amount of players there is: "; cin >> playersAmount; cout << "\n";
	}
}

bool how_many_players() {

	if (playersAmount == "1") {
		singlePlayer = true;
	}
	else if (playersAmount == "2") {
		singlePlayer = false;
	}
	

	return singlePlayer;
}

void board_make() {

	std::cout << "     |     |      \n";

	std::cout << "  " << grid[0] << "  |  " << grid[1] << "  |  " << grid[2] << "\n";

	std::cout << "_____|_____|_____ \n";
	std::cout << "     |     |      \n";

	std::cout << "  " << grid[3] << "  |  " << grid[4] << "  |  " << grid[5] << "\n";

	std::cout << "_____|_____|_____ \n";
	std::cout << "     |     |      \n";

	std::cout << "  " << grid[6] << "  |  " << grid[7] << "  |  " << grid[8] << "\n";
	std::cout << "     |     |      \n";

}

void win_condition() {//its in the name it checks for wins 



	//rows
	if ((grid[0] == grid[1]) && (grid[1] == grid[2]) && grid[0] != " ") {
		win(0);

	}
	else if ((grid[3] == grid[4]) && (grid[4] == grid[5]) && grid[3] != " ") {
		win(3);
	}
	else if ((grid[6] == grid[7]) && (grid[7] == grid[8]) && grid[6] != " ") {
		win(6);
	}

	//collums
	if ((grid[0] == grid[3]) && (grid[3] == grid[6]) && grid[0] != " ") {
		win(0);
	}
	else if ((grid[1] == grid[4]) && (grid[4] == grid[7]) && grid[1] != " ") {
		win(1);
	}
	else if ((grid[2] == grid[5]) && (grid[5] == grid[8]) && grid[2] != " ") {
		win(2);
	}

	//across
	if ((grid[0] == grid[4]) && (grid[4] == grid[8]) && grid[0] != " ") {
		win(0);
	}
	else if ((grid[2] == grid[4]) && (grid[4] == grid[6]) && grid[2] != " ") {
		win(2);
	}

}

void game_start_players_1() {//this will iterate through the player and the computers turn
	
	srand(time(NULL));//sets seed for random num gen

	for (int i = 0; i < 5; i++) {
		

		cout << "\n";

		cout << "Player 1 its your turn please enter 1-9 to select your choice: "; cin >> player1; convert_player1(); cout << "\n";

		board_make();
		win_condition();
		board_filled();

		cout << "\n";
		//Player 2's turn
		cout << "\n";
		cout << "Computer's turn "; computer = (rand() % 9) + 1; cout << computer;  convert_computer(); cout << "\n";
		
		board_make();
		win_condition();
		board_filled();
		

		cout << "\n";


	}

}





void game_start_players_2() {
	

	for (int i = 0; i < 5; i++) {//iterates through both players turns
		//Player 1's turn

		cout << "\n";

		cout << "Player 1 its your turn please enter 1-9 to select your choice: "; cin >> player1; convert_player1(); cout << "\n";

		board_make();
		win_condition();
		board_filled();

		cout << "\n";
		//Player 2's turn
		cout << "\n";
		cout << "Player 2 its now your turn select your choice 1-9: "; cin >> player2; convert_player2(); cout << "\n";

		board_make();
		win_condition();
		board_filled();


		cout << "\n";


	}

}



void new_line() {//made to push away the instructioins to look cleaner
	for (int i = 0; i < 27; i++) {
		cout << "\n";
	}
}



void convert_player1() {//player 1s conversion

	checking_player_1();

	bool filled_1 = false;

	

	for (int i = 0; i < 9; i++) {

		//checks if the spot is filled if it is filled it sets filled to true
		if (grid[i] != " " && (grid[i] == "X" || grid[i] == "O")) {


			filled_1 = true;


		}
		else if (grid[i] == " ") {
			filled_1 = false;

		}

		
		
		//converting the player choice 1-9 to a X or O
		if (filled_1 == false && player1 == i + 1 && player2 != i + 1) {
			grid.at(i) = "X";



		}
		else if (filled_1 == true && player1 == i + 1) {

			for (int x = 9; x > 0; x--) {

				

				if (player1 == x ||player1 == i + 1) {

					cout << "\n";

					cout << "Space is filled, please select a new space: "; cin >> player1; cout << "\n";
				}
			}

			checking_player_1();
		}

	



	}



}


void convert_player2() {//Player 2s conversion

	checking_player_2();

	bool filled_2 = false;

	for (int i = 0; i < 9; i++) {

		//checks if the spot is filled if it is filled it sets filled to true
		if (grid[i] != " " && (grid[i] == "X" || grid[i] == "O")) {


			filled_2 = true;


		}
		else if (grid[i] == " ") {
			filled_2 = false;

		}

		

		//converting the player choice 1-9 to a X or O
		if (filled_2 == false && player2 == i + 1 && player1 != i + 1) {
			grid.at(i) = "O";

			return;


		} 
		else if (filled_2 == true && player2 == i + 1) {
			
			for (int x = 9; x > 0; x--) {

				if (player2 == x || player2 == i + 1) {

					cout << "\n";

					cout << "Space is filled, please select a new space: "; cin >> player2; cout << "\n";
				}
			}

			checking_player_2();
		}
		
		
		




	}

}

void convert_computer() {//computers conversion
	
	bool filled_comp = false;

	for (int i = 0; i < 9; i++) {

		//checks if the spot is filled if it is filled it sets filled to true
		if (grid[i] != " " && (grid[i] == "X" || grid[i] == "O")) {


			filled_comp = true;


		}
		else if (grid[i] == " ") {
			filled_comp = false;

		}

		

		//converting the player choice 1-9 to a X or O
		if (filled_comp == false && computer == i + 1 && player1 != i + 1) {
			grid.at(i) = "O";

			


		}
		else if (filled_comp == true && computer == i + 1) {

			for (int x = 9; x > 0; x--) {



				if (computer == x || computer == i + 1) {

					cout << "\n";

					computer = (rand() % 9) + 1;

					
				}
			}


			

		}
		

		



	}

}


void checking_player_1() {

	while (player1 > 9 || player1 < 1) {
		cout << "\n";

		cout << "You cannot exceed 9 or go below 1 please pick anouther spot: "; cin >> player1; cout << "\n";

	}


}

void checking_player_2() {

	while (player2 > 9 || player2 < 1) {
		cout << "\n";

		cout << "You cannot exceed 9 or go below 1 please pick anouther spot: "; cin >> player2; cout << "\n";
	}
}

void checking_comptuer() {

	while (computer > 9 || computer < 1) {
		cout << "\n";
		computer = (rand() % 9) + 1;
	}
	
}




void board_filled() {



	for (int i = 0; i < 9; i++) {



		if (grid[i] == " ") {
			
			bFilled = false;
			return;


		}
		else if (grid[i] != " ") {

			bFilled = true;
		}


	}


	tie();
	return;
}

void tie() {

	if (bFilled = true) {
		cout << "Its a Tie\n";
		exit(0);
	}

}




void win(int num) {



	if (grid[num] == "X") {
		cout << "\n" << who_Won1 << " Won\n";

		winner = true;

		exit(0);
	}
	else if (grid[num] == "O") {
		cout << "\n" << who_Won2 << " Won\n";

		winner = true;

		exit(0);
	}



}
