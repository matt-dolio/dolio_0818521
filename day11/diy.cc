#include <iostream>
#include <cmath>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

float temp_conversion(float temp, int input=0) {

	if (input == 1) return (temp - 32) * 5 / 9; // F to C conversion
	else if (input == 2) return 9 * temp / 5 + 32; // C to F conversion
	else return 0;
}

float discount(float price, float discount) {

	return price - (price * (discount / 100));

}

void new_programmer() {
	
	cout << "Hello World!\n";
	return;

}

float trig(float value, int operation) {
	
	if (operation == 0) return sin(value);
	else if (operation == 1) return cos(value);
	else if (operation == 2) return tan(value);
	else return 0;

}

int main() {
	auto start = high_resolution_clock::now();
	
	cout << "78 F to : " << temp_conversion(78, 1) << endl;
	cout << "10 C to F: " << temp_conversion(10, 2) << endl;
	cout << "Discount 10% off of $10: " << discount(10, 10) << endl;
	cout << "Discount 25% off of $50: " << discount(50, 25) << endl;
	new_programmer();
	cout << "Trig sin() of 20: " << trig(20, 0) << endl;
	cout << "Trig cos() of 45: " << trig(45, 1) << endl;
	cout << "Trig tan() of 50: " << trig(50, 2) << endl;
	
	auto stop = high_resolution_clock::now();

	auto duration = 0;

	return 0;

}

