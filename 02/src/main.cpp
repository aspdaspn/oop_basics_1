#include <main.h>

// Task 1
class Person {
public:
	std::string m_name;
	unsigned short m_age;
	std::string m_gender;
	unsigned short m_weight;
	
	Person(std::string name = "", unsigned int age = 0, unsigned int weight = 0, std::string gender = "") 
	: m_name(name), m_age(age), m_weight(weight), m_gender(gender){
	}
	
	void change() {
		std::cout << "Enter new name: ";
		getline(std::cin, m_name);
		std::cout << "Enter new age: ";
		std::cin >> m_age;
		std::cout << "Enter Gender (Male | Female): ";
		std::cin.ignore();
		getline(std::cin, m_gender);
		std::cout << "Enter new weight: ";
		std::cin >> m_weight;
	}

};

class Student : public Person {
public:
	unsigned short m_id;
	unsigned short m_year;

	Student(unsigned int year = 0, unsigned int id = 0)
	: m_year(year), m_id(id) {
	}

	void setYear(unsigned int year) {
		m_year = year;
		return;
	}	

	void nextYear() {
		m_year++;
		return;
	}	

	void print() {
		std::cout << "ID: " << m_id << "\n";
		std::cout << "Name: " << m_name << "\n";
		std::cout << "Age: " << m_age << "\n";
		std::cout << "Gender: "<< m_gender << "\n";
		std::cout << "Weight: " << m_weight << "\n";
		std::cout << "Year: " << m_year << "\n";
	}
};

//Task 2
class Fruit {
	public:
		std::string m_name;
		std::string m_color;
		Fruit(std::string name = "", std::string color = "") {
		}
		
		std::string getName() {
			return m_name;
		}

		std::string getColor() {
			return m_color;
		}
};

class Apple : public Fruit {
	public:
		Apple(std::string color = ""){
			m_name = "apple";
			m_color = color;
		}
};

class Banana : public Fruit {
	public:
		Banana(){
			m_name = "banana";
			m_color = "yellow";
		}
};

class GrannySmith : public Apple {
	public:
		GrannySmith(){
			std::string temp = m_name;
			m_name = "Granny Smith ";
			m_name.append(temp);
			m_color = "green";
		}
};

int main(int argc, char** args) {
	//Task 1
	Student group[10];
	char input;
	int i = 0;
	do {
		std::cout << "Enter new Student:\n";
		group[i].change();
		group[i].setYear(1);
		group[i].m_id = i;
		i++;
		std::cout << "Press 'x' to exit or any key to continue\n";
		std::cin >> input;
		std::cin.ignore();
	} while (input != 'x');
	i = 0;
	int id = 0;
	do {
		std::cout << "Enter Student ID for output:\n";
		std::cin >> id;
		std::cin.ignore();
		group[id].print();
		std::cout << "Press 'x' to exit or any key to continue\n";
		std::cin >> input;
		std::cin.ignore();
	} while (input != 'x');
	
	// Task 2
	Apple a("red");
	Banana b;
	GrannySmith c;
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n" ;
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n" ;
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n" ;
	return SUCCESS;

	// Task 3
	// class Card {
	// }
	// 
	// class Deck : public Card {
	// }
	//
	// class Player {
	// }
	//
	// class AI : public Player {
	// }
	//
	// class Human : public Player {
	// }
}
