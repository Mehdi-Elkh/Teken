#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_CHOIX 5
#define TAILLE 1000



typedef struct {
	int numero;
	char intitule[TAILLE];
    char choix[NB_CHOIX][TAILLE];
    int place;
} Question;

typedef struct {
	char titre[100];
    int nb_questions;
    int negatif;
    int plusieurs; 
    Question question[100];
} QCM;

void afficher_QCM_dispo(){    
    printf("\n--- QCM DISPONIBLES ---\n");
    printf("1. maths.txt\n");
    printf("2. info.txt\n");
    printf("3. foot.txt\n");
}


int note(QCM qcm , int a , int note ){
    if(qcm.negatif == 1){
	    	if(a==qcm.question[i].place){
	      		printf("Vrai\n");
				note = note +1;
	    
	    	}
            else if(a == 5){
                note = note;
                printf("Question passée");
            }
	    	else{
	        	printf("Faux\n");
                note--;
	      	}
	    }
        else{
	    	if(a==qcm.question[i].place){
	      		printf("Vrai\n");
				note = note +1;
	   
	    	}
	    	else{
	        	printf("Faux\n");
                
	      	}
        }
}



void construct_QCM(QCM *qcm){
    	printf("Quel est le titre de votre QCM ? \n");
    	scanf("%s" , (*qcm).titre);
    	getchar();
	do{
    printf("Combien de questions voulez vous qu'il y ai dans votre QCM ? \n");
    scanf("%d" , &(*qcm).nb_questions);
    getchar();
		if((*qcm).nb_questions==0 || (*qcm).nb_questions<=0){
			printf("Veuillez choisir un nombre positif\n");
				}
	} while((*qcm).nb_questions==0 || (*qcm).nb_questions<=0);
    do{
        printf("Votre QCM est-il a points negatif ? (oui = 1 ; non = 0) \n");
    	scanf("%d" , &(*qcm).negatif);
    	getchar();
	    if((*qcm).negatif!=0 && (*qcm).negatif!=1){
		   	printf("Veuillez choisir un nombre valide entre 0 et 1\n");
		}
	  } while((*qcm).negatif!=0 && (*qcm).negatif!=1);
    for (int j = 0 ; j < (*qcm).nb_questions ; j++){
    	(*qcm).question[j].numero = j + 1;
            printf("Veuillez ecrire une question : \n");
    		fgets((*qcm).question[j].intitule, TAILLE ,stdin);
			   		printf("Veuillez enter une question");
				
	for(int i = 0 ; i < NB_CHOIX ; i++){
				printf("Veuillez ecrire le choix %d (5ème choix = passer la question) : \n", i +1);
            	fgets((*qcm).question[j].choix[i], TAILLE , stdin);
        }
        do{
            printf("A quelle place est la bonne reponse  ? \n");
        	scanf("%d", &(*qcm).question[j].place);
        	getchar();
			if((*qcm).question[j].place < 1 || (*qcm).question[j].place > NB_CHOIX){
				printf("Veuillez chosir un nombre entre 1 et %d",NB_CHOIX);
			}
		} while((*qcm).question[j].place < 1 || (*qcm).question[j].place > NB_CHOIX);
		
    }
    
}



void fichier_QCM(QCM *qcm){
    char filename[100];
    sprintf(filename , "%s.txt" , (*qcm).titre);
    
    FILE *f = fopen(filename , "w");
    
    if (f == NULL){
   		printf("Erreur ouverture fichier\n");
		return;
    }
    fprintf(f, "%d\n" , (*qcm).nb_questions);
    fprintf(f, "%d\n" , (*qcm).negatif);
    //Faudra ecrire si le qcm a plusieur reponses possibles pour pouvoir directement rgarder ici pour le calcul de la note
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


// BOUGEZ PAS la fonction d'ici sinon j'ai un probleme de declaration dans le mode étudiant 
void lire_QCM(QCM *qcm,char filename[]){
  
    FILE *f = fopen(filename , "r");
    if (f == NULL){
   		printf("Erreur ouverture fichier\n");
		return;
    }
	fscanf(f, "%d" , &(*qcm).nb_questions);
	fscanf(f, "%d" , &(*qcm).negatif);
    //Faudra lire si le qcm a plusieur reponses possibles pour pouvoir directement regarder ici pour le calcul de la note
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


void mode_ensaignant(){
    QCM qcm;
	construct_QCM(&qcm);
    fichier_QCM(&qcm);
    
}


void mode_etudiant(){
    QCM qcm ;
    int note , a;
    note = 0;
	int resulta;
	int choixQCM;              
	char fichier[100];
	
    printf("mode étudiant\n");
	afficher_QCM_dispo();
	
	printf("Choisissez le QCM a passer : ");
	scanf("%d", &choixQCM);   
	if(choixQCM == 1){
    	lire_QCM(&qcm, "maths.txt");
	}

	else if(choixQCM == 2){
	    lire_QCM(&qcm, "info.txt");
	}
	
	else if(choixQCM == 3){
	    lire_QCM(&qcm, "foot.txt");
	}
	
	
	else{
	    printf("Choix invalide\n");
	    return;
	}
	for( int i=0; i < qcm.nb_questions;i++){
		printf("\nQuestion %d :\n",qcm.question[i].numero);
		printf("%s", qcm.question[i].intitule);

		for (int j=0;j< NB_CHOIX;j++){
			printf("%d-",j+1);
			printf("%s",qcm.question[i].choix[j]);
		}
		printf("Votre réponse :");
		resulta= scanf("%d",&a);
		if(resulta!=1){
			printf("faux");
			while(getchar() != '\n');
            continue;	
		 }
        if(qcm.negatif == 1){
	    	if(a==qcm.question[i].place){
	      		printf("Vrai\n");
				note = note +1;
	    
	    	}
            else if(a == 5){
                note = note;
                printf("Question passée");
            }
	    	else{
	        	printf("Faux\n");
                note--;
	      	}
	    }
        else{
	    	if(a==qcm.question[i].place){
	      		printf("Vrai\n");
				note = note +1;
	   
	    	}
	    	else{
	        	printf("Faux\n");
                
	      	}
        }
	}
	 printf("votre note est %d sur %d \n",note, qcm.nb_questions);

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



    
