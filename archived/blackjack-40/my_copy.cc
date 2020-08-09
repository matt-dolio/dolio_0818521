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
	if (seed == 0) srand(time(0));
	else srand(seed);

	cout << "Welcome to Blackjack-40!\n\n";

	int money = 100;

	while (true) {
		int player_total = 0, dealer_total = 0;
		bool playerBust = false, dealerBust = false, playerBlackjack = false;

		cout << "You currently have $" << money << " and are betting $" << BET << endl;

		//YOU: For each player...
		// I don't recall 40 having to do this...
		/* Player initial card draw */
		for (int i = 0; i < 4; i++) {

			int card = draw_card(); // This is how you deal a card
			string card_name;

			//YOU: Handle aces (a 1 is worth 11)
			if (card == 1) {
				card_name = "an Ace";
			} else if (card == 11) {
				card_name = "a Jack";
				card = 10;
			} else if (card == 12) {
				card_name = "a Queen";
				card = 10;
			} else if (card == 13) {
				card_name = "a King";
				card = 10;
			} else if (card == 8) { // Being grammatically correct with eight because I'm stuffy
				card_name = "an " + to_string(card);
			} else {
				card_name = "a " + to_string(card);
			}
			cout << "You drew " << card_name << endl;
			player_total += card;
		}

		//Then we print the total
		cout << "The total value of your cards is: " << player_total << endl;

		if (player_total == 40) {
			playerBlackjack = true;
		}

		/* Player drawing */
		//YOU: Make an infinite loop for the players drawing cards until they bust or stay or quit
		while (true) {
			if (player_total > 40) {
				cout << "BUST! You lose!\n";
				break;
			} else if (player_total == 40) {
				break;
			}

			cout << "Do you wish to 1) Hit or 2) Stay or 3) Quit?\n";
			int input;
			cin >> input;

			if (!cin) {
				cout << "BAD INPUT!\n";
			} else if (input == 1) {

				int card = draw_card();
				string card_name;

				if (card == 1) {
					card_name = "an Ace";
				} else if (card == 11) {
					card_name = "a Jack";
					card = 10;
				} else if (card == 12) {
					card_name = "a Queen";
					card = 10;
				} else if (card == 13) {
					card_name = "a King";
					card = 10;
				} else if (card == 8) { // Being grammatically correct with eight because I'm stuffy
					card_name = "an " + to_string(card);
				} else {
					card_name = "a " + to_string(card);
				}
				cout << "You drew " << card_name << endl;
				player_total += card;

				cout << "Your total is: " << player_total << "." << endl;

			} else if (input == 2) {
				break;
			} else if (input == 3) {
				cout << "You have quit.\n";
				return 0;
			}
		}

		/* Dealer handling */
		//YOU: After the players are done, draw cards for the dealer until they get a 35 or higher, or bust
		while (true) {
			// I just want to check if player bust first to skip this
			playerBust = (player_total > 40);
			if (playerBust || playerBlackjack) {
				break;
			}

			int card = draw_card();
			string card_name;

			if (card == 1) {
				card_name = "an Ace";
			} else if (card == 11) {
				card_name = "a Jack";
				card = 10;
			} else if (card == 12) {
				card_name = "a Queen";
				card = 10;
			} else if (card == 13) {
				card_name = "a King";
				card = 10;
			} else if (card == 8) { // Being grammatically correct with eight because I'm stuffy
				card_name = "an " + to_string(card);
			} else {
				card_name = "a " + to_string(card);
			}
			cout << "The dealer drew " << card_name << endl;
			dealer_total += card;

			cout << "Dealer total is: " << dealer_total << "." << endl;

			if (dealer_total > 35) {
				break;
			}
		}

		/* Win handling */
		playerBust = (player_total > 40);
		dealerBust = (dealer_total > 40);

		if (playerBlackjack) {
			cout << "BLACKJACK!\n";
			money += BET * 2;
		} else if (playerBust && !dealerBust) {
			cout << "Dealer wins!\n";
			money -= BET;
		} else if (dealerBust && !playerBust) {
			cout << "Dealer busted! You win!\n";
			money += BET;
		} else if (!playerBust && !dealerBust) {
			if (player_total > dealer_total) {
				cout << "You win!\n";
				money += BET;
			} else if (player_total < dealer_total) {
				cout << "Dealer wins!\n";
				money -= BET;
			} else { // PUSH
				cout << "You pushed! No money lost.\n";
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


