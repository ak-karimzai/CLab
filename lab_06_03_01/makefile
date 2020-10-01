cc := gcc
cflags := -Wall -Werror -pedantic -std=c99

app.exe: main.o io.o sort.o
	$(cc) $^ -o $@

main.o: main.c main.h functions.h
	$(cc) $(cflags) -c $<

io.o: io.c io.h
	$(cc) $(cflags) -c $<

sort.o: sort.c sort.h
	$(cc) $(cflags) -c $<

.PHONY: clean

clean:
	rm -rf *.o *.exe