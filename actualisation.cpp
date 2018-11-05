//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "actualisation.h"
#include <stdio.h>
#include <dir.h>
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TActual *Actual;
//---------------------------------------------------------------------------
__fastcall TActual::TActual(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TActual::MonthCalendar1Click(TObject *Sender)
{
 Edit1->Text = MonthCalendar1->Date;
 eFile->Text = "";
 newfile = true;
}
//---------------------------------------------------------------------------
void __fastcall TActual::Button2Click(TObject *Sender)
{
char tmp[10];
 // AVANC_DEL = true;
 strcpy(m_exchange,"<null>TRUE</null>");
 Close();
}
//---------------------------------------------------------------------------


void __fastcall TActual::FormClose(TObject *Sender, TCloseAction &Action)
{
 Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TActual::Button1Click(TObject *Sender)
{
  char tmp[200]; AnsiString LastAct;
  int indx,idx;

  idx=ListBox1->Items->Count;

  indx = ListBox1->ItemIndex;
  if (indx <0) { Beep(); return; }

  if (idx==0) return;
  if (idx==1) indx = 0;

  if (indx <0 ) indx = idx-1;
  if (indx <0) return;


  //if (indx != 0)
  //    {
       LastAct=ListBox1->Items->Strings[idx-1];  // indx
       eFile->Text = LastAct;
  //  }

    /*
    else //{ Beep(); return; }
     {
      LastAct=ListBox1->Items->Strings[0];
       eFile->Text = LastAct;
     }
    */

  strcpy(tmp,eFile->Text.c_str());
  if (strlen(tmp)==0)
    {
     Application->MessageBoxA("Pas de fichier sélectionné",m_ecoplan,MB_OK);
     return;
    }
  AVANC_DEL = false;
  FIRST_AVANC=false;




  FillListBox();
  newfile=false;
  if (indx == idx-1) SAISIE_AVANC = true;
  else SAISIE_AVANC = false;

  Exec_Finish();
}


void __fastcall TActual::Exec_Finish()
{
 // preparer exchange 1
 char tmp[250]; int i,cnt;
 char mtemp[200];  char *p; char txt[300];
 char mess[250];  char fmt[50];
  char A[10],M[10],J[10],N[10];
  int  l,a,m,j,n; int dist;

 if (newfile)
    {
     strcpy(tmp,Edit1->Text.c_str());
     if (strlen(tmp) != 10)
       {
        Application->MessageBox("Format de date doit être JJ/MM/AAAA",ecoplan,MB_OK);
        return;
       }
      A[2]=0; M[2]=0; J[2]=0;
      A[0]=tmp[8]; A[1]=tmp[9];   a=atoi(A);
      M[0]=tmp[3]; M[1]=tmp[4];   m=atoi(M);
      J[0]=tmp[0]; J[1]=tmp[1];   j=atoi(J);

      if (m<0 || m>12) { Application->MessageBox("Mois Incorrect",ecoplan,MB_OK); return; }
      if (j<0 || j>31) { Application->MessageBox("Jour Incorrect",ecoplan,MB_OK); return; }
      if (m==2 && j>29) { Application->MessageBox("Jour Incorrect",ecoplan,MB_OK); return; }
      if ((m==4 || m==6 || m==9 || m==11) && j>29) { Application->MessageBox("Jour Incorrect",ecoplan,MB_OK); return; }
     // verifier distance
     dist = a*365+m*31+j;
     if (dist <=DISTLAST)
       {
        Application->MessageBox("Date inférieure à la dernière actualisation",ecoplan,MB_OK);
        return;
       }

    }

 if (!newfile)
 {
  if (SAISIE_AVANC == true)
    {
     eFile->Text = AnsiString(lastfile);
     strcpy(txt,lastfile);
     l=strlen(txt);
     if (l<12) { Beep(); return; }
     }
  else
    {
     eFile->Text = FileSelected;
     strcpy(txt,FileSelected.c_str());
    }

 strcpy(tmp,txt);
 p=strstr(tmp,".act");
 n=0;
 if (p)
   {
    A[0] = *(p-8); A[1]= *(p-7); A[2]=0; a=atoi(A)%100;
    M[0] = *(p-5); M[1]= *(p-4); M[2]=0;   m=atoi(M);
    J[0] = *(p-2); J[1]= *(p-1); J[2]=0;   j=atoi(J);
    // Suffixe[0]=*(p-3); Suffixe[1]=*(p-2); Suffixe[2]=*(p-1); Suffixe[3]= 0;
    //n=atoi(Suffixe);
   }


 sprintf(txt,"%02d/%02d/2%03d",j,m,a);
 sprintf(DatAct,"-%02d-%02d-%02d",a,m,j);
 Edit1->Text = AnsiString(txt);
 }

 strcpy(tmp,Edit1->Text.c_str());
 if (strlen(tmp)!=10)
  {
   Application->MessageBoxA("Date Incorrecte",ecoplan,MB_OK);
   return;
  }
 strcpy(m_exchange,"<da>"); strcat(m_exchange,tmp); strcat(m_exchange,"</da><tc>");
 strcat(m_exchange,"false");
 strcat(m_exchange,"</tc><new>");
 if (newfile) strcat(m_exchange,"true");
   else strcat(m_exchange,"false");
 strcat(m_exchange,"</new>");
 if (newfile)
  {
   /*
   strcat(m_exchange,"<file>");
   strcat(m_exchange,"-");
   strcat(m_exchange,lastsuffix); strcat(m_exchange,"</file>");
   */
  }
 else
  {
   strcpy(mtemp,eFile->Text.c_str());
   p=strstr(mtemp,".act"); if (p) *p=0;


   strcat(m_exchange,"<file>"); strcat(m_exchange,DatAct); strcat(m_exchange,"</file>");
   //strcat(m_exchange,"<file>"); strcat(m_exchange,mtemp); strcat(m_exchange,"</file>");
   }
 //WriteExchange(1);
 strcpy(mess,"Fichier d'actualisation: ");
 strcat(mess,eFile->Text.c_str()); //lastfile);
 strcat(mess,"\n Date : "); strcat(mess,txt);

 if (!newfile)
  {
   if (Application->MessageBoxA(mess,m_ecoplan,MB_YESNO)==IDNO)
    return;
  }
 FillListBox();
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TActual::FormCreate(TObject *Sender)
{
 int cnt,i;
 char tmp[250];
 txt[0]=0;

 TDateTime dtPresent = Now();
 MonthCalendar1->Date = dtPresent;
 //ReadExchange(2);
 /*
 cnt=ExplodeX('@',m_exchange);
 for (i=0;i<cnt;i++)
  {
   strcpy(tmp,m_exchange2); strcat(tmp,"-"); strcat(tmp,params[i]);
   ListBox1->Items->Add(AnsiString(tmp));
  }
 */
//  FillListBox();

}
//---------------------------------------------------------------------------

int __fastcall TActual::ExplodeX(char sep,char *str)
{
 int i, count, ip;
 char c,cpred;
 if(strlen(str)==0) return 0;
 count = 0; params[count][0]=0; // indice params
 c=str[0]; cpred=0;
 i=0; ip=0;
 while (c)
  {
   cpred=c;
   if (c==sep)
     {
      params[count][ip]=0;
      count++; ip=0;
      if (count >= MAX_PARAMS) count=MAX_PARAMS-1;
     }
   else
     {
      params[count][ip]=c;
      ip++;
     }
   i++; c=str[i];
  }
 if (cpred==sep) count--;
 return (count+1);
}
void __fastcall TActual::ListBox1Click(TObject *Sender)
{

  int indx,l;
  char tmp[100];
  char A[10],M[10],J[10],N[10];
  int  a,m,j,n;  char *p;

 // extract date from item selected
  indx = ListBox1->ItemIndex;
 if (indx==-1) { FileSelected = ""; return;  }

 strcpy(txt,ListBox1->Items->Strings[indx].c_str());
 eFile->Text = AnsiString(txt);
 FileSelected =  AnsiString(txt);

 l=strlen(txt);
 if (l<12) return;
 newfile=false;
 //
 // strcpy(tmp,params[indx]);
 strcpy(tmp,txt);

 p=strstr(tmp,".act");

 if (p)
   {
    A[0] = *(p-8); A[1]= *(p-7); A[2]=0; a=atoi(A)%100;
    M[0] = *(p-5); M[1]= *(p-4); M[2]=0;   m=atoi(M);
    J[0] = *(p-2); J[1]= *(p-1); J[2]=0;   j=atoi(J);
    strcpy(lastsuffix,p-8);
    p=strstr(lastsuffix,".act"); if (p) *p=0;
   }


 sprintf(txt,"%02d/%02d/2%03d",j,m,a);
 sprintf(DatAct,"-%02d-%02d-%02d",a,m,j);
 Edit1->Text = AnsiString(txt);

}
//---------------------------------------------------------------------------

void __fastcall TActual::FormShow(TObject *Sender)
{
  strcpy(FILE_AVANC_DELETED,"");
  AVANC_DEL = false ;
  FIRST = true;
  FillListBox();
}
//---------------------------------------------------------------------------

void __fastcall TActual::FillListBox()
{
 struct ffblk ffblk;
 int done; char tmp[250];
 char dir[250];  char APrev[20],MPrev[20],JPrev[20];;
 int aprev,mprev,jprev; char mess[200];
   AnsiString FDir,FName; char Project[500];
   char *p;  char fmt[100];
   char A[10],M[10],J[10],N[10];
  int  a,m,j,n;
  int nb; int dist,maxdist;

  int maxd, distd;

 int adate,atime;  int i;   AnsiString Res;
 int year,month,day,hour,minute,second;

  sprintf(tmp,"%02d-%02d-%02d",JourPrev,MoisPrev,AnPrev%100);
  p=tmp; strcpy(JPrev,p); JPrev[2]=0;  jprev=atoi(JPrev);
  p=p+3; strcpy(MPrev,p); MPrev[2]=0;  mprev=atoi(MPrev);
  p=p+3; strcpy(APrev,p); APrev[2]=0;  aprev=atoi(APrev);
  distprev = aprev*365 + mprev*31 + jprev;


   FDir = ExtractFileDir(DatabaseName);
   strcpy(dir,FDir.c_str()); strcat(dir,"\\*.act");
   ListBox1->Clear();
   strcpy(dateavanc,"");
   nlast=0; strcpy(lastsuffix,"");
   nb=0;

 DISTLAST=0;
 nlast = 0; maxdist=0; maxd=0;
 strcpy(Project,ProjectName); strcat(Project,"-");
 done = findfirst(dir,&ffblk,0);
   while (!done)
   {
     strcpy(tmp,ffblk.ff_name);
     if (strstr(tmp,".act") && strstr(tmp,Project) && !strstr(tmp,"Copie"))
       {
        // Ajouter si meme projet
        //prepare dateavanc with existing files
        p=strstr(tmp,".act");
        if (p)
           {
            A[0] = *(p-8); A[1]= *(p-7); A[2]=0; a=atoi(A)%100;
            M[0] = *(p-5); M[1]= *(p-4); M[2]=0;   m=atoi(M);
            J[0] = *(p-2); J[1]= *(p-1); J[2]=0;   j=atoi(J);
            dist = a*365 + m*31 + j;

            if (dist <= distprev)  // <=   = pour eviter de charger l'actualisation a la date de début prévisionnel
               {
                 /*if (FIRST)
                  {
                   Beep();
                   strcpy(mess,"La date d'actualisation du fichier ");
                   strcat(mess,tmp); strcat(mess," est antérieure à la date de début de projet\n");
                   strcat(mess,"Ce fichier n'est plus accessible et doit être supprimé");
                   Application->MessageBoxA(mess,m_ecoplan,MB_OK);
                  }
                 */
               }

            else
              {
               nb++;
               ListBox1->Items->Add(AnsiString(tmp));

               sprintf(fmt,"%02d-%02d-%02d",a,m,j);
               distd = a*365 + m*31 + j;
               if (distd>DISTLAST) DISTLAST=distd;
               strcat(dateavanc,fmt); strcat(dateavanc,"@");
              }
           }

       }
      done = findnext(&ffblk);
   }
 if (nb==0)
   {
    NB_ACT=0;
    Button1->Enabled = false;
    btEff->Enabled = false;
   }
  else
   {
    NB_ACT=nb;
    Button1->Enabled = true;
    btEff->Enabled = true;
    strcpy(lastfile,ListBox1->Items->Strings[nb-1].c_str());

   }
 FIRST = false;
}


void __fastcall TActual::Button4Click(TObject *Sender)
{
newfile=true;
AVANC_DEL=false;
SAISIE_AVANC=true;
// FillListBox();
if (NB_ACT==0) FIRST_AVANC=true; else FIRST_AVANC=false;
Exec_Finish();
// Button1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TActual::btEffClick(TObject *Sender)
{
 char mess[500];    FILE *fp;
 char fname[500]; char *p;  char todelete[500];
 bool result;   int nbfiles;   char tmp[500];
 char A[10],M[10],J[10],N[10];
  int  a,m,j,n;
 //if (nlast==0) { Beep(); return; }

 nbfiles=ListBox1->Items->Count;
 if (nbfiles==0) { Beep(); return; }

 strcpy(mess,"Voulez-Vous Effacer la dernière actualisation (");
 strcat(mess,lastfile);
 strcat(mess,") ?");
 if (Application->MessageBoxA(mess,m_ecoplan,MB_YESNO)==IDNO)
     return;
 // delete fichier DON et Fichier ACT   et DBR
 strcpy(fname,lastfile);
 p=strstr(fname,".act");

 strcpy(tmp,fname);

 strcpy(lastsuffix,"");
 p=strstr(tmp,".act");

 if (p)
   {
    A[0] = *(p-8); A[1]= *(p-7); A[2]=0; a=atoi(A)%100;
    M[0] = *(p-5); M[1]= *(p-4); M[2]=0;   m=atoi(M);
    J[0] = *(p-2); J[1]= *(p-1); J[2]=0;   j=atoi(J);
    strcpy(lastsuffix,p-8);
    p=strstr(lastsuffix,".act"); if (p) *p=0;
   }

p=strstr(fname,".act");
if (p)
  {
    *p=0;
    strcat(fname,".act");
    strcpy(todelete,DatabaseName); strcat(todelete,""); strcat(todelete,"-");
    strcat(todelete,lastsuffix); strcat(todelete,".act");

    fp=fopen(todelete,"rb");
    if (fp==NULL)
     {fp=fopen(todelete,"wb"); }
     //else {
      fclose(fp);
      result = DeleteFile(AnsiString(todelete));
      if (result == true)
        {
         strcpy(FILE_AVANC_DELETED,todelete);
         AVANC_DEL = true;
        }

      // }
    strcpy(fname,lastfile);
    p=strstr(fname,".act");
    if (p)
     {
      *p=0;
      strcat(fname,".don");
      strcpy(todelete,DatabaseName); strcat(todelete,""); strcat(todelete,"-");
      strcat(todelete,lastsuffix); strcat(todelete,".don");
      fp=fopen(todelete,"rb");
      if (fp==NULL)
       {fp=fopen(todelete,"wb"); }
      //else {
      fclose(fp);
      result = DeleteFile(AnsiString(todelete));
      // }

      // unlink (todelete);
     }
   strcpy(fname,lastfile);
    p=strstr(fname,".act");
    if (p)
     {
      *p=0;
      strcat(fname,".dbr");
      strcpy(todelete,DatabaseName); strcat(todelete,""); strcat(todelete,"-");
      strcat(todelete,lastsuffix); strcat(todelete,".dbr");
      fp=fopen(todelete,"rb");
      if (fp==NULL)
       {fp=fopen(todelete,"wb"); }
      //else {
      fclose(fp);
      result = DeleteFile(AnsiString(todelete));
      // }

      // unlink (todelete);
     }



   eFile->Text = "";
  }

// Sleep(1000);
strcpy(mess,"Effacement Actualisation ");
strcat(mess,lastfile);
strcat(mess," Effectuée");
Application->MessageBoxA(mess,m_ecoplan,MB_OK);
FillListBox();

}
//---------------------------------------------------------------------------

void __fastcall TActual::Button5Click(TObject *Sender)
{
strcpy(m_exchange,"<da></da>");
Close();
}
//---------------------------------------------------------------------------

