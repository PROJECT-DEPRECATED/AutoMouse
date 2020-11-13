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
int setDelay = 0;
int getX, getY;

int main(void) {
	onProgramInfo();
	std::cout << "\n";
	std::cout << "[AutoMouse Shell] Please type commands. If you don't know please type help.\n";
	
	while (onRunning) {
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

			std::cout << "[AutoMouse Shell] Please type the click rate. Default: 0ms, Example1) 1Second = 1000ms, Example2)10Second = 10000ms\n";
			std::cout << "ClickRate> ";
			std::cin >> setDelay;

			if (typeCommand == "left") {
				onClicked = true;
				
				if (setDelay == 0) {
					clickLeftButton(getX, getY, 0, onClicked);
				} 

				else {
					clickLeftButton(getX, getY, setDelay, onClicked);
				}
			}

			else if (typeCommand == "right") {
				onClicked = true;

				if (setDelay == 0) {
					clickRightButton(getX, getY, 0, onClicked);
				}

				else {
					clickRightButton(getX, getY, setDelay, onClicked);
				}
			}
		}
		
		else if (typeCommand == "clear") {
			system("cls");
		}
	
		else if (typeCommand == "capture") {
			std::cout << "Get X: " << getX << " " << "Get Y: " << getY << "\n";
		}

		else if (typeCommand == "version") {
			onProgramVersion();
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
			std::cout << "[AutoMouse Shell] exit: You can exit this program. Usage> exit\n";
		}
		
		else {
			std::cout << "[AutoMouse Shell] '" << typeCommand <<"' has Invalid command. If you don't know please type 'help'.\n";
		}
	}

    return 0;
}