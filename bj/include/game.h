#ifndef CARD_H
#define CARD_H

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
}
#endif
