//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modhelp.h"
#include "modRempl.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRemplTC *RemplTC;
//---------------------------------------------------------------------------
__fastcall TRemplTC::TRemplTC(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRemplTC::Button2Click(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TRemplTC::Button1Click(TObject *Sender)
{
 strcpy(m_exchange,"<src>"); strcat(m_exchange,eMask->Text.c_str());
 strcat(m_exchange,"</src><dst>"); strcat(m_exchange,eMot->Text.c_str());
 strcat(m_exchange,"</dst>");
 Close();
 }

//---------------------------------------------------------------------------

void __fastcall TRemplTC::FormClose(TObject *Sender, TCloseAction &Action)
{
 //strcpy(m_exchange,"");
 Close();       
}
//---------------------------------------------------------------------------

void __fastcall TRemplTC::FormCreate(TObject *Sender)
{
 strcpy(m_exchange,"");        
}
//---------------------------------------------------------------------------

void __fastcall TRemplTC::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre54");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

