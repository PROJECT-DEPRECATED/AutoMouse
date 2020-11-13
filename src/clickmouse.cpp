#include <iostream>
#include <windows.h>

int clickLeftButton(int GETX, int GETY, int GETDELAY, bool GETCLICKED) {
    std::cout << "Get X Location: " << GETX << " " << "Get Y Location: " << GETY << "\n";
	std::cout << "Running... Left Click Mouse\n";
    std::cout << "Click rate: " << GETDELAY << "\n";
	
	while (GETCLICKED) {
    	mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, GETX, GETY, 0, 0);
        Sleep(GETDELAY);
    	
		if (GetKeyState(VK_END)) {
			GETCLICKED = false;
            system("cls");
        }
	}

	return 0;
}

int clickRightButton(int GETX, int GETY, int GETDELAY, bool GETCLICKED) {
    std::cout << "Get X Location: " << GETX << " " << "Get Y Location: " << GETY << "\n";
	std::cout << "Running... Right Click Mouse\n";
    std::cout << "Click rate: " << GETDELAY << "\n";
	
	while (GETCLICKED) {
    	mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTUP, GETX, GETY, 0, 0);
        Sleep(GETDELAY);
    	
		if (GetKeyState(VK_END)) {
			GETCLICKED = false;
            system("cls");
        }
	}

	return 0;
}