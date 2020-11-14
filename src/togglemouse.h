#include <iostream>
#include <windows.h>

int toggleLeftButton(int GETX, int GETY, bool GETTOGGLE) {
	std::cout << "Get X Location: " << GETX << " " << "Get Y Location: " << GETY << "\n";
	std::cout << "Running... Left Toggle Mouse\n";
	
	while (GETTOGGLE) {
    	mouse_event(MOUSEEVENTF_LEFTDOWN, GETX, GETY, 0, 0);
    	
		if (GetKeyState(VK_END)) {
			GETTOGGLE = false;
            system("cls");
        }
	}

	return 0;
}

int toggleRightButton(int GETX, int GETY, bool GETTOGGLE) {
	std::cout << "Get X Location: " << GETX << " " << "Get Y Location: " << GETY << "\n";
	std::cout << "Running... Right Toggle Mouse\n";
	
	while (GETTOGGLE) {
		mouse_event(MOUSEEVENTF_RIGHTDOWN, GETX, GETY, 0, 0);
		
		if (GetKeyState(VK_END)) {
			GETTOGGLE = false;
            system("cls");
        }
	}

	return 0;
}