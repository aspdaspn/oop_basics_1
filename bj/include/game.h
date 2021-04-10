#include <iostream>
#include <vector>
#ifndef GAME_H
#define GAME_H

class Game {
	public:
		Game(const vector<string>& names);
		~Game();
		// plays Blackjack
		void Play();
	private:
		Deck m_Deck;
		House m_House;
		vector<Player> m_Players;
};
#endif
