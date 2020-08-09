#include <iostream>
#include <fstream>
using namespace std;

int main() {

	string input;
	cout << "What would you like to write to a file?\n";
	getline(cin, input);
	input += "\n";
	ofstream myFile;
	myFile.open("test.txt");
	myFile << input;
	myFile.close();

	return 0;
}
