#include "card.h"
		
// Method Flip reverses the card
bool Card::Flip() {
	return !m_flip;
}

// Method GetValue returns the Card value
int Card::GetValue() const {
	return m_value;
}
