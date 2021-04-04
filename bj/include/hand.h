#ifndef HAND_H
#define HAND_H
using namespace std;

// Class Hand
class Hand {
	private:
		vector <Card*> m_hand;
	public:
		Hand() { };
		~Hand() {
			m_hand.Clear();
		}
		void Add(Card *card);
		void Clear();
		int GetValue();
};
#endif
