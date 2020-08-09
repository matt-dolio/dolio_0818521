#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream in_file("/public/hamlet.txt");
	while (in_file) {
		string temp;
		in_file >> temp;
		if (!in_file) break; //error?
		cout << temp << " ";
	}

	return 0;
}
