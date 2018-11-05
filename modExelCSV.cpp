//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modExelCSV.h"
#include "modColCSV.h"
#include <stdio.h>
#include "globals.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TExecCSV *ExecCSV;
//---------------------------------------------------------------------------
__fastcall TExecCSV::TExecCSV(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TExecCSV::ImporterFichierTachesClick(
      TObject *Sender)
{
 Label4->Caption = "______________";


 OpenDialog1->FileName = "*.csv";
 if (OpenDialog1->Execute())
    {
     strcpy(filename,OpenDialog1->FileName.c_str());
     LoadData(filename);
     Label4->Caption = AnsiString(filename);
    }
}
//---------------------------------------------------------------------------



void __fastcall TExecCSV::LoadData(char *name)
{
FILE *fp;
char buf[1024],*p;
int nbcol,row,col,i,cntav,cntac;
char crit[50];
int nbjours,seuil;
char tmp[50];
int numcrit,cnttache; bool Flag;
TForm2 *frm;
char sepchamps[10];

frm = new TForm2(Application);
frm->ShowModal();
delete frm;

Clean_Grid(av,2);
Clean_Grid(ac,2);
fp = fopen(name,"rt");
if (fp==NULL)
  {
   Application->MessageBoxA("Erreur à l'ouverture du fichier CSV","Ecoplanning",MB_OK);
   return;
  }
strcpy(buf,"");
fgets(buf,1000,fp);    // Skip First row
ScanBuf(buf);
if (!feof(fp))
  {
  fgets(buf,1000,fp);
  ScanBuf(buf);
  }
cntac=1;
//ac->Cells[1][cntac] = AnsiString("P");
//ac->Cells[2][cntac] = AnsiString("PHASES");

cntac = 1;
cntav = 1;
cnttache = 0;
strcpy(tmp,eSeuil->Text.c_str());
seuil = atoi(tmp);
if (seuil ==0) seuil =100;
sepchamps[0]=SEPCHAMPS; sepchamps[1]=0;


while (!feof(fp))
   {
    p=strchr(buf,'\r'); if (p) *p=0;
    p=strchr(buf,'\n'); if (p) *p=0;
    strcat(buf,sepchamps);  // strcat(buf,",");
    nbcol = Explode(SEPCHAMPS,buf); // nbcol=Explode(',',buf);
    if (nbcol > 20) nbcol=20;

    for (i=0;i<nbcol;i++) RemoveQuotes(params[i]);

    Flag = false;
    if (strstr(params[0],"42"))
       {seuil = seuil; }
    nbjours = Compute_NbJours(params[COL3-1]); // 2]);
    // remplit av ou ac en fonction  des donnees
    /*
    if (strlen(params[5])==0)
      {

       if (nbjours>seuil)
        Flag=true;
        else Flag=false;
      }
      */
       if(cntav>1)
         { av->RowCount++;
           for (i=0;i<av->ColCount; i++) av->Colors[i][cntav] = clWhite;
          }


       av->Cells[1][cntav] = AnsiString(params[COL1-1]);
       av->Cells[2][cntav] = AnsiString(params[COL2-1]);
       av->Cells[3][cntav] = AnsiString (nbjours); // (params[COL3-1]);
       av->Cells[4][cntav] = AnsiString(params[COL4-1]);
       av->Cells[5][cntav] = AnsiString(params[COL5-1]);
       av->Cells[6][cntav] = AnsiString(params[COL6-1]);
       av->Cells[7][cntav] = AnsiString(params[COL7-1]);

       // av->Cells[3][cntav] = AnsiString(nbjours);
       if (nbjours==0)
              av->Colors[3][cntav] = clRed;

       Flag=false;
       if (Flag)
         {
          /*
          if(cntac>1) { ac->RowCount++; }
          sprintf(crit,"P-%03d",cntac);
          ac->Cells[1][cntac] = AnsiString(crit);
          ac->Cells[2][cntac] = AnsiString(params[1]);
          cntac++;
          */
          for (i=1;i<=7;i++)
            { av->Colors[i][cntav] = clYellow;

            }
          av->Cells[9][cntav] = "N";
         }
       if (!Flag)
         {
          cnttache++;
          av->Cells[0][cntav] = AnsiString(cnttache);
          av->Cells[9][cntav] = "T";
         }  else
         av->Cells[0][cntav] = "__";

       av->Cells[1][cntav] = AnsiString(cntav);
       av->Cells[8][cntav] = AnsiString(crit);
       av->Cells[3][cntav] = AnsiString(nbjours); // AnsiString(number);
       if (floating) av->Colors[3][cntav] = RGB(255,0,0);
         else  av->Colors[3][cntav] = RGB(255,255,255);

       if (nbjours==0) { av->Colors[3][cntav] = clRed;  av->Cells[3][cntav]="1"; }

       cntav++;
    //  }
    fgets(buf,1000,fp);
    ScanBuf(buf);
   }
fclose(fp);

Compute_Niveaux();
Compute_Succ();
}

void __fastcall  TExecCSV::RemoveQuotes(char *pr)
{
 int lg,i,m;
 char res[500];

 lg = strlen(pr);
 if (lg==0) return;
 m=0;
 for (i=0;i<lg;i++)
   {
    if (pr[i] != '"')
      { res[m]=pr[i];
        m++; res[m]=0;
      }
   }
 strcpy(pr,res);

}

void __fastcall  TExecCSV::Compute_Succ()
{
 int i,j,cntrow,cntpred;
 AnsiString Pred; char pred[500];
 AnsiString tmp; int dur;
 char *p;  char seppred[10];

 cntrow = av->RowCount;

  for (i=1;i<cntrow;i++) av->Cells[7][i]="";

 //seppred[0]=SEPPRED;
 seppred[0]='~'; //SEPPRED;
 seppred[1]=0;

 for (i=1;i<cntrow;i++)
   {
    if (av->Cells[0][i] != "__")
      {

       tmp = av->Cells[1][i];


       strcpy(pred,seppred); // strcpy(pred,";");
       strcat(pred,av->Cells[6][i].c_str());
       strcat(pred,seppred); // strcat(pred,";");
       // p = strchr(pred,',');
       // if (p) *p=';';
  // cntpred = Explode(SEPPRED,pred);
     cntpred = Explode('~',pred);
          //';',pred);
       av->Cells[6][i]= "";
       if (cntpred > 49) cntpred=49;
       for (j=1;j<cntpred;j++)
         {
          if (strlen(params[j]))
            {
             Decompose(params[j]);
             /// Cas du lien DF
             if (strcmp(LIEN,"DF")==0)
                {
                  strcpy(LIEN,"FF");
                  // modifier le decalage aussi
                  // retirer la duree
                  tmp = av->Cells[3][i];
                  if (tmp=="") dur = 0;
                  else dur = StrToInt(tmp);
                  DECAL = DECAL - dur;

                }

             if (TACHE==0)
              TACHE=TACHE;

             Pred = AnsiString(TACHE)+AnsiString(LIEN)+ AnsiString(DECAL);

             av->Cells[6][i]= av->Cells[6][i] + Pred + " |" ;
             if (i==167)
               { i=i;
               }
             Deduct_Succ(i);  //i);
            }
         }
      }
   }
}


 void __fastcall  TExecCSV::Deduct_Succ(int line)
 {
  // on connait TACHE PREDECESSEUR LIEN DECAL et TACHE ORIGINE = line
  AnsiString succ;
  char tmp[50];
  int i,numeco, tache,tach;

  if (TACHE==0) return;


      strcpy(tmp,av->Cells[1][line].c_str());
      tach = atoi(tmp);
      // Cherche numero taches ecoplanning au lieu de tache Project
      numeco = 1;
      for (i=1;i<av->RowCount;i++)
        {
         strcpy(tmp,av->Cells[1][i].c_str());
         tache = atoi(tmp);

         if (tache==tach)  //line) //line)
           {
            strcpy(tmp,av->Cells[0][i].c_str());
            numeco = atoi(tmp);
            if (numeco==0)
              {
               numeco=0;
               //av->Colors[7][i]= clRed;
               if (av->Cells[0][TACHE] == "__") av->Colors[7][TACHE]= clRed;
              }
            break;
           }

        }

     if (numeco !=0)
       {
        if (numeco==1)
          numeco=numeco;
        succ = AnsiString(numeco) + AnsiString(LIEN) + AnsiString(DECAL);
        av->Cells[7][TACHE] = av->Cells[7][TACHE] + succ + " |";
       }

 }

void __fastcall TExecCSV::Decompose(char *parm)
{
 char *p,*p1,*p2,*p3,*p4;
 char tmp[500],numtache[20],decal[20];
 int i;  int coef;

 strcpy(tmp,parm);
 if (tmp[0]=='"') tmp[0]='0';
 p=strstr(tmp," jour");
 if (p) { coef=1; *p=0; }
 else
   {
    p=strstr(tmp," sm");
    if (p) {coef=5; *p=0;}
    else
     {
      p=strstr(tmp," mois");
      if (p) { coef=21; *p=0; }
     }

   }
 p=NULL;
 p1=strstr(tmp,"FD"); if (p1) p=p1;
 p2=strstr(tmp,"FF"); if (p2) p=p2;
 p3=strstr(tmp,"DD");  if (p3) p=p3;
 p4=strstr(tmp,"DF"); if (p4) p=p4;

 if (p==NULL)
 { p = tmp+strlen(tmp); strcat(tmp,"FD0"); }
 for (i=0;i<20;i++) numtache[i]=0;
 strncpy(numtache,tmp,p-tmp);
 numtache[p-tmp] = 0;
 TACHE = atoi(numtache);
 if (TACHE==0)
   { TACHE=TACHE;
   }
 strncpy(LIEN,p,2);
 LIEN[2]=0;

 p=p+2;
 strcpy(decal,p);
 DECAL = atoi(decal);
 DECAL=DECAL*coef;
}



void __fastcall TExecCSV::Clean_Grid(TAdvStringGrid *sgrid, int strow)
{
 int r,c;
 int rr,cc;
 rr=sgrid->RowCount; cc=sgrid->ColCount;
 for (r=1;r<rr;r++)
  {
   for (c=1;c<cc;c++) sgrid->Cells[c][r]="";
  }
  sgrid->RowCount=strow;
}


int __fastcall TExecCSV::Explode(char sep,char *str)
{
 int i, l, count, ip;
 char c,cpred;
 l = strlen(str);
 if (l==0) return 0;
 count = 0; params[count][0]=0; // indice params
 c=str[0]; cpred=0;
 i=0; ip=0;
 while (c)
  { cpred=c;
   if (c==sep)
     { params[count][ip]=0; count++; ip=0; if (count > 49) count=49; }
   else
     { params[count][ip]=c;  ip++; }
   i++; c=str[i];
  }
 if (cpred==sep) count--; return (count+1);
}

void __fastcall TExecCSV::ScanBuf(char *buf)
{
 bool status;
 int  i,l;

 l = strlen(buf);
 status = true;
 for (i=0;i<l;i++)
  {
   if (buf[i]=='"')
     {
      if (status==false) status = true;
      else if (status==true) status = false;
     }
   //  if (status== true && buf[i]==SEPCHAMPS)  // ',')
   //  buf[i] = '-';
   if (status==false && buf[i]==SEPPRED)
      buf[i]='~';  
  }
}


int  __fastcall  TExecCSV::Compute_NbJours(char *parm)
{
 char *p;
 char tmp[100];
 int i,len,pos;
 int coef;
 char c;  float ff;

 coef=0;
 strcpy(tmp,parm);
 if (strlen(parm)==0) return 0;
 p=strstr(tmp," jour");
 if (p) { coef=1; *p=0; }
 else
   {
    p =strstr(tmp," sm");
    if (p) {coef=5; *p=0; }
    else
     {
      p=strstr(tmp," mois");
      if (p) {coef=21; *p=0; }
     }

   }
 len = strlen(tmp);
 pos = 0;
 strcpy(number,"0000000000");
 floating = false;
 for (i=0;i<len;i++)
   {
    c = tmp[i];
    if ((c>='0' && c<='9') || c=='~' || c==',')
      {
       if (c=='~' || c==',')
        { floating = true; c='.'; }
       number[pos] = c;
       pos++; number[pos]=0;
      }
    else
      {
       pos =0;
       number[pos] = '0';
       number[pos+1]=0;
      }
   }
if (!floating) { i=atoi(number); return i*coef; }
ff = atof(number)*coef; i=ff; 
return i;
}


//---------------------------------------------------------------------------

void __fastcall TExecCSV::cbLClick(TObject *Sender)
{
 LoadData(filename);       
}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::btRegenClick(TObject *Sender)
{
 Compute_Niveaux();
 Compute_Succ();
}


void __fastcall TExecCSV::Compute_Niveaux()
{
 int i,j1,m1,a1,j;
 char dt1[50],dt2[50],tmp[200];
 int dist1; int mind,maxd;
 int N0,N1,N2,N3;
 int cntac,cnttache;

 // Calcul date début, date fin
 mind = 10000; maxd = -1;   cnttache = 0;
 for (i=1;i<av->RowCount;i++)
   {
    //av->Cells[10][i]=AnsiString(i);
    strcpy(dt1,av->Cells[4][i].c_str());
    if (strlen(dt1)==12) strcpy(dt1,dt1+4);
    dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[10]=0; a1=atoi(dt1+6);
    dist1 = convert_date(a1,m1,j1);
    if (dist1 < mind) { mind = dist1; sprintf(ddeb,"%02d-%02d-%04d",j1,m1,a1+2000); }

    strcpy(dt1,av->Cells[5][i].c_str());
    if (strlen(dt1)==12) strcpy(dt1,dt1+4);
    dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[10]=0; a1=atoi(dt1+6);
    dist1 = convert_date(a1,m1,j1);
    if (dist1 > maxd) { maxd = dist1; sprintf(dfin,"%02d-%02d-%04d",j1,m1,a1+2000); }
   }
Label10->Caption = AnsiString(ddeb);
Label11->Caption = AnsiString(dfin);


Clean_Grid(ac,2);

cntac=0;
 cnttache = 0;
 N0=0; N1=0; N2=0; N3=0;
 // N0=1; N1=1; N2=1; N3=1;
for (i=1;i<av->RowCount;i++)
{
if (av->Cells[9][i] == "T")
  { av->Cells[8][i] = AnsiString(LastRupt);
    cnttache++;
    av->Cells[0][i]=AnsiString(cnttache);
  }
else
{
  av->Cells[0][i]="__";
  if (av->Cells[9][i] == "N")
    {
     N0++; N1=0;N2=0;N3=0;
     // sprintf(tmp,"%02d---",N0);  // Not P
     strcpy(tmp,"----");
     for (j=1;j<=7;j++) av->Colors[j][i] = clYellow;

    }
  if (av->Cells[9][i] == "N-1")
    {
     if (N0==0) N0=1;
     N1++;N2=0;N3=0;
     //sprintf(tmp,"%02d-%02d--",N0,N1);
     sprintf(tmp,"%02d---",N1);
     for (j=1;j<=7;j++) av->Colors[j][i] = clGreen;
    }
  if (av->Cells[9][i] == "N-2")
    {
     N2++;N3=0;
     //sprintf(tmp,"%02d-%02d-%02d-",N0,N1,N2);
     sprintf(tmp,"%02d-%02d--",N1,N2);

     for (j=1;j<=7;j++) av->Colors[j][i] = clLime;
    }
  if (av->Cells[9][i] == "N-3")
    {
     N3++;
     //sprintf(tmp,"%02d-%02d-%02d-%02d",N0,N1,N2,N3);
     sprintf(tmp,"%02d-%02d-%02d-",N1,N2,N3);

     for (j=1;j<=7;j++) av->Colors[j][i] = clGray;
    }

  if (av->Cells[6][i] != "") av->Colors[6][i]= clRed;
  strcpy(LastRupt,tmp);
  av->Cells[8][i] = AnsiString(LastRupt);
  cntac++; if (cntac>1) ac->RowCount++;
  ac->Cells[1][cntac] = AnsiString(LastRupt);
  ac->Cells[2][cntac] = av->Cells[2][i];

  } //else

 }




}


int  __fastcall TExecCSV::convert_date(int year, int month, int day)
{
 int n1,n2,bcl,N;
 int initval;
 //int nbdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  // calcul approximatif de  la distance par rapport au previsionnel
  n1 = (AnPrev%100)*365 + MoisPrev*28 + JourPrev;
  n2 = (year%100)*365 + month*28 + day;

 if (n2<n1) n2=n1+30;

  initval = n2-n1-30; N=initval;

  for (bcl=0;bcl<100;bcl++)
    {
     add_jour(AnPrev,MoisPrev,JourPrev,N);
     if ((An==year) && (Mois==month) && (Jour==day)) break;
     else N++;
    }
 return N;
}


int  __fastcall TExecCSV::add_jour(int year, int month, int day, int jours)
{
// resultats dans An,Mois,Jour
  int i,counter,nbj_restant, j;
//  char days[7][15] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
//  "Samedi" };
//  char months[12][15] = {"Janvier","Février","Mars","Avril","Mai","Juin","Juillet",
//   "Aout","Septembre","Octobre","Novembre","Décembre"};
  int nbdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


  An=year;Mois=month;Jour=day;
  if (An <100) An = An + 2000;
  int ok=1; j=jours;
  while (ok)
    {
     counter = nbdays[Mois-1];
     if (Mois==2){ if (IsLeapYear(An)) counter = 29;}
     nbj_restant = counter - Jour; // nb jours restants dans le mois en cours
     if (j <= nbj_restant)   // on va sortir
        {
         Jour=Jour+j;
         ok=0;
        }
     else
        {
         j=j-nbj_restant-1;
         Mois++;
         if (Mois==13) {Mois=1; An++; }
         Jour=1;  // 1er jour du mois suivant //Jour+nbj_restant+1;
        }

    }

 return 1;
 }

//---------------------------------------------------------------------------

void __fastcall TExecCSV::OuvrirFichierGrilles1Click(TObject *Sender)
{
 Label4->Caption = "______________";
 Label7->Caption = "______________";
 OpenDialog1->FileName = "*.tms";
 if (OpenDialog1->Execute())
    {
     strcpy(filetms,OpenDialog1->FileName.c_str());
     LoadGrid(filetms,av);
     Label7->Caption = AnsiString(filetms);
    }
Compute_Niveaux();
Compute_Succ();

}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::btDelClick(TObject *Sender)
{
int cnt,cntc; int i,j;

if (Application->MessageBoxA("Voulez-Vous Effacer la ligne ?","Ecoplanning",MB_YESNO)==IDNO)
   return;

 if (OldRow==0) return;
 cnt=av->RowCount; cntc=av->ColCount;
 for (i=OldRow;i<cnt-1;i++)
   {
     for (j=0;j<cntc;j++)  av->Cells[j][i]=av->Cells[j][i+1];
   }
for (j=0;j<cntc;j++)  av->Cells[j][cnt-1]= "";
av->RowCount--;
Compute_Niveaux();
Compute_Succ();

}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::avClickCell(TObject *Sender, int ARow, int ACol)
{
 if (ARow > 0) OldCol=ACol; OldRow=ARow;
}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::FormShow(TObject *Sender)
{
 AnsiString Dir;
 OldRow=1; OldCol=1;
 Change = false;
 Dir = GetCurrentDir();
 strcpy(HomeDirectory,Dir.c_str());
 }
//---------------------------------------------------------------------------

void __fastcall TExecCSV::btAppendClick(TObject *Sender)
{
 int row, j,cntc;
 row = av->RowCount;
 av->RowCount++;
 cntc = av->ColCount;
 for (j=0;j<cntc;j++) av->Cells[j][row]="";

}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::btInsClick(TObject *Sender)
{
 int cnt,cntc; int i,j;
 if (OldRow==0) return;
 av->RowCount++;
 cnt=av->RowCount;  cntc=av->ColCount;
 for (i=cnt-1;i>=OldRow;i--)
   {
    for (j=0;j<cntc;j++)  av->Cells[j][i]=av->Cells[j][i-1];
   }
 for (j=0;j<cntc;j++) av->Cells[j][OldRow]="";

 // initialiser
 av->Cells[9][OldRow]="T";
 Compute_Niveaux();
 Compute_Succ();

}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::btSaveClick(TObject *Sender)
{

 char grname[MAX_PATH];

 strcpy(grname,"*.tms");
 SaveDialog1->FileName = AnsiString(grname);
 if (SaveDialog1->Execute())
    {
      strcpy(grname,SaveDialog1->FileName.c_str());
      if (FileExists(SaveDialog1->FileName))
        {
         if (Application->MessageBoxA("Le fichier existe deja : Voulez-Vous le Remplacer?",
             "Ecoplanning",MB_YESNO)==IDNO) return;
        }
      // SaveGrid(grname,ac,"CRT");
      SaveGrid(grname,av);
    }
 btTachesClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall  TExecCSV::SaveGrid(char *fn,TAdvStringGrid *sg)
{
 FILE *fp; char buf[5000]; char tmp[2500];
 int i,j,cntr,cntc;
 cntr = sg->RowCount; cntc = sg->ColCount;
 fp = fopen(fn,"wt");
 if (fp==NULL)
   { Application->MessageBoxA("Erreur Ouverture Fichier","Ecoplanning",MB_OK);
     return;
   }

 for (i=1;i<cntr;i++)
   {
    buf[0]=0;
    for (j=0;j<cntc;j++)
      {
        sprintf(tmp,"<c%02d>%s</c%02d>",j,sg->Cells[j][i].c_str(),j);
        strcat(buf,tmp);
      }
    strcat(buf,"\n");
    fputs(buf,fp);
   }
 fclose(fp);
}

void __fastcall  TExecCSV::LoadGrid(char *fn,TAdvStringGrid *sg)
{
 FILE *fp;   char buf[5000],tmp[2500],tag[20];
 int i,j,cntr,cntc;
 cntc = sg->ColCount;
 fp = fopen(fn,"rt");
 if (fp==NULL)
   { Application->MessageBoxA("Erreur Ouverture Fichier","Ecoplanning",MB_OK);
     return;
   }
 Clean_Grid(sg,2);
 fgets(buf,4900,fp);
 i=0;
 while (!feof(fp))
   {
    ExtractValue(tmp,buf,"c01",0);
    if (strlen(tmp)>0)
      {
       i++; if (i>1) sg->RowCount++;
       for (j=0;j<cntc;j++)
        {

        sprintf(tag,"c%02d",j);
        ExtractValue(tmp,buf,tag,0);
        sg->Cells[j][i]=AnsiString(tmp);
        }
      }  
    fgets(buf,4900,fp);



   }

fclose (fp);
}

int __fastcall TExecCSV::ExtractValue(char *result, char *buff, char *tag, int posdeb)
{ char tmp[250];char *p,*p1,*p2; int pos,l;

 result[0]=0; strcpy(tmp,"<"); strcat(tmp,tag); strcat(tmp,">"); p = strstr(buff,tmp);
 l=0;
 if (p)
   {strcpy(tmp,"</"); strcat(tmp,tag); strcat(tmp,">");p1= strstr(buff,tmp);
    if (p1) {p2=p + strlen(tag)+2; l= p1-p2; strncpy(result,p2,l); result[l]=0; }
   }
 return l;
}

void __fastcall TExecCSV::avGetEditorType(TObject *Sender, int ACol,
      int ARow, TEditorType &AEditor)
{
if (ACol==9)
  {

   AEditor = edComboList;
   av->ClearComboString();
   av->AddComboString("T");
   av->AddComboString("N");
   av->AddComboString("N-1");
   av->AddComboString("N-2");
   av->AddComboString("N-3");
  }
}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::btTachesClick(TObject *Sender)
{
  // Fabrication des fichiers taches et Liaisons  et Criteres
 char grname[MAX_PATH];
 char fullpath[MAX_PATH];

 strcpy(grname,"TACHES.TXT");
 strcpy(fullpath,HomeDirectory); strcat(fullpath,"\\"); strcat(fullpath,grname);
 /*
 SaveDialog1->FileName = AnsiString(grname);
 if (SaveDialog1->Execute())
    {
      strcpy(grname,SaveDialog1->FileName.c_str());
      if (FileExists(SaveDialog1->FileName))
        {
         if (Application->MessageBoxA("Le fichier existe deja : Voulez-Vous le Remplacer?",
             "Ecoplanning",MB_YESNO)==IDNO) return;
        }

      SaveTaches(grname);
    }
 */

 SaveTaches(fullpath);

 strcpy(grname,"LIAISONS.TXT");
 strcpy(fullpath,HomeDirectory); strcat(fullpath,"\\"); strcat(fullpath,grname);
 /*
 SaveDialog1->FileName = AnsiString(grname);
 if (SaveDialog1->Execute())
    {
      strcpy(grname,SaveDialog1->FileName.c_str());
      if (FileExists(SaveDialog1->FileName))
        {
         if (Application->MessageBoxA("Le fichier existe deja : Voulez-Vous le Remplacer?",
             "Ecoplanning",MB_YESNO)==IDNO) return;
        }

      SaveLiaisons(grname);
    }

 */
 SaveLiaisons(fullpath);

strcpy(grname,"CRITERES.TXT");
strcpy(fullpath,HomeDirectory); strcat(fullpath,"\\"); strcat(fullpath,grname);

/*
 SaveDialog1->FileName = AnsiString(grname);
 if (SaveDialog1->Execute())
    {
      strcpy(grname,SaveDialog1->FileName.c_str());
      if (FileExists(SaveDialog1->FileName))
        {
         if (Application->MessageBoxA("Le fichier existe deja : Voulez-Vous le Remplacer?",
             "Ecoplanning",MB_YESNO)==IDNO) return;
        }

      SaveCriteres(grname);
    }
 */
 SaveCriteres(fullpath);
 Application->MessageBoxA("Sauvegarde effectuée","Ecoplanning",MB_OK);

}
//---------------------------------------------------------------------------


void __fastcall  TExecCSV::SaveTaches(char *grname)
{
 FILE *fp;  int cnt,i,cntc,j; char buf[500];
 AnsiString lib;
 char debs[100],datesouh[50];;
 cnt = av->RowCount;
 cntc = ac->RowCount;
 fp = fopen(grname,"wt");
 if (fp)
  {
   for (i=1;i<cnt;i++)
     {
      // if (av->Cells[0][i] != "__")
      //  {
         strcpy(buf,"\"");   strcat(buf,av->Cells[0][i].c_str()) ; strcat(buf,"\",");
         strcat(buf,"\"");   strcat(buf,av->Cells[2][i].c_str()) ; strcat(buf,"\",");
         strcat(buf,"\"");   strcat(buf,av->Cells[3][i].c_str()) ; strcat(buf,"\",");
         strcat(buf,"\"");   strcat(buf,av->Cells[8][i].c_str()) ; strcat(buf,"\",");
         // rechercher le libelle
         for (j=1;j<cntc;j++)
           {
            if (ac->Cells[1][j] == av->Cells[8][i])
              lib = ac->Cells[2][j];
           }
         strcat(buf,"\"");   strcat(buf,lib.c_str()) ; strcat(buf,"\",");  // libelle crit 1

         strcat(buf,"\"\",");  // code crit2
         strcat(buf,"\"\",");  // lib 2
         strcat(buf,"\"\",");  // crit 3
         strcat(buf,"\"\",");  // lib 3
         strcat(buf,"\"\",");  // vide
         strcat(buf,"\"0.00\",");  // montant

         if (av->Cells[6][i]=="")
            {
             // convertir date debut, en debut souhaité
             strcpy(debs,av->Cells[4][i].c_str());
             if (strlen(debs)==8) { strcpy(datesouh,debs); }
             else if (strlen(debs)==12) strcpy(datesouh,debs+4);
             else if (strlen(debs)==10)
               { datesouh[0]=debs[0];
                 datesouh[1]=debs[1];
                 datesouh[2]=debs[2];
                 datesouh[3]=debs[3];
                 datesouh[4]=debs[4];
                 datesouh[5]=debs[5];
                 datesouh[6]=debs[8];
                 datesouh[7]=debs[9];
                 datesouh[8]=0;
                }
             strcat(buf,"\"");
             strcat(buf,datesouh);
             strcat(buf,"\",");

            }


         else strcat(buf,"\"\",\"\",");

         strcat(buf,"\n");
         fputs(buf,fp);
        //}

     }


   fclose(fp);
  }
}

void __fastcall  TExecCSV::SaveLiaisons(char *grname)
{
 FILE *fp;  int cnt,i,k,nbsucc;  char buf[500];
 char tmp[5000]; int succ,lg,stt;
 char su[20],li[20],de[20]; int s,l,d; char c;

 cnt = av->RowCount;
 fp = fopen(grname,"wt");
 if (fp)
  {
   for (i=1;i<cnt;i++)
     {
      if (av->Cells[0][i] != "__")
        {



         strcpy(tmp,av->Cells[7][i].c_str());
         if (strlen(tmp) > 0)
           {
            
            nbsucc=Explode('|',tmp);
            for (succ=0;succ<nbsucc;succ++)
              {
               strcpy(buf,"\"");   strcat(buf,av->Cells[0][i].c_str()) ; strcat(buf,"\",");
               lg = strlen(params[succ]);
               if (lg)
                 {
                  stt = 0; su[0]=0; li[0]=0; de[0]=0;
                  s=0;l=0;d=0;
                  for (k=0;k<lg;k++)
                    {
                     c= params[succ][k];
                     if (c == 'D'  || c=='F') { stt=1; li[l]=c; l++; li[l]=0;  }
                     else if (c==' ') {;}
                     else
                      { if (stt==0) { su[s]=c;  s++; su[s] = 0; }
                       if (stt>=1) { de[d]=c; d++; de[d] = 0; }
                      }


                    } // for

                  strcat(buf,"\""); strcat(buf,su); strcat(buf,"\",");
                  strcat(buf,"\""); strcat(buf,de); strcat(buf,"\",");
                  strcat(buf,"\""); strcat(buf,li); strcat(buf,"\",");

                  strcat(buf,"\n");
                  fputs(buf,fp);
                 }  // if lg;
              }
            }
        }

     }

   fclose(fp);
  }

}

void __fastcall  TExecCSV::SaveCriteres(char *grname)
{
 FILE *fp;  int cnt,i,cntc,j; char buf[500];
 AnsiString lib;
 cntc = ac->RowCount;
 fp = fopen(grname,"wt");
 if (fp)
  {
   for (i=1;i<cntc;i++)
     {
      strcpy(buf,"<c>"); strcat(buf,ac->Cells[1][i].c_str()); strcat(buf,"</c>");
      strcat(buf,"<d>"); strcat(buf,ac->Cells[2][i].c_str()); strcat(buf,"</d>");
      strcat(buf,"\n");
      fputs(buf,fp);
     }
   // fabriquer INTERV et TRIS

   fclose(fp);
  }
}



void __fastcall TExecCSV::avCellValidate(TObject *Sender, int ACol, int ARow,
      AnsiString &Value, bool &Valid)
{

 if (ACol == 9)
   {
     Compute_Niveaux();
     Compute_Succ();
   }        
}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::avKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 Change = true;        
}
//---------------------------------------------------------------------------

void __fastcall TExecCSV::QuitterClick(TObject *Sender)
{
 if (Change)
   {
    if (Application->MessageBoxA("Grille Modifiée: Voulez-vous la saugarder","Ecoplanning",MB_YESNO)==IDYES)
       {
        btSaveClick(Sender);
       }

   }
 Close();        
}
//---------------------------------------------------------------------------
