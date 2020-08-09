#include <iostream>
using namespace std;

int main() {

	int a, b;
	cout << "Enter a number:" << endl;
	cin >> a;
	cout << "Enter another number:" << endl;
	cin >> b;
	cout << "The int average of a and b is: " << (a + b) / 2 << endl;
	float c = a;
	float d = b;
	cout << "The float average of a and b is: " << (c + d) / 2 << endl;

	return 0;
}
