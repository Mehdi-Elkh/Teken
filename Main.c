#include "bibliotheque.h"
#include "construct.h"
#include "fichier.h"
#include "mode.h"





int main() {
    
    QCM_base();
    
    int choix;
    int sousChoix;
	int resulta;
    char motDePasse[20];

    do {
        printf("\n=== MENU GENERAL ===\n");
        printf("1. Mode enseignant\n");
        printf("2. Mode etudiant\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        resulta = scanf("%d", &choix);

        if(resulta != 1){
            printf("Choix invalide\n");
            while(getchar() != '\n'){
            }
            choix = 0;
        }

        if (choix == 1) {
            
            printf("Entrez le mot de passe : ");
            scanf("%s", motDePasse);

            if (strcmp(motDePasse, "Teken2025") == 0) {
                
                do {
                    printf("\n--- MENU ENSEIGNANT ---\n");
                    printf("1. Creer un QCM\n");
                    printf("2. Retour\n");
                    printf("Votre choix : ");
                    resulta = scanf("%d", &sousChoix);

                    if(resulta != 1){
                        printf("Choix invalide\n");
                        while(getchar() != '\n'){
                        }
                        sousChoix = 0;
                    }

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
                resulta = scanf("%d", &sousChoix);

                if(resulta != 1){
                    printf("Choix invalide\n");
                    while(getchar() != '\n'){
                    }
                    sousChoix = 0;
                }


                if (sousChoix == 1) {
                   afficher_QCM_dispo();
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



    
