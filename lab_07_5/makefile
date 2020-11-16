cc := gcc
cflags := -std=c99 -Wall -Werror -pedantic

# uni_flags := -lcheck # windows
uni_flags := -pthread -lcheck_pic -pthread -lrt -lm -lsubunit # linux


head = ./inc/
src = ./src/
unit.test = ./unit_tests/
unit.test.header = ./inc/unit_test_headers/
obj = ./obj/

#run: app.exe 
#	./app.exe ./functional_tests/pos_in_1.txt .out

app.exe: $(obj)sort.o $(obj)main.o $(obj)output.o $(obj)input.o $(obj)key.o
	$(cc) $^ -o $@

unit_tests.exe: $(obj)unit_test.o $(obj)sort.o $(obj)key.o $(obj)key_unit_test.o $(obj)my_sort_tests.o $(obj)collect_unit_tests.o
	$(cc) $^ -o $@ $(uni_flags)

#unit_tests.exe: $(obj)unit_test.o $(obj)key.o
#	$(cc) $^ -o $@ $(uni_flags)

$(obj)sort.o: $(src)sort.c $(head)sort.h
	$(cc) $(cflags) -c $< -o $@

$(obj)key_unit_test.o: $(unit.test)key_unit_test.c $(unit.test.header)key_unit_test.h
	$(cc) $(cflags) -c $< -o $@ $(uni_flags)

$(obj)collect_unit_tests.o: $(unit.test)collect_unit_tests.c $(unit.test.header)collect_unit_tests.h
	$(cc) $(cflags) -c $< -o $@ $(uni_flags)

$(obj)my_sort_tests.o: $(unit.test)my_sort_tests.c $(unit.test.header)mysort_unit_test.h
	$(cc) $(cflags) -c $< -o $@ $(uni_flags)

$(obj)key.o: $(src)key.c $(head)key.h
	$(cc) $(cflags) -c $< -o $@

$(obj)input.o: $(src)input.c $(head)input.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

$(obj)output.o: $(src)output.c
	$(cc) -I$(head) $(cflags) -c $< -o $@

$(obj)unit_test.o: $(unit.test)unit_test.c $(unit.test.header)unit_function.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

$(obj)main.o: main.c $(head)main.h
	$(cc) -I$(head) $(cflags) -c $< -o $@

del: clean

.PHONY: clean

clean:
	rm -rf *.exe $(obj)*.o .out