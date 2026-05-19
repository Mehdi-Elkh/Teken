exec: construct.o fichier.o mode.o main.o
	gcc construct.o fichier.o mode.o main.o exec


construct.o : bilbliotheque.h construct.c construct.h
	gcc -c construct.c


fichier.o : bilbliotheque.h construct.c construct.h fichier.c fichier.h
	gcc -c fichier.c


mode.o : bilbliotheque.h construct.c construct.h fichier.c fichier.h mode.c mode.h
	gcc -c mode.c


main.o : bilbliotheque.h construct.c construct.h fichier.c fichier.h mode.c mode.h main.c main.h
	gcc -c main.c