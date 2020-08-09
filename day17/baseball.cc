#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {

	vector<int> away, home;
	while (cin) {

		int x, y;
		cin >> x >> y;
		if (!cin || x < 0 || y < 0) break;
		away.push_back(x);
		home.push_back(y);

	}

	if (!home.size() or !away.size()) {
		cout << "Sum is 0, avg is 0, whatever, it's all zeroes.\n";
		exit(0);
	}

	int away_tot = 0, home_tot = 0;
	int away_min = INT_MAX, away_max = 0;
	int home_min = INT_MAX, home_max = 0;
	for (int z : away) {
		away_tot += z;
		away_min = min(away_min, z);
		away_max = max(away_max, z);
	}

	for (int a : home) {
		home_tot += a;
		home_min = min(home_min, a);
		home_max = max(home_max, a);
	}

	cout << endl;
	cout << "Away total score: " << away_tot << endl;
	cout << "Home total score: " << home_tot << endl;
	cout << endl;
	cout << "Away min score: " << away_min << endl;
	cout << "Away max score: " << away_max << endl;
	cout << "Away average score: " << away_tot / away.size() << endl;
	cout << endl;
	cout << "Home min score: " << home_min << endl;
	cout << "Home max score: " << home_max << endl;
	cout << "Home average score: " << home_tot / home.size() << endl;
	string winner = (away_tot > home_tot) ? "Away" : "Home";
	cout << endl << winner << " wins!\n";

	// Option 2
	auto away_minmax = minmax_element(away.begin(), away.end());
	auto home_minmax = minmax_element(home.begin(), home.end());
	cout << "away min: " << *away_minmax.first << " away max: " << *away_minmax.second << endl;
	cout << "home min: " << *home_minmax.first << " home max: " << *home_minmax.second << endl;
	
	auto bob = 5;
	// auto bob; is illegal, undefined type
	cin >> bob;

	return 0;

}

