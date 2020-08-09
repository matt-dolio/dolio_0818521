#include <iostream>
using namespace std;

int main() {

	int sum = 0;
	for (int i = 0; i < 100; i++) {
		cout << "Please enter a number to add (0 for done):\n";
		int temp = 0;
		cin >> temp;
		if (temp == 0) break;
		sum += temp;
	}

	cout << "The sum of all your receipts is: " << sum << endl;

	return 0;
}
