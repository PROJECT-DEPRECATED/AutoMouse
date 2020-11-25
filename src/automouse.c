#include <stdio.h>
#include <windows.h>
#include "info.h"
#include "togglemouse.h"
#include "clickmouse.h"

bool onRunning = true;
bool isExit = false;
bool onToggled = false;
bool onClicked = false;
bool isReload = false;
int getX, getY;

int inRunning() {
	while (onRunning == true) {
		char* typeCommand;
		POINT getPointer;
		getX = getPointer.x;
		getY = getPointer.y;
		GetCursorPos(&getPointer);
		printf("> ");
    	scanf("%s", &typeCommand);
    
    	if (typeCommand == "toggle") {
    		printf("[AutoMouse Shell] Which key would you like to press? 'left' or 'right'\n");
			printf("SelectButton> ");
    		scanf("%s", typeCommand);

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
			printf("[AutoMouse Shell] Which key would you like to click? 'left' or 'right'\n");
			printf("SelectButton> ");
			scanf("%s", typeCommand);

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
			printf("[AutoMouse Shell] Clearing...");
			Sleep(1000);
			system("cls");
		}
	
		else if (typeCommand == "capture") {
			printf("Get X: " << getX << " " << "Get Y: " << getY << "\n");
		}

		else if (typeCommand == "version") {
			printf("[AutoMouse Shell] This program version is 1.0v\n");
		}

		else if (typeCommand == "reload") {
			isReload = true;
			onRunning = false;
		}
		
		else if (typeCommand == "exit") {
			printf("[AutoMouse Shell] Are you sure exit this programs? 'yes' or 'no'\n");
			isExit = true;
			
			while (isExit == true) {
				printf("exit> ");
				scanf("%s",typeCommand);
			
				if (typeCommand == "yes") {
					printf("[AutoMouse Shell] Goodbye!\n");
					onRunning = false;
					isExit = false;
				}
				
				else if (typeCommand == "no") {
					isExit == false;
					break;
				}
				
				else {
					printf("[AutoMouse] Invalid command. please type 'yes' or 'no'!\n");
				}
			}
		}

		else if (typeCommand == "help") {
			printf("[AutoMouse Shell] toggle: Keep the mouse click. Usage> ('/' is enter.) toggle/ left or right\n");
			printf("[AutoMouse Shell] click: Click the mouse in succession. Usage> ('/' is enter.) click/ left or right\n");
			printf("[AutoMouse Shell] clear: Initialize the shell output. Usage> clear\n");
			printf("[AutoMouse Shell] capture: You can check the position of the mouse pointer. Usage> capture\n");
			printf("[AutoMouse Shell] version: You can check this program version. Usage> version\n");
			printf("[AutoMouse Shell] reload: You can reload this program. Usage> reload\n");
			printf("[AutoMouse Shell] exit: You can exit this program. Usage> exit\n");
		}
		
		else {
			printf("[AutoMouse Shell] '%s' has Invalid command. If you don't know please type 'help'.\n", typeCommand);
		}
	}

	return 0;
}

int main() {
	system("title AutoMouse-1.0v");
    printf("Automouse-1.0v Made by Project_TL\n"); 
	printf("\n");
	printf("[AutoMouse Shell] Please type commands. If you don't know please type help.\n");

	inRunning();

	if (isReload == true) {
		system("cls");
        printf("Reloading Settings");
		Sleep(1000);
		system("cls");

		printf("Reloading Settings.");
		Sleep(1000);
		system("cls");

		printf("Reloading Settings..");
		Sleep(1000);
		system("cls");

		printf("Reloading Settings...");
		Sleep(1000);
		system("cls");

		printf("Reloading Settings....");
		Sleep(1000);
		system("cls");


		onRunning = true;
		isReload = false;
	}

	inRunning();
	return 0;
}