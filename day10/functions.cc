#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip> // fixed and setprecision
#include <cctype>
using namespace std;

int main() {

	cout << sqrt(9) << endl; // sqrt is square root function
	cout << abs(-3) << endl;
	cout << sqrt(pow(3, 2) + pow(4, 2)) << endl;
	cout << sin(360) << " is in radians" << endl;
	cout << hypot(3, 4) << endl; // yep this is a thing
	cerr << "Nice error bro" << endl;
	cout << sin(2*M_PI) << fixed << setprecision(2) << endl; // radians! M_PI is pi
	for (int i = 1; i <= 4; i++) {
		cout << pow(i, i) << endl;
	}

	// cctype
	string s = "Matthew Dolio";
	char c = 'a';
	cout << toupper(c) << endl; // uppercases
	cout << s << endl;

	cout << "Please enter your name\n" << endl;
	getline(cin, s);
	bool nameok = true;
	for (unsigned int i = 0; i < s.size(); i++) {
		if (!isalpha(s.at(i))) {
			nameok = false;
		} else {
			s.at(i) = toupper(s.at(i));
		}
	}
	if (nameok) {
		cout << "Name OK\n";
	} else {
		cout << "BAD NAME\n";
	}
	

	return 0;
}
