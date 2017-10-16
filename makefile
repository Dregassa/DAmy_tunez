all: linked_list.o music_library.o main.o
	gcc -o libtest main.o linked_list.o music_library.o

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c linked_list.h

music_library.o:
	gcc -c music_library.c music_library.h linked_list.h

main.o:
	gcc -c main.c music_library.h

clean:
	rm *o
	rm *gch
	rm *~

run: all
	./libtest
