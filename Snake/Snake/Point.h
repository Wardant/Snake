#pragma once
#include<iostream>
#include<list>
#include<random>


class Point {
public:

	friend const bool operator==(const Point &, const Point &);

	Point() : x(0), y(0), sym() {};
	~Point() {};
	
	void point_food(std::list<Point> &);
	void coord_head_snake();

	int x;
	int y;
	char sym;

private:

	std::default_random_engine d_r_e;

};

