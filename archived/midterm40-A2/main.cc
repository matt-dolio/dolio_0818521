#include <iostream>
using namespace std;

int main() { // There was no curly brace here
	int sum = 0, count = 0;
	while (true) {
		cout << "Please enter a number (current sum = " << sum  << "), 0 to quit:\n";
		int temp = 0;
		cin >> temp;
		if (!cin) {
			cout << "BAD INPUT!\n";
			exit(1);
		}
		if (temp == 0) break;
		sum += temp; // There was an equal sign here, changed to +=
		count++;
	}
	cout << "The sum was: " << sum << endl;
	cout << "The avg was: " << double(sum) / count << endl;
}
