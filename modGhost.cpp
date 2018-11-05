//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modGhost.h"
#include "modJust.h"
#include "modRetrait.h"
#include "modHauteur.h"
#include "modLib.h"
#include "modHelp.h"
#include "stdio.h"
#include "globals.h"
//  #include "isamd.h"
#include <printers.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGhost *Ghost;
//---------------------------------------------------------------------------
__fastcall TGhost::TGhost(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGhost::TitreenLigne1Click(TObject *Sender)
{
 if (TitreenLigne1->Checked == true) TitreenLigne1->Checked = false;
  else TitreenLigne1->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TGhost::LigneSparatriceHaute1Click(TObject *Sender)
{
 int X,Y;
 X=300; Y=400;
 strcpy(m_origin,"LSH");
 PLigne->Popup(X,Y);

}
//---------------------------------------------------------------------------
void __fastcall TGhost::PoliceTexte1Click(TObject *Sender)
{
  TFont *Fonte;
  int Color;
  AnsiString Name;
  int Height;
  char tmp[250];

 //  TFontDialog *TFontDialog1;
  TFontDialog1->Options << fdApplyButton;
  if (TFontDialog1->Execute())
    { Fonte = TFontDialog1->Font;
      Color = Fonte->Color;
      Height = Fonte->Height;
      Name = Fonte->Name;
    }
 // preparer dans m_reports
  sprintf(tmp,"<font><fc>%d</fc><fh>%d</fh><fn>%s</fn></font>",
              Color,Height,Name.c_str());
 strcpy(m_reports,tmp);

}
//---------------------------------------------------------------------------
void __fastcall TGhost::CouleurFond1Click(TObject *Sender)
{
   char tmp[250];
   TColor Color;
   if (CD->Execute())
    Color = CD->Color;
   sprintf(tmp,"<coulf>%d</coulf>",Color);
   strcpy(m_reports,tmp);

}
//---------------------------------------------------------------------------

void __fastcall TGhost::LigneSparatriceBasse1Click(TObject *Sender)
{
int X,Y;
 X=300; Y=400;
 strcpy(m_origin,"LSB");
 PLigne->Popup(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TGhost::JustificationTexte1Click(TObject *Sender)
{
 TJust *Just;
 Just = new TJust(Application);
 Just->ShowModal();
 delete Just;
}
//---------------------------------------------------------------------------

void __fastcall TGhost::FormCreate(TObject *Sender)
{
 int i;
  // ne pas toucher m_params qui contient TOUS les parametres a editer
 for (i=0;i<6;i++)
   { pc=i;
     New_Planning();
   }
 pc=1;
}

//---------------------------------------------------------------------------

void __fastcall TGhost::RetraitHorizontalTitre1Click(TObject *Sender)
{
 TRetrait *Retrait;
 Retrait = new TRetrait(Application);
 Retrait->ShowModal();
 delete Retrait;
}
//---------------------------------------------------------------------------

void __fastcall TGhost::CouleurLigne1Click(TObject *Sender)
{
 TColor Color;
 char tmp[250];
   if (CD->Execute())
    Color = CD->Color;
    sprintf(tmp,"<coulf>%d</coulf>",Color);
   strcpy(m_reports,tmp);
}
//---------------------------------------------------------------------------

void __fastcall TGhost::StyleLigne1Click(TObject *Sender)
{
int X,Y;
 X=300; Y=400;

 PStyle->Popup(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TGhost::EpaisseurLigne1Click(TObject *Sender)
{
 int X,Y;
 X=300; Y=400;
 PEpaiss->Popup(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TGhost::LigneSparatrice1Click(TObject *Sender)
{
 int X,Y;
 X=300; Y=400;
 strcpy(m_origin,"LS");
 PLigne->Popup(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TGhost::TitreenColonne1Click(TObject *Sender)
{
 if  (TitreenColonne1->Checked == true) TitreenColonne1->Checked = false;
 else  TitreenColonne1->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TGhost::HauteurTitreenLigne2Click(TObject *Sender)
{
THauteur *Hauteur;
 Hauteur = new THauteur(Application);
 Hauteur->ShowModal();
 delete Hauteur;
}
//---------------------------------------------------------------------------

void __fastcall TGhost::HauteurTitreenLigne1Click(TObject *Sender)
{
THauteur *Hauteur;
 Hauteur = new THauteur(Application);
 Hauteur->ShowModal();
 delete Hauteur;
}
//---------------------------------------------------------------------------

void __fastcall TGhost::PoliceetCouleurTexte1Click(TObject *Sender)
{
TFont *Fonte;
  int Color;
  AnsiString Name;
  int Height;
  char tmp[250];

 //  TFontDialog *TFontDialog1;
  TFontDialog1->Options << fdApplyButton;
  if (TFontDialog1->Execute())
    { Fonte = TFontDialog1->Font;
      Color = Fonte->Color;
      Height = Fonte->Height;
      Name = Fonte->Name;
    }
 // preparer dans m_reports
 sprintf(tmp,"<font><fc>%d</fc><fh>%d</fh><fn>%s</fn></font>",
              Color,Height,Name.c_str());
 strcpy(m_reports,tmp);

}


//---------------------------------------------------------------------------

void __fastcall TGhost::LigneSparatriceBasse2Click(TObject *Sender)
{
 int X,Y;
 X=300; Y=400;
 strcpy(m_origin,"LSB");
 PLigne->Popup(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TGhost::CouleurFond2Click(TObject *Sender)
{
 TColor Color; char tmp[250];
   if (CD->Execute())
    Color = CD->Color;
  sprintf(tmp,"<coulf>%d</coulf>",Color);
   strcpy(m_reports,tmp);
}
//---------------------------------------------------------------------------

void __fastcall TGhost::Libell2Click(TObject *Sender)
{
 TLibel *Libel;
 Libel = new TLibel(Application);
 Libel->ShowModal();
 delete Libel;

}
//---------------------------------------------------------------------------

void __fastcall TGhost::Libell1Click(TObject *Sender)
{
 TLibel *Libel;
 Libel = new TLibel(Application);
 Libel->ShowModal();
 delete Libel;
}
//---------------------------------------------------------------------------

void __fastcall TGhost::LigneSparatriceHaute2Click(TObject *Sender)
{
 int X,Y;
 X=300; Y=400;
 strcpy(m_origin,"LSH");
 PLigne->Popup(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TGhost::JustificationTexte2Click(TObject *Sender)
{
TJust *Just;
 Just = new TJust(Application);
 Just->ShowModal();
 delete Just;
}
//---------------------------------------------------------------------------

void __fastcall TGhost::RetraitHorizontalTitre2Click(TObject *Sender)
{
TRetrait *Retrait;
 Retrait = new TRetrait(Application);
 Retrait->ShowModal();
 delete Retrait;
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N00mm1Click(TObject *Sender)
{
 strcpy(m_reports,"<ep>0.0</ep>");        
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N010mm1Click(TObject *Sender)
{
strcpy(m_reports,"<ep>0.1</ep>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N020mm1Click(TObject *Sender)
{
strcpy(m_reports,"<ep>0.2</ep>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N050mm1Click(TObject *Sender)
{
strcpy(m_reports,"<ep>0.5</ep>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N080mm1Click(TObject *Sender)
{
strcpy(m_reports,"<ep>0.8</ep>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N100mm1Click(TObject *Sender)
{
strcpy(m_reports,"<ep>1.0</ep>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N150mm1Click(TObject *Sender)
{
strcpy(m_reports,"<ep>1.5</ep>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N200mm1Click(TObject *Sender)
{
strcpy(m_reports,"<ep>2.0</ep>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N250mm1Click(TObject *Sender)
{
strcpy(m_reports,"<ep>2.5</ep>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N5Click(TObject *Sender)
{
 strcpy(m_reports,"<st>psSolid</st>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N6Click(TObject *Sender)
{
strcpy(m_reports,"<st>psDash</st>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N7Click(TObject *Sender)
{
 strcpy(m_reports,"<st>psDot</st>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N8Click(TObject *Sender)
{
strcpy(m_reports,"<st>psDashDot</st>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::N9Click(TObject *Sender)
{
strcpy(m_reports,"<st>psDashDotDot</st>");
}
//---------------------------------------------------------------------------

void __fastcall TGhost::PoliceetCouleurTexte2Click(TObject *Sender)
{

  TFont *Fonte;
  int Color;
  AnsiString Name;
  int Size;
  char tmp[250];
  char bold[50],italic[50];
  TFontStyles  Style;
  // AnsiString Style;

 //  TFontDialog *TFontDialog1;
  TFontDialog1->Options;
  strcpy(m_exchange,"");
  if (TFontDialog1->Execute())
    { Fonte = TFontDialog1->Font;
      Color = Fonte->Color;
      Size = Fonte->Size;
      Name = Fonte->Name;
      Style = Fonte->Style;
      // recherche si bold et italique
      



 // preparer dans m_exchange
  sprintf(tmp,"<font><cl>%d</cl><fh>%d</fh><ft>%s</ft><bo>%s</bo><it>%s</it></font>",
          Color,Size,Name.c_str(),bold,italic);
 strcpy(m_exchange,tmp);
    }
}
//---------------------------------------------------------------------------

int __fastcall TGhost::ExtractValue(char *result, char *buff, char *tag, int posdeb)
{
 char tmp[250]; char *p,*p1,*p2; int pos,l;
 result[0]=0; strcpy(tmp,"<"); strcat(tmp,tag); strcat(tmp,">");
 p = strstr(buff,tmp); l=0;
 if (p)
   { strcpy(tmp,"</"); strcat(tmp,tag); strcat(tmp,">"); p1= strstr(buff,tmp);
    if (p1) { p2=p + strlen(tag)+2; l= p1-p2; strncpy(result,p2,l); result[l]=0; }
   }
 return l;
}

void __fastcall TGhost::New_Planning()
{
  int i;
  int coul;
  TPrinter *p = Printer();

  // de toutes les variables par defaut
 P_PLANNING[pc] = true;
//  if (pc==0) strcpy(P_NOM[pc],"Defaut");

  if (pc==0) strcpy(P_NOM[0],"Ordonnancement des tâches en planning compressé");

   else strcpy(P_NOM[pc],"");



 P_TRI[pc][0]=0;
 P_FILTRE[pc][0]=0;
 P_COLONNES[pc][0]=0;

 RELOADTRI[pc] = true;
 RELOADFILTRE[pc]= true;
 RELOADCOL[pc]=true;


 P_MARGES[pc]='O';
 P_GENRE[pc]='G';  // Gantt
 P_TYPE[pc]='P';   // Previs seul;
 P_GRILLE[pc]='N'; // Grille pour gantt
 P_LBRISE[pc]='N';  // Lignes brisees
 P_CADRE[pc]='N';
 P_ENTETE[pc]='N';
 P_MPENTETE[pc] = 'N';
 P_CALHAUT[pc]='O';
 P_CALBAS[pc]='O';
 P_PIED[pc]='N';
 P_MPPIED[pc]='N';
 P_DETAIL[pc]=1;

 // enveloppe

 coul= clGreen;


 //P_ENV_COUL[pc] = AnsiString(coul);
 //P_ENV_EPAIS[pc] = "1.0";
 //P_ENV_STYLE[pc] = "________";


 P_CDVV[pc]=65;     P_CDV[pc] = "65";

  // OK

 // IMPRIMANTE
 // definir mode Portrait
 P_MODE[pc] = 'P';
 //if (P_MODE[pc] == 'L') Printer()->Orientation = poLandscape;
 //else Printer()->Orientation = poPortrait;
 /*
 Printer()->Orientation = poPortrait;
 P_H[pc] = Printer()->PageHeight;
 P_W[pc] = Printer()->PageWidth;
 */

 p->Orientation = poPortrait;
 P_H[pc] = p->PageHeight;
 P_W[pc] = p->PageWidth;

 NB_DETAIL[pc]=0;
  // Marges
 // faire une conversion de mm vers pixels

 P_MH1[pc]=0.4;P_MH2[pc]=0.4;
 P_MV1[pc]=0.4;P_MV2[pc]=0.4; // coefficient COEF

 P_MARGH1[pc]=P_MARGH2[pc]=50;
 P_MARGV1[pc]=P_MARGV2[pc]=30;

 // P_H et P_W sont calculés au moment de l'impression

 // Cadre
 P_CADRE[pc] = 'O';
 P_ELC[pc] = 0.1;   // epaisseur
 P_CLC[pc] = clBlack;  // couleur Ligne



 // OK

 // En-Tete

 LOGONAME[pc]="";
 LOGOPOS[pc]="G";  // Gauche ou droite

 P_ET_BKG[pc]=(TColor)0xFFFFFF;

 for (i=0;i<9;i++)
  {
   PACTIF[pc][i]='O'; P_ORIENT[pc][i]='N';
   PT[pc][i]="Texte"; PC[pc][i]=clBlack;
   PB[pc][i]=clWhite;
   PF[pc][i]="Arial";PH[pc][i]=24;
   PHH[pc][i]=30;
   PN[pc][i]="Standard"; PX[pc][i]="Gras";
   PJH[pc][i]="Centre"; PJV[pc][i]="Haut";
   PR[pc][i]=0; PTYPE[pc][i]='L';  //  'L' POUR LIGNE 'C' pour colonne
  }

  PT[pc][0]= "Texte Gauche 1"; PT[pc][1]= "Texte Gauche 2"; PT[pc][2]= "Texte Gauche 3";
  PT[pc][3]= "Texte Centre 1"; PT[pc][4]= "Texte Centre 2"; PT[pc][5]= "Texte Centre 3";
  PT[pc][6]= "Texte Droite 1"; PT[pc][7]= "Texte Droite 2"; PT[pc][8]= "Texte Droite 3";

  PJH[pc][0]=PJH[pc][1]=PJH[pc][2]="Gauche";
  PJH[pc][3]=PJH[pc][4]=PJH[pc][5]="Centre";
  PJH[pc][6]=PJH[pc][7]=PJH[pc][8]="Droite";

  PJV[pc][0]=PJV[pc][1]=PJV[pc][2]="Haut";
  PJV[pc][3]=PJV[pc][4]=PJV[pc][5]="Haut";
  PJV[pc][6]=PJV[pc][7]=PJV[pc][8]="Haut";

 // OK

 // Calendrier Haut
  TColor Bg1,Bg2;
  Bg1 =TColor(0x99FFFF);  Bg2 =TColor(0xFFFF99);


  // OK

  P_ECHH[pc]="O"; P_ECHB[pc]="O";
  P_UNIT1[pc]="Semaine";  P_FORMATCAL1[pc]="31 J"; P_FREQ1[pc]="1";
  P_UNIT2[pc]="Mois";  P_FORMATCAL2[pc]="Janvier 08"; P_FREQ2[pc]="1";

  // Ligne 1  ==> Indice 9   Ligne 2 ===> Indice 10
  // Periode   0 = jour  1 = semaine  2 = quinzaine  3 = mois  4 = trimestre  5 = annee
  // FORMAT // 0 // 1 // 2 // 3 // 4 // 5 // 6 // 7



  i=9;
  PACTIF[pc][i]='O'; P_ORIENT[pc][i]='O';
  PT[pc][i]="Cal 1"; PC[pc][i]=clBlack; PB[pc][i]=Bg1;
  PF[pc][i]="Arial";PH[pc][i]=18; PHH[pc][i]=30;
  PN[pc][i]="Standard"; PX[pc][i]="Gras";
  PJH[pc][i]="Centre"; PJV[pc][i]="Haut";
  PR[pc][i]=0; PTYPE[pc][i]='L';
  P_UNIT1[pc]="Semaine";
  P_FREQ1[pc]=1;
  P_FORMATCAL1[pc]="31 J";

  i=10;
  PACTIF[pc][i]='O'; P_ORIENT[pc][i]='O';
  PT[pc][i]="Cal 2"; PC[pc][i]=clBlack; PB[pc][i]=Bg2;
  PF[pc][i]="Arial";PH[pc][i]=18; PHH[pc][i]=30;
  PN[pc][i]="Standard"; PX[pc][i]="Gras";
  PJH[pc][i]="Centre"; PJV[pc][i]="Haut";
  PR[pc][i]=0; PTYPE[pc][i]='L';
  P_UNIT2[pc]="Mois";
  P_FREQ2[pc]=1;
  P_FORMATCAL2[pc]="Janvier 05";

  // OK


  // Colonnes : Par defaut  Numero de taches, Deb Ptrev, Fin Previ, Duree

  for (i=8;i<MAX_COL;i++)
    {
     P_TRICOL[pc][i]=0;
     P_ATTR[pc][i]='C';  // en colonnes, pas horizontal ('L')
     P_ITAL[pc][i]='N'; P_BOLD[pc][i]='B';
     P_HAUT[pc][i]=18;
     P_EPAISSV[pc][i]=0;
     P_FONT[pc][i]="Arial";
     P_CFCOLOR[pc][i]=clBlack;
     P_CBCOLOR[pc][i]=0x99ffff;


    }
  //  Colonnes : col 0


  P_COL[pc]=12; //criteres;  // 1 + 4 colonnes par defaut

  P_TRICOL[pc][8]=1; P_TRICOL[pc][9]=21;
  P_TRICOL[pc][10]=22;P_TRICOL[pc][11]=3;
  P_FIELD[pc][8]="Numéro de Tâche";
  P_FIELD[pc][9]="Début au plus tôt Prévisionnel";
  P_FIELD[pc][10]="Fin au plus tôt Prévisionnel";
  P_FIELD[pc][11]="Durée prévisionnelle";


//  T_TITRE_COL[pc][0]="";
  T_TITRE_COL[pc][8]="N°"; T_TITRE_COL[pc][9]="Debut";
  T_TITRE_COL[pc][10]="Fin"; T_TITRE_COL[pc][11]="Dur";
  P_LARG[pc][0]=0;
  P_LARG[pc][8]=30; P_LARG[pc][9]=50; P_LARG[pc][10]=50;P_LARG[pc][11]=30;
  P_EPAISSV[pc][8]=1;P_EPAISSV[pc][9]=1;P_EPAISSV[pc][10]=1;P_EPAISSV[pc][11]=1;

  for (i=0;i<8;i++) P_FIELD[pc][i]="";



    for (i=0;i<MAX_TCHP; i++)
     {
      T_LLCC[pc][i] = "L";  // valeur L ou C
      T_POL[pc][i] = "Arial"; // police
      T_CTEXT[pc][i] = "0"; // couleur Texte
      T_TITAL[pc][i] = "Standard";
      T_TBOLD[pc][i] = "Standard";
      T_HAUTEUR[pc][i] = "14";
      T_JSH[pc][i] = "Centre";
      T_JSV[pc][i] = "Haut";
      T_CBKG[pc][i] = "";
      T_TLARG[pc][i] = "200";
      T_LS1[pc][i] ="";
      T_LS1EP[pc][i] = "0.1";    // Epaisseur
      T_LS1CL[pc][i] = "0";    // Couleur
      T_LS1ST[pc][i]="0";
      T_LS2[pc][i] = "";      // Oui/Non (pour titre en ligne)
      T_LS2EP[pc][i] = "";
      T_LS2CL[pc][i] = "";
      T_LS1ST[pc][i]="0"; // style

      E_ENV[pc][i] = "X";  // valeur L ou C
      E_POL[pc][i] = "Arial"; // police
      E_CTEXT[pc][i] = "0"; // couleur Texte
      E_TITAL[pc][i] = "Standard";
      E_TBOLD[pc][i] = "Standard";
      E_HAUTEUR[pc][i] = "14";
      E_JSH[pc][i] = "Centre";
      E_JSV[pc][i] = "Haut";
      E_CBKG[pc][i] = "";
      E_TLARG[pc][i] = "200";
      E_COULTRAIT[pc][i] = clGreen;
      E_EPAISS[pc][i] = "1.0";    // Couleur
      E_DESIGN[pc][i] = "X";
      E_STYLE[pc][i] = "_________";
      E_ENCADR[pc][i] = "X";


     }


   for (i=0;i<8;i++)
     {  P_ATTR[pc][i]='Z';
        P_FONT[pc][i]="Arial";
        P_CFCOLOR[pc][i]=clBlack; //StrToInt(PL_CTEXT[pc]);
        P_CBCOLOR[pc][i]=0x99ffff;
        P_HAUT[pc][i]=18;
        P_LARG[pc][i]=20;
        P_BOLD[pc][i]='B';
        P_ITAL[pc][i]='N';
        LSH[pc][i]=1;
        LSB[pc][i]=1;

     }
  P_TRICOL[pc][0]=41;
  P_ATTR[pc][0]='L';
  P_FIELD[pc][0]="+*PHASES";
  P_TRICOL[pc][1]=42;
  P_ATTR[pc][1]='C';
  P_FIELD[pc][1]=""; //+*INTERVENANTS";
  //P_TRICOL[pc][2]=4;  // date de debut prev
  //P_ATTR[pc][2]='C';
  //P_FIELD[pc][2]="+Début au plus tôt Prévisionnel";
  // OK


//////////////////////////////////////////////
 // Taches

  int j;

  P_TRAIT[pc][0]= clRed;
  P_TRAIT[pc][1]= clBlue;
  P_TRAIT[pc][2]= clRed;
  P_TRAIT[pc][3]= clBlue;


  for (i=0;i<MT;i++)
   {

     P_EPTRAIT[pc][i] = 1.5;

     for (j=0;j<4;j++)
       {
        P_INF[pc][i][j] = "Non";
        P_INFO[pc][i][j] = "";
        P_POLT[pc][i][j] = "Arial";
        P_COLTXTF[pc][i][j] = AnsiString(clBlack);
        P_COLTXTB[pc][i][j] = AnsiString(clWhite);
        P_ITALT[pc][i][j] = "Standard";
        P_BOLDT[pc][i][j] = "Gras";
        P_SIZET[pc][i][j] = 28;
       }
     P_INF[pc][i][0] = "Oui";
     P_SIZET[pc][i][0] = 38;
     P_INFO[pc][i][0]="Désignation Tâche|";
     P_COLTXTF[pc][i][1] = AnsiString(clBlue);
     P_COLTXTF[pc][i][2] = AnsiString(clPurple);
     P_COLTXTF[pc][i][3] = AnsiString(clLime);

     P_LIENS[pc][i] = "Oui";
     P_MARGE[pc][i] = "Non";
     P_COLMARGE[pc][i]= AnsiString(clBlack);
     P_STYLEM[pc][i] = ". . . .";
     P_STYLELIEN[pc][i] = ". . . . .";   // definir liste des liens
     P_COL_LIEN[pc][i] = AnsiString(clRed);
     P_EPAIS_LIEN[pc][i] = 0.1;
   }



 // Corps

   for (i=0;i<8;i++)
   {
    P_CYN[pc][i]="Oui";
    P_CCFG[pc][i]=clBlack;
    //P_CCBK[pc][i]=clWhite;
    P_CCST[pc][i]="________";
    P_CCEP[pc][i]=0.1;

   }

 P_CYNJT[pc] = "Oui";
 P_CYNJNT[pc] = "Non";
 P_CYNWENT[pc] = "Non";

  P_CJT[pc]="30";
  P_CJTFLAG[pc]="";
  P_CJNT[pc]="30";
  P_CWENT[pc]="30";
  P_CDH[pc]=50;
  P_CDV[pc]="65";    P_CDVV[pc]=65;


  P_CCJT[pc]= clWhite;
  P_CCJNT[pc]=clWhite;
  P_CCWENT[pc]=clWhite;



 //  Pied de Pages

  P_PD_BKG[pc]=(TColor)0xFFFFFF;

 for (i=25;i<34;i++)
  {
   PACTIF[pc][i]='O'; P_ORIENT[pc][i]='N';
   PT[pc][i]="Texte"; PC[pc][i]=clBlack;
   PB[pc][i]=clWhite;
   PF[pc][i]="Arial";PH[pc][i]=24;
   PHH[pc][i]=30;
   PN[pc][i]="Standard"; PX[pc][i]='Gras';
   PJH[pc][i]="Centre"; PJV[pc][i]="Haut";
   PR[pc][i]=0; PTYPE[pc][i]='L';  //  'L' POUR LIGNE 'C' pour colonne
  }

  PT[pc][25]= "$date"; PT[pc][26]= ""; PT[pc][27]= "";
  PT[pc][28]= ""; PT[pc][29]= ""; PT[pc][30]= "";
  PT[pc][31]= ""; PT[pc][32]= ""; PT[pc][33]= "";

  PJH[pc][25]=PJH[pc][26]=PJH[pc][27]="Centre";
  PJH[pc][28]=PJH[pc][29]=PJH[pc][30]="Centre";
  PJH[pc][31]=PJH[pc][32]=PJH[pc][33]="Centre";

  PJV[pc][25]=PJV[pc][26]=PJV[pc][27]="Haut";
  PJV[pc][28]=PJV[pc][29]=PJV[pc][30]="Haut";
  PJV[pc][31]=PJV[pc][32]=PJV[pc][33]="Haut";

}


void __fastcall TGhost::Global_Col(char *s)
{
int recdata,rc; char Key[100],RetKey[100];
 char tmp[5000];char buffer[5000];

 realisam *col;
 strcpy(tmp,m_directory);
 strcat(tmp,"\\eco_col");
 col=new realisam();
 rc = col->OpenEngine(tmp,248,"ndx","dat");   //256 - 8
 rc = col->SetIndexMode(0,0);

  strcpy(Key,s);
  rc=col->ReadDirectKey(0,Key,RetKey,&recdata);
  if (rc==0)  //  not defined
   {
    strcpy(P_COLONNES[pc],"");
    //if (strlen(s)) Application->MessageBoxA("Description Colonnes non trouvée dans la base de données",m_ecoplan,MB_OK);
    col->CloseEngine();
    return;
   }

 rc=col->ReadRecord(buffer,recdata);
 if (rc)
   { // extract

    ExtractValue(tmp,buffer,"l",0);
    ExtractValue(tmp,buffer,"des",0);
    ExtractValue(tmp,buffer,"champs",0);
    if (strlen(tmp))
        StripC(tmp);
   }
 col->CloseEngine();

}

void __fastcall TGhost::Global_Filtre(char *s)
{
    int count; int rc,recdata;
 char Key[100],RetKey[100];
 char tmp[5000];
 int indx,lg,i;
 char filename[250];
 char current_filter[200];
 realisam *filtres;
 char buffer[5000];

  strcpy(current_filter,s);
 // Read Data and display it


 filtres = new realisam();
 strcpy(filename,m_directory);
 strcat(filename,"\\eco_filtres");
 rc = filtres->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = filtres->SetIndexMode(0,0);

  strcpy(Key,current_filter);
  rc=filtres->ReadDirectKey(0,Key,RetKey,&recdata);
  if (rc==0)  //  not defined
    { strcpy(P_FILTRE[pc],"");
      // if (strlen(s)) Application->MessageBoxA("Filtre non trouvé dans la base de données",m_ecoplan,MB_OK);
      filtres->CloseEngine();
    return;
   }

 rc=filtres->ReadRecord(buffer,recdata);
 if (rc)
   { // extract

    strcpy(m_exchange,"<E><criteres><I>");

    ExtractValue(tmp,buffer,"nom",0);
    ExtractValue(tmp,buffer,"comment",0);

    ExtractValue(tmp,buffer,"tout",0);
    if (strcmp(tmp,"Y")==0) strcat(m_exchange,"T");
    ExtractValue(tmp,buffer,"aucun",0);
    if (strcmp(tmp,"Y")==0) strcat(m_exchange,"N");
    strcat(m_exchange,"</I>");
    ExtractValue(tmp,buffer,"criteres",0);

    //lbDetail->Clear();
    count = Explode('|',tmp);
    if (count > 0)
      {
        for (i=0;i<count;i++)
          { if (strlen(params[i])) Strip(params[i]); }
     }
   }
 strcat(m_exchange,"</criteres>");
 filtres->CloseEngine();
}

void __fastcall TGhost::Strip(char *s)
{
 char tmp[250];

 ExtractValue(tmp,s,"A",0); strcat(m_exchange,"<A>"); strcat(m_exchange,tmp); strcat(m_exchange,"</A>");
 ExtractValue(tmp,s,"C",0); strcat(m_exchange,"<C>"); strcat(m_exchange,tmp); strcat(m_exchange,"</C>");
 ExtractValue(tmp,s,"R",0); strcat(m_exchange,"<R>"); strcat(m_exchange,tmp); strcat(m_exchange,"</R>");
 ExtractValue(tmp,s,"V1",0); strcat(m_exchange,"<V1>"); strcat(m_exchange,tmp); strcat(m_exchange,"</V1>");
 ExtractValue(tmp,s,"V2",0); strcat(m_exchange,"<V2>"); strcat(m_exchange,tmp); strcat(m_exchange,"</V2>");
 strcat(m_exchange,"|");
 }


void __fastcall TGhost::Global_Planning(char *s)
{
int indx; char tmp[5000];
int rc,recdata; char Key[100],RetKey[100];
char filename[MAX_PATH];
char current_planning[100];
char x_ghost_prep[5000];

plannings = new realisam;

//strcpy(filename,DatabaseName);
// strcat(filename,"_plannings");

strcpy(filename,m_directory);  //DatabaseName);
 strcat(filename,"\\eco_plannings");

rc = plannings->OpenEngine(filename,1016,"ndx","dat");   //1024 - 8
rc = plannings->SetIndexMode(0,0);

strcpy(current_planning,s);
strcpy(Key,current_planning);    // Read General Record
 strcat(Key,"-GEN");
 rc=plannings->ReadDirectKey(0,Key,RetKey,&recdata);
  if (rc==0)  //  not defined
   { strcpy(P_NOM[pc],"");
     // if (strcmp(current_planning,"Defaut")==0) return;

      if (strcmp(current_planning,"Ordonnancement des tâches en planning compressé")==0) return;
      if (strcmp(current_planning,"Ordonnancement des tâches en Gantt")==0) return;
     //if (strlen(s))Application->MessageBoxA("Description Planning non trouvée dans la base de données",m_ecoplan,MB_OK);
    plannings->CloseEngine();
    return;
   }

 rc=plannings->ReadRecord(buffer,recdata);
 if (rc)
   { // extract
    New_Planning();
    LoadData(current_planning);
    AUTOMATE[pc]='G';  // Ghost
   }
plannings->CloseEngine();

strcpy(x_ghost_prep,"<pl>");strcat(x_ghost_prep, current_planning); strcat(x_ghost_prep,"</pl>");
strcat(x_ghost_prep,"<com>");
if (strlen(comment)> 1000) comment[1000]=0;
CommentPL[pc] = AnsiString(comment);
strcat(x_ghost_prep,comment);
strcat(x_ghost_prep,"</com>");
strcat(x_ghost_prep,"<org>modGhost:Global_Planning</org>");
m_ghost_prep[pc] = AnsiString(x_ghost_prep);

}

//////////////////////////////////////////////////
// GLOBAL_REPORT
/////////////////////////////////////////////////
void __fastcall TGhost::Global_Report(char *s)
{
int indx; char tmp[5000];
int rc,recdata; char Key[100],RetKey[100];
char filename[MAX_PATH];
char current_planning[100];
char x_ghost_prep[500];


plannings = new realisam;

//strcpy(filename,DatabaseName);
// strcat(filename,"_plannings");

strcpy(filename,m_directory);  //DatabaseName);
strcat(filename,"\\eco_rapports");

rc = plannings->OpenEngine(filename,1016,"ndx","dat");   //1024 - 8
rc = plannings->SetIndexMode(0,0);

strcpy(current_planning,s);
strcpy(Key,current_planning);    // Read General Record
 strcat(Key,"-GEN");
 rc=plannings->ReadDirectKey(0,Key,RetKey,&recdata);
  if (rc==0)  //  not defined
   { strcpy(P_NOM[pc],"");
    //if (strlen(s))Application->MessageBoxA("Description Rapport non trouvée dans la base de données",m_ecoplan,MB_OK);
    plannings->CloseEngine();
    return;
   }

 rc=plannings->ReadRecord(buffer,recdata);
 if (rc)
   { // extract
    New_Planning();
    LoadRapport(current_planning);
    AUTOMATE[pc]='G';
   }
plannings->CloseEngine();

strcpy(x_ghost_prep,"<pl>");strcat(x_ghost_prep, current_planning); strcat(x_ghost_prep,"</pl>");
strcat(x_ghost_prep,"<com>");
if (strlen(comment)>= 1000) comment[1000]=0;
strcat(x_ghost_prep,comment);
strcat(x_ghost_prep,"</com>");
strcat(x_ghost_prep,"<org>modGhost:Global_Report</org>");
m_ghost_prep[pc] = AnsiString(x_ghost_prep);

}

void __fastcall TGhost::LoadData(char *cp)
{
  int rc,recdata; char Key[100],RetKey[100];

  // Donnees generales
    strcpy(Key,cp); strcat(Key,"-GEN");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_gen,recdata);
        ExtractValue(str,buf_gen,"GEN",0);
        LoadGen();
      }

    strcpy(Key,cp); strcat(Key,"-MRG");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_marges,recdata);
        ExtractValue(str,buf_marges,"MRG",0);
        LoadMarges();
      }

    strcpy(Key,cp); strcat(Key,"-CDR");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_cadre,recdata);
        ExtractValue(str,buf_cadre,"CDR",0);
        LoadCadre();
      }

   strcpy(Key,cp); strcat(Key,"-ETT");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_entete,recdata);
        ExtractValue(str,buf_entete,"ETT",0);
        LoadEntete();
      }


 //  Calendrier
   strcpy(Key,cp); strcat(Key,"-CAL");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_cal,recdata);
        ExtractValue(str,buf_cal,"CAL",0);
        LoadCalendrier();
      }
 // Taches
   strcpy(Key,cp); strcat(Key,"-TCH");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_taches,recdata);
        ExtractValue(str,buf_taches,"TCH",0);
        LoadTaches();
      }
 // Corps Graphe
   strcpy(Key,cp); strcat(Key,"-COR");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_corps,recdata);
        ExtractValue(str,buf_corps,"COR",0);
        LoadCorps();
      }


 // Pied de Page
    strcpy(Key,cp); strcat(Key,"-PIE");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_pied,recdata);
        ExtractValue(str,buf_pied,"PIE",0);
        LoadPied();
      }

    strcpy(Key,cp); strcat(Key,"-BRI");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_pied,recdata);
        ExtractValue(str,buf_pied,"BRI",0);
        LoadBrise();
      }

 // Bandes  Lignes

  /*
   strcpy(Key,cp); strcat(Key,"-TLIG");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_tligne,recdata);
        ExtractValue(str,buf_tligne,"TLIG",0);
        LoadTLigne();
      }

 // Bandes  Colonnes

   strcpy(Key,cp); strcat(Key,"-TCOL");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_tcol,recdata);
        ExtractValue(str,buf_tcol,"TCOL",0);
        LoadTCol();
      }
   */
}





void __fastcall TGhost::LoadRapport(char *cp)
{
  int rc,recdata; char Key[100],RetKey[100];

  // Donnees generales
    strcpy(Key,cp); strcat(Key,"-GEN");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_gen,recdata);
        ExtractValue(str,buf_gen,"GEN",0);
        LoadGen();
      }

    strcpy(Key,cp); strcat(Key,"-MRG");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_marges,recdata);
        ExtractValue(str,buf_marges,"MRG",0);
        LoadMarges();
      }


    strcpy(Key,cp); strcat(Key,"-CDR");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_cadre,recdata);
        ExtractValue(str,buf_cadre,"CDR",0);
        LoadCadre();
      }

   strcpy(Key,cp); strcat(Key,"-ETT");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_entete,recdata);
        ExtractValue(str,buf_entete,"ETT",0);
        LoadEntete();
      }

  /*
 //  Calendrier
   strcpy(Key,cp); strcat(Key,"-CAL");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_cal,recdata);
        ExtractValue(str,buf_cal,"CAL",0);
        LoadCalendrier();
      }
 // Taches
   strcpy(Key,cp); strcat(Key,"-TCH");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_taches,recdata);
        ExtractValue(str,buf_taches,"TCH",0);
        LoadTaches();
      }
 // Corps Graphe

 */

     strcpy(Key,cp); strcat(Key,"-COR");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_corps,recdata);
        ExtractValue(str,buf_corps,"COR",0);
        LoadCorps();
      }

 // Pied de Page
    strcpy(Key,cp); strcat(Key,"-PIE");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_pied,recdata);
        ExtractValue(str,buf_pied,"PIE",0);
        LoadPied();
      }


 // Bandes  Lignes

  /*
   strcpy(Key,cp); strcat(Key,"-TLIG");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_tligne,recdata);
        ExtractValue(str,buf_tligne,"TLIG",0);
        LoadTLigne();
      }

 // Bandes  Colonnes

   strcpy(Key,cp); strcat(Key,"-TCOL");
    rc = plannings->ReadDirectKey(0,Key,RetKey,&recdata);
    if (rc)
      { rc =plannings->ReadRecord(buf_tcol,recdata);
        ExtractValue(str,buf_tcol,"TCOL",0);
        LoadTCol();
      }
  */
}


void __fastcall TGhost::LoadGen()
{
 char tmp[2500];

 ExtractValue(tmp,str,"nom",0);
 strcpy(P_NOM[pc],tmp);
 //eMemoire->Text=AnsiString(tmp);
 ExtractValue(comment,str,"com",0);
 //mPlanning->SetTextBuf(tmp);
 ExtractValue(tmp,str,"fut",0);
 strcpy(P_FILTRE[pc],tmp);
 Global_Filtre(P_FILTRE[pc]);
 //Affect_Filtre(P_FILTRE[pc]);
 ExtractValue(tmp,str,"tut",0);
 strcpy(P_TRI[pc],tmp);
 Global_Tri(P_TRI[pc]);
 //Affect_Tri(P_TRI[pc]);
 ExtractValue(tmp,str,"cut",0);
 strcpy(P_COLONNES[pc],tmp);
 Global_Col(P_COLONNES[pc]);
 //Affect_Colonnes(P_COLONNES[pc]);

 strcpy(m_assign,"<tri>"); strcat(m_assign,P_TRI[pc]);  strcat(m_assign,"</tri>");
 strcat(m_assign,"<col>"); strcat(m_assign,P_COLONNES[pc]);strcat(m_assign,"</col>");
 strcat(m_assign,"<fil>"); strcat(m_assign,P_FILTRE[pc]);strcat(m_assign,"</fil>");
 strcat(m_assign,"<org>ModGhost:LoadGen</org>");
 ExtractValue(tmp,str,"gen",0);
 if (strcmp(tmp,"C")==0)
    { P_GENRE[pc]='C';
      //rb11->Checked=true;rb12->Checked=false; cb2->Checked=false;
      }
     else
     { P_GENRE[pc]='G';
       //rb12->Checked=true; rb11->Checked=false;
      }

 /*
 ExtractValue(tmp,str,"envc",0);
 P_ENV_COUL[pc]=AnsiString(tmp);

 ExtractValue(tmp,str,"enve",0);
 P_ENV_EPAIS[pc]=AnsiString(tmp);

 ExtractValue(tmp,str,"envs",0);
 P_ENV_STYLE[pc]=AnsiString(tmp);
*/

 ExtractValue(tmp,str,"ggt",0);
 if (strcmp(tmp,"O")==0)
     { P_GRILLE[pc]='O';
       //cb2->Checked=true;
     }
     else
     { P_GRILLE[pc]='N';
       //cb2->Checked=false;
     }
 if (pc>3) P_GRILLE[pc]='O';
 ExtractValue(tmp,str,"tpl",0);
 if (strcmp(tmp,"P")==0)
     { P_TYPE[pc]='P';
       //rb1->Checked=true; rb2->Checked=false;
     }
     else
     { P_TYPE[pc]='R';
       //rb2->Checked = true; rb1->Checked=false;
     }
 ExtractValue(tmp,str,"lbr",0);
 if (strcmp(tmp,"O")==0)
    { P_LBRISE[pc]='O';
      //cb1->Checked = true;
    }
  else
    { P_LBRISE[pc]='N';
     //rb1->Checked = false;
    }
 ExtractValue(tmp,str,"mod",0);
 if (strcmp(tmp,"P")==0)
  { P_MODE[pc]='P';
    //rbPortrait->Checked=true; rbPaysage->Checked=false;
  }
     else
   { P_MODE[pc]='L';
     //rbPaysage->Checked=true; rbPortrait->Checked=false;
   }
 ExtractValue(tmp,str,"mrg",0);
 if (strcmp(tmp,"O")==0)
    { P_MARGES[pc]='O';
      //cb10->Checked=true;
    }
  else
    { P_MARGES[pc]='N';
      //cb10->Checked=false;
    }

 ExtractValue(tmp,str,"cad",0);
 if (strcmp(tmp,"O")==0)
    { P_CADRE[pc]='O';
      //cb3->Checked=true;
    }
  else
    { P_CADRE[pc]='N';
      //cb3->Checked=false;
    }

 ExtractValue(tmp,str,"ett",0);
 if (strcmp(tmp,"O")==0)
    { P_ENTETE[pc]='O';
     //cb4->Checked=true;
    }
   else
     { P_ENTETE[pc]='N';
       //cb4->Checked=false;
    }

 ExtractValue(tmp,str,"cah",0);
 if (strcmp(tmp,"O")==0)
    { P_CALHAUT[pc]='O';
      //cb5->Checked=true;
    }
  else { P_CALHAUT[pc]='N';
         //cb5->Checked=false;
       }

 ExtractValue(tmp,str,"cab",0);
 if (strcmp(tmp,"O")==0)
   { P_CALBAS[pc]='O';
     //cb6->Checked=true;
   }
  else
    { P_CALBAS[pc]='N';
     //cb6->Checked=false;
    }

 ExtractValue(tmp,str,"pie",0);
 if (strcmp(tmp,"O")==0)
    { P_PIED[pc]='O';  }
   else
    { P_PIED[pc]='N'; }

 ExtractValue(tmp,str,"mpe",0);
 if (strcmp(tmp,"O")==0)
    { P_MPENTETE[pc]='O'; }
   else
    { P_MPENTETE[pc]='N'; }


 ExtractValue(tmp,str,"mpp",0);
 if (strcmp(tmp,"O")==0)
    { P_MPPIED[pc]='O';
      //cb7->Checked=true;
    }
   else
    { P_MPPIED[pc]='N';
      //cb7->Checked=false;
    }
}

void __fastcall TGhost::LoadMarges()
{
 char tmp[200];

 ExtractValue(tmp,str,"mrg",0);
 if (strcmp(tmp,"O")==0) P_MARGES[pc]='O';
     else P_MARGES[pc]='N';
 ExtractValue(tmp,str,"mht",0); P_MV1[pc]= AnsiString(tmp);
 ExtractValue(tmp,str,"mba",0); P_MV2[pc]= AnsiString(tmp);
 ExtractValue(tmp,str,"mga",0); P_MH1[pc]= AnsiString(tmp);
 ExtractValue(tmp,str,"mdr",0); P_MH2[pc]= AnsiString(tmp);
}

void __fastcall TGhost::LoadCadre()
{

 char tmp[200];float ff;
 int  val;
 ExtractValue(tmp,str,"cad",0);
 if (strcmp(tmp,"O")==0) P_CADRE[pc]='O';
     else P_CADRE[pc]='N';

 ExtractValue(tmp,str,"cep",0);
 P_ELC[pc]=AnsiString(tmp);
 ff =AnsiToFloat(P_ELC[pc]); ff=ff*COEFMM;
 P_ELCF[pc] = (int) ff;

 ExtractValue(tmp,str,"ccl",0); val=atoi(tmp);
 P_CLC[pc]=(TColor)val;

}


float __fastcall TGhost::AnsiToFloat(AnsiString str)
{
 char tmp[200]; char *p;
 float f;
 strcpy(tmp,str.c_str());

 p=strchr(tmp,',');
 if (p) *p='.';
 f=atof(tmp);
 return f;

}

void __fastcall TGhost::LoadMem(char *s,int indx)
{
 char tmp[250];
 int c;
 ExtractValue(tmp,s,"txt",0);
 PT[pc][indx]=AnsiString(tmp);

 ExtractValue(tmp,s,"act",0);   // Actif O/N
 PACTIF[pc][indx]=AnsiString(tmp);

 ExtractValue(tmp,s,"pol",0);
 PF[pc][indx]=AnsiString(tmp);
 ExtractValue(tmp,s,"fgd",0); c=atoi(tmp);
 PC[pc][indx]=TColor(c);
 ExtractValue(tmp,s,"bkg",0); c=atoi(tmp);
 PB[pc][indx]= TColor(c);
 ExtractValue(tmp,s,"siz",0); c=atoi(tmp);
 PH[pc][indx]= c;;
 ExtractValue(tmp,s,"hgt",0); c=atoi(tmp);
 PHH[pc][indx]=c;
 ExtractValue(tmp,s,"ita",0);
 PN[pc][indx] = AnsiString(tmp);
 //if (strcmp(tmp,"I")==0) PN[pc][indx]="Italique"; else PN[pc][indx]="Standard";
 ExtractValue(tmp,s,"bld",0);
 PX[pc][indx] = AnsiString(tmp);
 //if (strcmp(tmp,"B")==0) PX[pc][indx]="Gras"; else PX[pc][indx]="Standard";

 ExtractValue(tmp,s,"jsh",0);
 PJH[pc][indx] = AnsiString(tmp);
 //if (strcmp(tmp,"G")==0) PJH[pc][indx]="Gauche";
 //  else  if (strcmp(tmp,"C")==0) PJH[pc][indx]='C';
 //  else PJH[pc][indx]='D';
 ExtractValue(tmp,s,"jsv",0);
 PJV[pc][indx] = AnsiString(tmp);
 //if (strcmp(tmp,"H")==0) PJV[pc][indx]='G';
 //  else  if (strcmp(tmp,"C")==0) PJV[pc][indx]='C';
 //  else PJV[pc][indx]='B';

 PTYPE[pc][indx]='N';
 // PACTIF[pc][indx]='O';
 P_ORIENT[pc][indx]='L';

}


void __fastcall TGhost::LoadEntete()
{
 char tmp[2000];

 ExtractValue(tmp,str,"ett",0);
 if (strcmp(tmp,"O")==0) P_ENTETE[pc]='O';
     else P_ENTETE[pc]='N';

 ExtractValue(tmp,str,"logn",0);
 LOGONAME[pc] = AnsiString(tmp);

 ExtractValue(tmp,str,"logp",0);
 LOGOPOS[pc] = AnsiString(tmp);

 ExtractValue(tmp,str,"eg1",0);
 LoadMem(tmp,0);
 ExtractValue(tmp,str,"eg2",0);
 LoadMem(tmp,1);
 ExtractValue(tmp,str,"eg3",0);
 LoadMem(tmp,2);
 ExtractValue(tmp,str,"ec1",0);
 LoadMem(tmp,3);
 ExtractValue(tmp,str,"ec2",0);
 LoadMem(tmp,4);
 ExtractValue(tmp,str,"ec3",0);
 LoadMem(tmp,5);
 ExtractValue(tmp,str,"ed1",0);
 LoadMem(tmp,6);
 ExtractValue(tmp,str,"ed2",0);
 LoadMem(tmp,7);
 ExtractValue(tmp,str,"ed3",0);
 LoadMem(tmp,8);
}

void __fastcall TGhost::LoadCalendrier()
{
 char s[2000],tmp[250];  int val;

 ExtractValue(tmp,str,"cah",0);
 if (strcmp(tmp,"O")==0) P_CALHAUT[pc]='O'; else P_CALHAUT[pc]='N';
 ExtractValue(tmp,str,"cab",0);
 if (strcmp(tmp,"O")==0) P_CALBAS[pc]='O'; else P_CALBAS[pc]='N';

 ExtractValue(s,str,"cl1",0);
 ExtractValue(tmp,s,"unt",0); P_UNIT1[pc]=AnsiString(tmp);
 ExtractValue(tmp,s,"fmt",0); P_FORMATCAL1[pc]=AnsiString(tmp);
 ExtractValue(tmp,s,"frq",0); P_FREQ1[pc]=AnsiString(tmp);
 LoadMem(s,9);


 ExtractValue(s,str,"cl2",0);
 ExtractValue(tmp,s,"unt",0); P_UNIT2[pc]=AnsiString(tmp);
 ExtractValue(tmp,s,"fmt",0); P_FORMATCAL2[pc]=AnsiString(tmp);
 ExtractValue(tmp,s,"frq",0); P_FREQ2[pc]=AnsiString(tmp);
 LoadMem(s,10);
}

void __fastcall TGhost::LoadTaches()
{
 char tmp[3000];
 int i;
 ExtractValue(tmp,str,"tc0",0);
 Ftaches(tmp,0);
 ExtractValue(tmp,str,"tc1",0);
 Ftaches(tmp,1);
 ExtractValue(tmp,str,"tc2",0);
 Ftaches(tmp,2);
 ExtractValue(tmp,str,"tc3",0);
 Ftaches(tmp,3);
}

void __fastcall TGhost::Ftaches(char *buf,int indice)
{
char tmp[5000]; int i; char tag[50];
char val[5000];


ExtractValue(val,buf,"tt",0); P_TRAIT[pc][indice]=AnsiString(val);
ExtractValue(val,buf,"tet",0);  P_EPTRAIT[pc][indice]=AnsiString(val);
ExtractValue(val,buf,"tm",0);  P_MARGE[pc][indice]=AnsiString(val);
ExtractValue(val,buf,"ts",0);  P_STYLEM[pc][indice]=AnsiString(val);
ExtractValue(val,buf,"tcm",0);  P_COLMARGE[pc][indice]=AnsiString(val);
ExtractValue(val,buf,"tl",0);  P_LIENS[pc][indice] = AnsiString(val);
ExtractValue(val,buf,"tsl",0);  P_STYLELIEN[pc][indice]= AnsiString(val);
ExtractValue(val,buf,"tcl",0);  P_COL_LIEN[pc][indice]=AnsiString(val);
ExtractValue(val,buf,"tel",0);  P_EPAIS_LIEN[pc][indice]=AnsiString(val);


 for (i=0;i<4;i++)
   {
    sprintf(tag,"ti%d",i);
    ExtractValue(tmp,buf,tag,0);
    ExtractValue(val,tmp,"inf",0);P_INF[pc][indice][i]=AnsiString(val);
    ExtractValue(val,tmp,"info",0);P_INFO[pc][indice][i]=AnsiString(val);
    ExtractValue(val,tmp,"pol",0);P_POLT[pc][indice][i]=AnsiString(val);
    ExtractValue(val,tmp,"ctxt",0);P_COLTXTF[pc][indice][i]=AnsiString(val);
    ExtractValue(val,tmp,"ital",0);P_ITALT[pc][indice][i]=AnsiString(val);
    ExtractValue(val,tmp,"bold",0);P_BOLDT[pc][indice][i]=AnsiString(val);
    ExtractValue(val,tmp,"siz",0);P_SIZET[pc][indice][i]=AnsiString(val);
    ExtractValue(val,tmp,"cbkg",0);P_COLTXTB[pc][indice][i]=AnsiString(val);
   }

}

void __fastcall TGhost::LoadCorps()
{
 char tmp[2000]; int i;
 char elm[2000];
 char tag[20];

 for (i=0;i<8;i++)
   {
    sprintf(tag,"c%d",i);
    ExtractValue(tmp,str,tag,0);

    ExtractValue(elm,tmp,"cyn",0);P_CYN[pc][i]=AnsiString(elm);
    ExtractValue(elm,tmp,"ccfg",0);P_CCFG[pc][i]=AnsiString(elm);
    //ExtractValue(elm,tmp,"ccbk",0);P_CCBK[pc][i]=AnsiString(elm);
    ExtractValue(elm,tmp,"ccst",0);P_CCST[pc][i]=AnsiString(elm);
    ExtractValue(elm,tmp,"ccep",0);P_CCEP[pc][i]=AnsiString(elm);
   }

  ExtractValue(elm,str,"cynjt",0);P_CYNJT[pc]=AnsiString(elm);
  ExtractValue(elm,str,"cynjnt",0);P_CYNJNT[pc]=AnsiString(elm);
  ExtractValue(elm,str,"cynwent",0);P_CYNWENT[pc]=AnsiString(elm);


  ExtractValue(elm,str,"cjt",0);P_CJT[pc]=AnsiString(elm);
  ExtractValue(elm,str,"cjtfl",0);P_CJTFLAG[pc]=AnsiString(elm);
  ExtractValue(elm,str,"cjnt",0);P_CJNT[pc]=AnsiString(elm);
  ExtractValue(elm,str,"cwent",0);P_CWENT[pc]=AnsiString(elm);
  ExtractValue(elm,str,"cdh",0);P_CDH[pc]=AnsiString(elm);
  ExtractValue(elm,str,"cdv",0);P_CDV[pc]=AnsiString(elm);  P_CDVV[pc]=atoi(elm);

  

  ExtractValue(elm,str,"ccjt",0);P_CCJT[pc]=AnsiString(elm);
  ExtractValue(elm,str,"ccjnt",0);P_CCJNT[pc]=AnsiString(elm);
  ExtractValue(elm,str,"ccwent",0);P_CCWENT[pc]=AnsiString(elm);

}

void __fastcall TGhost::LoadPied()
{
char tmp[2000];

 ExtractValue(tmp,str,"pg1",0);
 LoadMem(tmp,25);
 ExtractValue(tmp,str,"pg2",0);
 LoadMem(tmp,26);
 ExtractValue(tmp,str,"pg3",0);
 LoadMem(tmp,27);
 ExtractValue(tmp,str,"pc1",0);
 LoadMem(tmp,28);
 ExtractValue(tmp,str,"pc2",0);
 LoadMem(tmp,29);
 ExtractValue(tmp,str,"pc3",0);
 LoadMem(tmp,30);
 ExtractValue(tmp,str,"pd1",0);
 LoadMem(tmp,31);
 ExtractValue(tmp,str,"pd2",0);
 LoadMem(tmp,32);
 ExtractValue(tmp,str,"pd3",0);
 LoadMem(tmp,33);

}

void __fastcall TGhost::LoadBrise()
{
char tmp[2000];

 

}

void __fastcall TGhost::LoadTLigne()
{

  /*
   char tmp[250];
       ExtractValue(tmp,str,"pol",0); PL_POL[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ct",0);  PL_CTEXT[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"it",0);  PL_ITAL[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"bd",0);  PL_BOLD[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ht",0);  PL_HAUTEUR[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"jh",0);  PL_JSH[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"jv",0);  PL_JSV[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"cb",0);  PL_CBKG[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"lg",0);  PL_LARG[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ep1",0); PL_LS1EP[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"cl1",0); PL_LS1CL[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ls2",0); PL_LS2[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ep2",0); PL_LS2EP[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"cl2",0); PL_LS2CL[pc]=AnsiString(tmp);
  */
}

void __fastcall TGhost::LoadTCol()
{
  /*
  char tmp[250];
       ExtractValue(tmp,str,"pol",0); PC_POL[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ct",0);  PC_CTEXT[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"it",0);  PC_ITAL[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"bd",0);  PC_BOLD[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ht",0);  PC_HAUTEUR[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"jh",0);  PC_JSH[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"jv",0);  PC_JSV[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"cb",0);  PC_CBKG[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"lg",0);  PC_LARG[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ep1",0); PC_LS1EP[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"cl1",0); PC_LS1CL[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ls2",0); PC_LS2[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"ep2",0); PC_LS2EP[pc]=AnsiString(tmp);
       ExtractValue(tmp,str,"cl2",0); PC_LS2CL[pc]=AnsiString(tmp);
   */
}

void __fastcall TGhost::Global_Tri(char *s)
{
  int indx; char tmp[8000],buffer[8000];
 int rc,recdata; char Key[100],RetKey[100];
 char filename[250];

 realisam *tri;

 strcpy(filename,m_directory); strcat(filename,"\\eco_tri");
 tri=new realisam();
 rc = tri->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = tri->SetIndexMode(0,0);

  strcpy(Key,s);
  rc=tri->ReadDirectKey(0,Key,RetKey,&recdata);
  if (rc==0)  //  not defined
   { strcpy(P_TRI[pc],"");
    // if (strlen(s)) Application->MessageBoxA("Tri non trouvé dans la base de données",m_ecoplan,MB_OK);
    tri->CloseEngine();
    return;
   }
 rc=tri->ReadRecord(buffer,recdata);
 if (rc)
   { // extract
    ExtractValue(tmp,buffer,"detail",0);
    if (strcmp(tmp,"O")==0) P_DETAIL[pc]=1; else P_DETAIL[pc]=0;

    ExtractValue(tmp,buffer,"champs",0);
    if (strlen(tmp)) StripT(tmp);
    ExtractValue(tmp,buffer,"envelop",0);
    if (strlen(tmp)) StripEnvelop(tmp);
   }
 tri->CloseEngine();
}

void __fastcall TGhost::StripT(char *s)
{
 char tmp[5000];
 int count,i;
 for (i=0;i<8;i++) { P_TRICOL[pc][i]=0; P_ATTR[pc][i]='Z';  }
 //ExtractValue(tmp,s,"champs",0);
 count = Explode('|',s);
 if (count>8) count=8;
 NB_ITEMS_TRI[pc]=count; //NB_ITEMSTRI;
 if (count)
   {
    for (i=0; i<count; i++)
      {
       P_TRICOL[pc][i]=0;

       ExtractValue(tmp,params[i],"N0",0);
       if (strcmp(tmp,"X")==0) P_NIV0[pc][i]=1; else P_NIV0[pc][i]=0;

       ExtractValue(tmp,params[i],"N1",0);
       if (strcmp(tmp,"X")==0) P_NIV1[pc][i]=1; else P_NIV1[pc][i]=0;
       ExtractValue(tmp,params[i],"N2",0);
       if (strcmp(tmp,"X")==0) P_NIV2[pc][i]=1; else P_NIV2[pc][i]=0;
       ExtractValue(tmp,params[i],"N3",0);
       if (strcmp(tmp,"X")==0) P_NIV3[pc][i]=1; else P_NIV3[pc][i]=0;
       ExtractValue(tmp,params[i],"DT",0);
       if (strcmp(tmp,"X")==0) P_ENV[pc][i]=1; else P_ENV[pc][i]=0;

       ExtractValue(tmp,params[i],"TR",0);

       ExtractValue(tmp,params[i],"BL",0);

       ExtractValue(tmp,params[i],"lc",0);
        if (strcmp(tmp,"L")==0) P_ATTR[pc][i]='L';
        if (strcmp(tmp,"C")==0) P_ATTR[pc][i]='C';
        if (strcmp(tmp,"B")==0) P_ATTR[pc][i]='B';
        if (strcmp(tmp,"T")==0) P_ATTR[pc][i]='T';
        // Colonnes Detail
       ExtractValue(tmp,params[i],"CH",0);
       P_FIELD[pc][i] = AnsiString(tmp);


       ExtractValue(tmp,params[i],"pol",0);   // ft
       P_FONT[pc][i] = AnsiString(tmp);
       T_POL[pc][i]= P_FONT[pc][i];
       ExtractValue(tmp,params[i],"ct",0);
       P_CFCOLOR[pc][i] = atoi(tmp);
       T_CTEXT[pc][i]= P_CFCOLOR[pc][i];
       ExtractValue(tmp,params[i],"it",0);
       if (strcmp(tmp,"Standard")==0) P_ITAL[pc][i] = "Standard"; else P_ITAL[pc][i]="Italique";
       T_TITAL[pc][i]=P_ITAL[pc][i];
       ExtractValue(tmp,params[i],"bd",0);
       if (strcmp(tmp,"Standard")==0) P_BOLD[pc][i] = "Standard"; else P_BOLD[pc][i]="Gras";
       T_TBOLD[pc][i]=P_BOLD[pc][i];
       ExtractValue(tmp,params[i],"ht",0);
       P_HAUT[pc][i] = atoi(tmp);
       T_HAUTEUR[pc][i]=AnsiString(P_HAUT[pc][i]);
       ExtractValue(tmp,params[i],"cb",0);
       P_CBCOLOR[pc][i] = atoi(tmp);
       T_CBKG[pc][i]=AnsiString(P_CBCOLOR[pc][i]);
       ExtractValue(tmp,params[i],"jh",0);
       P_JH[pc][i] = AnsiString(tmp);
       T_JSH[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"jv",0);
       P_JV[pc][i] = AnsiString(tmp);
       T_JSV[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"lg",0);      // largeur
       P_LARG[pc][i] = atoi(tmp);
       T_TLARG[pc][i] = AnsiString(tmp);

       ExtractValue(tmp,params[i],"ls1",0);
       T_LS1[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"ep1",0);
       T_LS1EP[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"ep1",0);
       T_LS1EP[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"cl1",0);
       T_LS1CL[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"st1",0);
       T_LS1ST[pc][i] = AnsiString(tmp);

       ExtractValue(tmp,params[i],"ls2",0);
       T_LS2[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"ep2",0);
       T_LS2EP[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"cl2",0);
       T_LS2CL[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"st2",0);
       T_LS2ST[pc][i] = AnsiString(tmp);


      }
   }
}


void __fastcall TGhost::StripEnvelop(char *s)
{
 char tmp[5000];
 int count,i;
 count = Explode('|',s);
 if (count>8) count=8;
 //NB_ITEMSTRI;
 if (count)
   {
    for (i=0; i<count; i++)
      {
       ExtractValue(tmp,params[i],"lc",0);
       if (strcmp(tmp,"X")==0) { P_ENV[pc][i]=1; E_ENV[pc][i]="X"; }
       else { P_ENV[pc][i]=0; E_ENV[pc][i] = " "; }


       ExtractValue(tmp,params[i],"pol",0);   // ft
       E_POL[pc][i]= P_FONT[pc][i];
       ExtractValue(tmp,params[i],"ct",0);
       E_CTEXT[pc][i]= P_CFCOLOR[pc][i];
       ExtractValue(tmp,params[i],"it",0);
       E_TITAL[pc][i]=AnsiString(tmp);
       ExtractValue(tmp,params[i],"bd",0);
       E_TBOLD[pc][i]=AnsiString(tmp);
       ExtractValue(tmp,params[i],"ht",0);
       E_HAUTEUR[pc][i]=AnsiString(tmp);
       ExtractValue(tmp,params[i],"cb",0);
       E_CBKG[pc][i]=AnsiString(tmp);
       ExtractValue(tmp,params[i],"jh",0);
       E_JSH[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"jv",0);
       E_JSV[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"lg",0);      // largeur
       E_TLARG[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"coult",0);
       E_COULTRAIT[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"style",0);
       E_STYLE[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"epaiss",0);
       E_EPAISS[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"design",0);
       E_DESIGN[pc][i] = AnsiString(tmp);
       ExtractValue(tmp,params[i],"encadr",0);
       E_ENCADR[pc][i] = AnsiString(tmp);


      }
   }
}



void __fastcall TGhost::Save_GlobColonnes(char *s)
{
 char name[100]; char temp[50];
 char Key[100],RetKey[100];
 int rc,recdata,i,j,nbitems;
 char tmp[5000];
 char buffer[8000];
 realisam *col;

 strcpy(Key,s);
 if (strlen(Key) == 0) return ;

 // preparer buffer
 strcpy(buffer,"<l>"); strcat(buffer,Key); strcat(buffer,"</l>");
 strcat(buffer,"<des>");
 strcat(buffer,"Désignation");  //mCol->Lines->GetText());
 strcat(buffer,"</des>");
 strcat(buffer,"<champs>");
 nbitems = P_COL[pc]; //  asFCC->RowCount-1;  // lbDetail->Items->Count;
 for (j=8;j<nbitems;j++)
   {
    strcat(buffer,"<ch>"); strcat(buffer,P_FIELD[pc][j].c_str()); strcat(buffer,"</ch>");
    strcat(buffer,"<ft>"); strcat(buffer,P_FONT[pc][j].c_str()); strcat(buffer,"</ft>");
    sprintf(temp,"%d",P_CFCOLOR[pc][j]);
    strcat(buffer,"<cl>"); strcat(buffer,temp); strcat(buffer,"</cl>");

    strcat(buffer,"<it>"); strcat(buffer,P_ITAL[pc][j].c_str()); strcat(buffer,"</it>");
    strcat(buffer,"<gr>"); strcat(buffer,P_BOLD[pc][j].c_str()); strcat(buffer,"</gr>");

    //if (P_ITAL[pc][j] == 'I') strcpy(temp,"Italique"); else strcpy(temp,"Standard");
    //strcat(buffer,"<it>"); strcat(buffer,temp); strcat(buffer,"</it>");
    //if (P_BOLD[pc][j] == 'B') strcpy(temp,"Gras"); else strcpy(temp,"Standard");
    //strcat(buffer,"<gr>"); strcat(buffer,temp); strcat(buffer,"</gr>");
    sprintf(temp,"%d",P_HAUT[pc][j]);
    strcat(buffer,"<ta>"); strcat(buffer,temp); strcat(buffer,"</ta>");
    sprintf(temp,"%d",P_CBCOLOR[pc][j]);
    strcat(buffer,"<cf>"); strcat(buffer,temp); strcat(buffer,"</cf>");
    //if (P_JC[pc][j]=='G') strcpy (temp,"Gauche");
    //if (P_JC[pc][j]=='C') strcpy (temp,"Centre");
    //if (P_JC[pc][j]=='D') strcpy (temp,"Droite");
    strcat(buffer,"<jh>"); strcat(buffer,P_JH[pc][j].c_str()); strcat(buffer,"</jh>");
    //if (P_JV[pc][j]=='H') strcpy (temp,"Haut");
    //if (P_JV[pc][j]=='C') strcpy (temp,"Centre");
    //if (P_JV[pc][j]=='B') strcpy (temp,"Bas");
    strcat(buffer,"<jv>"); strcat(buffer,P_JV[pc][j].c_str()); strcat(buffer,"</jv>");
    sprintf(temp,"%d",P_LARG[pc][j]);
    strcat(buffer,"<ht>"); strcat(buffer,temp); strcat(buffer,"</ht>");

    strcat(buffer,"<tch>"); strcat(buffer,T_TITRE_COL[pc][j].c_str()); strcat(buffer,"</tch>");
    strcat(buffer,"<tft>"); strcat(buffer,T_FONT[pc][j].c_str()); strcat(buffer,"</tft>");
    sprintf(temp,"%d",T_CFCOLOR[pc][j]);
    strcat(buffer,"<tcl>"); strcat(buffer,temp); strcat(buffer,"</tcl>");
    //if (T_ITAL[pc][j] == 'I') strcpy(temp,"Italique"); else strcpy(temp,"Standard");
    strcat(buffer,"<tit>"); strcat(buffer,T_ITAL[pc][j].c_str()); strcat(buffer,"</tit>");
    //if (T_BOLD[pc][j] == 'B') strcpy(temp,"Gras"); else strcpy(temp,"Standard");
    strcat(buffer,"<tgr>"); strcat(buffer,T_BOLD[pc][j].c_str()); strcat(buffer,"</tgr>");
    sprintf(temp,"%d",T_HAUT[pc][j]);
    strcat(buffer,"<tta>"); strcat(buffer,temp); strcat(buffer,"</tta>");
    sprintf(temp,"%d",T_CBCOLOR[pc][j]);
    strcat(buffer,"<tcf>"); strcat(buffer,temp); strcat(buffer,"</tcf>");
    //if (T_JC[pc][j]=='G') strcpy (temp,"Gauche");
    //if (T_JC[pc][j]=='C') strcpy (temp,"Centre");
    //if (T_JC[pc][j]=='D') strcpy (temp,"Droite");
    strcat(buffer,"<tjh>"); strcat(buffer,T_JH[pc][j].c_str()); strcat(buffer,"</tjh>");
    //if (T_JV[pc][j]=='H') strcpy (temp,"Haut");
    //if (T_JV[pc][j]=='C') strcpy (temp,"Centre");
    //if (T_JV[pc][j]=='B') strcpy (temp,"Bas");
    strcat(buffer,"<tjv>"); strcat(buffer,T_JV[pc][j].c_str()); strcat(buffer,"</tjv>");
    sprintf(temp,"%d",T_LARG[pc][j]);
    strcat(buffer,"<tht>"); strcat(buffer,temp); strcat(buffer,"</tht>");

    strcat(buffer,"|");   // | as separator
   }
 strcat(buffer,"</champs>");
 strcpy(tmp,m_directory);   //DatabaseName);
 strcat(tmp,"\\eco_col");

 col = new realisam;
 rc = col->OpenEngine(tmp,248,"ndx","dat");   //256 - 8
 rc = col->SetIndexMode(0,0);

 rc = col->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = col->RewriteRecord(buffer, strlen(buffer)+1,recdata);
     else
     { recdata=col->GetNewRecordNumber();
       rc = col->WriteKey(0,Key,recdata);
       rc = col->WriteRecord(buffer,strlen(buffer)+1);
       
     }
 col->CloseEngine();

}

void __fastcall TGhost::Save_GlobTri(char *s)
{
  char name[100];  char stmp[100];
  char Key[100],RetKey[100];
  int rc,recdata,i,nbitems;
  char tmp[5000];
  char filename[250];
  realisam *tri;
  int count,j;
  char buffer[10000];
  AnsiString a;


///////////////////////////////////////////////
strcpy(Key,P_TRI[pc]);
 if (strlen(Key) == 0) return ;

 tri = new realisam();
 strcpy(filename,m_directory); strcat(filename,"\\eco_tri");
 rc = tri->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = tri->SetIndexMode(0,0);

 // Compute Number of Lignes and Colonnes
 strcpy(buffer,"<champs>");

 count = 0;
 for (i=0;i<8;i++) if (P_ATTR[pc][i] != 'Z') count ++;



 // preparer buffer
 strcpy(buffer,"<l>"); strcat(buffer,Key); strcat(buffer,"</l>");
 strcat(buffer,"<des>");
 strcat(buffer,"Commentaires");  // $$$$$$$$$  a mettre en global ??
 strcat(buffer,"</des>");
 strcat(buffer,"<detail>"); if (P_DETAIL[pc]!=0) strcat(buffer,"O"); else strcat(buffer,"N");
 strcat(buffer,"</detail>");

 strcat(buffer,"<champs>");
 count = NB_ITEMS_TRI[pc];
 if (count > 8)  count=8;
 for (i=0;i<count;i++)
   {
     strcpy(tmp,"<CH>"); strcat(tmp,P_FIELD[pc][i].c_str()); strcat(tmp,"</CH>");
     if (P_NIV0[pc][i]==1) strcat(tmp,"<N0>X</N0>"); else strcat(tmp,"<N0> </N0>");
     if (P_NIV1[pc][i]==1) strcat(tmp,"<N1>X</N1>"); else strcat(tmp,"<N1> </N1>");
     if (P_NIV2[pc][i]==1) strcat(tmp,"<N2>X</N2>"); else strcat(tmp,"<N2> </N2>");
     if (P_NIV3[pc][i]==1) strcat(tmp,"<N3>X</N3>"); else strcat(tmp,"<N3> </N3>");
     if (P_ENV[pc][i]==1) strcat(tmp,"<DT>X</DT>"); else strcat(tmp,"<DT> </DT>");


     strcat(tmp,"<TR>"); strcat(tmp,"X"); strcat(tmp,"</TR>");
     strcat(tmp,"<BL>"); strcat(tmp,"X"); strcat(tmp,"</BL>");
     ///////////////////////////////////
     //  les 3 descriptions  Titre Ligne, Col et detail ??


      if (P_ATTR[pc][i]=='L')  T_LLCC[pc][i]="L";
      if (P_ATTR[pc][i]=='C')  T_LLCC[pc][i]="C";
      if (P_ATTR[pc][i]=='B')  T_LLCC[pc][i]="B";
      if (P_ATTR[pc][i]=='T')  T_LLCC[pc][i]="T";

     strcat(tmp,"<lc>"); strcat(tmp,T_LLCC[pc][i].c_str()); strcat(tmp,"</lc>");
     a = T_LLCC[pc][i];

     j = i;
     strcat(tmp,"<pol>"); strcat(tmp,T_POL[pc][j].c_str()); strcat(tmp,"</pol>");
     strcat(tmp,"<ct>"); strcat(tmp,T_CTEXT[pc][j].c_str()); strcat(tmp,"</ct>");
     strcat(tmp,"<it>"); strcat(tmp,T_TITAL[pc][j].c_str()); strcat(tmp,"</it>");
     strcat(tmp,"<bd>"); strcat(tmp,T_TBOLD[pc][j].c_str()); strcat(tmp,"</bd>");
     strcat(tmp,"<ht>"); strcat(tmp,T_HAUTEUR[pc][j].c_str()); strcat(tmp,"</ht>");
     strcat(tmp,"<jh>"); strcat(tmp,T_JSH[pc][j].c_str()); strcat(tmp,"</jh>");
     strcat(tmp,"<jv>"); strcat(tmp,T_JSV[pc][j].c_str()); strcat(tmp,"</jv>");
     strcat(tmp,"<cb>"); strcat(tmp,T_CBKG[pc][j].c_str()); strcat(tmp,"</cb>");
     strcat(tmp,"<lg>"); strcat(tmp,T_TLARG[pc][j].c_str()); strcat(tmp,"</lg>");

     strcat(tmp,"<ls1>"); strcat(tmp,T_LS1[pc][j].c_str()); strcat(tmp,"</ls1>");
     strcat(tmp,"<ep1>"); strcat(tmp,T_LS1EP[pc][j].c_str()); strcat(tmp,"</ep1>");
     strcat(tmp,"<cl1>"); strcat(tmp,T_LS1CL[pc][j].c_str()); strcat(tmp,"</cl1>");
     strcat(tmp,"<st1>"); strcat(tmp,T_LS1ST[pc][j].c_str()); strcat(tmp,"</st1>");

     strcat(tmp,"<ls2>"); strcat(tmp,T_LS2[pc][j].c_str()); strcat(tmp,"</ls2>");
     strcat(tmp,"<ep2>"); strcat(tmp,T_LS2EP[pc][j].c_str()); strcat(tmp,"</ep2>");
     strcat(tmp,"<cl2>"); strcat(tmp,T_LS2CL[pc][j].c_str()); strcat(tmp,"</cl2>");
     strcat(tmp,"<st2>"); strcat(tmp,T_LS2ST[pc][j].c_str()); strcat(tmp,"</st2>");

     strcat(buffer,tmp); strcat(buffer,"|");   // | as separator
   }

 strcat(buffer,"</champs>");

 strcat(buffer,"<envelop>");
 for (i=0;i<count;i++)
   {
    strcpy(tmp,"<lc>"); strcat(tmp,E_ENV[pc][i].c_str()); strcat(tmp,"</lc>");
    strcat(tmp,"<pol>"); strcat(tmp,E_POL[pc][i].c_str()); strcat(tmp,"</pol>");
    strcat(tmp,"<ct>"); strcat(tmp,E_CTEXT[pc][i].c_str()); strcat(tmp,"</ct>");
    strcat(tmp,"<it>"); strcat(tmp,E_TITAL[pc][i].c_str()); strcat(tmp,"</it>");
    strcat(tmp,"<bd>"); strcat(tmp,E_TBOLD[pc][i].c_str()); strcat(tmp,"</bd>");
    strcat(tmp,"<ht>"); strcat(tmp,E_HAUTEUR[pc][i].c_str()); strcat(tmp,"</ht>");
    strcat(tmp,"<jh>"); strcat(tmp,E_JSH[pc][i].c_str()); strcat(tmp,"</jh>");
    strcat(tmp,"<jv>"); strcat(tmp,E_JSV[pc][i].c_str()); strcat(tmp,"</jv>");
    strcat(tmp,"<cb>"); strcat(tmp,E_CBKG[pc][i].c_str()); strcat(tmp,"</cb>");
    strcat(tmp,"<lg>"); strcat(tmp,E_TLARG[pc][i].c_str()); strcat(tmp,"</lg>");
    strcat(tmp,"<coult>"); strcat(tmp,E_COULTRAIT[pc][i].c_str()); strcat(tmp,"</coult>");
    strcat(tmp,"<style>"); strcat(tmp,E_STYLE[pc][i].c_str()); strcat(tmp,"</style>");
    strcat(tmp,"<epaiss>"); strcat(tmp,E_EPAISS[pc][i].c_str()); strcat(tmp,"</epaiss>");
    strcat(tmp,"<design>"); strcat(tmp,E_DESIGN[pc][i].c_str()); strcat(tmp,"</design>");
    strcat(tmp,"<encadr>"); strcat(tmp,E_ENCADR[pc][i].c_str()); strcat(tmp,"</encadr>");

    strcat(buffer,tmp); strcat(buffer,"|");
   }

 strcat(buffer,"</envelop>");


 rc = tri->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = tri->RewriteRecord(buffer, strlen(buffer)+1,recdata);
     else
     { recdata=tri->GetNewRecordNumber();
       rc = tri->WriteKey(0,Key,recdata);
       rc = tri->WriteRecord(buffer,strlen(buffer)+1);
      }



tri->CloseEngine();



}


int __fastcall TGhost::Explode(char sep,char *str)
{
 int i, count, ip;
 char c,cpred;
 if (strlen(str)==0) return 0;
 count = 0; params[count][0]=0; // indice params
 c=str[0]; cpred=0;
 i=0; ip=0;
 while (c)
  { cpred=c;
   if (c==sep)
     { params[count][ip]=0; count++; ip=0; if (count > 19) count=19; }
   else
     { params[count][ip]=c;  ip++; }
   i++; c=str[i];
  }
 if (cpred==sep) count--; return (count+1);
}


void __fastcall TGhost::StripC(char *s)
{
 char tmp[5000];
 int Row;   int count; int colcnt;
 int i,j,k;



 ExtractValue(tmp,s,"champs",0);
 count = Explode('|',s);
 colcnt=0;
 //NB_ITEMSCOL=count;
 if (count)
   {
     for (i=8; i<count+8; i++)  // 9, to skip default
       {
        ExtractValue(tmp,params[i-8],"ch",0);
        if (strlen(tmp) == 0 && i>8) break;
        if (strcmp(tmp,"Défaut") !=0)
        {

        //k=i;
        k=colcnt+8;
        j=i-8;
        colcnt++;

        P_TRICOL[pc][i]=0;
        P_ATTR[pc][i]='C';

        // Colonnes Detail
       ExtractValue(tmp,params[j],"ch",0);
       P_FIELD[pc][k] = AnsiString(tmp);
       ExtractValue(tmp,params[j],"ft",0);
       P_FONT[pc][k] = AnsiString(tmp);
       ExtractValue(tmp,params[j],"cl",0);
       P_CFCOLOR[pc][k] = atoi(tmp);
       ExtractValue(tmp,params[j],"it",0);
       P_ITAL[pc][k] = AnsiString(tmp);
       //if (strcmp(tmp,"Standard")==0) P_ITAL[pc][k] = 'N'; else P_ITAL[pc][k]='I';
       ExtractValue(tmp,params[j],"gr",0);
       P_BOLD[pc][k] = AnsiString(tmp);
       //if (strcmp(tmp,"Standard")==0) P_BOLD[pc][k] = 'N'; else P_BOLD[pc][k]='B';
       ExtractValue(tmp,params[j],"ta",0);
       P_HAUT[pc][k] = atoi(tmp);
       ExtractValue(tmp,params[j],"cf",0);
       P_CBCOLOR[pc][k] = atoi(tmp);
       ExtractValue(tmp,params[j],"jh",0);
       P_JH[pc][k] = AnsiString(tmp); //[0];
       ExtractValue(tmp,params[j],"jv",0);
       P_JV[pc][k] = AnsiString(tmp);  ///[0];
       ExtractValue(tmp,params[j],"ht",0);      // largeur
       P_LARG[pc][k] = atoi(tmp);

       ExtractValue(tmp,params[j],"tch",0);
       T_TITRE_COL[pc][k] = AnsiString(tmp);
       ExtractValue(tmp,params[j],"tft",0);
       T_FONT[pc][k] = AnsiString(tmp);
       ExtractValue(tmp,params[j],"tcl",0);
       T_CFCOLOR[pc][k] = atoi(tmp);
       ExtractValue(tmp,params[j],"tit",0);
       T_ITAL[pc][k] = AnsiString(tmp);  //[0];
       ExtractValue(tmp,params[j],"tgr",0);
       T_BOLD[pc][k] = AnsiString(tmp);  //[0];
       ExtractValue(tmp,params[j],"tta",0);
       T_HAUT[pc][k] = atoi(tmp);
       ExtractValue(tmp,params[j],"tcf",0);
       T_CBCOLOR[pc][k] = atoi(tmp);
       ExtractValue(tmp,params[j],"tjh",0);
       T_JH[pc][k] = AnsiString(tmp); //tmp[0];
       ExtractValue(tmp,params[j],"tjv",0);
       T_JV[pc][k] = AnsiString(tmp); //[0];
       ExtractValue(tmp,params[j],"tht",0);      // largeur
       T_LARG[pc][k] = atoi(tmp);
       }  //if (not zero)
      }
   }

 P_COL[pc]=8+colcnt;
}


void __fastcall TGhost::LoadPlanningFromFile(char *pl)
{
 char tmp[250];

 strcpy(tmp,pl);

 if (pc<4) Ghost->Global_Planning(P_NOM[pc]);
 else Global_Report(P_NOM[pc]);
}


void __fastcall TGhost::Help(char *url)
{
Thelp *Aide;
strcpy(m_help,url);
Aide = new Thelp(Application);
Aide->ShowModal();
delete Aide;
}
