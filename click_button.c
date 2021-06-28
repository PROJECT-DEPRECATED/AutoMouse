#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

void left_click(int GETX, int GETY, int GET_SLEEP_TIME) {
    mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
	Sleep(GET_SLEEP_TIME);
	mouse_event(MOUSEEVENTF_LEFTUP, GETX, GETY, 0, 0);
}

void right_click(int GETX, int GETY, int GET_SLEEP_TIME) {
    mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
	Sleep(GET_SLEEP_TIME);
	mouse_event(MOUSEEVENTF_RIGHTUP, GETX, GETY, 0, 0);
}