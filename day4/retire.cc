#include <iostream>
using namespace std;

int main() {

	int years_retirement = 0, income = 0;
	cout << "Please enter how many years you have until you retire and your annual income:  ";
	cin >> years_retirement >> income;
	cout << "Please enter how much money you want to have at retirement:  ";
	int target_money = 0;
	cin >> target_money;

	int retirement_money = years_retirement * income; // This is how much I'll have saved up
	
	if (retirement_money >= target_money) {
		cout << "You have enough for retirement! Yay!\n";
	} else {
		cout << "Sorry, I hope you like the taste of cat food.\n";
	}


	return 0;
}

