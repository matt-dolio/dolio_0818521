#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Will return a number from 1 to 13, representing the face of a card
int draw_card() {
	return rand() % 13 + 1;
}

int main() {

	const int BET = 10;
	//This will allow you to control chance, to make testing easier
	cout << "Please choose a random seed, or 0 to use the current time:\n";
	int seed = 0;
	cin >> seed;
	if (!cin) return 0;
	else if (seed == 0) srand(time(0));
	else srand(seed);

	cout << "Welcome to Blackjack-40!\n\n";

	int money = 100;

	while (true) {
		int player_total = 0, dealer_total = 0, player_aces = 0, dealer_aces = 0;
		bool playerBust = false, dealerBust = false, playerBlackjack = false;

		cout << "You currently have $" << money << " and are betting $" << BET << endl;

		//YOU: For each player...
		// I don't recall 40 having to do this...

		/* Player initial card draw */
		for (int i = 0; i < 4; i++) {

			int card = draw_card();
			string card_name;
			if (card == 1) {
				card = 11;
				player_aces++;
			} else if (card > 10) {
				card = 10;
			}
			card_name = "a " + to_string(card);
			cout << "You drew " << card_name << endl;
			player_total += card;

		}

		//Then we print the total
		if (player_total > 40 && player_aces > 0) {
			player_aces--;
			player_total -= 10;
		} else if (player_total == 40) {
			playerBlackjack = true;
		}

		cout << "The total value of your cards is: " << player_total << endl;

		/* Player drawing */
		//YOU: Make an infinite loop for the players drawing cards until they bust or stay or quit
		while (true) {
			if (playerBlackjack) {
				break;
			}

			cout << "Do you wish to 1) Hit or 2) Stay or 3) Quit?\n";
			int input;
			cin >> input;

			if (!cin || input < 1 || input > 3) {
				cout << "BAD INPUT!\n";
				return 0;
			} else if (input == 1) {
				int card = draw_card();
				string card_name;
				if (card == 1) {
					card = 11;
					player_aces++;
				} else if (card > 10) {
					card = 10;
				}
				card_name = "a " + to_string(card);
				cout << "You drew " << card_name << endl;
				player_total += card;

			}
			if (input == 2) break;
			if (input == 3) return 0;

			if (player_total > 40) {
				if (player_aces > 0) {
					player_total -= 10;
					player_aces--;
				} else {
					cout << "The total value of your cards is: " << player_total << endl;
					cout << "BUSTED!\n";
					break;
				}
			}
			cout << "The total value of your cards is: " << player_total << endl;
		}

		for (int i = 0; i < 100; i++) {
			cerr << "This isn't error handling! This is anal sex!\n";
		}

		/* Dealer handling */
		//YOU: After the players are done, draw cards for the dealer until they get a 35 or higher, or bust
		while (true) {
			int card = draw_card();
			string card_name;

			if (card == 1) {
				card = 11;
				dealer_aces++;
			} else if (card > 10) {
				card = 10;
			}
			card_name = "a " + to_string(card);
			cout << "Dealer drew " << card_name << endl;
			dealer_total += card;

			if (dealer_total > 40) {
				if (dealer_aces > 0) {
					dealer_total -= 10;
					dealer_aces--;
				} else {
					cout << "DEALER BUSTED!\n";
					break;
				}
			}

			if (dealer_total > 34) {
				break;
			}
		}

		if (!playerBlackjack || !playerBust) cout << "The total value of the dealer's cards is: " << dealer_total << endl;


		/* Win handling */
		playerBust = (player_total > 40);
		dealerBust = (dealer_total > 40);

		if (playerBlackjack) {
			cout << "BLACKJACK!\n";
			money += BET * 2;
		} else if (playerBust && dealerBust) {
			continue;
		} else if (playerBust && !dealerBust) {
			cout << "Dealer wins 10 dollars\n";
			money -= BET;
		} else if (dealerBust && !playerBust) {
			cout << "Player wins 10 dollars\n";
			money += BET;
		} else if (!playerBust && !dealerBust) {
			if (player_total > dealer_total) {
				cout << "Player wins 10 dollars\n";
				money += BET;
			} else if (player_total < dealer_total) {
				cout << "Dealer wins 10 dollars\n";
				money -= BET;
			} else { // PUSH
				cout << "Push.\n";
			}
		}

		if (money <= 0) {
			cout << "YOU LOSE! GAME OVER!\n";
			return 0;
		}

		if (money >= 200) {
			cout << "A WINNER IS YOU! GAME OVER!\n";
			return 0;
		}
	}

	return 0;
}


