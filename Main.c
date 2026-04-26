.#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_CHOIX 4
#define TAILLE 1000

//void shuffle(char *tab[], int n){
//    for(int i = n - 1; i > 0 ; i--){
//        int j = rand() % (i + 1);
//        char *tmp = tab[i];
//        tab[i] = tab[j];
//        tab[j] = tmp;       
//    }
//}

typedef struct {
	int numero;
	char intitule[TAILLE];
    char choix[NB_CHOIX][TAILLE];
    int place;
} Question;

typedef{
    int nb_questions;
    int negatif;
    int plusieurs; 
    Question question[100];
} QCM;



void mode_etudiant(){
    int a;
    int note;
    note = 0;
    printf("mode étudiant\n");
    printf("quelle est la racine carré de 25?\n");
    printf("1- 10\n");
    printf("2- 5\n");
    printf("3- 20\n");
    scanf("%d",&a);
    //Verification de la variable
    if(a==1){
        printf("Faux\n");
    }
    else if(a==2){
        printf("Vrai\n");
        note = note + 1;
    }
    else{
        printf("Faux\n");
      }
    printf("votre note est %d \n",note);


}

void mode_ensaignant(){
    QCM qcm;
	construct_QCM(&qcm);
    fichier_QCM(&qcm);
    
}

void construct_QCM(QCM *qcm){
    
    printf("Combien de questions voulez vous qu'il y ai dans votre QCM ? \n");
    scanf("%d" , &(*qcm).nb_questions);
    getchar();
    //Verification de la variable
    for (int j = 0 ; j < (*qcm).nb_questions ; j++){
    	(*qcm).question[j].numero = j + 1;
		printf("Veuillez ecrire une question : \n");
    	fgets((*qcm).question[j].intitule, TAILLE ,stdin);
        //Verification de la variable
        for(int i = 0 ; i < NB_CHOIX ; i++){
            printf("Veuillez ecrire le choix %d : \n", i +1);
            fgets((*qcm).question[j].choix[i], TAILLE , stdin); 
            //Verification de la variable
        }
        printf("A quelle place est la bonne reponse  ? \n");
        scanf("%d", &(*qcm).question[j].place);
        getchar();
        //Verification de la variable
    }
    
}


void fichier_QCM(QCM *qcm){
    
    FILE *f = fopen("qcm.txt" , "w");
    if (f == NULL){
   		printf("Erreur ouverture fichier\n");
		return;
    }
    fprintf(f, "%d" , (*qcm).nb_questions);
    //Faudra ecrire si le qcm a plusieur reponses possibles et si il est a point negatif aussi pour pouvoir directement rgarder ici pour le calcul de la note
    //Ou pas on peut juste traiter la structure
    for(int j = 0 ; j < (*qcm).nb_questions ; j++){
        fprintf(f , "%d.%s" , (*qcm).question[j].numero , (*qcm).question[j].intitule);
        fprintf(f, "%d\n" , (*qcm).question[j].place);
        
        for(int i = 0 ; i < NB_CHOIX ; i++){
            fprintf(f, "%s" , (*qcm).question[j].choix[i]);
        }
    }
    fclose(f);
}


void lire_QCM(QCM *qcm){
    
    FILE *f = fopen("qcm.txt" , "r");
    if (f == NULL){
   		printf("Erreur ouverture fichier\n");
		return;
    }
	fscanf(f, "%d" , &(*qcm).nb_questions);
    //Faudra lire si le qcm a plusieur reponses possibles et si il est a point negatif aussi pour pouvoir directement regarder ici pour le calcul de la note
    //Ou pas on peut juste traiter la structure
    for(int j = 0 ; j < (*qcm).nb_questions ; j++){
        fscanf(f, "%d.", &(*qcm).question[j].numero);
        fgets((*qcm).question[j].intitule, TAILLE , f);
        fscanf(f, "%d\n" , &(*qcm).question[j].place);
        
        for(int i = 0 ; i < NB_CHOIX ; i++){
            fgets((*qcm).question[j].choix[i], TAILLE , f);
        }
    }
    fclose(f);
}



int note(QCM *qcm , int *reponses){
    int note;
    for (int j = 0 ; j < (*qcm).nb_questions ; j++){
        if ( reponses[j] == (*qcm).questions([j].place){
            note++ ; 
        }else if (negatif){
            note-- ; 
        }
    }
    return note;
}


int main() {
    int choix;
    int sousChoix;
    char motDePasse[20];

    do {
        printf("\n=== MENU GENERAL ===\n");
        printf("1. Mode enseignant\n");
        printf("2. Mode etudiant\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            
            printf("Entrez le mot de passe : ");
            scanf("%s", motDePasse);

            if (strcmp(motDePasse, "Teken2025") == 0) {
                
                do {
                    printf("\n--- MENU ENSEIGNANT ---\n");
                    printf("1. Creer un QCM\n");
                    printf("2. Retour\n");
                    printf("Votre choix : ");
                    scanf("%d", &sousChoix);

                    if (sousChoix == 1) {
                        mode_ensaignant();
                    }
                    else if (sousChoix == 2) {
                        printf("Retour au menu general.\n");
                    }
                    else {
                        printf("Choix invalide.\n");
                    }

                }while (sousChoix != 2);
                
            }
            else {
                printf("Mot de passe incorrect.\n");
            }
        }
        else if (choix == 2) {
            
            do {
                printf("\n--- MENU ETUDIANT ---\n");
                printf("1. Voir les QCM disponibles\n");
                printf("2. Passer un QCM\n");
                printf("3. Retour\n");
                printf("Votre choix : ");
                scanf("%d", &sousChoix);

                if (sousChoix == 1) {
                    //On doit afficher la liste des fichiers pour qu'il puisse choisir quelle QCM il passe 
                }
                else if (sousChoix == 2) {
                    mode_etudiant();
                }
                else if (sousChoix == 3) {
                    printf("Retour au menu general.\n");
                }
                else {
                    printf("Choix invalide.\n");
                }

            }while (sousChoix != 3);
            
        }
        else if (choix == 3) {
            return 0;
        }
        else {
            printf("Choix invalide.\n");
        }

    }while (choix != 3);

    return 0;
}



