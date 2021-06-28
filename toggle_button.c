#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void left_toggle(int GETX, int GETY) {
    mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
	system("cls");
	printf("Toggle Click Activated...");

    mouse_event(MOUSEEVENTF_LEFTUP, GETX, GETY, 0, 0);
}

void right_toggle(int GETX, int GETY) {
    mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
	system("cls");
	printf("Toggle Click Activated...");

    mouse_event(MOUSEEVENTF_RIGHTUP, GETX, GETY, 0, 0);
}