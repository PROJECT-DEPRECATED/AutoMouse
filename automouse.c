#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>

#include "click_button.h"
#include "toggle_button.h"

int get_x, get_y, click_count;
int count, last_count;
char get_version[5] = "3.0v";

void get_gui() {
	printf("=================================\n");
	printf("= Click Mouse(LEFT): LEFT_KEY   =\n");
	printf("= Click Mouse(RIGHT): RIGHT_KEY =\n");
	printf("= Exit: End                     =\n");
	printf("=                               =\n");
	printf("= Last Click Count: %d clicks   =\n", last_count);
	printf("= Click Count: %dms             =\n", click_count);
	printf("=================================\n");
}

int main(int argc, char **argv) {
	click_count = 1;

	while (true) {
		count = 0;
		get_gui();

		POINT getPointer;
		get_x = getPointer.x;
		get_y = getPointer.y;
		GetCursorPos(&getPointer);
		
		if (GetKeyState(VK_LEFT)) {
			while (true) {
				left_click(get_x, get_y, count, click_count);

				count++;
				printf("Click Counter: %d", count);
				system("cls");

				if (GetKeyState(VK_DELETE)) {
					break;
				}
			}

			last_count = count;
		} else if (GetKeyState(VK_RIGHT)) {
			while (true) {
				right_click(get_x, get_y, count, click_count);

				count++;
				printf("Click Counter: %d", count);
				system("cls");

				if (GetKeyState(VK_DELETE)) {
					break;
				}
			}

			last_count = count;
		} else if (GetKeyState(VK_END)) {
			break;
		}

		system("cls");
	}
}