exec: construct.o fichier.o mode.o main.o
	gcc construct.o fichier.o mode.o main.o -o  exec


construct.o : bibliotheque.h construct.c construct.h
	gcc -c construct.c


fichier.o : bibliotheque.h construct.c construct.h fichier.c fichier.h
	gcc -c fichier.c


mode.o : bibliotheque.h construct.c construct.h fichier.c fichier.h mode.c mode.h
	gcc -c mode.c


main.o : bibliotheque.h construct.c construct.h fichier.c fichier.h mode.c mode.h main.c 
	gcc -c main.c
