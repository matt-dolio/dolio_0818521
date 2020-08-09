#include <iostream>
using namespace std;

int main() {

	double minTherm, maxTherm, prefTherm;

	cout << "What are the minimum and maximum values for the thermostat?\n";
	cin >> minTherm >> maxTherm;
	cout << "What temperature do you want to set the thermostat to?\n";
	cin >> prefTherm;

	if (!cin) {
		cout << "Error!\n";
		return 0;
	}

	prefTherm = clamp(prefTherm, minTherm, maxTherm);

	cout << "Thermostat was set to : " << prefTherm << endl;
	return prefTherm;
	// return 0;

}
