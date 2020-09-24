cc := gcc
cflags := -std=c99 -Wall -Werror -pedantic

run: main.exe
	./main.exe

main.exe: sort.o main.o function.o
	$(cc) $^ -o $@

sort.o: sort.c
	$(cc) $(cflags) -c $<

function.o: function.c function.h main.h
	$(cc) $(cflags) -c $<

main.o: main.c main.h
	$(cc) $(cflags) -c $<

del: clean

.PHONY: clean

clean:
	rm -rf *.exe *.o