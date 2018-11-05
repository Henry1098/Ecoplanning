//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modCsim.h"
#include "globals.h"
#include "plstd.h"
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TSimulOpen *SimulOpen;
AnsiString tempdate;
std::vector<std::string> vect3;
 std::vector<std::string> vect;
 int counter;
//---------------------------------------------------------------------------
__fastcall TSimulOpen::TSimulOpen(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

/*
void __fastcall TSimulOpen::Button2Click(TObject *Sender)
{
 char tmp[MAX_PATH];
 char fname[MAX_PATH]; char *p;
 int cnt,cntc; int i,j;
 if (OldRow==0) return;

 cnt=avsim->RowCount; cntc=avsim->ColCount;
 for (i=OldRow;i<cnt-1;i++)
   {
     for (j=0;j<cntc;j++)  avsim->Cells[j][i]=avsim->Cells[j][i+1];
   }
for (j=0;j<cntc;j++)  avsim->Cells[j][cnt-1]= "";
avsim->RowCount--;
Renum();
}
*/
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::btCreerClick(TObject *Sender)
{
 int nb;
 char tmp[100];

 Clean_Grid(avsim,2);
 Extraire_Data();

 if (rbDates->Checked==true)
   {
    if (eNombre->Text=="")
      {
       Application->MessageBoxA("Pas de Dates Spécifiées",m_ecoplan,MB_OK);
       return;
      }

    Select_Dates(eNombre->Text);
   }
 else if (rbTaches->Checked==true)
   {
    if (eTaches->Text=="")
      {
       Application->MessageBoxA("Pas de Taches Spécifiées",m_ecoplan,MB_OK);
       return;
      }
    //strcpy(tmp,eNombre->Text.c_str());
    //nb=atoi(tmp);
    //if (nb==0) return;
    //avsim->RowCount=nb+1; nbrow=nb;
    Select_Taches(eTaches->Text);
   }
 Renum();
 //Extraire_Data();
 if(rbDates->Checked == true){
 for(int i=0; i<avsim->RowCount;i++){
  avsim->Cells[1][i] =avsim->Cells[0][i];
  avsim->Cells[0][i] ="";
  }
  }else{
  for(int i=0; i<avsim->RowCount;i++)
  avsim->Cells[0][i] ="";
  }
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::Clean_Grid(TAdvStringGrid *sgrid, int strow)
{
 int r,c;
 int rr,cc;

 rr=sgrid->RowCount; cc=sgrid->ColCount;
 for (r=1;r<rr;r++) {for (c=1;c<cc;c++) sgrid->Cells[c][r]=""; }
 sgrid->RowCount=strow;
}

//---------------------------------------------------------------------------
void __fastcall TSimulOpen::Select_Dates(AnsiString dat)
{
 char tmp[2000]; int cnt,i,cmpt; int dist, dist1, dist2;
 char xdat[50];  int d;  int DistDebPrev,DistFinPrev;
 char mess[200];

 Clean_Grid(avsim,2);
 strcpy(tmp,dat.c_str());
 strcat(tmp,",");
 cmpt=0;


 sprintf(xdat,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);
 DistDebPrev=convert_date(xdat);
 sprintf(xdat,"%02d/%02d/%02d",JourFin,MoisFin,AnFin%100);
 DistFinPrev=convert_date(xdat);


 cnt = Explode(',',tmp);
 // verif des dates

 for (i=0;i<cnt;i++)
   {
    dist1 = convert_date(params[i]);
    if (dist1<DistDebPrev || dist1>DistFinPrev)
      {
       strcpy(mess,"La date "); strcat(mess,params[i]); strcat(mess," est incorrecte");
       Application->MessageBoxA(mess,"Ecoplanning",MB_OK);
       return;
      }

   }

 for (i=0;i<cnt;i++)
   {
    if (strlen(params[i]))
      {
        cmpt++; if (cmpt>1) avsim->RowCount++;
        avsim->Cells[1][cmpt]="";
        avsim->Cells[2][cmpt]="";
        avsim->Cells[2][cmpt]="";  //Période " + AnsiString(cmpt);



        avsim->Cells[3][cmpt]=AnsiString(params[i]);
        avsim->Cells[7][cmpt]=AnsiString(params[i]);
        avsim->Cells[4][cmpt]="";
        avsim->Cells[5][cmpt]="";
      }
   }
 for (i=1;i<cmpt;i++) avsim->Cells[2][i]= "Période " + AnsiString(i);

 Process_Dates();
}



void __fastcall TSimulOpen::Select_Taches(AnsiString tach)
{
 char tmp[2000],ntx[50]; int ind,cnt,i,nt,cmpt,dur;


 Clean_Grid(avsim,2);

 cmpt=0; memoTaches="";

  // Inserer date de debut

 /*
 cmpt++;  if (cmpt>1) avsim->RowCount++;
 sprintf(tmp,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);
 avsim->Cells[1][cmpt]="D";
 avsim->Cells[2][cmpt]="Début";
 avsim->Cells[3][cmpt]=AnsiString(tmp);
 avsim->Cells[4][cmpt]=avsim->Cells[3][cmpt];
 dur = Compute_Duree(avsim->Cells[3][cmpt],avsim->Cells[4][cmpt]);
 dur = 1;
 avsim->Cells[5][cmpt]=AnsiString(dur);
 */

 strcpy(tmp,tach.c_str());
 if (strlen(tmp)!=0)
  {
   strcat(tmp,",");
   cnt = Explode(',',tmp);
   for (i=0;i<=cnt;i++)
   {
    strcpy(ntx,params[i]);
    nt=atoi(ntx);
    if (nt>0)
      {
       ind=Find_Task(nt);
       if (ind>=0)
         {
          cmpt++;
          if (cmpt>1) avsim->RowCount++;
          avsim->Cells[1][cmpt]=AnsiString(Numt[ind]);
          avsim->Cells[2][cmpt]=Design[ind];



          avsim->Cells[5][cmpt]=AnsiString(Duree[ind]);
          avsim->Cells[9][cmpt]=AnsiString(Duree[ind]);



          avsim->Cells[3][cmpt]=Deb[ind];
          avsim->Cells[4][cmpt]=Fin[ind];

          avsim->Cells[7][cmpt]=Deb[ind];
          avsim->Cells[8][cmpt]=Fin[ind];

          memoTaches=memoTaches + "," + AnsiString(nt);
         }

      }
    }

  } // if strlen(tmp);



 // Inserer date de fin

 /*
 cmpt++;
 avsim->RowCount++;
  sprintf(tmp,"%02d/%02d/%02d",JourFin,MoisFin,AnFin%100);
 avsim->Cells[1][cmpt]="F";
 avsim->Cells[2][cmpt]="Fin";
 avsim->Cells[3][cmpt]=AnsiString(tmp);
 avsim->Cells[4][cmpt]= avsim->Cells[3][cmpt];
  avsim->Cells[5][cmpt]= "1";
 */
avsim->SortIndexes->Clear();
avsim->SortIndexes->Add(3);
avsim->QSortIndexed();

//  Process_Dates();
}


int __fastcall  TSimulOpen::Find_Task(int nt)
{
 int numt; int i;
 numt=-1;
 for (i=0;i<Cnt;i++)
   {
    if (Numt[i]==nt) { numt=i; break; }
   }
 return numt;
}

int __fastcall TSimulOpen::Explode(char sep,char *str)
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
     { params[count][ip]=0; count++; ip=0; if (count >= 200) count=200; }
   else
     { params[count][ip]=c;  ip++; }
   i++; c=str[i];
  }
 if (cpred==sep) count--; return (count+1);
}

void __fastcall TSimulOpen::Extraire_Data()
{
 char fn[MAX_PATH];
 char tmp[5000],ext[500];
 FILE *fp;  int lg;

 strcpy(fn,LocalBase);
 strcat(fn,"_av.txt");

 fp = fopen(fn,"r+b");
 if (fp==NULL)
   { Application->MessageBoxA("Fichier Taches non Trouvé",m_ecoplan,MB_OK);
     return;
   }
 Cnt=0;

 while (!feof(fp))
   {
    tmp[0]=0;
    fgets(tmp,4000,fp);
    lg = strlen(tmp);
    if (lg>10)
     {
      ExtractValue(ext,tmp,"c01",0);
      Numt[Cnt]=atoi(ext);
      ExtractValue(ext,tmp,"c02",0);
      Design[Cnt]=AnsiString(ext);
      ExtractValue(ext,tmp,"c03",0);
      Duree[Cnt]=atoi(ext);
      ExtractValue(ext,tmp,"c04",0);
      Deb[Cnt]=AnsiString(ext);
      ExtractValue(ext,tmp,"c05",0);
      Fin[Cnt]=AnsiString(ext);

      ExtractValue(ext,tmp,"c38",0);
      DistDeb[Cnt]= atoi(ext);
      ExtractValue(ext,tmp,"c39",0);
      DistFin[Cnt]= atoi(ext);


      ExtractValue(ext,tmp,"c41",0);
      Criter[Cnt][0]=AnsiString(ext);
      ExtractValue(ext,tmp,"c42",0);
      Criter[Cnt][1]=AnsiString(ext);
      ExtractValue(ext,tmp,"c43",0);
      Criter[Cnt][2]=AnsiString(ext);
      ExtractValue(ext,tmp,"c44",0);
      Criter[Cnt][3]=AnsiString(ext);
      ExtractValue(ext,tmp,"c45",0);
      Criter[Cnt][4]=AnsiString(ext);
      ExtractValue(ext,tmp,"c46",0);
      Criter[Cnt][5]=AnsiString(ext);
      ExtractValue(ext,tmp,"c47",0);
      Criter[Cnt][6]=AnsiString(ext);
      ExtractValue(ext,tmp,"c48",0);
      Criter[Cnt][7]=AnsiString(ext);
      Cnt++;
     }
   }
 fclose(fp);
}

void __fastcall TSimulOpen::Process_Dates()
{
 int cnt,i,d,dist, dist1,dist2;
 char xdat[50]; char tmp[200];


 avsim->SortIndexes->Clear();
 avsim->SortIndexes->Add(3);
 avsim->QSortIndexed();

 //  avsim->QSort();

 cnt=avsim->RowCount;
 for (i=1;i<cnt;i++)   //  -1
   {

    sprintf(tmp," Période %d",i);
    avsim->Cells[2][i]=AnsiString(tmp);

    strcpy(xdat,avsim->Cells[3][i].c_str());
    dist1=convert_date(xdat);
    dist1=avance_conges(dist1,1);
    add_jour(AnPrev,MoisPrev,JourPrev,dist1);
    sprintf (tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
    avsim->Cells[3][i]=AnsiString(tmp);

    if (i<cnt-1)avsim->Cells[4][i]=avsim->Cells[3][i+1];
   else
     {
      sprintf(tmp,"%02d/%02d/%02d",JourFin,MoisFin,AnFin%100);
     avsim->Cells[4][i]=AnsiString(tmp); 
     }
    strcpy(xdat,avsim->Cells[4][i].c_str());
    // if (strlen(xdat)==0) strcpy(
    dist2=convert_date(xdat);
    if (avsim->Cells[3][i]!=avsim->Cells[4][i])
      {
        if (i<cnt-2) dist=recule_temps(dist2,1,1);   // recule 1 jour
        else dist=dist2;
        add_jour(AnPrev,MoisPrev,JourPrev,dist);
        sprintf (tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
        avsim->Cells[4][i]=AnsiString(tmp);

        // calculer la duree entre  dist1 et dist, en tenant compte du calendrier
        d = nbjt(dist1,dist);
        avsim->Cells[5][i]=AnsiString(d);
      }
    else  avsim->Cells[5][i]= "1";  // durée 1;
   }
 avsim->RowCount--;
}

void __fastcall TSimulOpen::Fill_AvSort(int col)
{


}

int  __fastcall TSimulOpen::Compute_Duree(AnsiString deb,AnsiString end)
{
 char xdat[20]; int dist1,dist,dist2;
 int d;

 strcpy(xdat,deb.c_str());
 dist1=convert_date(xdat);
 dist1=avance_conges(dist1,1);

 strcpy(xdat,end.c_str());
 dist2=convert_date(xdat);
 dist=recule_temps(dist2,1,1);   // recule 1 jour

 d = nbjt(dist1,dist);
 return d;
}


//---------------------------------------------------------------------------

void __fastcall TSimulOpen::avsimClickCell(TObject *Sender, int ARow,
      int ACol)
{
 OldCol=ACol;
 OldRow=ARow;
 MemCell=avsim->Cells[ACol][ARow];
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::FormCreate(TObject *Sender)
{
 int i; char tmp[500];char d1t[500], d2t[500];
 AnsiString d1, d2;
 strcpy(m_saveAV,"GO");
 for (i=0;i<3000;i++)
   {
    Numt[i]=0;
    Design[i]="";
    Duree[i]=0;
    Deb[i]="";
    Fin[i]="";
   }
 memoTaches="";memoDates="";memoCrit="";
 strcpy(CurrentSim,"");
 strcpy(m_simul,"");
 loaded=false;

 sprintf(tmp,"%02d/%02d/%02d,%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100,
 JourFin,MoisFin,AnFin%100);

 eNombre->Text=AnsiString(tmp);
 memoDates=AnsiString(tmp);
 sprintf(tmp,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev);
 MonthCalendar1->Date = AnsiString(tmp);
 counter=0;

}
//---------------------------------------------------------------------------

int __fastcall TSimulOpen::ExtractValue(char *result, char *buff, char *tag, int posdeb)
{
 char tmp[250];
 char *p,*p1,*p2;
 int pos,l;

 result[0]=0;
 strcpy(tmp,"<"); strcat(tmp,tag); strcat(tmp,">");
 p = strstr(buff,tmp);
 l=0;
 if (p)
   {
    strcpy(tmp,"</"); strcat(tmp,tag); strcat(tmp,">");
    p1= strstr(buff,tmp);
    if (p1)
      {
       p2=p + strlen(tag)+2; l= p1-p2;
       strncpy(result,p2,l);
       result[l]=0;
      }
   }
 return l;
}
void __fastcall TSimulOpen::Button12Click(TObject *Sender)
{

Close();
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::Button3Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::btSaveClick(TObject *Sender)
{
 char name[256]; char tmp[12000]; char comment[1000];
 char *p; int cntrow,cntcol,i,j; char dbname[MAX_PATH];
 FILE *fp;

 if (Edit1->Text == "")
   {
    strcpy(dbname,DatabaseName); strcat(dbname,"*.sim");
    Application->MessageBoxA("Vous devez remplacer le caractère '*' par un suffixe de votre choix",m_ecoplan,MB_OK);
   }
  else
   {
    strcpy(dbname,Edit1->Text.c_str());
   }

   SaveDialog1->FileName = AnsiString(dbname);  //"*.sim";
   SaveDialog1->InitialDir = AnsiString(DatabaseName);
   SaveDialog1->Title = "Liste Simulateurs";
   if (SaveDialog1->Execute())
          {
            strcpy(name,SaveDialog1->FileName.c_str());
            if (FileExists(SaveDialog1->FileName))
              {
               strcpy(tmp,"Le Fichier "); strcat (tmp,SaveDialog1->FileName.c_str());
               strcat(tmp," Existe Déja. Voulez vous le remplacer ? ");
               if (Application->MessageBoxA(tmp,m_ecoplan,MB_YESNO)==IDNO) return;
              }

             Edit1->Text = SaveDialog1->FileName;
             lName->Caption = SaveDialog1->FileName;
            strlwr(name);
            fp=fopen(name,"w+b");
            if (fp==NULL)
              {Application->MessageBoxA("Impossible de Sauvegarder. Fichier déjà ouvert",m_ecoplan,MB_OK);
               return;
              }

            strcpy(CurrentSim,name);

            // 1st record = parametres generaux
            strcpy(tmp,"<rb>");
            // if (rbCrit->Checked==true) strcat(tmp,"rb1");
            // else
            if(rbDates->Checked==true) strcat(tmp,"rb2");
            else if (rbTaches->Checked==true) strcat(tmp,"rb3");
            strcat(tmp,"</rb>");
            // strcat(tmp,"<cr>"); strcat(tmp,eCrit->Text.c_str()); strcat(tmp,"</cr>");
            strcat(tmp,"<nb>"); strcat(tmp,eNombre->Text.c_str()); strcat(tmp,"</nb>");
            strcat(tmp,"<tch>"); strcat(tmp,eTaches->Text.c_str()); strcat(tmp,"</tch>");

            strcat(tmp,"<cm>"); mComment->GetTextBuf(comment,999);
            p = strstr(comment,"\r"); if (p) *p=0;
            p = strstr(comment,"\n"); if (p) *p=0;
            strcat(tmp,comment);strcat(tmp,"</cm>\n");
            fputs(tmp,fp);
            cntrow=avsim->RowCount;
            cntcol=avsim->ColCount;
            for (i=1;i<cntrow;i++)
              {
               strcpy(tmp,"");
               for (j=0;j<cntcol;j++)
                 { sprintf(comment,"<c%02d>%s</c%02d>",j,avsim->Cells[j][i].c_str(),j);
                   strcat(tmp,comment);
                 }
               strcat(tmp,"\n");
               fputs(tmp,fp);
              }
            fclose(fp);
          }
  loaded=true;

}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::Button10Click(TObject *Sender)
{
 FILE *fp; bool first; char tmp[5000],comment[2000];
 int nbcol,nbrow,j;  char icol[20];
 int dist1,dist2; char dat[50];
 strcpy(tmp,DatabaseName); strcat(tmp,"*.sim");

 strcpy(tmp,"*.sim");

OpenDialog1->FileName = AnsiString(tmp);  //"*.sim";
OpenDialog1->InitialDir = AnsiString(DatabaseName);
  if (OpenDialog1->Execute())
       {
         if (FileExists(OpenDialog1->FileName))
          {
            strcpy(name,OpenDialog1->FileName.c_str());
            lName->Caption = OpenDialog1->FileName;
            Edit1->Text = lName->Caption;
          }
          else {Beep(); return; }
  fp=fopen(name,"r+b");
  if (fp==NULL) return;
  strcpy(CurrentSim,name);
  Clean_Grid(avsim,2);
  first=true;  nbcol=avsim->ColCount;nbrow=0;
  while (!feof(fp))
   {
    strcpy(tmp,"");
    fgets(tmp,4800,fp);
    if (strlen(tmp) > 20)
      { if (first)
       { first=false;
        ExtractValue(comment,tmp,"rb",0);
        // if (strcmp(comment,"rb1")==0)  rbCrit->Checked=true;
        if (strcmp(comment,"rb2")==0) { rbDates->Checked=true; rbTaches->Checked = false; }
        if (strcmp(comment,"rb3")==0)  { rbTaches->Checked=true; rbDates->Checked=false; }
        // ExtractValue(comment,tmp,"cr",0); eCrit->Text=AnsiString(comment);
        ExtractValue(comment,tmp,"nb",0); eNombre->Text = AnsiString(comment);
        ExtractValue(comment,tmp,"tch",0); eTaches->Text = AnsiString(comment);
        ExtractValue(comment,tmp,"cm",0); mComment->SetTextBuf(comment);
       }
      else
        {
        nbrow++;
        if (nbrow > 1) avsim->RowCount++;
        for (j=0;j<nbcol;j++)
          {
           sprintf(icol,"c%02d",j);
           ExtractValue(comment,tmp,icol,0); avsim->Cells[j][nbrow]=AnsiString(comment);
           if (j==7 && avsim->Cells[j][nbrow]=="") avsim->Cells[7][nbrow]=avsim->Cells[3][nbrow];
           if (j==8 && avsim->Cells[j][nbrow]=="") avsim->Cells[8][nbrow]=avsim->Cells[4][nbrow];
           if (j==9 && avsim->Cells[j][nbrow]=="") avsim->Cells[9][nbrow]=avsim->Cells[5][nbrow];
           if (j==11 && avsim->Cells[j][nbrow]=="") avsim->Cells[11][nbrow]=100;
           if (j==12 && avsim->Cells[j][nbrow]=="") avsim->Cells[12][nbrow]=0;
          }
           strcpy(dat,avsim->Cells[7][nbrow].c_str());
           dist1=convert_date(dat);   avsim->Cells[6][nbrow]=dist1;

           strcpy(dat,avsim->Cells[8][nbrow].c_str());
           dist2=convert_date(dat);   avsim->Cells[10][nbrow]=dist2;
        }
      } // If strlen

    }
 fclose(fp);
 loaded=true;
 Renum();
  } // if execute
}
//---------------------------------------------------------------------------


void __fastcall TSimulOpen::avsimCanEditCell(TObject *Sender, int ARow,
      int ACol, bool &CanEdit)
{
 if (ARow==0) {CanEdit=false; return; }
 if (ACol==8 || ACol==9 || ACol==11 || ACol==2) { CanEdit=true; return; }
 CanEdit=false;
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::avsimCellValidate(TObject *Sender, int ACol,
      int ARow, AnsiString &Value, bool &Valid)
{
 char tmp[50];  int dist1,dist2,dur;

 Valid=false;
 if (avsim->Cells[2][1]=="") return;


 if (ACol==8)
    {
      strcpy(tmp,Value.c_str());
      dist2 = convert_date(tmp);
      strcpy(tmp,avsim->Cells[5][ARow].c_str()); dur = atoi(tmp);
      dist1=dist2 - dur;
      if (dist1 < 0)
       {
         Application->MessageBoxA("Date de début située avant le début prévisionnel","Ecoplanning",MB_OK);
         Valid=false;
       }
       else  Valid=true;
    }
 if (ACol==2) { Valid=true;  }

 if (ACol==9)   // Durée
    {
     Valid=true;
    }
 if (ACol==11)  // pourcentage
    {
     Valid=true;
    }

 if (Valid)
   { if (rbDates->Checked)  Simule(ARow,ACol);    // simulation Periode
     if (rbTaches->Checked) Simule_Taches(ARow,ACol);
   }
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::Simule(int row, int col)
{
 int cum; int nbrow,i; int a;
 char tmp[100]; int dist1,dist2,dur,durnew;
 int percent;  char dprev[15];
 char xdat[50];  int DistDebPrev; int xcal;
 char dt1[20],dt2[20];  int DUR;   int x,y;

// sprintf(dprev,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);



 strcpy(tmp,avsim->Cells[7][row].c_str());
 dist1 = convert_date(tmp);
 avsim->Cells[6][row]=dist1;
 strcpy(tmp,avsim->Cells[8][row].c_str());
 dist2 = convert_date(tmp);
 avsim->Cells[10][row]=dist2;
 // Make Date with Previsionnel

 sprintf(xdat,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);
 DistDebPrev=convert_date(xdat);


 switch(col)
  {
   case 8:  // date de fin
   // compute Date de debut => Durée => Pourcentage.. jour
   strcpy(tmp,avsim->Cells[8][row].c_str());
   dist2 = convert_date(tmp);


   strcpy(tmp,avsim->Cells[5][row].c_str()); dur = atoi(tmp);
   dist1=dist2 - dur;
   avsim->Cells[6][row]=dist1;
   xcal=1;
   x=recule_conges(dist2,xcal);
   y=recule_temps(x,xcal,dur) - 1;

   if (y<0)
     {
      Application->MessageBox("Date de début inférieure au début de projet",m_ecoplan,MB_OK);
      return;
     }

   avsim->Cells[10][row]=dist2;

   add_jour(AnPrev,MoisPrev,JourPrev,y);
   sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);

   avsim->Cells[7][row]=AnsiString(tmp);
   avsim->Cells[11][row]=100;
   avsim->Cells[12][row]=0;
   break;

   case 9:  // duree
   // calcule nlle date de fin, et pourcentage .. jour
   avsim->Cells[7][row]=avsim->Cells[3][row];
   strcpy(tmp,avsim->Cells[7][row].c_str());
   dist1 = convert_date(tmp);

   // NOUVEAU
   strcpy(dt1,avsim->Cells[7][row].c_str());

   strcpy(tmp,avsim->Cells[5][row].c_str()); dur = atoi(tmp);
   strcpy(tmp,avsim->Cells[9][row].c_str()); durnew = atoi(tmp);
   dist2=dist1+durnew+1;
   avsim->Cells[10][row]=dist2;
   xcal=1;

   x=avance_conges(dist1,xcal);
   y=avance_temps(x,xcal,durnew);
   add_jour(AnPrev,MoisPrev,JourPrev,y-1);


   // add_jour(AnPrev,MoisPrev,JourPrev,dist2);
   sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
   avsim->Cells[8][row]=AnsiString(tmp);
   percent = (durnew * 100) / dur;
   avsim->Cells[11][row]=percent;

   avsim->Cells[12][row]=durnew-dur;
   break;

   case 11:  // pourcentage
   // calcule nlle duree, date de fin,
   xcal=1;
   strcpy(tmp,avsim->Cells[5][row].c_str()); dur = atoi(tmp);
   strcpy(tmp,avsim->Cells[11][row].c_str()); percent = atoi(tmp);
   durnew = (percent*dur) / 100;
   avsim->Cells[9][row]=durnew;
   dist2=dist1+durnew+1;
   x=recule_conges(dist2,xcal);
   y=recule_temps(x,1,1);   // recule 1 jour
   avsim->Cells[10][row]=y; // dist2;
   add_jour(AnPrev,MoisPrev,JourPrev,y);   // dist2);
   sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
   avsim->Cells[8][row]=AnsiString(tmp);
   avsim->Cells[12][row]=durnew-dur;
   break;
  }

// calcul des dates de début sur toutes les rangées
nbrow = avsim->RowCount;
for (i=2;i<nbrow;i++)     //  = 2 ?
  {
    strcpy(xdat,avsim->Cells[8][i-1].c_str());
    dist1=convert_date(xdat);
    dist1=avance_conges(dist1+1,1);
    add_jour(AnPrev,MoisPrev,JourPrev,dist1);
    sprintf (tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
    avsim->Cells[7][i]=AnsiString(tmp);
    // calcul de date de fin en fonction de la duree


    strcpy(tmp,avsim->Cells[9][i].c_str());
    if (strlen(tmp)==0)
    strcpy(tmp,avsim->Cells[5][i].c_str());
    durnew = atoi(tmp);
    dist2 = avance_temps(dist1,1,durnew);

    //dist2=dist1+durnew+1;
    //dist2=avance_conges(dist2,1);
    avsim->Cells[10][i]=dist2;
    add_jour(AnPrev,MoisPrev,JourPrev,dist2-1);
    sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
    avsim->Cells[8][i]=AnsiString(tmp);

  }



// Calcul le cumul
 cum=0;
 nbrow = avsim->RowCount;
 for (i=1;i<nbrow;i++)
   {
    strcpy(tmp,avsim->Cells[12][i].c_str());
    a=atoi(tmp);
    cum += a;
    avsim->Cells[13][i]=cum;
   }
}

void __fastcall TSimulOpen::Simule_Taches(int row, int col)
{
 int cum; int nbrow,i; int a;
 char tmp[100]; int dist1,dist2,dur,durnew;
 int percent;  char dprev[15];
 char xdat[50];   int xcal,x,y;

// sprintf(dprev,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);
 strcpy(tmp,avsim->Cells[7][row].c_str());
 dist1 = convert_date(tmp);
 avsim->Cells[6][row]=dist1;
 strcpy(tmp,avsim->Cells[8][row].c_str());
 dist2 = convert_date(tmp);
 avsim->Cells[10][row]=dist2;
 // Make Date with Previsionnel
 ;


 switch(col)
  {
   case 8:  // date de fin
   // compute Date de debut => Durée => Pourcentage.. jour
   strcpy(tmp,avsim->Cells[8][row].c_str());
   dist2 = convert_date(tmp);

   strcpy(tmp,avsim->Cells[5][row].c_str()); dur = atoi(tmp);
   dist1=dist2 - dur;

   if (dist1 < 0)
     {
      Application->MessageBoxA("Date de début située avant le début prévisionnel","Ecoplanning",MB_OK);
      avsim->Cells[8][row]=MemCell;
      return;
     }

   avsim->Cells[10][row]=dist2;
   avsim->Cells[6][row]=dist1;
   add_jour(AnPrev,MoisPrev,JourPrev,dist1);
   sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
   avsim->Cells[7][row]=AnsiString(tmp);
   avsim->Cells[11][row]=100;
   avsim->Cells[12][row]=0;
   break;

   case 9:  // duree
   // calcule nlle date de fin, et pourcentage .. jour
   avsim->Cells[7][row]=avsim->Cells[3][row];
   strcpy(tmp,avsim->Cells[7][row].c_str());
   dist1 = convert_date(tmp);

   //strcpy(tmp,avsim->Cells[8][row].c_str());
   //dist2 = convert_date(tmp);
   // avsim->Cells[10][row]=dist2;

   strcpy(tmp,avsim->Cells[5][row].c_str()); dur = atoi(tmp);
   strcpy(tmp,avsim->Cells[9][row].c_str()); durnew = atoi(tmp);
   dist2=dist1+durnew;
   avsim->Cells[10][row]=dist2;

   xcal=1;
   x=avance_conges(dist1,xcal);
   y=avance_temps(x,xcal,durnew);
   add_jour(AnPrev,MoisPrev,JourPrev,y-1);

   // add_jour(AnPrev,MoisPrev,JourPrev,dist2-1);
   sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
   avsim->Cells[8][row]=AnsiString(tmp);
   percent = (durnew * 100) / dur;
   avsim->Cells[11][row]=percent;

   avsim->Cells[12][row]=durnew-dur;
   break;

   case 11:  // pourcentage
   // calcule nlle duree, date de fin,
   strcpy(tmp,avsim->Cells[5][row].c_str()); dur = atoi(tmp);
   strcpy(tmp,avsim->Cells[11][row].c_str()); percent = atoi(tmp);
   durnew = (percent*dur) / 100;
   avsim->Cells[9][row]=durnew;
   dist2=dist1+durnew;
   dist2=recule_temps(dist2,1,1);   // recule 1 jour
   avsim->Cells[10][row]=dist2;
   add_jour(AnPrev,MoisPrev,JourPrev,dist2);
   sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
   avsim->Cells[8][row]=AnsiString(tmp);

   avsim->Cells[12][row]=durnew-dur;
   break;
  }

// calcul des dates de début sur toutes les rangées
nbrow = avsim->RowCount;

// pour 1ere rangée prendre date deb prev et ajouter la durée

for (i=1;i<nbrow;i++)     //  = 2 ?
  {

    if (i==1)
      {
       strcpy(xdat,avsim->Cells[3][1].c_str());
      }
    else
      {
        strcpy(xdat,avsim->Cells[8][i-1].c_str());
       }
    dist1=convert_date(xdat);
    dist1=avance_conges(dist1,1);
    add_jour(AnPrev,MoisPrev,JourPrev,dist1);
    sprintf (tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
    avsim->Cells[7][i]=AnsiString(tmp);
    // calcul de date de fin en fonction de la duree


    strcpy(tmp,avsim->Cells[9][i].c_str());
    if (strlen(tmp)==0)
    strcpy(tmp,avsim->Cells[5][i].c_str());
    durnew = atoi(tmp);
    dist2 = avance_temps(dist1,1,durnew);

    //dist2=dist1+durnew+1;
    //dist2=avance_conges(dist2,1);
    avsim->Cells[10][i]=dist2;
    add_jour(AnPrev,MoisPrev,JourPrev,dist2-1);
    sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
    avsim->Cells[8][i]=AnsiString(tmp);

  }



// Calcul le cumul
 cum=0;
 nbrow = avsim->RowCount;
 for (i=1;i<nbrow;i++)
   {
    strcpy(tmp,avsim->Cells[12][i].c_str());
    a=atoi(tmp);
    cum += a;
    avsim->Cells[13][i]=cum;
   }
}



int  __fastcall TSimulOpen::comp_dist_dates(char *dt1, char *dt2, int calx,int offset)   // date8
{
 Word a1,a2,m1,m2,j1,j2;
 char d1[15],d2[15];
 int dist1,dist2,i;
 int annee20; int borne1; int borne2;


 if (strlen(dt1)==10) { dt1[6]=dt1[8]; dt1[7]=dt1[9]; dt1[10]=0;  dt1[8]=0; }
 if (strlen(dt2)==10) { dt2[6]=dt2[8]; dt2[7]=dt2[9]; dt2[10]=0;  dt2[8]=0; }
 if (strlen(dt1)==0) sprintf(dt1,"%02d-%02d-%02d",JourPrev,MoisPrev,AnPrev%100);
 if (strlen(dt2)==0) sprintf(dt2,"%02d-%02d-%02d",JourPrev,MoisPrev,AnPrev%100);
 if (strlen(dt1)!=8) sprintf(dt1,"%02d-%02d-%02d",JourPrev,MoisPrev,AnPrev%100);
 if (strlen(dt2)!=8) sprintf(dt2,"%02d-%02d-%02d",JourPrev,MoisPrev,AnPrev%100);
 if (strlen(dt1) != 8)
   {
    Application->MessageBoxA("Format Date Incorrect",m_ecoplan,MB_OK);
    return 0;
   }
 if (strlen(dt2) != 8)
   {
    Application->MessageBoxA("Format Date Incorrect",m_ecoplan,MB_OK);
    return 0;
   }
 strcpy(d1,dt1); strcpy(d2,dt2);
 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 d2[2]=0; j2=atoi(d2);  d2[5]=0; m2=atoi(d2+3);  d2[8]=0; a2=atoi(d2+6);

 if (cal !=0)  // on elargit les dates, et on calcule
   {
    annee20=2000+a1; dist1 = convert_date(dt1); //dist1=convert_date(annee20,m1,j1);
    annee20=2000+a2; dist2 = convert_date(dt2); //convert_date(annee20,m2,j2);
    NB1 = dist2-dist1+offset;
    NB3=NB1;
     if (NB1 < 0)  { borne1=dist2; borne2=dist1; }
     else {borne1=dist1; borne2=dist2; }
    // calcul de NB2 en fonction du calendrier
    NB2=0;
    for (i=borne1; i < borne2 ; i++)
      {
       if (cal[calx][i] == 'T') NB2++;
      }
   }

 if (a2>a1) return 1;
 if (a2<a1) return -1;

 if (m2>m1) return 1;
 if (m2<m1) return -1;

 if (j2>j1) return 1;
 if (j2<j1) return -1;
 return 0;
}




int  __fastcall TSimulOpen::convert_date(char *dat)
{
 int n1,n2,bcl,N;
 int initval,year,month,day;
 char dt[20];

 dt[0]=dat[0]; dt[1]=dat[1]; dt[2]=0;  day=atoi(dt);
 dt[0]=dat[3]; dt[1]=dat[4]; dt[2]=0;  month=atoi(dt);
 dt[0]=dat[6]; dt[1]=dat[7]; dt[2]=0;  year=atoi(dt)+2000;

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


int  __fastcall TSimulOpen::add_jour(int year, int month, int day, int jours)
{
  // resultats dans An,Mois,Jour
  int i,counter,nbj_restant, j;
  int nbdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  An=year;Mois=month;Jour=day;
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


 void __fastcall TSimulOpen::Renum()
{
 int i,cnt;
 cnt=avsim->RowCount;
 for (i=1;i<cnt;i++) avsim->Cells[0][i]=i;
}

/*
void __fastcall TSimulOpen::Button9Click(TObject *Sender)
{

 OpenDialog1->FileName = "*.sim";
 OpenDialog1->InitialDir = AnsiString(DatabaseName);
 if (OpenDialog1->Execute())
       {
         if (FileExists(OpenDialog1->FileName))
          {
            strcpy(name,OpenDialog1->FileName.c_str());
            if (Application->MessageBoxA("Voulez-Vous Supprimer Le fichier ?",m_ecoplan,
                MB_YESNO)==IDNO) return;
            unlink(name);

          }
          else {Beep(); return; }
        }
}

*/
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::btSupprClick(TObject *Sender)
{

 /*
 OpenDialog1->FileName = "*.sim";
 OpenDialog1->InitialDir = AnsiString(DatabaseName);
 if (OpenDialog1->Execute())
       {
         if (FileExists(OpenDialog1->FileName))
          {
            strcpy(name,OpenDialog1->FileName.c_str());
            if (Application->MessageBoxA("Voulez-Vous Supprimer Le fichier ?",m_ecoplan,
                MB_YESNO)==IDNO) return;
            unlink(name);

          }
          else {Beep(); return; }
        }
 */
 char tmp[MAX_PATH];
 if (strlen(CurrentSim)==0)
  {
   Application->MessageBoxA("Pas de Simulateur Sauvegardé",m_ecoplan,MB_OK);
   return;
  }
 if (Application->MessageBoxA("Confirmer la suppression du Simulateur",m_ecoplan,MB_YESNO)==IDNO) return;
 unlink(CurrentSim);


}
//---------------------------------------------------------------------------


void __fastcall TSimulOpen::btLancerClick(TObject *Sender)
{
 int cnt,i;
 char tmp[250];
 char sdur[20]; int dur;
 char sper[20]; int per;
 char simul[10000];
 char numtache[100]; int numt;

 if (!loaded)
   {
    Application->MessageBoxA("Pas de simulateur Sélectionné",m_ecoplan,MB_OK);
    return;
   }

 if (Application->MessageBoxA("Voulez-vous Effectuer la Simulation ?\nVotre projet va être renommé avec un suffixe de votre choix",m_ecoplan,MB_YESNO)==IDNO) return;
 if (Application->MessageBoxA("Vous Confirmez ?",m_ecoplan,MB_YESNO)==IDNO) return;

 // preparer  m_simul et transferer a plstd
 cnt = avsim->RowCount;
 strcpy(m_simul,"");
 strcpy(simul,"");
 if (rbTaches->Checked)
    {
     strcpy(simul,"<mode>TACHES</mode>");
    }
  else
    {
     strcpy(simul,"<mode>PERIODES</mode>");

    }

 for (i=1;i<cnt;i++)
   {
    strcpy(sdur,avsim->Cells[9][i].c_str()); dur = atoi(sdur);
    strcpy(sper,avsim->Cells[11][i].c_str()); per = atoi(sper);
    strcpy(numtache,avsim->Cells[1][i].c_str()); numt = atoi(numtache);
    sprintf(tmp,"<p%03d><d>%s</d><f>%s</f><t>%d</t><p>%d</p><nt>%d</nt></p%03d>",
              i,avsim->Cells[7][i].c_str(),avsim->Cells[8][i].c_str(),dur,per,numt,i);
    strcat(simul,tmp);
   }

  strcpy(m_simul,simul);
  Close();
 }

//---------------------------------------------------------------------------

void __fastcall TSimulOpen::rbDatesClick(TObject *Sender)
{
 char tmp[2000];
 if (rbDates->Checked==true)
   {

       sprintf(tmp,"%02d/%02d/%02d,%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100,
            JourFin,MoisFin,AnFin%100);
       memoDates=AnsiString(tmp);

    eNombre->Text=memoDates;
    eTaches->Text="";
    eCrit->Text="";
   }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TSimulOpen::rbTachesClick(TObject *Sender)
{
 if (rbTaches->Checked==true)
  {
   eCrit->Text="";
   eNombre->Text="";
   eTaches->Text=memoTaches;

  }
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::avsimGetFormat(TObject *Sender, int ACol,
      TSortStyle &AStyle, AnsiString &aPrefix, AnsiString &aSuffix)
{
 switch(ACol) {

case 3: AStyle = ssShortDateEU; //  AStyle=ssDate;
break;
 }

//  AStyle=ssShortDateEU;
}
//---------------------------------------------------------------------------


int  __fastcall TSimulOpen::avance_conges(int base,int ncal)
{
 // base doit etre place sur le Premier jour a examiner
 int xdeb,xlimit;
 xdeb=base; xlimit= MAX_JOURS-1000;
 // enlever les jours feries
 if (cal[ncal][xdeb] == 'N')
   { while ((cal[ncal][xdeb]=='N')&& (xlimit>0))
      { xdeb++; xlimit--; }

   }
return xdeb;
}

int  __fastcall TSimulOpen::avance_temps(int base,int ncal,int dur)
{
  // base doit etre positionné sur le premier jour a examiner
 int xdeb,xdur,xlimit;
 xdeb=base; xdur=dur; xlimit=MAX_JOURS-1000;
 while ((xdur>0) && (xlimit > 0))
   { if (cal[ncal][xdeb]=='T') xdur--;
    xdeb++; xlimit--;
    }
return xdeb;
}

int  __fastcall TSimulOpen::recule_conges(int base,int ncal)
{

 int xdeb,xlimit;
 //  base pointe sur le jour devant celui a examiner
 // en retour c'est un pointeur sur le "premier jour de conges"
 // sinon, c'est sur base
 xdeb=base-1;xlimit=xdeb;
 // sauter les jours feries;

 if (cal[ncal][xdeb] == 'N')
   { while((cal[ncal][xdeb] == 'N') && (xlimit >= 0)) {xlimit--; xdeb--; }
   }
 xdeb++;
 return xdeb;

 }

int  __fastcall TSimulOpen::recule_temps(int base,int ncal, int dur)
{
  int xdeb, xdur, xlimit;
  // base pointe sur le jour devant celui a examiner
  xdeb=base-1; xdur=dur; xlimit=xdeb;
 xlimit=base;
 while ((xdur > 0) && (xlimit >= 0))
   {
    if (cal[ncal][xdeb] == 'T') xdur--;
    xdeb--; xlimit--;
   }
 xdeb++;
 return xdeb;
}

int __fastcall TSimulOpen::nbjt(int d1,int d2)
{
 int jt,j;
 if (d1>=d2) return 1;

 j=d1; jt=0;
 while (j<=d2)
  {
   if (cal[1][j] == 'T') jt++;
   j++;
  }
 return jt;
}
void __fastcall TSimulOpen::MonthCalendar1DblClick(TObject *Sender)
{
char tmp[50];
 AnsiString dt,d1tt,d2tt;
 char mess[200];  char xdat[50];  char d1t[500], d2t[500];
 std::vector<std::string>::iterator it;
 AnsiString nomD;
 int dist1,DistDebPrev,DistFinPrev;
 int ijk = 0;
 if (rbDates->Checked==false) return;

 dt = MonthCalendar1->Date;
 strcpy(tmp,dt.c_str());
 tmp[6]=tmp[8];
 tmp[7]=tmp[9];
 tmp[8]=0;

 strcpy(mess,"Confirmer la Nouvelle Date : "); strcat(mess,tmp);
 if (Application->MessageBoxA(mess,m_ecoplan,MB_YESNO)==IDNO) return;

 sprintf(xdat,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);
 DistDebPrev=convert_date(xdat);
 sprintf(xdat,"%02d/%02d/%02d",JourFin,MoisFin,AnFin%100);
 DistFinPrev=convert_date(xdat);
 dist1 = convert_date(tmp);
 if (dist1<DistDebPrev || dist1>DistFinPrev)
      {
     strcpy(mess,"La date "); strcat(mess,tmp); strcat(mess," est incorrecte");
       Application->MessageBoxA(mess,"Ecoplanning",MB_OK);
       return;
      }




  // trier par dates


 memoDates=memoDates+","+AnsiString(tmp);

sprintf(d1t,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);
 sprintf(d2t,"%02d/%02d/%02d",JourFin,MoisFin,AnFin%100);

 d1tt = AnsiString(d1t);
 d2tt = AnsiString(d2t);
 TDate dateDD = StrToDate(dt);
 AnsiString ddd = dateDD.FormatString(L"yy/mm/dd");


 if(!vect.empty())
 {
   it =std::find(vect.begin(),vect.end(),ddd.c_str());

 if( it !=vect.end()) {
  vect.erase(it);
    counter--;
  }else{

   vect.push_back(ddd.c_str());
  }
 }else{

  vect.push_back(ddd.c_str());
 }

std::sort(vect.begin(), vect.end());
//        sortDayMonthYear();

AnsiString a,b,c,e,f,g;

a= a+d1tt+",";

for(int k = 0; k< vect.size();k++)
{
c = (vect[k]).c_str();
TDate date = StrToDate(c).FormatString(L"yy/mm/dd");
//vect.at(k)=(DateToStr(date.FormatString(L"dd/mm/yy")).c_str());
//b=(DateToStr(date.FormatString(L"dd/mm/yy")).c_str());
AnsiString ab = date.FormatString(L"dd/mm/yy");
a=a+ab+",";

}
                              /*
for(int ij = counter; ij < vect.size();ij++)
{
 b = (vect[ij]).c_str();
 a=a+b+",";

}

                              */
a=a+d2tt;
eNombre->Text=a;
counter=counter+1;   

}
//---------------------------------------------------------------------------




void __fastcall TSimulOpen::eNombreChange(TObject *Sender)
{
 Fill_AvSort(1);
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::eTachesChange(TObject *Sender)
{
 Fill_AvSort(2);
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::eTachesClick(TObject *Sender)
{
 rbTaches->Checked=true;
 rbDates->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::eNombreClick(TObject *Sender)
{
 rbDates->Checked = true;
 rbTaches->Checked=false;
}
//---------------------------------------------------------------------------

void __fastcall TSimulOpen::Button4Click(TObject *Sender)
{
for(int i = 0; i < vect.size(); i++)
ShowMessage((vect.at(i)).c_str());
}
//---------------------------------------------------------------------------
void __fastcall TSimulOpen::sortDayMonthYear()
{
AnsiString stringA,stringB,stringJ,stringM,stringAn,stringdate,stringC;
TDate dateA;

for(int i = 0; i< vect.size(); i++)
{
   stringA = (vect[i]).c_str();
   dateA = StrToDate(stringA);
   stringB = DateToStr(dateA.FormatString(L"yy/mm/dd"));
     vect3.push_back(stringB.c_str());
}




}

void __fastcall TSimulOpen::FormDestroy(TObject *Sender)
{
vect.clear();
}
//---------------------------------------------------------------------------


