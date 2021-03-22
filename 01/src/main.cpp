#include <main.h>

class Power {
	float base = 2;
	float exp = 3;

public:
	Power() {
	}

	void setPowerValues(float b, float e) {
		base = b;
		exp = e;
	}
	
	float calcPower() {
		return std::pow(base, exp);
	}
};

class RGBA {
	std::uint8_t m_red = 0;
	std::uint8_t m_green = 0;
	std::uint8_t m_blue = 0;
	std::uint8_t m_alpha = 255;

public:
	RGBA() {
	}
	
	RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) 
	: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {
	}

	void print() {
		std::cout << "Red: " << unsigned(m_red) << "\n";
		std::cout << "Green: " << unsigned(m_green) << "\n";
		std::cout << "Blue: " << unsigned(m_blue) << "\n";
		std::cout << "Alpha: " << unsigned(m_alpha) << "\n";
	}
};

class Stack {
	int *m_array;
	const int m_len;
	int m_stackPos;

public:
	Stack(const int len) {
		assert(len > 0);
		m_array = new int[len];
		m_len = len;
		m_stackPos = 0;
	}

	void reset() {
		for (int i = 0; i < m_len; i++)
			*(m_array + i) = 0;
		m_stackPos = 0;
	}
	
	bool push(int value) {
		return ((m_stackPos < m_len) && (*(m_array + m_stackPos++) = value));
	}

	int pop() {
		if (m_stackPos < 0) {
			std::cout << "Empty Stack!\n";
			return 0;
		}
		int output = *(m_array + --m_stackPos);
		*(m_array + m_stackPos) = 0;
		return output;
	}

	void print() {
		std::cout << "( ";
		for (int i = 0; i < m_stackPos; i++)
			std::cout << *(m_array + i) << " ";
		std::cout << ")\n";
	}

	~Stack() {
		delete[] m_array;
	}
};

struct Node {
	int data;
	Node *next;
};

class StackDDS {
	Node *head;
	int m_size;
	int m_maxSize;
public:
	StackDDS(int maxSize)
	: m_maxSize(maxSize), m_size(0), head(NULL) {
	}

	bool push(int value) {
		if (m_size >= m_maxSize)
			return false;
		Node *temp = new Node;
		temp -> data = value;
		temp -> next = head;
		head = temp;
		m_size++;
		return true;
	}

	int pop() {
		if (m_size == 0) {
			std::cout << "Stack is empty!\n";
			return 0;
		}
		Node *next = NULL;
		int value;
		value = head -> data;
		next = head;
		head = head -> next;
		delete[] next;
		m_size--;
		return value;
	}

	void print() {
		Node *current = head;
		std::cout << "( ";
		while(current != NULL) {
			std::cout << current -> data << " ";
			current = current -> next;
		}
		std::cout << ")\n";
	}
};

int main(int argc, char** args) {
	// Task 1
	Power p;
	std::cout << p.calcPower() << "\n";
	p.setPowerValues(4.5, 1.2);
	std::cout << p.calcPower() << "\n";

	//Task 2
	RGBA baseColor;
	baseColor.print();
	RGBA myColor(255, 153, 102, 127);
	myColor.print();

	//Task 3
	Stack stack(10);
	stack.reset();
	stack.print();
	stack.push(3) ? std::cout << "Success\n" : std::cout << "Stack Overflow\n";
	stack.push(7) ? std::cout << "Success\n" : std::cout << "Stack Overflow\n";
	stack.push(5) ? std::cout << "Success\n" : std::cout << "Stack Overflow\n";
	stack.print();
	std::cout << stack.pop() << "\n";
	stack.print();
	std::cout << stack.pop() << "\n";
	std::cout << stack.pop() << "\n";
	stack.print();

	//Task3 Dynamic Data structures
	StackDDS sdds(10);
	sdds.push(9);
	sdds.push(8);
	sdds.push(7);
	sdds.print();
	std::cout << sdds.pop() << "\n";
	std::cout << sdds.pop() << "\n";
	sdds.print();
	return SUCCESS;
}
