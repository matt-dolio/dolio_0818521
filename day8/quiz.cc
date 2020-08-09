#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {

	string input;
	/* Insert code here */
	while (true) {

		cout << "Continue?" << endl;
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "YES" || input == "Y") {
			continue;
		} else {
			break;
		}

	}

	return 0;
}
