
all: hash

hash: hash.o linked_list.o
	gcc -o hash hash.o linked_list.o

hash.o: hash.c linked_list.h
	gcc -c -Wall -ansi -pedantic hash.c

linked_list.o: linked_list.c linked_list.h
	gcc -c -Wall -ansi -pedantic linked_list.c

clean:
	rm hash hash.o linked_list.o
