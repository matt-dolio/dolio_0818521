#include <iostream>
using namespace std;

int main() {

	unsigned long long x, y = 1;
	cin >> x;

	for (int i = 1; i <= x; i++) {
		y *= i;
	}
	cout << y << endl;

	cout << sizeof(y) << endl;
	cout << sizeof(x) << endl;

	return 0;
}

