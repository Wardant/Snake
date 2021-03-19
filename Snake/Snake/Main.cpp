#include<iostream>
#include<list>
#include"Point.h"
#include"Screen.h"
#include"Snake.h"
#include"Game_info.h"







int main(int argc, char **argv) {



	setlocale(LC_ALL, "RUSSIAN");

	Snake objSnake;
	Screen objScreen;
	Game_info objGameInfo;


	objGameInfo.menu(objScreen);


	do {
		std::list<Point> list_point;
		Point objPHead, objPFood;


		objPHead.coord_head_snake();
		objPFood.point_food(list_point);
		objGameInfo.start_timer();

		//первичная отрисовка 3-х сегментов тела змейки
		for (int i = 0; i < 3; i++) {
			objPHead.y++;
			list_point.push_front(objPHead);
		}

		while (objSnake.indicator) {


			objScreen.draw_field();


			objScreen.pos(objPFood.x, objPFood.y, objPFood.sym);
			objScreen.pos(objPHead.x, objPHead.y, objPHead.sym);


			objSnake.move_and_grow(list_point, objPHead, objPFood, objScreen);
			objSnake.direction_snake(objPHead);


			objSnake.chek_body(list_point, objPHead);
			objSnake.check_walls(objPHead);


			objGameInfo.finish_timer();
			objGameInfo.score_and_time_info(objScreen, objSnake);


		}


		objGameInfo.end_game(objScreen);
		objGameInfo.restart_game(list_point, objPHead, objPFood, objSnake);

	} while (objGameInfo.play_again(objScreen));


	return 0;
}
