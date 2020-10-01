cc := gcc
cflags := -std=c99 -Wall -Werror -pedantic
head = ./inc/
src = ./src/
unit.test = ./unit_tests/
obj = ./obj/

#run: app.exe 
#	./app.exe ./functional_tests/pos_in_1.txt .out

app.exe: $(obj)sort.o $(obj)main.o $(obj)output.o $(obj)input.o $(obj)key.o
	$(cc) $^ -o $@

unit_tests.exe: $(obj)unit_test.o $(obj)sort.o $(obj)output.o $(obj)input.o $(obj)key.o
	$(cc) $^ -o $@

$(obj)sort.o: $(src)sort.c $(head)sort_header.h
	$(cc) $(cflags) -c $< -o $@

$(obj)key.o: $(src)key.c $(head)key.h
	$(cc) $(cflags) -c $< -o $@

$(obj)input.o: $(src)input.c $(head)input.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

$(obj)output.o: $(src)output.c
	$(cc) -I$(head) $(cflags) -c $< -o $@

$(obj)unit_test.o: $(unit.test)unit_test.c $(head)unit_function.h $(head)main.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

$(obj)main.o: main.c $(head)main.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

del: clean

.PHONY: clean

clean:
	rm -rf *.exe $(obj)*.o .out