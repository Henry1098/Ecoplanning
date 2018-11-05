// Type for TSL


typedef struct // stch
{
int t_numtache;
AnsiString t_design;
int t_duree;
//TStringList *t_pred;
//TStringList *t_succ;
//TStringList *t_amont;
AnsiString t_crit[8];
AnsiString t_libcrit[8];
//AnsiString t_codetache;
//float t_cout;
//int t_cal;
//AnsiString t_debsouh;
//AnsiString t_finsouh;
//AnsiString t_ch1;
//AnsiString t_ch2;
//AnsiString t_ch3;

} T_tch;

#ifndef spr
typedef struct prd
{
int p_numtache;
char p_tl[5];
int p_decal[5];
} spr;

#endif

#ifndef ssu
typedef struct suc
{
int s_numtache;
char s_tl[5];
int s_decal;
} ssu;
#endif


