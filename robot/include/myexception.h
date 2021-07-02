#include <iostream>
#include <string>
#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
using namespace std;

class Exception {
	protected:
		int m_x;
		int m_y;
		char m_direction;

	public:
		Exception(int x, int y, char direction);
		~Exception();

		virtual string description() const;
};

class IllegalCommand : public Exception {
	public:
		IllegalCommand(int x, int y, char direction);
		~IllegalCommand();
		string description() const;
};

class OffTheField : public Exception {
	public:
		OffTheField(int x, int y, char direction);
		~OffTheField();
		string description() const;
};

#endif
