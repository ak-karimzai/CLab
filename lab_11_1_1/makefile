cc := gcc
c_flag := -Wall -Werror -pedantic -std=c99

run : app.exe
	./app.exe

app.exe : temp.o main.o
	$(cc) $(c_flag) -o $@ $^

temp.o : temp.c 
	$(cc) $(c_flag) -c $^

main.o : main.c 
	$(cc) $(c_flag) -c $^

unit_tests.exe : unit.c
	$(cc) $(c_flag) -o $@ $^

.PHONY : clear

clear :
	rm -rf *.exe *.out