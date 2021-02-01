#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "clickbutton.h"
#include "togglebutton.h"

bool running = true;

bool toggled = false;
bool clicked = false;
bool get_select = false;

int getX, getY, count, click_second;
char getVersion[5] = "2.0v";
void get_gui();

void inRunning() {
	click_second = 0.001;

	while (running) {
		get_gui();

		POINT getPointer;
		getX = getPointer.x;
		getY = getPointer.y;
		GetCursorPos(&getPointer);
		
		if (GetKeyState(VK_INSERT)) {
			get_select = true;

			while (get_select) {
				if (GetKeyState(VK_LEFT)) {
					get_select = false;

					clicked = true;
					left_click(clicked, getX, getY, count, click_second);

					clicked = false;
				} else if (GetKeyState(VK_RIGHT)) {
					get_select = false;

					clicked = true;
					right_click(clicked, getX, getY, count, click_second);

					clicked = false;
				}
			}
		} else if (GetKeyState(VK_HOME)) {
			get_select = true;

			while (get_select) {
				if (GetKeyState(VK_LEFT)) {
					get_select = false;

					toggled = true;
					left_toggle(toggled, getX, getY);

					toggled = false;
				} else if (GetKeyState(VK_RIGHT)) {
					get_select = false;
					
					toggled = true;
					right_toggle(toggled, getX, getY);

					toggled = false;
				}
			}
		}

		system("cls");
	}
}

void get_gui() {
	printf("============================\n");
	printf("= Click Mouse: Insert      =\n");
	printf("= Toggle Mouse: Home       =\n");
	printf("= Set click second: Delete =\n");
	printf("= Exit: Pause              =\n");
	printf("=                          =\n");
	printf("= Click Second: %d Second  =\n", click_second);
	printf("============================\n");
}

int main(int argc, char **argv) {
	inRunning();
}