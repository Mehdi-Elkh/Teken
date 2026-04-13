#include <stdlib.h>

int main(){
  int choix;

  do{
    printf("\n --- MENU PRINCIPAL--- \n");
    printf("1. Mode Ensaignant \n");
    printf("2. Mode Etudiant \n");
    printf("3. Quitter \n");
    scanf("%d", &choix);

    if(choix == 1){
      printf("Mode enseignant ...\n);
    }
    else if(choix == 2){
        printf("Moee enseeignant ...\n);
    }
    else{
        printf("Ce que vous avez entré n'est pas valide, veuillez entrer un nombre entre 1 et 3. \n");
    }
  } while(choix != 3);

}
