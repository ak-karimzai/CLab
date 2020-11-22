.PHONY : clear

cc := gcc 
c_flags := -Wall -Werror -std=c99 -pedantic

src_dir := ./src/*.c
src_obj := ./src/*.o

unit_dir := ./tests/unit_tests/*.c

uni_flags := -lcheck # windows
# uni_flags := -pthread -lcheck_pic -pthread -lrt -lm -lsubunit # linux


objs := $(patsubst %.c, %.o, $(wildcard $(src_dir)))

main_obj := $(patsubst %.c, %.o, $(wildcard main.c))

unit_obj := $(patsubst %.c, %.o, $(wildcard $(unit_dir)))

app.exe : $(main_obj) $(objs)
	$(cc) $(c_flags) -o $@ $^ -lm

unit_tests.exe : $(unit_obj) $(objs)
	$(cc) $^ -o $@ -lm $(uni_flags)

clear :
	rm -rf *.exe $(src_obj) *.o