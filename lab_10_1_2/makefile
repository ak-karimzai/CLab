.PHONY : clear

cc := gcc 
c_flags := -Wall -Werror -std=c99 -pedantic

src_dir := ./src/*.c
src_obj := ./src/*.o

objs := $(patsubst %.c, %.o, $(wildcard $(src_dir)))

main_obj := $(patsubst %.c, %.o, $(wildcard main.c))

unit_obj := $(patsubst %.c, %.o, $(wildcard unit.c))

app.exe : $(main_obj) $(objs)
	$(cc) $(c_flags) -o $@ $^ -lm

unit_tests.exe : unit.c
	gcc -Wall -Werror -Wextra -pedantic -std=c99 unit.c -o $@

clear :
	rm -rf *.exe $(src_obj) *.o