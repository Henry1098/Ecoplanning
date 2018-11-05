//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "modHelp.h"
#include "modStyle.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDStyle *FDStyle;
//---------------------------------------------------------------------------
__fastcall TFDStyle::TFDStyle(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDStyle::Button2Click(TObject *Sender)
{
 m_exchange[0]=0;
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDStyle::Button1Click(TObject *Sender)
{
 if (cbStyle->Text=="")
   { Application->MessageBoxA("Aucun style sélectionné",m_ecoplan,MB_OK);
     return;
   }
 strcpy(m_exchange,"<style>");
 strcat(m_exchange,cbStyle->Text.c_str());
 strcat(m_exchange,"</style>");
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDStyle::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Planning.html#pl451");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

