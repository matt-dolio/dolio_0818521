#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include "/public/colors.h"
using namespace std;

const char EMPTY = '.';
const char PLAYER1 = 'X', PLAYER2 = 'O', WALL = '#';
const int GRID_SIZE = 10;
const int ROWS = 20, COLS = 30, WIN = 5;

void print_array(char arr[ROWS][COLS]) {
	//Will draw a WALL above the world
	for (int i = 0; i < COLS+2; i++)
		cout << WALL;
	cout << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (j == 0) cout << WALL; //Right wall
			cout << arr[i][j];
			if (j == COLS-1) cout << WALL; //Right wall
		}
		cout << endl;
	}
	//Will draw a WALL below the world
	for (int i = 0; i < COLS+2; i++)
		cout << WALL;
	cout << endl;
}

void refresh(char arr[ROWS][COLS]) {
		system("clear");
		print_array(arr);
}

bool check_win(char arr[ROWS][COLS], char turn) {
	
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			
			// horiz check
			int in_a_row = 0;
			for (int k = 0; k < WIN; k++) {
				if ((i+k < ROWS) and (arr[i+k][j] == turn)) in_a_row++;
			}
			if (in_a_row >= WIN) return true;

			// verti
			in_a_row = 0;
			for (int k = 0; k < WIN; k++) {
				if ((j+k < COLS) and (arr[i][j+k] == turn)) in_a_row++;
			}
			if (in_a_row >= WIN) return true;

			// first diag
			in_a_row = 0;
			for (int k = 0; k < WIN; k++) {
				if ((i+k < ROWS) and (j+k < COLS) and (arr[i+k][j+k] == turn)) in_a_row++;
			}
			if (in_a_row >= WIN) return true;

			// second diag
			in_a_row = 0;
			for (int k = 0; k < WIN; k++) {
				if ((i-k >= 0) and (j+k < COLS) and (arr[i-k][j+k] == turn)) in_a_row++;
			}
			if (in_a_row >= WIN) return true;

		}
	}

	return false;
}

int main() {
	
	if (WIN > GRID_SIZE) {
		cout << "Some stupid programmer made it impossible to win, killing program...\n";
		exit(1);
	}

	int players = 0;
	//If players is 1, then the AI will play as O
	while (players < 1 or players > 2) {
		cout << "Do you want single player (1) or two player (2) mode?\n";
		cin >> players;
		if (!cin) exit(1);
	}
	int seed = 0;
	if (players == 1) { 
		cout << "Please enter the seed for the random number generator.\n";
		cin >> seed;
		if (!cin) exit(1);
	}

	char arr[ROWS][COLS]; //20 rows and 10 columns - SIKE
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = EMPTY; //Characters use single quotes, strings use double quotes
		}
	}
	//Human is always player 1 ('X')
	//AI is always player 2 ('O')
	bool first_player = true;
	int moves = 0;
	while (true) {
		int x = 0, y = 0;
		char turn = first_player ? PLAYER1 : PLAYER2;
		if (first_player or players == 2) {
			cout << "Please enter x,y location:\n";
			cin >> x >> y;
			if (!cin) exit(1);
			
			//YOU: Check for the spot being in bounds
			if (x < 0 or x >= COLS or y < 0 or y >= ROWS) continue; // bounds checking
			
			// Check if the spot is available for moving in
			if (arr[y][x] != EMPTY) continue;
			
			arr[y][x] = turn;
		}
		else {
			//YOU: Generate a random column and row using rand() modulus the row / column size
			int row_option = rand() % ROWS;
			int col_option = rand() % COLS;

			//YOU: If that spot is taken, continue
			if (arr[row_option][col_option] != EMPTY) continue;

			//YOU: Else, mark that spot with an O
			else arr[row_option][col_option] = PLAYER2;
		}
		refresh(arr);
		if (check_win(arr,turn)) {
			cout << "Player " << turn << " wins!\n";
			exit(0);
		}
		//YOU: Write code to check for a draw here
		if (false) {
			cout << "Game is a draw.\n";
			exit(0);
		}
		first_player = !first_player;
	}
}













