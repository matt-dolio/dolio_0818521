#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//Set some global constants
const size_t SIZE = 10;
const char OPEN = '.';
const char WALL = '#';
const int WALL_PERCENTAGE = 15;
const char TREASURE = '$';
const int TREASURE_PERCENTAGE = 35;

void die() {
	cout << "BAD INPUT!\n";
	exit(1);
}

//Returns a number from 1 to 100
int roll() {
	return rand() % 100 + 1;
}

void print_map(const vector<vector char>> &map) {
	for (size_t i = 0; i < map.size(); i++) {
		for (size_t j = 0; j < map.size(); j++) {
			cout << map.at(i).at(j);
		}
		cout << endl;
	}
}

int main() {
	//Set a random seed for the random world below
	cout << "Please enter a random seed:\n";
	int seed = 0;
	cin >> seed;
	if (!cin) die();
	srand(seed); 

	//Create a random world based on this seed
	vector<vector<char>> field(SIZE);
	for (size_t i = 0; i < field.size(); i++) field.at(i).resize(SIZE);

	for (size_t i = 0; i < field.size(); i++) {
		for (size_t j = 0; j < field.size(); j++) {
			if (WALL_PERCENTAGE >= roll()) 
				field.at(i).at(j) = WALL;
			else if (TREASURE_PERCENTAGE >= roll()) 
				field.at(i).at(j) = TREASURE;
			else
				field.at(i).at(j) = OPEN;
		}
	}
	print_map(field);

	//Now place the hero on the map
	cout << "Where would you like to start? Type in a row and column:\n";
	size_t row = 0, col = 0;
	cin >> row >> col;
	if (!cin) die();
	if (field.at(row).at(col) == WALL) {
		cout << "Your hero appears inside a wall and dies. Game over!\n";
		exit(0);
	}
	else if (field.at(col).at(row) == TREASURE) {
		cout << "Your hero appears inside a treasure chest and dies. Game over!\n";
		exit(0);
	}
	else 
		cout << "That spot is valid. The game now begins!\n";
	//TODO Finish this RPG...
}

