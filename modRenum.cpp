//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modRenum.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRenum *Renum;
//---------------------------------------------------------------------------
__fastcall TRenum::TRenum(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRenum::AnnulerClick(TObject *Sender)
{
 strcpy(m_renum,"NO");
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TRenum::btYesClick(TObject *Sender)
{
 strcpy(m_renum,"YES");
 Close();
}
//---------------------------------------------------------------------------
