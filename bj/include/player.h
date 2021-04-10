#include <genplayer.h>
#include <hand.h>
#ifndef PLAYER_H
#define PLAYER_H

class Player : public GenericPlayer {
	public:
		Player(const string& name = "");

		virtual ~Player();

		// returns true if a player wants to take more cards
		virtual bool IsHitting() const;

		// player wins
		void Win() const;

		// player lose
		void Lose() const;

		// Draw
		void Push() const;
};
#endif
