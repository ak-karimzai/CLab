cc := gcc
cflags := -std=c99 -Wall -Werror -pedantic

run: main.exe
	./main.exe

main.exe: sort.o main.o
	$(cc) $^ -o $@

sort.o: sort.c
	$(cc) $(cflags) -c $<

main.o: main.c
	$(cc) $(cflags) -c $<

del: clean

.PHONY: clean

clean:
	rm -rf *.exe *.o