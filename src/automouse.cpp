#include <iostream>
#include <string>
#include <windows.h>
#include "info.h"
#include "togglemouse.cpp"
#include "clickmouse.cpp"
using namespace std;

bool onRunning = true;
bool isExit = false;
bool onToggled = false;
bool onClicked = false;
bool isReload = false;
int getX, getY;

int inRunning() {
	while (onRunning == true) {
		string typeCommand;
		POINT getPointer;
		getX = getPointer.x;
		getY = getPointer.y;
		GetCursorPos(&getPointer);
		std::cout << "> ";
    	std::cin >> typeCommand;
    
    	if (typeCommand == "toggle") {
    		std::cout << "[AutoMouse Shell] Which key would you like to press? 'left' or 'right'\n";
			std::cout << "SelectButton> ";
    		std::cin >> typeCommand;

    		if (typeCommand == "left") {
    			onToggled = true;
    			toggleLeftButton(getX, getY, onToggled);
			}
			
			else if (typeCommand == "right") {
				onToggled = true;
				toggleRightButton(getX, getY, onToggled);
			}
		}

		else if (typeCommand == "click") {
			std::cout << "[AutoMouse Shell] Which key would you like to click? 'left' or 'right'\n";
			std::cout << "SelectButton> ";
			std::cin >> typeCommand;

			if (typeCommand == "left") {
				onClicked = true;
				clickLeftButton(getX, getY, onClicked);
			}

			else if (typeCommand == "right") {
				onClicked = true;
				clickRightButton(getX, getY, onClicked);
			}
		}
		
		else if (typeCommand == "clear") {
			std::cout << "[AutoMouse Shell] Clearing...";
			Sleep(1000);
			system("cls");
		}
	
		else if (typeCommand == "capture") {
			std::cout << "Get X: " << getX << " " << "Get Y: " << getY << "\n";
		}

		else if (typeCommand == "version") {
			onProgramVersion();
		}

		else if (typeCommand == "reload") {
			isReload = true;
			onRunning = false;
		}
		
		else if (typeCommand == "exit") {
			std::cout << "[AutoMouse Shell] Are you sure exit this programs? 'yes' or 'no'\n";
			isExit = true;
			
			while (isExit == true) {
				std::cout << "exit> ";
				std::cin >> typeCommand;
			
				if (typeCommand == "yes") {
					std::cout << "[AutoMouse Shell] Goodbye!\n";
					onRunning = false;
					isExit = false;
				}
				
				else if (typeCommand == "no") {
					isExit == false;
					break;
				}
				
				else {
					std::cout << "[AutoMouse] Invalid command. please type 'yes' or 'no'!\n";
				}
			}
		}

		else if (typeCommand == "help") {
			std::cout << "[AutoMouse Shell] toggle: Keep the mouse click. Usage> ('/' is enter.) toggle/ left or right\n";
			std::cout << "[AutoMouse Shell] click: Click the mouse in succession. Usage> ('/' is enter.) click/ left or right\n";
			std::cout << "[AutoMouse Shell] clear: Initialize the shell output. Usage> clear\n";
			std::cout << "[AutoMouse Shell] capture: You can check the position of the mouse pointer. Usage> capture\n";
			std::cout << "[AutoMouse Shell] version: You can check this program version. Usage> version\n";
			std::cout << "[AutoMouse Shell] reload: You can reload this program. Usage> reload\n";
			std::cout << "[AutoMouse Shell] exit: You can exit this program. Usage> exit\n";
		}
		
		else {
			std::cout << "[AutoMouse Shell] '" << typeCommand <<"' has Invalid command. If you don't know please type 'help'.\n";
		}
	}

	return 0;
}

int main() {
	onProgramInfo();
	std::cout << "\n";
	std::cout << "[AutoMouse Shell] Please type commands. If you don't know please type help.\n";
	inRunning();

	if (isReload == true) {
		system("cls");
        std::cout << "Reloading Settings";
		Sleep(1000);
		system("cls");

		std::cout << "Reloading Settings.";
		Sleep(1000);
		system("cls");

		std::cout << "Reloading Settings..";
		Sleep(1000);
		system("cls");

		std::cout << "Reloading Settings...";
		Sleep(1000);
		system("cls");

		std::cout << "Reloading Settings....";
		Sleep(1000);
		system("cls");


		onRunning = true;
		isReload = false;
	}

	inRunning();
	return 0;
}