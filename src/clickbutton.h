#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

void left_click(bool GET_BOOL, int GETX, int GETY, int GET_COUNT, int GET_CLICK_PER_SECOND) {
    while (GET_BOOL) {
        mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
	    Sleep(GET_CLICK_PER_SECOND * 1000);
	    mouse_event(MOUSEEVENTF_LEFTUP, GETX, GETY, 0, 0);
	    GET_COUNT++;

	    system("cls");
	    printf("Click Counter: %d", GET_COUNT);
    }
}

void right_click(bool GET_BOOL, int GETX, int GETY, int GET_COUNT, int GET_CLICK_PER_SECOND) {
    while (GET_BOOL) {
        mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
	    Sleep(GET_CLICK_PER_SECOND * 1000);
	    mouse_event(MOUSEEVENTF_RIGHTUP, GETX, GETY, 0, 0);
	    GET_COUNT++;

	    system("cls");
	    printf("Click Counter: %d", GET_COUNT);
    }
}