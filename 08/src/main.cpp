#include "main.h"
using namespace std;

class Ex {
	private:
		float x;
	
	public:
		Ex(float value) : x(value) {
		}
		
		float getX() const {
			return x;
		}
};

class Bar {
	private:
		float y;

	public:
		Bar(float value = 0.0) {
		}

		void set(float a) {
			if (y + a > 100) 
				throw Ex(a * y);
			else 
				y = a;
		}
};

template<typename T>
T division(const T numerator, const T denominator) {
	if (denominator == 0)
		throw overflow_error("Division by zero!");
	
	return numerator / denominator;
}


int main(int argc, char** args) {
	// Task 01
	int n = 3;
	int d = 0;
	int r;
	try {
		r = division(n, d);
	}
	catch (overflow_error ex) {
		std::cerr << ex.what() << "\n";
	}
	
	cout << r << "\n";
	
	// Task 02
	Bar bar;
	float input;
	
	try {
		do {
			cout << "Enter value: \n";
			cin >> input;
			bar.set(input);
		} while (input);
	}	
		catch (Ex& ex) {
			cerr << "Exeption: " << ex.getX() << "\n";
		}
	
	
	return EXIT_SUCCESS;
}
