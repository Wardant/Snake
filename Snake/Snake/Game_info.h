#pragma once
#include<iostream>
#include<conio.h>
#include<chrono>
#include<list>
#include<cstdlib> 
#include"Screen.h"
#include"Snake.h"
#include"Point.h"



class Game_info {
public:

	void menu(Screen &);

	void score_and_time_info(Screen &, Snake &);
	void end_game(Screen &);

	bool play_again(Screen &);
	void restart_game(std::list<Point> &, Point &, Point &, Snake &);

	void start_timer();
	void finish_timer();
	void check_char();

private:

	char ch, y = 'Y', n = 'N';

	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> finish;

};
