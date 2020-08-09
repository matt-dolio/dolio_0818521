#include <iostream>
using namespace std;

int main() {

	double grade;
	cout << "What percentage grade do you have in the class?: " << endl;
	cin >> grade;

	if (!cin) {
		cout << "Error!\n";
	} else if (grade < 60) {
		cout << "Your grade is an F.\n";
	} else if (grade < 70) {
		cout << "Your grade is a D.\n";
	} else if (grade < 80) {
		cout << "Your grade is a C.\n";
	} else if (grade < 90) {
		cout << "Your grade is a B.\n";
	} else if (grade >= 90) {
		cout << "Your grade is an A.\n";
	} else {
		cout << "Something went wrong. Please try again.\n";
	}

	return 0;
}
