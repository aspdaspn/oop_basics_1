#ifndef HOUSE_H
#define HOUSE_H

class House : public GenericPlayer {
	public:
		House(const string& name = "House");

		virtual ~House();

		// shows if dealer wants to take another card
		virtual bool IsHitting() const;

		// turns the first card
		void FlipFirstCard();
};
#endif
