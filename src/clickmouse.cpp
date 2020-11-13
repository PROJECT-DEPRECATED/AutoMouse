#include <iostream>
#include <windows.h>

int clickLeftButton(int GETX, int GETY, bool GETCLICKED) {
    std::cout << "Get X Location: " << GETX << " " << "Get Y Location: " << GETY << "\n";
	std::cout << "Running... Left Click Mouse\n";
	
	while (GETCLICKED) {
    	mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
		Sleep(25);
        mouse_event(MOUSEEVENTF_LEFTUP, GETX, GETY, 0, 0);
		Sleep(25);

		if (GetKeyState(VK_END)) {
			GETCLICKED = false;
            system("cls");
        }
	}

	return 0;
}

int clickRightButton(int GETX, int GETY, bool GETCLICKED) {
    std::cout << "Get X Location: " << GETX << " " << "Get Y Location: " << GETY << "\n";
	std::cout << "Running... Right Click Mouse\n";
	
	while (GETCLICKED) {
    	mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
		Sleep(25);
        mouse_event(MOUSEEVENTF_RIGHTUP, GETX, GETY, 0, 0);
		Sleep(25);

		if (GetKeyState(VK_END)) {
			GETCLICKED = false;
            system("cls");
        }
	}

	return 0;
}