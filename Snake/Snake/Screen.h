#pragma once
#include<windows.h>
#include<iostream>
#include"Point.h"


class Screen {
public:

	Screen();
	
	void pos(int, int, char); // ��������� ���������
	void draw_field(); // ��������� �������� ����

private:

	// ��������� ��������� ����������� ������ ���� ����� ������ ������
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	void screen_w(); // ��������� ������ ��� ���������

};



