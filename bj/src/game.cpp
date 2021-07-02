#include <vector>
#include <iostream>
#include "card.h"
#include "hand.h"
#include "genplayer.h"
#include "player.h"
#include "house.h"
#include "deck.h"
#include "game.h"

using namespace std;

// Constructor accepts a pointer to the vector of strings containing Human-name players.
// It creates an Player-class object for every name.
Game::Game(const vector<string>& names) {
	// creates vector of players from vector with names
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName) {
		m_Players.push_back(Player(*pName));
	}

	// starts a random generator
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}

Game::~Game() {
}

void Game::Play() {
	// Hands round two start cards among everyone
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i) {
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}

	// Hides the first Dealers card
	m_House.FlipFirstCard();

	// Opens all player cards
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		cout << *pPlayer << endl;
	}
	cout << m_House << endl;
	
	// Hands round additional cards among players
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		m_Deck.AdditionalCards(*pPlayer);
	}

	// shows Dealers first card
	m_House.FlipFirstCard();
	cout << endl << m_House;

	// Hands round additional cards to dealer
	m_Deck.AdditionalCards(m_House);
	if (m_House.IsBusted()) {
		// All left players win
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			if (!(pPlayer -> IsBusted())) {
				pPlayer -> Win();
			}
		}
	} else {
		// compares the points of all players with dealer points
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
			if (!(pPlayer -> IsBusted())) {
				if (pPlayer -> GetTotal() > m_House.GetTotal()) {
					pPlayer -> Win();
				}
				else if (pPlayer -> GetTotal() < m_House.GetTotal()) {
					pPlayer -> Lose();
				}
				else {
					pPlayer -> Push();
				}
			}
		}
	}
	// clears players hand
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
		pPlayer -> Clear();
	}
	m_House.Clear();
}

