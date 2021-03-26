#include <main.h>
#include <arrayint.h>
#define SIZE 10
#define BORDER 10

void print(std::vector <int> &a) {
	std::cout << "The length is: " << a.size() << '\n';
	for (int i=0; i< a.size(); i++)
		std::cout << a[i] << ' ';
	std::cout << "\n";
}

int main(int argc, char** args) {
	srand(time(NULL));
	ArrayInt array(SIZE);
	std::vector <int> arrayV(SIZE);

	for (int i = 0; i < SIZE; ++i) {
		array[i] = rand() % BORDER;
		arrayV[i] = rand() % BORDER;
	}
	
	array.printArray();
	std::cout << "\n";
	// Задание 2. pop_back(), pop_front(), sortArray()
	std::cout << array.pop_back() << "\n";
	array.printArray();
	std::cout << "\n";
	std::cout << array.pop_front() << "\n";
	array.printArray();
	std::cout << "\n";
	array.sortArray(0, array.getLength() - 1);
	array.printArray();
	std::cout << "\n";

	// Задание 2. Посчитать сколько разных чисел в векторе	
	std::cout << "Vector: \n";
	print(arrayV);
	// отсортируем вектор
	std::sort(arrayV.begin(), arrayV.end());
	print(arrayV);
	// и посчитаем сколько уникальных чисел
	int counter = 1;
	for (int i = 1; i < arrayV.size(); ++i)
		if (arrayV[i] != arrayV[i - 1])
			++counter;
	std::cout << "Unique: " << counter << "\n";

	return EXIT_SUCCESS;
}
