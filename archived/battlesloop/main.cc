#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 12;
int board[SIZE][SIZE] = {};

//Makes a bunch of constants for the letters to be printed on the board
enum tiles { CLEAR=0, DESTROYER, SUBMARINE, BATTLESHIP, AIRCRAFT_CARRIER, HIT, MISS };
int message = 0; //If a ship has been destroyed, it will be set to BATTLESHIP or whatever

//Holds how big each ship is
enum sizes { DESTROYER_SIZE=2, SUBMARINE_SIZE=3, BATTLESHIP_SIZE=4, AIRCRAFT_CARRIER_SIZE=5 };

void die() {
	cout << "Bad input!\n";
	exit(1);
}

void win(); //Function prototype, ends the game successfully
void lose(); //Ends the game with failure

void print_board() {
	system("clear");
	cout << "BATTLESLOOP 2000(tm)\n";
	//Print column headers
	cout << "\t";
	for (size_t i = 0; i < SIZE; i++)
		cout << i << "\t";
	cout << endl;
	//Print board
	for (size_t i = 0; i < SIZE; i++) {
		//Print row headers
		cout << i << "\t";
		for (size_t j = 0; j < SIZE; j++) {
			if (board[j][i] == CLEAR) cout << "." << "\t";
			else if (board[j][i] == DESTROYER) cout << "D" << "\t";
			else if (board[j][i] == SUBMARINE) cout << "S" << "\t";
			else if (board[j][i] == BATTLESHIP) cout << "B" << "\t";
			else if (board[j][i] == AIRCRAFT_CARRIER) cout << "A" << "\t";
			else if (board[j][i] == HIT) cout << "*" << "\t";
			else if (board[j][i] == MISS) cout << "X" << "\t";
			else die();
		}
		cout << endl;
	}
	if      (message == MISS) 		cout << "MISS!\n";
	else if (message == HIT) 		cout << "HIT!\n";
	else if (message == DESTROYER) 	cout << "You sank my destroyer!\n";
	else if (message == SUBMARINE)  cout << "You sank my submarine!\n";
	else if (message == BATTLESHIP) cout << "You sank my battleship!\n";
	else if (message == AIRCRAFT_CARRIER) cout << "You sank my aircraft carrier!\n";

	message = 0; //Clear the message so it doesn't display again.
}

int main() {
	cout << "Welcome to Battlesloop 2000(tm)\n";
	cout << "Press any key and hit enter to continue.\n";
	getchar();

	int destroyer_pieces=2, submarine_pieces=3, battleship_pieces=4, aircraft_carrier_pieces=5;

	//PHASE 1 - Set up the ships on the board
	// Destroyer
	print_board();
	cout << "Please insert the (x,y) starting location for the destroyer:\n";
	int x=0,y=0;
	cin >> x >> y;
	if (!cin) die();
	//YOU: Error check the coordinates
	if (x >= SIZE or x < 0 or y >= SIZE or y < 0) die();
	cout << "Is the destroyer vertical (v) or horizontal (h)?\n";
	char c = 0;
	cin >> c;
	if (!cin) die();
	if (c == 'v') { //If vertical, we start at the top and go down
		for (int i = 0; i < DESTROYER_SIZE; i++) {
			if (x < SIZE and y < SIZE and board[x][y] == CLEAR) {
				board[x][y] = DESTROYER;
				y++;
			}
			else die();
		}
	}
	else if (c == 'h') {
		//YOU: Do the same for a horizontal ship
		for (int i = 0; i < DESTROYER_SIZE; i++) {
			if (x < SIZE and y < SIZE and board[x][y] == CLEAR) {
				board[x][y] = DESTROYER;
				x++;
			}
			else die();
		}
	}
	else die();
	


	//YOU: Do the same for the other three ships
	// Submarine
	print_board();
	cout << "Please insert the (x,y) starting location for the submarine:\n";
	x=0,y=0;
	cin >> x >> y;
	if (!cin) die();
	//YOU: Error check the coordinates
	if (x >= SIZE or x < 0 or y >= SIZE or y < 0) die();
	cout << "Is the submarine vertical (v) or horizontal (h)?\n";
	c = 0;
	cin >> c;
	if (!cin) die();
	if (c == 'v') { //If vertical, we start at the top and go down
		for (int i = 0; i < SUBMARINE_SIZE; i++) {
			if (x < SIZE and y < SIZE and board[x][y] == CLEAR) {
				board[x][y] = SUBMARINE;
				y++;
			}
			else die();
		}
	}
	else if (c == 'h') {
		//YOU: Do the same for a horizontal ship
		for (int i = 0; i < SUBMARINE_SIZE; i++) {
			if (x < SIZE and y < SIZE and board[x][y] == CLEAR) {
				board[x][y] = SUBMARINE;
				x++;
			}
			else die();
		}
	}
	else die();



	// Battleship
	print_board();
	cout << "Please insert the (x,y) starting location for the battleship:\n";
	x=0,y=0;
	cin >> x >> y;
	if (!cin) die();
	//YOU: Error check the coordinates
	if (x >= SIZE or x < 0 or y >= SIZE or y < 0) die();
	cout << "Is the battleship vertical (v) or horizontal (h)?\n";
	c = 0;
	cin >> c;
	if (!cin) die();
	if (c == 'v') { //If vertical, we start at the top and go down
		for (int i = 0; i < BATTLESHIP_SIZE; i++) {
			if (x < SIZE and y < SIZE and board[x][y] == CLEAR) {
				board[x][y] = BATTLESHIP;
				y++;
			}
			else die();
		}
	}
	else if (c == 'h') {
		//YOU: Do the same for a horizontal ship
		for (int i = 0; i < BATTLESHIP_SIZE; i++) {
			if (x < SIZE and y < SIZE and board[x][y] == CLEAR) {
				board[x][y] = BATTLESHIP;
				x++;
			}
			else die();
		}
	}
	else die();



	// Aircraft Carrier
	print_board();
	cout << "Please insert the (x,y) starting location for the aircraft carrier:\n";
	x=0,y=0;
	cin >> x >> y;
	if (!cin) die();
	//YOU: Error check the coordinates
	if (x >= SIZE or x < 0 or y >= SIZE or y < 0) die();
	cout << "Is the aircraft carrier vertical (v) or horizontal (h)?\n";
	c = 0;
	cin >> c;
	if (!cin) die();
	if (c == 'v') { //If vertical, we start at the top and go down
		for (int i = 0; i < AIRCRAFT_CARRIER_SIZE; i++) {
			if (x < SIZE and y < SIZE and board[x][y] == CLEAR) {
				board[x][y] = AIRCRAFT_CARRIER;
				y++;
			}
			else die();
		}
	}
	else if (c == 'h') {
		//YOU: Do the same for a horizontal ship
		for (int i = 0; i < AIRCRAFT_CARRIER_SIZE; i++) {
			if (x < SIZE and y < SIZE and board[x][y] == CLEAR) {
				board[x][y] = AIRCRAFT_CARRIER;
				x++;
			}
			else die();
		}
	}
	else die();
	


	//PHASE 2 - Shoot torpedoes at the ships until they're all destroyed
	int torpedoes = 40; //If these run out, we lose
	while (true) { //Main loop
		print_board(); //Display the world state

		//Input next move
		cout << "Please enter where you want to shoot a torpedo:\n";
		cin >> x >> y;
		if (!cin) die();
		//YOU: Add in bounds checks for x and y
		if (x >= SIZE or x < 0 or y >= SIZE or y < 0) die();
		bool miss = (board[x][y] == CLEAR or board[x][y] == HIT or board[x][y] == MISS);
		if (miss) {
			message = MISS; //This will do a cout << "MISS!\n"; when the board is next printed
			board[x][y] = MISS;
		}
		if (!miss) {
			//YOU: When should it not register a miss? Add an if statement for that
			//YOU: Mark the board with a hit	
			message = HIT;

			//YOU: If that was the last one of a certain ship, set message.
			// In other words, if that was the last of the battleship,
			// set message = BATTLESHIP. This will cause "You sank my battleship!" to be
			// printed the next time the board is displayed instead of just "HIT!"
			if (board[x][y] == DESTROYER) {
				destroyer_pieces--;
				if (destroyer_pieces == 0) {
					message = DESTROYER;
				}
			}
			else if (board[x][y] == SUBMARINE) {
				submarine_pieces--;
				if (submarine_pieces == 0) {
					message = SUBMARINE;
				}
			}
			else if (board[x][y] == BATTLESHIP) {
				battleship_pieces--;
				if (battleship_pieces == 0) {
					message = BATTLESHIP;
				}
			}
			else if (board[x][y] == AIRCRAFT_CARRIER) {
				aircraft_carrier_pieces--;
				if (aircraft_carrier_pieces == 0) {
					message = AIRCRAFT_CARRIER;
				}
			}
			board[x][y] = HIT;
			
			// If no ships remain, call win();
			//YOU: If no ships are remaining, call win();
			if (!destroyer_pieces and !submarine_pieces and !battleship_pieces and !aircraft_carrier_pieces) win();
		}


		//YOU: Reduce torpedoes by 1
		torpedoes--;
		//YOU: If torpedoes is < 0, call lose();
		if (torpedoes < 0) lose();
	}
}

void beep() {
	cout << "";
}
void win() {
	beep();
	cout << "    _     __        _____ _   _ _   _ _____ ____    ___ ____\n";
	cout << "   / \\    \\ \\      / /_ _| \\ | | \\ | | ____|  _ \\  |_ _/ ___|\n";
	cout << "  / _ \\    \\ \\ /\\ / / | ||  \\| |  \\| |  _| | |_) |  | |\\___ \\\n";
	cout << " / ___ \\    \\ V  V /  | || |\\  | |\\  | |___|  _ <   | | ___) |\n";
	cout << "/_/   \\_\\    \\_/\\_/  |___|_| \\_|_| \\_|_____|_| \\_\\ |___|____/\n";
	cout << "\n";
	cout << "__   _____  _   _\n";
	cout << "\\ \\ / / _ \\| | | |\n";
	cout << " \\ V / | | | | | |\n";
	cout << "  | || |_| | |_| |\n";
	cout << "  |_| \\___/ \\___/\n";
	beep();
	exit(0);
}

void lose() {
	beep();
	cout << "__   _____  _   _   _     ___  ____  _____\n";
	cout << "\\ \\ / / _ \\| | | | | |   / _ \\/ ___|| ____|\n";
	cout << " \\ V / | | | | | | | |  | | | \\___ \\|  _|\n";
	cout << "  | || |_| | |_| | | |__| |_| |___) | |___\n";
	cout << "  |_| \\___/ \\___/  |_____\\___/|____/|_____|\n";
	beep();

	exit(0);
}
