.PHONY: clear

cc := gcc
flags := -Wall -Werror -pedantic -std=c99
obj := ./obj/
objs := $(obj)output.o $(obj)free.o $(obj)gauss.o $(obj)add_mul.o $(obj)create_matrix.o $(obj)main.o
inc := ./inc/
src := ./src/

app.exe: $(objs)
	$(cc) $(flags) $^ -o $@

$(obj)main.o : main.c $(inc)main.h
	$(cc) $(flags) -c $< -o $@

$(obj)output.o : $(src)output.c $(inc)output.h
	$(cc) $(flags) -c $< -o $@

$(obj)free.o : $(src)free.c $(inc)free.h
	$(cc) $(flags) -c $< -o $@

$(obj)gauss.o : $(src)gauss.c $(inc)gauss.h
	$(cc) $(flags) -c $< -o $@

$(obj)add_mul.o : $(src)add_mul.c $(inc)add_mul.h
	$(cc) $(flags) -c $< -o $@

$(obj)create_matrix.o : $(src)create_matrix.c $(inc)create_matrix.h
	$(cc) $(flags) -c $< -o $@

unit_tests.exe: $(obj)unit.o
	$(cc) $(flags) $^ -o $@

$(obj)unit.o: unit.c
	$(cc) $(flags) -c $^

clear:
	rm -rf $(obj)*.o *.exe