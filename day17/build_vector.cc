#include <vector>
#include <iostream>
using namespace std;

int main() {

	vector<int> vec;
	while (cin) {
		int x;
		cin >> x;
		if (!cin || x == 0) break;
		vec.push_back(x);
	}

	return 0;

}
