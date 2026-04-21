#include <stdlib.h>
#include <stdio.h>
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
    printf("votre note est %d \n",&note);


}


int main(){
  int choix;

  do{
    printf("\n --- MENU PRINCIPAL--- \n");
    printf("1. Mode Ensaignant \n");
    printf("2. Mode Etudiant \n");
    printf("3. Quitter \n");
    scanf("%d", &choix);

    if(choix == 1){
      printf("Mode enseignant \n");
    }
    else if(choix == 2){
        mode_etudiant();
    }
    else{
        printf("Ce que vous avez entré n'est pas valide, veuillez entrer un nombre entre 1 et 3. \n");
    }
  } while(choix != 3);

}
