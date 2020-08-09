// DOLIO and AVENDANO
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool abs_difference(double input1, double input2, double epsilon) {
	double diff = input1 - input2;
	return (fabs(diff) < epsilon);
}

//Enum is useful when you want to make large numbers of mutually exclusive constants
//This creates 5 constant integers, named EQUILATERAL (= 0), ISOCELES (= 1), etc.
//It also creates a new integer type that can only hold a value from 0 to 4.
enum triangle_t { EQUILATERAL, ISOCELES, RIGHT, OTHER, ERROR };

/* This is equivalent, kinda, to:
const int EQUILATERAL = 0;
const int ISOCELES = 1;
const int RIGHT = 2;
const int OTHER = 3;
const int ERROR = 4;
*/

triangle_t triangle_tester(double side1, double side2, double side3) {

	//YOU: Do your work right here
	if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
		return ERROR;
	}

//	cout << (pow(side3, 2) == pow(side1, 2) + pow(side2, 2)) << endl;

	if (side1 == side2 and side2 == side3) return EQUILATERAL;
	else if (side1 == side2 || side2 == side3 || side3 == side1) return ISOCELES;
	else if (abs_difference(pow(side2, 2) + pow(side3, 2), pow(side1, 2), 0.001)) return RIGHT;
	else if (abs_difference(pow(side1, 2) + pow(side3, 2), pow(side2, 2), 0.001)) return RIGHT;
	else if (abs_difference(pow(side1, 2) + pow(side2, 2), pow(side3, 2), 0.001)) return RIGHT;
	else return OTHER;

}

int main() {
	float side1 = 0.0, side2 = 0.0, side3 = 0.0;
	cin >> side1 >> side2 >> side3;

	//YOU: Delete this next line...

	triangle_t result = triangle_tester(side1, side2, side3);

	if (result == EQUILATERAL)
		cout << "equilateral";
	else if (result == ISOCELES)
		cout << "isoceles";
	else if (result == RIGHT)
		cout << "right";
	else if (result == OTHER)
		cout << "other";
	else if (result == ERROR)
		cout << "error";
	else
		cout << "This is unpossible!";
	cout << endl;
}
