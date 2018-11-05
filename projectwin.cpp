//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "projectwin.h"
#include "globals.h"
#include "modHelp.h"
#include <stdio.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TfProjet *fProjet;
//---------------------------------------------------------------------------
__fastcall TfProjet::TfProjet(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfProjet::btSaveContClick(TObject *Sender)
{
  char tmp[512];



  if (strlen(m_importtaches)==0)
    {
     if (strlen(m_exchange) !=0)
        {
          Application->MessageBox("Pas de nom pour le fichier import .csv",m_ecoplan,MB_OK);
          return;
        }
    }
  strcpy(tmp,ENomProj->Text.c_str());

  if (strlen(tmp)==0)
    {
     Application->MessageBox("Pas de nom code pour le nouveau projet",m_ecoplan,MB_OK);
     return;
    }


  LASTTASK=0;
  if (SaveProject()== 0)  Close();
  LASTTASK=0;
}
//---------------------------------------------------------------------------



int __fastcall TfProjet::SaveProject()
{
   // consiste a stocker dans le fichier projet les nouvelles
   // caracteristiques
 int status = 0;
 char  dbname[255];
 char  dbnameext[255];
 int rc;
 int taches;
 char tmp[2500];  AnsiString Sdir;



 char retkey[100];
 char Key[20];
 int recdata;

 if (strcmp(m_exchange,"import")==0)
   {
    if (strlen(m_importtaches)==0 || strlen(m_importliaisons)==0)
      {
       Application->MessageBoxA("Cliquer sur le bouton Importer Fichiers Ecoplanning 4 avant de terminer",m_ecoplan,MB_OK);
       return 1;
      }
   }

 ENomProj->GetTextBuf(dbname,250);
 if (strlen(dbname)==0) { ShowMessage("Pas de Nom de Projet"); return 1;  }
 if (!Control_ValidField(dbname,"Nom de Projet")) return 1;

 //  strcpy(dbnameext,Directory.c_str());
 strcpy(dbnameext,Label3->Caption.c_str());
 Sdir = AnsiString(dbnameext);
 if (!DirectoryExists(Sdir))
    CreateDir(Sdir);

 strcat(dbnameext,"\\");





 strcat(dbnameext,dbname);
 strcpy(DatabaseName,dbnameext);



 strcat(dbnameext,".eco");
 if (FileExists(AnsiString (dbnameext)))
   {
    ShowMessage("Le Nom de Projet existe déjà");
    return 1;
   }

 newproj = new realisam();
 rc = newproj->OpenEngine(dbnameext,120,"eco","dat");   //512 - 8
 rc = newproj->SetIndexMode(0,0);
 if (rc<=0) { ShowMessage("Error Opening Ecobase database"); return 1; }

 taches=0;

     // ce nom sera transmis au gestionnaire

// code de la base
strcpy(Key,"<dbcode>"); recdata=newproj->GetNewRecordNumber();
rc = newproj->WriteKey(0,Key,recdata);
rc = newproj->WriteRecord(dbname,strlen(dbname)+1);

// titre de la base
strcpy(Key,"<dbtitre>"); recdata=newproj->GetNewRecordNumber();
rc = newproj->WriteKey(0,Key,recdata);
eTitre->GetTextBuf(tmp,250);
rc = newproj->WriteRecord(tmp,strlen(tmp)+1);
strcpy(TITRE,tmp);
Memo1->GetTextBuf(tmp,1800);
strcpy(OBSERV,tmp);
strcpy(Key,"<dbobserv>"); recdata=newproj->GetNewRecordNumber();
rc = newproj->WriteKey(0,Key,recdata);
rc = newproj->WriteRecord(OBSERV,strlen(OBSERV)+1);

// date previsionnelle
strcpy(Key,"<dateprevdebut>"); recdata=newproj->GetNewRecordNumber();
rc = newproj->WriteKey(0,Key,recdata);
eDebPrev->GetTextBuf(tmp,250);
rc = newproj->WriteRecord(tmp,strlen(tmp)+1);

// nombre de taches

strcpy(Key,"<taches>"); recdata=newproj->GetNewRecordNumber();
rc = newproj->WriteKey(0,Key,recdata);
sprintf(tmp,"%04d",taches);
rc = newproj->WriteRecord(tmp,strlen(tmp)+1);


// Taches par defaut

for (int i=1;i<=taches;i++)
  {
   sprintf(Key,"<T%04d>",i);
   recdata=newproj->GetNewRecordNumber();
   rc = newproj->WriteKey(0,Key,recdata);
   sprintf(tmp,"<T>%d</T><nom>Tache %d</nom><duree>1</duree>",i,i);
   rc = newproj->WriteRecord(tmp,strlen(tmp)+1);
   // creer predecesseurs et successeurs vides
       sprintf(Key,"<PR%04d>",i);
       recdata=newproj->GetNewRecordNumber();
       rc = newproj->WriteKey(0,Key,recdata);
       sprintf(tmp,"<PR%04d></PR%04d>",i,i);
       rc = newproj->WriteRecord(tmp,strlen(tmp)+1);
       sprintf(Key,"<SU%04d>",i);
       recdata=newproj->GetNewRecordNumber();
       rc = newproj->WriteKey(0,Key,recdata);
       sprintf(tmp,"<SU%04d></SU%04d>",i,i);
       rc = newproj->WriteRecord(tmp,strlen(tmp)+1);

  }

 rc = newproj->CloseEngine(); newproj->~realisam();
 Cancel=0;
 return status;
}


bool __fastcall TfProjet::Control_ValidField(char *fld,char *txt)
{
 char sep[100]; char cc[2];
 int i; bool retval; char mess[2000];
 strcpy(sep,"&é\"'{([|è`\\ç^à@)]}=+°\r\n€êâîôûäëïôüÿ£$¤%ùµ*?.,;/:§!");
 retval = true;
 for (i=0;i<strlen(fld);i++)
   {
    cc[0] = fld[i]; cc[1]=0;
    if (strstr(sep,cc))
      {
       strcpy(mess,"Champ "); strcat(mess,txt);
       strcat(mess," - Caractère Invalide : '"); strcat(mess,cc); strcat(mess,"'");
       Application->MessageBoxA(mess,m_ecoplan,MB_OK);
       retval=false;
       break;
      }
   }

 return retval;

}




void __fastcall TfProjet::FormCreate(TObject *Sender)
{

 int rc;
 int recdata;
 char RetKey[100];
 char buffer[2048];

 TDateTime dtPresent = Now();
 MonthCalendar1->Date = dtPresent;
 rc = db->ReadFirstKey(0,RetKey,&recdata);
 while (rc)
   {
    rc = db->ReadRecord(buffer,recdata);  // read record in buffer
    buffer[rc]=0;
    // insert record in the list box if type = PLANCHE
    // if (strstr(buffer,"PL:"))lbPlanches->Items->Add(buffer);
    rc = db->ReadNextKey(RetKey,&recdata);
   }

 eDebPrev->Text = DateToStr(Now());
 Directory = GetCurrentDir();
 Label3->Caption = DirectoryListBox1->Directory;
 btImport->Visible = false;
 Button2->Visible=false;
 ModeImport=0;
 if (strcmp(m_exchange,"import")==0)
    {ModeImport=1;
     btImport->Visible=true;
     Button2->Visible = true;
    }
 if (strcmp(m_exchange,"importCSV")==0)
    { ModeImport=2;
      btImport->Visible=true;
      btImport->Caption = "Importer Fichiers CSV";
      //Button2->Visible = true;
      //Button2->Caption = "Importer Critères";
     }
 strcpy(m_importtaches,""); strcpy(m_importliaisons,"");
 strcpy(m_importcriteres,"");
 }
//---------------------------------------------------------------------------





void __fastcall TfProjet::FormClose(TObject *Sender, TCloseAction &Action)
{
 //  just do nothing
 int a=0;
}
//---------------------------------------------------------------------------



void __fastcall TfProjet::Button1Click(TObject *Sender)
{
 Cancel = 1;
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TfProjet::MonthCalendar1Click(TObject *Sender)
{
  eDebPrev->Text = MonthCalendar1->Date;

}
//---------------------------------------------------------------------------

void __fastcall TfProjet::DirectoryListBox1Click(TObject *Sender)
{
  // Fonction du drive
 int index;
 //char CurrentDirectory[250];
 index = DirectoryListBox1->ItemIndex;
 if (index != -1)
    {
     try {
           Directory = DirectoryListBox1->GetItemPath(index);
           Label3->Caption = Directory;
         }
     catch (...)
          {
           Application->MessageBoxA("Erreur dans sélection Lecteur",m_ecoplan,MB_OK); //"Folder Selection","Exception : Drive Not ready",MB_OK);

          }
    }


}
//---------------------------------------------------------------------------

void __fastcall TfProjet::DriveComboBox1Change(TObject *Sender)
{
 char tmp[20];  char x;
 try {
        DirectoryListBox1->Drive = DriveComboBox1->Drive;
        x=DriveComboBox1->Drive;
        tmp[0]=x-32; tmp[1]=0; strcat(tmp,":\\");
        Label3->Caption = AnsiString(tmp);
     }
 catch (...)
     {
      Application->MessageBoxA("Erreur dans sélection Lecteur",m_ecoplan,MB_OK); //"Fo
     }
}
//---------------------------------------------------------------------------

void __fastcall TfProjet::btImportClick(TObject *Sender)
{

 strcpy(m_importtaches,"");
 strcpy(m_importliaisons,"");
 strcpy(m_importcriteres,"");

 if (ModeImport==1)
   {
     Application->MessageBoxA("Sélectionner le fichier des TACHES dans un Répertoire",m_ecoplan,MB_OK);
     OpenDialog1->FileName = "TACHES.txt";
     OpenDialog1->InitialDir = AnsiString(m_directory); //("C:\\ECOWIN"); //AnsiString(m_directory);
     if (OpenDialog1->Execute())
      {
      strcpy(m_importtaches,OpenDialog1->FileName.c_str());
      Application->MessageBoxA("Sélectionner le fichier des LIAISONS dans un Répertoire",m_ecoplan,MB_OK);
      OpenDialog1->FileName = "LIAISONS.txt";
      OpenDialog1->InitialDir = AnsiString(m_directory); // "C:\\ECOWIN");
      if (OpenDialog1->Execute())
       {
        strcpy(m_importliaisons,OpenDialog1->FileName.c_str());
        Application->MessageBoxA("Cliquer Sauvegarder/Continuer",m_ecoplan,MB_OK);
       }
    }
  }

 if (ModeImport==2)
   {
     strcpy(m_importtaches,"");
     strcpy(m_importcriteres,"");
     Application->MessageBoxA("Sélectionner le fichier _projet.csv dans un Répertoire",m_ecoplan,MB_OK);
     OpenDialog1->FileName = "*_projet.csv";
     OpenDialog1->InitialDir = AnsiString(m_directory); //("C:\\ECOWIN"); //AnsiString(m_directory);
     if (OpenDialog1->Execute())
      {
       strcpy(m_importtaches,OpenDialog1->FileName.c_str());
       Application->MessageBoxA("Sélectionner le fichier _criteres.csv dans un Répertoire",m_ecoplan,MB_OK);
       OpenDialog1->FileName = "*_criteres.csv";
       OpenDialog1->InitialDir = AnsiString(m_directory); // "C:\\ECOWIN");
       if (OpenDialog1->Execute())
       {
        strcpy(m_importcriteres,OpenDialog1->FileName.c_str());
        Application->MessageBoxA("Pour continuer, Cliquer Sauvegarder/Continuer",m_ecoplan,MB_OK);
       }
    }


   }
}
//---------------------------------------------------------------------------

void __fastcall TfProjet::btHelpClick(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre01");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

void __fastcall TfProjet::Button2Click(TObject *Sender)
{

 strcpy(m_importtaches,m_directory);
 strcpy(m_importliaisons,m_directory);
 strcpy(m_importcriteres,m_directory);

 strcat(m_importtaches,"\\TACHES.TXT");
 strcat(m_importliaisons,"\\LIAISONS.TXT");
 strcat(m_importcriteres,"\\CRITERES.TXT");

 /*

 Application->MessageBoxA("Sélectionner le fichier des TACHES ",m_ecoplan,MB_OK);
 OpenDialog1->FileName = "TACHES.txt";
 OpenDialog1->InitialDir = AnsiString(m_directory); //AnsiString(m_directory);
    if (OpenDialog1->Execute())
     {
      strcpy(m_importtaches,OpenDialog1->FileName.c_str());
      Application->MessageBoxA("Sélectionner le fichier des LIAISONS",m_ecoplan,MB_OK);
      OpenDialog1->FileName = "LIAISONS.txt";
      OpenDialog1->InitialDir = AnsiString(m_directory);
      if (OpenDialog1->Execute())
       {
        strcpy(m_importliaisons,OpenDialog1->FileName.c_str());
        Application->MessageBoxA("Sélectionner le fichier CRITERES",m_ecoplan,MB_OK);
        OpenDialog1->FileName = "LIAISONS.txt";
        OpenDialog1->InitialDir = AnsiString(m_directory);
        if (OpenDialog1->Execute())
          {
           strcpy(m_importcriteres,OpenDialog1->FileName.c_str());
          }
        Application->MessageBoxA("Cliquer Sauver/Continuer",m_ecoplan,MB_OK);
       }
   }
 */

  Application->MessageBoxA("Cliquer Sauver/Continuer",m_ecoplan,MB_OK);
}

//---------------------------------------------------------------------------

void __fastcall TfProjet::ENomProjExit(TObject *Sender)
{
 char newdir[MAX_PATH];
 // strcpy(newdir,m_directory); strcat(newdir,"\\");
 strcpy(newdir,Directory.c_str());  strcat(newdir,"\\");
 strcat(newdir,ENomProj->Text.c_str());
 Label3->Caption = AnsiString(newdir);
}
//---------------------------------------------------------------------------

