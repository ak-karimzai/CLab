cc := gcc
cflags := -std=c99 -Wall -Werror -pedantic
head = ./inc/
src = ./src/
unit.test = ./unit_test/
obj = ./obj/

run: app.exe 
	./app.exe ./functional_tests/pos_in_1.txt .out

unit_tests.exe: unit_test.o sort.o function.o
	$(cc) $^ -o $@

app.exe: $(obj)sort.o $(obj)main.o $(obj)function.o
	$(cc) $^ -o $@

$(obj)sort.o: $(src)sort.c
	$(cc) $(cflags) -c $< -o $@

$(obj)function.o: $(src)function.c $(head)function.h $(head)main.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

$(obj)unit_test.o: $(unit.test)unit_test.c $(head)unit_function.h $(head)main.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

$(obj)main.o: main.c $(head)main.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

del: clean

.PHONY: clean

clean:
	rm -rf *.exe $(obj)*.o .out