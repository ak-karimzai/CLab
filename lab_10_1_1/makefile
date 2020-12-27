.PHONY : clear

cc := gcc 
c_flags := -Wall -Werror -std=c99 -pedantic

uni_flags := -pthread -lcheck_pic -pthread -lrt -lm -lsubunit # linux
# uni_flags := -lcheck # windows

src_dir := ./src/*.c
src_obj := ./src/*.o

Unit_dir := ./tests/unit_tests/*.c
Unit_objs := ./tests/unit_tests/*.o

objs := $(patsubst %.c, %.o, $(wildcard $(src_dir)))

main_obj := $(patsubst %.c, %.o, $(wildcard main.c))

unit_objs := $(patsubst %.c, %.o, $(wildcard $(Unit_dir)))

unit_obj := $(patsubst %.c, %.o, $(wildcard unit_tests.c))

app.exe : $(main_obj) $(objs)
	$(cc) -o $@ $^

unit_tests.exe : $(unit_obj) $(unit_objs) $(objs)
	$(cc) -o $@ $^ $(uni_flags)

clear :
	rm -rf $(src_obj) $(Unit_objs) *.exe *.o *.out