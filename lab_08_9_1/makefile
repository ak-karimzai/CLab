.PHONY: clear

cc := gcc
flags := -Wall -Werror -pedantic -std=c99

app.exe: main.o
	$(cc) $(flags) $^ -o $@

main.o : main.c
	$(cc) $(flags) -c $^

unit_tests.exe: unit.o
	$(cc) $(flags) $^ -o $@

unit.o: unit.c
	$(cc) $(flags) -c $^

clear:
	rm -rf *.o *.exe