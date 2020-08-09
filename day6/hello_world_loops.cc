#include <iostream>
using namespace std;

int main() {

	/* for (int i = 0; i < 20; i++) {
		cout << "Hello world!\n";
	}*/

	for (int i = 0; i < 100; i++) {
		cout << i + 1 << endl;
		if ((i + 1) % 10 == 0) {
			cout << "Hey!\n";
		}
	}

	return 0;
}
