#ifndef HAND_H
#define HAND_H
using namespace std;

// Class Hand
class Hand {
	private:
		vector <*Card> m_hand;
	public:
		Hand() { };
		~Hand() {
			delete *m_hand;
		}
		void Add(Card *card);
		void Clear();
		int GetValue();
};
#endif
