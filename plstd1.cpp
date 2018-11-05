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

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
//#pragma link "AdvGridWorkbook"
//#pragma link "AsgMemo"
//#pragma link "AdvGrid"
//#pragma link "BaseGrid"
#pragma resource "*.dfm"
TplStandard *plStandard;
//---------------------------------------------------------------------------
__fastcall TplStandard::TplStandard(TComponent* Owner)
        : TForm(Owner)
{
  //Label5->Caption = DateToStr(Date());

}
//---------------------------------------------------------------------------
void __fastcall TplStandard::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 int rc;

 //  forces change
 change=1;
 if (change)  updatedatabase(LocalBase);
 if (proj) { rc = proj->CloseEngine(); proj->~genbase(); }

 // on signale a MainForm qu'on ferme
 strcpy(status,"<close>"); strcat(status,DatabaseName);
 strcat(status,"</close>");
 
 Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::updatedatabase(char *name)
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


 if (Application->MessageBox("Voulez vous sauvegarder les modifications du projet",
 LocalBase,MB_YESNO)==IDYES)
   {
    // le dbcode ne doit pas changer  'pb du nom de repertoire'
    // lire le nom de code
    rc = proj->ReadDirectKey(0,"<dbcode>",RetKey,&recdata);
    if (rc)  // ok : clé trouvée
       {
         rc = proj->ReadRecord(buffer,recdata);
         buffer[rc]=0;
         strcpy(dbcode,buffer);
       }
    rc = proj->CloseEngine(); proj->~genbase();

    strcpy(buffer,LocalBase); strcat(buffer,".dat");
    unlink(buffer);
    strcpy(buffer,LocalBase); strcat(buffer,".eco");
    unlink(buffer);
    proj = new genbase;
    rc = proj->OpenEngine(LocalBase,120,"eco","dat");   //512 - 8
    rc = proj->SetIndexMode(0,0);
    if (rc==0) { ShowMessage("Erreur à l'ouverture des fichiers projets"); exit (1); }

    // code de la base
     strcpy(Key,"<dbcode>"); recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     rc = proj->WriteRecord(dbcode,strlen(dbcode)+1);

    // titre de la base
     strcpy(Key,"<dbtitre>"); recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     rc = proj->WriteRecord(dbtitre,strlen(dbtitre)+1);

    // avancements
    strcpy(Key,"<avanc>"); recdata=proj->GetNewRecordNumber();
     rc = proj->WriteKey(0,Key,recdata);
     rc = proj->WriteRecord(dateavanc,strlen(dateavanc)+1);

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
       sprintf(Key,"<T%04d>",ii);
       recdata=proj->GetNewRecordNumber();
       rc = proj->WriteKey(0,Key,recdata);

       strcpy(buffer,AdvStringGrid1->Cells[2][i].c_str());

       strcpy(format,"<T>%d</T><nom>%s</nom><duree>%d</duree><cal>%d</cal><mom>%d</mom>");
       strcat(format,"<ct>%s</ct><da>%s</da><dtr>%s</dtr><ftr>%s<ftr><pc>%d</pc><nbj>%d</nbj>");

       sprintf(tmp,format,
              ii,buffer,duree[i],tcal[i],tmom[i],codetache[i],da[i],dtr[i],ftr[i],pc[i],nbj[i]);
       rc = proj->WriteRecord(tmp,strlen(tmp)+1);

       //  predecesseurs,
       sprintf(Key,"<PR%04d>",ii);
       recdata=proj->GetNewRecordNumber();
       rc = proj->WriteKey(0,Key,recdata);
       ipred=1;
       buffer[0]=0; sprintf(buffer,"<PR%04d>",ii);
       while ((pr[i][ipred]!=0) && (ipred<PS))
         {
          // if (pr[i][ipred] != 9999)
          // {
            sprintf(tmp,"<P%02d><num>%d</num><typ>%d</typ><decal>%d</decal></P%02d>",
               ipred,pr[i][ipred],pr_tl[i][ipred],pr_decal[i][ipred],ipred);
            strcat(buffer,tmp);
           // }
          ipred++;
         }
       sprintf(tmp,"</PR%04d>",ii); strcat(buffer,tmp);
       rc = proj->WriteRecord(buffer,strlen(buffer)+1);
    //  successeurs
       sprintf(Key,"<SU%04d>",ii);
       recdata=proj->GetNewRecordNumber();
       rc = proj->WriteKey(0,Key,recdata);
       isucc=1;
       buffer[0]=0; sprintf(buffer,"<SU%04d>",ii);
       while ((su[i][isucc]!=0)  && (isucc<PS))
         {
          //if (su[i][isucc] != 9999)
          // {
             sprintf(tmp,"<S%02d><num>%d</num><typ>%d</typ><decal>%d</decal></S%02d>",
               isucc,su[i][isucc],su_tl[i][isucc],su_decal[i][isucc],isucc);
            strcat(buffer,tmp);
           // }
          isucc++;
         }
       sprintf(tmp,"</SU%04d>",ii); strcat(buffer,tmp);
       rc = proj->WriteRecord(buffer,strlen(buffer)+1);
     }      // boucle for

   }  // IF OK
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
  {
   cpred=c;
   if (c==sep)
     {
      params[count][ip]=0;
      count++; ip=0;
      if (count > 49) count=49;
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

  strcpy(ecoplan,"Ecoplanning V 5.0");
  PageControl1->ActivePageIndex=0;
  TDateTime dtPresent = Now();
  DecodeDate(dtPresent, Year1, Month1, Day1);
  DecodeDate(dtPresent, Year2, Month2, Day2);


 //Application->MessageBox(DatabaseName,"Caption",MB_OK);
 proj = new genbase();
 strcpy(LocalBase,DatabaseName);
 rc = proj->OpenEngine(LocalBase,120,"eco","dat");   //512 - 8
 rc = proj->SetIndexMode(0,0);
// strcpy(toto,DatabaseName); //MainForm->Caption = AnsiString(DatabaseName);
 if (rc==0) { ShowMessage("Erreur à l'ouverture des fichiers projets"); exit (1); }

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
   plStandard->Caption = AnsiString (tmp);
   // modifier caption de la forme
  }

  // nettoyage buffer avvancement
 dateavanc[0]=0;

rc = proj->ReadDirectKey(0,"<avanc>",RetKey,&recdata);
 if (rc)  // ok : clé trouvée
  {
   rc = proj->ReadRecord(buffer,recdata);
   buffer[rc]=0;
   strcpy(dateavanc,buffer);
  }

AnPrev=2000; MoisPrev=1; JourPrev=1;
rc = proj->ReadDirectKey(0,"<dateprevdebut>",RetKey,&recdata);
 if (rc)  // ok : clé trouvée
  {

   rc = proj->ReadRecord(buffer,recdata);
   buffer[rc]=0;
   strcpy(dateprevdeb,buffer);
   Label7->Caption = AnsiString(dateprevdeb);
   buffer[2]=0; JourPrev=atoi(buffer);
   buffer[5]=0; MoisPrev=atoi(buffer+3);
   buffer[10]=0; AnPrev=atoi(buffer+6);
  }

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
      duree[i]=0;
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
      codetache[i][0]=0;


      for (j=0;j<PS;j++)
        {
         pr[i][j]=0; su[i][j]=0;
         pr_tl[i][j]=0; su_tl[i][j]=0;
         pr_decal[i][j]=0; su_decal[i][j]=0;
        }
     }
  // AdvStringGrid1->RowCount=nb_taches+2;
  AdvStringGrid1->ColCount= 16;
  AdvStringGrid1->Cells[0][0] = "";
  AdvStringGrid1->Cells[1][0] = "N°";
  AdvStringGrid1->Cells[2][0] = "Désignation";
  AdvStringGrid1->Cells[3][0] = "Durée Prev";
  AdvStringGrid1->Cells[4][0] = "Déb + Tot";
  AdvStringGrid1->Cells[5][0] = "Fin + Tot";
  AdvStringGrid1->Cells[6][0] = "Début + Tard";
  AdvStringGrid1->Cells[7][0] = "Fin + Tard";
  AdvStringGrid1->Cells[8][0] = "M. Tot.";
  AdvStringGrid1->Cells[9][0] = "M. Lib.";
  AdvStringGrid1->Cells[10][0] = "Cal";
  AdvStringGrid1->Cells[11][0] = "Code Tache";


  AdvStringGrid2->Cells[0][0] = "";
  AdvStringGrid2->Cells[1][0] = "N°";
  AdvStringGrid2->Cells[2][0] = "Désignation";
  AdvStringGrid2->Cells[3][0] = "Durée";
  AdvStringGrid2->Cells[4][0] = "Déb Prev Possible";
  AdvStringGrid2->Cells[6][0] = "Décalage";
  AdvStringGrid2->Cells[5][0] = "Type Lien";

  AdvStringGrid3->Cells[0][0] = "";
  AdvStringGrid3->Cells[1][0] = "N°";
  AdvStringGrid3->Cells[2][0] = "Désignation";
  AdvStringGrid3->Cells[3][0] = "Durée";
  AdvStringGrid3->Cells[4][0] = "Déb + Tôt";
  AdvStringGrid3->Cells[6][0] = "Décalage";
  AdvStringGrid3->Cells[5][0] = "Type Lien";

 // Boucle de lecture des taches // chargement des tableaux
 // syntaxe pour les taxes : Clé = <T%04d>
 // <T>%d</T><nom>Tache %d</nom><duree>1</duree>",i,i);

  // faire une lecture sequentielle des cles   et charger sommets
  // on remplit sommets
  rc = proj->ReadFirstKey(0,RetKey,&recdata);
  ix=0;
  while (rc)
    {  rc = proj->ReadRecord(buffer,recdata);  // read record in buffer
       buffer[rc]=0;
       lg = ExtractValue(tmp,buffer,"T",0);
       if (lg)
        { ix++;
          if(ix>1) AdvStringGrid1->RowCount++;
          sommets[ix]=atoi(tmp);
          AdvStringGrid1->Cells[1][ix]=atoi(tmp);
          ExtractValue(tmp,buffer,"nom",0);
          AdvStringGrid1->Cells[2][ix]=tmp;
          ExtractValue(tmp,buffer,"duree",0);
          AdvStringGrid1->Cells[3][ix]=tmp;
          duree[ix]=atoi(tmp);
          ExtractValue(tmp,buffer,"cal",0);
          if (strlen(tmp)) tcal[ix]=atoi(tmp);
            else tcal[ix]=1;
           AdvStringGrid1->Cells[10][ix]=tcal[ix];
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
         {
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
         {
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

  init_calendrier();

  current_task=1;
  grefresh(current_task);

}
//---------------------------------------------------------------------------

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
  char months[12][15] = {"Janvier","Février","Mars","Avril","Mai","Juin","Juillet",
   "Aout","Septembre","Octobre","Novembre","Décembre"};
  int nbdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if (AnPrev==0) AnPrev=2005;
  if (MoisPrev==0) MoisPrev=1;
  if (JourPrev==0) JourPrev=1;

  dtFirst = EncodeDate(AnPrev,MoisPrev,JourPrev);
  int counter = nbdays[MoisPrev-1];
  if (MoisPrev==2){ if (IsLeapYear(AnPrev)) counter = 29;}
  // on a besoin de savoir le 1er jour du mois
  int firstday = dtFirst.DayOfWeek();
  int dow;  // day of week
  dow = firstday-1;
  Comment = "1 er Jour Date Prev Debut " + AnsiString(dow) + " = " + AnsiString(days[dow]);
  //lb1->Items->Add(Comment);

  cals = new genbase();
  strcpy(tmp,m_directory); strcat(tmp,"\\calend");
  rc = cals->OpenEngine(tmp,56,"ndx","dat");   //64 - 8
  // rc = cals->OpenEngine("calend",56,"ndx","dat");   //64 - 8
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

    for (i=0;i<=MAX_JOURS;i++)
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
    //lb1->Items->Add(AnsiString(cal[n_cal]));
   }

 cals->CloseEngine(); cals->~genbase();
 //Label20->Caption = AnsiString(weeks[1]);
 return 1;
}

int  __fastcall TplStandard::add_jour(int year, int month, int day, int jours)
{
  // resultats dans An,Mois,Jour
  int i,counter,nbj_restant, j;
//  char days[7][15] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",
//  "Samedi" };
  char months[12][15] = {"Janvier","Février","Mars","Avril","Mai","Juin","Juillet",
   "Aout","Septembre","Octobre","Novembre","Décembre"};
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


 int  __fastcall TplStandard::comp_decal(int decal,int ncal,int deb)
 {
  int value;
  char tmp[250];
  int bcl,cnt;
  int i; char c;
  AnsiString st;

  bcl = decal; value=0;
  cnt=strlen(cal[ncal]);
 if (decal > 0)
  { i=deb+1;
   while ((bcl > 0) && (cnt >0))
     {value++;
      c = cal[ncal][i];
      if (c =='T') { bcl--;}
      cnt--; i++;
     }
   return value;
  }
 else  if  (decal >=0)
  {
   i=deb-1;
   bcl = -decal;
   while ((bcl > 0) && (i > 0))
     { value++;
      if (cal[ncal][i]=='T') { bcl--;}
      cnt--; i--;
     }
   return -value;
  }
 return 0;
 }


 int  __fastcall TplStandard::comp_duree(int dur,int ncal,int deb)
 {
  int value;
  char tmp[250];
  int bdeb,bcl,cnt;

  AnsiString st;
  // count on the right calendar the real number of days;
  int i;
  int d;


  d=dur;   i=0;
  value=0; i=deb;  cnt = strlen(cal[ncal]);  // i=deb
  while ((d >0) && (cnt>0))
    { cnt--; value++;
     if (cal[ncal][i]=='T') { i++; d--;}
     else { i++;}
    }

 // strncpy(tmp,cal[ncal],40); tmp[40]=0;
 // st = "compute duree Deb= " + AnsiString(deb)+ " durée = " + AnsiString(dur) + " value = " + AnsiString(value) + "extrait " + AnsiString(tmp);

  //lb1->Items->Add(st); // AnsiString(tmp));
  return value;
 }


int  __fastcall TplStandard::reverse(int fpt, int dur,int nc)
{
 int i,cnt;
 int fin,deb;
 int bcl = 0;
 int value;

 fin = fpt; cnt=strlen(cal[nc]);


  // calcul reverse pour trouver le début
  value = 0; bcl = dur; i=fin;
  while ((bcl>0) && (i>0))
    {
     cnt--;
     value++;
     if (cal[nc][i] == 'T')
          {bcl--;  }
     i--;
    }
 return value;
}

int __fastcall TplStandard::skip_days(int ncal,int deb)
{
 int value,i,cnt;
 value=0; cnt=7;
 i=deb;
 while (cnt>0)
  {
   if (cal[ncal][i] == 'N')
     {
      value++;
      }
   else break;
   cnt--; i++;
  }
 return value;
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

sommets[nb_taches+1]=0; // $$$$ 9999;   // nb_taches+1;
 // clean niveaux


 if (nb_taches == 0) return;


 for (i=0; i<MAX_T;i++) t_select[i]=0;
 for (i=0;i<MAX_NIV;i++)
    {
     for (j=0;j<NS;j++) {  niveaux[i][j]=0;  t_pred[i][j]=0; }
    }
  // etablir le dictionnaire des predecesseurs
 // c est une copie de pr
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
     // fin de calcul ?  quand toutes les taches ont ete selectionnees
     count=0;
     for (i=1;i<=nb_taches;i++) if (t_pred[i][1] == -1)  count++;    // -1
     if (count == nb_taches) flag=1;
     if (flag) ok=0;
    }  // end while

 // maintenant, on calcule les dates au plus tot
 // au niveau 0 : pas de calcul de max a faire

 // sommet terminal
  for (i=1;i<=nb_taches;i++) duree_reelle[i]=duree[i]; // §§§§§§§§§§§
  // date debut = date previsionnelle

  A=AnPrev; M=MoisPrev;J=JourPrev;

  for (tniv=0;tniv<iniv;tniv++)
   {
    inext=0; xmax=-1000;
    while (niveaux[tniv][inext] != 0)
     {
      ind=niveaux[tniv][inext];
      ind = exist_tache(ind,nb_taches); // §§§§§§§§§§§§§§§§§§§

      if (tniv==0)  // niveau zero
       {
         // on traite les taches normales
         imax=0; zcal=tcal[ind];
         total=avance_conges(0,zcal);

//         fduree = comp_up(-1,zcal,duree[ind]); // on demarre de -1 = fin plot tot du precedent!!!!

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
           xtpred=exist_tache(xtpred,nb_taches);   // §§§§§§§§§§§§§§§§
           // total=deb_plus_tot[xtpred] + duree_reelle[xtpred];  // remplacé par
           //total=fin_plus_tot[xtpred];
              if (pr_tl[ind][ipred]==0)     //  c est un lien fd
                 {
                   if ( pr_decal[ind][ipred] > 0)
                      { zcal=tcal[ind];
                        total = avance_conges(fin_plus_tot[xtpred]+1,zcal);
                        total = avance_temps(total,zcal,pr_decal[ind][ipred]);
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

               if (pr_tl[ind][ipred] == 2)  flag_amont = ipred;
               if (pr_tl[ind][ipred] == 3)    // Lien DD   Decal est >= 0
                  {
                   if ( pr_decal[ind][ipred] > 0)
                      { zcal=tcal[xtpred];
                        total=avance_conges(deb_plus_tot[xtpred],zcal);
                        total = avance_temps(total,zcal,pr_decal[ind][ipred]);
                       }
                   else if ( pr_decal[ind][ipred] == 0)
                        { zcal=tcal[ind];
                          total=avance_conges(deb_plus_tot[xtpred],zcal);
                        } // pas de calcul de decalage
                  }

           if (total > imax) imax=total;
           ipred++;
         }
        zcal=tcal[ind];
        deb_plus_tot[ind] = imax;
        fin_plus_tot[ind] = avance_temps(imax,zcal,duree[ind])-1;  // !!!! decalage de -1
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
              mom=tmom[t_amont];
              //deb_plus_tot[t_amont]=deb_plus_tot[mom];
              //deb_plus_tard[t_amont]=deb_plus_tard[mom];
              zcal=tcal[t_start];
              fdecal = comp_down(deb_plus_tot[t_start],zcal,pr_decal[t_start][flag_amont]);
              zcal=tcal[t_amont];
              fduree = comp_down(fdecal,zcal,duree[t_amont]);
              if (fduree < 0)
                { sprintf(tmp,"Tache Amont %d : Debordement possible sur le début",x_amont);
                 Application->MessageBoxA(tmp,ecoplan,MB_OK);
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

 // ??????????????????
 deb_plus_tot[nb_taches+1]= deb_plus_tot[xind]+duree_reelle[xind];

 // on fait des successeurs pour la tache fictive  (nb_taches+1)
 for (ind=1;ind<=nb_taches;ind++)   // §§§§§§§§§§§§§§§§§§§!
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
                   xtotal = comp_down(deb_plus_tard[nb_taches+1],zcal,duree[indx]);
                   imin=xtotal;
                  }
                else  // il existe un successeur
                  {  imin=imin; }
              isucc++;
           }
            else
              {
                xtsucc = exist_tache(xtsucc,nb_taches); //§§§§§§§§§§§§§§§
                if (su_tl[indx][isucc]==0)     //  c est un lien fd
                  {
                   if (su_decal[indx][isucc] > 0)
                     { zcal=tcal[indx];  // xtsucc];
                       fduree = comp_down(deb_plus_tard[xtsucc],zcal,su_decal[indx][isucc]);
                       zcal=tcal[indx];
                       xtotal = comp_down(fduree,zcal,duree[indx]);    // $$$$$$$$$$$$
                     }
                   else if (su_decal[indx][isucc] < 0)
                     {
                      zcal=tcal[indx]; //xtsucc];
                      fduree = comp_up(deb_plus_tard[xtsucc],zcal,-su_decal[indx][isucc]);
                      zcal=tcal[indx];
                      xtotal = comp_down(fduree,zcal,duree[indx]);
                     }
                   else
                     {zcal=tcal[indx];
                      xtotal = comp_down(deb_plus_tard[xtsucc],zcal,duree[indx]);
                     }
                  }
                if (su_tl[indx][isucc]==1)     //  c est un lien ff
                  {
                   if (su_decal[indx][isucc] > 0)
                     {zcal=tcal[xtsucc]; //  indx]; // xtsucc];
                      fduree = comp_down(fin_plus_tard[xtsucc],zcal,su_decal[indx][isucc]-1);
                      zcal=tcal[indx];
                      xtotal = comp_down(fduree,zcal,duree[indx]);
                     }
                   else if (su_decal[indx][isucc] < 0)
                     {zcal=tcal[xtsucc];  //  indx]; //xtsucc];
                      fduree = comp_up(fin_plus_tard[xtsucc],zcal,-su_decal[indx][isucc]); // -1);
                      zcal=tcal[indx];
                      xtotal = comp_down(fduree,zcal,duree[indx]);
                     }
                   else
                     {zcal=tcal[indx];
                      xtotal = comp_down(fduree,zcal,duree[indx]);
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
                       fduree = comp_down(deb_plus_tard[xtsucc],zcal,su_decal[indx][isucc]);
                       zcal=tcal[indx];
                       xtotal = comp_down(fduree,zcal,duree[indx]);    // $$$$$$$$$$$$
                     }
                   else if (su_decal[indx][isucc] < 0)
                     {
                      //zcal=tcal[indx]; //xtsucc];
                      //fduree = comp_up(deb_plus_tard[xtsucc],zcal,-su_decal[indx][isucc]);
                      //zcal=tcal[indx];
                      //xtotal = comp_down(fduree,zcal,duree[indx]);
                     }
                   else
                     {zcal=tcal[indx];
                      xtotal = comp_down(deb_plus_tard[xtsucc],zcal,duree[indx]);
                     }
                  }



                if (xtotal < imin) { imin=xtotal; }
                isucc++;
              }
          }  // while su

        if (imin==100000)  imin=0;
        deb_plus_tard[indx]=imin;
        zcal=tcal[indx];
        fduree = comp_up(deb_plus_tard[indx]-1,zcal,duree[indx]);
         //duree_reelle[indx] = fduree;
        //  $$$$ fin_plus_tard[indx]= imin + duree_reelle[indx] - 1;
        fin_plus_tard[indx]= fduree;

        if (su_tl[indx][1]== 2)
          {
           deb_plus_tard[indx] = deb_plus_tot[indx];
           fin_plus_tard[indx] = fin_plus_tot[indx];
          }



        if (flag_amont)
          {
           // boucle pour trouver les taches filles sur tmom;
          }




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
      add_jour(AnPrev,MoisPrev,JourPrev,deb_plus_tot[indx]);
      sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
      AdvStringGrid1->Cells[4][indx] = AnsiString(tmp); //deb_plus_tot[indx]+1);
      add_jour(AnPrev,MoisPrev,JourPrev,fin_plus_tot[indx]);
      sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
      AdvStringGrid1->Cells[5][indx] = AnsiString(tmp);  // fin_plus_tot[indx]);
      add_jour(AnPrev,MoisPrev,JourPrev,deb_plus_tard[indx]);
      sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
      AdvStringGrid1->Cells[6][indx] = AnsiString(tmp); //deb_plus_tard[indx]+1);
      add_jour(AnPrev,MoisPrev,JourPrev,fin_plus_tard[indx]);
      sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
      AdvStringGrid1->Cells[7][indx] = AnsiString(tmp);   // fin_plus_tard[indx]);
      AdvStringGrid1->Cells[8][indx] = AnsiString(marg_tot[indx]);
      AdvStringGrid1->Cells[9][indx] = AnsiString(marg_lib[indx]);
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

  dtFirst = EncodeDate(AnPrev,MoisPrev,JourPrev);
  firstday = dtFirst.DayOfWeek();
  int dow;  // day of week
  dow = firstday-1;

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
 ttot=deb_plus_tot[task];
 // adjust with position
 // position is relative to the middle (50 %)
 ttot = ttot + int (40*pos/200);     //  30/2
 if (ttot <0) ttot=0;
 ScrollBar2->Position = 50 + pos;
 if (nb_taches>0) ScrollBar1->Position = 100 * task / nb_taches;

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
 tdeb=task;  tfin=tdeb+30; if (tfin>nb_taches) tfin=nb_taches;

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
         Texte = Texte + AdvStringGrid1->Cells[2][ixx] + " (d=" + IntToStr(duree[ixx]) + ")";
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

void __fastcall TplStandard::Refresh_Pred_Succ(int row)
 {
  int  ipred, isucc,is;
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
    for (icol=1;icol<=AdvStringGrid2->ColCount;icol++)
      AdvStringGrid2->Cells[icol][irow]="";

    for (irow=1;irow<AdvStringGrid3->RowCount;irow++)
    for (icol=1;icol<=AdvStringGrid3->ColCount;icol++)
      AdvStringGrid3->Cells[icol][irow]="";

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
          if (pr[row][ipred] !=9999)
          {
          if (row > 1) AdvStringGrid2->RowCount++;
          AdvStringGrid2->Cells[1][ipred]=pr[row][ipred];           // taches
          AdvStringGrid2->Cells[2][ipred]=AdvStringGrid1->Cells[2][indice];           // designation
          AdvStringGrid2->Cells[3][ipred]=duree[indice];    //duree

          // Deb Prev Possible = fin au plus tot du predecesseur + decalage
         // add_jour_cal(AnPrev,MoisPrev,JourPrev,fin_plus_tot[indx]+1);

          if (pr_decal[row][ipred]>0)
          fd = comp_up(fin_plus_tot[indx],tcal[current_task],pr_decal[row][ipred]+1);
          else
          fd = comp_up(fin_plus_tot[indx],tcal[current_task],-pr_decal[row][ipred]-1);

          add_jour(AnPrev,MoisPrev,JourPrev,fd);
          sprintf(tmp,"%02d/%02d/%02d",Jour,Mois,An%100);
          AdvStringGrid2->Cells[4][ipred]=AnsiString(tmp);

          //AdvStringGrid2->Cells[4][ipred]=deb_plus_tot[indice]; // +1;
          if (pr_tl[row][ipred]==0) AdvStringGrid2->Cells[5][ipred]="FD";
           else if (pr_tl[row][ipred]==1) AdvStringGrid2->Cells[5][ipred]="FF";
           else if (pr_tl[row][ipred]==2) AdvStringGrid2->Cells[5][ipred]="AM";
           else if (pr_tl[row][ipred]==3) AdvStringGrid2->Cells[5][ipred]="DD";
          AdvStringGrid2->Cells[6][ipred]=pr_decal[row][ipred];     // decal
          }
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
              if (row>1) AdvStringGrid3->RowCount++;
              AdvStringGrid3->Cells[1][is]=su[row][isucc];           // taches
              AdvStringGrid3->Cells[2][is]=AdvStringGrid1->Cells[2][indice];          // designation
              AdvStringGrid3->Cells[3][is]=duree[indice];    //duree
              AdvStringGrid3->Cells[4][is]=deb_plus_tot[indice]+1;
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
 int ipred,found,indx;
  //AdvStringGrid2->Row++;
    // FAUX  insere tache predecesseur  (la tache en cours est current_task
    // tach et trped sont les numeros reels
    ipred=1;  found=0;
    indx = exist_tache(tach,new_nb_taches);

    while ((pr[indx][ipred]!=0) && (ipred<PS)) // && (pr[tach][ipred]!=9999)) && (ipred<PS))
       {
        if (pr[indx][ipred] == tpred){found=1; break; }
        else  ipred++;
       }

    if (ipred >= PS-1) Application->MessageBox("Insert Pred : Pred > PS ",ecoplan,MB_OK);
    pr[indx][ipred] = tpred;
    pr_tl[indx][ipred] = tl;
    pr_decal[indx][ipred] = decal;

    if (!found) AdvStringGrid2->RowCount++;
    pr[indx][ipred+1]=0; // 9999;

}

void __fastcall TplStandard::InsertSuccSeul(int tach,int tsucc,int tl, int decal)
{
 int isucc;
 int dec,xsucc;
 int found;


 // &&&&&&&&&&&&&&

 dec= exist_tache(tach,new_nb_taches);
 xsucc= tsucc; // =exist_tache(tsucc,new_nb_taches);
 if (dec==0) return;
 if (xsucc==0) return;

    isucc=1; found=0;
    while (((su[dec][isucc]!=0) && (su[dec][isucc] !=9999)) && (isucc<PS))
       {  if (su[dec][isucc] == tsucc) { found=1; break;} else isucc++; }

    if (isucc >= PS-1) Application->MessageBox("Insert Succ : Succ > PS ",ecoplan,MB_OK);
    su[dec][isucc] = xsucc;
    su_tl[dec][isucc] = tl;
    su_decal[dec][isucc] = decal;
     if (!found) AdvStringGrid3->RowCount++;

    isucc=1;
    while (su[dec][isucc] !=0) isucc++;
    su[dec][isucc]=9999; //0  9999;

}



//---------------------------------------------------------------------------


void __fastcall TplStandard::Effacer1Click(TObject *Sender)
{

 char tmp[100];
 // Effacer Tache   en cours
 sprintf(tmp,"Confirmer effacement de la tâche %d",current_task);
 if (Application->MessageBox(tmp,ecoplan,MB_YESNO) ==IDNO) return;
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
       AdvStringGrid1->Cells[2][indx+1]=AdvStringGrid1->Cells[2][indx];
       AdvStringGrid1->Cells[3][indx+1]=AdvStringGrid1->Cells[3][indx];
      } // for indx

   // insertion de la tache en indice "a"
   sommets[a]=nt;
   coche[a]=' ';
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
   AdvStringGrid1->Cells[2][a]=AnsiString(tmp);
   AdvStringGrid1->Cells[3][a]=1;
   if (a>1) AdvStringGrid1->RowCount++;
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




void __fastcall TplStandard::WriteExchange(int n)
{
 FILE *fp;
 fp = fopen("dataexchange.txt","w");
 if (fp)
   {
    fputs(exchange,fp);   fputs("\n",fp);
    if (n>1) { fputs(exchange2,fp); fputs("\n",fp); }
    fclose(fp);
   }
 else Application->MessageBox("Impossible d'ouvrir le fichier échanges",ecoplan,MB_OK);

}

void __fastcall TplStandard::ReadExchange(int n)
{
  FILE *fp;  int l;
 exchange2[0]=0;
 fp = fopen("dataexchange.txt","r+b");
 fgets(exchange,1999,fp);
 l=strlen(exchange); if (l>1) exchange[l-2]=0;
 if (n>1) { fgets(exchange2,1999,fp); l=strlen(exchange2); if (l>1) exchange2[l-2]=0; }
 fclose(fp);
}
void __fastcall TplStandard::CochertouteslesTaches1Click(TObject *Sender)
{
 int i;
 for (i=1;i<=nb_taches;i++) // §§§§§§§§§§§§§§§
   { coche[i] = 'X';
     AdvStringGrid1->Cells[0][i]="X";
   }
 refresh_coches();

}
//---------------------------------------------------------------------------

void __fastcall TplStandard::DcochertouteslesTaches1Click(TObject *Sender)
{
 int i;
 for (i=1;i<=nb_taches;i++)  // §§§§§§§§§§§§§§§§§§§
   {
    coche[i]=' ';
    AdvStringGrid1->Cells[0][i]=" ";
   }
 refresh_coches();
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::CopierlesTaches1Click(TObject *Sender)
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
 int ipred,tpred,decal,nt;
 int numtachpred,decalpred,tlpred,indpred;
 int l,count,i,index,first;
 int xnb_taches;
 int nb_coches;
 //   on va faire appel a une boite de dialogue;

     CTask = new TCopy(Application);
     CTask->ShowModal();
     delete CTask;
     ReadExchange(1);
     l=ExtractValue(tmp,exchange,"null",0);
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
     ExtractValue(tmp,exchange,"cascade",0);
     if (strcmp(tmp,"T")==0)
       { cascade=1;
         ExtractValue(tmp,exchange,"decalage",0);
         decalage=atoi(tmp);
         ExtractValue(tmp,exchange,"tl",0);
         tlien=atoi(tmp);
       }
     oldcoche=0; newcoche=0;
     ExtractValue(tmp,exchange,"old",0);
     if (strcmp(tmp,"T")==0)  oldcoche=1;
     ExtractValue(tmp,exchange,"new",0);
     if (strcmp(tmp,"T")==0)  newcoche=1;

   // compter les coches : message si dup > MAX_T
   count=0;
   xnb_taches=nb_taches;
   for (i=1;i<=xnb_taches;i++)if (coche[i]=='X') count++;
   if ((nb_taches+count) >= MAX_T)
    {
     Application->MessageBox("Nombre de tâches trop élevé ( > 4200 )",ecoplan,MB_OK);
     return;
    }
   //  maintenant, on y va, on duplique

   count=0;

   first=true;
   for (i=1;i<=xnb_taches;i++)
     {
      if ((coche[i]=='X') && (su_tl[i][1] != 2))   // ne pas copier taches amont
       {
        count++;  index= xnb_taches+count;
        nexttache++;

        duree[index]=duree[i];
        tcal[index] = tcal[i];

        filtr[index]=filtr[i];
       duree_reelle[index]=duree_reelle[i];
       strcpy(codetache[index],codetache[i]);
       strcpy(da[index],da[i]);
       strcpy(dtr[index],dtr[i]);
       strcpy(ftr[index],ftr[i]);
       //pc[indx+1]=pc[indx];
       //nbj[indx+1]=nbj[indx];
       //tmom[indx+1]=tmom[indx];



        sommets[index]=nexttache;
        AdvStringGrid1->Cells[1][index]= nexttache;
        AdvStringGrid1->Cells[2][index]= "Tache " + IntToStr(nexttache) + " ";
        nb_taches=nb_taches+1;
 //       pr[index][1]=0; su[index][1]=0; // 9999;

        if (!cascade)
          {
           if (!first)
             {
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

              } //
            first=false;
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
        AdvStringGrid1->RowCount++;
        if (newcoche==1)
          { coche[index]='X';
            AdvStringGrid1->Cells[0][index]= "X";
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
       AdvStringGrid1->Cells[2][indx]=AdvStringGrid1->Cells[2][indx+1];
       AdvStringGrid1->Cells[3][indx]=AdvStringGrid1->Cells[3][indx+1];
   }

   // clean the last row
   for (k=0;k<=AdvStringGrid1->ColCount;k++)  AdvStringGrid1->Cells[k][nb_taches]="";

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
    AdvStringGrid1->Cells[0][i]="X";
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
    AdvStringGrid1->Cells[0][i]="X";
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
 x=ScrollBar2->Position - 50;
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
  int l,decal,tl;
  char tmp[250];
  int ix; int first; int previous;

   TLienCoche *CLien;
 // lier taches cochees
 // faire paraitre une petite fenetre de dialogue
     CLien = new TLienCoche(Application);
     CLien->ShowModal();
     delete CLien;
     ReadExchange(1);
     l=ExtractValue(tmp,exchange,"null",0);
     if (strcmp(tmp,"TRUE")==0) return;

 // on extrait type de lien et decalage
     l=ExtractValue(tmp,exchange,"decalage",0);
     decal = atoi(tmp);
     l=ExtractValue(tmp,exchange,"tl",0);
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
      ecoplan,MB_YESNO)== IDNO) return;
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
      ecoplan,MB_YESNO)== IDNO) return;

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
 updatedatabase(LocalBase);
 Application->MessageBox(newname,ecoplan,MB_OK);
 return 1;

}

//---------------------------------------------------------------------------

void __fastcall TplStandard::MonthCalendar1Click(TObject *Sender)
{
 Edit3->Text = MonthCalendar1->Date;
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::Button9Click(TObject *Sender)
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
      if (coche[Row]=='X') coche[Row]=' ';
       else coche[Row]='X';
    AdvStringGrid1->Cells[0][Row] = coche[Row];
    AdvStringGrid1->Cells[1][Row] = IntToStr(sommets[Row]);
    AdvStringGrid1->Row=sommets[Row];
    AdvStringGrid1->Col=1;
     }
 }



//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 int i,ipred,isucc;
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
     if (nt>1) AdvStringGrid1->RowCount++;
     nb_taches++; new_nb_taches=nb_taches;

     sommets[nb_taches]=nt;
     AdvStringGrid1->Cells[1][nb_taches]=nt;


     //ExtractValue(tmp,exchange,"libel",0);

     sprintf(tmp,"Tache numéro %d",nt);

     AdvStringGrid1->Cells[2][nb_taches]= AnsiString (tmp);
     AdvStringGrid1->Cells[10][nb_taches]= "1";
     //ExtractValue(tmp,exchange,"duree",0);
     //dur = atoi(tmp);
      i=nb_taches;
      duree[i]=0;
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

     ipred=1;
     sommets[nb_taches]=nt;  ///nb_taches;

     AdvStringGrid1->Cells[3][nb_taches]= IntToStr(dur);
      current_task=nb_taches;
      grefresh(current_task);
     return;
   }  // VK_INSERT

 if (Key==VK_DELETE)
    {
    sprintf(tmp,"Confirmer effacement de la tâche %d",current_task);
    if (Application->MessageBox(tmp,ecoplan,MB_YESNO) ==IDNO) return;
    effacer_tache(current_task);

     current_task=1;
      if (nb_taches==0) current_task=0;
     else
      {  current_task=1;
         grefresh(current_task);
      }
    // AdvStringGrid1->Refresh();
    }

 }

void __fastcall TplStandard::AdvStringGrid1GetCellColor(TObject *Sender,
      int ARow, int ACol, TGridDrawState AState, TBrush *ABrush,
      TFont *AFont)
{
  if (AdvStringGrid1->Cells[8][ARow]=="0")
   {
    if (ACol==1) ABrush->Color=clRed;
   }
}







void __fastcall TplStandard::AdvStringGrid1CanEditCell(TObject *Sender,
      int ARow, int ACol, bool &CanEdit)
{
 CanEdit = true;
 if (ARow == 1) CanEdit = false;
 //if ((ACol < 2) || (ACol > 3)) CanEdit = false;
 if (ACol == 11) CanEdit = true;  // code tache
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::AdvStringGrid1ClickCell(TObject *Sender,
      int ARow, int ACol)
{
  /*
  if ((ARow <1) || (ARow > nb_taches)) return;
  SG1Col = Cur1Col = ACol;
  SG1Row = Cur1Row = ARow;

  current_task=ARow;
 grefresh(current_task);
 */
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
    exchange[0]=0;
    sprintf(exchange,"Préd. Tache %d",sommets[current_task]);
    WriteExchange(1);
    Num_Tache_Pred = new TNum_Tache_Pred(Application);
    Num_Tache_Pred->ShowModal();
    delete Num_Tache_Pred;
    ReadExchange(1);
    ExtractValue(tmp,exchange,"tache",0);
    numt = atoi(tmp);
    if ((numt <1) || (numt>9999)) return;
    nt = exist_tache(numt,nb_taches);
    if (nt==0)
     {
     Application->MessageBox("Cette tache n'existe pas",ecoplan,MB_OK);
     return;
     }
    ExtractValue(tmp,exchange,"tl",0);
    tl = atoi(tmp);
    ExtractValue(tmp,exchange,"decal",0);
    decal = atoi(tmp);

    if (numt==sommets[current_task])        // @@@@@@@@@@@@@@
      {
      Application->MessageBox("Même numéro de tâche prédecesseur",ecoplan,MB_OK);
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
     if (Application->MessageBox("Comfirmez la suppression du predecesseur",ecoplan,MB_YESNO)== IDNO)
     return;
     numt = StrToInt(AdvStringGrid2->Cells[1][SG2Row]);
     ctask=sommets[current_task];
     RemovePredSeul(ctask,numt);
     RemoveSuccSeul(numt,ctask);
     grefresh(current_task);
    }
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

 // §§§§§§§§§§§§§§§§§§§§§§

 if (Key==VK_INSERT)
   {
    exchange[0]=0;
    sprintf(exchange,"Succ. Tache %d",sommets[current_task]);
    WriteExchange(1);
    Num_Tache_Succ = new TNum_Tache_Succ(Application);
    Num_Tache_Succ->ShowModal();
    delete Num_Tache_Succ;
    ReadExchange(1);
    ExtractValue(tmp,exchange,"tache",0);
    numt = atoi(tmp);
    if ((numt <1) || (numt>9999)) return; //nb_taches)) return;
    nt = exist_tache(numt,nb_taches);
    if (nt==0)
     {
     Application->MessageBox("Cette tache n'existe pas",ecoplan,MB_OK);
     return;
     }
    ExtractValue(tmp,exchange,"tl",0);
    tl = atoi(tmp);
    ExtractValue(tmp,exchange,"decal",0);
    decal = atoi(tmp);

    if (numt==sommets[current_task])
      {
      Application->MessageBox("Même numéro de tâche successeur",ecoplan,MB_OK);
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
     if (Application->MessageBox("Comfirmez la suppression du successeur",ecoplan,MB_YESNO)== IDNO)
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
       AdvStringGrid1->Cells[2][indx+1]=AdvStringGrid1->Cells[2][indx];
       AdvStringGrid1->Cells[3][indx+1]=AdvStringGrid1->Cells[3][indx];
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
   nb_taches++;

}

void __fastcall TplStandard::TachesAmontssurtachesCoches1Click(
      TObject *Sender)
{
  int ind,precedent,torig, nt,ix,l;
  char tmp[250]; int nbt,dur_amont,design,pos;
  char libel[100],opdesign[10];
 //  examiner la premiere tache cochées
  TfTachesAmont *tam;


for (ind=1;ind <= nb_taches; ind++)
  {
   if (coche[ind]=='X')
    {
     exchange[0]=0;
     sprintf(exchange,"%d",sommets[ind]);
     strcpy(exchange2,AdvStringGrid1->Cells[2][ind].c_str());
     WriteExchange(2);
     tam = new TfTachesAmont(Application);
     tam->ShowModal();
     delete tam;
     ReadExchange(1);
     l=ExtractValue(tmp,exchange,"null",0);
     if (strcmp(tmp,"TRUE")!=0)
       {
         ExtractValue(tmp,exchange,"nbt",0);
         nbt = atoi(tmp);
         ExtractValue(tmp,exchange,"dur",0);
         dur_amont = atoi(tmp);
         ExtractValue(opdesign,exchange,"design",0);
         strcpy(libel,AdvStringGrid1->Cells[2][ind].c_str());

         // on demarre avec tache mere
         precedent = sommets[ind];
         torig = ind+1;
         for (ix=1;ix<=nbt;ix++)
          {
            nt = next_task();

            if (strcmp(opdesign,"same")==0) strcpy(tmp,libel);
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
 int ind,num_cal,l;
 TAffectCal *taf;
 char tmp[250];

 taf = new TAffectCal(Application);
 taf->ShowModal();
 delete taf;
 ReadExchange(1);
 l=ExtractValue(tmp,exchange,"null",0);
 if (strcmp(tmp,"TRUE")==0)  return;
 ExtractValue(tmp,exchange,"ncal",0);
 num_cal = atoi(tmp);
 if ((num_cal<1) || (num_cal>5)) num_cal= 1;


 for (ind=1;ind <= nb_taches; ind++)
  {
   if (coche[ind]=='X')
    {
         tcal[ind] = num_cal;
         AdvStringGrid1->Cells[10][ind]= num_cal;
    }
   } // end FOR

   current_task=1;
   init_calendrier();
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
     //current_task=vtask;
     grefresh(current_task);
     return;
    }
  if (ACol==5)  // Type
    { Valid=false;
      vtask = atoi(AdvStringGrid2->Cells[1][ARow].c_str());
      // vtask=exist_tache(vtask,nb_taches);
      if (strcmp(tmp,"fd")==0) { Valid=true; strcpy(tmp,"FD"); AdvStringGrid2->Cells[5][ARow]="FD"; }
      if (strcmp(tmp,"ff")==0) { Valid = true;strcpy(tmp,"FF"); AdvStringGrid2->Cells[5][ARow]="FF"; }
      if (strcmp(tmp,"am")==0) { Valid=true; strcpy(tmp,"AM"); AdvStringGrid2->Cells[5][ARow]="AM"; }
      if (strcmp(tmp,"dd")==0) { Valid=true; strcpy(tmp,"DD"); AdvStringGrid2->Cells[5][ARow]="DD"; }
      if ((strcmp(tmp,"FD")==0) ||
           (strcmp(tmp,"FF")==0) ||
           (strcmp(tmp,"DD")==0) ||
           (strcmp(tmp,"AM")==0))
       {
        idecal = atoi(AdvStringGrid2->Cells[6][ARow].c_str()); typl=0;
        if (strcmp(tmp,"FD")==0) typl = 0;
        if (strcmp(tmp,"FF")==0) typl= 1;
        if (strcmp(tmp,"AM")==0) typl= 2;
        if (strcmp(tmp,"DD")==0) typl= 3;
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
}
//---------------------------------------------------------------------------


int __fastcall  TplStandard::grefresh(int task)
{

 Compute_PlusTotA();
 Compute_PlusTardA();
 DrawGantt(task,-20);
 Refresh_Pred_Succ(task);
}


/////////////////////////////////////////////////////////////////

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
      if (strcmp(tmp,"fd")==0) { Valid=true; strcpy(tmp,"FD"); AdvStringGrid3->Cells[5][ARow]="FD"; }
      if (strcmp(tmp,"ff")==0) { Valid = true;strcpy(tmp,"FF"); AdvStringGrid3->Cells[5][ARow]="FF"; }
      if (strcmp(tmp,"am")==0) { Valid=true; strcpy(tmp,"AM"); AdvStringGrid3->Cells[5][ARow]="AM"; }
      if (strcmp(tmp,"dd")==0) { Valid=true; strcpy(tmp,"DD"); AdvStringGrid3->Cells[5][ARow]="DD"; }
      if ((strcmp(tmp,"FD")==0) ||
           (strcmp(tmp,"FF")==0) ||
           (strcmp(tmp,"DD")==0) ||
           (strcmp(tmp,"AM")==0))
       {
        idecal = atoi(AdvStringGrid3->Cells[6][ARow].c_str()); typl=0;
        if (strcmp(tmp,"FD")==0) typl = 0;
        if (strcmp(tmp,"FF")==0) typl= 1;
        if (strcmp(tmp,"AM")==0) typl= 2;
        if (strcmp(tmp,"DD")==0) typl= 3;
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
        if (strcmp(stypl,"FD")==0) typl = 0;
        if (strcmp(stypl,"FF")==0) typl= 1;
        if (strcmp(stypl,"AM")==0) typl= 2;
        if (strcmp(stypl,"DD")==0) typl= 3;
        Valid=true;
        new_nb_taches=nb_taches;
        InsertSuccSeul(current_task,vtask,typl,idecal);
        InsertPredSeul(vtask,current_task,typl,idecal);
        grefresh(current_task);
     return;
     }

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



int __fastcall TplStandard::verifdate(char *dt)
{
 char d[50];     // format DD/MM/AAAA
 char tmp[10];
 strcpy(d,dt);
 d[2]=0; JourVerif=atoi(d);
 d[5]=0; MoisVerif=atoi(d+3);
 d[10]=0; AnVerif=atoi(d+6);
 if ((JourVerif < 0) || (JourVerif > 31))
   {
    Application->MessageBoxA("Jour Incorrect",ecoplan,MB_OK);
    return 1;
   }
 if ((MoisVerif < 0) || (MoisVerif > 12))
   {
    Application->MessageBoxA("Mois Incorrect",ecoplan,MB_OK);
    return 1;
   }
 if ((AnVerif < 1990) || (AnVerif > 2050))
   {
    Application->MessageBoxA("Année Incorrecte",ecoplan,MB_OK);
    return 1;
   }
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


void __fastcall TplStandard::asAvancSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
 int task,itask;
 char tmp[250];
 int dur,nb;

  if ((ARow>0) && (ARow <= nb_taches))
  {
   strcpy(tmp,asAvanc->Cells[1][ARow].c_str());
   task = atoi(tmp);
   itask = exist_tache(task,nb_taches);


   //sprintf(tmp,"%02d-%02d-%04d",JourAvanc,MoisAvanc,AnAvanc);
   //if (strlen(da[itask])) AdvStringGrid4->Cells[1][1] = da[itask];
   //   else  AdvStringGrid4->Cells[1][1] = tmp;
   if (pc[itask] < 0) pc[itask]=100;
   AdvStringGrid4->Cells[3][1] = pc[itask];

   //strcpy(tmp,asAvanc->Cells[3][ARow].c_str()); // duree
   //dur = atoi(tmp);
   //nb= pc[itask]*dur / 100;
   //AdvStringGrid4->Cells[3][1] = nb;
   
   row_avancement = ARow;

   // if (nbj[itask] <=0) nbj

  }
}

void __fastcall TplStandard::validate_avancement()
{
 if (!global_valid) return;
 // row_avancement est a l'origine
 asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];
 asAvanc->Cells[7][row_avancement] = AdvStringGrid4->Cells[8][1];
 asAvanc->Cells[8][row_avancement] = AdvStringGrid4->Cells[6][1];
 asAvanc->Cells[9][row_avancement] = AdvStringGrid4->Cells[5][1];
// asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];
// asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];
// asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];
// asAvanc->Cells[6][row_avancement] = AdvStringGrid4->Cells[7][1];

}

//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid4CanEditCell(TObject *Sender,
      int ARow, int ACol, bool &CanEdit)
{
 if ((ARow==0)|| (ARow>1)) { CanEdit=false; return; }
 if (ACol<2){ CanEdit = false; return; }
 CanEdit=true;
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::AdvStringGrid4CellValidate(TObject *Sender,
      int ACol, int ARow, AnsiString &Value, bool &Valid)
{

 char tmp[250];
 float nbf;
 char dt1[20]; char dt2[20];
 int rc;
 strcpy(tmp,Value.c_str());
 global_valid=false;
 switch (ACol)
  {
   case 1:
      rc = verifdate(tmp);
      if (rc > 1)
        { Application->MessageBoxA("Date erronnée",ecoplan,MB_OK); Valid=false; break; }
      strcpy(dt1,tmp);
      Valid=true;
      break;
   case 2:  // Deb ?
      rc = verifdate(tmp);
      if (rc > 1)
        { Application->MessageBoxA("Date erronnée",ecoplan,MB_OK); Valid=false; break; }
      strcpy(dt1,tmp);
      break;

   case 3 : // % restant
      nbf = atof(tmp);
      if ((nbf<0.0)|| (nbf>100.0))
        { Application->MessageBoxA("Pourcentage avancement tache erronné",ecoplan,MB_OK);
          Valid=false; break;
        }
      Valid=true;
      break;
   case 4 : //nb jours restants

      Valid=true;
      break;

   case 5 : //debut plus tot reel
      rc = verifdate(tmp);
      if (rc > 1)
        { Application->MessageBoxA("Date erronnée",ecoplan,MB_OK); Valid=false; break; }
      strcpy(dt1,tmp);
      Valid=true;
      break;

   case 6 :  //  Duree

      Valid=true;
      break;
   case 7 :  // retard total
      rc = verifdate(tmp);
      if (rc > 1)
        { Application->MessageBoxA("Date erronnée",ecoplan,MB_OK); Valid=false; break; }
      strcpy(dt1,tmp);
      Valid=true;

      break;
   case 8 : // retard imputable
      rc = verifdate(tmp);
      if (rc > 1)
        { Application->MessageBoxA("Date erronnée",ecoplan,MB_OK); Valid=false; break; }
      strcpy(dt2,tmp);
      Valid=true;
      break;
  }
 global_valid=Valid;
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::AdvStringGrid4ClickCell(TObject *Sender,
      int ARow, int ACol)
{
 if (ACol==0)
  validate_avancement();
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::btDatActClick(TObject *Sender)
{
TActual *tac;
 char tmp[250];
 char isamname[250];
 char dt1[15];char dt2[15];
 int i,j,ok,indx;
 int count,rc,nt,l,cnt;
 bool flag_avanc,conc;
 char tachconcern[20];
 genbase *avanc;
 char Key[100],RetKey[100];
 int recdata;
 char buffer[1000];

 strcpy(exchange,dateavanc);
 WriteExchange(1);
 tac = new TActual(Application);
 tac->ShowModal();
 delete tac;
 ReadExchange(1);
 l=ExtractValue(tmp,exchange,"null",0);
 if (strcmp(tmp,"TRUE")==0) return;

  l=ExtractValue(dt1,exchange,"da",0);
  Label12->Caption = AnsiString(dt1);
  l=ExtractValue(tachconcern,exchange,"tc",0);
  conc=false; if (strcmp(tachconcern,"true")==0) conc=true;

  count=0;
 //strcpy(tmp,eDateAct->Text.c_str());
 //strcpy(tmp,"03-11-2004");

 rc = verifdate(dt1);
 if (rc>0) return;

 AnAvanc=AnVerif;MoisAvanc=MoisVerif;JourAvanc=JourVerif;

 sprintf(dt1,"%04d-%02d-%02d",AnAvanc,MoisAvanc,JourAvanc);

 // ou bien il existe deja un avancement, sinon, on convertit
 // en date, a partir de date au plus tot prev;

 // on nettoie la stringgrid !

 for (i=1;i<=asAvanc->ColCount;i++){for (j=1;j<=asAvanc->RowCount;j++) asAvanc->Cells[i][j]="";}
 asAvanc->RowCount=2;
 // // lecture du fichier pour trouver les avancements possibles
 // examen des dates d'avancement de toutes les taches
  cnt= Explode('@',dateavanc);
  if (cnt ==0) flag_avanc=false;
   else
     {
       avanc = new  genbase();
       strcpy(tmp,LocalBase);
       sprintf(isamname,"-%03d",cnt);
       strcat(tmp,isamname);
       rc = avanc->OpenEngine(tmp,120,"act","dat");   //512 - 8
       if (rc==0)
         {
          strcpy(tmp,"Fichier Actualisation ");
          strcat(tmp,isamname);
          strcat(tmp," non trouvé");
          Application->MessageBoxA(tmp,ecoplan,MB_OK);
          return;
         }
       rc = avanc->SetIndexMode(0,0);
       flag_avanc=true;
     }

 for (indx=1;indx<=nb_taches;indx++)
   { ok=false;
    add_jour(AnPrev,MoisPrev,JourPrev,deb_plus_tot[indx]);
    sprintf(dt2,"%04d-%02d-%02d",An,Mois,Jour);
    nt=exist_tache(indx,nb_taches);
    if (!conc) ok=true;
    else if  (strcmp(dt1,dt2) >=0) ok=true;  // tache concernee
    if (ok)
      { count++;
       if (count>1) asAvanc->RowCount++;
       asAvanc->Cells[1][count] = indx;
       nt=exist_tache(indx,nb_taches);
       asAvanc->Cells[2][count] = AdvStringGrid1->Cells[2][nt];
       asAvanc->Cells[3][count] = duree[indx]; // duree prev
       asAvanc->Cells[4][count] = AdvStringGrid1->Cells[4][nt];
       asAvanc->Cells[5][count] = AdvStringGrid1->Cells[5][nt];
       // lecture fichier isam pour les autres données
       if (flag_avanc) //
         {
          sprintf(Key,"<T%04d>",nt);
          rc = avanc->ReadDirectKey(0,Key,RetKey,&recdata);
          if (rc) // trouve
            {
             avanc->ReadRecord(buffer,recdata);
             ExtractValue(tmp,buffer,"rt",0);
             asAvanc->Cells[6][count]=tmp;
             ExtractValue(tmp,buffer,"ri",0);
             asAvanc->Cells[7][count]=tmp;
             ExtractValue(tmp,buffer,"dr",0);
             asAvanc->Cells[8][count]=tmp;
             ExtractValue(tmp,buffer,"dtr",0);
             asAvanc->Cells[9][count]=tmp;
             ExtractValue(tmp,buffer,"ftr",0);
             asAvanc->Cells[10][count]=tmp;
             ExtractValue(tmp,buffer,"cprev",0);
             asAvanc->Cells[11][count]=tmp;
             ExtractValue(tmp,buffer,"pcr",0);
             asAvanc->Cells[12][count]=tmp;
             ExtractValue(tmp,buffer,"nbjr",0);
             asAvanc->Cells[13][count]=tmp;

            }   //if rc trouvé
         } // if flag_avanc
      } // if OK

   } // for Loop

  if (flag_avanc)  { avanc->CloseEngine(); avanc->~genbase(); }
  sprintf(tmp,"%d",count);
  Label22->Caption = AnsiString(tmp);
}
//---------------------------------------------------------------------------


void __fastcall TplStandard::btSavActClick(TObject *Sender)
{
 genbase *avanc;
 // preparer nouvelle date pour string dateavanc.
 int count; char tmp[250]; char cnt[12];
 int rc; int indx; char isamname[250];
 char buffer[2000]; int tachnumber;
 char Key[100]; char RetKey[100];
 int recdata;

 count= Explode('@',dateavanc);
 //label 12, contient la date
 strcpy(tmp,Label12->Caption.c_str());
 if (strcmp(tmp,"----------")==0)
  { Application->MessageBoxA("Aucune Date Actualisation Choisie",ecoplan,MB_OK);
   return;
  }
 strcat(dateavanc,tmp);
 sprintf(tmp,"-%03d@",count+1);
 strcat(dateavanc,tmp);

 // preparer copie dans nouveau fichier Isam !
 avanc = new  genbase();
 strcpy(tmp,LocalBase);
 sprintf(cnt,"-%03d",count+1);
 strcat(tmp,cnt);

 //strcpy(isamname,tmp); strcat(isamname,".act"); unlink(isamname);
 //strcpy(isamname,tmp); strcat(isamname,".dat"); unlink(isamname);

 rc = avanc->OpenEngine(tmp,120,"act","dat");   //512 - 8
 rc = avanc->SetIndexMode(0,0);

 // preparation du buffer
 count=asAvanc->RowCount;
 for (indx=1;indx<count;indx++)
  {
   strcpy(tmp,asAvanc->Cells[1][indx].c_str());
   tachnumber=atoi(tmp);
   buffer[0]=0;
   strcat(buffer,"<nt>"); strcat(buffer,asAvanc->Cells[1][indx].c_str()); strcat(buffer,"</nt>"); //num tache
   strcat(buffer,"<rt>"); strcat(buffer,asAvanc->Cells[6][indx].c_str()); strcat(buffer,"</rt>");
   strcat(buffer,"<ri>"); strcat(buffer,asAvanc->Cells[7][indx].c_str()); strcat(buffer,"</ri>"); //num tache
   strcat(buffer,"<dr>"); strcat(buffer,asAvanc->Cells[8][indx].c_str()); strcat(buffer,"</dr>");
   strcat(buffer,"<dtr>"); strcat(buffer,asAvanc->Cells[9][indx].c_str()); strcat(buffer,"</dtr>"); //num tache
   strcat(buffer,"<ftr>"); strcat(buffer,asAvanc->Cells[10][indx].c_str()); strcat(buffer,"</ftr>");
   strcat(buffer,"<cprev>"); strcat(buffer,asAvanc->Cells[11][indx].c_str()); strcat(buffer,"</cprev>"); //num tache
   strcat(buffer,"<pcr>"); strcat(buffer,asAvanc->Cells[10][indx].c_str()); strcat(buffer,"</pcr>");
   strcat(buffer,"<nbjr>"); strcat(buffer,asAvanc->Cells[11][indx].c_str()); strcat(buffer,"</nbjr>");
   sprintf(Key,"<T%04d>",tachnumber);
   recdata=avanc->GetNewRecordNumber();
   rc = avanc->WriteKey(0,Key,recdata);
   rc = avanc->WriteRecord(buffer,strlen(buffer)+1);
  }
 rc = avanc->CloseEngine(); avanc->~genbase();
}
//---------------------------------------------------------------------------

void __fastcall TplStandard::Button1Click(TObject *Sender)
{
  char tmp[250]; int count,i;
  char cnt[10];
  char isamname[250];

 count= Explode('@',dateavanc);
 if (count >0)
  {
   for (i=1;i<=count;i++)
    { strcpy(tmp,LocalBase);
      sprintf(cnt,"-%03d",i);
      strcat(tmp,cnt);
      strcpy(isamname,tmp); strcat(isamname,".act"); unlink(isamname);
      strcpy(isamname,tmp); strcat(isamname,".dat"); unlink(isamname);
     }

  }
 dateavanc[0]=0;
}
//---------------------------------------------------------------------------

