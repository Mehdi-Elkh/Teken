#include <stdlib.h>
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
	char intitule[TAILLE];
    char choix[NB_CHOIX][TAILLE];
    int place;
} Question;

typedef{
    int nb_questions;
    Question questions[100];
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
    fichier_qcm(&qcm);
}

void construct_QCM(QCM *qcm){
    
    printf("Combien de questions voulez vous qu'il y ai dans votre QCM ? \n");
    scanf("%d" , &qcm.nb_questions);
    getchar();
    //Verification de la variable
    for (int j = 1 ; j <= qcm.nb_questions ; j++){
		printf("Veuillez ecrire une question : \n");
        fgets(qcm.question[j].intitule, TAILLE ,stdin);
        //Verification de la variable
        for(int i = 1 ; i < NB_CHOIX ; i++){
            printf("Veuillez ecrire le choix %d : \n", i);
            fgets(qcm.questions[j].choix[i], TAILLE , stdin); 
            //Verification de la variable
        }
        printf("A quelle place est la bonne reponse  ? \n");
        scanf("%d", &qcm.questions[j].place);
        getchar();
        //Verification de la variable
    }
    
}

void fichier_qcm(QCM *qcm){
    
    FILE *f = fopen("qcm.txt" , "w");
    
    fprintf(f, "%d" , qcm.qcm.nb_questions);
    //Faudra ecrire si le qcm a plusieur reponses possibles et si il est a point negatif aussi pour pouvoir directement rgarder ici pour le calcul de la note
    
    for(int j = 1 ; j <= qcm.nb_questions ; j++){
        fprintf(f , "%d.%s" , j , qcm.question[j].intitule);
        fprintf(f, "%d" , qcm.question[j].place);
        
        for(int i = 1 ; i <= NB_CHOIX , i++){
            fprintf(f, "%s" , qcm.questions[j].choix[]);
        }
    }
    fclose(f);
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



