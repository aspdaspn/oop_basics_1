#include <main.h>

template <class T>
class Pair1 {
	private:
		T m_first;
		T m_second;
	
	public:
		Pair1(T first, T second) : m_first(first), m_second(second) {
		}
		
		T first() const {
			return m_first;
		}

		T second() const {
			return m_second;
		}
};

template <class T1, class T2>
class Pair {
	protected:
		T1 m_first;
		T2 m_second;
	public:
		Pair(T1 first, T2 second) : m_first(first), m_second(second) {
		}

		T1 first() const {
			return m_first;
		}

		T2 second() const {
			return m_second;
		}
};

template <class T>
class StringValuePair : public Pair<std::string, T> {
	public:
		StringValuePair(std::string first, T second) : Pair<std::string, T> (first, second) {
		}
};

int main(int argc, char** args) {
	// Task 1
	{
		Pair1<int> p1(6, 9);
		std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
		const Pair1<double> p2(3.4, 7.8);
		std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}
	
	// Task 2
	{
		Pair<int, double> p1(6, 7.8);
		std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
		const Pair<double, int> p2(3.4, 5);
		std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}

	// Task 3
	{
		StringValuePair<int> svp("Amazing", 7);
		std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	}

	return EXIT_SUCCESS;
}
