#include <iostream>
using namespace std;

int main() {

	const double MIN = 60, MAX = 90;
	double current;

	cout << "What temperature do you want to set the thermostat to?\n";
	cin >> current;

	if (!cin) {
		cout << "Error!\n";
		return 0;
	}

	current = clamp(current, MIN, MAX);

	cout << "Thermostat was set to : " << current << endl;
	return current;
	// return 0;

}
