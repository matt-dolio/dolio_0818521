#include <iostream>
using namespace std;

int calc(int x, int y, int input = 0) {

	if (input == 1) return x + y;
	else if (input == 2) return x - y;
	else if (input == 3) return x * y;
	else if (input == 4) {
		if (y == 0) {
			cerr << "Can't div by 0\n";
			return 0;
		} else return x / y;
	} else return 0;

}

int main() {

	int x, y, input;
	cout << "Enter a value for x and y:\n";
	cin >> x >> y;
	if (!cin) return 0;
	cout << "Add (1), Subtract (2), Multiply (3), Divide (4)?\n";
	cin >> input;
	if (!cin) return 0;
	cout << calc(x, y, input) << endl;

	return 0;

}
