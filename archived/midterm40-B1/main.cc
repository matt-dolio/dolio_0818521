#include <iostream>
using namespace std;

const int VICTORY = 100;

int roll_die() {
	return rand() % 6 + 1;
}

int main() {
	cout << "Please enter a random seed:\n";
	int x = 0;
	cin >> x;
	if (!cin) exit(1);
	srand(x); //Seed the random number generator
	int rolls = 0, points = 0;
	while (points < VICTORY) {
		int first_die = roll_die();
		int secon_die = roll_die();
		int third_die = roll_die();
		cout << "Roll # " << rolls << ": " << first_die << "," << secon_die << "," << third_die << endl;
		if (first_die == secon_die and secon_die == third_die) {
			// If statement stated "and == third_die", needed comparator statement
			cout << "YAHTZEE! 50 points!\n";
			points += 50;
		} else {
			int total = first_die + secon_die + third_die;
			cout << "You win: " << total << " points.\n";
			points += total;
			// Needed to += points to total here, was declarative
		}
		rolls++;
	}
}
