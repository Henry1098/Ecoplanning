//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>

#include "plstd.h"
#include "num_pred.h"
#include "num_succ.h"
#include "inserttask.h"
#include "copytask.h"
#include "liencc.h"
#include "tachesamont.h"
#include "affcal.h"
#include "actualisation.h"
#include "modfilter.h"
#include "modGhost.h"
#include "modCriteres.h"
#include "globals.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TplStandard *plStandard;
//---------------------------------------------------------------------------
__fastcall TplStandard::TplStandard(TComponent* Owner)
        : TForm(Owner)
{
  

}
//---------------------------------------------------------------------------
void __fastcall TplStandard::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 int recdata;
 char Key[100],RetKey[100];


  delete im;


    // avancements
   if (proj)
    {
      strcpy(Key,"<avanc>"); recdata=proj->GetNewRecordNumber();
      proj->WriteKey(0,Key,recdata);
      proj->WriteRecord(dateavanc,strlen(dateavanc)+1);
    }

 if (change)  updatedatabase(LocalBase,1,0);
 if (proj) { proj->CloseEngine(); proj->~genbase(); }

 // if(FLAG_AVANC_LOADED) { avanc->CloseEngine(); avanc->~genbase(); }

 // on signale a MainForm qu'on ferme
     strcpy(status,"<close>"); strcat(status,DatabaseName);
     strcat(status,"</close>");
 Action = caFree;
}
//---------------------------------------------------------------------------

int __fastcall TplStandard::Change1()
{
 strcpy(status,"<ch1>"); strcat(status,DatabaseName);
 strcat(status,"</ch1>");
 change=1;
 return 0;
}

int __fastcall TplStandard::Change0()
{
 strcpy(status,"<ch0>"); strcat(status,DatabaseName);
 strcat(status,"</ch0>");
 change=0;
 return 0;
}

void __fastcall TplStandard::updatedatabase(char *name, int prompt,int mode)
{
  int rc;
  int recdata;
  char buffer[2000];
  char RetKey[100];
  char Key[100];
  char tmp[2000];
  char format[500];
  int ipred,isucc;
  int ii;
  char ss[20];
  char strpred[1000],strsucc[1000];


 if (prompt==1)
  {
    if (Application->MessageBox("Voulez vous sauvegarder les modifications du projet",
        name,MB_YESNO)==IDNO) return;
   }
    rc = proj->CloseEngine(); proj->~genbase();


    strcpy(buffer,name); strcat(buffer,".dat");
    rc=unlink(buffer);
    strcpy(buffer,name); strcat(buffer,".eco");
    rc=unlink(buffer);

    proj = new genbase;
    rc = proj->OpenEngine(name,120,"eco","dat");   //512 - 8
    rc = proj->SetIndexMode(0,0);
    if (rc==0) { ShowMessage("Erreur à l'ouverture des fichiers projets"); exit (1); }

    // titre de la base
     strcpy(Key,"<dbtitre>"); recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     rc = proj->WriteRecord(dbtitre,strlen(dbtitre)+1);


    // avancements
     if (mode) dateavanc[0]=0;
     strcpy(Key,"<avanc>"); recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     rc = proj->WriteRecord(dateavanc,strlen(dateavanc)+1);

     strcpy(Key,"<oldavanc>");recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     rc = proj->WriteRecord(FileNameAvanc,strlen(FileNameAvanc)+1);

    // date previsionnelle
     strcpy(Key,"<dateprevdebut>"); recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     rc = proj->WriteRecord(dateprevdeb,strlen(dateprevdeb)+1);

     // nombre de taches

     strcpy(Key,"<taches>"); recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     sprintf(tmp,"%04d",nb_taches);
     rc = proj->WriteRecord(tmp,strlen(tmp)+1);


    // Taches par defaut

    for (int i=1;i<=nb_taches;i++)         //§§§§§§§§§§§§§§§§§§§§§
      {
       ii=sommets[i];

       //  predecesseurs,
       strcpy(strpred,"|");
       sprintf(Key,"<PR%04d>",ii);
       recdata=proj->GetNewRecordNumber();
       rc = proj->WriteKey(0,Key,recdata);
       ipred=1;
       buffer[0]=0; sprintf(buffer,"<PR%04d>",ii);
       while ((pr[i][ipred]!=0) && (ipred<PS))
         {
            sprintf(tmp,"<P%02d><num>%d</num><typ>%d</typ><decal>%d</decal></P%02d>",
               ipred,pr[i][ipred],pr_tl[i][ipred],pr_decal[i][ipred],ipred);
            strcat(buffer,tmp);
          sprintf(ss,"%d|",pr[i][ipred]);
          strcat(strpred,ss);
          ipred++;
         }

       nbpred=ipred-1;

       sprintf(tmp,"</PR%04d>",ii); strcat(buffer,tmp);
       rc = proj->WriteRecord(buffer,strlen(buffer)+1);

       //  successeurs
       sprintf(Key,"<SU%04d>",ii);
       recdata=proj->GetNewRecordNumber();
       rc = proj->WriteKey(0,Key,recdata);
       isucc=1; strcpy(strsucc,"|");
       buffer[0]=0; sprintf(buffer,"<SU%04d>",ii);
       while ((su[i][isucc]!=0)  && (isucc<PS))
         {
             sprintf(tmp,"<S%02d><num>%d</num><typ>%d</typ><decal>%d</decal></S%02d>",
               isucc,su[i][isucc],su_tl[i][isucc],su_decal[i][isucc],isucc);
            strcat(buffer,tmp);
            sprintf(ss,"%d|",su[i][isucc]);
            strcat(strsucc,ss);
          isucc++;
         }
       nbsucc=isucc-1;
       sprintf(tmp,"</SU%04d>",ii); strcat(buffer,tmp);
       rc = proj->WriteRecord(buffer,strlen(buffer)+1);


       sprintf(Key,"<T%04d>",ii);
       recdata=proj->GetNewRecordNumber();
       rc = proj->WriteKey(0,Key,recdata);



       strcpy(buffer,libel[i]);

       strcpy(format,"<T>%d</T><nom>%s</nom><duree>%d</duree><cal>%d</cal><mom>%d</mom>");
       strcat(format,"<ct>%s</ct><da>%s</da><dtr>%s</dtr><ftr>%s</ftr><pc>%d</pc><nbj>%d</nbj>");
       strcat(format,"<dds>%s</dds><dfs>%s</dfs>");
       strcat(format,"<nbpred>%d</nbpred><nbsucc>%d</nbsucc>");
       strcat(format,"<pred>%s</pred><succ>%s</succ>");
       sprintf(tmp,format,
              ii,buffer,duree[i],tcal[i],tmom[i],codetache[i],da[i],dtr[i],ftr[i],
              pc[i],nbj[i],dds[i],dfs[i],nbpred,nbsucc,strpred,strsucc);
       rc = proj->WriteRecord(tmp,strlen(tmp)+1);

     }      // boucle for

     proj->CloseEngine();
     proj = new genbase;
     rc = proj->OpenEngine(name,120,"eco","dat");   //512 - 8
     rc = proj->SetIndexMode(0,0);

   Change0();
   Application->MessageBoxA("Sauvegarde effectuée",m_ecoplan,MB_OK);
}

int __fastcall TplStandard::exist_tache (int t,int range)
{
 int i,ret;

 ret=0;
 for (i=1;i<=range+1;i++)           // nb_taches
   {
    if (t==sommets[i]) ret=i;
   }
 return ret;
}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

int __fastcall TplStandard::Explode(char sep,char *str)
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
     { params[count][ip]=0; count++; ip=0; if (count > 49) count=49; }
   else
     { params[count][ip]=c;  ip++; }
   i++; c=str[i];
  }
 if (cpred==sep) count--; return (count+1);
}

void __fastcall TplStandard::Load_Fields()
{
 FILE *fp;
 char tmp[250];
 int col,row;
 char *p;

 strcpy(tmp,m_directory); strcat(tmp,"\\champs.txt");
 fp=fopen(tmp,"r+b");
 //fp = fopen("champs.txt","r+b");
 if (!fp) return;
 while (!feof(fp))
   {
    tmp[0]=0;
    fgets(tmp,99,fp);
    strcat(tmp,",");
    Explode(',',tmp);
    col=atoi(params[0]);
    row=atoi(params[1]);
    if (row>0)
     {  p=strstr(params[2],"\r"); if (p) *p=0;
        if (col==2) strcpy(ch_cod[row],params[2]);   // Code Champ
        if (col==3) strcpy(ch_des[row],params[2]);   // Désignation
        if (col==4) strcpy(ch_abb[row],params[2]);   // Abbreviation
        if (col==5) strcpy(ch_typ[row],params[2]);   // Type
        if (col==6) strcpy(ch_sai[row],params[2]);   // Saisie OUI/NON
        if (col==13) strcpy(ch_esp[row],params[2]);  // Largeur dans la grille
       }
  }
 fclose(fp);
}

int  __fastcall TplStandard::getvalue(int vol, int row, int ch)
{
 AnsiString val1; int col,x;
 TAdvStringGrid *avs;
// obtient valeur en fonction du champ systeme adv (valeur en retour stockee
// dans char retvalue; la colonne est calculée en fonction du champ
if (vol==4) avs=AdvStringGrid4;
else if (vol==6) avs=AdvStringGrid5;
else if (vol==5) avs= asAvanc;
else if (vol==1) avs=AdvStringGrid1;
else if (vol==2) avs=AdvStringGrid2;
else if (vol==3) avs=AdvStringGrid3;
col=0;
while(col < MAX_CHP)
 {
   if (vl_chp[vol][col]==ch)break;
   col++;
 }
if (col>=MAX_CHP) {strcpy(adv,"");
Application->MessageBoxA("Get Value: erreur dans decodage des champs",m_ecoplan,MB_OK);
return 0; }
val1=avs->Cells[col][row];
strcpy(adv,val1.c_str());
x=atoi(adv);
return x;
}

int  __fastcall TplStandard::setvalue(int vol,int row, int ch, char *p)
{
 int col;
 TAdvStringGrid *avs;
 // place la valeur stockee dans char p   vers la  ligne du volet,
 // dans la colonne a calculer d'apres ch
 col=0;
if (vol==4) avs=AdvStringGrid4;
else if (vol==6) avs=AdvStringGrid5;
else if (vol==5) avs= asAvanc;
else if (vol==1) avs=AdvStringGrid1;
else if (vol==2) avs=AdvStringGrid2;
else if (vol==3) avs=AdvStringGrid3;

while(col < MAX_CHP)
 {
   if (vl_chp[vol][col]==ch)break;
   col++;
 }
if (col>=MAX_CHP) {strcpy(adv,"");
Application->MessageBoxA("SetValue : erreur dans decodage des champs",m_ecoplan,MB_OK);
return 0; }
avs->Cells[col][row]= AnsiString(p);
return 1;
}


void __fastcall TplStandard::Init_Volet(int vol,TAdvStringGrid *avs)
{
 int i; //for (i=1;i<10;i++)  SGChamps->ColWidths[i]=50;
 // lecture du fichiers des champs
 FILE *fp;
 char tmp[100];
 char filename[255];
 int col,row,cnt,nbcol,numchamp,nbchamps;
 char *p;
 int esp;


 // clean zone volets
 for (i=0;i<20;i++)  vl_chp[vol][i]=0;
  // clean Grille (libélles, texte, etc..
 avs->RowCount=2;
 nbcol = avs->ColCount;
 for (i=0;i<nbcol;i++)
   {
    avs->Cells[i][0]="";
    avs->Cells[i][1]="";
   }

 nbchamps=0;
 sprintf(filename,"%s\\Volet%03d.txt",m_directory,vol);
 fp = fopen(filename,"r+b");
 if (!fp) return;
 while (!feof(fp))
   {
    tmp[0]=0;
    fgets(tmp,99,fp);
    strcat(tmp,",");
    cnt=Explode(',',tmp);
    col=atoi(params[0]);
    row=atoi(params[1]);
    if ((row>0)&& (col>1) && (cnt>2))
     {  p=strstr(params[2],"\r"); if (p) *p=0;
        if (params[2][0]=='C') p=params[2]+1;
        numchamp=atoi(p);
        vl_chp[vol][col-2]=numchamp;
        nbchamps++;
       }
  }
 fclose(fp);

 // boucle de chargement des labels et espacement
 if (nbchamps>avs->ColCount)
   { Application->MessageBoxA("Erreur definition Volet",m_ecoplan,MB_OK);
     nbchamps=avs->ColCount;
   }
 for (i=0;i<nbchamps;i++)
   {
    numchamp = vl_chp[vol][i];
    if (numchamp > MAX_CHAMP) numchamp = 51;  // champ neutre
    // espacement
    esp=atoi(ch_esp[numchamp]);
    avs->ColWidths[i]=esp;
    // ici on fait du HTML pour indiquer saisie possible
    if (strcmp(ch_sai[numchamp],"N") != 0)
      {
       strcpy(tmp,"<FONT color=\"clGreen\">");
       strcat(tmp,ch_abb[numchamp]);
       strcat(tmp,"</FONT>");
       avs->Cells[i][0]= AnsiString(tmp);
      }

    else avs->Cells[i][0]= AnsiString(ch_abb[numchamp]);
   }
}

int __fastcall TplStandard::Extraire_Date(char *fn)
{
 char *p;
 char tmp[100];
 char an[3],mois[3],jour[3];

 p = strstr(fn,"-");
 if (p)
   { strncpy(an,p+1,2); an[2]=0; AnAvanc=atoi(an);
     strncpy(mois,p+4,2); mois[2]=0; MoisAvanc=atoi(mois);
     strncpy(jour,p+7,2); jour[2]=0;  JourAvanc=atoi(jour);
     strcpy(tmp,jour); strcat(tmp,"/");
     strcat(tmp,mois); strcat(tmp,"/");
     strcat(tmp,an);
     Label12->Caption = AnsiString(tmp);
   }
 return 0;
}

void __fastcall TplStandard::Clear_Diagram(TImage *im)
{
 TRect Diagram;
 Diagram = Rect(0,0, im->Width,im->Height);
 im->Canvas->Brush->Color = clWhite; // BgColor;
 im->Canvas->FillRect(Diagram);

}

int __fastcall TplStandard::Init_Grids()
{
 int i,j;

 Clean_Grid(AdvStringGrid1,2);
 Clean_Grid(AdvStringGrid2,2);
 Clean_Grid(AdvStringGrid3,2);
 Clean_Grid(AdvStringGrid4,2);
 Clean_Grid(AdvStringGrid5,2);
 Clean_Grid(asAvanc,2);
 // clearer les diagrammes;

 Clear_Diagram(immGantt);
 Clear_Diagram(imGantt);
 Clear_Diagram(immAct);
 Clear_Diagram(imAvanc);
 Clear_Diagram(imPort);
 Clear_Diagram(imLand);

 Clear_Diagram(imRp);
 Clear_Diagram(imRl);
 Clear_Diagram(imRScreen);
 Clear_Diagram(imPp);
 Clear_Diagram(imPl);
 Clear_Diagram(imPScreen);

return 0;
}


void __fastcall TplStandard::Load_Ecochamps()
{
 char tmp[250];  FILE *fp;
 char buff[500];

 strcpy(tmp,m_directory); strcat(tmp,"\\ecochamp.txt");
 fp=fopen(tmp,"rt");
 fgets(buff,250,fp); CNT_CHAMPS=-1;
 while (!feof(fp))
  {
   if (strlen(buff)> 5)
    {CNT_CHAMPS++;
      if (CNT_CHAMPS >= MXC) break;
     ExtractValue(tmp,buff,"L",0);
     strcpy(libchamp[CNT_CHAMPS],tmp);
     ExtractValue(tmp,buff,"C",0);
     strcpy(cnt[CNT_CHAMPS],tmp);
     ExtractValue(tmp,buff,"A",0);
     strcpy(abb[CNT_CHAMPS],tmp);
     ExtractValue(tmp,buff,"N",0);
     strcpy(cln[CNT_CHAMPS],tmp);
    }
   fgets(buff,250,fp);
  }
 fclose(fp);





}



void __fastcall TplStandard::FormCreate(TObject *Sender)
{
  char tmp[2000];
   int rc,ix;
   char RetKey[100];
   char Key[100];
   int  recdata;
   int i,j,ok,l,xval;
   int ipred,isucc;
   char delim[50];
   char tmp1[50];
   int lg,ik;
   char *p;
   int x;
   char A[10],M[10],J[10],N[10];
   char txt[250],fxname[255];
   int a,m,n,cnt;

 // fl_message=false;
 // message = CreateEvent(0,FALSE,FALSE,0);

  Timer1->Enabled=false;
  Timer2->Enabled=false;

  flag_real=false;
  flag_init=false;

  TPrinter *pt = Printer();
  im = new Graphics::TBitmap();
  im->PixelFormat =pf8bit;
  im->Height= Printer()->PageHeight; //4125; //4000;
  im->Width=  Printer()->PageWidth; //2892; //4000;



  Load_Fields();
  Init_Volet(4,AdvStringGrid4);
  Init_Volet(6,AdvStringGrid5);
  Init_Volet(5,asAvanc);
  Init_Volet(1,AdvStringGrid1);
  Init_Volet(2,AdvStringGrid2);
  Init_Volet(3,AdvStringGrid3);

  Load_Ecochamps();

  strcpy(TYPL[0],"FD");
  strcpy(TYPL[1],"FF");
  strcpy(TYPL[2],"AM");
  strcpy(TYPL[3],"DD");

 strcpy(tmp,m_directory);
 strcat(tmp,"\\coche.jpg"); // critical.bmp");
 strcpy(strcoche,"<IMG src=\"file://"); strcat(strcoche,tmp); strcat(strcoche,"\">");
 //GetCurrentDirectory(MAX_PATH,tmp);
 strcpy(tmp,m_directory);
 strcat(tmp,"\\danger.gif");
 strcpy(strdanger,"<IMG src=\"file://"); strcat(strdanger,tmp); strcat(strdanger,"\">");




  PageControl1->ActivePageIndex=0;
  TDateTime dtPresent = Now();
  DecodeDate(dtPresent, Year1, Month1, Day1);
  DecodeDate(dtPresent, Year2, Month2, Day2);
  MonthCalendar1->Date = dtPresent;
  AnPrev=2000; MoisPrev=1; JourPrev=1;

  strcpy(LocalBase,DatabaseName);
  Init_Grids();

 avanc=new genbase();
 oldavanc=new genbase();
 proj = new genbase();

 
 rc = proj->OpenEngine(LocalBase,120,"eco","dat");   //512 - 8
 rc = proj->SetIndexMode(0,0);
 if (rc==0) { ShowMessage("Erreur à l'ouverture des fichiers projets"); exit (1); }

 rc = proj->ReadDirectKey(0,"<dateprevdebut>",RetKey,&recdata);
 if (rc)  // ok : clé trouvée
  {

   rc = proj->ReadRecord(buffer,recdata);
   buffer[rc]=0;
   strcpy(dateprevdeb,buffer);
   Label7->Caption = AnsiString(dateprevdeb);
   buffer[2]=0; JourPrev=atoi(buffer);
   buffer[5]=0; MoisPrev=atoi(buffer+3);
   buffer[10]=0; AnPrev=atoi(buffer+6);  AnPrev2=An%100;
  }

 strcpy(status,"<create>");
 strcat(status,DatabaseName);
 strcat(status,"</create>");

 rc = proj->ReadDirectKey(0,"<dbtitre>",RetKey,&recdata);
 if (rc)  // ok : clé trouvée
  {
   rc = proj->ReadRecord(buffer,recdata);
   buffer[rc]=0;
   strcpy(dbtitre,buffer);
   strcpy(tmp,"Project "); strcat(tmp,LocalBase);
   strcat(tmp," "); strcat(tmp,buffer);
  }

  // nettoyage buffer avvancement
dateavanc[0]=0;

rc = proj->ReadDirectKey(0,"<avanc>",RetKey,&recdata);
 if (rc)  // ok : clé trouvée
  {
   rc = proj->ReadRecord(buffer,recdata);
   buffer[rc]=0;

   // verifie si les fichiers existent
    cnt=Explode('@',buffer);
    for (i=0;i<cnt;i++)
      { strcpy(tmp,params[i]);
        l=strlen(tmp);
        if (l>=12)
         { strncpy(N,tmp+9,3); N[3]=0; n= atoi(N);
           strncpy(A+2,tmp+6,2);  A[4]=0;  A[0]= '2'; A[1]= '0'; a=atoi(A) % 100;
           strncpy(M,tmp+3,2);  M[2]=0;  m=atoi(M);
           strncpy(J,tmp,2);  J[2]=0;   j=atoi(J);
           sprintf(txt,"-%02d-%02d-%02d-%03d",a,m,j,n);
           strcpy(fxname,LocalBase); strcat(fxname,txt); strcat(fxname,".act");
           if (FileExists(fxname))
            { strcat(dateavanc,params[i]);
              strcat(dateavanc,"@");
               }
            else dateavanc[0]=0;
         }
      }
  } // if rc

 //  lecture du nombre de taches
 nb_taches=0;
 rc = proj->ReadDirectKey(0,"<taches>",RetKey,&recdata);
 if (rc)  // ok : clé trouvée
  {
   rc = proj->ReadRecord(buffer,recdata);
   buffer[rc]=0;
   nb_taches = atoi (buffer);
  }

  for (i=0;i<=(nb_taches+10);i++)     //  &&&&&&&&&&&&
     {
      duree[i]=0; duree_reelle[i]=0; deb_plus_tot[i]=0; fin_plus_tot[i]=0;
      deb_plus_tard[i]=0; fin_plus_tard[i]=0; sommets[i]=0; coche[i]= ' '; coch[i]=' ';
      filtr[i]= ' '; tcal[i]=1; tmom[i]=0; da[i][0]=0; dtr[i][0]=0; ftr[i][0]=0;
      pc[i]=0; nbj[i]=0; codetache[i][0]=0; dds[i][0]=0; dfs[i][0]=0;
      libel[i][0]=0; retard[i]=0;

      for (j=0;j<PS;j++)
        {
         pr[i][j]=0; su[i][j]=0;
         pr_tl[i][j]=0; su_tl[i][j]=0;
         pr_decal[i][j]=0; su_decal[i][j]=0;
        }
     }


 for (ix=0;ix<MAX_T;ix++) filtr[ix]=' ';
 // Boucle de lecture des taches // chargement des tableaux
 // syntaxe pour les taxes : Clé = <T%04d>
 // <T>%d</T><nom>Tache %d</nom><duree>1</duree>",i,i);

  // faire une lecture sequentielle des cles et charger sommets
  // on remplit sommets

  rc = proj->ReadFirstKey(0,RetKey,&recdata);
  ix=0;
  while (rc)
    {  buffer[0]=0;
       rc = proj->ReadRecord(buffer,recdata);  // read record in buffer
       buffer[rc]=0;
       lg = ExtractValue(tmp,buffer,"T",0);
       if (lg)
        { ix++;
          if(ix>1) AdvStringGrid1->RowCount++;
          sommets[ix]=atoi(tmp);
          filtr[ix]='X';
          //AdvStringGrid1->Cells[1][ix]=atoi(tmp);
          ExtractValue(tmp,buffer,"nom",0);
          //AdvStringGrid1->Cells[2][ix]=tmp;
          strcpy(libel[ix],tmp);
          ExtractValue(tmp,buffer,"duree",0);
          //AdvStringGrid1->Cells[3][ix]=tmp;
          duree[ix]=atoi(tmp);
          ExtractValue(tmp,buffer,"cal",0);
          if (strlen(tmp)) tcal[ix]=atoi(tmp);
            else tcal[ix]=1;
           //AdvStringGrid1->Cells[10][ix]=tcal[ix];
          ExtractValue(tmp,buffer,"mom",0);
          if (strlen(tmp)) tmom[ix]=atoi(tmp);
            else tmom[ix]=0;
          ExtractValue(tmp,buffer,"da",0);
          if (strlen(tmp)) strcpy(da[ix],tmp); else da[ix][0]=0;
          ExtractValue(tmp,buffer,"dtr",0);
          if (strlen(tmp)) strcpy(dtr[ix],tmp); else dtr[ix][0]=0;
          ExtractValue(tmp,buffer,"ftr",0);
          if (strlen(tmp)) strcpy(ftr[ix],tmp); else ftr[ix][0]=0;
          ExtractValue(tmp,buffer,"pc",0);
          if (strlen(tmp)) pc[ix]=atoi(tmp); else pc[ix]=-1;  // pourcentage
          ExtractValue(tmp,buffer,"nbj",0);
          if (strlen(tmp)) nbj[ix]=atoi(tmp); else nbj[ix]=-1;

          ExtractValue(tmp,buffer,"dds",0);
          if (strlen(tmp)) strcpy(dds[ix],tmp);
          //AdvStringGrid1->Cells[12][ix]=tmp;
          ExtractValue(tmp,buffer,"dfs",0);
          if (strlen(tmp)) strcpy(dds[ix],tmp);
          //AdvStringGrid1->Cells[13][ix]=tmp;
        }
       rc = proj->ReadNextKey(RetKey,&recdata);
    }

  if (ix != nb_taches)
     Application->MessageBox("Anomalie sur NB_Taches","",MB_OK);

  for (ix=1;ix<=nb_taches;ix++)       // &&&&&&&&&&&&
    {
     // traitement des predecesseurs,
     // structure du record
     // Cle = P000n    Record <PR%04d> puis ... <P%02d><num>.. </num>
                                       //       <typ>..</typ>
                                       //       <decal>..</decal></P%02d>
     //                  puis  </PR%04d>

        ik=sommets[ix];  // &&&&&&&& ok on cherche pred de la tache TT, pas de sa position
        sprintf(Key,"<PR%04d>",ik);   //  build  key for predecesseurs
        rc = proj->ReadDirectKey(0,Key,RetKey,&recdata);
        if (rc)  // ok : clé trouvée
         { buffer[0]=0;
          rc = proj->ReadRecord(buffer,recdata);
          buffer[rc]=0;
          if (rc)   //  ok, record predecesseur lu
           {
            ipred=1; ok=true;
            while (ok)
              {
               sprintf(delim,"P%02d",ipred);
               l = ExtractValue(tmp,buffer,delim,0);
               if (l == 0)ok=false; // { pr[ix][ipred]=9999; ok=false; }
                else
                  {
                   l= ExtractValue(tmp1,tmp,"num",0); xval=atoi(tmp1);
                   pr[ix][ipred]= xval;
                   l= ExtractValue(tmp1,tmp,"typ",0); xval=atoi(tmp1);
                   pr_tl[ix][ipred]= xval;
                   l= ExtractValue(tmp1,tmp,"decal",0); xval=atoi(tmp1);
                   pr_decal[ix][ipred] = xval;
                   ipred++;
                  }

               if (ipred >= PS) ok=false;

              }

           }
         }



     // traitement des successeurs
      // structure du record
     // Cle = S000n    Record <SU%04d> puis ... <SP%02d><num>.. </num>
                                       //       <typ>..</typ>
                                       //       <decal>..</decal></S%02d>
     //                  puis  </SU%04d>

        sprintf(Key,"<SU%04d>",ik);   // &&&&&&&& ok build  key for successeurs
        rc = proj->ReadDirectKey(0,Key,RetKey,&recdata);
        if (rc)  // ok : clé trouvée
         { buffer[0]=0;
          rc = proj->ReadRecord(buffer,recdata);
          buffer[rc]=0;
          if (rc)   //  ok, record successeur lu
           {
            isucc=1; ok=true;
            while (ok)
              {
               sprintf(delim,"S%02d",isucc);
               l = ExtractValue(tmp,buffer,delim,0);
               if (l == 0) ok=false;  // { su[ix][isucc]=9999; ok=false; }
                else
                  {
                   l= ExtractValue(tmp1,tmp,"num",0); xval=atoi(tmp1);
                   su[ix][isucc]= xval;
                   l= ExtractValue(tmp1,tmp,"typ",0); xval=atoi(tmp1);
                   su_tl[ix][isucc]= xval;
                   l= ExtractValue(tmp1,tmp,"decal",0); xval=atoi(tmp1);
                   su_decal[ix][isucc] = xval;

                   isucc++;
                  }
               if (isucc >= PS) ok=false;
              }
           }
         }
    }  //  boucle for nb of tasks

for (ix=1;ix<=nb_taches;ix++)
 {
   if (filtr[ix]=='X')
   {
    sprintf(Key,"<T%04d>",sommets[ix]);
      rc=proj->ReadDirectKey(0,Key,RetKey,&recdata);
      if (rc)
       { buffer[0]=0;
         rc = proj->ReadRecord(buffer,recdata);
         buffer[rc]=0;
         lg = ExtractValue(tmp,buffer,"T",0);
         if(ix>1) { AdvStringGrid1->RowCount++; av->RowCount++; }
         AdvStringGrid1->Cells[1][ix]=atoi(tmp);
         av->Cells[1][ix]=atoi(tmp);
         ExtractValue(tmp,buffer,"nom",0);
         AdvStringGrid1->Cells[2][ix]=tmp;
         av->Cells[2][ix]=tmp;
         ExtractValue(tmp,buffer,"duree",0);
         AdvStringGrid1->Cells[3][ix]=tmp;
         av->Cells[3][ix]=tmp;
         ExtractValue(tmp,buffer,"cal",0);
         AdvStringGrid1->Cells[10][ix]=tcal[ix];
         av->Cells[10][ix]=tcal[ix];
         ExtractValue(tmp,buffer,"dds",0);
         AdvStringGrid1->Cells[12][ix]=tmp;
         av->Cells[12][ix]=tmp;
         ExtractValue(tmp,buffer,"dfs",0);
         AdvStringGrid1->Cells[13][ix]=tmp;
         av->Cells[13][ix]=tmp;

        }
    } // if filter
 } // boucle for



  init_calendrier();

  rc = proj->ReadDirectKey(0,"<oldavanc>",RetKey,&recdata);
 if (rc)  // ok : clé trouvée
  {

   rc = proj->ReadRecord(buffer,recdata);
   buffer[rc]=0;
   strcpy(FileNameAvanc,buffer);
   strcpy(fxname,buffer); strcat(fxname,".act");
   if (FileExists(fxname))
     {
       Extraire_Date(FileNameAvanc);
       flag_loadavanc=true;
       flag_real=false;

     }
   else
     {
      flag_loadavanc = false;
      Clean_Grid(asAvanc,2);
      flag_real=true;
     // Create_First_Real();
     }

   // extraite la date d'actualisation

  }

  Read_Criteres();
  Load_Grille_Criteres();
  // strcpy(filter,"<T>");
  for(i=1;i<=nb_taches;i++)  filtr[i]='X';
  flag_init=true;
  Timer1->Enabled = true;
  current_task=1;
  grefresh(current_task);


}
//---------------------------------------------------------------------------

void __fastcall TplStandard::Create_First_Real()
{
  char isamname[250],tmp[250];
  int x,lg,ix;
  int rc,recdata; char Key[100],RetKey[100];

  x=1;
  AnAvanc=AnPrev; MoisAvanc=MoisPrev; JourAvanc=JourPrev;
  sprintf(tmp,"%s-%02d-%02d-%02d-%03d",LocalBase,AnPrev%100,MoisPrev,JourPrev,x);
  strcpy(FileNameAvanc,tmp);
  strcpy(isamname,tmp); strcat(isamname,".act"); unlink(isamname);
  strcpy(isamname,tmp); strcat(isamname,".don"); unlink(isamname);

   rc = proj->ReadFirstKey(0,RetKey,&recdata);
  ix=0;
  while (rc)
    {  buffer[0]=0;
       rc = proj->ReadRecord(buffer,recdata);  // read record in buffer
       buffer[rc]=0;
       lg = ExtractValue(tmp,buffer,"T",0);
       if (lg)
        { ix++;
          ExtractValue(tmp,buffer,"dtr",0);
          if (!strlen(tmp)) { getvalue(1,ix,4); strcpy(tmp,adv); }
          av->Cells[21][ix]=tmp;
          ExtractValue(tmp,buffer,"ftr",0);
          if (!strlen(tmp)) { getvalue(1,ix,5); strcpy(tmp,adv); }
          av->Cells[22][ix]=tmp;
          ExtractValue(tmp,buffer,"duree",0);
          if (!strlen(tmp)) { getvalue(1,ix,3); strcpy(tmp,adv); }
          av->Cells[23][ix]=tmp;
        }

     rc = proj->ReadNextKey(RetKey,&recdata);
    }
//$$$$  Change1();
}

void __fastcall TplStandard::InitTri()
{
Remplir_asTri();
Planning_Defaut();
}


int  __fastcall TplStandard::add_select(int it)
{
 int ix; int flg;
 ix = 1;  flg=0;
 while (t_select[ix] != 0)
   {
    if (t_select[ix] == it) {flg=1; break; }

    ix++;
   }
 if (flg==0)  t_select[ix]=it;
 return 1;
}

int  __fastcall TplStandard::exist_select(int it)
{
 int retval=0;
 int ix;
 for (ix=1;ix<=nb_taches;ix++)      // &&&&&&&&&&&&
   {
    if (t_select[ix]==it) {retval=ix; break; }
   }
 return retval;
}


void __fastcall TplStandard::RemovePredSeul(int tach,int tpred)
{

  // tach et tpred sont les numeros reel de taches : pas la position dans sommets

  int it, nt,indx,ipred;
  ipred=1;
  indx=exist_tache(tach,nb_taches);  // &&&&&&&&&&
  if (indx==0) return;
     while (pr[indx][ipred] !=0)
        {
         nt=pr[indx][ipred];
         if (nt==tpred)
          {// decaler  + break;
           for (it=ipred;it<PS;it++)
             {
              pr[indx][it]=pr[indx][it+1];
              pr_tl[indx][it]=pr_tl[indx][it+1];
              pr_decal[indx][it]=pr_decal[indx][it+1];
             }
           break;
          }
         ipred++;
       }
}

void __fastcall TplStandard::RemoveSuccSeul(int tach, int tsucc)
{
 int nt,it,indx,isucc;

    // tach et tsucc sont les numeros reels, pas les position
      isucc=1;
      indx=exist_tache(tach,nb_taches);       // &&&&&&&&&&&&&&
  if (indx==0) return;
      while ((su[indx][isucc] !=0) && (su[indx][isucc] != 9999))
       {
        nt=su[indx][isucc];
        if (nt==tsucc)
          { // decaler + break;
           for (it=isucc;it<PS;it++)
             {
              su[indx][it]=su[indx][it+1];
              su_tl[indx][it]=su_tl[indx][it+1];
              su_decal[indx][it]=su_decal[indx][it+1];
             }
           break;
          }

        isucc++;
       }
}



int  __fastcall TplStandard::remove_task(int it)
{
 // examine all predecesseurs, and remove task (decalage);
 int ix,ip, xt, xtrouve;

 ix = exist_tache(it,nb_taches);
     // §§§§§§§§§§§§§§§§§§§§
 if (ix==0) return 0;
 t_pred[ix][1]=-1;
 // t_pred[it][1] = -1;
 for (ix=1;ix<=nb_taches;ix++)
    {  ip=1; xtrouve = 0;
       while (t_pred[ix][ip] !=0)
       {
        if (t_pred[ix][ip]==it) xtrouve=ip;   // xtrouve a indice

        ip++;
       }
     // si xtrouvé, on va decaler et eliminer it , ip contient n+1 predecceseurs
     if (xtrouve)
       {
        for (xt=xtrouve;xt<=ip;xt++) t_pred[ix][xt]= t_pred[ix][xt+1];

       }
    }
 return 0;   
}


int  __fastcall TplStandard::init_calendrier()
{
 TDateTime dtFirst;
 int sum, i, n_cal;
 int rc, recdata;
 char ikey[50];
 char RetKey[50];
 char buffer[255];
 AnsiString Comment;
 char tmp[250];

 //lb1->Clear();

 char days[7][15] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
  "Samedi" };
 // char months[12][15] = {"Janvier","Février","Mars","Avril","Mai","Juin","Juillet",
 //  "Aout","Septembre","Octobre","Novembre","Décembre"};
 // int nbdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if (AnPrev==0) AnPrev=2005;
  if (MoisPrev==0) MoisPrev=1;
  if (JourPrev==0) JourPrev=1;

  dtFirst = EncodeDate(AnPrev,MoisPrev,JourPrev);
  //int counter = nbdays[MoisPrev-1];
  //if (MoisPrev==2){ if (IsLeapYear(AnPrev)) counter = 29;}
  // on a besoin de savoir le 1er jour du mois
  int firstday = dtFirst.DayOfWeek();
  int dow;  // day of week
  dow = firstday-1;
  Comment = "1 er Jour Date Prev Debut " + AnsiString(dow) + " = " + AnsiString(days[dow]);
  //lb1->Items->Add(Comment);

  cals = new genbase();

  strcpy(tmp,m_directory); strcat(tmp,"\\calend");
  rc = cals->OpenEngine(tmp,56,"ndx","dat");   //64 - 8
  rc = cals->SetIndexMode(0,0);
  // calcule la longueur de la duree reelle probable
  //  Sommme(duree[i] + 2) * 2
  sum=0;
  for (i=1;i<=nb_taches;i++) sum=sum+duree[i]+2;   // §§§§§§§§§§§§§
  sum = sum + sum;

  // for (i=0;i<=NB_CAL;i++) cal[i] = new char[sum];


  for (n_cal=1;n_cal<=NB_CAL;n_cal++)
   {
    // lecture WE
    // la date prev de debut correspond au 1 er jour
    sprintf(ikey,"%02d-0000-00-00",n_cal);   // clef pour determiner WE
    rc = cals->ReadDirectKey(0,ikey,RetKey,&recdata);
    rc = cals->ReadRecord(buffer,recdata);
    buffer[rc]=0;
    strncpy(weeks[n_cal],buffer+4,7); strncat(weeks[n_cal],buffer+4,7);
    // pour avoir au moins 13 jours
    //lb1->Items->Add(AnsiString(weeks[n_cal]));

    for (i=0;i<MAX_JOURS;i++)
      {
       cal[n_cal][i]=weeks[n_cal][dow-1 + (i % 7)];
       add_jour(AnPrev,MoisPrev,JourPrev,i);
       if ((i % 7) == 0)
         {
          sprintf (tmp,"%02d-%02d-%04d",Jour,Mois,An);
          //lb1->Items->Add(AnsiString(tmp));
         }
       //verifie si il existe un record N ou T
       sprintf(tmp,"%02d-%04d-%02d-%02d",n_cal,An,Mois,Jour);
       rc = cals->ReadDirectKey(0,tmp,RetKey,&recdata);
       if (rc)    // il existe des modifs apportées
          {
            rc = cals->ReadRecord(buffer,recdata);
            buffer[rc]=0;
            if (buffer[13]==0) buffer[13]='N';
            cal[n_cal][i]=buffer[13];
          }
      }
    cal[n_cal][MAX_JOURS-1]= 0;
   }

 cals->CloseEngine(); cals->~genbase();
 return 1;
}

int  __fastcall TplStandard::add_jour(int year, int month, int day, int jours)
{
  // resultats dans An,Mois,Jour
  int i,counter,nbj_restant, j;
//  char days[7][15] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
//  "Samedi" };
//  char months[12][15] = {"Janvier","Février","Mars","Avril","Mai","Juin","Juillet",
//   "Aout","Septembre","Octobre","Novembre","Décembre"};
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

int  __fastcall TplStandard::convert_date(int year, int month, int day)
{
 int n1,n2,bcl,N;
 int initval;
 //int nbdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  // calcul approximatif de  la distance par rapport au previsionnel
  n1 = (AnPrev%100)*365 + MoisPrev*28 + JourPrev;
  n2 = (year%100)*365 + month*28 + day;

  if (n2<n1)  { Application->MessageBoxA("Date Anterieure a la date de Début previsionnel",
                 m_ecoplan,MB_OK);
                return 0;
              }

  initval = n2-n1-30; N=initval;
  for (bcl=0;bcl<100;bcl++)
    {
     add_jour(AnPrev,MoisPrev,JourPrev,N);
     if ((An==year) && (Mois==month) && (Jour==day)) break;
     else N++;
    }
 return N;
}




int  __fastcall TplStandard::avance_conges(int base,int ncal)
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

int  __fastcall TplStandard::avance_temps(int base,int ncal,int dur)
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

int  __fastcall TplStandard::recule_conges(int base,int ncal)
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

int  __fastcall TplStandard::recule_temps(int base,int ncal, int dur)
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

int __fastcall TplStandard::Organise_Niveaux()
{
 int i,j,ipred,ok,flag,inext,idd,ddflag,ind,count;


 for (i=0; i<nb_taches+1;i++) t_select[i]=0;
 for (i=0;i<nb_taches+1;i++)
    {
     for (j=0;j<NS;j++) {  niveaux[i][j]=0;  t_pred[i][j]=0; }
    }
 for (i=1;i<=nb_taches;i++)     // §§§§§§§§§§§§§§§§
   { ipred=1;
     while(pr[i][ipred] !=0)
      { t_pred[i][ipred]= pr[i][ipred];
        ipred++;
      }
   }

 iniv=0; ok=1;
 while (ok)  // on definit les niveaux
    {
     flag=0;
     inext=0;
     // t_select va recevoir les taches sans predecesseurs
     for (i=0;i<=nb_taches;i++) t_select[i]=0;  // §§§§§§§§§§§§§§§

     for (i=1;i<=nb_taches;i++)   // §§§§§§§§§§§§§§§§§§§§
       {
        if (t_pred[i][1] == 0)    // la tache sommets[i] n a pas de predecesseurs
          {
           // elle entre dans t_select,
           add_select(sommets[i]);  // sommets [i]

           // examen des successeurs pour detecter les AMONT
           idd=1; ddflag=0;
           while (su[i][idd] !=0)
             {if (su_tl[i][idd] == 2)
               { ddflag=1; break; }
              idd++;
             }
           if (ddflag == 0)  // les AM ne sont pas integrees
             { niveaux[iniv][inext]=sommets[i];
               inext++;
             }
           }
       }
     ind = 1;
     while (t_select[ind] != 0)
     { remove_task(t_select[ind]);
       ind++;
     }
     // next
     iniv++;
     if(iniv>=MAX_T)
       {
        inext = inext;

       }

     // fin de calcul ?  quand toutes les taches ont ete selectionnees
     count=0;
     for (i=1;i<=nb_taches;i++) if (t_pred[i][1] == -1)  count++;    // -1
     if (count == nb_taches) flag=1;
     if (flag) ok=0;
    }  // end while
 return 0;
}

int __fastcall TplStandard::Ord_Pred(int ind,int xtpred,int ipred)
{

int total,zcal;
if (pr_tl[ind][ipred]==0)     //  c est un lien fd
   {
    if ( pr_decal[ind][ipred] > 0)
      { zcal=tcal[ind];
        total = avance_conges(fin_plus_tot[xtpred]+1,zcal);
        total = avance_temps(total,zcal,pr_decal[ind][ipred]);
        total = avance_conges(total,zcal);  // §§§§§§
      }
    else if ( pr_decal[ind][ipred] < 0)
      {  zcal=tcal[xtpred];
         total = avance_conges(fin_plus_tot[xtpred]+1,zcal);
         total = recule_temps(total,zcal,-pr_decal[ind][ipred]);
      }
   else { zcal=tcal[ind];
          total = avance_conges(fin_plus_tot[xtpred]+1,zcal);
        } // pas de calcul de decalage
   }
 if (pr_tl[ind][ipred]==1)     // c est un lien ff
   {
     if (pr_decal[ind][ipred] > 0)
      { zcal=tcal[xtpred];
        total = avance_conges(fin_plus_tot[xtpred]+1,zcal);
        total = avance_temps(total,zcal,pr_decal[ind][ipred]);
        total = avance_conges(total,zcal); //§§§§§
        total = recule_temps(total,zcal,duree[ind]);
      }
     else if (pr_decal[ind][ipred] < 0)
      { zcal=tcal[xtpred];
        total=recule_conges(fin_plus_tot[xtpred]+1,zcal);
        total=recule_temps(total,zcal,-pr_decal[ind][ipred]);
        total = recule_temps(total,zcal,duree[ind]);
      }
     else
      {
        zcal= tcal[ind];
        total=recule_conges(fin_plus_tot[xtpred]+1,zcal);
        total = recule_temps(total,zcal,duree[ind]);
       }
  }

if (pr_tl[ind][ipred] == 2)  total = -1;   //flag_amont = ipred;
if (pr_tl[ind][ipred] == 3)    // Lien DD   Decal est >= 0
   {
     if ( pr_decal[ind][ipred] > 0)
       { zcal=tcal[xtpred];
         total=avance_conges(deb_plus_tot[xtpred],zcal);
         total = avance_temps(total,zcal,pr_decal[ind][ipred]);
         total = avance_conges(total,zcal); //§§§§§§§
       }
     else if ( pr_decal[ind][ipred] == 0)
       { zcal=tcal[ind];
         total=avance_conges(deb_plus_tot[xtpred],zcal);
        } // pas de calcul de decalage
   }

 return total;

}

void __fastcall TplStandard::Compute_PlusTotA()
{
  int indx,ix,ipred,imax,istop, flag, count;
  int ok, xtpred, total;
  int nb_pass,fini;
  char tmp[250];
  int xind;
  int avance;
  int A,M,J;
  int inext,ind,tniv;
  int fduree,fdecal;
  int idd, ddflag,flag_amont,t_amont,t_start;
  int i,j;
  int mom; int zcal;

sommets[nb_taches+1]=0;

if (nb_taches == 0) return;

 Organise_Niveaux();
 for (i=1;i<=nb_taches;i++) duree_reelle[i]=duree[i]; // §§§§§§§§§§§

 for (tniv=0;tniv<iniv;tniv++)
   {
    inext=0; xmax=-1000;
    while (niveaux[tniv][inext] != 0)
     {
      ind=niveaux[tniv][inext];
      ind = exist_tache(ind,nb_taches);

      if (tniv==0)  // niveau zero
       {
         // on traite les taches normales
         imax=0; zcal=tcal[ind];
         total=avance_conges(0,zcal);

         deb_plus_tot[ind] = total;
         fin_plus_tot[ind]=  avance_temps(total,zcal,duree[ind])-1;
         duree_reelle[ind] = fin_plus_tot[ind] - deb_plus_tot[ind]+ 1;
         if (total > xmax) { xmax=total; xind=ind; }
       }
      else
       {
        // cherchons les predecesseurs de ind
        imax = -1000;ipred = 1; total=0;  flag_amont = 0;
        while (pr[ind][ipred]!=0)
          {
           xtpred=pr[ind][ipred];
           xtpred=exist_tache(xtpred,nb_taches);

           total = Ord_Pred(ind,xtpred,ipred);

           if (total==-1) flag_amont=ipred;

           if (total > imax) imax=total;
           ipred++;
         }
        zcal=tcal[ind];
        deb_plus_tot[ind] = imax;
        fin_plus_tot[ind] = avance_temps(imax,zcal,duree[ind])-1;  // !!!! decalage de -1
        fin_plus_tot[ind] = avance_conges(fin_plus_tot[ind],zcal);
        if (fin_plus_tot[ind] > xmax) { xmax= fin_plus_tot[ind];xind = ind; }
        duree_reelle[ind]=fin_plus_tot[ind]-deb_plus_tot[ind]+1;

        if (fin_plus_tot[ind] > xmax) { xmax= fin_plus_tot[ind];xind = ind; }

        // si taches amont : calcul des dates au plus tot
        if (flag_amont)
          {
           t_start = ind;
           t_amont = pr[ind][flag_amont];
           while (t_amont >0)
             { int x_amont = t_amont;
              t_amont = exist_tache(t_amont,nb_taches);
              // on connait la mere
              // mom=tmom[t_amont];
              //deb_plus_tot[t_amont]=deb_plus_tot[mom];
              //deb_plus_tard[t_amont]=deb_plus_tard[mom];
              zcal=tcal[t_start];
              fdecal = comp_down(deb_plus_tot[t_start],zcal,pr_decal[t_start][flag_amont]);
              zcal=tcal[t_amont];
              fduree = comp_down(fdecal,zcal,duree[t_amont]);
              if (fduree < 0)
                { sprintf(tmp,"Tache Amont %d : Debordement possible sur le début",x_amont);
                 Application->MessageBoxA(tmp,m_ecoplan,MB_OK);
                }
              deb_plus_tot[t_amont] = fduree; // fin_plus_tot[t_amont]=xstart;
              fin_plus_tot[t_amont] = comp_up(fduree-1,zcal,duree[t_amont]); //fdecal-1;
              duree_reelle[t_amont]= fin_plus_tot[t_amont]-deb_plus_tot[t_amont];
              t_start= t_amont;
              t_amont = pr[t_amont][1]; flag_amont = 1;
             }

          }

       }
     inext++;
     }
   }


 deb_plus_tot[nb_taches+1]= deb_plus_tot[xind]+duree_reelle[xind];

 // on fait des successeurs pour la tache fictive  (nb_taches+1)
 for (ind=1;ind<=nb_taches;ind++)   //
   {
    if (su[ind][1]==0) su[ind][1]=9999;
   }
}

int  __fastcall TplStandard::comp_up(int deb,int ncal,int dur)
{
 int xdeb,xdur,xlimit;
 xdeb=deb+1; xdur=dur; xlimit=MAX_JOURS;
 // enlever les jours feries
 if (cal[ncal][xdeb] == 'N')
   { while (cal[ncal][xdeb]=='N') xdeb++;
     xstart= xdeb; xdeb--;
   }
 else xstart=xdeb;

 while ((xdur>0) && (xlimit > 0))
   { if (cal[ncal][xdeb]=='T')
         xdur--;
    xdeb++; xlimit--;
    }
 xdeb--;
return xdeb;
}

int  __fastcall TplStandard::comp_down(int deb,int ncal,int dur)
{
 int xdeb,xdur,xlimit;
 xdeb=deb-1; xdur=dur; xlimit=xdeb;
 // sauter les jours feries;
 if (cal[ncal][xdeb] == 'N')
   { while((cal[ncal][xdeb] == 'N') && (xlimit >= 0)) {xlimit--; xdeb--; }
     xstart=xdeb; xdeb++;
   }
 else { xstart=xdeb; }   // xdeb
 xlimit=deb;
 while ((xdur > 0) && (xlimit >0))
   {
    if (cal[ncal][xdeb] == 'T') xdur--;
    xdeb--; xlimit--;
   }
 xdeb++;
 return xdeb;
}

int __fastcall  TplStandard::comp_dist_succ(int indx,int xtsucc, int isucc)
{
 int zcal,xtotal,flag_amont,fduree;

 if (su_tl[indx][isucc]==0)     //  c est un lien fd
                  {
                   if (su_decal[indx][isucc] > 0)
                     { zcal=tcal[indx];  // xtsucc];
                       xtotal=recule_conges(deb_plus_tard[xtsucc],zcal);
                       xtotal=recule_temps(xtotal,zcal,su_decal[indx][isucc]);
                       xtotal=recule_temps(xtotal,zcal,duree[indx]);
                     }
                   else if (su_decal[indx][isucc] < 0)
                     {
                      zcal=tcal[indx]; //xtsucc];
                      xtotal=avance_conges(deb_plus_tard[xtsucc],zcal);
                      xtotal=avance_temps(xtotal,zcal,-su_decal[indx][isucc]);
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);
                      //fduree = comp_up(deb_plus_tard[xtsucc],zcal,-su_decal[indx][isucc]);
                      //zcal=tcal[indx];
                      //xtotal = comp_down(fduree,zcal,duree[indx]);
                     }
                   else
                     {zcal=tcal[indx];
                      xtotal=recule_conges(deb_plus_tard[xtsucc],zcal);
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);
                      //xtotal = comp_down(deb_plus_tard[xtsucc],zcal,duree[indx]);
                     }
                  }
                if (su_tl[indx][isucc]==1)     //  c est un lien ff
                  {
                   if (su_decal[indx][isucc] > 0)
                     {zcal=tcal[indx]; //  indx]; // xtsucc];
                      xtotal=recule_conges(fin_plus_tard[xtsucc]+1,zcal);
                      xtotal=recule_temps(xtotal,zcal,su_decal[indx][isucc]);
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);

                      //fduree = comp_down(fin_plus_tard[xtsucc],zcal,su_decal[indx][isucc]-1);
                      //zcal=tcal[indx];
                      //xtotal = comp_down(fduree,zcal,duree[indx]);
                     }
                   else if (su_decal[indx][isucc] < 0)
                     {zcal=tcal[indx];  //  indx]; //xtsucc];
                      xtotal=avance_conges(fin_plus_tard[xtsucc]+1,zcal);
                      xtotal=avance_temps(xtotal,zcal,-su_decal[indx][isucc]);
                      xtotal = avance_conges(xtotal,zcal); //§§§§§§§
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);

                      //fduree = comp_up(fin_plus_tard[xtsucc],zcal,-su_decal[indx][isucc]); // -1);
                      //zcal=tcal[indx];
                      //xtotal = comp_down(fduree,zcal,duree[indx]);
                     }
                   else
                     {zcal=tcal[indx];
                      xtotal=recule_conges(fin_plus_tard[xtsucc]+1,zcal);
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);
                      // xtotal = comp_down(fduree,zcal,duree[indx]);
                     }
                  }
                 if (su_tl[indx][isucc]==2)     //  c est un lien amont
                  {
                   flag_amont = isucc;
                  }

                 if (su_tl[indx][isucc]==3)     //  c est un lien DD
                  {
                   if (su_decal[indx][isucc] > 0)
                     { zcal=tcal[indx];  // xtsucc];

                       xtotal = comp_down(deb_plus_tard[xtsucc],zcal,su_decal[indx][isucc]);
                       //xtotal = comp_down(fduree,zcal,duree[indx]);    // $$$$$$$$$$$$
                     }
                   else if (su_decal[indx][isucc] == 0)
                     {zcal=tcal[indx];
                      //xtotal = comp_down(deb_plus_tard[xtsucc],zcal,duree[indx]);
                      xtotal = deb_plus_tard[xtsucc];
                     }
                  }

 return xtotal;


}



void __fastcall TplStandard::Compute_PlusTardA()
{
 int ix,tniv,inext,indx,isucc,xtsucc;
 int imin,xtotal;
 int mmin;
 int i,imax,zx;
 int fdecal, fduree;
 char tmp[250];
 int idd, ddflag,flag_amont,t_amont,t_start,imom;
 int indmom;
 int zcal;

 flag_amont=0;
 if (nb_taches==0) return;
 for (ix=0;ix<MAX_T;ix++)   { deb_plus_tard[ix]=-1; }
 sommets[nb_taches+1]=9999;   // juste pour calcul au plus tard

 // calcul de la date au plus tard de 9999  (nb_taches + 1)  depend de la duree
 // max si certaines taches sont longues
 imax=-1;
 for (i=1;i<=nb_taches;i++)    //§§§§§§§§§§§§§
   {
    ix=deb_plus_tot[i]+duree_reelle[i];
    if (ix > imax) imax=ix;
   }

  if (imax>deb_plus_tot[nb_taches+1]) deb_plus_tard[nb_taches+1]=imax;
   else deb_plus_tard[nb_taches+1] = deb_plus_tot[nb_taches+1];

  for (tniv=iniv-1;tniv>=0;tniv--)
   {
    inext=0;
    while (niveaux[tniv][inext] != 0)
      {
       indx=niveaux[tniv][inext];
       indmom = niveaux[tniv][inext];
       indx = exist_tache(indx,nb_taches);  // §§§§§§§§§§§§
       imin=+100000;
        // cherchons les successeurs de ind
        isucc = 1; xtotal=0;
        while ((su[indx][isucc]!=0)) // && (su[indx][isucc]!=9999))
          {
            xtsucc=su[indx][isucc];
            if (xtsucc==9999)
             {
               if (isucc == 1)  // pas de vrai successeurs
                   // imin = deb_plus_tard[nb_taches+1] - duree_reelle[indx]; //0;
                  {
                   zcal=tcal[indx];
                   xtotal = recule_conges(deb_plus_tard[nb_taches+1],zcal); //,duree[indx]);
                   xtotal = recule_temps(xtotal,zcal,duree[indx]);
                   imin=xtotal;
                  }
                else  // il existe un successeur
                  {  imin=imin; }
              isucc++;
           }
            else
              {

                xtsucc = exist_tache(xtsucc,nb_taches); //§§§§§§§§§§§§§§§
                xtotal = comp_dist_succ(indx,xtsucc,isucc);

                if (xtotal < imin) { imin=xtotal; }
                isucc++;
              }
          }  // while su

        if (imin==100000)  imin=0;
        deb_plus_tard[indx]=imin;
        zcal=tcal[indx];
        fin_plus_tard[indx]=avance_temps(imin,zcal,duree[indx]) - 1;
        //fduree = comp_up(deb_plus_tard[indx]-1,zcal,duree[indx]);
         //duree_reelle[indx] = fduree;
        //  $$$$ fin_plus_tard[indx]= imin + duree_reelle[indx] - 1;
        //fin_plus_tard[indx]= fduree;

        if (su_tl[indx][1]== 2)
          {
           deb_plus_tard[indx] = deb_plus_tot[indx];
           fin_plus_tard[indx] = fin_plus_tot[indx];
          }
        if (flag_amont) { }
      inext++;
      }
   }

  // marge totale
  for (indx=1;indx<=nb_taches;indx++)
    {
     if (deb_plus_tard[indx]==deb_plus_tot[indx]) marg_tot[indx]=0;
     else
      { // calculer le nombre de jour travaillés
        // marg_tot[indx]= deb_plus_tard[indx] - deb_plus_tot[indx];
         zcal=tcal[indx];
         marg_tot[indx] = compute_marge(deb_plus_tot[indx],deb_plus_tard[indx],zcal);

        //marg_tot[indx]= deb_plus_tard[indx] - deb_plus_tot[indx];
      }
    }
  // marge libre

  for (indx=1;indx<=nb_taches;indx++)
    {

    }

   sommets[nb_taches+1]=0;


 //  Remplissage des differentes colonnes de AdvStringGrid1;

  for (indx=1;indx<=nb_taches;indx++)     // §§§§§§§§§§§§§§§§§§
    {

      AdvStringGrid1->Cells[3][indx] = AnsiString(duree[indx]);
      av->Cells[3][indx]=AnsiString(duree[indx]);
      add_jour(AnPrev,MoisPrev,JourPrev,deb_plus_tot[indx]);
      sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
      AdvStringGrid1->Cells[4][indx] = AnsiString(tmp); //deb_plus_tot[indx]+1);
      av->Cells[4][indx]=AnsiString(tmp);
      add_jour(AnPrev,MoisPrev,JourPrev,fin_plus_tot[indx]);
      sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
      AdvStringGrid1->Cells[5][indx] = AnsiString(tmp);  // fin_plus_tot[indx]);
      av->Cells[5][indx]=AnsiString(tmp);
      add_jour(AnPrev,MoisPrev,JourPrev,deb_plus_tard[indx]);
      sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
      AdvStringGrid1->Cells[6][indx] = AnsiString(tmp); //deb_plus_tard[indx]+1);
      av->Cells[6][indx]=AnsiString(tmp);
      add_jour(AnPrev,MoisPrev,JourPrev,fin_plus_tard[indx]);
      sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
      AdvStringGrid1->Cells[7][indx] = AnsiString(tmp);   // fin_plus_tard[indx]);
      av->Cells[7][indx]=AnsiString(tmp);
      AdvStringGrid1->Cells[8][indx] = AnsiString(marg_tot[indx]);
      av->Cells[8][indx] = AnsiString(marg_tot[indx]);
      if (marg_tot[indx] == 0)
        {
          AdvStringGrid1->Cells[1][indx] = IntToStr(sommets[indx])+ " " +AnsiString(strdanger);
        }
      else
        {
         AdvStringGrid1->Cells[1][indx] = IntToStr(sommets[indx]);
        }
      AdvStringGrid1->Cells[9][indx] = AnsiString(marg_lib[indx]);
      av->Cells[9][indx] = AnsiString(marg_lib[indx]);
    }

}

int  __fastcall TplStandard::compute_marge(int tot, int tard, int ncal)
{
 int i,marg;
 marg=0;
 for (i=tot; i<tard;i++)
  {
   if (cal[ncal][i]== 'T') marg++;
  }
 return marg;
}


void __fastcall TplStandard::DrawGantt(int task,int pos)
{
  int nbjours;
  int ix,ixx,tdeb,tfin;
  int xbase,x1base,ttot;
  int interval;
  char tmp[120];
  int  X1,X2,Y,xx1,xx2;
  int isucc;
  int firstday;
  AnsiString Texte;
  TDateTime dtFirst;
  int jx,jcal;
  int kx,kinterv,K1,K2;
  int basecal;
  int xtask;

  dtFirst = EncodeDate(AnPrev,MoisPrev,JourPrev);
  firstday = dtFirst.DayOfWeek();
  //int dow;  // day of week
  // dow = firstday-1;

  if (nb_taches==0) return;

   BgColor=clWhite;
   FgColor=clLime;
   TxColor=clYellow;


 Diagram = Rect(0,0, imGantt->Width,imGantt->Height);
 imGantt->Canvas->Brush->Color = clWhite; // BgColor;
 imGantt->Canvas->FillRect(Diagram);

 Diagram = Rect(0,0,imGantt->Width,imGantt->Height/10);
 imGantt->Canvas->Brush->Color = clAqua; //
 imGantt->Canvas->FillRect(Diagram);

 // tracé du rectangle du haut;
 imGantt->Canvas->Brush->Color = clBlack; //
 imGantt->Canvas->MoveTo(0,0);
 imGantt->Canvas->LineTo(imGantt->Width-1,0);
 imGantt->Canvas->LineTo(imGantt->Width-1,imGantt->Height/20);
 imGantt->Canvas->LineTo(0,imGantt->Height/20);
 imGantt->Canvas->LineTo(0,0);
 imGantt->Canvas->LineTo(0,imGantt->Height);
 //  Tracé du compte de jours

 if (nb_taches==0) return;

 nbjours = deb_plus_tot[nb_taches+1];
 if (nbjours != 0) interval = (imGantt->Width / nbjours)*0.90;
   else interval = 100;
 imGantt->Canvas->Font->Color = clBlack;

 interval=25; //nbjours=30;

 xtask=task-5; if (xtask <1) xtask=1;

 ttot=deb_plus_tot[xtask];
 // adjust with position
 // position is relative to the middle (50 %)
 ttot = ttot + int (40*pos/200);     //  30/2
 if (ttot <0) ttot=0;
 ScrollBar2->Position = 50 + pos;
 if (nb_taches>0) ScrollBar1->Position = 100 * xtask / nb_taches;

 imGantt->Canvas->Font->Color = clBlack;
 imGantt->Canvas->MoveTo(0,imGantt->Height/10);
 imGantt->Canvas->LineTo(imGantt->Width,imGantt->Height/10);

 // fixé a l'aide de calendrier 1;  //////////////////
 for (ix=ttot;ix<=(nbjours+ttot);ix++)    // tenir compte du calendrier
   {
    xbase=(ix-ttot)*interval +interval/3;
    sprintf (tmp,"%d",ix+1);       // doit commencer à 1, pas a zéro
    add_jour(AnPrev,MoisPrev,JourPrev,ix);
    sprintf(tmp, "%02d",Jour);
    imGantt->Canvas->Font->Height = 8;
    imGantt->Canvas->Font->Color = clBlack;
    imGantt->Canvas->Brush->Color = clAqua;  // White;
    imGantt->Canvas->TextOut(xbase,3,(AnsiString) tmp);
    imGantt->Canvas->Font->Color = clBlack;
    imGantt->Canvas->MoveTo(ix*interval,0);
    imGantt->Canvas->LineTo(ix*interval,imGantt->Height/20);

    // tracé des conges
    xbase= (ix-ttot+1)*interval;
        if (cal[1][ix]=='N')
      {
       x1base  =  xbase - interval+1;
       Diagram = Rect(x1base,(imGantt->Height/10)+1,xbase,imGantt->Height);
       imGantt->Canvas->Brush->Color = clSilver; //
       imGantt->Canvas->FillRect(Diagram);
      }

     imGantt->Canvas->Brush->Color = clWhite;
     imGantt->Canvas->Pen->Style = psDot;  // Dash;
     imGantt->Canvas->MoveTo(xbase,imGantt->Height/10);
     imGantt->Canvas->LineTo(xbase,imGantt->Height);
     imGantt->Canvas->Pen->Style = psSolid;

     /// AN = 15100 §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

     dtFirst = EncodeDate(An,Mois,Jour);
     firstday = dtFirst.DayOfWeek();
     if (firstday == 2)  // Mondays
       {
       // trace d'un trait vertical noir
        x1base  =  xbase - interval;
        sprintf(tmp,"%02d/%02d/%04d",Jour,Mois,An);
        imGantt->Canvas->Font->Color = clBlack;
        imGantt->Canvas->Brush->Color = clAqua;  // White;
        imGantt->Canvas->TextOut(x1base+5,(imGantt->Height/20)+3,(AnsiString) tmp);
        imGantt->Canvas->MoveTo(x1base,imGantt->Height/20);
        imGantt->Canvas->LineTo(x1base,imGantt->Height);
       }
     if (Jour==1)  // 1er du mois, un trait rouge;
       {
        x1base  =  xbase - interval;
        imGantt->Canvas->Pen->Color = clRed;
        imGantt->Canvas->MoveTo(x1base,imGantt->Height/10);
        imGantt->Canvas->LineTo(x1base,imGantt->Height);
        imGantt->Canvas->Pen->Color = clBlack;
       }

   }


 //14 taches par ecran   // 30
 tdeb=xtask;  tfin=tdeb+30; if (tfin>nb_taches) tfin=nb_taches;

 for (ixx=tdeb;ixx<=tfin;ixx++)
   {
    // calcul des coordonnees
    xx1 = deb_plus_tot[ixx]-ttot;
    xx2=fin_plus_tot[ixx]+1-ttot;
    X1= xx1*interval;
    X2= xx2*interval;
    Y = (ixx-tdeb+1)*25+ 30;
    if (X2>=0)
       { imGantt->Canvas->Pen->Width = 4;
         if (su_tl[ixx][1] == 2) imGantt->Canvas->Pen->Color = clGreen;
         else if (marg_tot[ixx]==0) imGantt->Canvas->Pen->Color = clRed;
         else imGantt->Canvas->Pen->Color = clBlue;

         jcal= tcal[ixx];if ((jcal < 1) || (jcal>5)) jcal =1;
         //for (jx=ttot;jx<=(nbjours+ttot);jx++)
         basecal = deb_plus_tot[ixx]-1;
         for (jx=xx1;jx<xx2;jx++)
           {
            X1=jx*interval;
            X2 = X1+interval;

            basecal++;
            if (cal[jcal][basecal] == 'T')
             { imGantt->Canvas->MoveTo(X1,Y);
             imGantt->Canvas->LineTo(X2,Y);
             }
            else
             { kinterv = 5;  // interval / 5   *
               K1=X1+kinterv; K2=X1+2*kinterv;
               imGantt->Canvas->MoveTo(K1,Y);
               imGantt->Canvas->LineTo(K2,Y);
               K1=X1+3*kinterv; K2=X1+4*kinterv;
               imGantt->Canvas->MoveTo(K1,Y);
               imGantt->Canvas->LineTo(K2,Y);
               //K1=X1+kinterv; K2=X1+2*kinterv;
               //mGantt->Canvas->MoveTo(K1,Y);
               //imGantt->Canvas->LineTo(K2,Y);
             }

           }

         //imGantt->Canvas->MoveTo(X1,Y);
         //imGantt->Canvas->LineTo(X2,Y);

         Y= (ixx-tdeb+1)*25 + 15;
         X1= xx1*interval;
         imGantt->Canvas->MoveTo(X1,Y);
         imGantt->Canvas->Pen->Color = clLime;
         imGantt->Canvas->Font->Color = clBlue;
         imGantt->Canvas->Brush->Color = clYellow;
         add_jour(AnPrev,MoisPrev,JourPrev,deb_plus_tot[ixx]);
         //sprintf(tmp,"%02d/%02d/%04d ",Jour,Mois,An);
         Texte = ""; AnsiString(tmp);
         Texte = Texte + av->Cells[2][ixx] + " (d=" + IntToStr(duree[ixx]) + ")";
         imGantt->Canvas->TextOut(X1,Y,Texte);

         // affichage des successeurs

         isucc=1;  Texte="";
         while ((su[ixx][isucc]!=0) && (isucc <PS))
            {
              if (su[ixx][isucc] != 9999)
              {
                Texte = Texte + IntToStr(su[ixx][isucc]);
                if (su_tl[ixx][isucc] == 0) Texte = Texte + " FD ";
                if (su_tl[ixx][isucc] == 1) Texte = Texte + " FF ";
                if (su_tl[ixx][isucc] == 2) Texte = Texte + " AM ";
                if (su_tl[ixx][isucc] == 3) Texte = Texte + " DD ";
               Texte = Texte + IntToStr(su_decal[ixx][isucc])+ "  ";
              }
            isucc++;
           }
         Y = (ixx-tdeb+1)*25+ 23;
         //imGantt->Canvas->MoveTo(X2+8,Y);
         imGantt->Canvas->Brush->Color=clWhite;
         imGantt->Canvas->Pen->Color=clBlack;
         imGantt->Canvas->TextOut(X2,Y,Texte);
         imGantt->Canvas->Pen->Width = 1;
     }  // if X1 > 0
   }
 DrawMiniGantt(task,pos);
}

void __fastcall TplStandard::DrawMiniGantt(int task,int pos)
{
  int nbjours;
  int ix,ixx,tdeb,tfin;
  int xbase,x1base,ttot;
  int interval;
  char tmp[120];
  int  X1,X2,Y,xx1,xx2;
  int isucc;
  int firstday;
  AnsiString Texte;
  TDateTime dtFirst;
  int jx,jcal;
  int kx,kinterv,K1,K2;
  int basecal;
  int xtask;
  //int itask;
  int idateplustot,ipred,i,isel,indx,indice;

  dtFirst = EncodeDate(AnPrev,MoisPrev,JourPrev);
  firstday = dtFirst.DayOfWeek();
 // int dow;  // day of week
 // dow = firstday-1;

  if (nb_taches==0) return;
   // rechercher les predecesseurs et successeurs de TASK !

 for (i=0;i<MAX_T;i++) selection[i]=0;
 //itask=task;
 isel=1;ipred=1; idateplustot=deb_plus_tot[task];
 while ((pr[task][ipred]!=0) && (ipred<PS))
        { indx =  pr[task][ipred]; indice=exist_tache(indx,nb_taches);
          if (deb_plus_tot[indice]<idateplustot) idateplustot=deb_plus_tot[indice];
          selection[isel]=indx; ipred++; isel++;
        }

 selection[isel]=task; isel++;
 isucc=1;
 while ((su[task][isucc]!=0) && (isucc<PS))
         {indx = su[task][isucc];
          if (su[task][isucc] != 9999)
            { selection[isel]=indx;
              isel++;
            }
          isucc++;
         }
   BgColor=clWhite;
   FgColor=clLime;
   TxColor=clYellow;


 Diagram = Rect(0,0, immGantt->Width,immGantt->Height);
 immGantt->Canvas->Brush->Color = clWhite; // BgColor;
 immGantt->Canvas->FillRect(Diagram);

 Diagram = Rect(0,0,immGantt->Width,immGantt->Height/10);
 immGantt->Canvas->Brush->Color = clAqua; //
 immGantt->Canvas->FillRect(Diagram);

 // tracé du rectangle du haut;
 immGantt->Canvas->Brush->Color = clBlack; //
 immGantt->Canvas->MoveTo(0,0);
 immGantt->Canvas->LineTo(immGantt->Width-1,0);
 immGantt->Canvas->LineTo(immGantt->Width-1,immGantt->Height/20);
 immGantt->Canvas->LineTo(0,immGantt->Height/20);
 immGantt->Canvas->LineTo(0,0);
 immGantt->Canvas->LineTo(0,immGantt->Height);
 //  Tracé du compte de jours

 if (nb_taches==0) return;

 nbjours = deb_plus_tot[nb_taches+1];
 if (nbjours != 0) interval = (immGantt->Width / nbjours)*0.90;
   else interval = 100;
 immGantt->Canvas->Font->Color = clBlack;

 interval=25; //nbjours=30;



  ttot=idateplustot;   //deb_plus_tot[xtask];
 // adjust with position
 // position is relative to the middle (50 %)
 ttot = ttot + int (40*pos/200);     //  30/2
 if (ttot <0) ttot=0;
 ScrollBar2->Position = 50 + pos;
 if (nb_taches>0) ScrollBar1->Position = 100 * xtask / nb_taches;

 immGantt->Canvas->Font->Color = clBlack;
 immGantt->Canvas->MoveTo(0,immGantt->Height/10);
 immGantt->Canvas->LineTo(immGantt->Width,immGantt->Height/10);

 // fixé a l'aide de calendrier 1;  //////////////////
 for (ix=ttot;ix<=(nbjours+ttot);ix++)    // tenir compte du calendrier
   {
    xbase=(ix-ttot)*interval +interval/3;
    sprintf (tmp,"%d",ix+1);       // doit commencer à 1, pas a zéro
    add_jour(AnPrev,MoisPrev,JourPrev,ix);
    sprintf(tmp, "%02d",Jour);
    immGantt->Canvas->Font->Height = 6;
    immGantt->Canvas->Font->Color = clBlack;
    immGantt->Canvas->Brush->Color = clAqua;  // White;
    immGantt->Canvas->TextOut(xbase,3,(AnsiString) tmp);
    immGantt->Canvas->Font->Color = clBlack;
    immGantt->Canvas->MoveTo(ix*interval,0);
    immGantt->Canvas->LineTo(ix*interval,immGantt->Height/20);

    // tracé des conges
    xbase= (ix-ttot+1)*interval;
        if (cal[1][ix]=='N')
      {
       x1base  =  xbase - interval+1;
       Diagram = Rect(x1base,(immGantt->Height/10)+1,xbase,immGantt->Height);
       immGantt->Canvas->Brush->Color = clSilver; //
       immGantt->Canvas->FillRect(Diagram);
      }

     immGantt->Canvas->Brush->Color = clWhite;
     immGantt->Canvas->Pen->Style = psDot;  // Dash;
     immGantt->Canvas->MoveTo(xbase,immGantt->Height/10);
     immGantt->Canvas->LineTo(xbase,immGantt->Height);
     immGantt->Canvas->Pen->Style = psSolid;

     dtFirst = EncodeDate(An,Mois,Jour);
     firstday = dtFirst.DayOfWeek();
     if (firstday == 2)  // Mondays
       {
       // trace d'un trait vertical noir
        x1base  =  xbase - interval;
        sprintf(tmp,"%02d/%02d/%04d",Jour,Mois,An);
        immGantt->Canvas->Font->Color = clBlack;
        immGantt->Canvas->Brush->Color = clAqua;  // White;
        immGantt->Canvas->TextOut(x1base+5,(immGantt->Height/20)+3,(AnsiString) tmp);
        immGantt->Canvas->MoveTo(x1base,immGantt->Height/20);
        immGantt->Canvas->LineTo(x1base,immGantt->Height);
       }
     if (Jour==1)  // 1er du mois, un trait rouge;
       {
        x1base  =  xbase - interval;
        immGantt->Canvas->Pen->Color = clRed;
        immGantt->Canvas->MoveTo(x1base,immGantt->Height/10);
        immGantt->Canvas->LineTo(x1base,immGantt->Height);
        immGantt->Canvas->Pen->Color = clBlack;
       }

   }




 //14 taches par ecran   // 30
 tdeb=selection[1]; tfin=tdeb+14; if (tfin>nb_taches) tfin=nb_taches;

 for (ixx=1;ixx<isel;ixx++)
   {
    indice=exist_tache(selection[ixx],nb_taches);
    // calcul des coordonnees
    xx1 = deb_plus_tot[indice]-ttot;
    xx2=fin_plus_tot[indice]+1-ttot;
    X1= xx1*interval;
    X2= xx2*interval;
    Y = ixx*25+ 30;
    if (X2>=0)
       { immGantt->Canvas->Pen->Width = 4;
         if (su_tl[indice][1] == 2) immGantt->Canvas->Pen->Color = clGreen;
         else if (marg_tot[indice]==0) immGantt->Canvas->Pen->Color = clRed;
         else immGantt->Canvas->Pen->Color = clBlue;

         jcal= tcal[indice];if ((jcal < 1) || (jcal>5)) jcal =1;
         //for (jx=ttot;jx<=(nbjours+ttot);jx++)
         basecal = deb_plus_tot[indice]-1;
         for (jx=xx1;jx<xx2;jx++)
           {
            X1=jx*interval;
            X2 = X1+interval;

            basecal++;
            if (cal[jcal][basecal] == 'T')
             { immGantt->Canvas->MoveTo(X1,Y);
             immGantt->Canvas->LineTo(X2,Y);
             }
            else
             { kinterv = 5;  // interval / 5   *
               K1=X1+kinterv; K2=X1+2*kinterv;
               immGantt->Canvas->MoveTo(K1,Y);
               immGantt->Canvas->LineTo(K2,Y);
               K1=X1+3*kinterv; K2=X1+4*kinterv;
               immGantt->Canvas->MoveTo(K1,Y);
               immGantt->Canvas->LineTo(K2,Y);
             }

           }


         Y= ixx*25 + 15;
         X1= xx1*interval;
         immGantt->Canvas->MoveTo(X1,Y);
         immGantt->Canvas->Pen->Color = clLime;
         immGantt->Canvas->Font->Color = clBlue;
         immGantt->Canvas->Brush->Color = clYellow;
         add_jour(AnPrev,MoisPrev,JourPrev,deb_plus_tot[ixx]);
         //sprintf(tmp,"%02d/%02d/%04d ",Jour,Mois,An);
         Texte = ""; AnsiString(tmp);
         Texte = Texte + av->Cells[2][indice] + " (d=" + IntToStr(duree[indice]) + ")";
         immGantt->Canvas->TextOut(X1,Y,Texte);

         // affichage des successeurs

         isucc=1;  Texte="";
         while ((su[indice][isucc]!=0) && (isucc <PS))
            {
              if (su[indice][isucc] != 9999)
              {
                Texte = Texte + IntToStr(su[indice][isucc]);
                if (su_tl[indice][isucc] == 0) Texte = Texte + " FD ";
                if (su_tl[indice][isucc] == 1) Texte = Texte + " FF ";
                if (su_tl[indice][isucc] == 2) Texte = Texte + " AM ";
                if (su_tl[indice][isucc] == 3) Texte = Texte + " DD ";
               Texte = Texte + IntToStr(su_decal[indice][isucc])+ "  ";
              }
            isucc++;
           }
         Y = ixx*25+ 23;
         immGantt->Canvas->Brush->Color=clWhite;
         immGantt->Canvas->Pen->Color=clBlack;
         immGantt->Canvas->TextOut(X2,Y,Texte);
         immGantt->Canvas->Pen->Width = 1;
     }  // if X1 > 0
   }
}




int __fastcall TplStandard::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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

 void __fastcall TplStandard::refresh_coches()
 {
  int i, ctr_coche,ctr_filt;
  // calculer le nombre de taches cochees et filtrees
  Label15->Caption = IntToStr(nb_taches);
  ctr_coche=0; ctr_filt=0;
  for (i=1;i<=nb_taches;i++)
    {
     if (coche[i]=='X') ctr_coche++;
     if (filtr[i]=='X') ctr_filt++;
    }

 Label16->Caption = IntToStr(ctr_coche);
 Label17->Caption = IntToStr(ctr_filt);
}

int __fastcall TplStandard::Compute_Possible(int row,int indice,int ipred)
{
  int zcal,fd;
  int xtpred;


  xtpred=pr[row][ipred];
  xtpred=exist_tache(xtpred,nb_taches);


  if (pr_tl[row][ipred]==0)   // lien FD
    {
     if (pr_decal[row][ipred]>0)
           {  zcal=tcal[row];
              fd = avance_conges(fin_plus_tot[xtpred]+1,zcal);
              fd = avance_temps(fd,zcal,pr_decal[row][ipred]);
              fd = avance_conges(fd,zcal);
           }
          else if (pr_decal[row][ipred]<0)
           { zcal=tcal[xtpred];
             fd = avance_conges(fin_plus_tot[xtpred]+1,zcal);
             fd = recule_temps(fd,zcal,-pr_decal[row][ipred]);      // -
           }
          else // =0
           {
            zcal=tcal[row];
            fd = avance_conges(fin_plus_tot[xtpred]+1,zcal);
            }
    }

  if (pr_tl[row][ipred]==1)     // c est un lien ff
   {
     if (pr_decal[row][ipred] > 0)
      { zcal=tcal[xtpred];
        fd = avance_conges(fin_plus_tot[xtpred]+1,zcal);
        fd = avance_temps(fd,zcal,pr_decal[row][ipred]);
        fd = avance_conges(fd,zcal); //§§§§§
        fd = recule_temps(fd,zcal,duree[row]);
      }
     else if (pr_decal[row][ipred] < 0)
      { zcal=tcal[xtpred];
        fd=recule_conges(fin_plus_tot[xtpred]+1,zcal);
        fd=recule_temps(fd,zcal,-pr_decal[row][ipred]);
        fd = recule_temps(fd,zcal,duree[row]);
      }
     else
      {
        zcal= tcal[row];
        fd=recule_conges(fin_plus_tot[xtpred]+1,zcal);
        fd = recule_temps(fd,zcal,duree[row]);
       }
  }

if (pr_tl[row][ipred] == 2)  fd = -1;   //flag_amont = ipred;
if (pr_tl[row][ipred] == 3)    // Lien DD   Decal est >= 0
   {
     if ( pr_decal[row][ipred] > 0)
       { zcal=tcal[xtpred];
         fd=avance_conges(deb_plus_tot[xtpred],zcal);
         fd = avance_temps(fd,zcal,pr_decal[row][ipred]);
         fd = avance_conges(fd,zcal); //§§§§§§§
       }
     else if ( pr_decal[row][ipred] == 0)
       { zcal=tcal[row];
         fd=avance_conges(deb_plus_tot[xtpred],zcal);
        } // pas de calcul de decalage
   }
 return fd;
}


void __fastcall TplStandard::Refresh_Pred_Succ(int row)
 {
  int  ipred, xtpred,isucc,is;
  int irow,icol;
  char tmp[100];
  int itask;
  int indice;
  int indx;
  int fd;

  if (nb_taches==0) return;
  if (row==0) return;
  // nettoyer les 2 grilles
  if (sommets[current_task] != 9999)
  Label11->Caption = IntToStr(sommets[current_task]);
  else Label11->Caption = "";



  for (irow=1;irow<AdvStringGrid2->RowCount;irow++)
    { for (icol=1;icol<=AdvStringGrid2->ColCount;icol++)
      AdvStringGrid2->Cells[icol][irow]="";
    }
  for (irow=1;irow<AdvStringGrid3->RowCount;irow++)
    {  for (icol=1;icol<=AdvStringGrid3->ColCount;icol++)
      AdvStringGrid3->Cells[icol][irow]="";
    }
  itask=sommets[row];
  if (itask != 9999)
   {
   sprintf(tmp,"Prédécesseurs de la tâche %d",itask);
   Label3->Caption = AnsiString(tmp);
   sprintf(tmp,"Successeurs de la tâche %d",itask);
   Label4->Caption = AnsiString(tmp);
   }
   else
    {
     Label3->Caption = "Prédécesseurs";
     Label4->Caption = "Successeurs";
    }
  // afficher les predecesseurs;
  current_task=row;
  ipred=1;
  AdvStringGrid2->RowCount = 2; // 20;
  AdvStringGrid3->RowCount = 2; //20;

  while ((pr[row][ipred]!=0) && (ipred<PS))
         {                                         // §§§§§§§§§§§§§§§§§§§§§
          indx =  pr[row][ipred];
          indice = exist_tache(indx,nb_taches);
          if (ipred > 1) AdvStringGrid2->RowCount++;
          AdvStringGrid2->Cells[1][ipred]=pr[row][ipred];           // taches
          AdvStringGrid2->Cells[2][ipred]=AdvStringGrid1->Cells[2][indice];           // designation
          AdvStringGrid2->Cells[3][ipred]=duree[indice];    //duree


          fd = Compute_Possible(row,indice,ipred);

          //  xtpred=pr[indice][ipred];
          //  xtpred=exist_tache(xtpred,nb_taches);

          add_jour(AnPrev,MoisPrev,JourPrev,fd);
          sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
          AdvStringGrid2->Cells[4][ipred]=AnsiString(tmp);

          if (pr_tl[row][ipred]==0) AdvStringGrid2->Cells[5][ipred]="FD";
           else if (pr_tl[row][ipred]==1) AdvStringGrid2->Cells[5][ipred]="FF";
           else if (pr_tl[row][ipred]==2) AdvStringGrid2->Cells[5][ipred]="AM";
           else if (pr_tl[row][ipred]==3) AdvStringGrid2->Cells[5][ipred]="DD";
          AdvStringGrid2->Cells[6][ipred]=pr_decal[row][ipred];     // decal

          ipred++;
         }

  // afficher les successeurs;
  isucc=1; is=1;
  while ((su[row][isucc]!=0) && (isucc<PS))
         {
          indx = su[row][isucc];
          indice = exist_tache(indx,nb_taches);
          // ne pas afficher si tache END
          if (su[row][isucc] != 9999)
            {                          // §§§§§§§§§§§§§§§§§§§§§§§§§§§§
              if (isucc>1) AdvStringGrid3->RowCount++;
              AdvStringGrid3->Cells[1][is]=su[row][isucc];           // taches
              AdvStringGrid3->Cells[2][is]=AdvStringGrid1->Cells[2][indice];          // designation
              AdvStringGrid3->Cells[3][is]=duree[indice];    //duree


              add_jour(AnPrev,MoisPrev,JourPrev,deb_plus_tot[indice]);
              sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
              AdvStringGrid3->Cells[4][is]=AnsiString(tmp);

              // AdvStringGrid3->Cells[4][is]=deb_plus_tot[indice]+1;
              if (su_tl[row][isucc]==0) AdvStringGrid3->Cells[5][is]="FD";
              else if (su_tl[row][isucc]==1) AdvStringGrid3->Cells[5][is]="FF";
              else if (su_tl[row][isucc]==2) AdvStringGrid3->Cells[5][is]="AM";
              else if (su_tl[row][isucc]==3) AdvStringGrid3->Cells[5][is]="DD";
              AdvStringGrid3->Cells[6][is]=su_decal[row][isucc];
              is++;
            }
          isucc++;
         }
 refresh_coches();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TplStandard::InsertPredSeul(int tach,int tpred, int tl, int decal)
{
 int ipred,found,indx,xpred,imax;
  //AdvStringGrid2->Row++;
    // FAUX  insere tache predecesseur  (la tache en cours est current_task
    // tach et trped sont les numeros reels
    ipred=1;  found=0;
    indx = exist_tache(tach,new_nb_taches);
    xpred=1;
    while ((pr[indx][ipred]!=0) && (ipred<PS)) // && (pr[tach][ipred]!=9999)) && (ipred<PS))
       {
        if (pr[indx][ipred] == tpred){found=1; xpred=ipred;}
        ipred++;
       }
    if (!found && (ipred > 1)) { xpred=ipred; pr[indx][ipred+1]=0; }
    if (ipred >= PS-1) Application->MessageBox("Insert Pred : Pred > PS ",m_ecoplan,MB_OK);
    pr[indx][xpred] = tpred;
    pr_tl[indx][xpred] = tl;
    pr_decal[indx][xpred] = decal;

    if (!found && (ipred>1))AdvStringGrid2->RowCount++;

}

void __fastcall TplStandard::InsertSuccSeul(int tach,int tsucc,int tl, int decal)
{
 int isucc;
 int dec,xsucc;
 int found,f9999;
 int indsucc;


 // &&&&&&&&&&&&&&

 dec= exist_tache(tach,new_nb_taches);
 xsucc= tsucc; // =exist_tache(tsucc,new_nb_taches);
 if (dec==0) return;
 if (xsucc==0) return;
    indsucc=1;
    isucc=1; found=0; f9999=0;
    while ((su[dec][isucc]!=0)  && (isucc<PS))
       { if (su[dec][isucc] == tsucc) { found=1; indsucc= isucc;}
         if (su[dec][isucc]==9999) f9999=1;
         isucc++;
       }

    if (isucc >= PS-1) Application->MessageBox("Insert Succ : Succ > PS ",m_ecoplan,MB_OK);
    if (!found && (isucc>1)) {
         if (f9999) {  indsucc=isucc-1; su[dec][isucc]=9999; }
         else indsucc=isucc;
        } 
    su[dec][indsucc] = xsucc;
    su_tl[dec][indsucc] = tl;
    su_decal[dec][indsucc] = decal;
     if (!found && (isucc>1)) AdvStringGrid3->RowCount++;

 //   isucc=1;
 //   while (su[dec][isucc] !=0) isucc++;
 //   su[dec][isucc]=9999; //0  9999;

}



//---------------------------------------------------------------------------


void __fastcall TplStandard::Effacer1Click(TObject *Sender)
{

 char tmp[100];
 // Effacer Tache   en cours
 sprintf(tmp,"Confirmer effacement de la tâche %d",current_task);
 if (Application->MessageBox(tmp,m_ecoplan,MB_YESNO) ==IDNO) return;
 effacer_tache(current_task);

 current_task=1;
 grefresh(current_task);


}
//---------------------------------------------------------------------------




void __fastcall TplStandard::Inserer1Click(TObject *Sender)
{
 // click sur Inserer Tache
 int a,b,nt;
 int indx,k;
 char tmp[250];

 a=current_task;
 if (nb_taches==0)
 {
  Application->MessageBox("Pas de tâche existante - Utilisez la touche 'INSER'","Insertion Tâche",MB_OK);
  return;
  }
 if (a==1)
 sprintf (tmp,"Insertion d'une tâche devant la tâche %d ? ", a);
  else
 sprintf (tmp,"Insertion d'une tâche entre les tâches %d et %d ? ", a-1,a);

 if (Application->MessageBox(tmp,"Insertion Tâche",MB_YESNO) == IDNO) return;

    // chercher premier numero de tache libre
    nt = next_task();
    sprintf(tmp,"Nlle Tache %d",nt);
    for (indx=nb_taches;indx>=a;indx--)
      {
       coche[indx+1]=coche[indx];
       coch[indx+1]=coch[indx];
       sommets[indx+1]=sommets[indx];
       filtr[indx+1]=filtr[indx];
       duree[indx+1]=duree[indx];
       duree_reelle[indx+1]=duree_reelle[indx];
       strcpy(codetache[indx+1],codetache[indx]);
       strcpy(da[indx+1],da[indx]);
       strcpy(dtr[indx+1],dtr[indx]);
       strcpy(ftr[indx+1],ftr[indx]);
       pc[indx+1]=pc[indx];
       nbj[indx+1]=nbj[indx];
       tmom[indx+1]=tmom[indx];
       tcal[indx+1]=tcal[indx];


       // maj des predecesseurs et successeurs

       for (k=0;k<PS;k++)
         { pr[indx+1][k] = pr[indx][k];
           pr_tl[indx+1][k] = pr_tl[indx][k];
           pr_decal[indx+1][k] = pr_decal[indx][k];
           su[indx+1][k] = su[indx][k];
           su_tl[indx+1][k] = su_tl[indx][k];
           su_decal[indx+1][k] = su_decal[indx][k];
         }

       AdvStringGrid1->Cells[1][indx+1]=AdvStringGrid1->Cells[1][indx];
       av->Cells[1][indx+1]=av->Cells[1][indx];
       AdvStringGrid1->Cells[2][indx+1]=AdvStringGrid1->Cells[2][indx];
       av->Cells[2][indx+1]=av->Cells[2][indx];
       AdvStringGrid1->Cells[3][indx+1]=AdvStringGrid1->Cells[3][indx];
       av->Cells[3][indx+1]=av->Cells[3][indx];
      } // for indx

   // insertion de la tache en indice "a"
   sommets[a]=nt;
   coche[a]=' ';
   coch[a]=1;
   duree[a]=1;
   duree_reelle[a]=1;
   filtr[a]=' ';
   tcal[a]=1;
   tmom[a]=0;
   codetache[a][0]=0;
   for (k=0;k<PS;k++)
     { pr[a][k]=0; pr_tl[a][k]=0; pr_decal[a][k]=0;
       su[a][k]=0; su_tl[a][k]=0; su_decal[a][k]=0;
     }
   su[a][1]=9999;
   sprintf(tmp,"Nlle Tache %d",nt);
   AdvStringGrid1->Cells[1][a]=nt;
   av->Cells[1][a]=nt;
   AdvStringGrid1->Cells[2][a]=AnsiString(tmp);
   av->Cells[2][a]=AnsiString(tmp);
   AdvStringGrid1->Cells[3][a]=1;
   av->Cells[3][a]=1;
   if (a>1) { AdvStringGrid1->RowCount++; av->RowCount++; }
   sprintf(tmp,"Creation d'une nouvelle tâche %d",nt);
   Application->MessageBox(tmp,"Insertion Tâche",MB_OK);

   nb_taches++;
   current_task=1;
   grefresh(current_task);
}
//---------------------------------------------------------------------------

int __fastcall TplStandard::next_task()
{
 int indx,it;
 it=0;
 for (indx=1;indx<=nb_taches;indx++)
   {
    if (sommets[indx] > it) it = sommets[indx];
   }
 it++;
 return it;
}

void __fastcall TplStandard::Tout_Cocher()
{
 int i;

 for (i=1;i<=nb_taches;i++) // §§§§§§§§§§§§§§§
   { coche[i] = 'X';
     AdvStringGrid1->Cells[0][i]=AnsiString(strcoche);  //"X";
   }
 refresh_coches();
}


void __fastcall TplStandard::Tout_Decocher()
{
int i;
 for (i=1;i<=nb_taches;i++)  // §§§§§§§§§§§§§§§§§§§
   {
    coche[i]=' ';
    AdvStringGrid1->Cells[0][i]=" ";
   }
 refresh_coches();
}

void __fastcall TplStandard::Copier_Cocher()
{


 char tmp[250];
 TCopy *CTask;
 int cascade;
 int decalage;
 int tl;
 int tlien;
 int oldcoche;
 int newcoche;
 int nexttache;
 int ipred,tpred,decal,nt,isucc,tsucc;
 int numtachpred,decalpred,tlpred,indpred;
 //int l;
 int count,i,index;
 //int first;
 int xnb_taches;
 int nb_coches;

     CTask = new TCopy(Application);
     CTask->ShowModal();
     delete CTask;
     // ReadExchange(1);
     ExtractValue(tmp,m_exchange,"null",0);
     if (strcmp(tmp,"TRUE")==0) return;

     nexttache=0; nb_coches=0;
     for (i=1;i<=nb_taches;i++)
        { if (sommets[i]>nexttache) nexttache=sommets[i];
          if (coche[i]=='X') nb_coches++;
        }
     //  preparer sommets [i] defacon a prendre en compte les nlles taches
     // nb taches cochees dans nb_coches;
     for (i=1; i <=nb_coches; i++)
             sommets[i+nb_taches] = nexttache + i;
        new_nb_taches = nb_taches+nb_coches;

     // decodage de exchange
     cascade=0; decalage=0; tl=0;
     ExtractValue(tmp,m_exchange,"cascade",0);
     if (strcmp(tmp,"T")==0)
       { cascade=1;
         ExtractValue(tmp,m_exchange,"decalage",0);
         decalage=atoi(tmp);
         ExtractValue(tmp,m_exchange,"tl",0);
         tlien=atoi(tmp);
       }
     oldcoche=0; newcoche=0;
     ExtractValue(tmp,m_exchange,"old",0);
     if (strcmp(tmp,"T")==0)  oldcoche=1;
     ExtractValue(tmp,m_exchange,"new",0);
     if (strcmp(tmp,"T")==0)  newcoche=1;

   // compter les coches : message si dup > MAX_T
   count=0;
   xnb_taches=nb_taches;
   for (i=1;i<=xnb_taches;i++)if (coche[i]=='X') count++;
   if ((nb_taches+count) >= MAX_T)
    {
     Application->MessageBox("Nombre de tâches trop élevé ( > 3000 )",m_ecoplan,MB_OK);
     return;
    }
   //  maintenant, on y va, on duplique


   //first=true;

   count=0;
   for (i=1;i<=xnb_taches;i++)
     {
      if ((coche[i]=='X') && (su_tl[i][1] != 2))   // ne pas copier taches amont
       {
        count++;  index= xnb_taches+count;
        nexttache++;
        AdvStringGrid1->RowCount++;
        av->RowCount++;
        duree[index]=duree[i];
        tcal[index] = tcal[i];

        filtr[index]=filtr[i];
        duree_reelle[index]=duree_reelle[i];
        strcpy(codetache[index],codetache[i]);
        strcpy(da[index],da[i]);
        strcpy(dtr[index],dtr[i]);
        strcpy(ftr[index],ftr[i]);

        sommets[index]=nexttache;
        AdvStringGrid1->Cells[1][index]= nexttache;
        av->Cells[1][index]= nexttache;
        AdvStringGrid1->Cells[2][index]= "Tache " + IntToStr(nexttache) + " ";
        av->Cells[2][index]= "Tache " + IntToStr(nexttache) + " ";
        AdvStringGrid1->Cells[10][index]= tcal[i];
        av->Cells[10][index]= tcal[i];
        nb_taches=nb_taches+1;


        if (!cascade)
          {
           //if (!first)
           //  {
              ipred=1;
              while ((pr[i][ipred] != 0) && (ipred<PS))
                {
                  // inserer un predecesseur que si tache cochee
                  nt= pr[i][ipred];  //
                  if (coche[nt]=='X')
                   {
                      tl = pr_tl[i][ipred];
                      decal = pr_decal[i][ipred];
                      tpred = nexttache - i + nt;
                      InsertPredSeul(nexttache,tpred,tl,decal);
                      InsertSuccSeul(tpred,nexttache,tl,decal);
                    }
                  ipred++;
                 } // while


              isucc=1;
              while ((su[i][isucc] != 0) && (isucc<PS))
                {
                  // inserer un successeur que si tache cochee
                  nt= su[i][isucc];  //
                  if (nt==9999) {nt=0; coche[0]=' '; }
                  if (coche[nt]=='X')
                   {
                      tl = su_tl[i][isucc];
                      decal = su_decal[i][isucc];
                      tsucc = nexttache - i + nt;
                      InsertSuccSeul(nexttache,tsucc,tl,decal);
                      InsertPredSeul(tsucc,nexttache,tl,decal);
                    }
                  isucc++;
                 } // while

             // } //  first
            //first=false;
           } // ! cascade


        if (cascade)   //
         {
          // if (!first)
          //   {
              InsertPredSeul(index,i,tlien,decalage);
              InsertSuccSeul(i,index,tlien,decalage);
              ipred=1;
              while ((pr[i][ipred] != 0) && (ipred<PS))
                {
                  nt= pr[i][ipred];  //
                  if (coche[nt]=='X')
                   {
                      tl = pr_tl[i][ipred];
                      decal = pr_decal[i][ipred];
                      tpred = nexttache - i + nt;
                     InsertPredSeul(nexttache,tpred,tl,decal);
                     InsertSuccSeul(tpred,nexttache,tl,decal);
                    }
                 ipred++;
               }
             isucc=1;
              while ((su[i][isucc] != 0) && (isucc<PS))
                {
                  // inserer un successeur que si tache cochee
                  nt= su[i][isucc];  //
                  if (nt==9999) {nt=0; coche[0]=' '; }
                  if (coche[nt]=='X')
                   {
                      tl = su_tl[i][isucc];
                      decal = su_decal[i][isucc];
                      tsucc = nexttache - i + nt;
                      InsertSuccSeul(nexttache,tsucc,tl,decal);
                      InsertPredSeul(tsucc,nexttache,tl,decal);
                    }
                  isucc++;
                 } // while
         } // if cascade
      }  // if coche=X
     } // for

           // cocher-decocher en fin de traitement


  count=0; nexttache=0;
  for (i=1;i<=xnb_taches;i++)
     {
      if (coche[i]=='X')
       {
        count++;    index= xnb_taches+count;
        nexttache++;

        if (oldcoche==0)  {coche[i]=' '; AdvStringGrid1->Cells[0][i]= " "; }

        if (newcoche==1)
          { coche[index]='X';
            AdvStringGrid1->Cells[0][index]=AnsiString(strcoche);  //"X";
          }
        else
          {
           coche[index]=' ';
            AdvStringGrid1->Cells[0][index]= " ";
          }
      }
    }

  current_task=1;
  grefresh(current_task);
  Change1();

}

void __fastcall TplStandard::CochertouteslesTaches1Click(TObject *Sender)
{
 Tout_Cocher();
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::DcochertouteslesTaches1Click(TObject *Sender)
{
 Tout_Decocher();
}
//---------------------------------------------------------------------------




void __fastcall TplStandard::CopierlesTaches1Click(TObject *Sender)
{
 Copier_Cocher();
}

void __fastcall TplStandard::effacer_tache(int t)
{
 int indice;
 int indx,k,nt,it;
 int ipred,isucc;

 indice = exist_tache(t,nb_taches);
 if ((indice==0) || (indice > MAX_T)) return;
 if (nb_taches < 1) return;

 for (indx=indice; indx<=nb_taches+1; indx++)
   {
    sommets[indx]=sommets[indx+1];
    coche[indx]=coche[indx+1];
    tcal[indx]=tcal[indx+1];
    tmom[indx]=tmom[indx+1];
    filtr[indx]=filtr[indx+1];
    duree[indx]=duree[indx+1];
    duree_reelle[indx]=duree_reelle[indx+1];
       // maj des predecesseurs et successeurs

       for (k=0;k<PS;k++)
         { pr[indx][k] = pr[indx+1][k];
           pr_tl[indx][k] = pr_tl[indx+1][k];
           pr_decal[indx][k] = pr_decal[indx+1][k];
           su[indx][k] = su[indx+1][k];
           su_tl[indx][k] = su_tl[indx+1][k];
           su_decal[indx][k] = su_decal[indx+1][k];
         }


       AdvStringGrid1->Cells[1][indx]=AdvStringGrid1->Cells[1][indx+1];
       av->Cells[1][indx]=av->Cells[1][indx+1];
       AdvStringGrid1->Cells[2][indx]=AdvStringGrid1->Cells[2][indx+1];
       av->Cells[1][indx]=av->Cells[1][indx+1];
       AdvStringGrid1->Cells[3][indx]=AdvStringGrid1->Cells[3][indx+1];
       av->Cells[1][indx]=av->Cells[1][indx+1];
   }

   // clean the last row
   for (k=0;k<=AdvStringGrid1->ColCount;k++)  AdvStringGrid1->Cells[k][nb_taches]="";
   for (k=0;k<=av->ColCount;k++)  av->Cells[k][nb_taches]="";
   nb_taches--;
 // traitement pour retirer tous les predecesseurs ou successeurs
 // lies a la tache T

  for (indx=1;indx<=nb_taches;indx++)
    {
     ipred=1;
     while ((pr[indx][ipred] !=0) && (pr[indx][ipred] !=9999))
       {
        nt=pr[indx][ipred];
        if (nt==t)
          {// decaler  + break;
           for (it=ipred;it<PS;it++)
             {
              pr[indx][it]=pr[indx][it+1];
              pr_tl[indx][it]=pr_tl[indx][it+1];
              pr_decal[indx][it]=pr_decal[indx][it+1];
             }
           break;
          }

        ipred++;
       }
     isucc=1;
      while ((su[indx][isucc] !=0) && (su[indx][isucc] != 9999))
       {
        nt=su[indx][isucc];
        if (nt==t)
          { // decaler + break;
           for (it=isucc;it<PS;it++)
             {
              su[indx][it]=su[indx][it+1];
              su_tl[indx][it]=su_tl[indx][it+1];
              su_decal[indx][it]=su_decal[indx][it+1];
             }
           break;
          }

        isucc++;
       }


    }
 current_task=1;
 grefresh(current_task);
}


//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TplStandard::CocherDcocherTacheencours1Click(
      TObject *Sender)
{
 int i;
 i = current_task;
 // tache en cours doit etre dans current_task
 if (coche[i]=='X')
   {
    coche[i]=' ';
    AdvStringGrid1->Cells[0][i]=" ";
   }
 else
   {
    coche[i]='X';
    AdvStringGrid1->Cells[0][i]=AnsiString(strcoche);
   }
 refresh_coches();
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::CocherDcocherTches1Click(TObject *Sender)
{
  int i;
 for (i=1;i<=nb_taches;i++)
  {
  if (coche[i]=='X')
   {
    coche[i]=' ';
    AdvStringGrid1->Cells[0][i]=" ";
   }
 else
   {
    coche[i]='X';
    AdvStringGrid1->Cells[0][i]=AnsiString(strcoche);
   }
 }

 refresh_coches();

}
//---------------------------------------------------------------------------


void __fastcall TplStandard::ScrollBar2Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
 //
 int x;
 //x=ScrollBar2->Position - 50;
 DrawGantt(current_task,x);
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::ScrollBar1Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
 int x1,x2;
 x2=ScrollBar2->Position - 50;
 x1=int (ScrollBar1->Position*nb_taches/100)+1;

 DrawGantt(x1,x2);

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::LierTachesCoches1Click(TObject *Sender)
{
  int decal,tl;
  char tmp[250];
  int ix; int first; int previous;

   TLienCoche *CLien;
 // lier taches cochees
 // faire paraitre une petite fenetre de dialogue
     CLien = new TLienCoche(Application);
     CLien->ShowModal();
     delete CLien;
     //ReadExchange(1);
     ExtractValue(tmp,m_exchange,"null",0);
     if (strcmp(tmp,"TRUE")==0) return;

 // on extrait type de lien et decalage
     ExtractValue(tmp,m_exchange,"decalage",0);
     decal = atoi(tmp);
     ExtractValue(tmp,m_exchange,"tl",0);
     tl= atoi(tmp);


 //  on fabrique les liens avec les predecesseurs
 // previous contient le numero de taches precedente
     first = 1;  // la premiere tache cochee n'aura pas de predecesseurs
     for (ix=1;ix<=nb_taches;ix++)
       {
        if (coche[ix]=='X')
         {
          if (first)  first=0;
          else
           {
            // nt=sommets[ix];
            new_nb_taches = nb_taches;
            ctask=sommets[ix];
            InsertPredSeul(ctask,previous,tl,decal);
            InsertSuccSeul(previous,ctask,tl,decal);
           }
          previous = sommets[ix];
         }
       }

     current_task=1;
     grefresh(current_task);

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::SupprimerTchesCoches1Click(TObject *Sender)
{
 int ok,i,numtache;
 if (Application->MessageBox("Voulez vous supprimer les taches cochées ?",
      m_ecoplan,MB_YESNO)== IDNO) return;
 ok = 1;

 while(ok)
   {
    // chercher s'il reste une tache cochee
    numtache=0;
    for (i=1;i<=nb_taches;i++)
       {
        if (coche[i] == 'X') { coche[i]=' '; numtache=sommets[i]; break; }
       }
     if (numtache != 0)
        effacer_tache(numtache);
     else ok=0;
   }

    current_task=1;
    grefresh(current_task);
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::delier_tache(int t)
{
 int indice;
 int indx,k,nt,it;
 int ipred,isucc;
 int tblpred[500], tblsucc[500];
 int ctrpred,ctrsucc,i;


 indice = exist_tache(t,nb_taches);
 if ((indice==0) || (indice > MAX_T)) return;
 if (nb_taches < 1) return;

 for (i=0;i<500;i++) {tblpred[i]=0; tblsucc[i]=0; }
 ctrpred=0;ctrsucc=0;

 // traitement pour retirer tous les predecesseurs ou successeurs
 // lies a la tache T   : delier uniquement entre taches cochees
  indx=1;
  while (indx<=nb_taches)
     {
      if (sommets[indx]==t)
        {
         ipred=1;
         while (pr[indx][ipred] !=0)
           {
             if (coche[pr[indx][1]]=='X')
               { tblpred[ctrpred]=pr[indx][ipred];
                 ctrpred++;
               }
             ipred++;
           }
         isucc=1;
         while  ((su[indx][isucc] !=0) && (su[indx][isucc]!=9999))
           {
             if (coche[su[indx][isucc]]=='X')
              { tblsucc[ctrsucc]= su[indx][isucc];
                ctrsucc++;
              }
             isucc++;
           }

         break;
        }
      indx++;
     }

// on va maintenant  retirer les pred et succ selectionnes

  for (i=0;i<ctrpred;i++)
     {
       ctask=sommets[indx];
       RemovePredSeul(ctask,tblpred[i]);
       RemoveSuccSeul(tblpred[i],ctask);
     }
  for (i=0;i<ctrsucc;i++)
     { ctask=sommets[indx];
       RemoveSuccSeul(indx,tblsucc[i]);
       RemovePredSeul(tblsucc[i],indx);
     }

}



void __fastcall TplStandard::DlierTchesCoches1Click(TObject *Sender)
{
 // delier taches cochees
 // enlever tous les liens suppr et pred lies a une tache donnee
 int i;
 if (Application->MessageBox("Voulez vous délier les tâches cochées ?",
      m_ecoplan,MB_YESNO)== IDNO) return;

    for (i=1;i<=nb_taches;i++)
       {
        if (coche[i] == 'X')  delier_tache(sommets[i]);

        }


  current_task=1;
 grefresh(current_task);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

int __fastcall TplStandard::SaveAs(char *name)
{
 char newname[256];
 char *p;

 strcpy(newname,name); strlwr(newname);
 p = strstr(newname,".indx");
 if (p) *p=0;
 strcpy(LocalBase,name);
 updatedatabase(LocalBase,0,0);
 Application->MessageBoxA(newname,m_ecoplan,MB_OK);
 return 1;

}

//---------------------------------------------------------------------------

void __fastcall TplStandard::MonthCalendar1Click(TObject *Sender)
{
 Edit3->Text = MonthCalendar1->Date;
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::btDatPrevClick(TObject *Sender)
{
 char Key[100],RetKey[100];
 int  rc, recdata;
 char tmp1[200],tmp[200];

  strcpy(Key,"<dateprevdebut>");
  strcpy(tmp1,Edit3->Text.c_str());
  rc = proj->ReadDirectKey(0,Key,RetKey,&recdata);
  if (rc) rc = proj->RewriteRecord(tmp1, strlen(tmp1)+1,recdata);
  else
   { recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     rc = proj->WriteRecord(tmp1,strlen(tmp1)+1);
   }
 strcpy(dateprevdeb,tmp1);
 Label7->Caption = Edit3->Text;

   tmp1[2]=0; JourPrev=atoi(tmp1);
   tmp1[5]=0; MoisPrev=atoi(tmp1+3);
   tmp1[10]=0; AnPrev=atoi(tmp1+6);

 PageControl1->ActivePageIndex=0;
 init_calendrier();

  current_task=1;
 grefresh(current_task);
}

int __fastcall TplStandard::Bcl_Pred(int t,int p)
{
 int i,j,memt,memp;
 Organise_Niveaux();
 // verifier si Predecesseur P n'est pas dans les successeurs

 if (iniv==1) return 0;
  memt=-1;memp=-1;

 for (i=0;i<iniv;i++)
  {
   j=0;
   while (niveaux[i][j] != 0)
     {
      if (niveaux[i][j] == t) memt=i;
      if (niveaux[i][j] == p) memp=i;
      j++;
     }
  }
  if (memp > memt) return 1;


 return 0; // OK
}

int __fastcall TplStandard::Bcl_Succ(int t,int s)
{
 int i,j,memt,mems;
 Organise_Niveaux();  // iniv est le niveau max
 // verifier si tache S n'est pas dans les niveaux avant T
 if (iniv==1) return 0;
 memt=-1;mems=-1;
 for (i=0;i<iniv;i++)
  {
   j=0;
   while (niveaux[i][j] != 0)
     {
      if (niveaux[i][j] == t) memt=i;
      if (niveaux[i][j] == s) mems=i;
      j++;
     }
  }
  if (mems < memt) return 1;
 return 0; //OK
}



// =======================================================================
//  ALL ADVSTRINGGRID 1
// =======================================================================


//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid1ContextPopup(TObject *Sender,
      TPoint &MousePos, bool &Handled)
{
 int X,Y;
 X = MousePos.x;
 Y = MousePos.y;
  AdvStringGrid1->MouseToCell(X, Y, CurCol, CurRow);
 // conversion en ligne et colonne courantes
 PopupList->Popup(X, Y);
}

void __fastcall TplStandard::AdvStringGrid1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int Column, Row;

  AdvStringGrid1->MouseToCell(X, Y, Column, Row);
  if ((Row > nb_taches) || (Row < 0)) return;
  if (Column==0)
     { SG1Row=Row; SG1Col=0;
      if (coche[Row]=='X') { coche[Row]=' '; AdvStringGrid1->Cells[0][Row] = ' '; }
       else { coche[Row]='X';    AdvStringGrid1->Cells[0][Row] = AnsiString(strcoche); }
    AdvStringGrid1->Cells[1][Row] = IntToStr(sommets[Row]);
    AdvStringGrid1->Row=sommets[Row];
    AdvStringGrid1->Col=1;
     }
 }



//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 int i,
 isucc;
 char tmp[250];
 int nt,dur;
 TNewTask *NewTask;
 int exist,ok;
 int j;

 if (Key == VK_INSERT)
    {    //  insertion d une tache a la fin

     nt=nb_taches+1;
     ok=0;
     while (!ok)
      {
         exist = exist_tache(nt,nb_taches);
         if (exist !=0)  nt++;  else ok=1;
       }
     if (nt>1) { AdvStringGrid1->RowCount++; av->RowCount++; }
     nb_taches++; new_nb_taches=nb_taches;

     sommets[nb_taches]=nt;
     AdvStringGrid1->Cells[1][nb_taches]=nt;
     av->Cells[1][nb_taches]=nt;


     //ExtractValue(tmp,exchange,"libel",0);

     sprintf(tmp,"Tache numéro %d",nt);

     AdvStringGrid1->Cells[2][nb_taches]= AnsiString (tmp);
     av->Cells[2][nb_taches]= AnsiString (tmp);
     strcpy(libel[nb_taches],tmp);
     AdvStringGrid1->Cells[10][nb_taches]= "1";  // cal
     av->Cells[10][nb_taches]= "1";  // cal
     //ExtractValue(tmp,exchange,"duree",0);
     //dur = atoi(tmp);
      i=nb_taches;
      duree[i]=1;
      duree_reelle[i]=0;
      deb_plus_tot[i]=0;
      fin_plus_tot[i]=0;
      deb_plus_tard[i]=0;
      fin_plus_tard[i]=0;
      sommets[i]=0;
      coche[i]= ' ';
      filtr[i]= ' ';
      tcal[i]=1;
      tmom[i]=0;
      da[i][0]=0;
      dtr[i][0]=0;
      ftr[i][0]=0;
      pc[i]=0;
      nbj[i]=0;
      //bel[i][0]=0;


      for (j=0;j<PS;j++)
        {
         pr[i][j]=0; su[i][j]=0;
         pr_tl[i][j]=0; su_tl[i][j]=0;
         pr_decal[i][j]=0; su_decal[i][j]=0;
        }


     dur=1;


     if (dur <=0) dur=1;
     duree[nb_taches]=dur;

     // nettoyage des predecesseurs de la tache END ainsi que
     // les succ

 //    ipred=1;
     sommets[nb_taches]=nt;  ///nb_taches;
     AdvStringGrid1->Cells[3][nb_taches]= IntToStr(dur);
     av->Cells[3][nb_taches]= IntToStr(dur);
     current_task=nb_taches;
     grefresh(current_task);
     return;
   }  // VK_INSERT

 if (Key==VK_DELETE)
    {
    sprintf(tmp,"Confirmer effacement de la tâche %d",current_task);
    if (Application->MessageBox(tmp,m_ecoplan,MB_YESNO) ==IDNO) return;
    effacer_tache(current_task);
     current_task=1;
      if (nb_taches==0) current_task=0;
     else
      {  current_task=1;
         grefresh(current_task);
      }
    // AdvStringGrid1->Refresh();
    }

  if (Key==' ')
    {
      if (coche[current_task]==' ')
        {
         AdvStringGrid1->Cells[0][current_task] = AnsiString(strcoche);
         coche[current_task]= 'X';
        }
        else
       {
        AdvStringGrid1->Cells[0][current_task] = "";
         coche[current_task]= ' ';
       }
    }

 Change1();

 }
void __fastcall TplStandard::AdvStringGrid1CanEditCell(TObject *Sender,
      int ARow, int ACol, bool &CanEdit)
{
 int ch;
 CanEdit = false;
 if (ARow ==0) return;
 ch=vl_chp[1][ACol];
 if (ch_sai[ch][0]=='N') return;
 CanEdit = true;
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::AdvStringGrid1ClickCell(TObject *Sender,
      int ARow, int ACol)
{

  if ((ARow <1) || (ARow > nb_taches)) return;
  SG1Col = Cur1Col = ACol;
  SG1Row = Cur1Row = ARow;

  current_task=ARow;
 grefresh(current_task);

}
//---------------------------------------------------------------------------




void __fastcall TplStandard::AdvStringGrid1CellValidate(TObject *Sender,
      int ACol, int ARow, AnsiString &Value, bool &Valid)
{
  int a,nt;
  char tmp[250];
  if (ACol==3)  // duree
    { // verifier si numerique (sinon ca plante)
     strcpy(tmp,Value.c_str());
     a = atoi(tmp);
     if (a <=0) { Valid=false; Beep(); return; }

     duree[ARow] = a;
     Valid = true;
    }

 if (ACol==2)  // Libelle du champ
    {
     strcpy(libel[ARow],Value.c_str());
     Valid=true;
    }

 Change1();
 current_task=ARow;
 grefresh(current_task);
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid1SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
 // int a,b;
 if ((ARow>0) && (ARow <= nb_taches))
  {  current_task=ARow;
  grefresh(current_task);
  }
}

// =================================================================
//          ADVSTRINGGRID2
// =================================================================

void __fastcall TplStandard::AdvStringGrid2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 int numt,nt;
 int tl;
 int decal;
 TNum_Tache_Pred *Num_Tache_Pred;
 //int ipred,isucc;

 char tmp[250];

 // §§§§§§§§§§§§§§§§§§

 if (Key==VK_INSERT)
   {
    m_exchange[0]=0;
    sprintf(m_exchange,"%d",sommets[current_task]);
    //WriteExchange(1);
    Num_Tache_Pred = new TNum_Tache_Pred(Application);
    Num_Tache_Pred->ShowModal();
    delete Num_Tache_Pred;
    //ReadExchange(1);
    ExtractValue(tmp,m_exchange,"tache",0);
    numt = atoi(tmp);
    if ((numt <1) || (numt>9999)) return;
    nt = exist_tache(numt,nb_taches);
    if (nt==0)
     {
     Application->MessageBox("Cette tache n'existe pas",m_ecoplan,MB_OK);
     return;
     }
    if (Verif_Succ(current_task,nt))
      { Application->MessageBoxA("Cette tache est déja un successeur",m_ecoplan,MB_OK);
        return;
      }

    if (Bcl_Pred(current_task,numt))
      {
       Application->MessageBoxA("Anomalie Ordonnancement - Bouclage",m_ecoplan,MB_OK);
        return;
      }

    ExtractValue(tmp,m_exchange,"tl",0);
    tl = atoi(tmp);
    ExtractValue(tmp,m_exchange,"decal",0);
    decal = atoi(tmp);

    if (numt==sommets[current_task])        // @@@@@@@@@@@@@@
      {
      Application->MessageBox("Même numéro de tâche prédecesseur",m_ecoplan,MB_OK);
      return;
     }

    new_nb_taches = nb_taches;
    ctask=sommets[current_task];
    InsertPredSeul(ctask,numt,tl,decal);           // numt @@@@@@@@@@@@ààà nt
    InsertSuccSeul(numt,ctask,tl,decal);           //  nt  @@@@@@@@@@@@@à
    grefresh(current_task);
    }
  else if (Key == VK_DELETE)
    {
     if (Application->MessageBox("Comfirmez la suppression du lien predecesseur",m_ecoplan,MB_YESNO)== IDNO)
     return;
     numt = StrToInt(AdvStringGrid2->Cells[1][SG2Row]);
     ctask=sommets[current_task];
     RemovePredSeul(ctask,numt);
     RemoveSuccSeul(numt,ctask);
     grefresh(current_task);
    }
 Change1();
}


// =========================================================================
//      ADVSTRINGGRID3
// =========================================================================

void __fastcall TplStandard::AdvStringGrid3KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 int nt,numt;
 int tl;
 int decal;
 TNum_Tache_Succ *Num_Tache_Succ;
 //int isucc,ipred;

 char tmp[250];

 Change1();
 // §§§§§§§§§§§§§§§§§§§§§§

 if (Key==VK_INSERT)
   {
    m_exchange[0]=0;
    sprintf(m_exchange,"%d",sommets[current_task]);
    //WriteExchange(1);
    Num_Tache_Succ = new TNum_Tache_Succ(Application);
    Num_Tache_Succ->ShowModal();
    delete Num_Tache_Succ;
    //ReadExchange(1);
    ExtractValue(tmp,m_exchange,"tache",0);
    numt = atoi(tmp);
    if ((numt <1) || (numt>9999)) return; //nb_taches)) return;
    nt = exist_tache(numt,nb_taches);
    if (nt==0)
     {
     Application->MessageBox("Cette tache n'existe pas",m_ecoplan,MB_OK);
     return;
     }

     if (Verif_Pred(current_task,nt))
      { Application->MessageBoxA("Cette tache est déja un prédecesseur",m_ecoplan,MB_OK);
        return;
      }
    if (Bcl_Succ(current_task,numt))
      {
       Application->MessageBoxA("Anomalie Numéro de Tache - Bouclage",m_ecoplan,MB_OK);
        return;

      }
    ExtractValue(tmp,m_exchange,"tl",0);
    tl = atoi(tmp);
    ExtractValue(tmp,m_exchange,"decal",0);
    decal = atoi(tmp);

    if (numt==sommets[current_task])
      {
      Application->MessageBox("Même numéro de tâche successeur",m_ecoplan,MB_OK);
      return;
      }

    // insere tache successeur  (la tache en cours est current_task
    new_nb_taches = nb_taches;
    ctask=sommets[current_task];
    InsertSuccSeul(ctask,numt,tl,decal);
    InsertPredSeul(numt,ctask,tl,decal);
    grefresh(current_task);
    }
  else if (Key == VK_DELETE)
    {
     if (Application->MessageBox("Comfirmez la suppression du lien successeur",m_ecoplan,MB_YESNO)== IDNO)
     return;


     numt = StrToInt(AdvStringGrid3->Cells[1][SG3Row]);
     ctask=sommets[current_task];
     RemoveSuccSeul(ctask,numt);
     RemovePredSeul(numt,ctask);
     grefresh(current_task);
    }
}


// =========================================================================
//---------------------------------------------------------------------------

int __fastcall TplStandard::insere_tache(int pos, int dur, int nt, char *txt)
{
int a,indx,k;
char tmp[250];
a=pos;
for (indx=nb_taches;indx>=a;indx--)  // PROVISOIRE   §§§§§§§§§§§§§§§§§§
      {
       coche[indx+1]=coche[indx];
       sommets[indx+1]=sommets[indx];
       filtr[indx+1]=filtr[indx];
       tcal[indx+1]=tcal[indx];
       tmom[indx+1]=tmom[indx];
       duree[indx+1]=duree[indx];
       duree_reelle[indx+1]=duree_reelle[indx];
       // maj des predecesseurs et successeurs

       for (k=0;k<PS;k++)
         { pr[indx+1][k] = pr[indx][k];
           pr_tl[indx+1][k] = pr_tl[indx][k];
           pr_decal[indx+1][k] = pr_decal[indx][k];
           su[indx+1][k] = su[indx][k];
           su_tl[indx+1][k] = su_tl[indx][k];
           su_decal[indx+1][k] = su_decal[indx][k];
         }

       AdvStringGrid1->Cells[1][indx+1]=AdvStringGrid1->Cells[1][indx];
       av->Cells[1][indx+1]=av->Cells[1][indx];
       AdvStringGrid1->Cells[2][indx+1]=AdvStringGrid1->Cells[2][indx];
       av->Cells[2][indx+1]=av->Cells[2][indx];
       AdvStringGrid1->Cells[3][indx+1]=AdvStringGrid1->Cells[3][indx];
       av->Cells[3][indx+1]=av->Cells[3][indx];
      }

   // insertion de la tache en indice "a"
   sommets[a]=nt;
   coche[a]=' ';
   duree[a]=1;
   duree_reelle[a]=1;
   tcal[a]=1;
   tmom[a]=0;
   filtr[a]=' ';
   if (a>1) AdvStringGrid1->RowCount++;
    for (k=0;k<PS;k++)
    { pr[a][k]=0; pr_tl[a][k]=0; pr_decal[a][k]=0;
      su[a][k]=0; su_tl[a][k]=0; su_decal[a][k]=0;
    }
  su[a][1]=9999;

   // sprintf(tmp,"Nlle Tache %d",nt);
   AdvStringGrid1->Cells[1][a]=nt;
   AdvStringGrid1->Cells[2][a]=AnsiString(txt);
   av->Cells[1][a]=nt;
   av->Cells[2][a]=AnsiString(txt);
   nb_taches++;
 return 0;
}

void __fastcall TplStandard::TachesAmontssurtachesCoches1Click(
      TObject *Sender)
{
  int ind,precedent,torig, nt,ix;
  char tmp[250]; int nbt,dur_amont,design,pos;
  char libelx[100],opdesign[10];
 //  examiner la premiere tache cochées
  TfTachesAmont *tam;


for (ind=1;ind <= nb_taches; ind++)
  {
   if (coche[ind]=='X')
    {
     m_exchange[0]=0;
     sprintf(m_exchange,"%d",sommets[ind]);
     strcpy(m_exchange2,AdvStringGrid1->Cells[2][ind].c_str());
     //WriteExchange(2);
     tam = new TfTachesAmont(Application);
     tam->ShowModal();
     delete tam;
     //ReadExchange(1);
     ExtractValue(tmp,m_exchange,"null",0);
     if (strcmp(tmp,"TRUE")!=0)
       {
         ExtractValue(tmp,m_exchange,"nbt",0);
         nbt = atoi(tmp);
         ExtractValue(tmp,m_exchange,"dur",0);
         dur_amont = atoi(tmp);
         ExtractValue(opdesign,m_exchange,"design",0);
         strcpy(libelx,AdvStringGrid1->Cells[2][ind].c_str());

         // on demarre avec tache mere
         precedent = sommets[ind];
         torig = ind+1;
         for (ix=1;ix<=nbt;ix++)
          {
            nt = next_task();

            if (strcmp(opdesign,"same")==0) strcpy(tmp,libelx);
              else sprintf(tmp,"Tache Amont %d",nt);
            insere_tache(torig,dur_amont,nt,tmp);  // ,precedent,2,1, tmp);
            new_nb_taches = nb_taches;
            InsertPredSeul(precedent,nt,2,0);
            InsertSuccSeul(nt,precedent,2,0);
            pos = exist_tache(nt,new_nb_taches);
            tmom[pos]=ind;   // memorise la mere;
            precedent=nt;
            torig++;
          }
         current_task=ind;
         grefresh(current_task);
       } //if not null

   } // if coche
  } // end boucle for

}
//---------------------------------------------------------------------------


void __fastcall TplStandard::AffecterunCalendrier1Click(TObject *Sender)
{
 int ind,num_cal;
 TAffectCal *taf;
 char tmp[250];

 taf = new TAffectCal(Application);
 taf->ShowModal();
 delete taf;

 //ReadExchange(1);
 ExtractValue(tmp,m_exchange,"null",0);
 if (strcmp(tmp,"TRUE")==0)  return;
 ExtractValue(tmp,m_exchange,"ncal",0);
 num_cal = atoi(tmp);
 if ((num_cal<1) || (num_cal>5)) num_cal= 1;


 for (ind=1;ind <= nb_taches; ind++)
  {
   if (coche[ind]=='X')
    {
         tcal[ind] = num_cal;
         AdvStringGrid1->Cells[10][ind]= num_cal;
         av->Cells[10][ind]= num_cal;
    }
   } // end FOR

   current_task=1;
   //  init_calendrier();
   grefresh(current_task);
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid2CanEditCell(TObject *Sender,
      int ARow, int ACol, bool &CanEdit)
{
 CanEdit = true;
 if (ARow < 1) CanEdit = false;

 if ((ACol < 3) || (ACol > 6)) CanEdit = false;
 if  (ACol==4) CanEdit = false;
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid3CanEditCell(TObject *Sender,
      int ARow, int ACol, bool &CanEdit)
{
  CanEdit = true;
 if (ARow < 1) CanEdit = false;

 if ((ACol < 3) || (ACol > 6)) CanEdit = false;
 if  (ACol==4) CanEdit = false;
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid2CellValidate(TObject *Sender,
      int ACol, int ARow, AnsiString &Value, bool &Valid)
{
  int a; int vtask;
  char tmp[250];
  int typl,idecal;
  char stypl[10];

  strcpy(tmp,Value.c_str());
  if (ACol==3)  // duree
    { // verifier si numerique (sinon ca plante)
     vtask = atoi(AdvStringGrid2->Cells[1][ARow].c_str());
     vtask=exist_tache(vtask,nb_taches);
     a = atoi(tmp);
     if (a <=0) { Valid=false; Beep(); return; }

     duree[vtask] = a;
     Valid = true;

     grefresh(current_task);
     return;
    }
  if (ACol==5)  // Type
    { Valid=false;
      vtask = atoi(AdvStringGrid2->Cells[1][ARow].c_str());
      // vtask=exist_tache(vtask,nb_taches);
      strupr(tmp);
      if (strcmp(tmp,"FD")==0) { Valid=true; AdvStringGrid2->Cells[5][ARow]="FD"; }
      if (strcmp(tmp,"FD")==0) { Valid = true; AdvStringGrid2->Cells[5][ARow]="FF"; }
      if (strcmp(tmp,"AM")==0) { Valid=true;  AdvStringGrid2->Cells[5][ARow]="AM"; }
      if (strcmp(tmp,"DD")==0) { Valid=true;  AdvStringGrid2->Cells[5][ARow]="DD"; }
      if ((strcmp(tmp,"FD")==0) ||
           (strcmp(tmp,"FF")==0) ||
           (strcmp(tmp,"DD")==0) ||
           (strcmp(tmp,"AM")==0))
       {
        idecal = atoi(AdvStringGrid2->Cells[6][ARow].c_str()); typl=0;
        typl=0;
        if (strcmp(tmp,"FD")==0) typl = 0;
        else if (strcmp(tmp,"FF")==0) typl= 1;
        else if (strcmp(tmp,"AM")==0) typl= 2;
        else if (strcmp(tmp,"DD")==0) typl= 3;
        Valid=true;
        new_nb_taches=nb_taches;
        InsertPredSeul(current_task,vtask,typl,idecal);
        InsertSuccSeul(vtask,current_task,typl,idecal);
        grefresh(current_task);
        return;
       }
       else { Valid=false; Beep(); return; }
    }

  if (ACol==6) // Decal
     {
      vtask = atoi(AdvStringGrid2->Cells[1][ARow].c_str());
      idecal = atoi(tmp);  // decalage
      strcpy(stypl,AdvStringGrid2->Cells[5][ARow].c_str());
      strupr(stypl);
        if (strcmp(stypl,"FD")==0) typl = 0;
        if (strcmp(stypl,"FF")==0) typl= 1;
        if (strcmp(stypl,"AM")==0) typl= 2;
        if (strcmp(stypl,"DD")==0) typl= 3;
        Valid=true;
        new_nb_taches=nb_taches;
        InsertPredSeul(current_task,vtask,typl,idecal);
        InsertSuccSeul(vtask,current_task,typl,idecal);
     grefresh(current_task);
     return;
     }
 Change1();
}
//---------------------------------------------------------------------------


int __fastcall  TplStandard::grefresh(int task)
{

 Compute_PlusTotA();
 Compute_PlusTardA();
 DrawGantt(task,-20);
 Refresh_Pred_Succ(task);
 return 0;
}


/////////////////////////////////////////////////////////////////

int __fastcall TplStandard::Verif_Succ(int t,int a)
{
 int exist,xtsucc,isucc;
 exist=0;
 isucc=1;
 while (su[t][isucc]!=0)
    { xtsucc=su[t][isucc];
      xtsucc=exist_tache(xtsucc,nb_taches);
      if (xtsucc==a) exist = 1;
      isucc++;
    }
 return exist;
}


int __fastcall TplStandard::Verif_Pred(int t,int a)
{
 int exist,xtpred,ipred;
 exist=0;
 ipred=1;
 while (pr[t][ipred]!=0)
    { xtpred=pr[t][ipred];
      xtpred=exist_tache(xtpred,nb_taches);
      if (xtpred==a) exist = 1;
      ipred++;
    }
 return exist;
}

int __fastcall TplStandard::Verif_Decal(int t, int decal)
{
 int dist1,dist2,task;
 task = exist_tache(t,nb_taches);
 dist1 = deb_plus_tot[task];
 dist2 = fin_plus_tot[task];
 if ((dist2+decal+1) < dist1) return 0;
 else return 1;
}

void __fastcall TplStandard::AdvStringGrid3CellValidate(TObject *Sender,
      int ACol, int ARow, AnsiString &Value, bool &Valid)
{
    int a; int vtask;
  char tmp[250];
  int typl,idecal;
  char stypl[10];

  strcpy(tmp,Value.c_str());
  if (ACol==3)  // duree
    { // verifier si numerique (sinon ca plante)
     vtask = atoi(AdvStringGrid3->Cells[1][ARow].c_str());
     vtask=exist_tache(vtask,nb_taches); // OK
     a = atoi(tmp);
     if (a <=0) { Valid=false; Beep(); return; }

     duree[vtask] = a;
     Valid = true;
     grefresh(current_task);
     return;
    }
  if (ACol==5)  // Type
    { Valid=false;
      vtask = atoi(AdvStringGrid3->Cells[1][ARow].c_str());
      // vtask=exist_tache(vtask,nb_taches);
      strupr(tmp);
      if (strcmp(tmp,"FD")==0) { Valid=true;  AdvStringGrid3->Cells[5][ARow]="FD"; }
      if (strcmp(tmp,"FF")==0) { Valid = true; AdvStringGrid3->Cells[5][ARow]="FF"; }
      if (strcmp(tmp,"AM")==0) { Valid=true; AdvStringGrid3->Cells[5][ARow]="AM"; }
      if (strcmp(tmp,"DD")==0) { Valid=true;  AdvStringGrid3->Cells[5][ARow]="DD"; }

      if ((strcmp(tmp,"FD")==0) ||
           (strcmp(tmp,"FF")==0) ||
           (strcmp(tmp,"AM")==0) ||
           (strcmp(tmp,"DD")==0))
       {
        idecal = atoi(AdvStringGrid3->Cells[6][ARow].c_str()); typl=0;
        typl=0;
        if (strcmp(tmp,"FD")==0) typl = 0;
        else if (strcmp(tmp,"FF")==0) typl= 1;
        else if (strcmp(tmp,"AM")==0) typl= 2;
        else if (strcmp(tmp,"DD")==0) typl= 3;
        Valid=true;
        new_nb_taches=nb_taches;
        InsertSuccSeul(current_task,vtask,typl,idecal);
        InsertPredSeul(vtask,current_task,typl,idecal);
        grefresh(current_task);
        return;
       }
       else { Valid=false; Beep(); return; }
    }

  if (ACol==6) // Decal
     {
      vtask = atoi(AdvStringGrid3->Cells[1][ARow].c_str());
      idecal = atoi(tmp);  // decalage
      strcpy(stypl,AdvStringGrid3->Cells[5][ARow].c_str());
        strupr(stypl);
        if (strcmp(stypl,"FD")==0) typl = 0;
        if (strcmp(stypl,"FF")==0) typl= 1;
        if (strcmp(stypl,"AM")==0) typl= 2;
        if (strcmp(stypl,"DD")==0) typl= 3;

        if (idecal < 0)
           { int rc = Verif_Decal(current_task,idecal);
             if (rc ==0)
               {
                Application->MessageBoxA("Decalage négatif incorrect",m_ecoplan,MB_OK);
                Valid = false; return;
               }
           }

        Valid=true;
        new_nb_taches=nb_taches;
        InsertSuccSeul(current_task,vtask,typl,idecal);
        InsertPredSeul(vtask,current_task,typl,idecal);
        grefresh(current_task);
     return;
     }
 Change1();
}
//---------------------------------------------------------------------------



void __fastcall TplStandard::AdvStringGrid2SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
 SG2Col=ACol;
 SG2Row=ARow; // pour pouvoir effacer
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::AdvStringGrid3SelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
 SG3Col=ACol;
 SG3Row=ARow; // pour pouvoir effacer
}
//---------------------------------------------------------------------------



int __fastcall TplStandard::verifdate(char *dt10)
{
 char d[50];     // format DD/MM/AAAA    et stockage dans std_date et reverse_date
 char tmp[10];
 strcpy(d,dt10);
 d[2]=0; JourVerif=atoi(d);
 d[5]=0; MoisVerif=atoi(d+3);
 d[10]=0; AnVerif=atoi(d+6);


 std_date[0]=0; reverse_date[0]=0;

 if ((JourVerif ==0) || (JourVerif > 31))
   {
    Application->MessageBoxA("Jour Incorrect",m_ecoplan,MB_OK);
    return 1;
   }
 if ((MoisVerif == 0) || (MoisVerif > 12))
   {
    Application->MessageBoxA("Mois Incorrect",m_ecoplan,MB_OK);
    return 1;
   }
 if ((AnVerif < 2000) || (AnVerif > 2050))
   {
    Application->MessageBoxA("Année Incorrecte",m_ecoplan,MB_OK);
    return 1;
   }

sprintf(std_date,"%02d/%02d/%02d",JourVerif,MoisVerif,AnVerif%100);
sprintf(reverse_date,"%02d/%02d/%02d",AnVerif,MoisVerif,JourVerif%100);
return 0;
}

int __fastcall TplStandard::verifdate8(char *dt)
{
 char d[50];     // format DD/MM/AA    et stockage dans std_date et reverse_date
 char tmp[10];
 strcpy(d,dt);
 d[2]=0; JourVerif=atoi(d);
 d[5]=0; MoisVerif=atoi(d+3);
 d[8]=0; AnVerif=atoi(d+6);


 std_date[0]=0; reverse_date[0]=0;

 if ((JourVerif == 0) || (JourVerif > 31))
   {
    Application->MessageBoxA("Jour Incorrect",m_ecoplan,MB_OK);
    return 1;
   }
 if ((MoisVerif == 0) || (MoisVerif > 12))
   {
    Application->MessageBoxA("Mois Incorrect",m_ecoplan,MB_OK);
    return 1;
   }
 if ((AnVerif == 0) || (AnVerif > 50))
   {
    Application->MessageBoxA("Année Incorrecte",m_ecoplan,MB_OK);
    return 1;
   }

sprintf(std_date,"%02d/%02d/%02d",JourVerif,MoisVerif,AnVerif%100);
sprintf(reverse_date,"%02d/%02d/%02d",AnVerif,MoisVerif,JourVerif%100);
return 0;
}


void __fastcall TplStandard::AdvStringGrid1GetFormat(TObject *Sender,
      int ACol, TSortStyle &AStyle, AnsiString &aPrefix,
      AnsiString &aSuffix)
{

//TSortStyle = (ssAutomatic, ssAlphabetic, ssNumeric, ssDate, ssAlphaNoCase, ssAlphaCase,
//ssShortDateEU, ssShortDateUS, ssCustom, ssFinancial);

switch(ACol) {
case 1: AStyle=ssNumeric; //AStyle=ssAlphaNoCase;
break;
case 2: AStyle=ssAlphaNoCase;
break;
case 3: AStyle=ssNumeric;
break;
case 4: ssShortDateEU; //  AStyle=ssDate;
break;
case 5: AStyle=ssNumeric;
aSuffix="pk";
break;
case 6: AStyle=ssNumeric;
aPrefix="$";
break;

}

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::validate_avancement()
{
 if (!global_valid) return;
 // row_avancement est a l'origine
 //asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];
 //asAvanc->Cells[7][row_avancement] = AdvStringGrid4->Cells[8][1];
 //asAvanc->Cells[8][row_avancement] = AdvStringGrid4->Cells[6][1];
 //asAvanc->Cells[9][row_avancement] = AdvStringGrid4->Cells[5][1];
// asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];
// asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];
// asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];
// asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];

}

//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid4CanEditCell(TObject *Sender,
      int ARow, int ACol, bool &CanEdit)
{
 int ch;
 CanEdit = false;
 if (ARow ==0) return;
 ch=vl_chp[4][ACol];
 if (ch_sai[ch][0]=='N') return;
 CanEdit = true;
}
//---------------------------------------------------------------------------

int  __fastcall TplStandard::CopieAvancePrev(char *fn)
{

 int recdata; char Key[100],RetKey[100];
 int count; int lim;
 char tmp[250]; int nt;
 char ntach[10];

 avanc->OpenEngine(fn,120,"act","don");
 avanc->SetIndexMode(0,0);
 // fabriquer d'apres la grille du previsionnel

 lim = AdvStringGrid1->RowCount;

 for (count=1;count<lim;count++)
   {
    sprintf(ntach,"%d",sommets[count]);
 //   getvalue(1,count,1); strcpy(ntach,adv);
    if (sommets[count] !=0) //strlen(ntach))
      {
       nt=atoi(ntach);
       buffer[0]=0;
       strcat(buffer,"<nt>"); strcat(buffer,ntach); strcat(buffer,"</nt>");
       sprintf(tmp,"<da>%02d-%02d-%02d</da>",JourAvanc,MoisAvanc,AnAvanc%100);
       strcat(buffer,tmp);
       getvalue(1,count,2); concat("lb");
       getvalue(1,count,4); concat("ddp");
       getvalue(1,count,3); concat("dp");
       getvalue(1,count,5); concat("dfp");
       getvalue(1,count,9); concat("cal");
       getvalue(1,count,4); concat("ddr");
       getvalue(1,count,3); concat("dr");
       getvalue(1,count,5); concat("dfr");
       getvalue(1,count,8); concat("mt");
       getvalue(1,count,4); concat("dtposs");
       strcpy(adv,"0"); concat("rimp"); concat("rtot");
       strcpy(adv,"100"); concat("prest");
       getvalue(1,count,3); concat("jrest");
       getvalue(1,count,8); concat("margrl");
       recdata = avanc->GetNewRecordNumber();
       sprintf(Key,"T%04d",nt);
       avanc->WriteKey(0,Key,recdata);
       avanc->WriteRecord(buffer, strlen(buffer)+1);
      }
    }
avanc->CloseEngine(); avanc->~genbase();
return 0;
}

int  __fastcall TplStandard::CopieAvance(char *suf,char *fn)
{
 char tmp[250];
 int rc,recdata,recold; char Key[100],RetKey[100];
 rc = avanc->OpenEngine(fn,120,"act","don");
 rc = avanc->SetIndexMode(0,0);


 strcpy(tmp,LocalBase); strcat(tmp,suf);
 rc = oldavanc->OpenEngine(tmp,120,"act","don");
 rc = oldavanc->SetIndexMode(0,0);

 rc = oldavanc->ReadFirstKey(0,RetKey,&recold);
 while (rc)
   {
    rc=oldavanc->ReadRecord(buffer,recold);
    recdata = avanc->GetNewRecordNumber();
    rc = avanc->WriteKey(0,RetKey,recdata);
    rc = avanc->WriteRecord(buffer, strlen(buffer)+1);
    rc = oldavanc->ReadNextKey(RetKey,&recold);
    strcpy(Key,RetKey);
   }

 oldavanc->CloseEngine(); oldavanc->~genbase();
 avanc->CloseEngine(); avanc->~genbase();
 return 0;
}


int __fastcall TplStandard::Load_Avanc(char *fn,bool concern)
{
 char Key[100], RetKey[100];
 int rc, recdata;
 genbase *avanc;
 char dt1[15];char dt2[15];
 bool ok; int count,zcal;
 char tmp[250];
 int dist1,dist2,dist3,dur,i,j;
 int a1,m1,j1,a2,m2,j2;
 float fdata,fdata2;
 int result2,x;

 flag_alert=false;
 flag_alertPred=false;

 for (j=1;j<AdvStringGrid4->ColCount;j++)  AdvStringGrid4->Cells[j][1]="";
 for (i=1;i<AdvStringGrid5->RowCount;i++)
    {
     for (j=1;j<AdvStringGrid5->ColCount;j++)  AdvStringGrid5->Cells[j][1]="";

    }
  AdvStringGrid5->RowCount = 2;

    // On ouvre maintenant le fichier et on charge les données
  avanc = new  genbase();    // ne pas enlever, sinon erreur
  rc = avanc->OpenEngine(FileNameAvanc,120,"act","don");   //512 - 8
  rc = avanc->SetIndexMode(0,0);

  rc = avanc->ReadFirstKey(0,RetKey,&recdata);
  count=0;
  while (rc)
   {
    rc=avanc->ReadRecord(buffer,recdata);
    buffer[rc]=0;
    ExtractValue(tmp,buffer,"ddp",0);  // debut previsionnel
    // mettre sous la forme AA-MM-JJ
    dt2[0]=tmp[6]; dt2[1]=tmp[7]; dt2[2]='-';dt2[3]=tmp[3];
    dt2[4]=tmp[4];dt2[5]='-'; dt2[6]=tmp[0];dt2[7]=tmp[1];



    ok=false;
    if (!concern) ok=true;
    //else if  (strcmp(dt1,dt2) >=0) ok=true;  // tache concernee

    ok =true;
    if (ok)
      { count++;
        if (count>1) asAvanc->RowCount++;
        ExtractValue(tmp,buffer,"nt",0); setvalue(5,count,39,tmp);
        ExtractValue(tmp,buffer,"da",0); setvalue(5,count,70,tmp);
        ExtractValue(tmp,buffer,"lb",0); setvalue(5,count,40,tmp);
        ExtractValue(tmp,buffer,"ddr",0); setvalue(5,count,41,tmp);
        ExtractValue(tmp,buffer,"dr",0); setvalue(5,count,42,tmp);
        ExtractValue(tmp,buffer,"dfr",0); setvalue(5,count,43,tmp);
        ExtractValue(tmp,buffer,"rimp",0); setvalue(5,count,44,tmp);
        ExtractValue(tmp,buffer,"rtot",0); setvalue(5,count,45,tmp);
        ExtractValue(tmp,buffer,"ddp",0); setvalue(5,count,46,tmp);
        ExtractValue(tmp,buffer,"dp",0); setvalue(5,count,47,tmp);
        ExtractValue(tmp,buffer,"dfp",0); setvalue(5,count,48,tmp);
        ExtractValue(tmp,buffer,"cal",0); setvalue(5,count,62,tmp);
        ExtractValue(tmp,buffer,"mt",0); setvalue(5,count,66,tmp);
        ExtractValue(tmp,buffer,"dtposs",0); setvalue(5,count,69,tmp);
        ExtractValue(tmp,buffer,"prest",0); setvalue(5,count,71,tmp);
        ExtractValue(tmp,buffer,"jrest",0); setvalue(5,count,72,tmp);
        ExtractValue(tmp,buffer,"margrl",0); setvalue(5,count,73,tmp);
        //ExtractValue(tmp,buffer,"pourcrest",0); setvalue(5,count,69,tmp);
        // on attribue un %
        getvalue(5,count,43); strcpy(dt1,adv);   // fin reelle
        dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[8]=0; a1=atoi(dt1+6);
        dist1 = convert_date(a1+2000,m1,j1);
         strcpy(dt2,Label12->Caption.c_str());  // date avancement
         dt2[2]=0; j2=atoi(dt2);  dt2[5]=0; m2=atoi(dt2+3);  dt2[8]=0; a2=atoi(dt2+6);
        dist2 = convert_date(a2+2000,m2,j2);
        getvalue(5,count,41); strcpy(dt1,adv);   // debut reel
        dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[8]=0; a1=atoi(dt1+6);
        dist3 = convert_date(a1+2000,m1,j1);

        if (dist1<=dist2)  // la tache est supposee terminée
         {
          setvalue(5,count,71,"0");
          setvalue(5,count,72,"0");
         }
        else if (dist2<dist3)  // tache pas encore commencée
         {
          setvalue(5,count,71,"100");
          getvalue(5,count,42); dur=atoi(adv);
          sprintf(tmp,"%d",dur); setvalue(5,count,72,tmp);
         }
        else // tache a cheval sur date avancement
         {
          // calcul du pourcentage et jours restants
          getvalue(5,count,62);  zcal=atoi(adv);
          getvalue(5,count,43); strcpy(dt1,adv);   // fin reelle
          strcpy(dt2,Label12->Caption.c_str());  // date avancement
          comp_dist_dates(dt2,dt1,zcal,0);
          //NB2 = nb jours restants

          sprintf(tmp,"%d",NB2);
          setvalue(5,count,72,tmp);
          fdata = (float) NB2;
          // duree
          getvalue(5,count,42); result2=atoi(adv);
          fdata2 = (float) result2;
          if (fdata2==0.0) fdata2=1.0;
          x= ( fdata *100.0) / (fdata2);
          sprintf(tmp,"%d",x);
          setvalue(5,count,71,tmp);
         }

      } // if OK

    rc = avanc->ReadNextKey(RetKey,&recdata);
   } // end while
 asAvanc->RowCount = count+1;
 avanc->CloseEngine(); avanc->~genbase();
 fname->Caption = AnsiString(FileNameAvanc);

 Image_Avanc("Avancement");
 return 0;

}



void __fastcall TplStandard::btDatActClick(TObject *Sender)
{
TActual *tac;
 char tmp[250];
 char dt1[15];char dt2[15];
 int i,j,ok,indx;
 int count,rc,nt,l,cnt,x;
 bool conc;
 char tachconcern[20];
 genbase *avanc;
 char nameact[255];
 char *p;
 char Key[100],RetKey[100];
 int  recdata;
 char buffer[1000];
 char str[200];

 bool flag_new;
 char suffixe[250];



 FLAG_AVANC_LOADED = false;
 // Change1();
 strcpy(m_exchange,dateavanc);
 strcpy(m_exchange2,LocalBase);
 //WriteExchange(2);
 tac = new TActual(Application);
 tac->ShowModal();
 delete tac;
 //ReadExchange(1);
 l=ExtractValue(tmp,m_exchange,"null",0);
 if (strcmp(tmp,"TRUE")==0) return;

  l=ExtractValue(dt1,m_exchange,"da",0);
  if (l!=10)
    {
     Application->MessageBoxA("Date Incorrecte",m_ecoplan,MB_OK);
     return;
    }
  rc = verifdate(dt1);
  if (rc>0) return;
  Label12->Caption = AnsiString(std_date);

  l=ExtractValue(tachconcern,m_exchange,"tc",0);
  conc=false; if (strcmp(tachconcern,"true")==0) conc=true;
  l=ExtractValue(tmp,m_exchange,"new",0);
  flag_new=false; if(strcmp(tmp,"true")==0) flag_new=true;
  l=ExtractValue(suffixe,m_exchange,"file",0)==0;

  //suffixe[2]='-';  suffixe[5]='-';
  count=0;

 AnAvanc=AnVerif;MoisAvanc=MoisVerif;JourAvanc=JourVerif;
 // pour verifier les dates dt1 et dt2
 sprintf(dt1,"%02d-%02d-%02d",AnAvanc%100,MoisAvanc,Jour);

 // ou bien il existe deja un avancement, sinon, on convertit
 // en date, a partir de date au plus tot prev;

 // on nettoie la stringgrid !

 for (i=1;i<asAvanc->ColCount;i++){for (j=1;j<=asAvanc->RowCount;j++) asAvanc->Cells[i][j]="";}
 asAvanc->RowCount=2;
 // // lecture du fichier pour trouver les avancements possibles
 // examen des dates d'avancement de toutes les taches
  cnt= Explode('@',dateavanc);

  if (cnt ==0)
     {flag_avanc=false;
      // on construit isam d'apres le previsionnel

      strcpy(tmp,Label12->Caption.c_str());
      p=strstr(tmp,"/"); if (p) *p='-';
      p=strstr(tmp,"/"); if (p) *p='-';
      strcat(dateavanc,tmp); sprintf(tmp,"-%03d@",1); strcat(dateavanc,tmp);
      x=1;
      sprintf(tmp,"%s-%02d-%02d-%02d-%03d",LocalBase,AnAvanc%100,MoisAvanc,JourAvanc,x);

      strcpy(FileNameAvanc,tmp);
      strcpy(isamname,tmp); strcat(isamname,".act"); unlink(isamname);
      strcpy(isamname,tmp); strcat(isamname,".don"); unlink(isamname);
      CopieAvancePrev(FileNameAvanc); //isamname);

     }
   else
     {
      if (flag_new)
       {
        count= Explode('@',dateavanc); strcpy(tmp,Label12->Caption.c_str());
        strcat(dateavanc,tmp); sprintf(tmp,"-%03d@",count+1); strcat(dateavanc,tmp);
        sprintf(isamname,"%s-%02d-%02d-%02d-%03d",LocalBase,AnAvanc%100,MoisAvanc,JourAvanc,count+1);
        strcpy(FileNameAvanc,isamname);
        strcpy(tmp,isamname); strcat(tmp,".act"); unlink(tmp); // delete just in case
        strcpy(tmp,isamname); strcat(tmp,".don"); unlink(tmp); // delete former
        CopieAvance(suffixe,FileNameAvanc);
       }

      else // on a le fichier ancien
       {
        strcpy(FileNameAvanc,LocalBase); strcat(FileNameAvanc,suffixe);
       }
     }


  Change1();

  Load_Avanc(FileNameAvanc,conc);

 avanc = new  genbase();    // ne pas enlever, sinon erreur
 rc = avanc->OpenEngine(FileNameAvanc,120,"act","don");   //512 - 8
 rc = avanc->SetIndexMode(0,0);
 //int  nbrec = avanc->NumberOfKeys(0);

//    Compute_DateDebutPossible();

  btSavAct->Enabled = true;
  fname->Caption = AnsiString(FileNameAvanc);

  FLAG_AVANC_LOADED = true;
  sprintf(tmp,"%d",count);
  Label22->Caption = AnsiString(tmp);

  Planning_Defaut();



}
//---------------------------------------------------------------------------


void __fastcall TplStandard::btSavActClick(TObject *Sender)
{
 // preparer nouvelle date pour string dateavanc.
 int count; int ix,ij; char tmp[250]; char cnt[100];
 int rc; int nt;
 char Key[100]; char RetKey[100];
 int recdata;
// int nbrec;

 // boucle pour sauver les valeurs de asAvanc

 count = asAvanc->RowCount;

 // avanc->CloseEngine(); avanc->~genbase();
 avanc = new  genbase();    // ne pas enlever, sinon erreur
 rc = avanc->OpenEngine(FileNameAvanc,120,"act","don");   //512 - 8
 rc = avanc->SetIndexMode(0,0);

 //nbrec = avanc->NumberOfKeys(0);

 for (ix=1;ix<count;ix++)
  {
   getvalue(5,ix,39); nt=atoi(adv);
   sprintf(Key,"T%04d",nt);
   rc=avanc->ReadDirectKey(0,Key,RetKey,&recdata);
   if (rc)
     { buffer[0]=0;

      getvalue(5,ix,39); concat("nt");
      getvalue(5,ix,70); concat("da");
      getvalue(5,ix,40); concat("lb");

      getvalue(5,ix,41); concat("ddr");
      getvalue(5,ix,42); concat("dr");
      getvalue(5,ix,43); concat("dfr");
      getvalue(5,ix,44); concat("rimp");
      getvalue(5,ix,45); concat("rtot");
      getvalue(5,ix,46); concat("ddp");
      getvalue(5,ix,47); concat("dp");
      getvalue(5,ix,48); concat("dfp");
      getvalue(5,ix,62); concat("cal");
      getvalue(5,ix,66); concat("mt");
      getvalue(5,ix,69); concat("dtposs");
      getvalue(5,ix,71); concat("prest");
      getvalue(5,ix,72); concat("jrest");
      getvalue(5,ix,73); concat("margrl");


      avanc->RewriteRecord(buffer,strlen(buffer)+1,recdata);
     }
   else Application->MessageBoxA("Tache non trouvée dans Fichier",m_ecoplan,MB_OK);
  }

 avanc->CloseEngine(); avanc->~genbase();
 avanc = new  genbase();    // ne pas enlever, sinon erreur
 rc = avanc->OpenEngine(FileNameAvanc,120,"act","don");   //512 - 8
 rc = avanc->SetIndexMode(0,0);

 FLAG_AVANC_LOADED = true;


 Application->MessageBoxA("Actualisation Saugardée",m_ecoplan,MB_OK);
}
//---------------------------------------------------------------------------

int __fastcall TplStandard::concat(char *tag)
{
 strcat(buffer,"<"); strcat(buffer,tag); strcat(buffer,">");
 strcat(buffer,adv);
 strcat(buffer,"</"); strcat(buffer,tag); strcat(buffer,">");
 return 0;
}


void __fastcall TplStandard::ScrollBar6Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
 int x1,x2;
 x2=ScrollBar6->Position - 50;
 x1=int (ScrollBar1->Position*nb_taches/100)+1;

 DrawMiniGantt(x1,x2);

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::ScrollBar5Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
 int x;
 x=ScrollBar5->Position - 50;
 DrawMiniGantt(current_task,x);
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TplStandard::btRecalculClick(TObject *Sender)
{
 init_calendrier();
 current_task=1;
 grefresh(current_task);
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::Remplir_asTri()
{
 int i,cnt;
 Clean_Grid(asTri,2);
 cnt=0;
 for (i=1;i<=nb_taches;i++)
   {
    if (filtr[i]=='X')
     {
      cnt++;
      if (cnt>1) asTri->RowCount++;
      asTri->Cells[0][cnt]="N";  // normal
      asTri->Cells[20][cnt]=IntToStr(sommets[i]);
      asTri->Cells[21][cnt]=AnsiString(libel[i]);
      asTri->Cells[22][cnt]=IntToStr(duree[i]);

      asTri->Cells[23][cnt]=av->Cells[4][i];
      asTri->Cells[24][cnt]=av->Cells[5][i];
      asTri->Cells[28][cnt]=av->Cells[21][i];
      asTri->Cells[29][cnt]=av->Cells[22][i];

      asTri->Cells[32][cnt]=av->Cells[8][i];

      // ajouter aussi les criteres
      asTri->Cells[2][cnt]=av->Cells[41][i];
      asTri->Cells[3][cnt]=av->Cells[42][i];
      asTri->Cells[4][cnt]=av->Cells[43][i];
      asTri->Cells[5][cnt]=av->Cells[44][i];
      asTri->Cells[6][cnt]=av->Cells[45][i];
      asTri->Cells[7][cnt]=av->Cells[46][i];
      asTri->Cells[8][cnt]=av->Cells[47][i];
      asTri->Cells[9][cnt]=av->Cells[48][i];

      asTri->Cells[11][cnt]=av->Cells[51][i];
      asTri->Cells[12][cnt]=av->Cells[52][i];
      asTri->Cells[13][cnt]=av->Cells[53][i];
      asTri->Cells[14][cnt]=av->Cells[54][i];
      asTri->Cells[15][cnt]=av->Cells[55][i];
      asTri->Cells[16][cnt]=av->Cells[56][i];
      asTri->Cells[17][cnt]=av->Cells[57][i];
      asTri->Cells[18][cnt]=av->Cells[58][i];

     }
   }


}


int  __fastcall TplStandard::Exec_Alpha(char *ch,char *cond,char *v1,char *v2)
{
 int result;
 result=0;
 if (strcmp(cond,"egal à")==0)
   {
    if(strcmp(ch,v1)==0) result=1;
   }
 else if (strcmp(cond,"différent de")==0)
   {
    if (strcmp(ch,v1)!=0) result=1;
   }
 else if (strcmp(cond,"inférieur à")==0)
   {
    if (strcmp(ch,v1) <0) result=1;
   }
 else if (strcmp(cond,"inférieur ou égal à")==0)
   {
    if (strcmp(ch,v1)<=0) result=1;
   }
 else if (strcmp(cond,"supérieur à")==0)
   {
    if (strcmp(ch,v1) > 0) result=1;
   }
 else if (strcmp(cond,"supérieur ou égal à")==0)
   {
    if (strcmp(ch,v1) >= 0) result=1;
   }
 else if (strcmp(cond,"compris entre")==0)
   {
    if ((strcmp(ch,v1)>=0)&&(strcmp(ch,v2)<=0)) result=1;
   }
 else if (strcmp(cond,"non compris entre")==0)
   {
    if ((strcmp(ch,v1)<= 0) ||(strcmp(ch,v2)>=0)) result=1;
   }
 else if (strcmp(cond,"contient")==0)
   {

   }
 else if (strcmp(cond,"ne contient pas")==0)
   {

   }
 else if (strcmp(cond,"contient masque")==0)
   {

   }
 else if (strcmp(cond,"ne contient pas masque")==0)
   {

   }


 return result;
}

int  __fastcall TplStandard::Exec_Num(char *ch,char *cond,char *v1,char *v2)
{
 int result,x1,x2,c;
 result=0;
 c=atoi(ch); x1=atoi(v1); x2=atoi(v2);

 if (strcmp(cond,"egal à")==0)
   { if (c==x1) result=1;
   }
 else if (strcmp(cond,"différent de")==0)
   {
    if (c!=x2) result=1;
   }
 else if (strcmp(cond,"inférieur à")==0)
   {
    if (c<x1) result=1;
   }
 else if (strcmp(cond,"inférieur ou égal à")==0)
   {
    if (c<=x1) result=1;
   }
 else if (strcmp(cond,"supérieur à")==0)
   {
    if (c>x1) result=1;
   }
 else if (strcmp(cond,"supérieur ou égal à")==0)
   {
    if (c>=x1) result=1;
   }
 else if (strcmp(cond,"compris entre")==0)
   {
    if ((c>=x1) && (c<=x2)) result=1;
   }
 else if (strcmp(cond,"non compris entre")==0)
   {
    if ((c<=x1) || (c>=x2)) result = 1;
   }
 else if (strcmp(cond,"contient")==0)
   {

   }
 else if (strcmp(cond,"ne contient pas")==0)
   {

   }
 else if (strcmp(cond,"contient masque")==0)
   {

   }
 else if (strcmp(cond,"ne contient pas masque")==0)
   {

   }


 return result;
}

int  __fastcall TplStandard::Exec_Date(char *ch,char *cond,char *v1,char *v2)
{
 int result;  char c[15],d[15],f[15];
  result=0;
 // convertir date au format correct
 c[0]=ch[6]; c[1]=ch[7]; c[2]=ch[3]; c[3]=ch[4]; c[4]=ch[0]; c[5]=ch[1]; c[6]=0;
 d[0]=v1[6]; d[1]=v1[7]; d[2]=v1[3]; d[3]=v1[4]; d[4]=v1[0]; d[5]=v1[1]; d[6]=0;
 f[0]=v2[6]; f[1]=v2[7]; f[2]=v2[3]; f[3]=v2[4]; f[4]=v2[0]; f[5]=v2[1]; f[6]=0;

 if (strcmp(cond,"egal à")==0)
   {
       if(strcmp(c,d)==0) result=1;
   }
 else if (strcmp(cond,"différent de")==0)
   {
    if (strcmp(c,d)!=0) result=1;
   }
 else if (strcmp(cond,"inférieur à")==0)
   {
    if (strcmp(c,d) <0) result=1;
   }
 else if (strcmp(cond,"inférieur ou égal à")==0)
   {
    if (strcmp(c,d)<=0) result=1;
   }
 else if (strcmp(cond,"supérieur à")==0)
   {
    if (strcmp(c,d) > 0) result=1;
   }
 else if (strcmp(cond,"supérieur ou égal à")==0)
   {
    if (strcmp(c,d) >= 0) result=1;
   }
 else if (strcmp(cond,"compris entre")==0)
   {
    if ((strcmp(c,d)>=0)&&(strcmp(c,f)<=0)) result=1;
   }
 else if (strcmp(cond,"non compris entre")==0)
   {
    if ((strcmp(c,d)<= 0) ||(strcmp(c,f)>=0)) result=1;
   }
 else if (strcmp(cond,"contient")==0)
   {
    if (strcmp(c,d)==0) result = 1;
   }
 else if (strcmp(cond,"ne contient pas")==0)
   {
    if (strstr(c,d)== NULL) result=1;
   }
 else if (strcmp(cond,"contient masque")==0)
   {
    // if (strstr(
   }
 else if (strcmp(cond,"ne contient pas masque")==0)
   {

   }

   return result;
}

void __fastcall TplStandard::Exec_Pas_Pas(char *str)
{
 int col; char lib[250];  int cnt,i,val,result;
 char condition[50]; char champ[100]; char init[10];
 char val1[50],val2[50];
 char action[50];
 ExtractValue(lib,str,"C",0);
 ExtractValue(condition,str,"R",0);
 strlwr(condition);
 ExtractValue(val1,str,"V1",0);
 ExtractValue(val2,str,"V2",0);
 ExtractValue(action,str,"A",0);
 ExtractValue(init,str,"I",0);
 strlwr(action);
 for (i=0;i<=nb_taches;i++) filtint[i]=' ';

 if (strcmp(init,"T")==0)
   {     for (i=1;i<=nb_taches;i++) filtr[i]='X'; }
 if (strcmp(init,"N")==0)
   {     for (i=1;i<=nb_taches;i++) filtr[i]=' '; }

 col = RechercheCol(lib);
 if (col==0) return;
 // CONTROL contient le type de données  A,N,D

 cnt=av->RowCount;
 for (i=1;i<cnt;i++)
   {
    strcpy(champ,av->Cells[col][i].c_str());

    if (strcmp(CONTROL,"A")==0)
     {  result = Exec_Alpha(champ,condition,val1,val2);
        if (result) filtint[i]='X';
     }
    if (strcmp(CONTROL,"N")==0)
     {  result = Exec_Num(champ,condition,val1,val2);
        if (result) filtint[i]='X';
     }
    if (strcmp(CONTROL,"D")==0)
     {  result = Exec_Date(champ,condition,val1,val2);
        if (result) filtint[i]='X';
     }

     if ((strcmp(action,"ajouter")==0)&&(result)) filtr[i]='X';
     else if ((strcmp(action,"supprimer")==0) &&(result)) filtr[i]=' ';
     else if ((strcmp(action,"ajouter sauf")==0) &&  (!result)) filtr[i]='X';
     else if ((strcmp(action,"supprimer sauf")==0) && (!result)) filtr[i]=' ';

   }


}


int __fastcall TplStandard::Exec_Filter(int mod, char *filter)
{
 // on nettoye toutes les "grids"
 char fxname[250];
 int i; int nbt,t,count;
 int rc,recdata;
 char RetKey[100],tmp[1000];
 char *p;
// Init_Grids();

/*
 if (strncmp(filter,"<N>",3) == 0)
   { // effacer toutes les taches
    for (i=0;i<MAX_T;i++) filtr[i]=' ';
    NB_TACHES = 0;
    nb_tachfiltr=0;
    Clean_Grid(asTri,2); // ne pas remplir
   }
 if (strncmp(filter,"<T>",3)==0)
   { // prendre toutes les taches
    for (i=1;i<=nb_taches;i++) filtr[i]='X';
    Remplir_asTri();
   }
*/

 if (strncmp(filter,"<P>",3)==0)
   {
    Exec_Pas_Pas(filter);
    Remplir_asTri();
    Planning_Defaut();
   }

 if (strncmp(filter,"<E>",3)==0)
   {
    ExtractValue(tmp,filter,"criteres",0);
    count = Explode('|',tmp); // result dans params
    for (i=0;i<count;i++)
      {
       Exec_Pas_Pas(params[i]);
      }
    Remplir_asTri();
    Planning_Defaut();
   }



 Label17->Caption = IntToStr(nb_tachfiltr);
 return 0;
}

int __fastcall TplStandard::Exec_Trier(char *s)
{
 char tmp[1500];  int i,count,crit;
 char tri[500];
 Application->MessageBoxA(m_sort,"Tri",MB_OK);
 // constituer la colonne 1 de asTri;
 // retrouver les criteres et les col  champs;

 ExtractValue(tmp,s,"champs",0);
 Explode('|',tmp);     // result dans params
 if (count==0) return 0;
 strcpy(tri,"");
 for (i=0;i<count;i++)
   {
    if (params[i][1]=='*')   // c'est un critere
      {
       crit = RechercheColCrit(params[i]+2);      //
       crit++;

      }


   }





 return 0;
}

int __fastcall TplStandard::Exec_Criteres(char *s)
{
 int i,col;
 char c1[250],c2[250],c3[250],c4[250],c5[250],c6[250],c7[250],c8[250],lib[250],tmp[250];


 // affecter un criteres aux taches cochees
 ExtractValue(c1,m_criteres,"c1",0);
 ExtractValue(c2,m_criteres,"c2",0);
 ExtractValue(c3,m_criteres,"c3",0);
 ExtractValue(c4,m_criteres,"c4",0);
 ExtractValue(c5,m_criteres,"c5",0);
 ExtractValue(c6,m_criteres,"c6",0);
 ExtractValue(c7,m_criteres,"c7",0);
 ExtractValue(c8,m_criteres,"c8",0);
 ExtractValue(lib,m_criteres,"lib",0);

  //recherche de la colonne correcte
 col=3;
 for (i=3;i<asCrit->ColCount;i++)
   {
    if ((asCrit->Cells[i][0]+"-") == AnsiString(c1))
      col = i;
   }
 strcpy(tmp,"");
 strcat(tmp,c1); strcat(tmp,c2); strcat(tmp,c3); strcat(tmp,c4);

 for (i=1;i<=nb_taches;i++)
   {
    if (coch[i]=='X')
     {
      asCrit->Cells[col][i]=AnsiString(tmp);
      asCrit->Cells[col+1][i]=lib;
     }
   }
 return 0;
}


int __fastcall TplStandard::Exec_Coches(char *s)
{

 if (strcmp(m_coche,"<21>")==0) Tout_Cocher_Crit();
 if (strcmp(m_coche,"<22>")==0) Tout_Decocher_Crit();
 if (strcmp(m_coche,"<23>")==0) Cocher_Decocher_Crit();

 return 0;
}



void __fastcall TplStandard::Timer1Timer(TObject *Sender)
{
 char tmp[255];
 int lg;

 Timer1->Enabled = false;

 if (flag_real) { Create_First_Real(); flag_real=false; }
 if (flag_init) { InitTri(); flag_init=false;}
 if (flag_alert) { if (flip_flop) { lAlert->Font->Color = clBlack; lAlert->Caption = ""; flip_flop = false;}
 else {lAlert->Font->Color = clRed;lAlert->Caption = "Retard Imputable";flip_flop = true; }}

 if (flag_alertPred){if (flip_flopPred){ lAlertPred->Font->Color = clBlack;lAlertPred->Caption = "";flip_flopPred = false;}
 else {lAlertPred->Font->Color = clRed;sprintf(tmp,"Tache %d : Retard Imputable",av_tache_pred);lAlertPred->Caption = AnsiString(tmp); flip_flopPred = true; }}

 lg = strlen(m_filtre);
 if (lg > 0) { modfilter=0;Exec_Filter(modfilter,m_filtre);m_filtre[0]=0;}
 lg = strlen(m_coche);
  if (lg > 0){ Exec_Coches(m_coche); m_coche[0]=0; }
 lg = strlen(m_criteres);
 if (lg>0) { Exec_Criteres(m_criteres); m_criteres[0]=0; Change1(); }
 lg = strlen(m_sort);
 if (lg>0) { Exec_Trier(m_sort); m_sort[0]=0; Change1(); }
 Timer1->Enabled = true;
}
//---------------------------------------------------------------------------




void __fastcall TplStandard::asAvancCanEditCell(TObject *Sender, int ARow,
      int ACol, bool &CanEdit)
{
 CanEdit=false;
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid5CanEditCell(TObject *Sender,
      int ARow, int ACol, bool &CanEdit)
{
 int ch;
 CanEdit = false;
 if (ARow==0) return;
 ch=vl_chp[6][ACol];
 if (ch_sai[ch][0]=='N') return;
 CanEdit = true;
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::asAvancClickCell(TObject *Sender, int ARow,
      int ACol)
{
 int task,ptask; //pptask;
 char tmp[250];
 char str[250];
 int dur,nb,i,t,nt,count;
 int ipred;
 int dist,maxdist;
 char d1[15]; int a1,j1,m1;

 AnsiString Val1;

 if (ARow==0) return;

 //flag_alert = false;
 //flag_alertPred=false;

 row_avancement = ARow;
 strcpy(tmp,asAvanc->Cells[1][ARow].c_str());
 task = atoi(tmp);
 sprintf(tmp,"%d",task);
 lTA->Caption = AnsiString(tmp);
  getvalue(5,ARow,44);           // retard imputable
  setvalue(4,1,53,adv);
  getvalue(5,ARow,45);           // retard imputable
  setvalue(4,1,54,adv);
  getvalue(5,ARow,41);           // date debut reelle
  setvalue(4,1,56,adv);
  getvalue(5,ARow,42);           // duree reelle
  setvalue(4,1,55,adv);
  getvalue(5,ARow,43);           // date fin reelle
  setvalue(4,1,57,adv);
  getvalue(5,ARow,69);           // date deb possible
  setvalue(4,1,26,adv);
  getvalue(5,ARow,71);
  setvalue(4,1,29,adv);
  getvalue(5,ARow,72);
  setvalue(4,1,28,adv);

 // Date dans label 12
 sprintf(tmp,"%02d/%02d/%02d",JourAvanc,MoisAvanc,AnAvanc%100);
 setvalue(4,1,52,tmp);

 //setvalue(4,1,29,"0");  // pourcentage restant
 //setvalue(4,1,28,"0");  // jours restant
 //setvalue(4,1,30,"0");  // cout
 // cleaner les predecesseurs

 AdvStringGrid5->RowCount=2;
 for(i=0;i<AdvStringGrid5->ColCount;i++)
      AdvStringGrid5->Cells[i][1]="";


 ipred=1; count=0;
 maxdist=0;

 while(pr[task][ipred] != 0)
   {
    nt=pr[task][ipred];

    for (i=1; i<asAvanc->RowCount; i++)
      {
       getvalue(5,i,39); t=atoi(adv);
       if (t==nt)
         {
          count++; if (count>1) AdvStringGrid5->RowCount++;
          getvalue(5,i,39); setvalue(6,count,31,adv);
          getvalue(5,i,40); setvalue(6,count,59,adv);
          getvalue(5,i,41); setvalue(6,count,35,adv);
          getvalue(5,i,42); setvalue(6,count,64,adv);
          getvalue(5,i,43); setvalue(6,count,36,adv);
          getvalue(5,i,44); setvalue(6,count,33,adv);
          getvalue(5,i,45); setvalue(6,count,34,adv);
          getvalue(5,i,69); setvalue(6,count,32,adv);
          getvalue(5,i,48); setvalue(6,count,65,adv);
          getvalue(5,i,62); setvalue(6,count,63,adv);
          getvalue(5,i,71); setvalue(6,count,37,adv);
          getvalue(5,i,72); setvalue(6,count,38,adv);

          getvalue(5,i,43); strcpy(d1,adv);   // fin reelle
          d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
          dist = convert_date(a1+2000,m1,j1);
          if (dist>maxdist) maxdist=dist;

          //pptask=exist_tache(nt,nb_taches);
          strcpy(tmp,TYPL[pr_tl[nt][ipred]]);
          setvalue(6,ipred,60,tmp);
          sprintf(tmp,"%d",pr_decal[nt][ipred]);
          setvalue(6,ipred,61,tmp);
         }
      }


    ipred++;
   }

   //getvalue(5,ARow,69);           // date deb possible
   //if (strlen(adv)==0)
   Compute_DateDebutPossible();




}
//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid5CellValidate(TObject *Sender,
      int ACol, int ARow, AnsiString &Value, bool &Valid)
{
  // retrouver le champ
 int ch; int val,rc;
 char tmp[255]; float cout; int x; int tachepred;
 float fdata; float fdata2; int result,result2;
 char str[50];
 char dt1[15],dt2[15],dt3[15];
 int xcal;


 getvalue(6,ARow,63); xcal=atoi(adv);
 getvalue(6,ARow,31); tachepred=atoi(adv);
 av_tache_pred=tachepred;
 getvalue(5,row_avancement,39); //tache=atoi(adv);
 ch=vl_chp[6][ACol];
 strcpy(tmp,AdvStringGrid5->Cells[ACol][ARow].c_str());
 row_av_pred =ARow;
 Valid=true;
 switch (ch)
   {
    case 37 : // % restant
       val=atoi(tmp);
       if ((val <0) || (val > 100))
         { Application->MessageBoxA("Pourcentage incorrect",m_ecoplan,MB_OK);
           Valid = false; break;
         }

       // lire durée réelle et calculer nb jours restants
       getvalue(6,ARow,55);
       result = atoi(adv);
       x =  ((float) val) * (((float) result) / 100.0) +0.5;

       sprintf(str,"%d",x);
       setvalue(6,ARow,38,str);
       break;
    case 38 : // Jours restants
       val=atoi(tmp);
       if ((val <0) || (val > 999))
         { Application->MessageBoxA("Nombre Jours restants Incorrect",m_ecoplan,MB_OK);
           Valid = false; break;
         }
       // compute percentage

       //getvalue(6,ARow,38);
       result = val; //atoi(adv);
       fdata = (float) result;
       getvalue(6,ARow,64); // duree reelle predecesseur
       result2=atoi(adv);
       fdata2 = (float) result2;
       x= ( fdata *100.0) / (fdata2);
       sprintf(str,"%d",x);
       setvalue(6,ARow,37,str);

       break;

    case 64 :  // duree reelle predecesseur
       val=atoi(tmp);
       if ((val <0) || (val > 999))
         { Application->MessageBoxA("Duree Réelle Incorecte",m_ecoplan,MB_OK);
           Valid = false; break;
         }

       break;

    case 35 :  // date début réel
       rc=verifdate8(tmp);
       if (rc>0) { Valid = false; break;}
       rc=verif_conges(tmp,xcal);
       if (rc>0) { Valid=false;
       Application->MessageBoxA("Date invalide : jour de congé",m_ecoplan,MB_OK);
                   break;
            }

       break;

    case 36 : // date fin rélle
       rc=verifdate8(tmp);
       if (rc>0) { Valid = false; break;}
       rc=verif_conges(tmp,xcal);
       if (rc>0) { Valid=false;
       Application->MessageBoxA("Date invalide : jour de congé",m_ecoplan,MB_OK);
                   break;
            }
       break;

   }
 if (Valid==true)
   {
    Compute_DateDebutPossiblePred(ARow);
    setvalue(6,ARow,ch,tmp);

    CHPRED=ch;
    CH=ch;
       switch (CH)
      {
       case 37 :
         //Compute_Jours_RestantsPred(ARow);
         Compute_Fin_AvancePred(ARow);
         Compute_Date_DebPred(ARow);
         break;

       case 38 :
         //Compute_Percent_RestantPred(ARow);
         Compute_Fin_AvancePred(ARow);
         Compute_Date_DebPred(ARow);
         break;


       case 36 :
         Compute_Date_DebPred(ARow);
         break;
      }

    getvalue(4,1,52); strcpy(dt1,adv);   // data avancement
    getvalue(6,ARow,35); strcpy(dt2,adv);   // date debut reel
    getvalue(6,ARow,36); strcpy(dt3,adv);   // date fin reelle


    rc=comp_dist_dates(dt1,dt2,0,0);
    if (rc>0)  //  date debut reel apres avancement
      {
       setvalue(6,ARow,37,"100");
       getvalue(6,ARow,64); setvalue(6,ARow,38,adv);
       setvalue(6,ARow,33,"0"); setvalue(6,ARow,34,"0");
      }
    else // date debut avant avancement
      { rc=comp_dist_dates(dt1,dt3,0,0);
        if (rc < 0)  // date de fin avant date avancement : % = 0;
          {
           setvalue(5,ARow,37,"0");
           setvalue(5,ARow,38,"0");

          }
        else
          {
           // getvalue(5,row_avancement,62); xcal=atoi(adv);
           getvalue(6,ARow,63); xcal= atoi(adv);
           rc=comp_dist_dates(dt1,dt3,xcal,0);
           sprintf(adv,"%d",NB2);
           setvalue(6,ARow,38,adv);
           Compute_Percent_RestantPred(ARow);
           Compute_Date_DebPred(ARow);
          }
       Compute_Retard_ImputablePred(ARow);
       Compute_Retard_TotalPred(ARow);
      }


   Compute_DateDebutPossible();  // de la tache en cours

    CH=57;
    Timer2->Enabled=true;
    // Propage(57);  // propager sur la tache en cours
    Compute_Flag_Alert();
    Compute_Flag_AlertPred(ARow);

   }
 Change1();
}




void __fastcall TplStandard::AdvStringGrid4CellValidate(TObject *Sender,
      int ACol, int ARow, AnsiString &Value, bool &Valid)
{
 // retrouver le champ
 int ch; int val,rc;
 char tmp[255]; float cout; int x;
 float fdata; float fdata2; int result,result2;
 char str[50]; char tmp1[250];
 int xcal;
 char dt1[15],dt2[15],dt3[15];


 ch=vl_chp[4][ACol];
 strcpy(tmp,AdvStringGrid4->Cells[ACol][1].c_str());
 getvalue(5,row_avancement,62); xcal=atoi(adv);
 Valid=true;
 switch (ch)
   {
    case 29 : // % restant
       val=atoi(tmp);
       if ((val <0) || (val > 100))
         { Application->MessageBoxA("Pourcentage incorrect",m_ecoplan,MB_OK);
           Valid = false; break;
         }
       getvalue(5,row_avancement,62); xcal=atoi(adv);
       // comparer date de fin et date avancement
       getvalue(4,1,57); strcpy(dt1,adv);   // date fin reelle
       getvalue(4,1,52); strcpy(dt2,adv);   // date avancement
       rc=comp_dist_dates(dt1,dt2,0,0);
       //getvalue(4,1,29); val=atoi(adv);
       getvalue(4,1,55); result = atoi(adv);
       //result = atoi(valperc);
       x =  ((float) val) * (((float) result) / 100.0) +0.5;
       sprintf(str,"%d",x); setvalue(4,1,28,str);
       break;
    case 28 : // Jours restants
       val=atoi(tmp);
       if ((val <0) || (val > 999))
         { Application->MessageBoxA("Nombre Jours restants Incorrect",m_ecoplan,MB_OK);
           Valid = false; break;
         }
       result = val; // atoi(valjr);
       fdata = (float) result;
       getvalue(4,1,55);
       result2=atoi(adv);
       fdata2 = (float) result2;
       if (fdata2==0.0) fdata2=1.0;
       x= ( fdata *100.0) / (fdata2);
       sprintf(str,"%d",x);
       setvalue(4,1,29,str);

       break;

    case 55 :  // duree reelle
       val=atoi(tmp);
       if ((val <0) || (val > 999))
         { Application->MessageBoxA("Duree Réelle Incorecte",m_ecoplan,MB_OK);
           Valid = false; break;
         }

       break;

    case 56 :  // date début réel
       rc=verifdate8(tmp);
       if (rc>0) { Valid = false; break;}
       rc=verif_conges(tmp,xcal);
       if (rc>0) { Valid=false;
       Application->MessageBoxA("Date invalide : jour de congé",m_ecoplan,MB_OK);
                   break;
            }

       break;

    case 57 : // date fin rélle
       rc=verifdate8(tmp);
       if (rc>0) { Valid = false; break;}
       rc=verif_conges(tmp,xcal);
       if (rc>0) { Valid=false;
       Application->MessageBoxA("Date invalide : jour de congé",m_ecoplan,MB_OK);
                   break;
                 }

       break;

    case 30 : // % cout reel
       val=atoi(tmp);
       if ((val <0) || (val > 100))
         { Application->MessageBoxA("Pourcentage Cout Réel Incorrect",m_ecoplan,MB_OK);
           Valid = false; break;
         }
       break;

    case 58 : // Cout reel consomé
       cout = atof(tmp);
       if (cout < 0.0)
       { Application->MessageBoxA("Cout Réel Incorrect",m_ecoplan,MB_OK);
           Valid = false; break;
         }
       break;
   }
 if (Valid==true)
   {
    setvalue(4,1,ch,tmp);
    CH=ch;
    Timer2->Enabled=true;
    // Propage(ch);

  }


}
//---------------------------------------------------------------------------

int  __fastcall TplStandard::Propage(int ch)
{
  char dt1[15],dt2[15],dt3[15];
  int rc; int xcal;
    //CH=ch;
    getvalue(4,1,52); strcpy(dt1,adv);   // data avancement
    getvalue(4,1,56); strcpy(dt2,adv);   // date debut reel
    getvalue(4,1,57); strcpy(dt3,adv);   // date fin reelle
    //Compute_DateDebutPossible();   // on obtint le predecesseur le plus contraignant
    //sprintf(tmp1,"%d %d",DECAL,NUM_TACHE_PRED);

   Sleep(100);
    switch (CH)
      {
       case 29 :
         Compute_Jours_Restants();
         Compute_Fin_Avance();
         Compute_Date_Deb();
         break;

       case 28 :
         Compute_Percent_Restant();
         Compute_Fin_Avance();
         Compute_Date_Deb();
         break;


       case 57 :
         Compute_Date_Deb();

         break;
      }

    getvalue(4,1,52); strcpy(dt1,adv);   // data avancement
    getvalue(4,1,56); strcpy(dt2,adv);   // date debut reel
    getvalue(4,1,57); strcpy(dt3,adv);   // date fin reelle
    rc=comp_dist_dates(dt1,dt2,0,0);
    if (rc>0)  //  date debut reel apres avancement
      {
       setvalue(4,1,29,"100");
       getvalue(4,1,55); setvalue(4,1,28,adv);
       setvalue(4,1,53,"0"); setvalue(4,1,54,"0");
      }
    else // date debut avant avancement
      { rc=comp_dist_dates(dt1,dt3,0,0);
        if (rc < 0)  // date de fin avant date avancement : % = 0;
          {
           setvalue(4,1,29,"0");
           setvalue(4,1,28,"0");

          }
        else
          {
           getvalue(5,row_avancement,62); xcal=atoi(adv);
           rc=comp_dist_dates(dt1,dt3,xcal,0);
           sprintf(adv,"%d",NB2);
           setvalue(4,1,28,adv);
           Compute_Percent_Restant();
           Compute_Date_Deb();
          }
       Compute_Retard_Imputable();
       Compute_Retard_Total();
      }
    Compute_Flag_Alert();
    //Compute_Flag_AlertPred();

   // On recalcule tout l'avancement

   // envoi des saisies dans la grille principale
 getvalue(4,1,53);  setvalue(5,row_avancement,44,adv);  // ret imp
 getvalue(4,1,54);  setvalue(5,row_avancement,45,adv);  // ret total
 getvalue(4,1,55);  setvalue(5,row_avancement,42,adv);  // duree reelle
 getvalue(4,1,56);  setvalue(5,row_avancement,41,adv);  // deb plus tot reel
 getvalue(4,1,57);  setvalue(5,row_avancement,43,adv);  // date fin reelle
 getvalue(4,1,26);  setvalue(5,row_avancement,69,adv);  // date debut reel possible
 getvalue(4,1,52);  setvalue(5,row_avancement,70,adv);  //
 getvalue(4,1,29);  setvalue(5,row_avancement,71,adv);  //
 getvalue(4,1,28);  setvalue(5,row_avancement,72,adv);  //

 int row,maj,nt,i,t;

 // maj des prédecesseurs aussi
 for (row=1;row<AdvStringGrid5->RowCount;row++)
  {
    getvalue(6,row,31); nt=atoi(adv);
    maj=0;
    for (i=1;i<asAvanc->RowCount; i++)
      { getvalue(5,i,39); t=atoi(adv);
        if (t==nt)
          {
           getvalue(6,row,35); setvalue(5,i,41,adv);  // date debut reel
           getvalue(6,row,36); setvalue(5,i,43,adv);
           getvalue(6,row,64); setvalue(5,i,42,adv);
           getvalue(6,row,33); setvalue(5,i,44,adv);
           getvalue(6,row,34); setvalue(5,i,45,adv);
           getvalue(6,row,32); setvalue(5,i,69,adv);
           getvalue(6,row,37); setvalue(5,i,71,adv);
           getvalue(6,row,38); setvalue(5,i,72,adv);
           getvalue(4,1,52);  setvalue(5,i,70,adv);  // date avancement
           maj=1;
           break;
          }
      }
   if (maj==0)
     {
       // predecesseur pas present dans la grille

     }
  }

 Faire_Riper();
 Image_Avanc("Avancement au ");
 Change1();
 return 0;
 }

int  __fastcall TplStandard::is_succ(int base,int numt)
{
 int ind,isucc,xtsucc,ok;

 ind = exist_tache(base,nb_taches);
 if (ind==0) return 0;
 isucc = 1;
 ok=0;
 while ((su[ind][isucc]!=0))
   {
    xtsucc=su[ind][isucc];
    if (xtsucc==9999) { ok= 0; break; }
     else
     { if (xtsucc==numt) { ok=1; break;  }}
   isucc++;
   }
 return ok;
}


int __fastcall TplStandard::Faire_Riper()
{
 int tache_en_cours,nt; //nbsel;
 int tniv,inext,ind,i,nbrow,ok;
 int mem_niv; //mem_ind;
 int retard, ret;
 int tache, tsucc,isel,iself;
 char tmp[200];
 // Pour chacune des taches

 getvalue(5,row_avancement,39); tache_en_cours = atoi(adv);
 //getvalue(4,1,54); ret= atoi(adv);
 //getvalue(4,1,53); retard = atoi(adv);
 //if (ret>retard) retard= ret;

 getvalue(5,row_avancement,72); //nb jours restants
 retard=atoi(adv);

 // rechercher la tache dans les niveaux
ok=0;
// for (tniv=0;tniv<iniv;tniv++)
//   {

      tniv=0;
      while(!ok)
       { inext=0;
         while (niveaux[tniv][inext] != 0)
          { ind=niveaux[tniv][inext];
            ind = exist_tache(ind,nb_taches);
            if (ind==tache_en_cours)
              {
               ok = 1;
               mem_niv=tniv; // mem_ind=inext;
               break;
              }
          inext++;
          } //
        tniv++;
        if (tniv>=iniv) { break;} //  return 0;}
       }
 //  }

for (i=0; i<nb_taches;i++) { t_select[i]=0; t_selectf[i]=0; }
//nbsel=1;
t_select[0]=tache_en_cours;

Calcul_Avancement(mem_niv,tache_en_cours,retard);
//Calcul_MR();

Calcul_Margereelle(retard);
return 0;

}

int __fastcall TplStandard::Decale_Tache_Succ(int row,int retard)
{
int dist,x,y,dur;
 int a1,m1,j1,a2,m2,j2;
 char d1[15]; char d2[15];
 char tmp[250];
 int xcal;

 /// === date de debut previ + Retard !!!!!
 getvalue(5,row,62); xcal=atoi(adv);  // calendrier

 // calcule la date de debut reel a partir de la date debut previsionel
 getvalue(5,row,41); strcpy(d1,adv);   // debut reelle
 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 // avance conges , avance temps
 dist = convert_date(a1+2000,m1,j1);   //
 x=avance_conges(dist,xcal);
 y=avance_temps(x,xcal,retard);
 x=avance_conges(y,xcal);
 add_jour(AnPrev,MoisPrev,JourPrev,x);
 // result dans An,Mois,Jour
 sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
 setvalue(5,row,41,tmp);   //

 getvalue(5,row,41); strcpy(d1,adv);   // debut reelle
 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 // on calcule maintenant la date de fin
 getvalue(5,row,42); dur= atoi(adv);
 getvalue(5,row,41); strcpy(d2,adv);   // debut reelle
 d2[2]=0; j2=atoi(d2);  d2[5]=0; m2=atoi(d2+3);  d2[8]=0; a2=atoi(d2+6);
 // avance conges , avance temps
 dist = convert_date(a2+2000,m2,j2);
 x=avance_conges(dist,xcal);
 y=avance_temps(x,xcal,dur);
 x = avance_conges(y,xcal); //§§§§§§§
 add_jour(AnPrev,MoisPrev,JourPrev,x-1);
 // result dans An,Mois,Jour
 sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
 setvalue(5,row,43,tmp);
 return 0;
}

int __fastcall TplStandard::TrouveRow(int t)
{
 int row,i,nt;
 row=0;
 for (i=1;i<asAvanc->RowCount;i++)
   {getvalue(5,i,39); nt = atoi(adv);
    if (nt==t) row=i;
   }
 return row;
}

int _fastcall  TplStandard::Calcul_Avancement(int niv, int tache,int jours)
{
int i,zcal,tniv,inext,xmax;
int total,flag_amont,ind,imax,xind,ipred,xtpred;
int rowtache,rowpred,dur,x,y;
int frpred,frtache,drpred,drtache;
int a1,j1,m1; char d1[15],dt1[15],dt2[15],tmp[100];
//int distftache;
int distfpred,distdpred;
int margetot; //
int imin;

 for (i=1;i<=nb_taches;i++) { duree_reelle[i]=duree[i]; retard[i]=0; }
   // date debut = date previsionnelle
  //A=AnPrev; M=MoisPrev;// J=JourPrev;
  for (tniv=niv+1;tniv<iniv;tniv++)
   {
    inext=0; xmax=-1000;
    while (niveaux[tniv][inext] != 0)
     {
       ind=niveaux[tniv][inext];
       rowtache=TrouveRow(ind);
       getvalue(5,rowtache,43); strcpy(d1,adv);   // debut fin reelle  de la tache en cours
       d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
       // distftache = convert_date(a1+2000,m1,j1);
       ind = exist_tache(ind,nb_taches);
          if (tniv==0)  // niveau zero
            {
              imax=0; imin=0;
              //imax=0; zcal=tcal[ind];
              //total=avance_conges(0,zcal);
              //deb_plus_tot[ind] = total;
              //fin_plus_tot[ind]=  avance_temps(total,zcal,duree[ind])-1;
              //duree_reelle[ind] = fin_plus_tot[ind] - deb_plus_tot[ind]+ 1;
              //if (total > xmax) { xmax=total; xind=ind; }
            }
          else // if tniv !=0
           {
             // cherchons les predecesseurs de ind
            imax = -1000;ipred = 1; total=0;  flag_amont = 0;
            imin = 10000;
            while (pr[ind][ipred]!=0)
             {xtpred=pr[ind][ipred];
              rowpred=TrouveRow(xtpred);
              xtpred=exist_tache(xtpred,nb_taches);
              getvalue(5,rowpred,43); strcpy(d1,adv);
              d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
              distfpred = convert_date(a1+2000,m1,j1);
              getvalue(5,rowpred,41); strcpy(d1,adv);
              d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
              distdpred = convert_date(a1+2000,m1,j1);

              if (pr_tl[ind][ipred]==0)     //  c est un lien fd
                 { if ( pr_decal[ind][ipred] > 0)
                      { zcal=tcal[ind];
                        total = avance_conges(distfpred+1,zcal);
                        total = avance_temps(total,zcal,pr_decal[ind][ipred]);
                        total = avance_conges(total,zcal); // §§§§§
                      }
                   else if ( pr_decal[ind][ipred] < 0)
                      {  zcal=tcal[xtpred];
                         total = avance_conges(distfpred+1,zcal);
                         total = recule_temps(total,zcal,-pr_decal[ind][ipred]);
                      }
                   else { zcal=tcal[ind];
                          total = avance_conges(distfpred+1,zcal);
                        } // pas de calcul de decalage
                  }  // if lien fd
               if (pr_tl[ind][ipred]==1)     // c est un lien ff
                  {
                   if (pr_decal[ind][ipred] > 0)
                       { zcal=tcal[xtpred];
                         total = avance_conges(distfpred+1,zcal);
                         total = avance_temps(total,zcal,pr_decal[ind][ipred]);
                         total = avance_conges(total,zcal); //§§§§§§§
                         total = recule_temps(total,zcal,duree[ind]);
                        }
                    else if (pr_decal[ind][ipred] < 0)
                       { zcal=tcal[xtpred];
                         total=recule_conges(distfpred+1,zcal);
                         total=recule_temps(total,zcal,-pr_decal[ind][ipred]);
                         total = recule_temps(total,zcal,duree[ind]);
                        }
                    else
                       {
                        zcal= tcal[ind];
                        total=recule_conges(distfpred+1,zcal);
                        total = recule_temps(total,zcal,duree[ind]);
                       }
                  }  // if lien FF

               if (pr_tl[ind][ipred] == 2)  flag_amont = ipred;
               if (pr_tl[ind][ipred] == 3)    // Lien DD   Decal est >= 0
                  {
                   if ( pr_decal[ind][ipred] > 0)
                      { zcal=tcal[xtpred];
                        total=avance_conges(distdpred,zcal);
                        total = avance_temps(total,zcal,pr_decal[ind][ipred]);
                        total = avance_conges(total,zcal); //§§§§§§§
                       }
                   else if ( pr_decal[ind][ipred] == 0)
                        { zcal=tcal[ind];
                          total=avance_conges(distdpred,zcal);
                        } // pas de calcul de decalage
                  }  // if lien DD

               if (total > imax) imax=total;
               if (total < imin) imin=total;
               ipred++;
               }   // while ipred
           zcal=tcal[ind];

           add_jour(AnPrev,MoisPrev,JourPrev,imax);
           sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
           setvalue(5,rowtache,41,tmp);  // debut reel
           setvalue(5,rowtache,69,tmp);  // debut reel possible

           add_jour(AnPrev,MoisPrev,JourPrev,imin);
           sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);


           getvalue(5,rowtache,42); dur= atoi(adv);
           x=avance_conges(imax,zcal);
           y=avance_temps(x,zcal,dur);
           add_jour(AnPrev,MoisPrev,JourPrev,y-1);
           // result dans An,Mois,Jour
           sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
           setvalue(5,rowtache,43,tmp);

           // calcul du retard total = difference fin prev - fin reelle
           getvalue(5,rowtache,43); strcpy(dt2,adv);   // date fin réel
           getvalue(5,rowtache,73); //margetot=atoi(adv);
           getvalue(5,rowtache,48); strcpy(dt1,adv);   // date fin previsionnel

           comp_dist_dates(dt1,dt2,zcal,0);
           //if (margetot >= NB2) NB2=0;
           //else NB2=NB2-margetot;
           sprintf(tmp,"%d",NB2);
           setvalue(5,rowtache,45,tmp);
         } // end else !=0

        //} // end if(ind== tache)
      inext++;
      } // end while
   } // end for
 return 0;
}

int __fastcall  TplStandard::comp_dist_succ_avanc(int indx,int xtsucc, int isucc,int deb,int fin)
{
 int zcal,xtotal,flag_amont,fduree;



 if (su_tl[indx][isucc]==0)     //  c est un lien fd
                  {
                   if (su_decal[indx][isucc] > 0)
                     { zcal=tcal[indx];  // xtsucc];
                       xtotal=recule_conges(deb,zcal);
                       xtotal=recule_temps(xtotal,zcal,su_decal[indx][isucc]);
                       xtotal=recule_temps(xtotal,zcal,duree[indx]);
                     }
                   else if (su_decal[indx][isucc] < 0)
                     {
                      zcal=tcal[indx]; //xtsucc];
                      xtotal=avance_conges(deb,zcal);
                      xtotal=avance_temps(xtotal,zcal,-su_decal[indx][isucc]);
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);
                     }
                   else
                     {zcal=tcal[indx];
                      xtotal=recule_conges(deb,zcal);
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);
                     }
                  }
                if (su_tl[indx][isucc]==1)     //  c est un lien ff
                  {
                   if (su_decal[indx][isucc] > 0)
                     {zcal=tcal[indx]; //
                      xtotal=recule_conges(fin+1,zcal);
                      xtotal=recule_temps(xtotal,zcal,su_decal[indx][isucc]);
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);

                     }
                   else if (su_decal[indx][isucc] < 0)
                     {zcal=tcal[indx];  //
                      xtotal=avance_conges(fin+1,zcal);     //§§§ + 1
                      xtotal=avance_temps(xtotal,zcal,-su_decal[indx][isucc]);
                      xtotal = avance_conges(xtotal,zcal); //§§§§§§§
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);

                     }
                   else
                     {zcal=tcal[indx];
                      xtotal=recule_conges(fin+1,zcal);
                      xtotal=recule_temps(xtotal,zcal,duree[indx]);
                     }
                  }
                 if (su_tl[indx][isucc]==2)     //  c est un lien amont
                  {
                   flag_amont = isucc;
                  }

                 if (su_tl[indx][isucc]==3)     //  c est un lien DD
                  {
                   if (su_decal[indx][isucc] > 0)
                     { zcal=tcal[indx];  // xtsucc];

                       xtotal = comp_down(deb,zcal,su_decal[indx][isucc]);
                       //zcal=tcal[indx];
                       //xtotal = comp_down(fduree,zcal,duree[indx]);    // $$$$$$$$$$$$
                     }
                   else if (su_decal[indx][isucc] == 0)
                     {zcal=tcal[indx];
                      //xtotal = comp_down(deb,zcal,duree[indx]);
                      xtotal=deb;
                     }
                  }

 return xtotal;


}



int __fastcall TplStandard::Calcul_MR()
{
 int ix,t,indx,zcal,xtsucc;
 int isucc,imin,rowsucc,rowmin;
 char dat1[15],dat2[15],tmp[255];

 for (ix=1;ix<asAvanc->RowCount;ix++)
   {
    getvalue(5,ix,39); t=atoi(adv); // numero de taches
    indx = exist_tache(t,nb_taches);
    getvalue(5,ix,43); strcpy(dat1,adv);  // date fin reelle
    zcal = tcal[indx];
    isucc = 1; imin=10000;
    while ((su[indx][isucc]!=0)) //
      { xtsucc=su[indx][isucc];
        if (xtsucc == 9999)
         imin=0;
        else
        {
         rowsucc=TrouveRow(xtsucc);
         getvalue(5,rowsucc,41); strcpy(dat2,adv); // date debut
         comp_dist_dates(dat1, dat2,zcal,0);
         if (NB2 < imin) {imin = NB2; rowmin=rowsucc; }
        }
       isucc++;
      }

    getvalue(5,rowmin,41); strcpy(dat2,adv); // date debut
    comp_dist_dates(dat1, dat2,zcal,0);
    sprintf(tmp,"indx %d, succmin %d, NB2= %d",indx,rowmin,NB2);
    Application->MessageBoxA(tmp,m_ecoplan,MB_OK);
   }
return 0;
}




int __fastcall TplStandard::Calcul_Margereelle(int retard)
{
 int ix,tniv,inext,indx,isucc,xtsucc;
 int imin; //,xtotal;
 int mmin; int i,zx; int fdecal, fduree;
 char tmp[250];
 int idd, ddflag,flag_amont,t_amont,t_start,imom;
 int indmom; int zcal; int a1,m1,j1;
 int DT; int dtsucc,ftsucc,dtx;   // ftx;
 int dist,t,rowx,rowsucc,indsucc;
 char d1[15]; int marge,percent;
 int diff,indexpred;
 char dt1[15],dt2[15];
 char dat1[15],dat2[15];
 char DAT1[15],DAT2[15],DATT[15];
char dtfictif[15],dtPrev[15];
 int a1fic,m1fic,j1fic;
 int margesucc; //,margeindx;
 int indfict,distmin;
 int minisucc,minxtsucc;
 int flag_ok,dtdecal;
 int distavanc;

 flag_amont=0;
 if (nb_taches==0) return 0;
 sommets[nb_taches+1]=9999;   // juste pour calcul au plus tard
 imin=10000;


 distavanc = convert_date(AnAvanc,MoisAvanc,JourAvanc);


  DT=0;    tniv=iniv-1; inext=0;
  while(niveaux[tniv][inext] !=0)
 {
  t=niveaux[tniv][inext]; rowx=TrouveRow(t);
  getvalue(5,rowx,43); strcpy(d1,adv);  // date fin reelle
  d1[2]=0; j1fic=atoi(d1);  d1[5]=0; m1fic=atoi(d1+3);  d1[8]=0; a1fic=atoi(d1+6);
  dist = convert_date(a1fic+2000,m1fic,j1fic);
  if (dist > DT) { DT=dist; indfict=rowx; }
  inext++;
 }


 //  DT=DT+1; // distance de la tache fictive 9999

 getvalue(5,indfict,43); strcpy(dtfictif,adv);


  margesucc=DT;
  for (tniv=iniv-1;tniv>=0;tniv--)
   {
    inext=0;
    while (niveaux[tniv][inext] != 0)
      {
       indx=niveaux[tniv][inext]; t=indx;
       // on extrait les valeurs liees a INDX
       rowx=TrouveRow(t);
       getvalue(5,rowx,43); strcpy(dt1,adv);  // date fin reelle
       strcpy(dat1,dt1);
       dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[8]=0; a1=atoi(dt1+6);
       //ftx =
       convert_date(a1+2000,m1,j1);
       getvalue(5,rowx,73);
       //margeindx= atoi(adv);

       getvalue(5,rowx,41); strcpy(d1,adv);  // date deb reelle
       strcpy(DAT1,adv);
       d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
       dtx = convert_date(a1+2000,m1,j1);

       indmom = niveaux[tniv][inext];
       indx = exist_tache(indx,nb_taches);  // §§§§§§§§§§§§
       imin=10000;
       zcal=tcal[indx];
        // cherchons les successeurs de ind
       isucc = 1; //xtotal=0;
       while ((su[indx][isucc]!=0)) // && (su[indx][isucc]!=9999))
          {
            xtsucc=su[indx][isucc];
            flag_ok=false;
            if (xtsucc==9999)
             { if (isucc == 1)  // pas de vrai successeurs
                  { comp_dist_dates(dat1,dtfictif,zcal,0);
                    strcpy(DAT2,dtfictif);
                    marge = NB2;
                    //marge=margesucc-ftx;
                    imin=marge;
                    flag_ok=true;
                  }
                else  // il existe un successeur
                  {  imin=imin; }
              isucc++;
              }
            else
              {
                flag_ok=false;
                xtsucc = exist_tache(xtsucc,nb_taches);
                rowsucc = TrouveRow(xtsucc);
                getvalue(5,rowsucc,41); strcpy(d1,adv);  // date deb reelle
                strcpy(dat2,adv);
                d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
                dtsucc = convert_date(a1+2000,m1,j1);

                getvalue(5,rowsucc,43); strcpy(d1,adv);  // fin reelle
                d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
                ftsucc = convert_date(a1+2000,m1,j1);



                getvalue(5,rowsucc,73); margesucc=atoi(adv);
                // dtdecal = avance_temps(dtsucc,zcal,margesucc);

                dtdecal = comp_dist_succ_avanc(indx,xtsucc,isucc,dtsucc,ftsucc);
                dtdecal = avance_temps(dtdecal,zcal,margesucc);

                if (dtdecal < imin)
                  {imin = dtdecal; minxtsucc = xtsucc;
                   minisucc = isucc;
                   strcpy(DAT2,dat2);
                  }

                isucc++;
              }
          }  // while su

        if (imin==10000)  imin=0;
        getvalue(5,rowx,71); percent=atoi(adv);
        if (percent >= 0)
         {
          if (flag_ok== false)
           {
             xtsucc = exist_tache(minxtsucc,nb_taches);
             rowsucc = TrouveRow(xtsucc);

             getvalue(5,rowsucc,43); strcpy(d1,adv);  // date deb reelle
             strcpy(dat2,adv);
             d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
             ftsucc = convert_date(a1+2000,m1,j1);

             strcpy(d1,DAT2); //date debut reel succ);
             d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
             dtsucc = convert_date(a1+2000,m1,j1);
             getvalue(5,rowsucc,73); margesucc=atoi(adv);

             dtdecal = comp_dist_succ_avanc(indx,xtsucc,minisucc,dtsucc,ftsucc);
             dtdecal = avance_temps(dtdecal,zcal,margesucc);
             add_jour(AnPrev,MoisPrev,JourPrev,dtdecal);
             sprintf(DATT,"%02d-%02d-%02d",Jour,Mois,An%100);



             // dtdecal = avance_temps(dtsucc,zcal,margesucc);
             comp_dist_dates(DAT1,DATT,zcal,0);


             marge = NB2;    // - margeindx;
             marge=marge;
           }
 //         if (ftx <  distavanc)
 //           {
 //
 //            setvalue(5,rowx,71,"0");
 //            setvalue(5,rowx,72,"0");
 //           }
 //         else
 //          {
             sprintf(tmp,"%d",marge);
             setvalue(5,rowx,73,tmp);
            if (dtx > distavanc)
            {
             setvalue(5,rowx,71,"100");
             getvalue(5,rowx,42); int dur=atoi(adv);
             sprintf(tmp,"%d",dur);
             setvalue(5,rowx,72,tmp);
            }
   //        }
         }
        else setvalue(5,rowx,73,"0");

        inext++;
       } // while

    } // end for


  sommets[nb_taches+1]=0;
  return 0;
 }


int __fastcall TplStandard::verif_conges(char *dt, int xcal)
{
 char dt1[15]; int dist1;
 int a1,m1,j1;
 strcpy(dt1,dt);

 dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[8]=0; a1=atoi(dt1+6);

 dist1=convert_date(a1+2000,m1,j1);

 if (cal[xcal][dist1]=='N') return 1;
 else return 0;

}

int __fastcall TplStandard::Compute_Percent_Restant()
{
 char str[50],tmp[200];
 int result,val,x,result2;
 float fdata,fdata2;



       getvalue(4,1,28);   // nbjrestants
       result = atoi(adv);
       //result = atoi(valjr);
       fdata = (float) result;
       getvalue(4,1,55);
       result2=atoi(adv);
       fdata2 = (float) result2;
       if (fdata2==0.0) fdata2=1.0;
       x= ( fdata *100.0) / (fdata2);
       sprintf(str,"%d",x);
       setvalue(4,1,29,str);
 return 0;
}


int __fastcall TplStandard::Compute_Jours_Restants()
{
char str[50],tmp[200];
int result,val,x;//,xcal;
 char dt1[15],dt2[15];

       getvalue(5,row_avancement,62); //xcal=atoi(adv);
       // comparer date de fin et date avancement
       getvalue(4,1,57); strcpy(dt1,adv);   // date fin reelle
       getvalue(4,1,52); strcpy(dt2,adv);   // date avancement
       comp_dist_dates(dt1,dt2,0,0);
       getvalue(4,1,29); val=atoi(adv);
       getvalue(4,1,55); result = atoi(adv);
       //result = atoi(valperc);
       x =  ((float) val) * (((float) result) / 100.0) +0.5;
       sprintf(str,"%d",x); setvalue(4,1,28,str);
       return 0;
}

int __fastcall TplStandard::Compute_Duree_Reelle()
{
 int xcal; //int nbrestants,rc;
 char tmp[50],dt1[20], dt2[20];

 getvalue(5,row_avancement,62); xcal=atoi(adv);  // calendrier
 getvalue(4,1,28); // nbrestants = atoi(adv);     // nbjourrestant
 // lire date de debut reelle
 getvalue(4,1,57); strcpy(dt2,adv);   // fin reelle
 getvalue(4,1,56); strcpy(dt1,adv);   // debut reelle
 comp_dist_dates(dt1,dt2,xcal,0);
 // NB1= distance y compris conges NB2= nombre de jours travailles
 sprintf(tmp,"%d",NB2+1);
 setvalue(4,1,55,tmp);
return 0;
}

int __fastcall TplStandard::Compute_Fin_Avance()
{
 Word j1,m1,a1;
 char d1[15]; char tmp[50];
 int dist_tot,x,y,xcal,nbrest;


 getvalue(5,row_avancement,62); xcal=atoi(adv);  // calendrier
 getvalue(4,1,28); nbrest= atoi(adv);
 getvalue(4,1,52); strcpy(d1,adv);   // avancement
 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 // avance conges , avance temps
 dist_tot = convert_date(a1+2000,m1,j1);   // calcule N par rapport au deb previsionnel
 x=avance_conges(dist_tot+1,xcal);
 y=avance_temps(x,xcal,nbrest);
 add_jour(AnPrev,MoisPrev,JourPrev,y-1);
 // result dans An,Mois,Jour
 sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
 setvalue(4,1,57,tmp);
return 0;
}

int __fastcall TplStandard::Compute_Date_Fin()
{
 Word j1,m1,a1;
 char d1[15]; char tmp[50];
 int dist_tot,x,y,xcal,dur;


 getvalue(5,row_avancement,62); xcal=atoi(adv);  // calendrier
 getvalue(4,1,55); dur= atoi(adv);
 getvalue(4,1,56); strcpy(d1,adv);   // debut reelle
 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 // avance conges , avance temps
 dist_tot = convert_date(a1+2000,m1,j1);   // calcule N par rapport au deb previsionnel
 x=avance_conges(dist_tot,xcal);
 y=avance_temps(x,xcal,dur);
 add_jour(AnPrev,MoisPrev,JourPrev,y-1);
 // result dans An,Mois,Jour
 sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
 setvalue(4,1,57,tmp);
 return 0;
}



int __fastcall TplStandard::Compute_Fin_AvancePred(int row)
{
 Word j1,m1,a1;
 char d1[15]; char tmp[50];
 int dist_tot,x,y,xcal,nbrest;


 getvalue(6,row,63); xcal=atoi(adv);  // calendrier
 getvalue(6,row,38); nbrest= atoi(adv);
 getvalue(4,1,52); strcpy(d1,adv);   // avancement
 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 // avance conges , avance temps
 dist_tot = convert_date(a1+2000,m1,j1);   // calcule N par rapport au deb previsionnel
 x=avance_conges(dist_tot+1,xcal);
 y=avance_temps(x,xcal,nbrest);
 add_jour(AnPrev,MoisPrev,JourPrev,y-1);
 // result dans An,Mois,Jour
 sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
 setvalue(6,row,36,tmp);
 return 0;
}



int  __fastcall TplStandard::Compute_Deb_From_Fin(char *dt)
{
 int xcal,x,y,dur; char d1[15];
 int a1,m1,j1,dist;  char tmp[100];

getvalue(5,row_avancement,62); xcal=atoi(adv);  // calendrier
getvalue(4,1,55); dur= atoi(adv);      // duree reelle
//getvalue(4,1,57);
strcpy(d1,dt);      // date fin reelle
d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
dist = convert_date(a1+2000,m1,j1);   //
x=recule_conges(dist+1,xcal);
y=recule_temps(x,xcal,dur);
add_jour(AnPrev,MoisPrev,JourPrev,y);
 // result dans An,Mois,Jour
sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
setvalue(4,1,56,tmp);  // deb tot reel
return 0;
}

int __fastcall TplStandard::Compute_Date_Deb()
{
 Word j1,m1,a1;
 char d1[15]; char tmp[50];
 int dist_avanc,x,y,xcal,dur; //nbjrest; //,nbjfait;
 getvalue(5,row_avancement,62); xcal=atoi(adv);  // calendrier
 getvalue(4,1,55); dur= atoi(adv);      // duree reelle
 // getvalue(4,1,52);  strcpy(d1,adv);    // date avancement

 getvalue(4,1,57);  strcpy(d1,adv);    // date fin reel
 getvalue(4,1,28); //nbjrest=atoi(adv);
 // nbjfait=dur-nbjrest;

 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 dist_avanc = convert_date(a1+2000,m1,j1);   // calcule N par
 x=recule_conges(dist_avanc+1,xcal);
 y=recule_temps(x,xcal,dur); // nbjfait);
 add_jour(AnPrev,MoisPrev,JourPrev,y);
 // result dans An,Mois,Jour
 sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
 setvalue(4,1,56,tmp);  // deb tot reel
 return 0;
 }

int __fastcall TplStandard::Compute_Retard_Total()
{
 char dt1[15]; char dt2[15];
 int xcal; char tmp[50];
 int margetot;

 getvalue(5,row_avancement,62); xcal=atoi(adv);
 getvalue(4,1,57); strcpy(dt2,adv);   // date fin réel
 getvalue(5,row_avancement,66); margetot=atoi(adv);
 getvalue(5,row_avancement,48); strcpy(dt1,adv);   // date fin previsionnel
 comp_dist_dates(dt1,dt2,xcal,0);

 if (margetot >= NB2) NB2=0;
 else NB2=NB2-margetot;

 sprintf(tmp,"%d",NB2);
 setvalue(4,1,54,tmp);
 return 0;
}


int __fastcall TplStandard::Compute_Retard_Imputable()
{
 char dt1[15]; char dt2[15];
 int xcal; char tmp[50];
 int j1,m1,a1,j2,m2,a2;
 int dist,durp,x,y;
 int decal;
 int dur_tache;
 int impute,impred,i;

 Compute_DateDebutPossible();



 /*
 getvalue(5,row_avancement,62); xcal=atoi(adv);
 getvalue(5,row_avancement,47); durp=atoi(adv);

 //  ret imputable = fin reelle tache - duree previsonelle - fin reelle du predecesseur
 //                  +/- decalages

 getvalue(4,1,57); strcpy(dt2,adv);   // date fin reel
 dt2[2]=0; j2=atoi(dt2);  dt2[5]=0; m2=atoi(dt2+3);  dt2[8]=0; a2=atoi(dt2+6);

 dist = convert_date(a2+2000,m2,j2);   //
 x=recule_conges(dist+1,xcal);
 y=recule_temps(x,xcal,durp);

 add_jour(AnPrev,MoisPrev,JourPrev,y);
 sprintf(dt2,"%02d/%02d/%02d",Jour,Mois,An%100);

 // boucle pour trouver le plus contraignant possibles

 impute=0;
 for (i=1;i<AdvStringGrid5->RowCount;i++)
   {
    getvalue(6,i,33);  impred= atoi(adv);
    if (impred>impute) impute=impred;
   }

  //getvalue(4,1,26); strcpy(dt1,adv);   // debut reel possible
 // getvalue(5,row_avancement,46); strcpy(dt1,adv); // date debut previsionnel //possible

 //getvalue(6,IND_PRED,36); strcpy(dt1,adv);  // date de fin du predecesseur contraignant
 */

 getvalue(4,1,26); strcpy(dt1,adv);   // debut reel possible
 getvalue(4,1,56); strcpy(dt2,adv);   // debut reel
 getvalue(5,row_avancement,62); xcal=atoi(adv);  
 comp_dist_dates(dt1,dt2,xcal,0);

 // NB2= retard imputable
 // getvalue(4,1,55); dur_tache=atoi(adv);

 // NB2=NB2-DECAL-impute;
 sprintf(tmp,"%d",NB2);
 setvalue(4,1,53,tmp);
 return 0;
}



int __fastcall TplStandard::Compute_DateDebutPossible()
{

 int i,decal; int typl,fd,rc;
 int calp,calt, fin_plus_tot;
 int durtache;
 int max_contrainte; int mem_ind;

 char tmp[255]; //int imin=0;
 char dt1[15],dt2[15];
 char type_lien[20];

 // calcul date debut reelle possible


  // imin=1000;
  max_contrainte = 0;   DECAL=0; NUM_TACHE_PRED=0; IND_PRED=0;
  for (i=1;i<AdvStringGrid5->RowCount;i++)
     {
       getvalue(6,i,31);
       if (strcmp(adv,"")==0)
       {
        // getvalue(4,1,56);  // lire date debut reel
        // setvalue(4,1,26,adv); // l'ecrire dans date deb possible
         break;
       }
       getvalue(6,i,61);  // decalage
       decal = atoi(adv);
       getvalue(6,i,63);  // calendrier predecesseur
       calp= atoi(adv);
       getvalue(5,row_avancement,62);
       calt= atoi(adv);
       getvalue(6,i,36);
       strcat(adv,"01/01/00");
       elargir_annee(adv);
       date10[2]=0; JourPred=atoi(date10);
       date10[5]=0; MoisPred=atoi(date10+3);
       date10[10]=0; AnPred=atoi(date10+6);
       fin_plus_tot = convert_date(AnPred,MoisPred,JourPred);
       getvalue(4,1,55); durtache = atoi(adv);

       getvalue(6,i,60); strcpy(type_lien,adv);

       fd = Compute_Decalages(fin_plus_tot,type_lien,calt,calp,decal,durtache);
       if (fd > max_contrainte)
               {max_contrainte = fd ; row_contrainte=i; mem_ind = i;
               IND_PRED=i; //imin=fd;
               getvalue(6,i,31); NUM_TACHE_PRED=atoi(adv);
               getvalue(6,mem_ind,60);  DECAL = atoi(adv);
              }

      }

   if (max_contrainte !=0)
    {
     add_jour(AnPrev,MoisPrev,JourPrev,max_contrainte);
     sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);

   }
  else
   {
    sprintf(tmp,"%02d/%02d/%02d",JourPrev,MoisPrev,AnPrev%100);
   }
 setvalue(4,1,26,tmp);
 Compute_Flag_Alert();
 return 0;
}

int  __fastcall TplStandard::Compute_Decalages(int base,char *typl,int caltache,int calpred,int decal,int dur)
{
 int total;
 total=0;

 if (strcmp(typl,"FD")==0) // FD
                 {
                   if ( decal > 0)
                      {
                        total = avance_conges(base+1,caltache);
                        total = avance_temps(total,caltache,decal);
                        total = avance_conges(total,caltache);
                      }
                   else if ( decal < 0)
                      {  total = avance_conges(base+1,calpred);
                         total = recule_temps(total,calpred,-decal);
                      }
                   else {
                          total = avance_conges(base+1,caltache);
                        } // pas de calcul de decalage
                  }
               if (strcmp(typl,"FF")==0)    // c est un lien ff
                  {
                   if (decal > 0)
                       { total = avance_conges(base+1,calpred);
                         total = avance_temps(total,calpred,decal);
                         total = recule_temps(total,calpred,dur);
                        }
                    else if (decal < 0)
                       {
                         total=recule_conges(base+1,calpred);
                         total=recule_temps(total,calpred,-decal);
                         total = recule_temps(total,calpred,dur);
                        }
                    else
                       {

                        total=recule_conges(base+1,caltache);
                        total = recule_temps(total,caltache,dur);
                       }
                  }

               if (strcmp(typl,"AM")==0) {} // flag_amont = ipred;
               if (strcmp(typl,"DD")==0)   // Lien DD   Decal est >= 0
                  {
                   if ( decal > 0)
                      {
                        total=avance_conges(base,calpred);
                        total = avance_temps(total,calpred,decal);
                       }
                   else if ( decal == 0)
                        {
                         total=avance_conges(base,caltache);
                        } // pas de calcul de decalage
                  }
 return total;

}

int __fastcall TplStandard::Compute_Flag_Alert()

{
char dt1[15],dt2[15];
int rc;

    getvalue(4,1,53); rc=atoi(adv);
    if (rc!=0) { flag_alert = true; }
    // else { flag_alert = false; lAlert->Caption = ""; }
 return 0;
}

int __fastcall TplStandard::Compute_Flag_AlertPred(int row)

{
char dt1[15],dt2[15];
int rc;

 getvalue(6,row,33); rc=atoi(adv);
    if (rc!=0) { flag_alertPred = true; }
   //  else { flag_alertPred = false; lAlertPred->Caption = ""; }
 return 0;
}


int __fastcall  TplStandard::elargir_annee(char *dt8)
{
 strcpy(date10,dt8);
 date10[9]=dt8[7]; date10[8]=dt8[6];
 date10[6]='2';  date10[7]='0';   date10[10]=0;
 return 0;
}

int  __fastcall TplStandard::comp_dist_dates(char *dt1, char *dt2, int calx,int offset)   // date8
{
 Word a1,a2,m1,m2,j1,j2;
 char d1[15],d2[15];
 int dist1,dist2,i;
 int annee20; int borne1; int borne2;

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
    annee20=2000+a1; dist1=convert_date(annee20,m1,j1);
    annee20=2000+a2; dist2=convert_date(annee20,m2,j2);
    NB1 = dist2-dist1+offset;
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



int __fastcall TplStandard::Compute_Percent_RestantPred(int row)
{
 char str[50],tmp[200];
 int result,val,x,result2;
 float fdata,fdata2;

       getvalue(6,row,38);  // Jours restants
       result = atoi(adv);

       // result = atoi(valjr);
       fdata = (float) result;
       getvalue(6,row,64);  // Duree
       result2=atoi(adv);
       fdata2 = (float) result2;
       if (fdata2 != 0.0) x= ( fdata *100.0) / (fdata2);
       else x=0.0;
       sprintf(str,"%d",x);
       setvalue(6,row,37,str);
 return 0;
}
int __fastcall TplStandard::Compute_Jours_RestantsPred(int row)
{
char str[50],tmp[200];
 int result,val,x;
       getvalue(6,row,37); val=atoi(adv);
       getvalue(6,row,64); result = atoi(adv);
       //result = atoi(valperc);
       x =  ((float) val) * (((float) result) / 100.0) +0.5;
       sprintf(str,"%d",x); setvalue(6,row,38,str);
  return 0;
}

int __fastcall TplStandard::Compute_Duree_ReellePred(int row)
{ // uniquement si des date de debut ou de fin on ete changees
 int xcal; //int nbrestants,rc;
 char tmp[50],dt1[20], dt2[20];

 getvalue(6,row,63); xcal=atoi(adv);  // calendrier
 getvalue(6,row,38); // nbrestants = atoi(adv);     // nbjourrestant
 // lire date de debut reelle
 getvalue(6,row,36); strcpy(dt2,adv);   // fin reelle
 getvalue(6,row,35); strcpy(dt1,adv);   // debut reelle
 comp_dist_dates(dt1,dt2,xcal,0);
 // NB1= distance y compris conges NB2= nombre de jours travailles
 sprintf(tmp,"%d",NB2+1);
 setvalue(6,row,64,tmp);
 return 0;
}

int __fastcall TplStandard::Compute_Date_FinPred(int row)
{
 Word j1,m1,a1;
 char d1[15]; char tmp[50];
 int dist_tot,x,y,xcal,dur;


 getvalue(6,row,63); xcal=atoi(adv);  // calendrier
 getvalue(6,row,64); dur= atoi(adv);    // duree
 getvalue(6,row,35); strcpy(d1,adv);   // debut reelle
 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 // avance conges , avance temps
 dist_tot = convert_date(a1+2000,m1,j1);   // calcule N par rapport au deb previsionnel
 x=avance_conges(dist_tot,xcal);
 y=avance_temps(x,xcal,dur);
 add_jour(AnPrev,MoisPrev,JourPrev,y-1);
 // result dans An,Mois,Jour
 sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
 setvalue(6,row,36,tmp);
 return 0;
}

int  __fastcall TplStandard::Compute_Deb_From_FinPred(int row)
{
 int xcal,x,y,dur;
 char d1[15]; int dist,a1,j1,m1;
 char tmp[15];

getvalue(6,row,63); xcal=atoi(adv);  // calendrier
getvalue(6,row,64); dur= atoi(adv);      // duree reelle
getvalue(6,row,36); strcpy(d1,adv);      // date fin reelle
d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
dist = convert_date(a1+2000,m1,j1);   //
x=recule_conges(dist+1,xcal);
y=recule_temps(x,xcal,dur);
add_jour(AnPrev,MoisPrev,JourPrev,y);
 // result dans An,Mois,Jour
sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
setvalue(6,row,35,tmp);  // deb tot reel
return 0;
}

int __fastcall TplStandard::Compute_Date_DebPred(int row)
{
 Word j1,m1,a1;
 char d1[15]; char tmp[50];
 int dist_avanc,x,y,xcal,dur,nbjrest; //,nbjfait;
 getvalue(6,row,63); xcal=atoi(adv);  // calendrier
 getvalue(6,row,64); dur= atoi(adv);
 // getvalue(4,1,52);  strcpy(d1,adv);    // date avancement

 getvalue(6,row,36); strcpy(d1,adv);  // date fin reelle

 getvalue(6,row,38); nbjrest=atoi(adv);
 // nbjfait=dur-nbjrest;

 d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
 dist_avanc = convert_date(a1+2000,m1,j1);   // calcule N par rapport au deb previsionnel
 x=recule_conges(dist_avanc+1,xcal);
 y=recule_temps(x,xcal,dur); // nbjfait);
 add_jour(AnPrev,MoisPrev,JourPrev,y);
 // result dans An,Mois,Jour
 sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
 setvalue(6,row,35,tmp);  // deb tot reel

// x=avance_conges(dist_avanc,xcal);
// y=avance_temps(x,xcal,nbjrest);
// add_jour(AnPrev,MoisPrev,JourPrev,y);
 // result dans An,Mois,Jour
// sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
// setvalue(6,row,36,tmp);  // fin temps reel
return 0;
}

int __fastcall TplStandard::Compute_Retard_TotalPred(int row)
{
 char dt1[15]; char dt2[15];
 int xcal; char tmp[50];
 int margetot;  int i,t,nt;

 getvalue(6,row,63); xcal=atoi(adv);
 //getvalue(6,row,35); strcpy(dt2,adv);   // date debut reel

 getvalue(6,row,36); strcpy(dt2,adv);
 getvalue(6,row,65); strcpy(dt1,adv);   // fin previsionnel

 getvalue(6,row,31); nt=atoi(adv);
 for (i=1;i<asAvanc->RowCount; i++)
   { getvalue(5,i,39); t=atoi(adv);
     if (t==nt) {getvalue(5,i,66); margetot=atoi(adv);
        break; }
   }

 comp_dist_dates(dt1,dt2,xcal,0);
 // NB2= retard total
 // retirer la marge totale
 NB2=NB2-margetot;
 sprintf(tmp,"%d",NB2);
 setvalue(6,row,34,tmp);
 return 0;
}

int __fastcall TplStandard::Compute_Retard_ImputablePred(int row)
{
 char dt1[15]; char dt2[15];
 int xcal; char tmp[50];
 int i,nt,t; int durp;
 int j1,j2,m1,m2,a1,a2;
 int dist,x,y;

 getvalue(6,row,63); xcal=atoi(adv);
 getvalue(6,row,36); strcpy(dt2,adv);   // date fin réel
 // get value duree reel
 // boucle dans asAvanc pour trouver la duree previsionnelle
 // numero de taches dans

 getvalue(6,row,31); nt=atoi(adv);
 for (i=1;i<asAvanc->RowCount; i++)
   { getvalue(5,i,39); t=atoi(adv);
     if (t==nt) {getvalue(5,i,47); durp=atoi(adv);
        break; }
   }


 //  ret imputable = fin reelle tache - duree previsonelle - date debut reelle
 //  +/- charge

 dt2[2]=0; j2=atoi(dt2);  dt2[5]=0; m2=atoi(dt2+3);  dt2[8]=0; a2=atoi(dt2+6);

 dist = convert_date(a2+2000,m2,j2);   //
 x=recule_conges(dist+1,xcal);
 y=recule_temps(x,xcal,durp);
 add_jour(AnPrev,MoisPrev,JourPrev,y);
 sprintf(dt2,"%02d/%02d/%02d",Jour,Mois,An%100);

 // getvalue(6,row,35);   strcpy(dt1,adv);      // date debut reelle

 getvalue(6,row,32);   strcpy(dt1,adv);
 comp_dist_dates(dt1,dt2,xcal,0);

 // NB2= retard imputable
 NB2 = NB2 - DECALPRED;
 sprintf(tmp,"%d",NB2);
 setvalue(6,row,33,tmp);
 return 0;
}


int __fastcall TplStandard::Compute_DateDebutPossiblePred(int row)
{
 int i,decal; int typl,fd,rc;
 int calp,calt, f_plus_tot;
 int durtache;
 int max_contrainte;
 //int row_contrainte;
 char tmp[255];
 char dt1[15],dt2[15];
 char type_lien[20];

 int ch; int ind,pt,ipred;
 int mem_ind,mem_ipred;

 // calcul date debut reelle possible

  max_contrainte = 0;
  DECALPRED=0; CALP=0;

  // boucle sur les predecesseurs des predecesseurs !!!!
  getvalue(6,row,31);  ch=atoi(adv); if (ch==0) return 0;
  ind = exist_tache(ch,nb_taches);
  ipred = 1;
  while(pr[ind][ipred]!=0)
    {
     pt=pr[ind][ipred]; pt=exist_tache(pt,nb_taches);
     strcpy(type_lien,TYPL[pr_tl[ind][ipred]]);
     decal = pr_decal[ind][ipred];
     calt = tcal[ind];
     calp = tcal[pt];
     f_plus_tot = fin_plus_tot[pt];
     getvalue(6,row,64); durtache=atoi(adv);
     fd = Compute_Decalages(f_plus_tot,type_lien,calt,calp,decal,durtache);
     if ((fd )>max_contrainte)
              {max_contrainte = fd ; row_contrainte=i; mem_ind = pt;
               mem_ipred = ipred;
              }
     ipred++;
    }
  if (max_contrainte !=0)
    {
     add_jour(AnPrev,MoisPrev,JourPrev,max_contrainte);
     // on a la date dans An,Mois,Jour;
     sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
     setvalue(6,row,59,tmp);
     DECALPRED=pr_decal[mem_ind][mem_ipred];
   }
 return 0;
}


//---------------------------------------------------------------------------

void __fastcall TplStandard::asAvancContextPopup(TObject *Sender,
      TPoint &MousePos, bool &Handled)
{
int X,Y;
 X = MousePos.x;
 Y = MousePos.y;
  asAvanc->MouseToCell(X, Y, CurCol, CurRow);
 // conversion en ligne et colonne courantes
 PopupActiv->Popup(X, Y);
}
//---------------------------------------------------------------------------








void __fastcall TplStandard::btSauverCommeClick(TObject *Sender)
{
 char name[256];
 int mb; char fn[255];
 char *p; int ret;
    SaveDialog1->FileName = "*.eco";
    if (SaveDialog1->Execute())
          {
            strcpy(name,SaveDialog1->FileName.c_str());
            // ret = plST->SaveAs(name);
            strlwr(name);
            p=strstr(name,".eco");
            if (p) *p=0;
            if (FileExists(SaveDialog1->FileName))
              {
               mb = Application->MessageBoxA
               ("Le Fichier existe déjà : Voulez vous le remplacer ?",m_ecoplan,MB_YESNOCANCEL);
                 if (mb==IDCANCEL) return;
                 if (mb==IDNO) return;
                 if (mb==IDYES)
                   {
                    strcpy(fn,name); strcat(fn,".eco"); unlink(fn);
                    strcpy(fn,name); strcat(fn,".dat"); unlink(fn);
                   }
              }



            //MainForm->Caption= "Ecoplanning 5.0 - " + AnsiString(name);

            // mettre a jour Caption of main form
            strcpy(status,"<caption>");
            strcat(status,name);
            strcat(status,"</caption>");

            p=strstr(name,"\\");
            if (p) p=strstr(p+1,"\\");
            if (p)
              {
                strcpy(dbcode,p+1);
                strcpy(dbtitre,dbcode);
              }



            updatedatabase(name,0,1);
          }


}
//---------------------------------------------------------------------------

void __fastcall TplStandard::btSauverClick(TObject *Sender)
{
 updatedatabase(LocalBase,0,0);
 strcpy(status,"<caption>");
 strcat(status,LocalBase);
 strcat(status,"</caption>");
}

//---------------------------------------------------------------------------

/*-----------------------------------------------------------------------
This function is the OnClick event of a TButton that is on a TForm.
On the TForm is also a TImage named image.
------------------------------------------------------------------------*/
void __fastcall TplStandard::Print_Image(TImage *image)
{
    TPrinter *p = Printer();

    // create a memory dc for the image
    HDC h_dc = image->Picture->Bitmap->Canvas->Handle;
    int bmp_w = image->Picture->Bitmap->Width,
    bmp_h = image->Picture->Bitmap->Height;

    HDC h_mem_dc = ::CreateCompatibleDC (h_dc);
    HBITMAP h_mem_bmp = ::CreateCompatibleBitmap (h_dc, bmp_w, bmp_h);
    HBITMAP h_old_bmp = ::SelectObject (h_mem_dc, h_mem_bmp);

    // fix up bad video drivers
    bool is_pal_dev = false;
    LOGPALETTE *pal;
    HPALETTE h_pal, h_old_pal;

    if (::GetDeviceCaps (image->Canvas->Handle, RASTERCAPS) & RC_PALETTE)
    {
        pal = static_cast <LOGPALETTE *>(malloc (sizeof (LOGPALETTE) + (sizeof (PALETTEENTRY) * 256)));
        memset (pal, 0, sizeof (LOGPALETTE) + (sizeof (PALETTEENTRY) * 256));
        pal->palVersion = 0x300;
        pal->palNumEntries = ::GetSystemPaletteEntries(image->Canvas->Handle, 0, 256, pal->palPalEntry);
        if (pal->palNumEntries != 0)
        {
            h_pal = ::CreatePalette (pal);
            h_old_pal = ::SelectPalette (h_mem_dc, h_pal, false);
            is_pal_dev = true;
        }
        else
        {
            free (pal);
        }
    }

    // copy the image on to the memory dc
    ::BitBlt (h_mem_dc, 0, 0, bmp_w, bmp_h, h_dc, 0, 0, SRCCOPY);

    if (is_pal_dev)
    {
        ::SelectPalette (h_mem_dc, h_old_pal, false);
        ::DeleteObject (h_pal);
    }

    // delete the mem dc
    ::SelectObject (h_mem_dc, h_old_bmp);
    ::DeleteDC (h_mem_dc);

    // get memory for a BITMAPIFO Structure
    HANDLE h_bmp_info = ::GlobalAlloc (GHND, sizeof (BITMAPINFO) + (sizeof (RGBQUAD) * 256));
    BITMAPINFO* bmp_info = static_cast <BITMAPINFO *>(::GlobalLock (h_bmp_info));
    //Set up the structure
    memset (bmp_info, NULL, sizeof (BITMAPINFO) + (sizeof (RGBQUAD) * 255));
    bmp_info->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmp_info->bmiHeader.biPlanes = 1;
    bmp_info->bmiHeader.biBitCount = 8;
    bmp_info->bmiHeader.biWidth = bmp_w;
    bmp_info->bmiHeader.biHeight = bmp_h;
    bmp_info->bmiHeader.biCompression = BI_RGB;

    // find out how much memory for the bits
    ::GetDIBits (h_dc, h_mem_bmp, 0, bmp_h, NULL, bmp_info, DIB_RGB_COLORS);

    // Allocate memory for the bits
    HANDLE h_bits = GlobalAlloc (GHND, bmp_info->bmiHeader.biSizeImage);
    void *bits = ::GlobalLock (h_bits);

    // this time get the bits
    ::GetDIBits (h_dc, h_mem_bmp, 0, bmp_h, bits, bmp_info, DIB_RGB_COLORS);

    // fix up for bad video driver

    if (is_pal_dev)
    {
        for (int i = 0; i < pal->palNumEntries; i++)
        {
            bmp_info->bmiColors[i].rgbRed = pal->palPalEntry[i].peRed;
            bmp_info->bmiColors[i].rgbGreen = pal->palPalEntry[i].peGreen;
            bmp_info->bmiColors[i].rgbBlue = pal->palPalEntry[i].peBlue;
        }
        free (pal);
    }

    // begin the printing
    p->BeginDoc ();

    // scale print size
    int scale_x, scale_y;
    if (p->PageWidth < p->PageHeight)
    {
        scale_x = p->PageWidth;
        scale_y = image->Picture->Height * (p->PageWidth / bmp_w);
    }
    else
    {
        scale_x = image->Picture->Width * (p->PageHeight / bmp_h);
        scale_y = p->PageHeight;
    }

    // fix up for print with palette
    is_pal_dev = false;
    if (::GetDeviceCaps (h_dc, RASTERCAPS) & RC_PALETTE)
    {
        pal = static_cast<LOGPALETTE *>(malloc (sizeof (LOGPALETTE) + (sizeof (PALETTEENTRY) * 256)));
        memset (pal, 0, sizeof (LOGPALETTE) + (sizeof (PALETTEENTRY) * 256));
        pal->palVersion = 0x300;
        pal->palNumEntries = 256;
        for (int i = 0; pal->palNumEntries; i++)
        {
            pal->palPalEntry[i].peRed = bmp_info->bmiColors[i].rgbRed;
            pal->palPalEntry[i].peGreen = bmp_info->bmiColors[i].rgbGreen;
            pal->palPalEntry[i].peBlue = bmp_info->bmiColors[i].rgbBlue;
        }
        h_pal = CreatePalette(pal);
        free (pal);
        h_old_pal = SelectPalette(p->Canvas->Handle, h_pal, false);
        is_pal_dev = true;
    }



    scale_y =Printer()->PageHeight ;
    scale_x =Printer()->PageWidth  ;

    // send the bits to the printer
    StretchDIBits(p->Canvas->Handle, 0, 0, scale_x, scale_y,
		0, 0, bmp_w, bmp_h, bits,bmp_info, DIB_RGB_COLORS, SRCCOPY);

    // end the print
    p->EndDoc ();

    // clean up
    ::DeleteObject (h_mem_bmp);

    if (is_pal_dev)
    {
        ::SelectObject (p->Canvas->Handle, h_old_pal);
        ::DeleteObject (h_pal);
    }

    ::GlobalUnlock (bits);
    ::GlobalFree (h_bits);
    ::GlobalUnlock (bmp_info);
    ::GlobalFree (h_bmp_info);
}








void __fastcall TplStandard::Timer2Timer(TObject *Sender)
{
 Timer2->Enabled=false;
 Propage(CH);
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::Button3Click(TObject *Sender)
{
 dateavanc[0]=0;
}
//---------------------------------------------------------------------------





void __fastcall TplStandard::imPortMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// mouse coordinates X and Y
int rx1,rx2,ry1,ry2;
TRect Dst,Src;
int imx; int imy;
int ext;
imx=im->Width;
imy=im->Height;

///   imPort is assigned to Image im !!!!!

ext = (11-Zoom->Position)*100;
rx1= (imx * X / imPort->Width) -ext;
if (rx1 <0) rx1=0;
rx2 = rx1+2*ext;
if (rx2 > im->Width) {rx2=im->Width; rx1=rx2-2*ext; }

ry1= (imy * Y / imPort->Height) - ext;
if (ry1 <0) ry1=0;
ry2 = ry1+2*ext;
if (ry2 > im->Height) {ry2=im->Height; ry1=ry2-2*ext; }


Dst = Rect(0,0,imAvanc->Width,imAvanc->Height);
Src = Rect(rx1,ry1,rx2,ry2);

imAvanc->Canvas->CopyRect(Dst,imPort->Canvas,Src);
}
//---------------------------------------------------------------------------

int __fastcall TplStandard::exist_prev(int t)
{
 int i; int tach=0;
 for (i=1;i<AdvStringGrid1->RowCount;i++)
   {
    sprintf(adv,"%d",sommets[i]);
    // getvalue(1,i,1);
    tach=atoi(adv);
    if (tach==t) { tach=i; break; }
   }
return tach;
}




void __fastcall TplStandard::Image_Avanc(char *title)
{
 int isg,jsg,bcl,tprevis,trow,marg,maxdist,dist; //,distPrev;
 char d1[15]; int a1,m1,j1;
 // Preparation des données dans la grille sg

 Clean_Grid(sg,2);
  // Tri eventuel

 // copy des donnees a afficher dans SG

 // distPrev= convert_date(AnPrev,MoisPrev,JourPrev);

 maxdist=0;
 bcl = 1; isg=1;
 while (bcl < asAvanc->RowCount)
 {
   if (isg>1) sg->RowCount++;
   // recuperer les donnees previsionnelles
   getvalue(5,bcl,39); tprevis = atoi(adv);

   trow = exist_prev(tprevis);
   sg->Cells[1][isg] = "";  // critere 1
   sg->Cells[2][isg] = "";  // critere 2
   sg->Cells[3][isg] = "";  // critere 3

   sg->Cells[4][isg] = sommets[trow];
   //AdvStringGrid1->Cells[1][trow];
   sg->Cells[5][isg] = AdvStringGrid1->Cells[2][trow];

 //  getvalue(1,trow,4); sg->Cells[6][isg]= AnsiString(adv);
   sg->Cells[6][isg] = AdvStringGrid1->Cells[4][trow];   // date debut
   sg->Cells[7][isg] = AdvStringGrid1->Cells[5][trow];   // date fin
   // color depends on the margin
   getvalue(1,trow,8); marg=atoi(adv); // margetotale
   if (marg==0) sg->Cells[8][isg] = 0 ; // color rouge
     else sg->Cells[8][isg] = 1 ; // blue
   getvalue(1,trow,9); sg->Cells[9][isg] = adv; // val 1 = calendrier

   // donnees reelles
   isg++; sg->RowCount++;
   sg->Cells[1][isg] = "";  // critere 1
   sg->Cells[2][isg] = "";  // critere 2
   sg->Cells[3][isg] = "";  // critere 3
   getvalue(5,bcl,62); sg->Cells[9][isg] = AnsiString(adv);  // cal
   getvalue(5,bcl,39); sg->Cells[4][isg] = AnsiString(adv);
   getvalue(5,bcl,40); sg->Cells[5][isg] = AnsiString(adv);
   getvalue(5,bcl,41); sg->Cells[6][isg] = AnsiString(adv);  // date debut
   getvalue(5,bcl,43); sg->Cells[7][isg] = AnsiString(adv);  // date fin

   // calcul de la distance max date de fin (pour le nb de jours)
   strcpy(d1,adv);
   d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
   dist = convert_date(a1+2000,m1,j1);

   if (dist>maxdist) maxdist=dist;

   getvalue(5,bcl,73); marg=atoi(adv); // margetotale
   sg->Cells[8][isg] = 2 ; // color verte

   isg++;
   bcl++;
  }

 Graph_Avanc(sg->RowCount-1,maxdist);

}


void __fastcall TplStandard::Graph_Avanc(int nbt,int maxdist)
{
 int espacex,espacey;
 // clean the rectangle


 //
 if (im) delete im;
  im = new Graphics::TBitmap();
  im->PixelFormat =pf8bit;
  im->Height= Printer()->PageHeight;
  im->Width=  Printer()->PageWidth;

 TRect Diagram = Rect(0,0, im->Width,im->Height);
 im->Canvas->Brush->Color = clWhite; // BgColor;
 im->Canvas->FillRect(Diagram);

 espacex = im->Width/(maxdist+20);
 if (espacex > 70) espacex=70;

 espacey = im->Height/(nbt/2 + 12);
 if (espacey > 70) espacey=70;


Draw_Calendars(nbt,maxdist,espacex,espacey);
Draw_Diagram(maxdist,espacex,espacey);

 //imPort->Stretch = true;
 //imLand->Stretch=true;
 // imPort->Picture->Graphic = im;
 //imPort->Canvas->Draw(0,0,im);

 imPort->Picture->Assign(im);
 imLand->Picture->Assign(im);

int rx1,rx2,ry1,ry2;
TRect Dst,Src;
//int imx; int imy;
//imx=im->Width;
//imy=im->Height;
int ext;

///   imPort is assigned to Image im !!!!!

ext = 500;
rx1= 0;
if (rx1 <0) rx1=0;
rx2 = rx1+2*ext;
if (rx2 > im->Width) {rx2=im->Width; rx1=rx2-2*ext; }

ry1= 0;
if (ry1 <0) ry1=0;
ry2 = ry1+2*ext;
if (ry2 > im->Height) {ry2=im->Height; ry1=ry2-2*ext; }

Dst = Rect(0,0,imAvanc->Width,imAvanc->Height);
Src = Rect(rx1,ry1,rx2,ry2);
imAvanc->Canvas->CopyRect(Dst,imPort->Canvas,Src);
}



void __fastcall TplStandard::Draw_Calendars(int nbt,int maxdist, int spx,int spy)
{
 int ix,xbase,x1base,y;
 char tmp[255];
 TDateTime dtFirst;
 int nbtach;

 nbtach=nbt/2;
 y= (nbtach+4)*spy;
 TRect Diagram = Rect(0,spy,im->Width,3*spy);
 im->Canvas->Brush->Color = clAqua; //
 im->Canvas->FillRect(Diagram);

 im->Canvas->Pen->Width = 1;
 im->Canvas->Brush->Style = bsSolid;

 // tracé du rectangle global;
 im->Canvas->Pen->Color = clBlack;
 im->Canvas->MoveTo(0,0);
 im->Canvas->LineTo(im->Width-1,0);
 im->Canvas->LineTo(im->Width-1,y);
 im->Canvas->LineTo(0,y);  //im->Height-1);
 im->Canvas->LineTo(0,0);

 // ligne pour la bande de titre
 im->Canvas->MoveTo(0,spy);
 im->Canvas->LineTo(im->Width-1,spy);

 // lignes pour les dates

 im->Canvas->MoveTo(0,2*spy);
 im->Canvas->LineTo(im->Width-1,2*spy);
 im->Canvas->MoveTo(0,3*spy);
 im->Canvas->LineTo(im->Width-1,3*spy);

 im->Canvas->Font->Style = TFontStyles()<< fsBold;

 if (nbtach< 15) im->Canvas->Font->Size = 20;
 else if (nbtach< 35) im->Canvas->Font->Size = 18;

 else if (nbtach< 55) im->Canvas->Font->Size = 18;
 else if (nbtach< 75) im->Canvas->Font->Size = 16;
 else if (nbtach< 95) im->Canvas->Font->Size = 16;
 else if (nbtach< 115) im->Canvas->Font->Size = 20;
 else if (nbtach< 135) im->Canvas->Font->Size = 14;
 else if (nbtach< 155) im->Canvas->Font->Size = 12;
 else if (nbtach< 175) im->Canvas->Font->Size = 12;
 else im->Canvas->Font->Size = 8;


 im->Canvas->Font->Color = clBlack;
 im->Canvas->Brush->Color = clAqua;



 y= (nbtach+4)*spy;

 for (ix=0;ix<= maxdist;ix++)    // tenir compte du calendrier
   {
    xbase=ix*spx + spx/3;
    add_jour(AnPrev,MoisPrev,JourPrev,ix);
    sprintf(tmp, "%02d",Jour);
    im->Canvas->Font->Color = clBlack;
    im->Canvas->Brush->Color = clAqua;
    im->Canvas->TextOut(xbase,3+spy,(AnsiString) tmp);
    im->Canvas->MoveTo(ix*spx,spy);
    im->Canvas->LineTo(ix*spx,2*spy);

    // tracé des conges
      xbase= (ix+1)*spx;
      if (cal[1][ix]=='N')
      {
       x1base  =  xbase - spx+1;
       Diagram = Rect(x1base,3*spy+1,xbase,y); //im->Height-3*spy);
       im->Canvas->Brush->Color = clSilver; //
       im->Canvas->FillRect(Diagram);
      }

//     imGantt->Canvas->Brush->Color = clWhite;
     im->Canvas->Font->Color = clBlack;
     im->Canvas->Brush->Color = clWhite;

     if (spx > 50)
      {
     im->Canvas->Pen->Style = psDot;  // Dash;
     im->Canvas->MoveTo(xbase,spy*3);
     im->Canvas->LineTo(xbase,y); //im->Height-3*spy);
     im->Canvas->Pen->Style = psSolid;
      }
     add_jour(AnPrev,MoisPrev,JourPrev,ix);
     dtFirst = EncodeDate(An,Mois,Jour);

     int firstday = dtFirst.DayOfWeek();
     if (firstday == 2)  // Mondays
       {
       // trace d'un trait vertical noir
        x1base  =  xbase - spx;
        sprintf(tmp,"%02d/%02d/%04d",Jour,Mois,An);
        im->Canvas->Pen->Color = clBlack;
        im->Canvas->Brush->Color = clAqua;  // White;
        im->Canvas->TextOut(x1base+5,2*spy+3,(AnsiString) tmp);
        im->Canvas->Pen->Color = clBlack;
        im->Canvas->Brush->Color = clWhite;  // White;
        im->Canvas->MoveTo(x1base,2*spy);
        im->Canvas->LineTo(x1base,y);  //im->Height-3*spy);
       }
     if (Jour==1)  // 1er du mois, un trait rouge;
       {
        x1base  =  xbase - spx;
        im->Canvas->Font->Color = clRed;
        im->Canvas->Brush->Color = clAqua;
        imGantt->Canvas->MoveTo(x1base,2*spy);
        imGantt->Canvas->LineTo(x1base,y); //im->Height-3*spy);
       }

   }  // end for

 // copie du "rectangle bleu des dates
 Diagram = Rect(0,spy,im->Width,3*spy+1);
 y= (nbtach+4)*spy;
 TRect Dst = Rect(0,y,im->Width,y+2*spy+1);
 im->Canvas->CopyRect(Dst,im->Canvas,Diagram);
}


void __fastcall TplStandard::Draw_Diagram(int maxdist,int spx,int spy)
{
 int nbt,ix,color,jcal,dist1,dist2;
 char tmp[200],d1[15],d2[15];
 int a1,a2,m1,m2,j1,j2;
 int jx; int x,y,interval;
 int step,k,xt,yt,nbtaches,it;
 AnsiString Texte;

 step = spx / 5;
 nbt = sg->RowCount - 1;
 im->Canvas->Pen->Width = 5;
 nbtaches = nbt/2;

 for (it=1;it<=nbtaches;it++)
  {

   ix = it*2-1;

   strcpy(d1,sg->Cells[6][ix].c_str()); // date debut
   strcpy(d2,sg->Cells[7][ix].c_str()); // date fin
   d1[2]=0; j1=atoi(d1);  d1[5]=0; m1=atoi(d1+3);  d1[8]=0; a1=atoi(d1+6);
   dist1 = convert_date(a1+2000,m1,j1);
   d2[2]=0; j2=atoi(d2);  d2[5]=0; m2=atoi(d2+3);  d2[8]=0; a2=atoi(d2+6);
   dist2 = convert_date(a2+2000,m2,j2);

   interval = dist2-dist1+1;
   y = spy*(it+3);   // 3 a cause des titre
   //  ecrire d'abord le texte
   im->Canvas->Font->Color = clBlack;
   im->Canvas->Brush->Color = clWhite;
   im->Canvas->Brush->Style = bsClear;
   yt = y-spy/3;
   xt = dist1*spx+1;
   Texte = sg->Cells[5][ix];
   im->Canvas->TextOut(xt,yt,Texte);

   //yt = y-spy/10;  xt = (dist2+1)*spx + 1;
   //Texte = sg->Cells[7][ix];
   //im->Canvas->TextOut(xt,yt,Texte);

   // tache previsionnelle

   y=y+spy/3;
   strcpy(tmp,sg->Cells[8][ix].c_str());
   color=atoi(tmp);
   switch (color)
    {
     case 0: im->Canvas->Pen->Color = clRed; break;
     case 1: im->Canvas->Pen->Color = clBlue; break;
     case 2: im->Canvas->Pen->Color = clGreen; break;
     case 3: im->Canvas->Pen->Color = clPurple; break;
    }
   // calendrier dans val1 (col 9)
   strcpy(tmp,sg->Cells[9][ix].c_str()); jcal= atoi(tmp);

    for (jx=0;jx<interval;jx++)
     {
      x = (dist1+jx) * spx;
      im->Canvas->MoveTo(x,y);
      if (cal[jcal][dist1+jx]== 'N')
        {
         for (k=0;k<2;k++)
           {
            x = x + step;
            im->Canvas->MoveTo(x,y);
            x = x+step;
            im->Canvas->LineTo(x,y);
           }

        }
      else im->Canvas->LineTo(x+spx,y);
     }

   ix = ix+1;   // tache reelle
   y = y + spy/5;
   strcpy(tmp,sg->Cells[8][ix].c_str());
   color=atoi(tmp);
   switch (color)
    {
     case 0: im->Canvas->Pen->Color = clRed; break;
     case 1: im->Canvas->Pen->Color = clBlue; break;
     case 2: im->Canvas->Pen->Color = clGreen; break;
     case 3: im->Canvas->Pen->Color = clPurple; break;
    }
   // calendrier dans val1 (col 9)
   strcpy(tmp,sg->Cells[9][ix].c_str()); jcal= atoi(tmp);

    for (jx=0;jx<interval;jx++)
     {
      x = (dist1+jx) * spx;
      im->Canvas->MoveTo(x,y);
      if (cal[jcal][dist1+jx]== 'N')
        {
         for (k=0;k<2;k++)
           {
            x = x + step;
            im->Canvas->MoveTo(x,y);
            x = x+step;
            im->Canvas->LineTo(x,y);
           }
        }
      else im->Canvas->LineTo(x+spx,y);
     }
  }
}


//---------------------------------------------------------------------------

void __fastcall TplStandard::btPrAvancClick(TObject *Sender)
{
 Image_Avanc("Actualisation");
 Print_Image(imPort);  // Port);
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::imLandMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
int rx1,rx2,ry1,ry2;
TRect Dst,Src;
int imx; int imy;
imx=im->Width;
imy=im->Height;
int ext;

///   imLand is assigned to Image im !!!!!

ext = (11-Zoom->Position)*100;
rx1= (imx * X / imLand->Width) -ext;
if (rx1 <0) rx1=0;
rx2 = rx1+2*ext;
if (rx2 > im->Width) {rx2=im->Width; rx1=rx2-2*ext; }

ry1= (imy * Y / imLand->Height) - ext;
if (ry1 <0) ry1=0;
ry2 = ry1+2*ext;
if (ry2 > im->Height) {ry2=im->Height; ry1=ry2-2*ext; }


Dst = Rect(0,0,imAvanc->Width,imAvanc->Height);
Src = Rect(rx1,ry1,rx2,ry2);

 imAvanc->Canvas->CopyRect(Dst,imLand->Canvas,Src);
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::btFontClick(TObject *Sender)
{
 FontDialog1 = new TFontDialog(NULL);
 FontDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::asAvancGetCellColor(TObject *Sender, int ARow,
      int ACol, TGridDrawState AState, TBrush *ABrush, TFont *AFont)
{

 int perc;

 getvalue(5,ARow,71); perc = atoi(adv);
 if (perc == 0)
   {
    if (ACol==1)
      {  ABrush->Color=clYellow;
      }
   }

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::Clean_Grid(TAdvStringGrid *sgrid, int strow)
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

void _fastcall TplStandard::Read_Criteres()
{
 FILE *fp;
 char tmp[250]; int ctr;
 char buffer[250];

 strcpy(tmp,LocalBase); strcat(tmp,"_crit.txt");
 fp=fopen(tmp,"rt");
 if (fp)
   {
    buffer[0]=0; ctr=0;
    fgets(buffer,512,fp);
     while (!feof(fp))   // lire les 8 premiers records;
      {
       ctr++;
       ExtractValue(tmp,buffer,"l",0);
       asCrit->Cells[ctr*2+1][0]=tmp;
       ExtractValue(tmp,buffer,"d",0);
       asCrit->Cells[ctr*2+2][0]=tmp;
       if (ctr==8) break;
       fgets(buffer,512,fp);
      }
    fclose (fp);
   }
}


int  __fastcall TplStandard::RechercheColCrit(char *str)
{
int result;  AnsiString Str; int i,j;
 result=0;
 Str = AnsiString(str);
 for (i=1;i<=8;i++)
  {
   j=2*i+2;  // libelle , et non pas le code
   if (asCrit->Cells[j][0]==Str) result=i;
  }
return result;

}


void __fastcall TplStandard::Load_Grille_Criteres()
{
 FILE*fp;
 int i,ctr; char fn[250];  char buf[2024];
 char tmp[250];

 i=av->RowCount;

 Clean_Grid(asCrit,2);
 Read_Criteres();
 for (i=1;i<=nb_taches;i++)
   {
    if (i>1) asCrit->RowCount++;
    asCrit->Cells[1][i]=sommets[i];
    asCrit->Cells[2][i]=libel[i];
   }

         // Lecture du fichier _affect;
   strcpy(fn,LocalBase);
   strcat(fn,"_affect.txt");
   fp=fopen(fn,"rt");
   if (fp)
     {
      buf[0]=0; ctr=0;
      fgets(buf,1000,fp);
      while (!feof(fp))   // lire les 8 premiers records;
        {
         if (strlen(buf)>5)
               {
                ctr++;
                ExtractValue(tmp,buf,"nt",0); asCrit->Cells[1][ctr]=tmp;

                ExtractValue(tmp,buf,"des",0); asCrit->Cells[2][ctr]=tmp;
                ExtractValue(tmp,buf,"c1",0); asCrit->Cells[3][ctr]=tmp;
                av->Cells[41][ctr]=tmp;
                ExtractValue(tmp,buf,"d1",0); asCrit->Cells[4][ctr]=tmp;
                av->Cells[51][ctr]=tmp;
                ExtractValue(tmp,buf,"c2",0); asCrit->Cells[5][ctr]=tmp;
                av->Cells[42][ctr]=tmp;
                ExtractValue(tmp,buf,"d2",0); asCrit->Cells[6][ctr]=tmp;
                av->Cells[52][ctr]=tmp;
                ExtractValue(tmp,buf,"c3",0); asCrit->Cells[7][ctr]=tmp;
                av->Cells[43][ctr]=tmp;
                ExtractValue(tmp,buf,"d3",0); asCrit->Cells[8][ctr]=tmp;
                av->Cells[53][ctr]=tmp;
                ExtractValue(tmp,buf,"c4",0); asCrit->Cells[9][ctr]=tmp;
                av->Cells[44][ctr]=tmp;
                ExtractValue(tmp,buf,"d4",0); asCrit->Cells[10][ctr]=tmp;
                av->Cells[54][ctr]=tmp;
                ExtractValue(tmp,buf,"c5",0); asCrit->Cells[11][ctr]=tmp;
                av->Cells[45][ctr]=tmp;
                ExtractValue(tmp,buf,"d5",0); asCrit->Cells[12][ctr]=tmp;
                av->Cells[55][ctr]=tmp;
                ExtractValue(tmp,buf,"c6",0); asCrit->Cells[13][ctr]=tmp;
                av->Cells[46][ctr]=tmp;
                ExtractValue(tmp,buf,"d6",0); asCrit->Cells[14][ctr]=tmp;
                av->Cells[56][ctr]=tmp;
                ExtractValue(tmp,buf,"c7",0); asCrit->Cells[15][ctr]=tmp;
                av->Cells[47][ctr]=tmp;
                ExtractValue(tmp,buf,"d7",0); asCrit->Cells[16][ctr]=tmp;
                av->Cells[57][ctr]=tmp;
                ExtractValue(tmp,buf,"c8",0); asCrit->Cells[17][ctr]=tmp;
                av->Cells[48][ctr]=tmp;
                ExtractValue(tmp,buf,"d8",0); asCrit->Cells[18][ctr]=tmp;
                av->Cells[58][ctr]=tmp;
                } // if strlen

                fgets(buf,1000,fp);
               } // while
            fclose(fp);
           } //  if fp
}



void __fastcall TplStandard::PageControl1Change(TObject *Sender)
{
 FILE *fp;
 int Pindex,i;    int ctr;
 char tmp[250],fn[250],buf[1024];

 Pindex = PageControl1->ActivePageIndex;

 switch (Pindex)
   {
    case 8 :
          strcpy(m_menu,"ENACoches1");
          if (flag_loadavanc)
            {
             flag_loadavanc=false;
             Load_Avanc(FileNameAvanc,true);
            }
         break;

    case 2 :
          strcpy(m_menu,"ENACoches2");
          Load_Grille_Criteres();
          break;

   } // end switch
 //sprintf(tmp,"Active Page Index is %d",Pindex);
 // Application->MessageBoxA(tmp,m_ecoplan,MB_OK);
 }
//---------------------------------------------------------------------------

void __fastcall TplStandard::Coche_Decoche_Crit(int col,int row)
{


  if ((row > nb_taches) || (row < 0)) return;
  if (col==0)
     {
      if (coch[row]=='X') { coch[row]=' '; asCrit->Cells[0][row] = ' '; }
      else { coch[row]='X';    asCrit->Cells[0][row] = AnsiString(strcoche); }
     }
 }

void __fastcall TplStandard::asCritMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int Row,Column;
  asCrit->MouseToCell(X, Y, Column, Row);
  CrRow=Row;CrCol=Column;
  Coche_Decoche_Crit(Column,Row);
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::Cocher_Decocher_Crit()
{
 int i;
 for (i=1;i<=nb_taches;i++)
  {
   if (coch[i]==' ')
    {
     coch[i] = 'X';
     asCrit->Cells[0][i]=AnsiString(strcoche);
    }
   else
    {
     coch[i] = ' ';
     asCrit->Cells[0][i]=" ";

    }
  }

}

void __fastcall TplStandard::Tout_Cocher_Crit()
{
  int i;

 for (i=1;i<=nb_taches;i++) // §§§§§§§§§§§§§§§
   { coch[i] = 'X';
     asCrit->Cells[0][i]=AnsiString(strcoche);  //"X";
   }

}

void __fastcall TplStandard::Tout_Decocher_Crit()
{
int i;
 for (i=1;i<=nb_taches;i++)  // §§§§§§§§§§§§§§§§§§§
   {
    coch[i]=' ';
    asCrit->Cells[0][i]=" ";
   }

}
void __fastcall TplStandard::asCritContextPopup(TObject *Sender,
      TPoint &MousePos, bool &Handled)
{
  int X,Y;
 X = MousePos.x;
 Y = MousePos.y;
  //AdvStringGrid1->MouseToCell(X, Y, CurCol, CurRow);
 // conversion en ligne et colonne courantes
 PopupCrit->Popup(X, Y);

}
//---------------------------------------------------------------------------



void __fastcall TplStandard::FormActivate(TObject *Sender)
{

 //  envoyer un signal pour dire qui a le focus (nom du projet);
 int a;
 a=0;
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::asCritClickCell(TObject *Sender, int ARow,
      int ACol)
{
 FILE *fp;
 int Col,Ind,j,ctr;
 char tmp[1000],xbuffer[520];
 char c1[50],c2[50],c3[50],c4[50];
 char lib[100];

 lC1->Caption="";lC2->Caption="";lC3->Caption="";lC4->Caption="";
 lD1->Caption="";lD2->Caption="";lD3->Caption="";lD4->Caption="";
 lT1->Caption="";lT2->Caption="";lT3->Caption="";lT4->Caption="";
 j = ACol % 2;
  if (j==0) Col=ACol-1; else Col=ACol;

 Ind = (Col-2)/2; Ind++;
 if ((Ind<1) || (Ind>8)) return;
 strcpy(tmp,asCrit->Cells[Col][ARow].c_str());


 j=Explode('-',tmp);
 if (strlen(params[0])) lC1->Caption = AnsiString(params[0]); else lC1->Caption = "";
 if (strlen(params[1])) lC2->Caption = AnsiString(params[1]); else lC2->Caption = "";
 if (strlen(params[2])) lC3->Caption = AnsiString(params[2]); else lC3->Caption = "";
 if (strlen(params[3])) lC4->Caption = AnsiString(params[3]); else lC4->Caption = "";

 strcpy(tmp,LocalBase);
 strcat(tmp,"_crit.txt");


 fp=fopen(tmp,"rt");
 if (fp == NULL)  return;
 // recherche des libellés
  xbuffer[0]=0; ctr=0;
  fgets(xbuffer,512,fp);
   while (!feof(fp))   // lire les 8 premiers records;
      {

       ctr++;
       if (ctr==8) break;
       fgets(xbuffer,512,fp);
       }

     fgets(xbuffer,512,fp);
     ctr = 0;


 while (!feof(fp))
    {

      ctr++;
      if (strlen(xbuffer) > 5)
       {
       ExtractValue(c1,xbuffer,"c1",0); ExtractValue(c2,xbuffer,"c2",0);
       ExtractValue(c3,xbuffer,"c3",0); ExtractValue(c4,xbuffer,"c4",0);
       ExtractValue(lib,xbuffer,"d",0);
       if (strcmp(c1,params[0])==0)
        {
         if (strcmp(c2,params[1])==0)
           {
            if (strcmp(c3,params[2])==0)
               {
                if (strcmp(c4,params[3])==0)
                   {
                    if (strlen(c4)) { lD4->Caption = AnsiString(lib); }
                   }   //C4
                else lD3->Caption = AnsiString(lib);
               } //C3
            else lD2->Caption = AnsiString(lib);
           }   //C2
          else lD1->Caption = AnsiString(lib);
         }//C1

       }  // strlen (5);
      fgets(xbuffer,512,fp);
      } // end while
 fclose (fp);
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::btAccCritClick(TObject *Sender)
{
 TCriteres *Criteres;
 Criteres = new TCriteres(Application);
 Criteres->Show(); //Modal();
 // delete Criteres;

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::btSaveAffectClick(TObject *Sender)
{
 // Sauvegarde des données présentes dans la grille
 // Fichier séquentiel texte

 char fn[250];
 FILE *fp;
 int i,count;  char tmp[2000];
 strcpy(fn,LocalBase);
 strcat(fn,"_affect.txt");

 count=asCrit->RowCount;
 fp = fopen(fn,"wt");
 if (fp)
   {
    for (i=1;i<count;i++)
    {
   tmp[0]=0;
   strcat(tmp,"<nt>"); strcat(tmp,asCrit->Cells[1][i].c_str()); strcat(tmp,"</nt>");
   strcat(tmp,"<des>"); strcat(tmp,asCrit->Cells[2][i].c_str()); strcat(tmp,"</des>");
   strcat(tmp,"<c1>"); strcat(tmp,asCrit->Cells[3][i].c_str()); strcat(tmp,"</c1>");
   strcat(tmp,"<d1>"); strcat(tmp,asCrit->Cells[4][i].c_str()); strcat(tmp,"</d1>");
   strcat(tmp,"<c2>"); strcat(tmp,asCrit->Cells[5][i].c_str()); strcat(tmp,"</c2>");
   strcat(tmp,"<d2>"); strcat(tmp,asCrit->Cells[6][i].c_str()); strcat(tmp,"</d2>");
   strcat(tmp,"<c3>"); strcat(tmp,asCrit->Cells[7][i].c_str()); strcat(tmp,"</c3>");
   strcat(tmp,"<d3>"); strcat(tmp,asCrit->Cells[8][i].c_str()); strcat(tmp,"</d3>");
   strcat(tmp,"<c4>"); strcat(tmp,asCrit->Cells[9][i].c_str()); strcat(tmp,"</c4>");
   strcat(tmp,"<d4>"); strcat(tmp,asCrit->Cells[10][i].c_str()); strcat(tmp,"</d4>");
   strcat(tmp,"<c5>"); strcat(tmp,asCrit->Cells[11][i].c_str()); strcat(tmp,"</c5>");
   strcat(tmp,"<d5>"); strcat(tmp,asCrit->Cells[12][i].c_str()); strcat(tmp,"</d5>");
   strcat(tmp,"<c6>"); strcat(tmp,asCrit->Cells[13][i].c_str()); strcat(tmp,"</c6>");
   strcat(tmp,"<d6>"); strcat(tmp,asCrit->Cells[14][i].c_str()); strcat(tmp,"</d6>");
   strcat(tmp,"<c7>"); strcat(tmp,asCrit->Cells[15][i].c_str()); strcat(tmp,"</c7>");
   strcat(tmp,"<d7>"); strcat(tmp,asCrit->Cells[16][i].c_str()); strcat(tmp,"</d7>");
   strcat(tmp,"<c8>"); strcat(tmp,asCrit->Cells[17][i].c_str()); strcat(tmp,"</c8>");
   strcat(tmp,"<d8>"); strcat(tmp,asCrit->Cells[18][i].c_str()); strcat(tmp,"</d8>");
   strcat(tmp,"\r\n");
   fputs(tmp,fp);
  }
 fclose(fp);
 Application->MessageBoxA("Sauvegarde Effectuée",m_ecoplan,MB_OK);
 }  // if fp
 else Application->MessageBoxA("Impossible d'ouvrir le fichier Affectation",m_ecoplan,MB_OK);

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::btResetClick(TObject *Sender)
{
 Clean_Grid(asTri,2);
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::Planning_Defaut()
{
 //int count,
 int i,nt;
 char tmp[250];

 AnsiString Val;
 /*
 Load_Grille_Criteres();
 Clean_Grid(asTri,2);
 count = asAvanc->RowCount;
 if (count == 2) return;
 for (i=1;i<count;i++)
  {
   strcpy(tmp,asAvanc->Cells[1][i].c_str());    // Avanc
   nt=atoi(tmp);
   Add_Row(i,nt);    // ajoute toutes les données disponibles
  }
*/

/*
asTri->SortIndexes->Clear();
asTri->SortIndexes->Add(1);
asTri->SortIndexes->Add(2);
asTri->SortIndexes->Add(3);
asTri->SortIndexes->Add(4);
asTri->SortIndexes->Add(5);
asTri->SortIndexes->Add(6);
asTri->SortIndexes->Add(7);
asTri->SortIndexes->Add(8);
asTri->QSortIndexed();
*/
asTri->QSort();

Graph_Default('L');
// count = 0;
}


void __fastcall TplStandard::btToutClick(TObject *Sender)
{
 Planning_Defaut();
}


int __fastcall TplStandard::Add_Row(int row,int nt)
{
 int r,i,ncol,indx;
 if (row>1) asTri->RowCount++;
 r=asTri->RowCount-1;

 indx=exist_tache(nt,nb_taches);
 if (indx==0) return 0;

/* asTri->Cells[0][r] = "N";  // type
 asTri->Cells[20][r] = asAvanc->Cells[1][row];  // ntache
 asTri->Cells[21][r] = asAvanc->Cells[2][row];  //  design
 asTri->Cells[22][r] = asAvanc->Cells[4][row];
 // date de but reel et fin reel
 asTri->Cells[28][r] = asAvanc->Cells[3][row];  // Reel
 asTri->Cells[29][r] = asAvanc->Cells[5][row];  // Reel
 asTri->Cells[32][r] = asAvanc->Cells[15][row];  // Marge
*/
 asTri->Cells[0][r] = "N";  // type
 asTri->Cells[20][r] = asAvanc->Cells[1][row];  // ntache
 asTri->Cells[21][r] = asAvanc->Cells[2][row];  //  design
 asTri->Cells[22][r] = asAvanc->Cells[4][row];
 // date de but reel et fin reel
 asTri->Cells[28][r] = asAvanc->Cells[3][row];  // Reel
 asTri->Cells[29][r] = asAvanc->Cells[5][row];  // Reel
 asTri->Cells[32][r] = asAvanc->Cells[15][row];  // Marge




 //
 for (i=1;i<=8;i++)
   {
    ncol = i*2+1;
    asTri->Cells[i+1][r] = asCrit->Cells[ncol][row];   //
    ncol++;
    asTri->Cells[i+10][r] = asCrit->Cells[ncol][row];   // libelle
   }
return 0;
}

//---------------------------------------------------------------------------

void __fastcall TplStandard::btTriClick(TObject *Sender)
{
/*
asTri->SortIndexes->Clear();
asTri->SortIndexes->Add(1);
asTri->SortIndexes->Add(2);
asTri->SortIndexes->Add(3);

asTri->SortIndexes->Add(4);
asTri->SortIndexes->Add(5);
asTri->SortIndexes->Add(6);
asTri->SortIndexes->Add(7);
asTri->SortIndexes->Add(8);
asTri->QSortIndexed();
*/
asTri->QSort();
}

//---------------------------------------------------------------------------

void __fastcall TplStandard::btPrepClick(TObject *Sender)
{
 //Prepare_Graphic(P_MODE);
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::Define_Text(int rang,bool actif,bool HC, AnsiString S,TColor Fc, TColor Bc,
                                    AnsiString  FontName, int Fz, char S1, char S2,
                                    char Jh, char Jv,int Retrait,char ptype)
{
 PACTIF[rang]=actif;
 P_ORIENT[rang]=HC;  // Horizontal, Colonne
 PT[rang]=S; PC[rang]=Fc;  PB[rang]=Bc; PF[rang]=FontName;
 PH[rang] = Fz;  PN[rang]= S1; PX[rang]=S2; PJH[rang]=Jh; PJV[rang]=Jv;   // just V
 PR[rang] = Retrait; PTYPE[rang]=ptype;
}

void __fastcall TplStandard::Affect_LS(int rang, bool lsh,TColor lsh_c,int lsh_s, int lsh_e,
                                  bool lsb,TColor lsb_c,int lsb_s, int lsb_e)
{
 LSH[rang]=lsh; LSH_COLOR[rang]=lsh_c;
 LSH_STYLE[rang]=lsh_s; LSH_EPAISSEUR[rang]=lsh_e;

 LSB[rang]=lsb;  LSB_COLOR[rang]=lsb_c;
 LSB_STYLE[rang]=lsb_s; LSB_EPAISSEUR[rang]=lsb_e;

}

void __fastcall TplStandard::Graph_Default(char style)
{
  int i;

 // calculer nb de taches (detail)
 NB_DETAIL = asTri->RowCount-1;
 if (NB_DETAIL <=1)
   {
    Application->MessageBoxA("Pas de Taches",m_ecoplan,MB_OK);
    return;
   }

 // MARGES
 P_MARGH1=P_MARGH2=50;
 P_MARGV1=P_MARGV2=30;


 //  P_CADRE
 P_CADRE = 'O';  // oui;
 P_ELC = 5;   // epaisseur
 P_CLC = clBlack;  // couleur Ligne


 // Texte
 Define_Text(0,true,true,"Planning : -Par Phases",clBlue,clWhite,"Arial",24,'I','B','G','C',15,'L');
 Define_Text(1,true,true,"- Par Lots",clBlue,clWhite,"Arial",24,'I','B','G','C',120,'L');
 Define_Text(2,true,true,"- Par Prestations",clBlue,clWhite,"Arial",24,'I','B','G','C',120,'L');
 Define_Text(3,true,true,"RESTRUCTURATION RESTAURANT",clBlack,clWhite,"Arial",32,'N','B','C','C',0,'L');
 Define_Text(4,true,true,"",clBlack,clWhite,"Arial",24,'N','B','G','C',0,'L');
 Define_Text(5,true,true,"",clBlack,clWhite,"Arial",32,'N','B','G','C',0,'L');    // 2eme sous titre
 Define_Text(6,true,true,"Logiciel Ecoplanning",clBlack,clWhite,"Arial",24,'N','B','C','C',15,'L');
 Define_Text(7,true,true,"7 Rue des Hortensias",clBlack,clWhite,"Arial",24,'N','B','C','C',15,'L');
 Define_Text(8,true,true,"92350 Le Plessis Robinson",clBlack,clWhite,"Arial",24,'N','B','C','C',15,'L');

 //  Calendrier

 TColor Bg1,Bg2;

 //Bg1=clYellow;   Bg2= clBlue;    //  00BBGGRR

 Bg1 =TColor(0x99FFFF);  Bg2 =TColor(0xFFFF99);

 Define_Text(9,true,true,"Cal 1",clBlack,Bg1,"Arial",18,'N','B','C','C',15,'L');
 Define_Text(10,true,true,"Cal 2",clBlack,Bg2,"Arial",18,'N','B','G','C',15,'L');

 //   Le texte est defini dynamiquement
 Define_Text(11,true,true,"Crit0",Bg1,clBlack,"Arial",20,'I','B','G','C',200,'L');    // en ligne
 Affect_LS(11,true,clBlack,0,2,true,clBlack,0,2);

 Define_Text(12,true,false,"Crit1",Bg2,clBlack,"Arial",20,'N','B','G','C',0,'C');      // en colonnes
 Affect_LS(12,true,clBlack,0,2,true,clBlack,0,2);
 Define_Text(13,false,false,"Crit2",clBlack,clWhite,"Arial",24,'I','B','G','C',200,'C');
 Define_Text(14,false,false,"Crit3",clBlack,clWhite,"Arial",24,'N','B','G','C',10,'C');
 Define_Text(15,false,false,"Crit4",clBlack,clWhite,"Arial",24,'I','B','G','C',200,'C');
 Define_Text(16,false,false,"Crit5",clBlack,clWhite,"Arial",24,'N','B','G','C',10,'C');
 Define_Text(17,false,false,"Crit6",clBlack,clWhite,"Arial",24,'I','B','G','C',200,'C');
 Define_Text(18,false,false,"Crit7",clBlack,clWhite,"Arial",24,'N','B','G','C',10,'C');
 // Detail  Texte Dans Colonnes, si on emploie des données colonnes
 Define_Text(20,true,false,"Colonne",clBlack,clWhite,"Arial",24,'N','B','G','C',0,'C');

 // Detail Texte des libelles de taches
 Define_Text(21,true,false,"Crit3",clBlack,clWhite,"Arial",18,'N','B','G','C',0,'C');



 // Affectation des criteres
/*
 P_CR0 = 'H'; P_CR1 = 'V'; P_CR2=' '; P_CR3 = ' ';
 P_RH0 = 300;  // retrait Horizontal
 P_RH1 = 5;
 P_RH2 = 5;
 P_RH3 = 5;
       // faire routine qui long calcule en fonction du texte et de la fonte.
       // TextWidth and TextHeight
 P_LCR0 = 450; // longueur max en pixels
 P_LCR1 = 350;
 P_LCR2 = 0;
 P_LCR3 = 0;
*/
 // Calcul nombre "ruptures" Crit 0; si en Ligne Crit1, ,crit2, crit3;
 Compute_Ruptures();


int haut = 18;
 // calculer nb de colonnes
 P_COL = 0;
 for (i=0;i<21;i++) {  P_LC[i] = 0;  P_TRICOL[i]=0; }
 // attribuer les colonnes et les champs
 P_TRICOL[0]=11;   P_ATTR[0]='H';  P_FONT[0]="Arial"; P_HAUT[0]= haut;
   P_ITAL[0]='N'; P_BOLD[0]='B'; P_EPAISSV[0]=15; P_TITRE_COL[0]="";
 P_TRICOL[1]=12;   P_ATTR[1]='C';  P_FONT[1]="Arial"; P_HAUT[1]= haut;
   P_ITAL[1]='N'; P_BOLD[1]='B'; P_EPAISSV[1]=2; P_TITRE_COL[1]="";
 P_TRICOL[2]=20;   P_ATTR[2]='C';  P_FONT[2]="Arial"; P_HAUT[2]= haut;
   P_ITAL[2]='N'; P_BOLD[2]='B'; P_EPAISSV[2]=2; P_TITRE_COL[2]="N°";
 P_TRICOL[3]=28;  P_ATTR[3]='C';  P_FONT[3]="Arial"; P_HAUT[3]= haut;
   P_ITAL[3]='N'; P_BOLD[3]='B'; P_EPAISSV[3]=2; P_TITRE_COL[3]="Début";
 P_TRICOL[4]=29;  P_ATTR[4]='C';  P_FONT[4]="Arial"; P_HAUT[4]= haut;
   P_ITAL[4]='N'; P_BOLD[4]='B'; P_EPAISSV[4]=2; P_TITRE_COL[4]="Fin";
 P_TRICOL[5]=22;  P_ATTR[5]='C';  P_FONT[5]="Arial"; P_HAUT[5]= haut;
   P_ITAL[5]='N'; P_BOLD[5]='B'; P_EPAISSV[5]=2; P_TITRE_COL[5]="Dur";
 P_TRICOL[6]=0;  P_ATTR[6]='C';  P_FONT[6]="Arial"; P_HAUT[6]= haut;
   P_ITAL[6]='N'; P_BOLD[6]='N'; P_EPAISSV[6]=2; P_TITRE_COL[6]="";
 P_TRICOL[7]=0;   P_ATTR[7]=' ';  P_FONT[7]="Arial"; P_HAUT[7]= haut;
   P_ITAL[7]='N'; P_BOLD[7]='N'; P_EPAISSV[7]=2; P_TITRE_COL[7]="";
 // faire terminer par zero
 P_COL=6;

 // calculer date debut, date de fin  -> Echelle horizontale


 P_DECAL = 15;  // Decalage calendrier

 P_MODE='P';  // Planning
 STYLE = 'L';
 Prepare_Graphic();


}

void __fastcall TplStandard::Prepare_Graphic()

{
 TRect R;
 //
 Clean_Grid(asT,2);
 X0=0;Y0=0;

 if (STYLE == 'L') Printer()->Orientation = poLandscape;
 else Printer()->Orientation = poPortrait;

 P_H = Printer()->PageHeight;
 P_W = Printer()->PageWidth;

 if(P_MODE == 'P')  // Planning
  {
    if (imP) delete imP;
    imP = new Graphics::TBitmap();
    imP->PixelFormat =pf8bit;
    imP->Height= P_H;
    imP->Width=  P_W;
    R = Rect(0,0, imP->Width,imP->Height);
    imP->Canvas->Brush->Color = clWhite; // BgColor;
    imP->Canvas->FillRect(R);
   }
  else
   {
    if (imR) delete imR;
    imR = new Graphics::TBitmap();
    imR->PixelFormat =pf8bit;
    imR->Height= P_H;
    imR->Width=  P_W;
    R = Rect(0,0, imR->Width,imR->Height);
    imR->Canvas->Brush->Color = clWhite; // BgColor;
    imR->Canvas->FillRect(R);
   }


 G_PrepareHV();   // determine MAXDIST et TAILLE HORIZONTALE des Taches





 G_Cadre();   //  P_MARGH et V, et EPaisseur et Couleur
 G_Titre();
 G_Colonnes();        // calculer la taille des colonnes
 G_Calendrier();
 G_Detail();


 if (P_MODE=='P')
  { Draw_Planning(imP);
   imPp->Picture->Assign(imP);
   imPl->Picture->Assign(imP);
  }
 else
  { Draw_Planning(imR);
    imRp->Picture->Assign(imR);
    imPl->Picture->Assign(imR);
  }

}


int __fastcall TplStandard::RechercheCol(char *str)
{
 int col,i;
 col=0;
 for (i=0;i<CNT_CHAMPS;i++)
   {
    if (strcmp(libchamp[i],str)==0)
     { col = atoi(cln[i]);
       strcpy(CONTROL,cnt[i]);
       break; }
   }
 return col;
}


void __fastcall TplStandard::Draw_Planning(Graphics::TBitmap *B)
{
 TRect R; int cnt,i; char Cod[20];
 TColor c; char tmp[250]; int a;
 int x1,y1,x2,y2;
 TFont *F;
 TRect Dst,Src;

 F = new TFont;
 // Clear Graphics area


 cnt=asT->RowCount;
 if (cnt==2) return;

 for (i=1;i<cnt;i++)
   {
    strcpy(Cod,asT->Cells[0][i].c_str());
    if (strcmp(Cod,"LH")==0)
      {
       strcpy(tmp,asT->Cells[6][i].c_str()); a= atoi(tmp);
       c=TColor(a);
       B->Canvas->Brush->Color = c;
       strcpy(tmp,asT->Cells[7][i].c_str()); a= atoi(tmp);
       c=TColor(a);
       B->Canvas->Pen->Color = c;
       strcpy(tmp,asT->Cells[8][i].c_str()); a= atoi(tmp);
       B->Canvas->Pen->Width = a;
       strcpy(tmp,asT->Cells[1][i].c_str()); x1= atoi(tmp);
       strcpy(tmp,asT->Cells[2][i].c_str()); y1= atoi(tmp);
       strcpy(tmp,asT->Cells[3][i].c_str()); x2= atoi(tmp);
       strcpy(tmp,asT->Cells[4][i].c_str()); y2=atoi(tmp);
       B->Canvas->MoveTo(x1,y1);
       B->Canvas->LineTo(x2,y1);

      }
    if (strcmp(Cod,"LV")==0)
      {
       strcpy(tmp,asT->Cells[6][i].c_str()); a= atoi(tmp);
       c=TColor(a);
       B->Canvas->Brush->Color = c;
       strcpy(tmp,asT->Cells[7][i].c_str()); a= atoi(tmp);
       c=TColor(a);
       B->Canvas->Pen->Color = c;
       strcpy(tmp,asT->Cells[8][i].c_str()); a= atoi(tmp);
       B->Canvas->Pen->Width = a;

       strcpy(tmp,asT->Cells[10][i].c_str()); a= atoi(tmp);
       if (strcmp(tmp,"D")==0)
           {B->Canvas->Brush->Color = clWhite;
            B->Canvas->Pen->Style = psDot;
           }
       else
           B->Canvas->Pen->Style = psSolid;
       strcpy(tmp,asT->Cells[1][i].c_str()); x1= atoi(tmp);
       strcpy(tmp,asT->Cells[2][i].c_str()); y1= atoi(tmp);
       strcpy(tmp,asT->Cells[3][i].c_str()); x2= atoi(tmp);
       strcpy(tmp,asT->Cells[4][i].c_str()); y2=atoi(tmp);
       B->Canvas->MoveTo(x1,y1);
       B->Canvas->LineTo(x1,y2);
      }

    else if (strcmp(Cod,"TX")==0)
      {
       strcpy(tmp,asT->Cells[6][i].c_str()); a= atoi(tmp);
       c=TColor(a);
       B->Canvas->Brush->Color = c;
       strcpy(tmp,asT->Cells[7][i].c_str()); a= atoi(tmp);
       c=TColor(a); F->Color=c;
       F->Name = asT->Cells[9][i];
       strcpy(tmp,asT->Cells[8][i].c_str()); a= atoi(tmp);
       F->Size = a;
       F->Style = TFontStyles();
       strcpy(tmp,asT->Cells[10][i].c_str()); a= atoi(tmp);
       if (strcmp(tmp,"I")==0) F->Style = F->Style << fsItalic;
       strcpy(tmp,asT->Cells[11][i].c_str()); a= atoi(tmp);
       if (strcmp(tmp,"B")==0) F->Style = F->Style << fsBold;

       B->Canvas->Font = F;
       strcpy(tmp,asT->Cells[1][i].c_str()); x1= atoi(tmp);
       strcpy(tmp,asT->Cells[2][i].c_str()); y1= atoi(tmp);
       B->Canvas->TextOut(x1,y1,asT->Cells[12][i]);
      }
   else if (strcmp(Cod,"RT")==0)   // rectangle couleur
      {

       strcpy(tmp,asT->Cells[1][i].c_str()); x1= atoi(tmp);
       strcpy(tmp,asT->Cells[2][i].c_str()); y1= atoi(tmp);
       strcpy(tmp,asT->Cells[3][i].c_str()); x2= atoi(tmp);
       strcpy(tmp,asT->Cells[4][i].c_str()); y2=atoi(tmp);
       strcpy(tmp,asT->Cells[6][i].c_str()); a= atoi(tmp);
       c=TColor(a);
//       sprintf(tmp,"x1=%d y1=%d x2=%d y2=%d col=%d ",x1,y1,x2,y2,c);
//       Application->MessageBoxA(tmp,"RH",MB_OK);
       R = Rect(x1,y1,x2,y2);
       B->Canvas->Brush->Color = c;
       B->Canvas->FillRect(R);
      }
   else if (strcmp(Cod,"CR")==0)   // copie rect
      {
       strcpy(tmp,asT->Cells[1][i].c_str()); x1= atoi(tmp);
       strcpy(tmp,asT->Cells[2][i].c_str()); y1= atoi(tmp);
       strcpy(tmp,asT->Cells[3][i].c_str()); x2= atoi(tmp);
       strcpy(tmp,asT->Cells[4][i].c_str()); y2=atoi(tmp); 
       Src = Rect(x1,memy1,x2,memy2);
       Dst = Rect(x1,y1,x2,y2);
       B->Canvas->CopyRect(Dst,B->Canvas,Src);


      }

   } // boucle for
}


void __fastcall TplStandard::G_Colonnes()
{
 // chercher les crit en colonnes (pas en ligne) et
 // calculer la taille maxi du texte

 // raz des coordonnées de colonnes

 int i,j,cnt;
 AnsiString txt;

 cnt = asTri->RowCount;
 int x1,y1,x2,y2;

 i=0;  P_LC[0]=P_MARGH1+P_ELC;  // epaisseurs du cadre
 P_MAXSIZE[0]=0; P_EPAISSV[0]=0;
 while ((P_TRICOL[i]) &&(i<20))
   {
    P_MAXSIZE[i]=0;
    if (P_ATTR[i]=='C')
      {
       for (j=1;j<cnt;j++)
         { txt = asTri->Cells[P_TRICOL[i]][j];    // $$$$$
          Compute_LH(P_FONT[i],txt,P_HAUT[i],P_ITAL[i],P_BOLD[i]);
          L=L+30;      //  % pour espacement
          if (L>P_MAXSIZE[i]) P_MAXSIZE[i]=L;
         }
       if (i>0)
         { P_LC[i]=P_LC[i-1] + P_MAXSIZE[i-1] + P_EPAISSV[i-1]; //  + des epaisseurs
           P_LENGTH[i]= P_MAXSIZE[i];
          // tracé des colonnes
          if (i>1)
           {

            x1= P_LC[i]; y1=Y0; x2=x1+2; y2=P_H-P_MARGV2 -P_ELC;
            Insert_G("LV",x1,y1,x2,y2,"",TColor(0),TColor(0),2,"",'X','X',"");

            if (P_TRICOL[i-1]<20)
             {
              // et remplir la couleur du precedent ...
            // y1 et Y2 les memes
            x2=x1-1; x2=P_LC[i-1];

             Insert_G("RT",x1,y1,x2,y2,"DT",TColor(0xffff99),TColor(0xffff99),0,"",' ',' ',"");
             }
           }
         }

      }
    i++;
   }
 P_LC[i]=P_LC[i-1] + P_MAXSIZE[i-1] + P_EPAISSV[i-1];
 x1= P_LC[i]; y1=Y0; x2=x1+2; y2=P_H-P_MARGV2;
 Insert_G("LV",x1,y1,x2,y2,"",TColor(0),TColor(0),2,"",'X','X',"");

 P_DEBUTGANTT=  P_LC[i]+P_MAXSIZE[i]+P_ELC; //+ P_MARGH1+ 5;  //epaisseurs
}


void __fastcall TplStandard::G_Calendrier()
{
 int col,numchamp; AnsiString txt; char tmp[250];
 int first; int x1,y1,x2,y2;  bool flprem;
 int firstday,ix,base,increm_CAL1,increm_CAL2;
 TDateTime dtFirst;
 AnsiString mo[13];

 mo[1]="Jan";  mo[2]="Fev"; mo[3]="Mar";  mo[4]="Avr"; mo[5]="Mai";  mo[6]="Jui";
 mo[7]="Jui";  mo[8]="Aou"; mo[9]="Sep";  mo[10]="Oct"; mo[11]="Nov";  mo[12]="Dec";

 H_CAL1=30; H_CAL2=30; H_COPYRIGHT=40;
 first = 1;
 for (col=0;col<P_COL;col++)
     {
      numchamp = P_TRICOL[col];
      if (numchamp >= 20)
        {
         if (first)
           {
            x1=P_LC[col-1];x2=P_LC[col]; y1=Y0; y2=y1+H_CAL1+H_CAL2+1;
            Insert_G("RT",x1,y1,x2,y2,"DT",TColor(0xffffff),TColor(0xffffff),0,"",' ',' ',"");
            x1=P_LC[col]; x2=P_W - P_MARGH2;
            y1=Y0; y2=y1;
            Insert_G("LH",x1,y1,x2,y2,"DT",TColor(0),TColor(0),1,"",'N','N',"");
            y1=Y0+H_CAL1+H_CAL2; y2=y1;
            Insert_G("LH",x1,y1,x2,y2,"DT",TColor(0),TColor(0),1,"",'N','N',"");
            first=0;
           }
         // calcul des cadrages
         txt = P_TITRE_COL[col];
         Compute_LH(P_FONT[col],txt,P_HAUT[col],P_ITAL[col],P_BOLD[col]);
         x1 = P_LC[col]+ (P_LC[col+1]-P_LC[col])/2-L/2;
         x2=x1+L;
         y1=Y0+(H_CAL1+H_CAL2-H)/2;
         y2=y1+P_HAUT[col];
         Insert_G("TX",x1,y1,x2,y2,"DT",TColor(0xffffff),TColor(0),P_HAUT[col],P_FONT[col],'N','N',txt);
        }
     }

 // Tracé de la ligne separatrice des calendriers et remplissage couleurs
  x1=P_DEBUTGANTT-2; x2=P_W - P_MARGH2-P_ELC;
  y1=Y0+1; y2=y1+H_CAL1;
  Insert_G("RT",x1,y1,x2,y2,"DT",PB[9],PB[9],0,"",' ',' ',"");

  y1=Y0+H_CAL1; y2=y1+1;
  Insert_G("LH",x1,y1,x2,y2,"DT",TColor(0),TColor(0),1,"",'N','N',"");

  y1=y2+1; y2=y1+H_CAL2;
  Insert_G("RT",x1,y1,x2,y2,"DT",PB[10],PB[10],0,"",' ',' ',"");

 //  Remplissage calendrier   et tracé des lignes verticales

 base = P_W - P_MARGV2 - P_DEBUTGANTT - P_LASTTEXT - 30;  // 100  marge pour texte
 increm_CAL1= 7*base/P_MAXDIST-1;   // ou 14  ou plus
 increm_CAL2 = 30*base/P_MAXDIST - 1;

 // cas du premier mois
 flprem= false;
 if (JourPrev >1)  flprem=true;



 for (ix=0;ix<=P_MAXDIST;ix++)
  {
   add_jour(AnPrev,MoisPrev,JourPrev,ix);
   dtFirst=EncodeDate(An,Mois,Jour);
   firstday = dtFirst.DayOfWeek();
   if (firstday==2) // lundi
     {
      x1 = P_DEBUTGANTT + base*ix/P_MAXDIST;
      x2 = x1+1;
      y1 = Y0; y2=y1+H_CAL1;
      Insert_G("LV",x1,y1,x2,y2,"DT",TColor(0),TColor(0),1,"",'N','N',"");

      y1 = Y0+H_CAL1+H_CAL2+2; y2=P_H - P_MARGV2;
      Insert_G("LV",x1,y1,x2,y2,"DT",TColor(0),TColor(0),1,"",'D','N',"");


      x1 = x1+2;  // decalage pour ecrire la date
      sprintf(tmp,"%d/%d",Jour,Mois);
      txt=AnsiString(tmp);
      Compute_LH(PF[9],tmp,PH[9],PN[9],PX[9]);
      x2=x1+L;
      y1=Y0+1+(H_CAL1-H)/2;
      y2=y1+PH[9];
      Insert_G("TX",x1,y1,x2,y2,"DT",PB[9],PC[9],PH[9],PF[9],PN[9],PX[9],txt);

     }
   if ((Jour==1) || flprem)  // ligne verticale pleine
     {
      x1 = P_DEBUTGANTT + base*(ix-1)/P_MAXDIST;
      x2 = x1+1;
      y1 = Y0+H_CAL1+1; y2=y1+H_CAL2;
      Insert_G("LV",x1,y1,x2,y2,"DT",TColor(0),TColor(0),1,"",'N','N',"");
      y1 = Y0+H_CAL1+H_CAL2+1; y2=P_H - P_MARGV2;
       if (!flprem)
      Insert_G("LV",x1,y1,x2,y2,"DT",TColor(0),TColor(0),1,"",'N','N',"");

      sprintf(tmp,"%02d",An%100);
      txt=mo[Mois]+ " "+ AnsiString(tmp);

      Compute_LH(PF[10],tmp,PH[10],PN[10],PX[10]);
      x1=x1+ (increm_CAL2 - L)/2;
      x2=x1+L;
      y1=Y0+1+ H_CAL1 + (H_CAL2-H)/2;
      y2=y1+PH[9];
      Insert_G("TX",x1,y1,x2,y2,"DT",PB[10],PC[10],PH[10],PF[10],PN[10],PX[10],txt);
      flprem=false;
     }

  }
 memy1=Y0;   memy2= Y0+H_CAL1+H_CAL2;   // memorise y1 / y2   pour copie rectangle calendrier
 Y0=Y0+H_CAL1+H_CAL2+4;
}



void __fastcall TplStandard::G_Detail()
{
 AnsiString txt,C,Cr[8]; // criteres
 bool f[8];
 TRect Src,Dst;

 int i,crit;
 //bool debut;
 int nb_l;
 int x1,y1,x2,y2; int col,numchamp;


 for (i=0;i<8;i++) { f[i]=true; Cr[i]=""; }
 // cnt= asTri->RowCount;
 //debut = true;
  nb_l = NB_DETAIL + P_RUPT0;
  if (nb_l == 0) return;
  P_H_TACHE = P_H - P_MARGV2 - P_ELC - Y0 - 2*H_CAL1 - 2*H_CAL2 - H_COPYRIGHT;  //130;   // 30 reservé pour copyright + 100 Calendrier
  P_H_TACHE = P_H_TACHE /nb_l;

  P_LST=2;

  for (i=1;i<=NB_DETAIL;i++)
   {
    for (crit=1; crit<=8;crit++)
     {
      if (PACTIF[crit+10])
       { C=asTri->Cells[crit+1][i];
        if (C != Cr[crit])
         { if (!f[crit])
            {
             f[crit] = false;
             Finir(crit+10,asTri->Cells[crit+10][i]);
            }
           Commencer(crit+10,asTri->Cells[crit+10][i]);
         }

       // Y0 = Y0+P_H_TACHE;
       Cr[crit]=C;
      } // if PACTIF
     }

    // Tracé des colonnes
    // Y0 est toujours la base
    for (col=0;col<P_COL;col++)
     {
      numchamp = P_TRICOL[col];
      if (numchamp >= 20)
        {
         txt = asTri->Cells[numchamp][i];
         Compute_LH(P_FONT[col],txt,P_HAUT[col],P_ITAL[col],P_BOLD[col]);

         x1 = P_LC[col] + (P_LC[col+1]-P_LC[col])/2 - L/2;
         x2 = x1+P_LENGTH[col];

         y1=Y0+ (P_H_TACHE - P_HAUT[col]-2)/2;  // -2 pour epaisseur des traits
         y2=Y0+P_HAUT[col];
         Insert_G("TX",x1,y1,x2,y2,"DT",TColor(0xffffff),TColor(0),P_HAUT[col],P_FONT[col],'N','N',txt);
         x1=P_LC[col]; x2=P_LC[col+1];
         y1=Y0+P_H_TACHE; y2=y1+1;
         Insert_G("LH",x1,y1,x2,y2,"DT",TColor(0),TColor(0),1,"",'N','N',"");
        }
     }

    // calcul de x1 et x2
    char dt1[15];
    int j1,m1,a1,dist1,dist2,base;
    strcpy(dt1,asTri->Cells[28][i].c_str());  // date debut reelle
    dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[8]=0; a1=atoi(dt1+6);
    dist1 = convert_date(a1+2000,m1,j1);
    strcpy(dt1,asTri->Cells[29][i].c_str());  // date fin reelle
    dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[8]=0; a1=atoi(dt1+6);
    dist2 = convert_date(a1+2000,m1,j1) + 1;
    base = P_W - P_MARGV2 - P_DEBUTGANTT - P_LASTTEXT - 30;  // 100  marge pour texte
    x1 = P_DEBUTGANTT + base*dist1/P_MAXDIST;
    x2 = x1+200;   // taille du texte
    Y0=Y0+2;
    y1=Y0+2; y2=y1+P_H_TACHE/2;
    int hauteur = PH[21];
    Insert_G("TX",x1,y1,x2,y2,"DT",TColor(0xffffff),TColor(0),hauteur,"Arial",'N','N',asTri->Cells[21][i]);

    // Graphique a tracer  GANTT
    y1=y1+2*P_H_TACHE/3+2;  y2=y2+P_H_TACHE/2;
    x2 = P_DEBUTGANTT + base*dist2/P_MAXDIST;
    int margt= StrToInt(asTri->Cells[32][i]);
    if (margt==0) Insert_G("LH",x1,y1,x2,y2,"DT",clWhite,clRed,5,"",'N','N',"XXX");
     else Insert_G("LH",x1,y1,x2,y2,"DT",clWhite,clBlue,5,"",'N','N',"XXX");

    Y0 = Y0+P_H_TACHE;
   }
//  Fin du tracé  : Cleaner le bas, inserer un deuxieme calendrier

x1=P_MARGH1+P_ELC;  x2=P_W - P_MARGH2 - P_ELC;
y1=Y0; y2= P_H - P_MARGV2-P_ELC;
Insert_G("RT",x1,y1,x2,y2,"DT",clWhite,clWhite,0,"",' ',' ',"");
y2=y1+1;
Insert_G("LH",x1,y1,x2,y2,"DT",clBlack,clBlack,1,"",' ',' ',"");   // ligne noire
Y0++;
x1=P_DEBUTGANTT;  // x2 reste le meme
y1=Y0; y2=y1+H_CAL1 + H_CAL2;
// copy rectangle, meme X1,X2  et memy1 , memy2 pour les Y sources
Insert_G("CR",x1,y1,x2,y2,"",clBlack,clBlack,0,"",' ',' ',"");
}

void __fastcall TplStandard::G_Cadre()
{
 int x1,x2,y1,y2;
 int ax1,ax2,ay1,ay2;
 // sauter marge
 X0=X0+P_MARGH1; Y0=Y0+P_MARGV1;
 x1=X0;y1=Y0; x2=P_W - P_MARGH2; y2=y1+P_ELC; ay2=P_H - P_MARGV2;
 Insert_G("LH",x1,y1,x2,y2,"",TColor(0),TColor(0),P_ELC,"",' ',' ',"");

 ay2=P_H - P_MARGV2;
 Insert_G("LV",x1,y1,x1,ay2,"",TColor(0),TColor(0),P_ELC,"",'X','X',"");

 Insert_G("LH",x1,ay2,x2,ay2,"",TColor(0),TColor(0),P_ELC,"",'X','X',"");
 Insert_G("LV",x2,ay2,x2,y1,"",TColor(0),TColor(0),P_ELC,"",'X','X',"");

 X0=X0+P_ELC;
}

void __fastcall TplStandard::G_Titre()
{
 int x1,y1,x2,y2,l,h,n,maxh;
 // Lign1  : G1 T1 et D1
 Y0=Y0+5; maxh = 60;

 n=0;
 Compute_LH(PF[n],PT[n],PH[n],PN[n],PX[n]);
 x1=X0+PR[n]; x2=x1+L; y1=Y0;y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"G1",PB[n],PC[n],PH[n],PF[n],PN[n],PX[n],PT[n]);
 n=3;
 Compute_LH(PF[n],PT[n],PH[n],PN[n],PX[n]);
 x1=P_W/2 -L/2;
 x2=x1+L; y1=Y0;y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"G1",PB[n],PC[n],PH[n],PF[n],PN[n],PX[n],PT[n]);
 n=6;
 Compute_LH(PF[n],PT[n],PH[n],PN[n],PX[n]);
 x1=P_W - P_MARGH2 - L -10;
 x2=x1+L; y1=Y0;y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"G1",PB[n],PC[n],PH[n],PF[n],PN[n],PX[n],PT[n]);
 Y0=Y0 + maxh;
 n=1;
 Compute_LH(PF[n],PT[n],PH[n],PN[n],PX[n]);
 x1=X0+PR[n]; x2=x1+L; y1=Y0;y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"G1",PB[n],PC[n],PH[n],PF[n],PN[n],PX[n],PT[n]);
 n=5;
 Compute_LH(PF[n],PT[n],PH[n],PN[n],PX[n]);
 x1=P_W/2 -L/2;
 x2=x1+L; y1=Y0;y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"G1",PB[n],PC[n],PH[n],PF[n],PN[n],PX[n],PT[n]);
 n=7;
 Compute_LH(PF[n],PT[n],PH[n],PN[n],PX[n]);
 x1=P_W - P_MARGH2 - L -10;
 x2=x1+L; y1=Y0;y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"G1",PB[n],PC[n],PH[n],PF[n],PN[n],PX[n],PT[n]);

 Y0=Y0+maxh;
 n=2;
 Compute_LH(PF[n],PT[n],PH[n],PN[n],PX[n]);
 x1=X0+PR[n]; x2=x1+L; y1=Y0;y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"G1",PB[n],PC[n],PH[n],PF[n],PN[n],PX[n],PT[n]);

 n=8;
 Compute_LH(PF[n],PT[n],PH[n],PN[n],PX[n]);
 x1=P_W - P_MARGH2 - L -10;
 x2=x1+L; y1=Y0;y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"G1",PB[n],PC[n],PH[n],PF[n],PN[n],PX[n],PT[n]);

 Y0=Y0+maxh;
}


void __fastcall TplStandard::G_PrepareHV()
{
 int cnt,i,mem;
 char dt1[15];
 int j1,m1,a1,dist;

 mem=0;
 cnt = asTri->RowCount;  P_MAXDIST=0;
 for (i=1;i<cnt;i++)
  {
   strcpy(dt1,asTri->Cells[29][i].c_str());  // date fin reelle
   dt1[2]=0; j1=atoi(dt1);  dt1[5]=0; m1=atoi(dt1+3);  dt1[8]=0; a1=atoi(dt1+6);
   dist = convert_date(a1+2000,m1,j1);
   if (dist>P_MAXDIST) { P_MAXDIST=dist; mem=i; }
  }
  AnsiString font; int ht;
  font = PF[21]; ht=PH[21];

 Compute_LH(font,asTri->Cells[21][mem],ht,'N','N');
 P_LASTTEXT = L;
 // %%%%%
}


void __fastcall TplStandard::Compute_LH(AnsiString FName, AnsiString txt,int h,char ital,char bold)
{
 TFont *F;
 F = new TFont;
 F->Name =FName;
 F->Size= h;
 F->Style = TFontStyles();
 if(ital=='I') F->Style = F->Style << fsItalic;
 if (bold=='B')F->Style = F->Style << fsBold;

 iTest->Canvas->Font = F;

 iTest->Canvas->Font->Name = FName;
 iTest->Canvas->Font->Size = h;
 H = iTest->Canvas->TextHeight(txt);
 L = iTest->Canvas->TextWidth(txt);
}


void __fastcall TplStandard::Commencer(int rupt,AnsiString txt)
{
 //  si attr 'V' Vertical ==> dessiner Ligne Horizontale

 if (PACTIF[rupt])  //
   {
     Faire_LSH(rupt);  // Critere en ligne
     Draw_Rupture(rupt,txt);
     Faire_LSB(rupt);
   }
}

void __fastcall TplStandard::Finir(int rupt,AnsiString txt)
{
 //int a;
 //a=0;

}

void __fastcall TplStandard::Faire_LSH(int rupt)
{
  int x1,y1,x2,y2;
  if (LSH[rupt])   // On traite ligne  LSH  Ligne Horizontale Haute
   {
    X0=P_MARGH1+P_ELC;  // $$$$$ 10 = epaisseur du cadre
    x1=X0; x2=P_W - P_MARGH2;
    y1=Y0; y2= y1+LSH_EPAISSEUR[rupt];
    Insert_G("LH",x1,y1,x2,y2,"",TColor(0),TColor(0),LSH_EPAISSEUR[rupt],"",' ',' ',"");
    //Insert_G("RT",x1,y1,x2,y2,"",PC[rupt],PB[rupt],0,"",' ',' ',"");
   }
}


void __fastcall TplStandard::Faire_LSB(int rupt)
{
  int x1,y1,x2,y2;
  if (LSB[rupt])   // On traite ligne  LSH  Ligne Horizontale Haute
   {
    X0=P_MARGH1+P_ELC;  // 20 = epaisseur du cadre
    x1=X0; x2=P_W - P_MARGH2;
    y1=Y0; y2= y1+LSB_EPAISSEUR[rupt];
    Insert_G("LH",x1,y1,x2,y2,"",TColor(0),TColor(0),LSB_EPAISSEUR[rupt],"",' ',' ',"");
   }
}

void __fastcall TplStandard::Draw_Rupture(int rupt, AnsiString txt)
{
 int x1,y1,x2,y2;
  TFont *F;
 F = new TFont;
 F->Name = PF[rupt];
 F->Size= PH[rupt];
 F->Style = TFontStyles();
 if(PN[rupt]=='I') F->Style = F->Style << fsItalic;
 if (PX[rupt]=='B')F->Style = F->Style << fsBold;

 if (P_ORIENT[rupt])
    { x1=P_MARGH1+P_ELC; y1=Y0; x2= P_W - P_MARGH2-P_ELC; y2=y1+P_H_TACHE;
     Insert_G("RT",x1,y1,x2,y2,"DT",TColor(0x99ffff),TColor(0x99ffff),0,"",' ',' ',txt);
    }

 Compute_LH(F->Name,PT[rupt],PH[rupt],PN[rupt],PX[rupt]);

 x1= P_MARGH1 + PR[rupt] + 10;
 x2= x1 + L;
 y1 = Y0+2; y2=y1+H;
 Insert_G("TX",x1,y1,x2,y2,"DT",PC[rupt],PB[rupt],PH[rupt],PF[rupt],PN[rupt],PX[rupt],txt);

 if (P_ORIENT[rupt]) Y0=Y0+P_H_TACHE;
}

void __fastcall TplStandard::imPpMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
TRect Dst,Src;
int imx; int imy;
int ext;

if (!imP) return;

imx=imP->Width;
imy=imP->Height;

///   imPort is assigned to Image im !!!!!

ext = (11-ZoomP->Position)*100;
rx1= (imx * X / imPp->Width) -ext;
if (rx1 <0) rx1=0;
rx2 = rx1+2*ext;
if (rx2 > imP->Width) {rx2=imP->Width; rx1=rx2-2*ext; }

ry1= (imy * Y / imPp->Height) - ext;
if (ry1 <0) ry1=0;
ry2 = ry1+2*ext;
if (ry2 > imP->Height) {ry2=imP->Height; ry1=ry2-2*ext; }


Dst = Rect(0,0,imPScreen->Width,imPScreen->Height);
Src = Rect(rx1,ry1,rx2,ry2);

imPScreen->Canvas->CopyRect(Dst,imPp->Canvas,Src);

Origin_Image=imPp;

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::imPlMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
TRect Dst,Src;
int imx; int imy;

if (!imP) return;

imx=imP->Width;
imy=imP->Height;
int ext;

///   imLand is assigned to Image im !!!!!

ext = (11-ZoomP->Position)*100;
rx1= (imx * X / imPl->Width) -ext;
if (rx1 <0) rx1=0;
rx2 = rx1+2*ext;
if (rx2 > imP->Width) {rx2=imP->Width; rx1=rx2-2*ext; }

ry1= (imy * Y / imPl->Height) - ext;
if (ry1 <0) ry1=0;
ry2 = ry1+2*ext;
if (ry2 > imP->Height) {ry2=imP->Height; ry1=ry2-2*ext; }

Dst = Rect(0,0,imPScreen->Width,imPScreen->Height);
Src = Rect(rx1,ry1,rx2,ry2);

 imPScreen->Canvas->CopyRect(Dst,imPl->Canvas,Src);
 Origin_Image=imPl;

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::Insert_G(char *typ,int x1,int y1,int x2,int y2,
        char *ref, TColor bg, TColor fg, int epais, AnsiString font, char ital,
        char bold, AnsiString text)
{
 int r;

 asT->RowCount++;
 r=asT->RowCount-1;
 asT->Cells[0][r] = typ;
 asT->Cells[1][r] = x1;
 asT->Cells[2][r] = y1;
 asT->Cells[3][r] = x2;
 asT->Cells[4][r] = y2;
 asT->Cells[5][r] = ref;
 asT->Cells[6][r] = (int)bg;
 asT->Cells[7][r] = (int)fg;
 asT->Cells[8][r] = epais;
 asT->Cells[9][r] = font;      // ou style trait pour LH ou LV
 asT->Cells[10][r] = ital;
 asT->Cells[11][r] = bold;
 asT->Cells[12][r] = text;
}



void __fastcall TplStandard::Compute_Ruptures()
{
 AnsiString Code;
 int i,cnt;
 P_RUPT0=P_RUPT1=P_RUPT2=P_RUPT3=0;
 cnt=asTri->RowCount;

 Code = "";
 for (i=1;i<cnt;i++)
   {
    if (asTri->Cells[2][i] != Code){P_RUPT0++; Code = asTri->Cells[2][i]; }
   }
 Code = "";
 for (i=1;i<cnt;i++)
   {
    if (asTri->Cells[3][i] != Code){P_RUPT1++; Code = asTri->Cells[3][i]; }
   }
 Code = "";
 for (i=1;i<cnt;i++)
   {
    if (asTri->Cells[4][i] != Code){P_RUPT2++; Code = asTri->Cells[4][i]; }
   }
 Code = "";
 for (i=1;i<cnt;i++)
   {
    if (asTri->Cells[5][i] != Code){P_RUPT3++; Code = asTri->Cells[5][i]; }
   }

 if (P_RUPT1 !=0) P_RUPT1 -= P_RUPT0;
 if (P_RUPT2 !=0) P_RUPT2 -= P_RUPT1;
 if (P_RUPT3 !=0) P_RUPT3 -= P_RUPT2;

 i=0;
}

void __fastcall TplStandard::btGraphPlClick(TObject *Sender)
{
Planning_Defaut();

int ext,rx1,rx2,ry1,ry2;
TRect Dst,Src;
ext = (11-ZoomP->Position)*100;
rx1= 0;
if (rx1 <0) rx1=0;
rx2 = rx1+2*ext;
if (rx2 > imP->Width) {rx2=imP->Width; rx1=rx2-2*ext; }

ry1= 0;
if (ry1 <0) ry1=0;
ry2 = ry1+2*ext;
if (ry2 > imP->Height) {ry2=imP->Height; ry1=ry2-2*ext; }

Dst = Rect(0,0,imPScreen->Width,imPScreen->Height);
Src = Rect(rx1,ry1,rx2,ry2);
imPScreen->Canvas->CopyRect(Dst,imPl->Canvas,Src);

}
//---------------------------------------------------------------------------


void __fastcall TplStandard::btPrPClick(TObject *Sender)
{
 Planning_Defaut();
 Print_Image(imPl);  // Port);
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::imPScreenContextPopup(TObject *Sender,
      TPoint &MousePos, bool &Handled)
{
 int x,y;
 x=MousePos.x;
 y=MousePos.y;
 if (Origin_Image==imPl)
   {
    PopPlann1->Popup(x, y);

   }
 else if (Origin_Image==imPp)
   {
    PopPlann1->Popup(x, y);

   }
}
//---------------------------------------------------------------------------

