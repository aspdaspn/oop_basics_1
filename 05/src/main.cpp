#include <main.h>

template <class T>
class Pair1 {
	private:
		T m_first;
		T m_second;
	
	public:
		Pair1(T first, T second) :
		m_first(first), m_second(second) {
		}
		
		T first() const {
			return m_first;
		}

		T second() const {
			return m_second;
		}

};

int main(int argc, char** args) {
	// Task1
	Pair1<int> p1(6, 9);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	const Pair1<double> p2(3.4, 7.8);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	
	return EXIT_SUCCESS;
}
