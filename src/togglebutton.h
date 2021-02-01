#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

void left_toggle(bool GET_BOOL, int GETX, int GETY) {
    while (GET_BOOL) {
        mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
	    system("cls");
        
	    printf("Toggle Click Activated...");
    }

    mouse_event(MOUSEEVENTF_LEFTUP, GETX, GETY, 0, 0);
}

void right_toggle(bool GET_BOOL, int GETX, int GETY) {
    while (GET_BOOL) {
        mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
	    system("cls");
        
	    printf("Toggle Click Activated...");
    }

    mouse_event(MOUSEEVENTF_RIGHTUP, GETX, GETY, 0, 0);
}