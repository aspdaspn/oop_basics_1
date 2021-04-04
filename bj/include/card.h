#ifndef CARD_H
#define CARD_H

/* 
 * Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три
 * поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля
 * масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в
 * этом классе должно быть два метода:
 * ● метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он
 * ее поворачивает лицом вверх, и наоборот.
 * ● метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/

// Card Suits
enum Suit {Diamonds, Clubs, Hearts, Spades};

// Card values
enum Value {Ace, Two= 2, Three = 3, Four = 4, Five = 5, Six = 6, 
	Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 10, Queen = 10, King = 10};

//Class Card
class Card {
	private:
		Suit m_suit;
		Value m_value;
		bool m_flip;
	public:
		Card() { };
		bool Flip();
		int GetValue() const;
};
#endif
