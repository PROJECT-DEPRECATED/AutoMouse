#include <stdio.h>
#include <windows.h>
#include "togglemouse.h"
#include "clickmouse.h"

int onRunning = 1;
int isExit = 0;
int onToggled = 0;
int onClicked = 0;
int isReload = 0;
int getX, getY;

int inRunning() {
	while (onRunning == 1) {
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
    			onToggled = 1;
    			toggleLeftButton(getX, getY, onToggled);
			}
			
			else if (typeCommand == "right") {
				onToggled = 1;
				toggleRightButton(getX, getY, onToggled);
			}
		}

		else if (typeCommand == "click") {
			printf("[AutoMouse Shell] Which key would you like to click? 'left' or 'right'\n");
			printf("SelectButton> ");
			scanf("%s", typeCommand);

			if (typeCommand == "left") {
				onClicked = 1;
				clickLeftButton(getX, getY, onClicked);
			}

			else if (typeCommand == "right") {
				onClicked = 1;
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
			isReload = 1;
			onRunning = 0;
		}
		
		else if (typeCommand == "exit") {
			printf("[AutoMouse Shell] Are you sure exit this programs? 'yes' or 'no'\n");
			isExit = 1;
			
			while (isExit == 1) {
				printf("exit> ");
				scanf("%s",typeCommand);
			
				if (typeCommand == "yes") {
					printf("[AutoMouse Shell] Goodbye!\n");
					onRunning = 0;
					isExit = 0;
				}
				
				else if (typeCommand == "no") {
					isExit == 0;
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

	if (isReload == 1) {
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


		onRunning = 1;
		isReload = 0;
	}

	inRunning();
	return 0;
}