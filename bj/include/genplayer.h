#ifndef GENERIC_PLAYER_H
#define GENERIC_PLAYER_H
using namespace std;
// Class Generic Player
class GenericPlayer : public Hand {
	protected:
		string m_name;
	public:
		GenericPlayer(string name) : m_name(name) {
		}
		// Returns if a player need a card
		virtual bool isHitting();
		
		// Hand Sum more than 21
		bool IsBoosted();

		// output about excess
		void Bust();
};
#endif
