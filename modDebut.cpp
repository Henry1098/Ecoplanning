//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "globals.h"
#include "modDebut.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDateProjet *DateProjet;
//---------------------------------------------------------------------------
__fastcall TDateProjet::TDateProjet(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDateProjet::Button3Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TDateProjet::Button1Click(TObject *Sender)
{
 if (Application->MessageBoxA("Voulez-Vous Modifier la Date de Début Prévisionnelle ?",
       m_ecoplan,MB_YESNO)==IDNO) return;


 // Envoyer nlle date a plStd;

 strcpy(m_dateprev,eDebPrev->Text.c_str());

 Close();
}
//---------------------------------------------------------------------------

void __fastcall TDateProjet::FormCreate(TObject *Sender)
{
 char tmp[50];
 sprintf(tmp,"%02d/%02d/%04d",JourPrev,MoisPrev,AnPrev);
 eDebPrev->Text=AnsiString(tmp);
 TDateTime dtPresent = Now();
 MonthCalendar1->Date = dtPresent;
// eDebPrev->Text = DateToStr(Now());
}
//---------------------------------------------------------------------------


void __fastcall TDateProjet::MonthCalendar1Click(TObject *Sender)
{
 eDebPrev->Text=MonthCalendar1->Date;
}
//---------------------------------------------------------------------------

void __fastcall TDateProjet::Button2Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre42");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

