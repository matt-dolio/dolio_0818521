#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void die(string s = "INVALID INPUT!") {
	cout << s << endl;
	exit(EXIT_FAILURE);
}

//Holds a record for a single species of Pokemon, such as Pikachu
class Pokemon {
	public:
	//YOU: Add member variable ints for each of the following: 
		//index - what index it is in the pokedex
		int index;
		//name (this is a string not an int)
		string name;
		//hp - how much damage it takes before dying fainting
		int hp;
		//attack - this number gets multiplied by the move's power to determine damage
		int attack;
		//defense - incoming damage gets divided by this number
		int defense;
		//speed - whichever pokemon has the highest speed attacks first, flip a coin on a tie
		int speed;
		//special - like attack and defense both, but for special moves
		int special;
		//Note: this is also the order the data is ordered in the file
		void SetTypes();
	//YOU: Add member variables of type string for type1 and type2
		string type1, type2;
};
vector<Pokemon> pokemon_db; //Holds all pokemon known to mankind

//This function reads from the "pokemon.txt" file in the directory and loads the data into the pokemon_db global vector
//Each row has: pokemon number, name, hp, etc.
void load_pokemon_db(string filename = "pokemon.txt", string filename2 = "types.txt") {
	ifstream ins(filename);
	if (!ins) die("Couldn't load file "s + filename);
	ifstream ins2(filename2);
	if (!ins2) die("Couldn't load file "s + filename2);
	string line1, line2;
	while (ins and ins2) {	
		Pokemon temp;
		getline(ins, line1);
		getline(ins2, line2);
		string dex, name, type1, type2;
		string dex2, name2, hp, attack, defense, speed, special;
		stringstream ss1(line2), ss2(line1);
		getline(ss1,dex,'\t');
		if (dex == "") break;
		if (!isdigit(dex.at(0))) continue;
		getline(ss1,name,'\t');
		getline(ss1,type1,'\t');
		getline(ss1,type2,'\t');
		if (type2 == "") type2 = ""; // Redundancy department of redundancy
		getline(ss2,dex2,'\t');
		if (!isdigit(dex2.at(0))) continue;
		getline(ss2,name2,'\t');
		getline(ss2,hp,'\t');
		if (!isdigit(hp.at(0))) continue;
		getline(ss2,attack,'\t');
		if (!isdigit(attack.at(0))) continue;
		getline(ss2,defense,'\t');
		if (!isdigit(defense.at(0))) continue;
		getline(ss2,speed,'\t');
		if (!isdigit(speed.at(0))) continue;
		getline(ss2,special,'\t');
		if (!isdigit(special.at(0))) continue;
		temp.index = stoi(dex2);
		temp.name = name;
		temp.hp = stoi(hp);
		temp.attack = stoi(attack);
		temp.defense = stoi(defense);
		temp.speed = stoi(speed);
		temp.special = stoi(special);
		temp.type1 = type1;
		temp.type2 = type2;
		//YOU: Read from the files the data into a temporary Pokemon, getting the stats from pokemon.txt and its types from types.txt
		
		pokemon_db.push_back(temp);	
	}
}

//This class holds a record for each move in the game
class Move {
	public:
		//YOU: Add member variable for each of these:
		//int index, string name, string type, string category, int PP, int power, int accuracy
		int index;
		string name;
		string type;
		string category;
		int PP;
		int power;
		int accuracy;
};
vector<Move> move_db;

//Reads all moves from moves.txt into move_db
//Be sure to discard all status moves
void load_move_db(string filename="moves.txt") {
	ifstream ins(filename);
	if (!ins) die("Couldn't load "s + filename);
	string line;
	while (ins) {
		//YOU: Read from the file, make a temp Move with all the data read in
		//YOU: Push it back into the move_db
		Move temp;
		getline(ins, line);
		string index, name, type, category, PP, power, accuracy;
		stringstream ss(line);
		getline(ss,index,'\t');
		if (index == "") break;
		if (!isdigit(index.at(0))) continue;
		getline(ss,name,'\t');
		getline(ss,type,'\t');
		getline(ss,category,'\t');
		getline(ss,PP,'\t');
		if (!isdigit(PP.at(0))) continue;
		getline(ss,power,'\t');
		if (!isdigit(power.at(0))) continue;
		getline(ss,accuracy,'\t');
		if (!isdigit(accuracy.at(0))) continue;
		temp.index = stoi(index);
		temp.name = name;
		temp.type = type;
		temp.category = category;
		temp.PP = stoi(PP);
		if (power == "—") temp.power = 0;
		else temp.power = stoi(power);
		if (accuracy == "—") temp.accuracy = 0;
		else temp.accuracy = stoi(accuracy);

		move_db.push_back(temp);
	}
}

//PART 2
//This conducts a one versus one battle between two pokemon of your choice
void battle_mode() {
	//Pick a Pokemon and a move for team one
	//Pick a Pokemon and a move for team two
	//Whichever Pokemon has the higher speed goes first
	//Have them do damage to each other based on their move * power * type modifier
	//Target Pokémon reduces damage based on its defense or special defense
}

//PART 2
void explore_mode() {
}

int main() {
	srand(0); //Fixed seed - don't change this
	system("figlet POKEMON");
	system("figlet ++ and \\#");
	cout << "Do you want to use the Gen1 Pokémon? (Type \"NO\" for no, anything else for yes.)\n";
	string answer;
	bool gen1;
	getline(cin,answer);
	for (char &c:answer) c = toupper(c); //Uppercaseify
	string filename1, filename2;
	if (answer == "NO") {
		gen1 = false;
		cout << "Please enter the two files containing the Pokémon and types for the Pokémon.\n";
		cin >> filename1 >> filename2;
		load_pokemon_db(filename1, filename2);
	}
	else {
		gen1 = true;
		load_pokemon_db();
	}
	/* Debug the load - uncomment this to see everything
	for (Pokemon p : pokemon_db) {
		cerr << "Pokedex Entry " << p.index << ": " << p.name << " hp: " << p.hp << " attack: " << p.attack;
		cerr << " defense: " << p.defense << " speed: " << p.speed << " special: " << p.special;
		cerr << " type1: " << p.type1 << " type2: " << p.type2 << endl;
	}
	*/

	string filename3;
	if (answer == "NO") {
		cout << "Please enter the file containing the moves for your Pokémon.\n";
		cin >> filename3;
		load_move_db(filename3);
	}
	else
		load_move_db();

	/*	
	// DEBUG the load - uncomment this to see the results
	for (Move m : move_db) {
		if (m.index == 0) continue;
		cerr << "Move Index " << m.index << ": " << m.name << " " << " type: " << m.type << " category: " << m.category << " PP: " << m.PP << " power: " << m.power << " accuracy: " << m.accuracy << "%\n";
	}
	*/

	cout << "Do you want to\n1) Print Pokémon Data?\n2) Print Move Data?\n3) Pokemon Battle (1v1)\n4) Explore the World?\n";
	int choice = 0;
	cin >> choice;
	if (!cin || choice < 1 || choice > 4) die();
	if (choice == 1) {
		cout << "Please enter the Pokedex number of the Pokémon whose data you want to print:\n";
		int index = 0;
		cin >> index;
		if (!cin) die();
		if (!index and gen1) die();
		//Pokemon p = pokemon_db.at(index+1); //Pokedex starts at 1, this only works for Gen1 Pokémon
		Pokemon p;
		for (const Pokemon &poke : pokemon_db) if (index == poke.index) p = poke;
		cout << "Pokedex Entry " << p.index << ": " << p.name << " hp: " << p.hp << " attack: " << p.attack;
		cout << " defense: " << p.defense << " speed: " << p.speed << " special: " << p.special;
		cout << " type1: " << p.type1 << " type2: " << p.type2 << endl;
	}
	else if (choice == 2) {
		cout << "Please enter the move number of the move whose data you want to print:\n";
		int index = 0;
		cin >> index;
		if (!cin) die();
		Move m;
		for (const Move &mo : move_db) if (index == mo.index) m = mo;
		if (m.name == "Error") cout << "No move loaded with that index.\n";
		else
			cout << "Move Index " << m.index << ": " << m.name << " " << " type: " << m.type << " category: " << m.category << " PP: " << m.PP << " power: " << m.power << " accuracy: " << m.accuracy << "%\n";
	}
	if (choice == 3) battle_mode(); //PART 2
	else explore_mode(); //PART 2
}
