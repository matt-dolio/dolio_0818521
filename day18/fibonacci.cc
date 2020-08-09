#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	vector<unsigned long long> vec(2,1);
	for (int i = 0; i < 100; i++) {
		unsigned long long val = vec.at(i) + vec.at(i+1);
		vec.push_back(val);
	}
	
	for (unsigned long long x : vec) cout << x << endl;
}

