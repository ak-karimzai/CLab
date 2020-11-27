cc := gcc
c_flag := -Wall -Werror -pedantic -std=c99

app.exe : temp.c
	$(cc) $(c_flag) -o $@ $^

.PHONY : clear

clear :
	rm -rf *.exe *.out