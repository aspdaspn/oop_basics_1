#include <main.h>
int main(int argc, char** args) {
	// Task 1
	int digit;
	do {
		std::cout << "Enter an integer, 0 to exit: ";
		std::cin >> digit;
		if (std::cin.fail()) {
			std::cout << "\nYou entered something wrong!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			digit = -1;
		}
	} while (digit !=0);
	return EXIT_SUCCESS;
}
