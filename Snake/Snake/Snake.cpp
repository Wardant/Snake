#include"Snake.h"


Snake::Snake() {
	using namespace std;
	indicator = true;
	delay = 0.4s;
}



void Snake::direction_snake(Point &ob) {
	using namespace std;

	//_kbhit() ���������� true, ���� ������ �������
	//_getch() ����� ������� ������� � ����� ��� ��������


	if (_kbhit()) {
		char ch = _getch();

		//������������� ����� ������, �������� ��������� ������
		if (dir == RIGHT && ch == 'a') {
			dir = RIGHT;
		}
		else if (dir == LEFT && ch == 'd') {
			dir = LEFT;
		}
		else if (dir == UP && ch == 's') {
			dir = UP;
		}
		else if (dir == DOWN && ch == 'w') {
			dir = DOWN;
		}
		else {
			for (auto elem : command) {
				if (elem.first == ch) {
					dir = elem.second;
				}
			}
		}


	}

	this_thread::sleep_for(delay);
	switch (dir)
	{
	case LEFT:
		ob.x--;
		break;
	case RIGHT:
		ob.x++;
		break;
	case UP:
		ob.y--;
		break;
	case DOWN:
		ob.y++;
		break;
	}


}

void Snake::move_and_grow(std::list<Point> &list, Point &obH, Point &obF,
	Screen &ob)
{
	using namespace std;

	Point temp;

	//���� ���������� ��������� ����������� 1 ������� ����
	// + 10 �����
	// � ���������� �������� ��� ��������� �������� ������
	if (obH == obF) {
		obF.point_food(list);
		list.push_front(obH);
		score += 10;
		delay -= 10ms;
	}

	//�� ������ �������� ��������� �� 1 ������� � ���������,
	//����� ������� ������ �� ��� ����������� � ������� ������
	if (list.size() == 0) {
		list.push_back(obH);
	}
	else {
		temp = list.back();
		ob.pos(temp.x, temp.y, ' ');
		list.pop_back();
		list.push_front(obH);
	}
}


void Snake::chek_body(std::list<Point> &list, Point &obj) {
	for (auto &elem : list) {
		if (obj == elem) {
			indicator = false;
		}
	}
}


void Snake::check_walls(Point &obj) {
	if (obj.x == 79 || obj.y == 23 || obj.x == 0 || obj.y == 0) {
		indicator = false;
	}
}

void Snake::dir_reset() {
	dir = RIGHT;
}