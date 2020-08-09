#include <string.h>
#include <time.h>
#include <iostream>

int subtraction(float a, float b) {
	std::cout << "a - b = " << a - b << std::endl << std::endl;
	return 0;
}

int addition(float a, float b) {
	std::cout << "a + b = " << a + b << std::endl << std::endl;
	return 0;
}

int multiplication(float a, float b) {
	std::cout << "a * b = " << a * b << std::endl << std::endl;
	return 0;
}

int division(float a, float b) {
	std::cout << "a / b = " << a / b << std::endl << std::endl;
	return 0;
}

/*
int modulus(float a, float b) {
	std::cout << "a % b = " << a % b << std::endl;
	return 0;
}
*/


int main() {
	std::cout << "Welcome to the math machine! :)\n";
	float a, b;
	std::string c;
	std::cout << "Enter the first number: ";
	std::cin >> a;
	std::cout << "Enter the second number: ";
	std::cin >> b;
	std::cout << "What arithmetic would you like to perform? (ADD, SUB, MULT, DIV): ";
	std::cin >> c;

	std::transform(c.begin(), c.end(), c.begin(), ::toupper);

	if (c == "ADD") {
		addition(a, b);
	} else if (c == "SUB") {
		subtraction(a, b);
	} else if (c == "MULT") {
		multiplication(a, b);
	} else if (c == "DIV") {
		division(a, b);
	} /*else if (to_upper(c) == "MOD") {
		modulus(a, b);
	}*/ else {
		std::cout << "Sorry, I didn't quite get that. Please try again.\n";
	}

	return 0;
}



