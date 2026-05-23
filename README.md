# Teken
Présentation du projet

Ce projet est une application de QCM réalisée en langage C dans le terminal.

Le programme possède deux modes :

  -un mode enseignant
  
  -un mode étudiant
  
Les QCM sont enregistrés dans des fichiers .txt puis lu par le programme



FONCTIONNALITE

Mode enseignant
Le mode enseignant permet :
  
  -créer un QCM
  
  -choisir le titre du QCM
  
  -choisir le nombre de questions
  
  -choisir si le QCM possède des points négatifs
  
  -écrire les questions
  
  -écrire les réponses
  
  -choisir la bonne réponses
  
Chaque QCM est enregistré automatiquement dans un fichier .txt.



MODE ETUDIANT

Le mode étudiant permet :

  -afficher les QCM disponibles
  
  -choisir un QCM
  
  -répondre aux questions
  -passer une question
  
  -afficher la note finale
  
  -Le programme vérifie également :
  
    -les lettres à la place des nombres
    
    -les nombres invalides
    
    -les erreurs utilisateur


  STRUCTURE DU PROJET:
 Fichier           Rôle                              

 Main.c           menu principal                    
construct.c       création des QCM
fichier.c         lecture et écriture des fichiers
mode.c            mode étudiant et enseignant
bibliotheque.h    structures et constantes
construct.h       prototypes du mode création       
fichier.h        prototypes des fonctions fichiers 
mode.h          prototypes des modes 
makefile         compilation automatique



  

