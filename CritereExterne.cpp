//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CritereExterne.h"
#include "modCriteres.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::asCritCanEditCell(TObject *Sender, int ARow,
      int ACol, bool &CanEdit)
{
 CanEdit=false;
 if (ARow < 1) return;
 if (ACol < 3) return;
 CanEdit=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::asCritClickCell(TObject *Sender, int ARow,
      int ACol)
{
if (ARow==0) return
 DispCritere(ARow,ACol);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btAccCritClick(TObject *Sender)
{
 TCriteres *Criteres;
 Criteres = new TCriteres(Application);
 Criteres->Height=773;
 Criteres->Width=905;
 Criteres->ShowModal();
 delete Criteres;
}
//---------------------------------------------------------------------------
