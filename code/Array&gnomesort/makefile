
program: main.o array.o gnome_sort.o
	gcc -o program main.o array.o gnome_sort.o 

main.o: main.c
	gcc -c main.c

array.o: array.c
	gcc -c array.c

gnome_sort.o: gnome_sort.c
	gcc -c gnome_sort.c

clean:
	rm -f *.o program *~
