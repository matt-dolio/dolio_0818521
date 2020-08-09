#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int x = 0;
	cout << "Please enter a number:\n";
	cin >> x;
	cout << ((x > 2) ? "X is bigger than 2" : "X is <= 2") << endl;
	return 0;
}
