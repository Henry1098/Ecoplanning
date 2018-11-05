//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modBandes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDbandes *FDbandes;
//---------------------------------------------------------------------------
__fastcall TFDbandes::TFDbandes(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDbandes::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFDbandes::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

