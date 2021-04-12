#ifndef ROBOT_H
#define ROBOT_H

class Robot {
	private:
		int m_id;
		int m_x = 0;
		int m_y = 0;
	
	public:
		Robot(int id);
		~Robot();
		void move(char direction);
		bool isPresent(int x, int y) const;
};
#endif
