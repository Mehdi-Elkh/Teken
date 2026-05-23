#include "fichier.h"

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
    
    
    for(int j = 0 ; j < (*qcm).nb_questions ; j++){
        fprintf(f , "%d.%s" , (*qcm).question[j].numero , (*qcm).question[j].intitule);
        
        for(int i = 0 ; i < NB_CHOIX ; i++){
        	fprintf(f, "%s" , (*qcm).question[j].choix[i]);
            fprintf(f, "%d\n" , (*qcm).question[j].vrai[i]);
        }
    }
    fclose(f);
}

void lire_QCM(QCM *qcm,char filename[]){
  
    FILE *f = fopen(filename , "r");
    if (f == NULL){
   		printf("Erreur ouverture fichier\n");
		return;
    }
    
	fscanf(f, "%d" , &(*qcm).nb_questions);
	fscanf(f, "%d" , &(*qcm).negatif);

    for(int j = 0 ; j < (*qcm).nb_questions ; j++){
        fscanf(f, "%d.", &(*qcm).question[j].numero);
        fgets((*qcm).question[j].intitule, TAILLE , f);
        
        for(int i = 0 ; i < NB_CHOIX ; i++){
        	fgets((*qcm).question[j].choix[i], TAILLE , f);
            fscanf(f, "%d\n" , &(*qcm).question[j].vrai[i]);
        }
    }
    fclose(f);
}

void QCM_base(){
   
   FILE *f = fopen ("liste_qcm.txt" , "w");
   
   
   if ( f!= NULL){
      fclose(f);
      return;
   }
   
   if( f == NULL ){
      printf("Erreur ouverture fichier\n");
      return;
   }
   fprintf(f , "maths\n");
   fprintf(f , "info\n");
   fprintf(f , "foot\n");
   
   fclose(f);
}


void titre_QCM(QCM *qcm){
   
	printf("Titre ajouté : %s\n", (*qcm).titre);

   FILE *f = fopen("liste_qcm.txt","a");
   
   if( f == NULL ){
      printf("Erreur ouverture fichier\n");
      return;
   }
   
      fprintf(f,"%s\n",(*qcm).titre);
      
      fclose(f);
}



void afficher_QCM_dispo(){
   FILE *f = fopen("liste_qcm.txt","r");
   
   char titre[100];
   int i = 1;
   
   if( f == NULL ){
      printf("Erreur ouverture fichier\n");
      return;
   }
   
   printf("----QCM DISPONIBLES----\n");
   
   while(fgets(titre, 100 , f ) != NULL){
      printf("%d. %s" , i , titre);
      i++;
   }
}