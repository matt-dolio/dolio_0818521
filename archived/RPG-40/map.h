#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <ncurses.h>
using namespace std; //Boo hiss

class Map {
	public: vector<vector<char>> map;
	default_random_engine gen;
	public:
	static const char HERO     = 'H';
	static const char MONSTER  = 'M';
	static const char WALL     = '#';
	static const char WATER    = '~';
	static const char OPEN     = '.';
	static const char TREASURE = '$';
	static const char HEALTH   = '+';
	static const char MERCHANT = '@';
	static const char WISE_MAN = '?';
	static const size_t SIZE = 100; //World is a 100x100 map
	static const size_t DISPLAY = 30; //Show a 10x10 area at a time
	//Randomly generate map
	void init_map() {
		uniform_int_distribution<int> d100(1,100);
		map.clear();
		map.resize(SIZE); //100 rows tall
		for (auto &v : map) v.resize(SIZE,'.'); //100 columns wide
		for (size_t i = 0; i < SIZE; i++) {
			for (size_t j = 0; j < SIZE; j++) {
				//Line the map with walls
				if (i == 0 or j == 0 or i == SIZE-1 or j == SIZE-1) 
					map.at(i).at(j) = WALL;
			//	else if (i == SIZE/2 and j == SIZE/2) {}; 
					//map.at(i).at(j) = HERO;
				else {
					//1% chance of monster
					if (d100(gen) <= 1) {
						map.at(i).at(j) = MONSTER;
					} // 1% chance treasure
					else if (d100(gen) <= 1) {
						map.at(i).at(j) = TREASURE;
					} // 9% chance wall
					else if (d100(gen) <= 7) {
						map.at(i).at(j) = WALL;
					} // 20% chance wall near another wall
					else if (d100(gen) <= 20) {
						if (map.at(i-1).at(j) == WALL or map.at(i+1).at(j) == WALL or map.at(i).at(j-1) == WALL or map.at(i).at(j+1) == WALL)
							map.at(i).at(j) = WALL;
					} // 2% chance water
					else if (d100(gen) <= 2) { 
						map.at(i).at(j) = WATER;
					} // 35% chance water near another water (for pools or ponds)
					else if (d100(gen) <= 35) {
						if (map.at(i-1).at(j) == WATER or map.at(i+1).at(j) == WATER or map.at(i).at(j-1) == WATER or map.at(i).at(j+1) == WATER)
							map.at(i).at(j) = WATER;
					} // 2% chance health pack
					else if (d100(gen) <= 1) {
						map.at(i).at(j) = HEALTH;
					} // 1% chance MERCHANT
					else if (d100(gen) <= 1) {
						map.at(i).at(j) = MERCHANT;
					}
					else if (d100(gen) <= 1) {
						map.at(i).at(j) = WISE_MAN;
					}
				}
			}
		}
	}
	//Draw the DISPLAY tiles around coordinate (x,y)
	void draw(int x, int y) {
		int start_x = x - DISPLAY/2;
		int end_x = x + DISPLAY/2;
		int start_y = y - DISPLAY/2;
		int end_y = y + DISPLAY/2;

		//Bounds check to handle the edges
		if (start_x < 0) {
			end_x = end_x - start_x;
			start_x = 0;
		}
		if (end_x > SIZE-1) {
			start_x = start_x - (end_x - (SIZE-1));
			end_x = SIZE-1;
		}
		if (start_y < 0) {
			end_y = end_y - start_y;
			start_y = 0;
		}
		if (end_y > SIZE-1) {
			start_y = start_y - (end_y - (SIZE-1));
			end_y = SIZE-1;
		}

		//Now draw the map using NCURSES
		for (size_t i = start_y; i <= end_y; i++) {
			for (size_t j = start_x; j <= end_x; j++) {
				if (i == y && j == x) {
					attron(A_UNDERLINE | A_BOLD);
					mvaddch(i-start_y,j-start_x,'H');
					attroff(A_UNDERLINE | A_BOLD);
				}
				else {
					int color = 1;
					if (map.at(i).at(j) == WALL)
						color = 5;
					else if (map.at(i).at(j) == WATER)
						color = 2;
					else if (map.at(i).at(j) == HERO)
						color = 3;
					else if (map.at(i).at(j) == TREASURE)
						color = 4;
					else if (map.at(i).at(j) == MONSTER)
						color = 6;
					else if (map.at(i).at(j) == HEALTH)
						color = 7;
					else if (map.at(i).at(j) == MERCHANT)
						color = 8;
					else if (map.at(i).at(j) == WISE_MAN)
						color = 4;

					attron(COLOR_PAIR(color));
					mvaddch(i-start_y,j-start_x,map.at(i).at(j));
					attroff(COLOR_PAIR(color));
				}
			}
		}
	}
	Map() {
		init_map();
	}
};
