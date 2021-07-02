#include "globals.h"
#include "main.h"
#include "myexception.h"
#include "robot.h"
using namespace std;

void printField(Robot r) {
	system("clear");
	for (int i = 0; i < SZY; ++i) {
		for (int j = 0; j < SZX; ++j)
			r.isPresent(j, i) ? cout << "R" : cout << "-";
		cout << "\n";
	}
}

int main(int argc, char** args) {
	Robot r(1);
	char d;
	try {
		while (true) {
			printField(r);
			cout << "Up: w, Down: s, Left: a, Right: d\n";
			cin >> d;
			r.move(d);
		}
	}
	catch (Exception& ex) {
		cerr << ex.description() << "\n";
	}
	
	return EXIT_SUCCESS;
}
