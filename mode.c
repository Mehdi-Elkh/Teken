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
	for( int i=0; i < qcm.nb_questions;i++){
		int juste =1;
		printf("\nQuestion %d :\n",qcm.question[i].numero);
		printf("%s", qcm.question[i].intitule);

		for (int j=0;j< NB_CHOIX;j++){
			printf("%d-",j+1);
			printf("%s",qcm.question[i].choix[j]);
		
			printf(" (1 = vrai / 0 = faux / 2 = passer question) : ");
    		resulta = scanf("%d", &rep[j]);
            
    		if (resulta != 1) {
        		printf("Erreur\n");
        		while (getchar() != '\n');
        		rep[j] = 0;
            }
			if (rep[j] == 2) {
        		printf("Question passée\n");
        		juste = 0;
       			break;
			}

			if (rep[j] != qcm.question[i].vrai[j]) {
        		juste = 0;
    		}
    	}
    	if (juste == 0) {
    		if (rep[0] == 2) {
                //On passe la question
            } else {
       		 	printf("Faux\n");
        		if (qcm.negatif == 1) {
                	note--;
    			}
			}
		}
		else {
    		printf("Vrai\n");
    		note++;
		}  
	}
	 printf("Votre note est %d sur %d \n",note, qcm.nb_questions);

}