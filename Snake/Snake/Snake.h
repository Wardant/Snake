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

	void direction_snake(Point &); //направление движения змейки
	//непосредственное изменение координат, и приращивание сегментов тела
	void move_and_grow(std::list<Point> &, Point &, Point &, Screen &);

	void check_walls(Point &);// проверка столкновения со стеной
	void chek_body(std::list<Point> &, Point &);// проверка столкновения с телом

	int score = 0; // сумма игровых очков

	void dir_reset();//функция сброса направления движения

	/*переменная которая будет отслеживать столкнулись змейка со своим
	телом или стеной, изначально она будет true для того что бы после изменения
	состояния она передала значение false и цикл и завершил игру*/
	bool indicator;
	

private:
	
	enum  Direction { RIGHT, LEFT, UP, DOWN, STOP };// команды для направления змейки
	Direction dir;

	std::chrono::duration<double> delay; // задержка скорости движения змейки

	std::map<char, Direction> command{
		{ 'a', LEFT },
		{ 'd', RIGHT },
		{ 'w', UP },
		{ 's', DOWN }	
	};

};

