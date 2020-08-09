#include <iostream>
#include <vector>
using namespace std;

//A class for tracking my sweet gains in weightlifting
//Every week, I will record how much I can squat
//I can then query how much I'm up from the start
class Gains {
	int baseline = 0; //How much we lifted to begin with
	vector<int> vec; //Our record of lifts from each week

	public:
	void set_baseline(int new_baseline) {
		baseline = new_baseline;
	}

	//Record my current week's lift
	void add_lift(int kilos) {
		if (kilos < 0) { //Check for negative weight
			cout << "Do you even lift, bro?\n";
			exit(1);
		}
		//Record the new lift into the vector
		vec.push_back(kilos);
	}

	//Look through our history for our max amount lifted
	int max_lift() {
		int max = 0;
		for (size_t i = 0; i < vec.size(); i++) {
			if (vec.at(i) > max) max = vec.at(i);
		}
		return max;
	}

	//Returns our sick gains, which is defined as how much we lift now (our most recent lift)
	// minus our baseline lift held in baseline
	int compute_gains() {
		if (vec.size() == 0) return 0; //No lifts, no gains
		int last_lift = vec.back(); //same thing as vec.at(vec.size()-1)
		return last_lift - baseline;
	}

	//Returns how much we've lost from our peak.
	//In other words if our max lift was 200 kilos but we can only lift 100 now, we will return -100
	int compute_losses() {
		if (vec.size() == 0) return 0; //No lifts, no losses
		int last_lift = vec.back();
		return last_lift - max_lift();
	}
};

int main() {
	Gains squat;
	squat.set_baseline(100); //100 kilo baseline
	cout << "Please enter your squats (one per line, 0 to quit):\n";
	while (cin) {
		int lift = 0;
		cin >> lift; //Read the week's lift
		if (!cin || lift == 0) break;
		squat.add_lift(lift); //Add it to our records
	}
	cout << "Your gains in squats: " << squat.compute_gains() << endl;
	cout << "Your losses in squats: " << squat.compute_losses() << endl;

	Gains chest;
	chest.set_baseline(10); //10 kilo baseline
	cout << "Please enter your chest fly (one per line, 0 to quit):\n";
	while (cin) {
		int lift = 0;
		cin >> lift; //Read the week's lift
		if (!cin || lift == 0) break;
		chest.add_lift(lift); //Add it to our records
	}
	cout << "Your gains in chest fly: " << chest.compute_gains() << endl;
	cout << "Your losses in chest fly: " << chest.compute_losses() << endl;
	return 0;
}
