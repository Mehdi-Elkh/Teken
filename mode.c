#include "mode.h"


void mode_ensaignant(){
    QCM qcm;
	construct_QCM(&qcm);
    fichier_QCM(&qcm);
    
}

void mode_etudiant(){
    QCM qcm ;
    int note = 0 , rep[NB_CHOIX];
  
	int resulta;
	int choixQCM;              
	char fichier[100];
	
    printf("mode étudiant\n");
	afficher_QCM_dispo();
	
	printf("Choisissez le QCM a passer : ");
	printf("Choisissez le QCM a passer : ");
	resulta = scanf("%d", &choixQCM);
	
	if(resulta != 1){
	    printf("Choix invalide\n");
	    while(getchar() != '\n'){
	    }
	    return;
	} 
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