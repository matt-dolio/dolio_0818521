#include <iostream>
using namespace std;

int main() {

	int highwayNumber;
	cin >> highwayNumber;

	bool even = (!(highwayNumber % 2));
	bool primary = (highwayNumber < 100 && highwayNumber > 0);

	if (primary) cout << "I-" << highwayNumber << " is primary, going " << (even ? "east/west" : "north/south") << "." << endl;
	else {
		cout << "I-" << highwayNumber << " is auxiliary, serving I-" << highwayNumber % 100 << ", going " << (even ? "east/west" : "north/south") << "." << endl;
	}

	return 0;
}
