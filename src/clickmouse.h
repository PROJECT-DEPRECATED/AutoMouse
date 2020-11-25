#include <stdio.h>
#include <windows.h>

int clickLeftButton(int GETX, int GETY, int GETCLICKED) {
    printf("Get X Location: %d Get Y Location: %d\n", GETX, GETY);
	printf("Running... Left Click Mouse\n");
	
	while (GETCLICKED == 1) {
    	mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
		Sleep(25);
        mouse_event(MOUSEEVENTF_LEFTUP, GETX, GETY, 0, 0);
		Sleep(25);

		if (GetKeyState(VK_END)) {
			GETCLICKED = 0;
            system("cls");
        }
	}

	return 0;
}

int clickRightButton(int GETX, int GETY, int GETCLICKED) {
	printf("Get X Location: %d Get Y Location: %d\n", GETX, GETY);
	printf("Running... Right Click Mouse\n");
	
	while (GETCLICKED == 1) {
    	mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
		Sleep(25);
        mouse_event(MOUSEEVENTF_RIGHTUP, GETX, GETY, 0, 0);
		Sleep(25);

		if (GetKeyState(VK_END)) {
			GETCLICKED = 0;
            system("cls");
        }
	}

	return 0;
}