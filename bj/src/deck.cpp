#include <algorithm>
#include <vector>
#include <iostream>
#include "card.h"
#include "hand.h"
#include "genplayer.h"
#include "deck.h"

using namespace std;

Deck::Deck() {
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck() {
}

void Deck::Populate() {
	Clear();
	// Make standard Deck
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
		for (int r = Card::ACE; r <= Card::KING; ++r) {
			Add(new Card(static_cast<Card::rank>(r),
									 static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle() {
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand) {
	if (!m_Cards.empty()) {
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else {
		cout << "Out of cards. Unable to deal.";
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer) {
	cout << endl;
	// Deals cards until a player get busted or he stops taking cards
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()) {
		Deal (aGenericPlayer);
		cout << aGenericPlayer << endl;

		if (aGenericPlayer.IsBusted()) {
			aGenericPlayer.Bust();
		}
	}
}

