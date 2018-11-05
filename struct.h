// insere les structures

 typedef struct  tch
  {
   AnsiString t_numtache;
   AnsiString t_design;
   int        t_duree;
   TStringList *t_pred;
   TStringList *t_succ;
   TStringList *t_amont;
   AnsiString  t_code;
   AnsiString  t_crit[8];
   AnsiString  t_coutP;
   AnsiString  t_coutN;
   AnsiString  t_ch1;
   AnsiString  t_ch2;
   AnsiString  t_ch3;
  } T_tch;

 typedef   T_tch *P_tch;

 struct prd
  {
   AnsiString  p_numtache;
   int         p_tl;
   int         p_decal;
  } spr;

 struct suc
  {
   AnsiString  s_numtache;
   int         s_tl;
   int         s_decal;
  } ssu;