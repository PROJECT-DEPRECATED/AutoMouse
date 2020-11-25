#include <stdio.h>
#include <windows.h>

int toggleLeftButton(int GETX, int GETY, int GETTOGGLE) {
	printf("Get X Location: %d Get Y Location: %d\n", GETX, GETY);
	printf("Running... Left Toggle Mouse\n");
	
	while (GETTOGGLE == 1) {
    	mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
    	
		if (GetKeyState(VK_END)) {
			GETTOGGLE = 0;
            system("cls");
        }
	}

	return 0;
}

int toggleRightButton(int GETX, int GETY, int GETTOGGLE) {
	printf("Get X Location: %d Get Y Location: %d\n", GETX, GETY);
	printf("Running... Right Toggle Mouse\n");
	
	while (GETTOGGLE == 1) {
		mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
		
		if (GetKeyState(VK_END)) {
			GETTOGGLE = 0;
            system("cls");
        }
	}

	return 0;
}