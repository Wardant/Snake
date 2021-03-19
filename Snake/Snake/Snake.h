#pragma once
#include<iostream>
#include<conio.h>
#include<thread>
#include<chrono>
#include<list>
#include<map>
#include"Point.h"
#include"Screen.h"



class Snake {
public:

	Snake();

	void direction_snake(Point &); //����������� �������� ������
	//���������������� ��������� ���������, � ������������ ��������� ����
	void move_and_grow(std::list<Point> &, Point &, Point &, Screen &);

	void check_walls(Point &);// �������� ������������ �� ������
	void chek_body(std::list<Point> &, Point &);// �������� ������������ � �����

	int score = 0; // ����� ������� �����

	void dir_reset();//������� ������ ����������� ��������

	/*���������� ������� ����� ����������� ����������� ������ �� �����
	����� ��� ������, ���������� ��� ����� true ��� ���� ��� �� ����� ���������
	��������� ��� �������� �������� false � ���� � �������� ����*/
	bool indicator;
	

private:
	
	enum  Direction { RIGHT, LEFT, UP, DOWN, STOP };// ������� ��� ����������� ������
	Direction dir;

	std::chrono::duration<double> delay; // �������� �������� �������� ������

	std::map<char, Direction> command{
		{ 'a', LEFT },
		{ 'd', RIGHT },
		{ 'w', UP },
		{ 's', DOWN }	
	};

};

