#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void die() {
	cout << "BAD INPUT!\n";
	exit(1);
}

void write_int(ofstream &outs, int x) {
	outs << x << endl;
}

int read_int(ifstream &ins) {
	int x = 0;
	ins >> x;
	return x;
}

int main() { 
	cout << "Please enter a random seed:\n";
	int seed = 0;
	cin >> seed;
	if (!cin) die();
	srand(seed);

	cout << "Writing 10 random numbers to file.txt:\n";
	ofstream outs("file.txt");
	for (int i = 0; i < 10; i++) {
		int foo = rand() % 10;
		cout << "Wrote: " << foo << endl;
		write_int(outs,foo);
	}
	outs.close();

	cout << "Reading them back from file.txt:\n";
	srand(seed); //Reset the random seed
	ifstream ins("file.txt");
	for (int i = 0; i < 10; i++) {
		int foo = rand() % 10;
		int bar = read_int(ins);
		cout << "Expected: " << foo << " Got: " << bar << endl;
	}
	ins.close();
}
