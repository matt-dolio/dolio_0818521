#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void die(string error = "No error given") {
	cerr << error << endl;
	cout << "BAD INPUT!\n";
	exit(EXIT_FAILURE);
}

//This code is correct, it returns true if the string s is in the vector vec
bool is_in(const vector<string> &vec, const string &s) {
	return (find(vec.begin(),vec.end(),s) != vec.end());
}

string recognize_chord(const vector<string> &input) {
	if (input.size() != 3) die("Recognize chord input size error"); //Sanity check
	vector<string> cmajor = {"C","E","G"};
	vector<string> fmajor = {"F","A","C"};
	vector<string> gmajor = {"G","B","D"};
	int cmajor_count = 0, fmajor_count = 0, gmajor_count = 0;
	for (size_t i = 0; i < input.size(); i++) {
		if (is_in(cmajor,input.at(i))) cmajor_count++;
		if (is_in(fmajor,input.at(i))) fmajor_count++;
		if (is_in(gmajor,input.at(i))) gmajor_count++;
	}

	if (cmajor_count >= 3) return "C Major";
	if (fmajor_count >= 3) return "F Major";
	if (gmajor_count >= 3) return "G Major";
	return "Unknown";
}

int main() {
	cout << "Welcome to Chordata, the major triad chord database!\n";
	cout << "You will type in three notes in any order and I will tell you what chord it is.\n";
	cout << "Note: sharps and flats are not supported. Coming soon!\n";
	cout << "Please enter three notes separated by spaces:\n";
	vector<string> input;
	for (int i = 0; i < 3; i++) {
		string temp;
		cin >> temp;
		if (temp.size() != 1) {
			die("Invalid sizing error");
		}
		if (temp < "A" or temp > "G") {
			die("Less than/Greater than error");
		}
		input.push_back(temp);
	}
	cout << recognize_chord(input) << endl;
}
