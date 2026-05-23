#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_CHOIX 5
#define TAILLE 1000



typedef struct {
	int numero;
	char intitule[TAILLE];
    char choix[NB_CHOIX][TAILLE];
    int vrai[NB_CHOIX];
} Question;

typedef struct {
	char titre[100];
    int nb_questions;
    int negatif;
    Question question[100];
} QCM;
#endif
