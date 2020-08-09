#include <iostream>
using namespace std;

/*void to_upper(string c) {

	for (char & c : str) {
		c = toupper(c);
	}

	return;
}*/

string to_upper(string s) {

	string ans;
	for (char c : s) {
		ans.push_back(toupper(c));
	}

	return ans;
}

int main() {

	// to_upper function addition by @Harrison on Discord
	string test1 = "Hello, world!";
	test1 = to_upper(test1);
	cout << test1 << endl;

	// One-liner as suggested by @Adversary on Discord
	string test2 = "Second test!";
	transform(test2.begin(), test2.end(), test2.begin(), ::toupper);
	cout << test2 << endl;

	return 0;
}
