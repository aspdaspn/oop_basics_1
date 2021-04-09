#ifndef DECK_H
#define DECK_H

class Deck : public Hand {
	public:
		Deck();
		virtual ~Deck();
		// Make 52-card deck
		void Populate();
		// Shuffle cards
		void Shuffle();
		// Deal single hard to Hand
		void Deal(Hand& aHand);
		// Gives a player an additional card
		void AdditionalCards(GenericPlayer& aGenericPlayer);
};

#endif
