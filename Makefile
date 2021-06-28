automouse.exe: automouse.o click_button.o toggle_button.o
		gcc -o automouse.exe click_button.o toggle_button.o automouse.o\
***
    
click_button.o: click_button.c
		gcc -c -o click_button.o click_button.c\
***

toggle_button.o: toggle_button.c
		gcc -c -o toggle_button.o toggle_button.c\
***

automouse.o: automouse.c
		gcc -c -o automouse.o automouse.c\
***

clean_obj:
		rm *.o\
***

clean_file:
		rm automouse.exe\

clean:
		rm *.o automouse.exe\
***