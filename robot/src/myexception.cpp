#include <iostream>
#include <stdexcept>
#include "myexception.h"
using namespace std;

Exception::Exception(int x, int y, char direction) : m_x(x), m_y(y), m_direction(direction) {
}

Exception::~Exception() {
}

string Exception::description() const {
	return ""; 
}

IllegalCommand::IllegalCommand(int x, int y, char direction) : Exception(x, y, direction) {
}

IllegalCommand::~IllegalCommand() {
}

string IllegalCommand::description() const {
	return "Wrong movement: " + string(1, m_direction);
}

OffTheField::OffTheField(int x, int y, char direction) : Exception(x, y, direction) {
}

OffTheField::~OffTheField() {
}

string OffTheField::description() const {
	return "Out of the field. x = " + to_string(m_x) + " y = " + to_string(m_y) + ", movement: " + string(1, m_direction);
}
