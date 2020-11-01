cc := gcc
cflags := -Wall -Werror -pedantic -std=c99

obj := ./obj/
src := ./src/
inc := ./inc/
uni.src := ./unit_tests/
uni.inc := ./inc/unit_test_headers/

app.exe : $(obj)main.o $(obj)io.o $(obj)sort.o
	$(cc) $^ -o $@

$(obj)main.o : main.c $(inc)main.h
	$(cc) $(cflags) -c $< -o $@

$(obj)io.o : $(src)io.c $(inc)io.h
	$(cc) $(cflags) -c $< -o $@

$(obj)sort.o : $(src)sort.c $(inc)sort.h
	$(cc) $(cflags) -c $< -o $@

unit_tests.exe : $(obj)unit.o $(obj)collect_unit_tests.o $(obj)read_unit_test.o $(obj)io.o
	$(cc) $^ -o $@ -lcheck

$(obj)unit.o : $(uni.src)unit_test.c $(uni.inc)unit_test.h
	$(cc) $(cflags) -c $< -o $@

$(obj)collect_unit_tests.o : $(uni.src)collect_unit_tests.c $(uni.inc)collect_unit_tests.h
	$(cc) $(cflags) -c $< -o $@

$(obj)read_unit_test.o : $(uni.src)read_unit_test.c $(uni.inc)read_unit.h
	$(cc) $(cflags) -c $< -o $@	

.PHONY: clean

clean:
	rm -rf $(obj)*.o *.exe