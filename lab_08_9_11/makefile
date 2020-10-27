.PHONY: clear

cc := gcc
flags := -Wall -Werror -pedantic -std=c99
obj := ./obj/
inc := ./inc/
src := ./src/
unit.src := ./unit_test/
unit.inc := $(inc)unit_test_headers/

objs := $(obj)output.o $(obj)free.o $(obj)gauss.o $(obj)add_mul.o $(obj)create_matrix.o $(obj)main.o
unit.objs := $(obj)output.o $(obj)free.o  $(obj)add_mul.o $(obj)create_matrix.o $(obj)addition_unit_test.o $(obj)multiplication_unit_test.o $(obj)unit_test.o $(obj)collect_unit_test.o  #$(obj)gauss.o

app.exe: $(objs)
	$(cc) $(flags) $^ -o $@

unit_tests.exe: $(unit.objs)
	$(cc) $(flags) $^ -o $@ -lcheck

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

$(obj)addition_unit_test.o : $(unit.src)addition_unit_tests.c $(unit.inc)addition_unit_tests.h 
	$(cc) $(flags) -c $< -o $@

$(obj)multiplication_unit_test.o : $(unit.src)multiplication_unit_tests.c $(unit.inc)multiplication_unit_tests.h 
	$(cc) $(flags) -c $< -o $@

$(obj)unit_test.o : $(unit.src)unit_test.c $(unit.inc)unit_function.h 
	$(cc) $(flags) -c $< -o $@

$(obj)collect_unit_test.o : $(unit.src)collect_unit_tests.c $(unit.inc)collect_unit_tests.h 
	$(cc) $(flags) -c $< -o $@

$(obj)unit.o: unit.c 
	$(cc) $(flags) -c $^ -o$@

clear:
	rm -rf $(obj)*.o *.exe