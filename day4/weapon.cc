#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int attack(int damage, int monster_health) {

	int attack_roll = rand() % 20 + 1, damage_roll = 0;

	if (attack_roll == 20) {
		damage_roll = 2 * (rand() % damage + 1);
		cout << "CRIT! Your attack does: " << damage_roll << " damage!" << endl;
	} else if (attack_roll > 9) {
		damage_roll = rand() % damage + 1;
		cout << "Hit! Your attack does: " << damage_roll << " damage!" << endl;
	} else {
		damage_roll = 0;
		cout << "You missed!" << endl;
	}

	monster_health = monster_health - damage_roll;
	if (monster_health <= 0) {
		cout << "You killed the monster!" << endl;
		return 0;
	} else {
		cout << "Monster's health is: " << monster_health << endl;
		cout << "Press enter to continue:" << endl;
		cin.ignore();
		attack(damage, monster_health);
	}

	return 0;
}

int main() {

	srand(time(0)); // Initializes random number generator
	int damage = 0, monster_health = 20;
	string weapon;
	cout << "What weapon do you choose?" << endl;
	cin >> weapon;
	transform(weapon.begin(), weapon.end(), weapon.begin(), ::tolower);
	if (weapon == "dagger") damage = 4;
	else if (weapon == "shortsword") damage = 6;
	else if (weapon == "longsword") damage = 8;
	else if (weapon == "halberd") damage = 10;
	else if (weapon == "greataxe" || weapon == "greatsword") damage = 12;
	else damage = 6;

	cout << "Press enter to continue:" << endl;
	cin.ignore();

	attack(damage, monster_health);

	return 0;
}



