#include "main.h"
using namespace std;

ostream& endll(ostream& os) {
	os.flush();
	return os << "\n\n";
}


int main(int argc, char** args) {
	// Task 1
	int digit;
	do {
		cout << "Enter an integer, 0 to exit: ";
		cin >> digit;
		if (cin.fail()) {
			cout << "\nYou entered something wrong!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			digit = -1;
		}
	} while (digit !=0);
	// Task 2
	cout << "It should be" << endll;
	cout << "Two lines free above this" << endl;
	return EXIT_SUCCESS;
}
