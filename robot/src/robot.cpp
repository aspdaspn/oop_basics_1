#include "globals.h"
#include "robot.h"
#include "myexception.h"

Robot::Robot(int id) : m_id(id) {
}

Robot::~Robot() {
}

void Robot::move(char direction) {
	switch (direction) {
		case 'w':
			--m_y;
			break;
		case 's':
			++m_y;
			break;
		case 'a':
			--m_x;
			break;
		case 'd':
			++m_x;
			break;
		default:
			throw IllegalCommand(m_x, m_y, direction);
	}

	if (m_x < 0 || m_x > SZX) {
		throw OffTheField(m_x, m_y, direction);
	}

	if (m_y < 0 || m_y > SZY) {
		throw OffTheField(m_x, m_y, direction);
	}
}

bool Robot::isPresent(int x, int y) const {
	return ((x == m_x) && (y == m_y));
}
