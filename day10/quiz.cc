#include <iostream>
using namespace std;

int main() {

	int input;
	cin >> input;
	if (!cin) return 0;

	for (unsigned int i = 1; i <= (input / 2); i++) {
		if (input % i == 0) {
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}
