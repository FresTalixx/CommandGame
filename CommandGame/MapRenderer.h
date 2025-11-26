#pragma once

#include <iostream>
#include "Room.h"
#include "consoleCommands.h"

using namespace std;

class MapRenderer {
private:
	Room* roomToRender;
	size_t height;
	size_t width;

	size_t startX;
	size_t startY;

public:
	MapRenderer(Room* roomToRender) : roomToRender(roomToRender) {
        height = 5;
        width = 5;
        startX = 0;
        startY = 0;
    }

	MapRenderer(Room* roomToRender, size_t height, size_t width, size_t startX, size_t startY)
		: roomToRender(roomToRender), height(height), width(width), startX(startX), startY(startY) {}

	// /----------    ----------\
	// |                        |
	// |                        |
	//         Room Name
	// |                        |
	// |                        |
	// \----------    ----------/

	// check if the exit exists and according to the info draw corresponing exits

    void render() {
        SetCursorPosition(startX, startY);

        for (size_t row = 0; row < height; ++row) {
            SetCursorPosition(startX, startY + row);
            // top border
            if (row == 0) {
                cout << "/";
                cout << string(width / 2 - 2, '-');

                if (roomToRender->getExit("north"))
                    cout << "   ";
                else
                    cout << "---";

                cout << string(width / 2 - 2, '-');
                cout << "\\\n";
                continue;
            }

            // bottom border
            if (row == height - 1) {
                cout << "\\";
                cout << string(width / 2 - 2, '-');

                if (roomToRender->getExit("south"))
                    cout << "   ";
                else
                    cout << "---";

                cout << string(width / 2 - 2, '-');
                cout << "/\n";
                continue;
            }

            // middle row = room name
            if (row == height / 2) {
                string name = roomToRender->getName();
                int leftPadding = max(1, int((width - name.size()) / 2));
                int rightPadding = max(1, int(width - name.size() - leftPadding));

                if (roomToRender->getExit("west")) {
                    cout << " ";
                }
                else {
                    cout << "|";
                }
                cout << string(leftPadding - 1, ' ')
                    << name
                    << string(rightPadding - 1, ' ');

                    if (roomToRender->getExit("east")) {
                        cout << " \n";
                    }
                    else {
                        cout << "|\n";
                    }
                continue;
            }

            // side walls + possible exits
            cout << "|";
            cout << string(width - 2, ' ');
            cout << "|\n";
        }
    }

};

