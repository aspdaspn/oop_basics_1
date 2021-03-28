#include "hand.h"
// Method to add card to hand
void Hand::Add(Card *card) {
	m_hand.push_back(*card);
}

// Method to clear Hand
void Hand::Clear() {
	m_hand.clear();
}

// Method returns Hand Value
int Hand::GetValue() {
	int sum = 0;
	for (int i = 0; i < m_hand.size(); ++i)
		sum += m_hand->m_value[i];
	return sum;
}
		
