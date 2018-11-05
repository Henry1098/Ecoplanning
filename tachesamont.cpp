//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tachesamont.h"
#include "globals.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma resource "*.dfm"
TfTachesAmont *fTachesAmont;
//---------------------------------------------------------------------------
__fastcall TfTachesAmont::TfTachesAmont(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfTachesAmont::Button2Click(TObject *Sender)
{
char tmp[10];
 m_exchange[0]=0;
 strcpy(m_exchange,"<null>TRUE</null>");
 Close();
}
//---------------------------------------------------------------------------


void __fastcall TfTachesAmont::UpDown1Click(TObject *Sender,
      TUDBtnType Button)
{
 int nbtach;
 nbtach = atoi(Edit1->Text.c_str());
 if (Button == Comctrls::btNext)
   {
    nbtach++;
    if (nbtach > 10) nbtach=10;
   }
 else
   { nbtach--;
     if (nbtach < 0) nbtach=0;
   }
 Edit1->Text = IntToStr(nbtach);
}

//---------------------------------------------------------------------------

void __fastcall TfTachesAmont::UpDown2Click(TObject *Sender,
      TUDBtnType Button)
{
 int dur;
 dur = atoi(Edit2->Text.c_str());
 if (Button == Comctrls::btNext)
   {
    dur++;
    if (dur > 30) dur=30;
   }
 else
   { dur--;
     if (dur < 0) dur=0;
   }
 Edit2->Text = IntToStr(dur);
}
//---------------------------------------------------------------------------

void __fastcall TfTachesAmont::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TfTachesAmont::FormCreate(TObject *Sender)
{
 tache_mere=atoi(m_exchange);
 strcpy(ecoplan,"Ecoplanning 5.0");
 Label5->Caption = AnsiString(tache_mere);
 Label6->Caption = AnsiString(m_exchange2);
}
//---------------------------------------------------------------------------

void __fastcall TfTachesAmont::Button1Click(TObject *Sender)
{
 // preparer exchange 1
 char tmp[250]; int i;

 strcpy(tmp,Edit1->Text.c_str());
 i=atoi(tmp);
 if (i<1 || i> 10)
   {
   Application->MessageBoxA("Nombre de tâches incorrect",ecoplan,MB_OK);
   return;
   }
 strcpy(m_exchange,"<nbt>"); strcat(m_exchange,tmp); strcat(m_exchange,"</nbt><dur>");
 strcpy(tmp,Edit2->Text.c_str());
 i=atoi(tmp);
 if (i<0  || i>30)
   {
   Application->MessageBoxA("Durée tâches incorrecte",ecoplan,MB_OK);
   return;
   }
 strcat(m_exchange,tmp); strcat(m_exchange,"</dur><design>");
 if (CheckBox1->Checked == true) strcat(m_exchange,"same");
    else strcat(m_exchange,"other");
 strcat(m_exchange,"</design>");
 Close();

}
//---------------------------------------------------------------------------

