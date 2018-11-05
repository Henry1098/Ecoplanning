//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "modMarges.h"
#include "globals.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDmarges *FDmarges;
//---------------------------------------------------------------------------
__fastcall TFDmarges::TFDmarges(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDmarges::Button1Click(TObject *Sender)
{
 // prepare m_exchange
 char tmp[250];
 strcpy(tmp,"<marge>");
 P_MV1[pc]=Edit1->Text;
 P_MV2[pc]=Edit2->Text;
 P_MH1[pc]=Edit3->Text;
 P_MH2[pc]=Edit4->Text;
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDmarges::Button2Click(TObject *Sender)
{
strcpy(m_exchange,"");
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFDmarges::FormCreate(TObject *Sender)
{
 char tmp[100];

 Edit1->Text=P_MV1[pc];
 Edit2->Text=P_MV2[pc];
 Edit3->Text=P_MH1[pc];
 Edit4->Text=P_MH2[pc];

}
//---------------------------------------------------------------------------

void __fastcall TFDmarges::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"Plannings.html#Pl41");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

