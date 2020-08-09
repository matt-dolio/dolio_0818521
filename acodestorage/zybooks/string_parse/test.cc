#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
	string data;
	istringstream inSS(data);
	getline(inSS, data, ',');
	cout << data << endl;
	string x;
	int y;
	inSS >> x;
	inSS >> y;

	cout << x << endl;
	cout << y << endl;
	return 0;
}
