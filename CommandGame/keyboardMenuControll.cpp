#include "consoleCommands.h"
#include <conio.h>
#include <vector>

#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80
#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77

using namespace std;

int menuControl(const char* menu[], int menuSize, int startLineX = 0, int startLineY = 0,
	int normalTextColor = WHITE, int normalBgColor = BLACK, int highlightedTextColor = BLACK,
	int highlightedbgColor = WHITE) {


	SetCursorPosition(startLineX, startLineY);
	int y = startLineY;

	SetColor(normalTextColor, normalBgColor);

	for (int i = 0; i < menuSize; ++i) {
		SetCursorPosition(startLineX, y + i);
		cout << menu[i] << "\n";
	}


	SetCursorPosition(startLineX, startLineY);
	SetColor(highlightedTextColor, highlightedbgColor);
	cout << menu[y - startLineY];
	ShowConsoleCursor(false);
	while (1) {
		int key = _getch();
		if (key == 224) {
			key = _getch();

			switch (key) {
				case UP_ARROW_KEY:
					SetCursorPosition(startLineX, y);
					SetColor(normalTextColor, normalBgColor);
					cout << menu[y - startLineY];
					--y;
					if (y < startLineY)
						y = startLineY + menuSize - 1;
					SetCursorPosition(startLineX, y);
					SetColor(highlightedTextColor, highlightedbgColor);
					cout << menu[y - startLineY];
					SetColor(normalTextColor, normalBgColor);
					
					break;

				case DOWN_ARROW_KEY:
					SetCursorPosition(startLineX, y);
					SetColor(normalTextColor, normalBgColor);
					cout << menu[y - startLineY];
					++y;
					if (y > startLineY + menuSize - 1)
						y = startLineY;
					SetCursorPosition(startLineX, y);
					SetColor(highlightedTextColor, highlightedbgColor);
					cout << menu[y - startLineY];
					SetColor(normalTextColor, normalBgColor);
					
					break;
			}

		}
		else if (key == 13) {
			SetColor(WHITE, BLACK);
			return y - startLineY + 1;

		}
	}



}


int menuControl(vector<string> menu, int startLineX = 0, int startLineY = 0,
	int normalTextColor = WHITE, int normalBgColor = BLACK, int highlightedTextColor = BLACK,
	int highlightedbgColor = WHITE) {


	SetCursorPosition(startLineX, startLineY);
	int y = startLineY;

	SetColor(normalTextColor, normalBgColor);

	for (int i = 0; i < menu.size(); ++i) {
		SetCursorPosition(startLineX, y + i);
		cout << menu[i] << "\n";
	}


	SetCursorPosition(startLineX, startLineY);
	SetColor(highlightedTextColor, highlightedbgColor);
	cout << menu[y - startLineY];
	ShowConsoleCursor(false);
	while (1) {
		int key = _getch();
		if (key == 224) {
			key = _getch();

			switch (key) {
			case UP_ARROW_KEY:
				SetCursorPosition(startLineX, y);
				SetColor(normalTextColor, normalBgColor);
				cout << menu[y - startLineY];
				--y;
				if (y < startLineY)
					y = startLineY + menu.size() - 1;
				SetCursorPosition(startLineX, y);
				SetColor(highlightedTextColor, highlightedbgColor);
				cout << menu[y - startLineY];
				SetColor(normalTextColor, normalBgColor);

				break;

			case DOWN_ARROW_KEY:
				SetCursorPosition(startLineX, y);
				SetColor(normalTextColor, normalBgColor);
				cout << menu[y - startLineY];
				++y;
				if (y > startLineY + menu.size() - 1)
					y = startLineY;
				SetCursorPosition(startLineX, y);
				SetColor(highlightedTextColor, highlightedbgColor);
				cout << menu[y - startLineY];
				SetColor(normalTextColor, normalBgColor);

				break;
			}

		}
		else if (key == 13) {
			SetColor(WHITE, BLACK);
			return y - startLineY + 1;

		}
	}



}


int menuControlHorizontal(const char* menu[], int menuSize, int startLineX, int startLineY, int horizontalGap) {


	SetCursorPosition(startLineX, startLineY);
	int x = startLineX;

	SetColor(Colors::WHITE, Colors::BLACK);

	for (int i = 0; i < menuSize; ++i) {
		SetCursorPosition(startLineX * i, startLineY);
		cout << menu[i];
	}


	SetCursorPosition(startLineX, startLineY);
	SetColor(Colors::BLACK, Colors::WHITE);
	cout << menu[0];
	ShowConsoleCursor(false);
	while (1) {
		int key = _getch();
		if (key == 224) {
			key = _getch();

			switch (key) {
			case LEFT_ARROW_KEY:
				SetCursorPosition(x, startLineY);
				SetColor(Colors::WHITE, Colors::BLACK);
				cout << menu[x - startLineX];
				--x;
				if (x < startLineX)
					x = startLineX + menuSize - 1;
				SetCursorPosition(x, startLineY);
				SetColor(Colors::BLACK, Colors::WHITE);
				cout << menu[x - startLineX];
				SetColor(Colors::WHITE, Colors::BLACK);

				break;

			case RIGHT_ARROW_KEY:
				SetCursorPosition(x, startLineY);
				SetColor(Colors::WHITE, Colors::BLACK);
				cout << menu[x - startLineX];
				++x;
				if (x > startLineX + menuSize - 1)
					x = startLineX;
				SetCursorPosition(x, startLineY);
				SetColor(Colors::BLACK, Colors::WHITE);
				cout << menu[x - startLineX];
				SetColor(Colors::WHITE, Colors::BLACK);

				break;
			}

		}
		else if (key == 13) {
			SetColor(WHITE, BLACK);
			return x - startLineX + 1;

		}
	}



}