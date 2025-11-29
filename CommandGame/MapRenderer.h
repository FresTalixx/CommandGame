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
            if (roomToRender->getShowHiddenThingsRoom()) {
                SetColor(WHITE, DARK_YELLOW);
            }
            else {
                SetColor(BLUE, BLACK);
            }

            SetCursorPosition(startX, startY + row);
            // top border
            if (row == 0) {
                cout << "/";
                cout << string(width / 2 - 2, '-');

                if (roomToRender->getExit("north")) {
                    if (roomToRender->isRoomLocked("north")) {
                        cout << "|||";
                    }
                    else {
                        cout << "   ";
                    }
                }

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

                if (roomToRender->getExit("south")) {
                    if (roomToRender->isRoomLocked("south")) {
                        cout << "|||";
                    }
                    else {
                        cout << "   ";
                    }
                }
                    
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
                    if (roomToRender->isRoomLocked("west")) {
                        cout << "-";
                    }
                    else {
                        cout << " ";
                    }
                    
                }
                else {
                    cout << "|";
                }
                cout << string(leftPadding - 1, ' ')
                    << name
                    << string(rightPadding - 1, ' ');

                if (roomToRender->getExit("east")) {
                    if (roomToRender->isRoomLocked("east")) {
                        cout << "-";
                    }
                    else {
                        cout << " ";
                    }

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

        

		auto hiddenItems = roomToRender->getHiddenItems();
		auto visibleItems = roomToRender->getVisibleItems();
        
		// if there are no items in the room, return
        if (hiddenItems.empty() && visibleItems.empty()) {
            return;
		}
        SetColor(GREEN, BLACK);
		// render visible and invisible items if the flag is set
        if (roomToRender->getShowHiddenThingsRoom()) {
            int visibleItemsGap = 0;
            int hiddenItemsGap = 0;

            for (auto& item : visibleItems) {
                SetColor(GREEN, DARK_YELLOW); // to remove black bg from flashlight's light
                SetCursorPosition(startX + 1 + visibleItemsGap, startY + 1); // top row of the room
                cout << item->getName();
                visibleItemsGap += item->getName().size();
			}

            for (auto& item : hiddenItems) {
                SetColor(RED, DARK_YELLOW); // to remove black bg from flashlight's light
                SetCursorPosition(startX + 1 + hiddenItemsGap, startY + height - 2); // bottom row of the room
                cout << item->getName();
                hiddenItemsGap += item->getName().size();
            }
		}
        else {
            int tempHeight = 0;
            int visibleItemsGap = 0;

            for (auto& item : visibleItems) {
                SetCursorPosition(startX + 1 + visibleItemsGap, startY + 1); // top row of the room
                cout << item->getName();
                visibleItemsGap += item->getName().size();
			}
        }
        SetColor(BLUE, BLACK);
    }

};

