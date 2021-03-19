#include"Screen.h"


Screen::Screen() {
	screen_w();
	draw_field();
}



void Screen::pos(int x, int y, char sym) {

	COORD temp;

	temp.X = static_cast<SHORT>(x);
	temp.Y = static_cast<SHORT>(y);


	SetConsoleCursorPosition(hStdout, temp);
	std::cout << sym;
}

//размер окна консоли без прокрукти
void Screen::screen_w() {


	int width = 80, height = 25;


	//Сначала задаем минимальные значения окна
	SMALL_RECT zeroWindow = { 0, 0, 0, 0 };
	COORD zBuffer = { 1, 1 };
	SetConsoleWindowInfo(hStdout, TRUE, &zeroWindow);
	SetConsoleScreenBufferSize(hStdout, zBuffer);

	//А уже потом изменяем значения на нужные нам
	COORD bufferSize = { width, height };
	SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
	SetConsoleScreenBufferSize(hStdout, bufferSize);
	SetConsoleWindowInfo(hStdout, TRUE, &windowSize);

	
}

void Screen::draw_field() {
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);

	int width = 80, height = 24;
	char sym = '#';


	for (int y = 0; y < height; y++) {
		if (y == 0 || y == height - 1) {
			for (int x = 0; x < width; x++)
				pos(x, y, sym);
		}
		else {
			pos(0, y, sym);
			pos(width - 1, y, sym);
		}
	}

}

