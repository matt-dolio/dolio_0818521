#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <vector>
using namespace std;

int main() {

	unsigned int i;
	size_t start = time(0);
	vector<int> vec(100, 40); //make a hundy 40s
//	for (size_t i = 0; i < vec.size(); i++) {
//		cout << vec.at(i) << endl;
//	}

//	for (int x : vec) {
//		cout << x << endl;
//	}
	
std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	//1. write code to output the sum of all the ints in vec
	int sum = 0;
	for (i = 0; i < vec.size(); i++) {
		sum += vec.at(i);
	}
	cout << sum << endl;

	//2. write code to fill vec with random numbers from 1 to 10
	//If you want to do a range based for loop here, use this instead:
	for (int &x : vec) x = rand() % 10 + 1;

	//3. Add it up again and print the sum
	sum = 0;
	for (i = 0; i < vec.size(); i++) {
		sum += vec.at(i);
	}

	//4. Multiply the first 10 numbers together and cout the product
	int product = 1;
	for (i = 0; i < 10; i++) {
		product *= vec.at(i);
	}
	cout << product << endl;
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << "Time passed: " << setprecision(3) << fixed << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000.0 << endl;
}
