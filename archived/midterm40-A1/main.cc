#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//This function is supposed to compute f(x) = 3*(sqrt(abs(x)) / 2)
double f(double x) {
	return (3 * (sqrt(abs(x)) / 2));
	/*
	   temp was set to int, and return was missing an asterisk (*)
	   I went ahead and just removed the temp variable altogether
	   and just replaced temp in the return with the proper
	   statement, and included the asterisk (*).
	*/
}

int main() {
	cout << "Please enter a double:\n";
	double x = 0;
	cin >> x;
	cout << "f(x) = " << fixed << setprecision(2) << f(x) << endl;
	return 0;
}
