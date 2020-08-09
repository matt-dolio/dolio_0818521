#include <iostream>
using namespace std;

int main() {

	int x = 0, y = 0;
	cin >> x >> y;
	cout << static_cast<float>(x + y) / 2 << endl; // Most C++
	cout << float(x + y) / 2 << endl; // Medium C++
	cout << (float) (x + y) / 2 << endl; // Not very C++
	
	return 0;
}

