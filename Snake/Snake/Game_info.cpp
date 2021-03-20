#include"Game_info.h"



void Game_info::menu(Screen &obj) {
	using namespace std;

	obj.pos(33, 5, ' ');
	cout << " � � � � � � ";

	obj.pos(36, 7, ' ');
	cout << "Y" << " ����� ";

	obj.pos(36, 8, ' ');
	cout << "N" << " ����� ";

	check_char();

	system("cls");
}

void Game_info::check_char() {
	/*��� ������� ��������� ��� ��������� ������� � ������� �������, � ����������
	������ ������� ����� ���� N � Y*/

	do {
		ch = _getch();

		if (islower(ch)) {
			ch = toupper(ch);
		}

		if (n == ch) {
			exit(0);
		}
	} while (ch != 'Y');

}


void Game_info::score_and_time_info(Screen &ob_sc, Snake &ob_sn) {

	using namespace std;
	using namespace chrono;

	ob_sc.pos(5, 24, '>');

	std::cout << " ���-�� ����� " << ob_sn.score << "  ����� � ����: ";

	auto sec = duration_cast<seconds>(finish - start).count();
	auto min = duration_cast<minutes>(finish - start).count();

	if (sec >= 60) {
		sec %= 60;
	}

	cout << min << " ��� " << sec << " ��� ";
}

void Game_info::start_timer() {
	start = std::chrono::steady_clock::now();
}

void Game_info::finish_timer() {
	finish = std::chrono::steady_clock::now();
}

void Game_info::end_game(Screen &obj) {

	using namespace std;
	system("cls");

	obj.pos(26, 12, ' ');
	cout << " �  �  �  �  �    �  �  �  �  .  .  .  " << endl;

	obj.pos(36, 14, ' ');
	cout << " � ������ ";
	this_thread::sleep_for(5s);

}

bool Game_info::play_again(Screen &obj) {

	using namespace std;
	system("cls");

	obj.pos(26, 8, ' ');
	cout << " � � � � � �   � � �!??? ";

	obj.pos(36, 10, ' ');
	cout << "Y" << " �� ";

	obj.pos(36, 11, ' ');
	cout << "N" << " ��� ";

	check_char();

	if (ch == 'Y') {
		system("cls");
		return true;
	}

}

void Game_info::restart_game(std::list<Point> &list, Point &ob1, Point &ob2,
	Snake &ob3) {

	list.clear();
	ob1.~Point();
	ob2.~Point();
	ob3.dir_reset();
	ob3.indicator = true;

}