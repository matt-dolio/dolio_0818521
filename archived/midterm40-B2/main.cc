#include <iostream>
#include <cmath>
using namespace std;

void die() {
	cout << "You typed in a bad radius!\n";
	exit(1);
}

int main() {
	cout << "Please enter the radius of a circle:\n";
	float radius = 0; // There was a missing semicolon here
	cin >> radius;
	if (!cin || (radius == 0)) die(); // Was typed "radius = 0"
	cout << "The area of a circle of that radius is: " << ((M_PI) * (radius * radius)) << endl;
	return 0;
}

