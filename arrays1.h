#ifndef ARRAYSH
#define ARRAYSH

#define MAX_T  4200
#define PS     20

int   duree[MAX_T];
int   pr[MAX_T][PS]; int su[MAX_T][PS];
int   pr_tl[MAX_T][PS]; int su_tl[MAX_T][PS];
int   pr_decal[MAX_T][PS]; int su_decal[MAX_T][PS];
int   deb_plus_tot[MAX_T];
int   fin_plus_tot[MAX_T];
int   deb_plus_tard[MAX_T];
int   fin_plus_tard[MAX_T];

char  coche[MAX_T];

int   marg_tot[MAX_T];
int   marg_lib[MAX_T];


int   nb_taches;

int   sommets[MAX_T+1];

int J;   // jour J initial
int CJ;  // jour en cours



#endif

