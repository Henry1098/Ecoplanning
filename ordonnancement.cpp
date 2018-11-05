// Algorithme de calcul des dates au plus tot et au plus tard
//

#include "ordonnancement.h"


void dates_plus_tot(int *sommets, int nbt,int *staches,int *duree, int** pr, int *ddtot,int *dftot)
{
 int indx;
 int ipred;
 int itask; int ok;
 //  la premiere tache stockee demarre avec l indice 1
 //  l indice zero sert a initialiser une tache fictive Start;
 ddtot[0]; // tstart = 0;
 sommets[0] = 0;
 staches[0] = 0;     // tache fictives start
 // on rajoute une tache fictive "END" dans la liste des sommets
 sommets[nbt+1]=0x7fff;

 for (indx=1;indx<=nbt;indx++)    // boucle principale
   {
    // ne doit pas appartenir a Staches et doit avoir un predecesseur deja decrit
    ok=1;
    for (int ix=0;ix<=nbt+1;ix++)
       { if (sommets[indx]==staches[ix]) {ok=0; break; }
       }
    if (ok)   // la tache n est pas dans la liste
      {
       // boucle sur les predecesseurs possibles
       int imax=0;
       ipred=1;

       while (pr[indx][ipred]!=0)
         {
          imax = pr[indx][ipred];
          ipred++;
         }
      }

   }


}

void dates_plus_tard(int *sommets, int nbt,int *staches,int *duree, int **succ, int dfp,int *ddtard, int *dftard)
{



}







