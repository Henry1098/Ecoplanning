//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modDOC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TDOC *DOC;
//---------------------------------------------------------------------------
__fastcall TDOC::TDOC(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDOC::Button1Click(TObject *Sender)
{
 Close();        
}
//---------------------------------------------------------------------------
void __fastcall TDOC::Button2Click(TObject *Sender)
{
CppWebBrowser1->ExecWB(Shdocvw_tlb::OLECMDID_PRINT, Shdocvw_tlb::OLECMDEXECOPT_PROMPTUSER);
}
//---------------------------------------------------------------------------
