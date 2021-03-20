#include"Point.h"


void Point::point_food(std::list<Point> &list) {

	//��������� ��������� ����� ��������� ���
	std::uniform_int_distribution<int> uid_x(2, 78);
	std::uniform_int_distribution<int> uid_y(2, 22);

	x = uid_x(d_r_e);
	y = uid_y(d_r_e);

	//�������� ��� �� ���������� �� ���������� � ���� ������
	for (auto &elem : list) {
		if (x == elem.x && y == elem.y) {
			x++;
			y++;
		}
	}

	sym = (' ', 48); // food symbol
}


void Point::coord_head_snake() {
	x = 80 / 2;
	y = 25 / 2;
	sym = '@';
}

const bool operator==(const Point &left, const Point &right) {
	if (left.x == right.x && left.y == right.y) {
		return true;
	}
	else {
		return false;
	}
}

