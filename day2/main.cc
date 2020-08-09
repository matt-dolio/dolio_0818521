#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int x, y, z;
	x = 2;
	y = 3;
	z = 6;
	double pi, e, phi;
	pi = 3.1415;
	e = 2.71828;
	phi = 1.618;
	//cout << x + y << endl;
	//cout << x + (y - z) << endl;
	cout << "pi = " << pi << " e = " << e << " phi = " << phi << endl;
	cout << "x = " << x << " y = " << y << " z = " << z << endl;
	cout << "x to the yth power = " << pow(x, y) << endl;
	cout << "x to the zth power = " << pow(x, z) << endl;
	cout << "x to the zth power = " << pow(x, z) << endl;
	cout << "5/2.5 =  " << 5/2.5 << endl;
	cout << "y to the zth power = " << pow(y, z) << endl;
	cout << "pi * e = " << pi * e << endl;
	cout << "pi squared = " << pow(pi, 2) << endl;
	cout << "10.5 + 5 = " << 10.5 + 5  << endl;
	//cout << "10.1 % 5 = " << 10.1 % 5  << endl; This, in fact, does not work, and won't compile
	cout << "10.0 / 0.0 = " << 10.0 / 0.0  << endl; // This results in a divide by zero error BUT NO WARNING
	cout << "10 / 0 = " << 10 / 0  << endl; // This results in a divide by zero error with a warning
	/*string firstname, middlename, lastname;

	cout << "What is your name? ";
	cin >> firstname >> middlename >> lastname;

	cout << "Hello, " << firstname << " " << middlename << " " << lastname << "!\n";
	*/
	return 0;
}

