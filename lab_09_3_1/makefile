cc := gcc
cflags := -Wall -Werror -pedantic -std=c99

obj := ./obj/
src := ./src/
inc := ./inc/

app.exe : $(obj)main.o $(obj)io.o $(obj)sort.o
	$(cc) $^ -o $@

$(obj)main.o : main.c $(inc)main.h
	$(cc) $(cflags) -c $< -o $@

$(obj)io.o : $(src)io.c $(inc)io.h
	$(cc) $(cflags) -c $< -o $@

$(obj)sort.o : $(src)sort.c $(inc)sort.h
	$(cc) $(cflags) -c $< -o $@

unit_tests.exe : unit.o
	$(cc) $< -o $@ -o $@

$(obj)unit.o : unit.c
	$(cc) $(cflags) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(obj)*.o *.exe