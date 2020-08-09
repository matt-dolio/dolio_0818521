#include <iostream>
#include <typeinfo>

int main() {
	
	// prints out the users name, checks type first.
	std::string name;
	std::cout << "What is your name? ";
	std::cin >> name;

	if (typeid(name).name != std::string) {
		cout << "I didn't quite get that. Please try again.\n";
		return 0;
	} else {
		cout << "Hello, " << name << "!\n";
		return 0;
	}

}


