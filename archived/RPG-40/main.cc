#include "map.h"
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const int MAX_FPS = 60; //Cap frame rate
const unsigned int TIMEOUT = 10; //Milliseconds to wait for a getch to finish
const int UP = 65; //Key code for up arrow
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;

/*
	Quick key for MAP class constants
	Map::HERO == 'H';
	Map::MONSTER == 'M';
	Map::WALL == '#';
	Map::WATER == '~';
	Map::OPEN == '.';
	Map::TREASURE == '$';
*/


/*

 _   _ _____ _     _     ___    _____ _   _ _____ ____  _____ _
| | | | ____| |   | |   / _ \  |_   _| | | | ____|  _ \| ____| |
| |_| |  _| | |   | |  | | | |   | | | |_| |  _| | |_) |  _| | |
|  _  | |___| |___| |__| |_| |   | | |  _  | |___|  _ <| |___|_|
|_| |_|_____|_____|_____\___/    |_| |_| |_|_____|_| \_\_____(_)

- If you're looking for the storybuilding, exit vim (reminder: shift+zz) and type
	
	% cat STORY

- I hope you enjoy my game!

*/


//Turns on full screen text mode
void turn_on_ncurses() {
	initscr();//Start curses mode
	start_color(); //Enable Colors if possible
	init_pair(1, COLOR_WHITE, COLOR_BLACK); //Set up some color pairs
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_BLUE, COLOR_BLACK);
	init_pair(8, COLOR_GREEN, COLOR_BLACK);
	clear();
	noecho();
	cbreak();
	timeout(TIMEOUT); //Set a max delay for key entry
}

//Exit full screen mode - also do this if you ever want to use cout or gtest or something
void turn_off_ncurses() {
	clear();
	endwin(); // End curses mode
	system("clear");
}

void player_died() {
	endwin();
	system("clear");
	system("figlet YOU DIED!");
	cout << "\nThe hero has fallen in the heat of battle.\n";
	cout << "Unable to go on, the wise men of Egaria were\n";
	cout << "left defenseless and the kingdom fell to\n";
	cout << "corruption. GAME OVER!\n";
	exit(0);
}

void player_won() {
	endwin();
	system("clear");
	system("figlet YOU WON!");
	cout << "\nThe hero, having gone through many trials\n";
	cout << "and tribulations, fought off several monsters\n";
	cout << "and solved the wise men's riddles, allowing\n";
	cout << "the corruption to be put to an end. The hero\n";
	cout << "was pardoned for his crimes, and sought to lead\n";
	cout << "a better, sober life after his experience in the\n";
	cout << "field. He would go on to become one of St. Linpus'\n";
	cout << "head guards and swear to protect the kingdom to\n";
	cout << "the best of his ability. YOU WIN!\n";
	exit(0);
}

// IN: puzzle_step, gold
// OUT: puzzle_step, gold
int wise_man(int &puzzle_step, int &gold, int player_level) {
	endwin();
	system("clear");

	int puzzle_price;
	if (puzzle_step == 0) {
		cout << "Greetings, estranged traveler.\n";
		usleep(1000000);
		cout << "\nIt appears you need some assistance...\n";
		usleep(1000000);
		cout << "\nMyself and other wise men across the land\n";
		cout << "can resolve this conflict if you solve our\n";
		cout << "riddles. There will be a fee, so go fight\n";
		cout << "some monsters and gain experience along with\n";
		cout << "it. Speak to us once you are ready.\n";
		puzzle_step++;
		usleep(5000000);
		return 0;
	} else if (puzzle_step == 1) {
		cout << "Greetings, traveller. To unlock this first riddle,\n";
		cout << "you must first pay a fee of 10 gold. Unlock? (Y/N)\n";
		string input;
		cin >> input;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (true) {
			if (!cin) {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			} else if (input == "Y" or input == "y") {
				if (gold >= 10) {
					gold -= 10;
					while (true) {
						cout << "I am not alive, but I grow.\n";
						usleep(750000);
						cout << "I don't have lungs, but I need air.\n";
						usleep(750000);
						cout << "I don't have a mouth, but water kills me.\n";
						usleep(750000);
						cout << "\nWhat am I?\n";
						string answer;
						getline(cin, answer);
						if (!cin) {
							cout << "I don't think that's quite right, try again.\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							getline(cin, answer);
							continue;
						}
						transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
						if (answer == "FIRE") {
							cout << "Correct! We are one step closer to cleansing this land!\n";
							puzzle_step++;
							usleep(2000000);
							return 0;
						} else {
							cout << "Incorrect! Try again.\n";
							usleep(500000);
							continue;
						}

					}
				} else {
					cout << "You do not possess the necessary funds.\n";
					usleep(750000);
					cout << "Return once you have obtained more coin.\n";
					cout << "...\n";
					usleep(2000000);
					return 0;
				}
			} else if (input == "N" or input == "n") {
				cout << "I see. Well, return to me or find another of my kind\n";
				cout << "to pursue your end goal.\n";
				cout << "...\n";
				usleep(2000000);
				return 0;
			} else {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
	} else if (puzzle_step == 2) {
		cout << "Greetings, traveller. To unlock this second riddle,\n";
		cout << "you must first pay a fee of 35 gold. Unlock? (Y/N)\n";
		string input;
		cin >> input;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (true) {
			if (!cin) {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			} else if (input == "Y" or input == "y") {
				if (gold >= 35) {
					gold -= 35;
					while (true) {
						cout << "What runs around the whole yard without moving?\n";
						string answer;
						getline(cin, answer);
						if (!cin) {
							cout << "I don't think that's quite right, try again.\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							getline(cin, answer);
							continue;
						}
						transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
						if (answer == "FENCE" or answer == "A FENCE") {
							cout << "Correct! We are one step closer to cleansing this land!\n";
							puzzle_step++;
							usleep(2000000);
							return 0;
						} else {
							cout << "Incorrect! Try again.\n";
							usleep(500000);
							continue;
						}
					}
				} else {
					cout << "You do not possess the necessary funds.\n";
					usleep(750000);
					cout << "Return once you have obtained more coin.\n";
					cout << "...\n";
					usleep(2000000);
					return 0;
				}
			} else if (input == "N" or input == "n") {
				cout << "I see. Well, return to me or find another of my kind\n";
				cout << "to pursue your end goal.\n";
				cout << "...\n";
				usleep(2000000);
				return 0;
			} else {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
	} else if (puzzle_step == 3) {
		cout << "Greetings, traveller. To unlock the third riddle,\n";
		cout << "you must first pay a fee of 60 gold. Unlock? (Y/N)\n";
		string input;
		cin >> input;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (true) {
			if (!cin) {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			} else if (input == "Y" or input == "y") {
				if (gold >= 60) {
					gold -= 60;
					while (true) {
						cout << "What can you catch but never throw?\n";
						string answer;
						getline(cin, answer);
						if (!cin) {
							cout << "I don't think that's quite right, try again.\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							getline(cin, answer);
							continue;
						}
						transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
						if (answer == "COLD" or answer == "A COLD" or answer == "FLU" or answer == "THE FLU") {
							cout << "Correct! We are one step closer to cleansing this land!\n";
							puzzle_step++;
							usleep(2000000);
							return 0;
						} else {
							cout << "Incorrect! Try again.\n";
							usleep(500000);
							continue;
						}
					}
				} else {
					cout << "You do not possess the necessary funds.\n";
					usleep(750000);
					cout << "Return once you have obtained more coin.\n";
					cout << "...\n";
					usleep(2000000);
					return 0;
				}
			} else if (input == "N" or input == "n") {
				cout << "I see. Well, return to me or find another of my kind\n";
				cout << "to pursue your end goal.\n";
				cout << "...\n";
				usleep(2000000);
				return 0;
			} else {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
	} else if (puzzle_step == 4) {
		cout << "Greetings, traveller. To unlock the fourth riddle,\n";
		cout << "you must first pay a fee of 110 gold. Unlock? (Y/N)\n";
		string input;
		cin >> input;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (true) {
			if (!cin) {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			} else if (input == "Y" or input == "y") {
				if (gold >= 110) {
					gold -= 110;
					while (true) {
						cout << "You can see it everyday, ";
						usleep(750000);
						cout << "but cannot touch it at will.\n";
						usleep(750000);
						cout << "\nWhat is it?\n";
						string answer;
						getline(cin, answer);
						if (!cin) {
							cout << "I don't think that's quite right, try again.\n";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							getline(cin, answer);
							continue;
						}
						transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
						if (answer == "SKY" or answer == "THE SKY") {
							cout << "Correct! We are one step closer to cleansing this land!\n";
							puzzle_step++;
							usleep(2000000);
							return 0;
						} else {
							cout << "Incorrect! Try again.\n";
							usleep(500000);
							continue;
						}
					}
				} else {
					cout << "You do not possess the necessary funds.\n";
					usleep(750000);
					cout << "Return once you have obtained more coin.\n";
					cout << "...\n";
					usleep(2000000);
					return 0;
				}
			} else if (input == "N" or input == "n") {
				cout << "I see. Well, return to me or find another of my kind\n";
				cout << "to pursue your end goal.\n";
				cout << "...\n";
				usleep(2000000);
				return 0;
			} else {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
	} else if (puzzle_step == 5) {
		cout << "Greetings, traveller. To unlock this final riddle,\n";
		cout << "you must be at least level 4 and pay 150 gold. Surely\n";
		cout << "you can meet those requirements. Unlock riddle? (Y/N)\n";
		string input;
		cin >> input;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (true) {
			if (!cin) {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			} else if (input == "Y" or input == "y") {
				if (gold >= 150) {
					if (player_level >= 4) {
						gold -= 150;
						while (true) {
							cout << "What are two things you can never eat for breakfast?\n";
							string answer;
							getline(cin, answer);
							if (!cin) {
								cout << "I don't think that's quite right, try again.\n";
								cin.clear();
								cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								getline(cin, answer);
								continue;
							}
							transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
							if (answer == "LUNCH AND DINNER" or answer == "DINNER AND LUNCH" or answer == "LUNCH DINNER" or answer == "DINNER LUNCH") {
								cout << "Correct! We've completed the trials! We can eradicate this monster!\n";
								puzzle_step++;
								usleep(2000000);
								return 0;
							} else {
								cout << "Incorrect! Try again.\n";
								usleep(500000);
								continue;
							}
						}
					} else {
						cout << "You have the funds, but you aren't skilled enough!\n";
						usleep(750000);
						cout << "Return once you have gained more experience. (Level 4)\n";
						cout << "...\n";
						usleep(2000000);
						return 0;
					}
				} else {
					cout << "You do not possess the necessary funds.\n";
					usleep(750000);
					cout << "Return once you have obtained more coin.\n";
					cout << "...\n";
					usleep(2000000);
					return 0;
				}
			} else if (input == "N" or input == "n") {
				cout << "I see. Well, return to me or find another of my kind\n";
				cout << "to pursue your end goal.\n";
				cout << "...\n";
				usleep(2000000);
				return 0;
			} else {
				cout << "I didn't quite get that. Unlock riddle? (Y/N)\n";
				cin >> input;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
	} else {
		cout << "I can not offer any more wisdom.\n";
		usleep(2000000);
		return 0;
	}

	return 0;
}

// IN: gold
// OUT: gold
int merchant(int &gold) {

	endwin();
	system("clear");

	cout << "Welcome to my shop, traveller!\n";

	string input;
	int item_gen = rand() % 34;
	string sale_item;
	int sale_price;
	switch (item_gen) {
	case 0:
		sale_item = "some dingy bag I found on the side of the road";
		sale_price = 8;
		break;
	case 1:
		sale_item = "an original mint copy of Action Comics #1";
		sale_price = 678351;
		break;
	case 2:
		sale_item = "Rush's \"Roll the Bones\" on vinyl";
		sale_price = 145;
		break;
	case 3:
		sale_item = "a week-old cheddar cheese bagel from Uncle Harry's";
		sale_price = 3;
		break;
	case 4:
		sale_item = "a banana peel I pulled from the trash bin outside a tavern";
		sale_price = 2;
		break;
	case 5:
		sale_item = "a three-legged kitten";
		sale_price = 78;
		break;
	case 6:
		sale_item = "an 8-track tape of The Clash's \"London Calling\"";
		sale_price = 1979;
		break;
	case 7:
		sale_item = "some groucho glasses";
		sale_price = 45;
		break;
	case 8:
		sale_item = "a jar of coconut oil";
		sale_price = 21;
		break;
	case 9:
		sale_item = "a small coffee from 7-Eleven";
		sale_price = 12;
		break;
	case 10:
		sale_item = "a knife (made of foam)";
		sale_price = 23;
		break;
	case 11:
		sale_item = "an empty bottle of Jim Beam";
		sale_price = 5;
		break;
	case 12:
		sale_item = "a porcelain plate with a large chunk broken off";
		sale_price = 12;
		break;
	case 13:
		sale_item = "a \"Live, Laugh, Love\" poster";
		sale_price = 14;
		break;
	case 14:
		sale_item = "a cinder block";
		sale_price = 23;
		break;
	case 15:
		sale_item = "a playing card with a weird stain on it";
		sale_price = 7;
		break;
	case 16:
		sale_item = "a box of various locks of hair";
		sale_price = 43;
		break;
	case 17:
		sale_item = "a bloody leather glove with a finger in it";
		sale_price = 23;
		break;
	case 18:
		sale_item = "a single snake-skin boot, size 2";
		sale_price = 90;
		break;
	case 19:
		sale_item = "an open box of paper toilet seat covers, gently used";
		sale_price = 2;
		break;
	case 20:
		sale_item = "2 pennies";
		sale_price = 5;
		break;
	case 21:
		sale_item = "Slash's tophat";
		sale_price = 69;
		break;
	case 22:
		sale_item = "a computer that can't run DOOM";
		sale_price = 666;
		break;
	case 23:
		sale_item = "a plastic lightsaber that's stuck open";
		sale_price = 420;
		break;
	case 24:
		sale_item = "a tomato that will never rot (it's plastic)";
		sale_price = 28;
		break;
	case 25:
		sale_item = "a watch that's "s + to_string(rand() % 12 + 1) + " hours and " + to_string(rand() % 59 + 1) + " minutes off";
		sale_price = 56;
		break;
	case 26:
		sale_item = "a bottle of Head & Shoulders";
		sale_price = 22;
		break;
	case 27:
		sale_item = "a small pile of neatly folded clothes";
		sale_price = 43;
		break;
	case 28:
		sale_item = "a rubber band ball";
		sale_price = 60;
		break;
	case 29:
		sale_item = "dull sandpaper";
		sale_price = 8;
		break;
	case 30:
		sale_item = "a Playstation 2 Slim";
		sale_price = 2008;
		break;
	case 31:
		sale_item = "a bag of mexican-style shredded cheese of unknown age";
		sale_price = 45;
		break;
	case 32:
		sale_item = "a thermostat";
		sale_price = 132;
		break;
	case 33:
		sale_item = "a handful of chocolate chips that have been in my pocket for a while";
		sale_price = 12;
		break;
	}
	cout << "I'm selling " << sale_item << " for " << sale_price << " gold.\n";
	cout << "Would you like to buy? (Y/N)" << endl;
	cin >> input;
	while (true) {
		if (!cin) {
			cout << "I didn't quite get that. Would you like to buy? (Y/N)\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> input;
			continue;
		} else if (input == "Y" or input == "y") {
			if (sale_price > gold) {
				cout << "You don't have enough money! Cheapskate!\n\n";
				usleep(2000000);
				return 0;
			} else {
				cout << "Thanks for your money! Nyeheheh\n";
				gold -= sale_price;
				usleep(2000000);
				return 0;
			}
		} else if (input == "N" or input == "n") {
			cout << "Fine then! See if I care.\n";
			usleep(2000000);
			return 0;
		} else {
			cout << "I don't know what you mean. Would you like to buy? (Y/N)\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> input;
			continue;
		}
	}

	return 0;
}

// IN: player_health, player_level
// OUT: player_health
bool battle(int &player_health, int player_level) {

	bool win_battle = false, fled = false;
	int enemy_health = rand() % 8 + 12; // 12-20 health

	endwin();
	system("clear");

	cout << "You faced a monster! What will you do?\n";
	cout << "Attack (1), Defend (2), or Flee (3) [20% chance]\n";
	int input;
	cin >> input;

	while (enemy_health > 0) {
		bool defending = false;
		if (!cin) {
			cout << "I didn't quite get that. Try again!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> input;
			continue;
		} else if (input == 1) {
			bool crit = ((rand() % 100 + 1) > 90); // 10% chance of crit
			int attack = rand() % 4 + 1; // 1-4 damage base
			if (crit) {
				enemy_health -= (attack + player_level) * 2;
				cout << "CRITICAL! Hit for " << (attack + player_level) * 2 << " damage. Enemy has " << enemy_health << " health left.\n";
			} else {
				enemy_health -= attack + player_level;
				cout << "Hit for " << attack + player_level << " damage. Enemy has " << enemy_health << " health left.\n";
			}
		} else if (input == 2) {
			defending = true;
		} else if (input == 3) {
			bool succeed = ((rand() % 100 + 1) > 80);
			if (succeed) {
				cout << "You escaped!" << endl;
				win_battle = true;
				break;
			} else {
				cout << "You failed to escape!" << endl;
			}
		} else {
			cout << "That is not an option, try again.\n";
			cin >> input;
			continue;
		}

		if (enemy_health < 1) {
			win_battle = true;
			cout << "You killed the monster!" << endl;
			break; // break before enemy gets to attack if it's dead.
		}
		int enemy_attack = rand() % 3 + 1;
		if (defending) {
			player_health -= enemy_attack / 2;
			cout << "Enemy did " << enemy_attack / 2 << " damage! You have " << player_health << " health left\n";
		} else {
			player_health -= enemy_attack;
			cout << "Enemy did " << enemy_attack << " damage! You have " << player_health << " health left\n";
		}

		if (player_health <= 0) {
			win_battle = false;
			break;
		}

		cout << "Attack (1), Defend (2), or Flee (3) [20% chance]\n";
		cin >> input;
	}

	if (win_battle) {
		usleep(2000000);
		return true;
	} else return false;
}


int main() {
	srand(time(0)); // Seed random number generator
	turn_on_ncurses();
	Map map;
	int gold = 0, health = 20, experience = 0, player_level = 1, puzzle_step = 0;
	int x = Map::SIZE / 2, y = Map::SIZE / 2; //Start in middle of the world
	int old_x = -1, old_y = -1;
	while (true) {
		int ch = getch(); // Wait for user input, with TIMEOUT delay
		if (ch == 'q' || ch == 'Q') break;
		else if (ch == RIGHT) {
			/*
				Quick note for the future:
				I tried checking map.map.at(y).at(x) using y--/y++, etc
				This causes double movement and no collision detection
				due to y--/y++ being shorthand for y-=1/y+=1, which
				is similar to a logic error of if (y = 1) setting y to 1.
			 */
			if (map.map.at(y).at(x + 1) == Map::TREASURE) {
				map.map.at(y).at(x + 1) = Map::OPEN;
				x++;
				gold += rand() % 4 + 1;
			} else if (map.map.at(y).at(x + 1) == Map::OPEN or map.map.at(y).at(x + 1) == Map::WATER) x++;
			else if (map.map.at(y).at(x + 1) == Map::MONSTER) {
				bool result = battle(health, player_level);
				if (result) { // You won
					experience += 10;
					gold += 10;
					map.map.at(y).at(x + 1) = Map::OPEN;
					clear();
					map.draw(x, y);
					refresh();
				} else { // Lol u died
					player_died();
				}
			} else if (map.map.at(y).at(x + 1) == Map::HEALTH) {
				map.map.at(y).at(x + 1) = Map::OPEN;
				x++;
				health += 3;
				if (health > 20) health = 20; // clamp
			} else if (map.map.at(y).at(x + 1) == Map::MERCHANT) {
				int result = merchant(gold);
				if (result == 0) { // should be always
					clear();
					map.draw(x, y);
					refresh();
				}
			} else if (map.map.at(y).at(x + 1) == Map::WISE_MAN) {
				int result = wise_man(puzzle_step, gold, player_level);
				if (result == 0) {
					clear();
					map.draw(x, y);
					refresh();
				}
			}

			if (y >= Map::SIZE) y = Map::SIZE - 1; //Clamp value
		} else if (ch == LEFT) {
			if (map.map.at(y).at(x - 1) == Map::TREASURE) {
				map.map.at(y).at(x - 1) = Map::OPEN;
				x--;
				gold += rand() % 4 + 1;
			} else if (map.map.at(y).at(x - 1) == Map::OPEN or map.map.at(y).at(x - 1) == Map::WATER) x--;
			else if (map.map.at(y).at(x - 1) == Map::MONSTER) {
				bool result = battle(health, player_level);
				if (result) { // You won
					experience += 10;
					gold += 10;
					map.map.at(y).at(x - 1) = Map::OPEN;
					clear();
					map.draw(x, y);
					refresh();
				} else { // Lol u died loser
					player_died();
				}
			} else if (map.map.at(y).at(x - 1) == Map::HEALTH) {
				map.map.at(y).at(x - 1) = Map::OPEN;
				x--;
				health += 3;
				if (health > 20) health = 20; // clamp
			} else if (map.map.at(y).at(x - 1) == Map::MERCHANT) {
				int result = merchant(gold);
				if (result == 0) {
					clear();
					map.draw(x, y);
					refresh();
				}
			} else if (map.map.at(y).at(x - 1) == Map::WISE_MAN) {
				int result = wise_man(puzzle_step, gold, player_level);
				if (result == 0) {
					clear();
					map.draw(x, y);
					refresh();
				}
			}

			if (y < 0) y = 0; //Clamp y
		} else if (ch == UP) {
			if (map.map.at(y - 1).at(x) == Map::TREASURE) {
				map.map.at(y - 1).at(x) = Map::OPEN;
				y--;
				gold += rand() % 4 + 1;
			} else if (map.map.at(y - 1).at(x) == Map::OPEN or map.map.at(y - 1).at(x) == Map::WATER) y--;
			else if (map.map.at(y - 1).at(x) == Map::MONSTER) {
				bool result = battle(health, player_level);
				if (result) { // You won
					experience += 10;
					gold += 10;
					map.map.at(y - 1).at(x) = Map::OPEN;
					clear();
					map.draw(x, y);
					refresh();
				} else { // Lol u died
					player_died();
				}
			} else if (map.map.at(y - 1).at(x) == Map::HEALTH) {
				map.map.at(y - 1).at(x) = Map::OPEN;
				y--;
				health += 3;
				if (health > 20) health = 20; // clamp
			} else if (map.map.at(y - 1).at(x) == Map::MERCHANT) {
				int result = merchant(gold);
				if (result == 0) {
					clear();
					map.draw(x, y);
					refresh();
				}
			} else if (map.map.at(y - 1).at(x) == Map::WISE_MAN) {
				int result = wise_man(puzzle_step, gold, player_level);
				if (result == 0) {
					clear();
					map.draw(x, y);
					refresh();
				}
			}

			if (x < 0) x = 0; // Clamp x
		} else if (ch == DOWN) {
			/*
				Quick note here:
				We moved map.map... to the top of the statement
				BEFORE y++ because then it was checking for the
				next value after already moving, which would in
				turn remove the wrong character from the board.
			*/
			if (map.map.at(y + 1).at(x) == Map::TREASURE) {
				map.map.at(y + 1).at(x) = Map::OPEN;
				y++;
				gold += rand() % 4 + 1;
			} else if (map.map.at(y + 1).at(x) == Map::OPEN or map.map.at(y + 1).at(x) == Map::WATER) y++;
			else if (map.map.at(y + 1).at(x) == Map::MONSTER) {
				bool result = battle(health, player_level);
				if (result) { // You won
					experience += 10;
					gold += 10;
					map.map.at(y + 1).at(x) = Map::OPEN;
					clear();
					map.draw(x, y);
					refresh();
				} else { // Lol u died
					player_died();
				}
			} else if (map.map.at(y + 1).at(x) == Map::HEALTH) {
				map.map.at(y + 1).at(x) = Map::OPEN;
				y++;
				health += 3;
				if (health > 20) health = 20; // clamp
			} else if (map.map.at(y + 1).at(x) == Map::MERCHANT) {
				int result = merchant(gold);
				if (result == 0) {
					clear();
					map.draw(x, y);
					refresh();
				}
			} else if (map.map.at(y + 1).at(x) == Map::WISE_MAN) {
				int result = wise_man(puzzle_step, gold, player_level);
				if (result == 0) {
					clear();
					map.draw(x, y);
					refresh();
				}
			}

			if (x >= Map::SIZE) x = Map::SIZE - 1; //Clamp value
		} else if (ch == ERR) { //No keystroke
			; //Do nothing
		}

		if (player_level == 0) player_level = 1;
		else if (experience >= 350) player_level = 6;
		else if (experience >= 280) player_level = 5;
		else if (experience >= 160) player_level = 4;
		else if (experience >= 90) player_level = 3;
		else if (experience >= 40) player_level = 2;

		// Game-winning code
		if (player_level == 6 and puzzle_step == 6) {
			player_won();
		}

		//	Stop flickering by only redrawing on a change
		if (x != old_x or y != old_y) {
			clear();
			map.draw(x, y);
			mvprintw(Map::DISPLAY + 1, 0, "X: %i | Y: %i\n", x, y);
			mvprintw(Map::DISPLAY + 2, 0, "Gold: %i | Health: %i | XP: %i | Level: %i\n", gold, health, experience, player_level);
			if (map.map.at(y).at(x) == Map::WATER) mvprintw(Map::DISPLAY + 3, 0, "You're swimming!");
			refresh();
		}
		old_x = x;
		old_y = y;
		usleep(1000000 / MAX_FPS);
	}
	turn_off_ncurses();
}
