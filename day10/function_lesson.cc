#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

int f(int x) { return 2 * pow(x, 2); }

int g(int x) { return sin(x) + cos(x); }

int h(int x) { return (10 - abs(x)) * tan(x); }

int j(int x) { return exp(M_PI * x); }

int k(int x) { return 2 * f(x) + sin(g(x)); }

int i(int x) { return x * x; }

int main() {

	cout << "f(2) = " << f(2) << endl;
	cout << "g(45) = " << g(45) << endl;
	cout << "h(10) = " << h(10) << endl;
	cout << "j(2) = " << j(2) << endl;
	cout << "k(10) = " << k(10) << endl;

	cout << "i test = " << i(2) << endl;

	return 0;
}
