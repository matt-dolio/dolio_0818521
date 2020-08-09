#include <iostream>
#include <vector>
using namespace std;

class Alignment {
  public:
	int law; // 1 is lawful, 0 neutral, -1 chaotic
	int good; // 1 is good, 0 neutral, -1 evil
};

class Hero {
  public:
	string name;
	int attack; // How much damage from 1 to 10
	int defense; // How much less damage they take from 1 to 10
	int money; // Money from 1 to INT_MAX
	bool plot_armor; // If true, can't die
	Alignment alignment; // Lawful good or chaotic evil or whatever
};

int main() {
	system("figlet GAME OF PORCELAIN THRONES | lolcat");

	// Option 1
	Hero Jon_Snow;
	Jon_Snow.name = "Jon Snow";
	Jon_Snow.attack = 6;
	Jon_Snow.defense = 7;
	Jon_Snow.money = 0;
	Jon_Snow.plot_armor = true;
	Jon_Snow.alignment.law = 1;
	Jon_Snow.alignment.good = 1;

	// Option 2 - Universal Initialization Syntax: {} are called "initializer lists"
	// Hero Jon_Snow = {"Jon Snow",6,7,0,true,{1,1}};

	return 0;
}
