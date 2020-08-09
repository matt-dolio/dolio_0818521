#include <iostream>
using namespace std;

int main() {

	cout << "Please enter your age: \n";
	int age = 0;
	cin >> age;

	if (!cin) {
		cout << "Error! ACCESS DENIED\n";
		return 0;
	} else if (age <= 0) {
		cout << "Enter a real age! ACCESS DENIED\n";
		return 0;
	} else if (age <= 4) {
		cout << "You're far too young to be browsing the Internet! ACCESS DENIED\n";
		return 0;
	} else if (age >= 130) {
		cout << "You're either lying or I'm about to be impressed. ACCESS DENIED\n";
		return 0;
	} else if (age < 13) {
		cout << "You're a child!\n";
	} else if (age < 18) {
		cout << "You're a teenager!\n";
	} else if (age < 21) {
		cout << "You're an adult! (That can't do adult things yet)\n";
	} else if (age < 65) {
		cout << "You're an adult!\n";
	} else if (age >= 65) {
		cout << "You're a senior citizen!\n";
	} else {
		cout << "I'm not too sure WHAT you are!\n";
	}

	srand(time(0)); // Random number generator
	int passwd = rand() % 10 + 1;
	cout << "Please guess the password (1-10): \n";
	int guess = 0;
	cin >> guess;
	while (guess != passwd) {
		if (!cin) {
			cout << "Error!\n";
		} else if (guess > passwd) {
			cout << "Too high!\n";
		} else {
			cout << "Too low!\n";
		}
		cin >> guess;
	}
	cout << "Correct! ACCESS GRANTED\n";

	return 0;
}

