cc_exe := gcc -Wall -Werror -pedantic 
cc_o := gcc -Wall -Werror -pedantic -c 

main.exe: main.o functions.o functions.h
	$(cc_exe) main.o functions.o 

main.o: main.c
	$(cc_o) main.c

functions.o: functions.c
	$(cc_o) functions.c

clean:
	rm -rf *.o *.exe