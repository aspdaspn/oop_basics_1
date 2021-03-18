#include <main.h>

class Figure {
public:
	virtual double area() = 0;
};

class Parallelogram: public Figure {
public:
	float m_aSide;
	float m_bSide;
	float m_height;

	Parallelogram(float aSide, float bSide, float height)
	: m_aSide(aSide), m_bSide(bSide), m_height(height) {
	}

	double area() {
		return m_aSide * m_height;
	}
};

class Circle: public Figure {
public:
	float m_radius;
	
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

int main(int argc, char** args) {
	Rhombus rhombus(10, 7, 3);
	std::cout << rhombus.area() << std::endl;
	Circle circle(3);
	std::cout << circle.area() << std::endl;
	return EXIT_SUCCESS;
}
