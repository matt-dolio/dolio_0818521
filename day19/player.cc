#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unistd.h>
using namespace std;

const char EMPTY = '.', WALL = '#';
const char PLAYER1 = 'X', PLAYER2 = 'O';
const int ROWS = 30, COLS = 30;

void print_array(char arr[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

int main() {
	char arr[ROWS][COLS]; // 20 rows and 10 columns
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = EMPTY;
		}
	}
	int x = 0, y = 0;
	int vel_x = 0, vel_y = 0;
	cout << "Please enter x, y starting location:\n";
	cin >> x >> y;
	cout << "Please enter vel_x, vel_y starting values:\n";
	cin >> vel_x >> vel_y;
	if (!cin) exit(0);
	while (true) {
		arr[y][x] = EMPTY;
		x += vel_x;
		y += vel_y;
		if (x >= COLS) {
			int overshoot = x - (COLS-1);
			x = COLS-1-overshoot;
			vel_x *= -1;
		}
		if (y >= ROWS) {
			int overshoot = y - (ROWS-1);
			y = ROWS-1;
			vel_y *= -1;
		}
		if (x < 0) {
			x = -x;
			vel_x *= -1;
		}
		if (y < 0) {
			y = -y;
			vel_y *= -1;
		}
		arr[y][x] = WALL;
		system("clear");
		print_array(arr);
		usleep(100'000);
	}
}
