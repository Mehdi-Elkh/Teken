  #include "mode.h"


void mode_ensaignant(){
    QCM qcm;
				construct_QCM(&qcm);
    fichier_QCM(&qcm);
				titre_QCM(&qcm);
    
}

void mode_etudiant(){
 QCM qcm ;
 int note = 0 , rep[NB_CHOIX];
	float note_20;
  
	int resulta;
	int choixQCM;    
	char titre[100];          
	char fichier[100];
	
 printf("mode étudiant\n");
	afficher_QCM_dispo();
	
	printf("Choisissez le QCM a passer : ");
	scanf("%d" , &choixQCM);
	
	FILE *f = fopen("liste_qcm.txt","r");
	
	if (f == NULL){
   		printf("Erreur ouverture fichier\n");
		return;
	}

	for ( int i = 0 ; i < choixQCM ; i++){
		fgets(titre , 100 , f);
	}

	fclose(f);
	
	titre[strlen(titre)-1] = '\0';
		
	sprintf(fichier , "%s.txt" , titre);
	
	lire_QCM(&qcm , fichier);

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
		note_20 = (note/qcm.nb_questions)*20
	 printf("Votre note est de %f sur 20 \n",note_20);
		

}
