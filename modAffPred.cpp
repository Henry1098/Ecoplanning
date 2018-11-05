//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "modHelp.h"
#include "modAffPred.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAffPred *AffPred;
//---------------------------------------------------------------------------
__fastcall TAffPred::TAffPred(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAffPred::Button2Click(TObject *Sender)
{
 strcpy(m_exchange,"");
 Close();
}
//---------------------------------------------------------------------------

void __fastcall TAffPred::Button1Click(TObject *Sender)
{
 strcpy(m_exchange,"<tache>"); strcat(m_exchange,Edit2->Text.c_str()); strcat(m_exchange,"</tache>");
 strcat(m_exchange,"<decal>"); strcat(m_exchange,Edit1->Text.c_str()); strcat(m_exchange,"</decal>");
 strcat(m_exchange,"<type>");
 if (rb1->Checked==true) strcat(m_exchange,"FD");
 if (rb2->Checked==true) strcat(m_exchange,"FF");
 if (rb3->Checked==true) strcat(m_exchange,"DD");
 strcat(m_exchange,"</type>");
 if (CheckBox1->Checked == true) strcat(m_exchange,"<decoch>O</decoch>");
    else strcat(m_exchange,"<decoch>N</decoch>");


Close();
}
//---------------------------------------------------------------------------

void __fastcall TAffPred::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre212");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

