#include <main.h>
#include <arrayint.h>

int main(int argc, char** args) {
	ArrayInt array(5);
	for (int i = 0; i < 5; ++i)
		array[i] = i + 1;
	array.printArray();
	std::cout << "\n";
	std::cout << array.pop_back() << "\n";
	array.printArray();
	std::cout << "\n";
	std::cout << array.pop_front() << "\n";
	array.printArray();
	std::cout << "\n";
	return EXIT_SUCCESS;
}
