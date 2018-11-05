//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include "modplanches.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TPlanches *Planches;
//---------------------------------------------------------------------------
__fastcall TPlanches::TPlanches(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPlanches::btNewFieldClick(TObject *Sender)
{
 int number;
 char tmp[100];

 if (AdvF->RowCount > 1)
    AdvF->RowCount++;
    number = AdvF->RowCount - 1;
    sprintf(tmp,"C%03d",number);
    AdvF->Cells[1][number]=AnsiString(tmp);
    //AdvF->ColWidths[1]=30;
}
//---------------------------------------------------------------------------

void __fastcall TPlanches::FormCreate(TObject *Sender)
{
  int rc,recdata;
  char Key[100],RetKey[100];
  char tmp[255]; int lg;

  GetCurrentDirectory(MAX_PATH,main_directory);

  strcpy(localbase,m_directory);

  strcat(localbase,"\\champs.txt");
  AdvF->LoadFromFile(AnsiString(localbase));

  strcpy(localbase,m_directory);
  strcat(localbase,"\\volets.txt");
  AdvV->LoadFromFile(AnsiString(localbase));

  strcpy(localbase,m_directory);
  strcat(localbase,"\\planches.txt");
  AdvP->LoadFromFile(AnsiString(localbase));

  fnumber=AdvF->RowCount - 1;
  vnumber=AdvV->RowCount - 1;
  pnumber=AdvP->RowCount - 1;

  if (fnumber==0) AdvF->Cells[1][1]= "C001";
  if (vnumber==0) AdvV->Cells[1][1]= "V001";

}
//---------------------------------------------------------------------------

void __fastcall TPlanches::FormClose(TObject *Sender, TCloseAction &Action)
{
  // Question si sauvegarde

 if (change)
  {
   if (Application->MessageBoxA("Voulez-Vous Sauver les Modifications",
    "Ecoplanning",MB_YESNO)== IDYES) return;
  }
}
//---------------------------------------------------------------------------

int __fastcall TPlanches::ExtractValue(char *result, char *buff, char *tag, int posdeb)
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

void __fastcall TPlanches::btSaveClick(TObject *Sender)
{
 SaveData();
}
//---------------------------------------------------------------------------

void __fastcall TPlanches::btSaveFieldsClick(TObject *Sender)
{
 SaveData();
}
//---------------------------------------------------------------------------

int __fastcall TPlanches::SaveData()
{
  strcpy(localbase,m_directory);
  strcat(localbase,"\\champs.txt");
  AdvF->SaveToFile(AnsiString(localbase));

  strcpy(localbase,m_directory);
  strcat(localbase,"\\volets.txt");
  AdvV->SaveToFile(AnsiString(localbase));

  strcpy(localbase,m_directory);
  strcat(localbase,"\\planches.txt");
  AdvP->SaveToFile(AnsiString(localbase));

  Application->MessageBoxA("Données Sauvegardées","Ecoplanning",MB_OK);
  return 0;
}

void __fastcall TPlanches::Button2Click(TObject *Sender)
{
 int number;
 char tmp[100];

 if (AdvV->RowCount > 1)
    AdvV->RowCount++;
    number = AdvV->RowCount - 1;
    sprintf(tmp,"V%03d",number);
    AdvV->Cells[1][number]=AnsiString(tmp);
}
//---------------------------------------------------------------------------



void __fastcall TPlanches::AdvVClickCell(TObject *Sender, int ARow,
      int ACol)
{

 FILE *fp;
 char tmp[50];
 int i;

 if (ACol < 2)
  {
   strcpy(vfilename,m_directory);
   strcat(vfilename,"\\Volet");
   sprintf(tmp,"%03d",ARow);
   strcat(vfilename,tmp); strcat(vfilename,".txt");
   // Load File if it Exists
   if (FileExists(vfilename))
     {
      for (i=0;i<28;i++)
          AdvSGVolet->Cells[i][1]="";
      AdvSGVolet->LoadFromFile(AnsiString(vfilename));
     }
   else
     {
      for (i=0;i<28;i++)
          AdvSGVolet->Cells[i][1]="";

      fp = fopen(vfilename,"wt");
      fclose(fp);
      AdvSGVolet->SaveToFile(AnsiString(vfilename));
      AdvSGVolet->LoadFromFile(AnsiString(vfilename));
      sprintf(tmp,"V%03d",ARow);
      AdvSGVolet->Cells[1][1] = tmp;
     }
   Label4->Caption = AnsiString(tmp);

  }

}
//---------------------------------------------------------------------------

void __fastcall TPlanches::Button6Click(TObject *Sender)
{
 AdvSGVolet->SaveToFile(AnsiString(vfilename));
}
//---------------------------------------------------------------------------

void __fastcall TPlanches::Button1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TPlanches::Button3Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

