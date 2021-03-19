#pragma once
#include<windows.h>
#include<iostream>
#include"Point.h"


class Screen {
public:

	Screen();
	
	void pos(int, int, char); // выведение координат
	void draw_field(); // отрисовка игрового поля

private:

	// получение экранного дескриптора своего рода номер экрана вывода
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	void screen_w(); // отрисовка экрана без прокрутки

};



