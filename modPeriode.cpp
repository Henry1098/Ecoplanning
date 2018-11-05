//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modPeriode.h"
#include "globals.h"
#include "modghost.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPeriod *Period;
//---------------------------------------------------------------------------
__fastcall TPeriod::TPeriod(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPeriod::Button2Click(TObject *Sender)
{
strcpy(m_exchange,"");
Close();
}
//---------------------------------------------------------------------------
void __fastcall TPeriod::Button1Click(TObject *Sender)
{
 char tmp[200];

 strcpy(tmp,Edit1->Text.c_str());
 if (strlen(tmp)!=8)
    {
     Application->MessageBox("Date de début incorrecte",m_ecoplan,MB_OK);
     return;
    }
 strcpy(tmp,Edit2->Text.c_str());
 if (strlen(tmp)!=8)
    {
     Application->MessageBox("Date de fin incorrecte",m_ecoplan,MB_OK);
     return;
    }

 strcpy(m_exchange,"<dd>"); strcat(m_exchange,Edit1->Text.c_str()); strcat(m_exchange,"</dd>");
 strcat(m_exchange,"<df>"); strcat(m_exchange,Edit2->Text.c_str()); strcat(m_exchange,"</df>");
Close();
}
//---------------------------------------------------------------------------
void __fastcall TPeriod::FormShow(TObject *Sender)
{
 char tmp[50];
 Ghost->ExtractValue(tmp,m_exchange,"dd",0);
 Edit1->Text=AnsiString(tmp);
 Ghost->ExtractValue(tmp,m_exchange,"df",0);
 Edit2->Text=AnsiString(tmp);
}
//---------------------------------------------------------------------------
