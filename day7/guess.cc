#include <iostream>
using namespace std;

int main() {

	while (true) {
		srand(time(0)); // Random number generator
		int passwd = rand() % 100 + 1;
		cout << "Please guess the password (1-100): \n";
		int guess = 0, difference = 0, prevDifference = 0, tries = 0;
		cin >> guess;
		while (guess != passwd && tries < 5) {

			if (!cin) {
				cout << "Error, try again! (No penalty)\n";
			} else if (guess > passwd) {
				cout << "Too high!\n";
				difference = guess - passwd;
			} else {
				cout << "Too low!\n";
				difference = passwd - guess;
			}

			if (prevDifference) {
				if (prevDifference > difference) {
					cout << "Getting warmer!\n";
				} else if (prevDifference < difference) {
					cout << "Getting colder!\n";
				}
			}

			if (difference <= 10) {
				cout << "You're hot!\n";
			}

			tries++;
			prevDifference = difference;
			cin >> guess;
		}

		if (tries == 5) {
			cout << "Too many attempts! Try again!\n";
		} else {
			cout << "Correct! ACCESS GRANTED\n";
		}
	}
	return 0;
}
