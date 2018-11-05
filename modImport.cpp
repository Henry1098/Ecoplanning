//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modImport.h"
#include "globals.h"
#include "modHelp.h"
#include "modGhost.h"
#include <stdio.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TImport *Import;
//---------------------------------------------------------------------------
__fastcall TImport::TImport(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TImport::FormShow(TObject *Sender)
{
// Ghost->ExtractValue(ExtName,m_impt,"type",0);


}
//---------------------------------------------------------------------------

void __fastcall TImport::Button4Click(TObject *Sender)
{
 strcpy(ExtName,"pln");
 SelectFile();
}


void __fastcall TImport::SelectFile()
 {
 char *p;
 char PEXT[50];
 char name[250];
 AnsiString Test;

 strcpy(PEXT,"."); strcat(PEXT,ExtName);
 strlwr(PEXT);

Test =  AnsiString(m_directory) + "\\Reference\\Plannings";

if (strcmp(PEXT,".pln")==0) OpenDialog1->InitialDir = AnsiString(m_directory) + "\\Reference\\Plannings";
if (strcmp(PEXT,".tri")==0) OpenDialog1->InitialDir = AnsiString(m_directory) + "\\Reference\\Tris";
if (strcmp(PEXT,".fil")==0) OpenDialog1->InitialDir = AnsiString(m_directory) + "\\Reference\\Filtres";
if (strcmp(PEXT,".col")==0) OpenDialog1->InitialDir = AnsiString(m_directory) + "\\Reference\\Colonnes";



OpenDialog1->FileName = ""; // AnsiString(PEXT);
if (strcmp(PEXT,".pln")==0) OpenDialog1->Filter = "Plannings (.pln)|*.pln";   //*.tri;*.fil;*.col";
if (strcmp(PEXT,".tri")==0) OpenDialog1->Filter = "Tris (.tri)|*.tri";
if (strcmp(PEXT,".fil")==0) OpenDialog1->Filter = "Filtres (.fil)|*.fil";
if (strcmp(PEXT,".col")==0) OpenDialog1->Filter = "Colonnes (.col)|*.col";

if (OpenDialog1->Execute())
     {
         strcpy(name,OpenDialog1->FileName.c_str());
         p=strstr(name,PEXT);
         if (p)
          {
           if (strcmp(PEXT,".pln")==0)   Exec_Pln(name);
           if (strcmp(PEXT,".tri")==0)   Exec_Tri(name);
           if (strcmp(PEXT,".fil")==0)   Exec_Fil(name);
           if (strcmp(PEXT,".col")==0)   Exec_Col(name);
           }
          else
             {
             Application->MessageBoxA("Fichier choisi Incorrect",m_ecoplan,MB_OK);
             return;
             }
     }
 }


void __fastcall TImport::Exec_Pln(char *name)
{
char buffer [10000];

char TempKey[100],Key[100],RetKey[100];
int rc,recdata,i,nbitems;
char tmp[2000];  char *p,*p1;
char filename[250]; bool flag_insert;


FILE *fp;

fp=fopen(name,"rt");
if (fp == NULL)
  { Application->MessageBoxA("Fichier Non Trouvé",m_ecoplan,MB_OK);
    return;
  }
p=name;
p1=strchr(p,'\\');
 while (p1) { p=p1+1; p1=strchr(p,'\\'); }

strcpy(filename,p);
p=strstr(filename,".pln");
if (p==NULL)
   {
    Application->MessageBoxA("Fichier Sans Extension .pln",m_ecoplan,MB_OK);
    return;
   }
*p = 0;
strcpy(TempKey,filename);
buffer[0]=0;
bigbuf[0]=0;
fgets(buffer,9000,fp);
strcat(bigbuf,buffer);
while (!feof(fp))
 {
  if (strlen(buffer)>0)
    {
     fgets(buffer,9000,fp);
     strcat(bigbuf,buffer);
    }
 }
fclose(fp);

strcpy(filename,m_directory);  //DatabaseName);
 strcat(filename,"\\eco_plannings");

fichier = new realisam;
rc = fichier->OpenEngine(filename,1016,"ndx","dat");   //1024 - 8
rc = fichier->SetIndexMode(0,0);

strcpy(Key,TempKey); strcat(Key,"-GEN");
strcpy(temps,"<GEN>");
Ghost->ExtractValue(buffer,bigbuf,"GEN",0);
strcat(temps,buffer);
strcat(temps,"</GEN>");

rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
if (rc) rc = fichier->RewriteRecord(temps, strlen(temps)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(temps,strlen(temps)+1);
     }

strcpy(temps,"<MRG>");
Ghost->ExtractValue(buffer,bigbuf,"MRG",0);
strcat(temps,buffer);
strcat(temps,"</MRG>");
strcpy(Key,TempKey); strcat(Key,"-MRG");
 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(temps, strlen(temps)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(temps,strlen(temps)+1);
     }


strcpy(temps,"<ETT>");
Ghost->ExtractValue(buffer,bigbuf,"ETT",0);
strcat(temps,buffer);
strcat(temps,"</ETT>");
strcpy(Key,TempKey); strcat(Key,"-ETT");
 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(temps, strlen(temps)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(temps,strlen(temps)+1);
     }


strcpy(temps,"<CAL>");
Ghost->ExtractValue(buffer,bigbuf,"CAL",0);
strcat(temps,buffer);
strcat(temps,"</CAL>");
 strcpy(Key,TempKey); strcat(Key,"-CAL");
 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(temps, strlen(temps)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(temps,strlen(temps)+1);
     }

strcpy(temps,"<CDR>");
Ghost->ExtractValue(buffer,bigbuf,"CDR",0);
strcat(temps,buffer);
strcat(temps,"</CDR>");
 strcpy(Key,TempKey); strcat(Key,"-CDR");
 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(temps, strlen(temps)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(temps,strlen(temps)+1);
     }

 strcpy(temps,"<TCH>");
Ghost->ExtractValue(buffer,bigbuf,"TCH",0);
strcat(temps,buffer);
strcat(temps,"</TCH>");
 strcpy(Key,TempKey); strcat(Key,"-TCH");
 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(temps, strlen(temps)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(temps,strlen(temps)+1);
     }


 strcpy(temps,"<COR>");
Ghost->ExtractValue(buffer,bigbuf,"COR",0);
strcat(temps,buffer);
strcat(temps,"</COR>");
 strcpy(Key,TempKey); strcat(Key,"-COR");
 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(temps, strlen(temps)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(temps,strlen(temps)+1);
     }

 strcpy(temps,"<PIE>");
Ghost->ExtractValue(buffer,bigbuf,"PIE",0);
strcat(temps,buffer);
strcat(temps,"</PIE>");
 strcpy(Key,TempKey); strcat(Key,"-PIE");
 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(temps, strlen(temps)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(temps,strlen(temps)+1);
     }

fichier->CloseEngine();


// inclure dans la liste .txt

strcpy(name,m_directory); strcat(name,"\\eco_plannings.txt");
Exec_Maj_Preseance(name,TempKey);
Application->MessageBoxA("Nouveau Planning Intégré",m_ecoplan,MB_OK);
}


void __fastcall TImport::Exec_Maj_Preseance(char *name, char *Key)
{
 FILE *fp;

 char temps[200];
 char buffer[500];
 bool flag_insert;


fp=fopen(name,"rt");
if (fp == NULL) { fopen(name,"wt"); fclose(fp); fp=fopen(name,"rt"); }

 strcpy(temps,"<l>");
 strcat(temps,Key);
 strcat(temps,"</l>");
 buffer[0]=0;
 fgets(buffer,200,fp);

while (!feof(fp))
 { if (strlen(buffer)>0) { if(strstr(buffer,temps)) flag_insert = false; }
  fgets(buffer,200,fp);
 }
fclose(fp);
if (flag_insert)
  {
   fopen(name,"a+");
   strcat(temps,"\r\n");
   fputs(temps,fp);
   fclose(fp);
  }


}


void __fastcall TImport::Exec_Tri(char *name)
{

 char Key[100],RetKey[100];
 int rc,recdata,i,j,nbitems;
 char tmp[10000];
 char filename[250]; char *p,*p1;
 char buffer[20000];
 FILE *fp;
 fp=fopen(name,"rt");
 if (fp == NULL)
  { Application->MessageBoxA("Fichier Non Trouvé",m_ecoplan,MB_OK);
    return;
  }

 p=name;
p1=strchr(p,'\\');
 while (p1) { p=p1+1; p1=strchr(p,'\\'); }

strcpy(filename,p);
p=strstr(filename,".tri");
if (p==NULL)
   {
    Application->MessageBoxA("Fichier Sans Extension .tri",m_ecoplan,MB_OK);
    return;
   }
*p = 0;
strcpy(Key,filename);
buffer[0]=0;
bigbuf[0]=0;
fgets(buffer,9000,fp);
strcat(bigbuf,buffer);
while (!feof(fp))
 {
  if (strlen(buffer)>0)
    {
     fgets(buffer,9000,fp);
     strcat(bigbuf,buffer);
    }
 }
fclose(fp);
strcpy(buffer,bigbuf);

 fichier = new realisam;
 strcpy(filename,m_directory); strcat(filename,"\\eco_tri");
 rc = fichier->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = fichier->SetIndexMode(0,0);

 // preparer buffer





 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(buffer, strlen(buffer)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(buffer,strlen(buffer)+1);
     }
fichier->CloseEngine();
strcpy(name,m_directory); strcat(name,"\\eco_tri.txt");
Exec_Maj_Preseance(name,Key);
Application->MessageBoxA("Nouveau Tri Intégré",m_ecoplan,MB_OK);


}

void __fastcall TImport::Exec_Fil(char *name)
{

 char Key[100],RetKey[100];
 int rc,recdata,i,j,nbitems;
 char tmp[10000];
 char filename[250];  char *p1,*p;
 char buffer[20000];
 FILE *fp;
 fp=fopen(name,"rt");
 if (fp == NULL)
  { Application->MessageBoxA("Fichier Non Trouvé",m_ecoplan,MB_OK);
    return;
  }


 p=name;
p1=strchr(p,'\\');
 while (p1) { p=p1+1; p1=strchr(p,'\\'); }

strcpy(filename,p);
p=strstr(filename,".fil");
if (p==NULL)
   {
    Application->MessageBoxA("Fichier Sans Extension .fil",m_ecoplan,MB_OK);
    return;
   }
*p = 0;
strcpy(Key,filename);
buffer[0]=0;
bigbuf[0]=0;
fgets(buffer,9000,fp);
strcat(bigbuf,buffer);
while (!feof(fp))
 {
  if (strlen(buffer)>0)
    {
     fgets(buffer,9000,fp);
     strcat(bigbuf,buffer);
    }
 }
fclose(fp);
strcpy(buffer,bigbuf);


 fichier = new realisam;
 strcpy(filename,m_directory); strcat(filename,"\\eco_filtres");
 rc = fichier->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = fichier->SetIndexMode(0,0);

 // preparer buffer





 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(buffer, strlen(buffer)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(buffer,strlen(buffer)+1);
     }
fichier->CloseEngine();
strcpy(name,m_directory); strcat(name,"\\eco_filtres.txt");
Exec_Maj_Preseance(name,Key);
Application->MessageBoxA("Nouveau Filtre Intégré",m_ecoplan,MB_OK);





}

void __fastcall TImport::Exec_Col(char *name)
{
 char Key[100],RetKey[100];
 int rc,recdata,i,j,nbitems;
 char tmp[10000];  char *p,*p1;
 char filename[250];
 char buffer[20000];
 FILE *fp;

 fp=fopen(name,"rt");
 if (fp == NULL)
  { Application->MessageBoxA("Fichier Non Trouvé",m_ecoplan,MB_OK);
    return;
  }
 p=name;
p1=strchr(p,'\\');
 while (p1) { p=p1+1; p1=strchr(p,'\\'); }

strcpy(filename,p);
p=strstr(filename,".col");
if (p==NULL)
   {
    Application->MessageBoxA("Fichier Sans Extension .col",m_ecoplan,MB_OK);
    return;
   }
*p = 0;
strcpy(Key,filename);
buffer[0]=0;
bigbuf[0]=0;
fgets(buffer,9000,fp);
strcat(bigbuf,buffer);
while (!feof(fp))
 {
  if (strlen(buffer)>0)
    {
     fgets(buffer,9000,fp);
     strcat(bigbuf,buffer);
    }
 }
fclose(fp);
strcpy(buffer,bigbuf);


fichier = new realisam;
 strcpy(filename,m_directory); strcat(filename,"\\eco_col");
 rc = fichier->OpenEngine(filename,248,"ndx","dat");   //256 - 8
 rc = fichier->SetIndexMode(0,0);

 // preparer buffer





 rc = fichier->ReadDirectKey(0,Key,RetKey,&recdata);
 if (rc) rc = fichier->RewriteRecord(buffer, strlen(buffer)+1,recdata);
     else
     { recdata=fichier->GetNewRecordNumber();
       rc = fichier->WriteKey(0,Key,recdata);
       rc = fichier->WriteRecord(buffer,strlen(buffer)+1);
     }
fichier->CloseEngine();
strcpy(name,m_directory); strcat(name,"\\eco_col.txt");
Exec_Maj_Preseance(name,Key);
Application->MessageBoxA("Nouvelle Description Colonnes Intégrée",m_ecoplan,MB_OK);

}
//---------------------------------------------------------------------------

void __fastcall TImport::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------


void __fastcall TImport::Button1Click(TObject *Sender)
{
strcpy(ExtName,"tri");
 SelectFile();
}
//---------------------------------------------------------------------------

void __fastcall TImport::Button5Click(TObject *Sender)
{
strcpy(ExtName,"fil");
 SelectFile();
}
//---------------------------------------------------------------------------

void __fastcall TImport::Button6Click(TObject *Sender)
{
strcpy(ExtName,"col");
SelectFile();
}
//---------------------------------------------------------------------------

