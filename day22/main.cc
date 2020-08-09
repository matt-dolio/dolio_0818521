#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool fun(const char *arr, int SIZE) {
	for (int i = 0; i < SIZE-1; i++) {
		if (arr[i] == arr[i+1]) return true;
	}
	return false;
}

// returns true if there are 2 or more pairs of letters in a word
bool fun2(const char *arr, int SIZE) {
	int count = 0;
	for (int i = 0; i < SIZE-1; i++) {
		if (arr[i] == arr[i+1]) count++;
	}
	if (count >= 2) return true;
	else return false;
}

bool is_sorted(const char *arr, int SIZE) {
	for (int i = 0; i < SIZE-1; i++) {
		if (arr[i] > arr[i+1]) return false;
	}
	return true;
}

bool is_sorted(string s) {
	string temp = s;
	sort(temp.begin(), temp.end());
	if (temp == s) return true;
	else return false;
}

//Given string s, remove all letters not in order
void stalin_sort(string &s) {
	for (size_t i = 0; i < s.size()-1; i++) {
		if (s.at(i) > s.at(i+1)) {
			s.erase(i+1, 1);
			i--;
		}
	}
}

int main() {
	cout << "Enter a word\n";
	string s;
	cin >> s;
	if (!cin) exit(0);

//	bool val1 = fun(s.c_str(), s.size());
//	cout << boolalpha << "Val1 is " << val1 << endl;
//	bool val2 = fun2(s.c_str(), s.size());
//	cout << boolalpha << "Val2 is " << val2 << endl;
//	bool val3 = is_sorted(s);
//	cout << "Val3 is " << ((val3) ? "alphabetically sorted" : "not alphabetically sorted") << endl;

	cout << "Pre-stalin sort " << s << endl;
	stalin_sort(s);
	cout << "Post-stalin sort " << s << endl;

	return 0;

}
