#include "hand.h"

Hand::Hand() {
	m_Cards.reserve(7);
}

Hand::~Hand() {
	Clear();
}

// Method to add card to hand
void Hand::Add(Card *pCard) {
	m_Cards.push_back(*pCard);
}

// Method to clear Hand
void Hand::Clear() {
	// go over the vector dealocating the value in Heap
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
		delete *iter;
		*iter = 0;
	}
	m_Cards.clear();
}

// Method returns Hand Value
int Hand::GetTotal() const {
	// If no cards on hand, return 0
	if (m_Cards.empty()) {
		return 0;
	}

	// If first card has value = 0, it face down. Return 0
	if (m_Cards[0] -> GetValue() == 0) {
		return 0;
	}

	// Get sum of all card values. Ace bring 1 at this step
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
		total += (*iter) -> GetValue();
	}

	// Check if an Ace is present on the Hand
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
		if ((*iter) -> GetValue() == Card::ACE) {
			containsAce = true;
		}
	}

	// If an Ace is present and the Hand value is low, Ace gives 11 points
	if (containsAce && total <= 11) {
		// add only 10 points because we gave 1 point for an Ace already
		total += 10;
	}

	return total;
}
}
		
