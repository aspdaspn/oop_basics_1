#ifndef GENERIC_PLAYER_H
#define GENERIC_PLAYER_H

class GenericPlayer : public Hand {
	friend ostream& operator<< (ostream& os, const GenericPlayer& aGenericPlayer);

	public:
		GenericPlayer(const string& name = "");

		virtual ~GenericPlayer();

		// Returns if a player need a card
		virtual bool IsHitting() const = 0;
		
		// Hand Sum more than 21
		bool IsBusted() const;

		// output about excess
		void Bust() const;

	protected:
		string m_Name;
};
#endif
