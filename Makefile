all: reverse.o list.o
	gcc -o reverse reverse.o list.o 

reverse.o: reverse.c
	gcc -c reverse.c -Wall -Werror 

list.o: list.c
	gcc -c list.c -Wall -Werror

clean:
	rm -f *.o reverse
