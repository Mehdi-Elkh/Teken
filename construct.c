
#include "bibliotheque.h"





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
				
		for(int i = 0 ; i < NB_CHOIX - 1 ; i++){
				printf("Veuillez ecrire le choix %d : \n", i + 1);
            	fgets((*qcm).question[j].choix[i], TAILLE , stdin);
        
        	do{
                
            	printf("Est ce que le choix%d est t'il vrai ? (1=oui , 0=non) \n", i+1);
        		scanf("%d", &(*qcm).question[j].vrai[i]);
        		getchar();
				if((*qcm).question[j].vrai[i] != 1 && (*qcm).question[j].vrai[i] != 0){
					printf("Veuillez chosir un nombre entre 0 et 1");
				
        		}
			
            } while((*qcm).question[j].vrai[i] != 0 && (*qcm).question[j].vrai[i] != 1);
        }
    }
}