#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {

	bool hasNegative, startTooHigh, invalidNum;
	vector<string> digits = {"", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	vector<string> tenExponents = {"shi", "bai", "qian", "wan"};
	const int MAX = 99999;
	int to, start, step;

	cout << "Please enter a number that you want to count up to in Mandarin.\n";
	cin >> to;

	if (!cin) {
		cout << "BAD INPUT!\n";
		return 0;
	} else if (to < 1 || to > MAX) {
		cout << "BAD INPUT!\n";
		return 0;
	}

	cout << "Please enter what number to start with:\n";
	cin >> start;

	if (!cin) {
		cout << "BAD INPUT!\n";
		return 0;
	} else if (start > to || start < 0) { // start is greater than to
		cout << "BAD INPUT!\n";
		return 0;
	}

	cout << "What step size do you want to use?\n";
	cin >> step;

	if (!cin) {
		cout << "BAD INPUT!\n";
		return 0;
	} else if (step < 1) {
		cout << "BAD INPUT!\n";
		return 0;
	}

	for (int i = start; i <= to; i = i + step) {

		string output;
		bool tenThousands = (i >= 10000), thousands = (i >= 1000), hundreds = (i >= 100), tens = (i >= 10), ones = (i >= 0);
		output += (to_string(i) + " ");
		if (tenThousands) {
			output += (digits.at(i / 10000 % 10) + " " + tenExponents.at(3) + " ");
		}
		if (thousands) {
			output += (digits.at(i / 1000 % 10) + " " + tenExponents.at(2) + " ");
		}
		if (hundreds) {
			output += (digits.at(i / 100 % 10) + " " + tenExponents.at(1) + " ");
		}
		if (tens) {
			if (i >= 10 && i < 20) {
				output += (tenExponents.at(0) + " ");
			} else {
				output += (digits.at(i / 10 % 10) + " " + tenExponents.at(0) + " ");
			}
		}
		if (ones) {
			output += (digits.at(i % 10));
		}
		if (i == 0) {
			output += "ling";
		}
		cout << output << endl;

	}

	return 0;
}
