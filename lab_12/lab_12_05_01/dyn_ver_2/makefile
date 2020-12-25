cc := gcc
cflags := -std=c99 -Wall -Werror 
position_independent_code := -fPIC

dyn_lib_run := -L. -l_arr

# uni_flags := -lcheck # windows
uni_flags := -pthread -lcheck_pic -pthread -lrt -lm -lsubunit # linux

dyn_lib := lib_arr.so

head = ./inc/
src = ./src/
obj = ./obj/
unit.test = ./unit_tests/
unit.test.header = ./inc/unit_test_headers/


all : Export app.exe

app.exe: $(obj)main.o $(obj)output.o $(obj)input.o
	$(cc)  $^ -o $@ -ldl

unit_tests.exe : $(obj)unit_test.o $(obj)collect_unit_tests.o $(obj)key_unit_test.o $(obj)my_sort_tests.o
	$(cc) $^ -o $@ $(uni_flags) $(dyn_lib_run)

Export : $(dyn_lib)
	export LD_LIBRARY_PATH=LD_LIBRARY_PATH:.

$(dyn_lib) : $(obj)sort.o $(obj)key.o
	$(cc) $(position_independent_code) -shared -o $@ $^

$(obj)sort.o: $(src)sort.c $(head)sort.h
	$(cc) $(cflags) $(position_independent_code) -c $< -o $@

$(obj)key_unit_test.o: $(unit.test)key_unit_test.c $(unit.test.header)key_unit_test.h
	$(cc) $(cflags) -c $< -o $@

$(obj)collect_unit_tests.o: $(unit.test)collect_unit_tests.c $(unit.test.header)collect_unit_tests.h
	$(cc) $(cflags) -c $< -o $@

$(obj)my_sort_tests.o: $(unit.test)my_sort_tests.c $(unit.test.header)mysort_unit_test.h
	$(cc) $(cflags) -c $< -o $@

$(obj)key.o: $(src)key.c $(head)key.h
	$(cc) $(cflags) $(position_independent_code) -c $< -o $@

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
	rm -rf *.exe $(obj)*.o .out *.so *.o
