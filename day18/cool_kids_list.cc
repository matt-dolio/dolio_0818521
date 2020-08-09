#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void uppercaseify(string &s) {
	for (char &c : s) c = toupper(c);
}

int main() {
	vector<string> cool_kids;
	vector<string> kowai_kids;
//	while (true) {
//		cout << "Please enter a name (type \"done\" to be done):\n";
//		string s;
//		cin >> s;
//		if (s == "DONE" or !cin) break;
//		if (s == "DOLIO" or s == "GURDEV" or s == "JAI") kowai_kids.push_back(s);
//		else cool_kids.push_back(s);
//	}
//
//	cout << "COOL KIDS LIST:\n";
//	for (string s : cool_kids) cout << s << endl;
//	cout << endl;
//	cout << "KOWAI KIDS LIST:\n";
//	for (string s : kowai_kids) cout << s << endl;
//	cout << endl;
//
//	sort(cool_kids.begin(), cool_kids.end());
//	sort(kowai_kids.begin(), kowai_kids.end());

	while (true) {
		cout << "Please enter your name or type \"done\" when done:\n";
		string s;
		cin >> s;
		if (!cin) break;
		if (s == "done") break;
		for (int i = 0; i < name.size()/2; i++) {
			swap(name.at(i), name.at(name.size()-1-i));
		}
		reverse(name.begin(),name.end());
		cout << "Your name backwards is:\n";
		cout << name << endl;
		bool anagram = ()

	}

	return 0;
}
