#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unistd.h>
using namespace std;

const char EMPTY    = '.';
const char WALL     = '#';
const char PLAYER1  = 'X';
const char PLAYER2  = 'O';
const char FIREWORK = '*';
const int ROWS      = 10;
const int COLS      = 10;
const int WIN       = 5;
// int wall_trap = -1;

void print_array(char arr[ROWS][COLS]) {
	// Will draw a WALL above the world
	for (int i = 0; i < COLS+2; i++) {
		cout << WALL;
	}
	cout << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (j == 0) cout << WALL;
			cout << arr[i][j];
			if (j == COLS-1) cout << WALL;
		}
		cout << endl;
	}
	// Will draw a WALL below the world
	for (int i = 0; i < COLS+2; i++) {
		cout << WALL;
	}
	cout << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (j == 0) cout << WALL;
			cout << arr[i][j];
			if (j == COLS-1) cout << WALL;
		}
		cout << endl;
	}
}

void refresh(char arr[ROWS][COLS]) {
	system("clear");
	print_array(arr);
	// usleep(250'000); // 4 fps
}

int main() {
	char arr[ROWS][COLS];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = EMPTY;
		}
	}
	bool first_player = true;
	int moves = 0;
	while (true) {
		// do some stuff, this isn't the starter code so i gave up
	}

}
