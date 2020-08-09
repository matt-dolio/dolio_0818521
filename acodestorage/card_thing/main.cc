#include <iostream>
#include <vector>
using namespace std;

int main() {
	string royalty[4] = {"Ace", "Jack", "Queen", "King"};
	string suit[4] = {"Hearts", "Spades", "Clubs", "Diamonds"};
	vector<string> royalCards;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			royalCards.push_back(royalty[i] + " of " + suit[j]);
		}
	}

	for (int i = 0; i < 16; i++) {
		cout << royalCards[i] << endl;
	}

	return 0;
}

