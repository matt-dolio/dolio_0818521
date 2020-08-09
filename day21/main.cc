#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// The Rule of Sith for memory is that for each new there is one delete
	int *arr = new int[100]; // The pointer is on the stack, and the 100 ints are allocated off the heap
	arr[5] = arr[6]; // Using unintialized memory - bad
	arr[10] = -9000;
	arr[7] = arr[10] * 2;
	arr[2000] = arr[10] * 2; // Out of bounds - bad
	delete[] arr; // Free up the memory when we're done with it
	delete[] arr; // Double free - bad
	arr[50] = 42; // Use after free - bad

	// Vectors = WAY SAFER AND NICER AND STUFF
	vector<int> vec(100);
	vec.at(200) = 60; // This will just crash - NICE
	cout << vec.at(6) << endl; // OKAY - It's just been initialized to 0 

}
