#include <iostream>
#include "helloworldfunction"
using namespace std;

int main() {

	cout << "Testing capability to include my own header files...\n";
	cout << "Next statement should return \"Hello world!\"...\n";
	cout << HelloWorld() << endl;
	cout << "Attempted. Exiting...\n";
	return 0;

}
