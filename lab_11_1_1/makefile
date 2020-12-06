cc := gcc
c_flag := -Wall -Werror -pedantic -std=c99

# uni_flags := -lcheck # windows
uni_flags := -pthread -lcheck_pic -pthread -lrt -lm -lsubunit # linux


src := ./src/*.c
test_src := ./tests/unit_tests/*.c
src_obj := ./src/*.o
test_obj := ./inc/unit_tests/*.o

objs := $(patsubst %.c, %.o, $(wildcard $(src)))
main_obj := $(patsubst %.c, %.o, $(wildcard main.c))
tests_objs := $(patsubst %.c, %.o, $(wildcard $(test_src)))

run : app.exe
	./app.exe

app.exe : $(main_obj) $(objs)
	$(cc) -o $@ $^

unit_tests.exe : $(tests_objs) $(objs)
	$(cc) -o $@ $^ $(uni_flags)

.PHONY : clear

clear :
	rm -rf *.exe $(main_obj) $(src_obj) $(tests_objs)