#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {

	// Step 1: Prompt the user for a title for data, and output the title.
	cout << "Enter a title for the data:\n"; // Prompt
	string title; // Initialize variable
	getline(cin, title); // Get entire string by user input buffer
	cout << "You entered: " << title << endl; // Output user-input title
	cout << endl;

	// Step 2: Prompt the user for the headers of two columns of a table. Output the column headers.
	cout << "Enter the column 1 header:\n"; // Prompt the user
	string column_1, column_2; // Initialize variables
	getline(cin, column_1); // Get string input by user input buffer
	cout << "You entered: " << column_1 << endl; // Output column 1 to the user
	cout << endl;
	cout << "Enter the column 2 header:\n"; // Prompt the user again!
	getline(cin, column_2); // Get string input by user input buffer
	cout << "You entered: " << column_2 << endl; // Output column 2 to the user
	cout << endl;

	// Step 3: Prompt the user for data points. Must be in format: *string*, *int*. Store the info BEFORE
	// the comma into a string variable and the information after the comma into an integer. The user will
	// enter -1 when they have finished entering data points. Output the data points. Store the string
	// components of the data points in a vector of strings. Store the integer components of the data
	// points in a vector of integers.	
	string userInput = "";
	vector<string> stringComponent; // Initalize vectors
	vector<int> integerComponent;
	int integerInput;
	string nameInput; // Initialize variables
	bool commaPresent = false;
	istringstream inSS(userInput); // stream the user input to stringstream
	
	cout << "Enter a data point (-1 to stop input):\n"; // Prompt user
	getline(cin, userInput); // Get input from user input buffer
	
	while (userInput != "-1") {
		if (userInput == "-1") break;
		for (unsigned int i = 0; i < userInput.length(); i++) {
			if (userInput.at(i) == ',') {
				commaPresent = true;
			}
		}
		if (!commaPresent) {
			cout << "Error: No comma in string.\n";
		} else {
			inSS >> nameInput; // Should be name in the first place
			inSS >> integerInput; // Might have error here
			if (!cin) {
				cout << "Some error" << endl;
			} else {
				cout << "Reached else statement\n";
			}
		}

		cout << endl;
		cout << "Enter a data point (-1 to stop input):\n";
		getline(cin, userInput);
	}
	return 0;
}
