#include <iostream>
using namespace std;

int main() {

	int arr[3];
	arr[0] = 123;
	arr[1] = 456;
	arr[2] = 789;
	for (int i = 0; i < 400; i++) {
		cout << arr[i] << endl;
	}

	return 0;

}
