.PHONY : clear

cc := gcc
c_flags := -Wall -Werror -Wextra -std=c99 -pedantic

src_dir := ./src/*.c
src_obj := ./src/*.o

objs := $(patsubst %.c, %.o, $(wildcard $(src_dir)))

main_obj := $(patsubst %.c, %.o, $(wildcard main.c))

unit_obj := $(patsubst %.c, %.o, $(wildcard unit.c))

run : app.exe
	./app.exe

app.exe : $(main_obj) $(objs)
	$(cc) $(c_flags) -o $@ $^ -lm

unit_tests.exe : $(unit_obj)
	$(cc) -o $@ $^ 

memcheck : app.exe
	valgrind --leak-check=full ./app.exe

clear :
	rm -rf $(src_obj) *.exe *.o *.out