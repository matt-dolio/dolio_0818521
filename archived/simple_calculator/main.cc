#include <iostream>
using namespace std;

int main() {

	// Retrieving necessary user input
	int input, num1, num2;
	cout << "1) addition 2) subtraction 3) multiplication 4) division:" << endl;
	cin >> input;

	if (!cin) { // Trying to do sanitation for first input prior to running calculations
		cout << "BAD INPUT!" << endl;
		return 0;
	} else if (input > 5 || input < 1) { // I'm not sure if this is valid sanitation, I don't know much about cpp
		cout << "BAD INPUT!" << endl;
		return 0;
	}
	// Input is valid, so...
	cout << "Please enter two numbers:  " << endl;
	cin >> num1 >> num2;

	// Time to do the calculations
	if (!cin) { // Checking that the entries were numbers
		cout << "BAD INPUT!" << endl;
		return 0;
	} else if (input == 1) { // Addition statement
		cout << num1 + num2 << endl;
	} else if (input == 2) { // Subtraction statement
		cout << num1 - num2 << endl;
	} else if (input == 3) { // Multiplication statement
		cout << num1 * num2 << endl;
	} else if (input == 4) { // Division statement
		if (num2 == 0) { // If the second number entered is 0 (since the numerator can be 0, it's just 0)
			cout << "BAD INPUT!" << endl;
		} else {
			cout << num1 / num2 << endl;
		}
	} else if (input == 5) { // Secret modulus statement
		if (num2 == 0) {
			cout << "BAD INPUT!" << endl;
			return 0;
		} else {
			cout << num1 % num2 << endl;
		}
	} else { // If nothing else checks out, obviously there's some bad input there.
		cout << "BAD INPUT!" << endl;
		return 0;
	}

	return 0;
}
