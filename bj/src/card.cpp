#include "card.h"
using namespace std;

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {
}

void Card::Flip() {
	m_IsFaceUp = !(m_IsFaceUp);
}

// Method GetValue returns the Card value
int Card::GetValue() const {
	// if card is tirned face down, return 0
	int value = 0;
	if (m_IsFaceUp) {
		// value is the Card value
		value = m_Rank;
		
		// value is equal to 10 for Jack, Queen and King
		if (value > 10) {
			value = 10;
		}
	}
	
	return value;
}

// Overload the << operator for sending Card object to cout
ostream& operator<< (ostream& os, const Card& aCard) {
	const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	const string SUITS[] = { "c", "d", "h", "s" };

	if (aCard.m_IsFaceUp) {
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	} else {
		os << "XX";
	}

	return os;
}
