#include "main.h"
#include "card.h"
#include "hand.h"
#include "genplayer.h"
#include "player.h"
#include "house.h"
#include "deck.h"
#include "game.h"

using namespace std;

int main(int argc, char** args) {
	cout << "\t\tWelcome to Blackjack!\n\n";
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7) {
		cout << "How many players? (1 - 7): ";
		cin >> numPlayers;
	}
	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i) {
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;
	// Game loop
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N') {
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}
	return EXIT_SUCCESS;
}
