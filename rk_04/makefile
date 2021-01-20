.PHONY : clean

run : app.exe
	./app.exe

app.exe : main.o list_operations.o
	gcc $^ -o $@

list_operations.o : list_operations.c
	gcc -Wall -Werror -std=c99 -c $<

main.o : main.c
	gcc -Wall -Werror -std=c99 -c $<

clean :
	rm -rf *.o *.exe