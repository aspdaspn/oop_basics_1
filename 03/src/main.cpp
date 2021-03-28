#include <main.h>

/* Task 1
 * Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram
 * (параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle
 * (прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы.
 * Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных
 * классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/
class Figure {
public:
	virtual double area() = 0;
};

class Parallelogram: public Figure {
protected:
	float m_aSide;
	float m_bSide;
	float m_height;
public:
	Parallelogram(float aSide, float bSide, float height)
	: m_aSide(aSide), m_bSide(bSide), m_height(height) {
	}

	double area() {
		return m_aSide * m_height;
	}
};

class Circle: public Figure {
protected:
	float m_radius;
public:	
	Circle(float radius) 
	: m_radius(radius) {
	}

	double area() {
		return 3.14 * m_radius * m_radius;
	}
};

class Rectangle: public Parallelogram {
public:
	Rectangle(float aSide, float bSide) : Parallelogram(aSide, bSide, m_height) {
		m_aSide = aSide;
		m_bSide = bSide;
	}

	double area() {
		return m_aSide * m_bSide;
	}
};

class Square: public Parallelogram {
public:
	Square(float aSide) : Parallelogram(aSide, m_bSide, m_height) {
		m_aSide = aSide;
	}

	double area() {
		return m_aSide * m_aSide;
	}
};

class Rhombus: public Parallelogram {
public:
	Rhombus(float aSide, float bSide, float height) : Parallelogram(aSide, bSide, height) {
		m_aSide = aSide;
		m_bSide = bSide;
		m_height = height;
	}

	double area() {
		return m_aSide * m_height;
	}
};

/* Task 2
 * Создать класс Car (автомобиль) с полями company (компания) и model (модель).
 * Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов
 * наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они
 * выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой
 * последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
*/

class Car {
protected:
	std::string m_company;
	std::string m_model;
public:
	Car(std::string company, std::string model) 
	: m_model(model), m_company(company) {
		std::cout << m_company << " " << m_model << "\n";
	}
};

class PassengerCar: virtual public Car {
public:
	PassengerCar(std::string company, std::string model)
	: Car(company, model) {
		std::cout << "Passenger Car\n";
	}
};

class Bus: virtual public Car {
public:
	Bus(std::string company, std::string model)
	: Car(company, model) {
		std::cout << "Bus\n";
	}
};

class Minivan: public PassengerCar, public Bus {
public:
	Minivan(std::string company, std::string model)
	: PassengerCar(company, model), Bus(company, model), Car(company, model) {
		std::cout << "Minivan\n";
	}
};

/* Task 3
 * Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или
 * 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
 * ● математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
 * ● унарный оператор (-)
 * ● логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
*/
class Fraction {
	private:
		int m_numerator;
		int m_denominator;
	public:
		Fraction() {
			m_numerator = 0;
			m_denominator = 1;
		}

		Fraction (int numerator, int denominator) 
		:	m_numerator(numerator), m_denominator(denominator) {
			if (!m_denominator) {
				m_numerator = 0;
				m_denominator = 1;
			}
		}
		
		int getFractionNumerator() const {
			return m_numerator;
		}

		int getFractionDenominator() const {
			return m_denominator;
		}

		void printFraction() const {
			std::cout << m_numerator << "/" << m_denominator << "\n";
		}

		friend Fraction operator+ (const Fraction &fr1, const Fraction &fr2);
		friend Fraction operator- (const Fraction &fr1, const Fraction &fr2);
		friend Fraction operator* (const Fraction &fr1, const Fraction &fr2);
		friend Fraction operator/ (const Fraction &fr1, const Fraction &fr2);

		Fraction operator-() {
			m_numerator = -m_numerator;
			m_denominator = -m_denominator;
			return Fraction(m_numerator, m_denominator);
		}

		friend bool operator== (const Fraction &fr1, const Fraction &fr2);
		friend bool operator!= (const Fraction &fr1, const Fraction &fr2);
		friend bool operator< (const Fraction &fr1, const Fraction &fr2);
		friend bool operator> (const Fraction &fr1, const Fraction &fr2);
		friend bool operator<= (const Fraction &fr1, const Fraction &fr2);
		friend bool operator>= (const Fraction &fr1, const Fraction &fr2);
};

Fraction operator+ (const Fraction &fr1, const Fraction &fr2) {
	Fraction result;
	if (fr1.m_denominator == fr2.m_denominator) {
		result.m_numerator = fr1.m_numerator + fr2.m_numerator;
		result.m_denominator = fr1.m_denominator;
	} else {
		result.m_numerator = (fr1.m_numerator*fr2.m_denominator) + (fr2.m_numerator*fr1.m_denominator);
		result.m_denominator = fr1.m_denominator * fr2.m_denominator;
	}
	return result;
}

Fraction operator- (const Fraction &fr1, const Fraction &fr2) {
	Fraction result;
	if (fr1.m_denominator == fr2.m_denominator) {
		result.m_numerator = fr1.m_numerator - fr2.m_numerator;
		result.m_denominator = fr1.m_denominator;
	} else {
		result.m_numerator = (fr1.m_numerator*fr2.m_denominator) - (fr2.m_numerator*fr1.m_denominator);
		result.m_denominator = fr1.m_denominator * fr2.m_denominator;
	}
	return result;
}

Fraction operator* (const Fraction &fr1, const Fraction &fr2) {
	Fraction result;
	result.m_numerator = fr1.m_numerator * fr2.m_numerator;
	result.m_denominator = fr1.m_denominator * fr2.m_denominator;
	return result;
}

Fraction operator/ (const Fraction &fr1, const Fraction &fr2) {
	Fraction result;
	result.m_numerator = fr1.m_numerator * fr2.m_denominator;
	result.m_denominator = fr1.m_denominator * fr2.m_numerator;
	return result;
}

bool operator== (const Fraction &fr1, const Fraction &fr2) {
	if (fr1.m_denominator == fr2.m_denominator)
		return (fr1.m_denominator == fr2.m_denominator && fr1.m_numerator == fr2.m_numerator);
	else {
		Fraction c1;
		Fraction c2;
		c1.m_numerator = (fr1.m_numerator*fr2.m_denominator);
		c2.m_numerator = (fr2.m_numerator*fr1.m_denominator);
		c1.m_denominator = fr1.m_denominator * fr2.m_denominator;
		c2.m_denominator = c1.m_denominator;
		return (c1.m_denominator == c2.m_denominator && c1.m_numerator == c2.m_numerator);
	}
}

bool operator!= (const Fraction &fr1, const Fraction &fr2) {
	return !(fr1 == fr2);
}

bool operator< (const Fraction &fr1, const Fraction &fr2) {
	if (fr1.m_denominator == fr2.m_denominator)
		return (fr1.m_numerator < fr2.m_numerator);
	else {
		Fraction c1;
		Fraction c2;
		c1.m_numerator = (fr1.m_numerator*fr2.m_denominator);
		c2.m_numerator = (fr2.m_numerator*fr1.m_denominator);
		c1.m_denominator = fr1.m_denominator * fr2.m_denominator;
		c2.m_denominator = c1.m_denominator;
		return (c1.m_numerator < c2.m_numerator);
	}
}

bool operator> (const Fraction &fr1, const Fraction &fr2) {
	if (fr1.m_denominator == fr2.m_denominator)
		return (fr1.m_numerator > fr2.m_numerator);
	else {
		Fraction c1;
		Fraction c2;
		c1.m_numerator = (fr1.m_numerator*fr2.m_denominator);
		c2.m_numerator = (fr2.m_numerator*fr1.m_denominator);
		c1.m_denominator = fr1.m_denominator * fr2.m_denominator;
		c2.m_denominator = c1.m_denominator;
		return (c1.m_numerator > c2.m_numerator);
	}
}

bool operator<= (const Fraction &fr1, const Fraction &fr2) {
	return !(fr1 > fr2);
}

bool operator>= (const Fraction &fr1, const Fraction &fr2) {
	return !(fr1 < fr2);
}

/* Task 4
 * Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три
 * поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля
 * масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в
 * этом классе должно быть два метода:
 * ● метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он
 * ее поворачивает лицом вверх, и наоборот.
 * ● метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/
enum Suit {Diamonds, Clubs, Hearts, Spades};
enum Value {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
class Card {
	private:
		Suit m_suit;
		Value m_value;
		bool m_flip;
	public:
		Card() {
		}
		
		bool Flip() {
			return !m_flip;
		}

		int GetValue() const {
			return m_value;
		}
};

int main(int argc, char** args) {
	// Task 1
	Rhombus rhombus(10, 7, 3);
	std::cout << rhombus.area() << std::endl;
	Circle circle(3);
	std::cout << circle.area() << std::endl;

	// Task 2
	Minivan minivan("Ford", "S-Max");

	// Task 3
	Fraction f1(1, 2);
	Fraction f2(3, 2);
	Fraction f3;
	f3 = f1 + f2;
	f3 = f3 - f2;
	-f3;
	f3.printFraction();
	(f1 != f2) ? std::cout << "Not Equal\n" : std::cout << "Equal\n";
	(f1 < f2) ? std::cout << "Less\n" : std::cout << "More\n";
	return EXIT_SUCCESS;
}
