#include <iostream>
#include <windows.h>
using namespace std;

int clickLeftButton(int GETX, int GETY, bool GETCLICKED) {
	int getClickCount;

    std::cout << "Get X Location: " << GETX << "Get Y Location: " << GETY << "\n";
	std::cout << "Running... Left Click Mouse\n";
	
	while (GETCLICKED) {
    	mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
		Sleep(25);
		++getClickCount;

        mouse_event(MOUSEEVENTF_LEFTUP, GETX, GETY, 0, 0);
		Sleep(25);

		if (GetKeyState(VK_END)) {
			GETCLICKED = false;
            system("cls");
			
			std::cout << "Click Count Result: " << getClickCount << endl;
        }
	}
	

	return getClickCount;
}

int clickRightButton(int GETX, int GETY, bool GETCLICKED) {
	int getClickCount;

	std::cout << "Get X Location: " << GETX << "Get Y Location: " << GETY << "\n";
	std::cout << "Running... Right Click Mouse\n";
	
	while (GETCLICKED) {
    	mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
		Sleep(25);
		++getClickCount;

        mouse_event(MOUSEEVENTF_RIGHTUP, GETX, GETY, 0, 0);
		Sleep(25);

		if (GetKeyState(VK_END)) {
			GETCLICKED = false;
            system("cls");

			std::cout << "Click Count Result: " << getClickCount << endl;
        }
	}

	return getClickCount;
}