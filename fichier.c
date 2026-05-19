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