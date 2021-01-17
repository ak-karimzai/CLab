.PHONY : clear

cc := gcc 
c_flags := -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=c99

src_dir := ./src/*.c
src_obj := ./src/*.o

unit_dir := ./tests/unit_tests/*.c
unit_obj := ./tests/unit_tests/*.o

uni_flags := -lcheck # windows
# uni_flags := -pthread -lcheck_pic -pthread -lrt -lm -lsubunit # linux


objs := $(patsubst %.c, %.o, $(wildcard $(src_dir)))

main_obj := $(patsubst %.c, %.o, $(wildcard main.c))

unit_obj := $(patsubst %.c, %.o, $(wildcard $(unit_dir)))

app.exe : $(main_obj) $(objs)
	$(cc) -o $@ $^ -lm

unit_tests.exe : $(unit_obj) $(objs)
	$(cc) $^ -o $@ $(uni_flags)

clear :
	rm -rf *.exe $(src_obj) $(unit_obj) *.o