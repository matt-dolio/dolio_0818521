//Fill in the missing magic
#include <iostream>
using namespace std;

//All the below is inside main()...
int main() {
	//Print: "Enter x: " followed by an endl
	cout << "Enter x: " << endl;

	//Create a double named x and initialize it to 0
	double x = 0;

	//Read from cin into x
	cin >> x;

	//Print: "Enter y: " followed by an endl
	cout << "Enter y: " << endl;

	//Create a double named y and initialize it to 0
	double y = 0;

	//Read from cin into y
	cin >> y;

	//Print: "The average of x and y is: " followed by an endl
	cout << "The average of x and y is: " << endl;

	//Print the average of x and y followed by an endl
	cout << (x + y) / 2 << endl;

	//Print: "How many bootleg anime DVDs do you have?" followed by an endl
	cout << "How many bootleg anime DVDs do you have?" << endl;

	//Create an int named dvds and initialize it to 0
	int dvds = 0;

	//Read from cin into dvds
	cin >> dvds;

	//Print: "What is the average value of your bootleg DVDs?" followed by an endl
	cout << "What is the average value of your bootleg DVDs?" << endl;

	//Create an double named value and initialize it to 0
	double value = 0;

	//Read from cin into value
	cin >> value;

	//Print: "The value of your collection is: " followed by (on the same line) dvds * value followed by an endl
	cout << "The value of your collection is: " << dvds * value << endl;

	return 0;
}
