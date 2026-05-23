#ifndef FICHIER_H
	#define FICHIER_H
    
    #include "bibliotheque.h"
    #include "construct.h"
    
    void fichier_QCM(QCM *qcm);
    void lire_QCM(QCM *qcm,char filename[]);
    void QCM_base();
    void titre_QCM(QCM *qcm);
    void afficher_QCM_dispo(QCM *qcm);
#endif
