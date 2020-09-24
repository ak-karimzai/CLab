cc := gcc
cflags := -Wall -Werror -pedantic -std=c99

app.exe: main.o functions.o
	$(cc) $^ -o $@

main.o: main.c main.h functions.h
	$(cc) $(cflags) -c $<

functions.o: functions.c main.h
	$(cc) $(cflags) -c $<