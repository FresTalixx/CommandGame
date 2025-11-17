#pragma once

#include "consoleCommands.h"
#include <vector>
#include <string>

int menuControl(const char* menu[], int menuSize, int startLineX = 0, int startLineY = 0,
	int normalTextColor = WHITE, int normalBgColor = BLACK, int highlightedTextColor = BLACK,
	int highlightedbgColor = WHITE);
int menuControl(vector<string> menu, int startLineX = 0, int startLineY = 0,
	int normalTextColor = WHITE, int normalBgColor = BLACK, int highlightedTextColor = BLACK,
	int highlightedbgColor = WHITE);
int menuControlHorizontal(const char* menu[], int menuSize, int startLineX, int startLineY, int horizontalGap);