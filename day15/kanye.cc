#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int verycool(int &x) {
	x = x + 1;
	return 42 * x;
}

int main() {
	int kanye = 0;
	cout << verycool(kanye) << endl;
	cout << verycool(kanye) << endl;
	cout << verycool(kanye) << endl;
	cout << kanye << endl;
	int jojo = 10;
	cout << verycool(jojo) << endl;
	cout << verycool(jojo) << endl;
	cout << verycool(jojo) << endl;
	cout << verycool(jojo) << endl;
	cout << verycool(jojo) << endl;
	cout << jojo << endl;
	return 0;
}
