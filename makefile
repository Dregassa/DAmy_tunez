all: linked_list.o playlist.o main.o
	gcc -o libtest main.o linked_list.o playlist.o

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c linked_list.h

playlist.o:
	gcc -c playlist.c playlist.h linked_list.h

main.o:
	gcc -c main.c playlist.c

clean:
	rm *.o
	rm *.gch
	rm *~

run: all
	./libtest
