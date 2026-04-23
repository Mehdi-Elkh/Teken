#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_CHOIX 3

//void shuffle(char *tab[], int n){
//    for(int i = n - 1; i > 0 ; i--){
//        int j = rand() % (i + 1);
//        char *tmp = tab[i];
//        tab[i] = tab[j];
//        tab[j] = tmp;       
//    }
//}

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
	char question[1000], reponse[1000] , choix[1000];
    int nb_questions, place; 
    int negatif , plusieur ;
	char *tab[NB_CHOIX];
    printf("mode ensaignant\n");
    printf("Combien de questions voulez vous qu'il y ai dans votre QCM ? \n");
    scanf("%d" , &nb_questions);
    getchar();
    //Verification de la variable
    printf("Souhaitez-vous qu'il y ai plusieurs reponses possible ? (oui : 1 / non : 0) \n");
    scanf("%d", &plusieur);
    getchar();
    //Verification de la variable
		// if (plusieur = 1){
  	    //     on demande pour les point negatif et on fait entrer un QCM avec plusieurs reponses possibles (utilisateur qui choisi le nombre a chaque fois)
        //}else{
        //     on demande pour les point negatif et on fait entrer un QCM avec une seul reponse possible comme j'ai fait juste en dessous
        //}
    printf("Souhaitez-vous mettre des points negatifs dans le QCM ? (oui : 1 / non : 0) \n");
    scanf("%d", &negatif);
    getchar();
    //Verification de la variable
    	//Ca impactera la note au final de l'eleve donc faudra la calculer par rapport aux points negatifs (ou non) dans la fonction qui calculera la note)
    for(int j = 1; j <= nb_questions ; j++){
        printf("Veuillez ecrire une question : \n");
        fgets(question, 1000 ,stdin) ;
        //Verification de la variable
    	printf("Veuillez entrez la bonne reponse : \n");
        fgets(reponse, 1000 , stdin);
    	//Verification de la variable
        printf("A quelle place voulez-vous que la bonne reponse soit ? \n");
        scanf("%d", &place);
        getchar();
        //Verification de la variable
        for(int i = 0; i < NB_CHOIX; i++){
            if( i == place ){
                tab[i] = strdup(reponse);
            }else{
        		printf("Veuillez ecrire un autre choix que vous voulez proposez : \n");
    			scanf("%s", choix);
            	tab[i] = strup(choix);
            }
        }    
        
    }
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



