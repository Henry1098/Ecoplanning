//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modMiseEnPage.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TMiseEnPage *MiseEnPage;
//---------------------------------------------------------------------------
__fastcall TMiseEnPage::TMiseEnPage(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMiseEnPage::btOKClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TMiseEnPage::btAnnulClick(TObject *Sender)
{
 Close();        
}
//---------------------------------------------------------------------------

void __fastcall TMiseEnPage::btSupprClick(TObject *Sender)
{
 Application->MessageBoxA("En cours",m_ecoplan,MB_OK);       
}
//---------------------------------------------------------------------------

void __fastcall TMiseEnPage::btInsererClick(TObject *Sender)
{
 Application->MessageBoxA("En cours",m_ecoplan,MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TMiseEnPage::FormShow(TObject *Sender)
{
 int i,j,page;
 ar->RowCount = 2; page=0;
 for (i=0;i<INDXPAGE;i++)
  {
   j=i+1;
   if (i>1) ar->RowCount++;
   ar->Cells[0][j] = SPAGE[i];
   if (SPAGE[i]=='P') page++;
   ar->Cells[1][j] = AnsiString(page);
   ar->Cells[2][j] = T[i];

  }






}
//---------------------------------------------------------------------------

