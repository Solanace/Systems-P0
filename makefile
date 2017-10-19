all: linked_list.c music_library.c main.c
	gcc linked_list.c music_library.c main.c

run: all
	./a.out

clean:
	rm a.out
