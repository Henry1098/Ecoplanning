//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

// #include "modHelp.h"
#include "num_succ.h"
#include "plstd.h"
#include "globals.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNum_Tache_Succ *Num_Tache_Succ;
//---------------------------------------------------------------------------
__fastcall TNum_Tache_Succ::TNum_Tache_Succ(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNum_Tache_Succ::Button1Click(TObject *Sender)
{
  char tmp[50];
  Edit1->SetTextBuf("-1");
  Edit1->GetTextBuf(tmp,20);
  strcpy(m_exchange,"<tache>-1</tache>");
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TNum_Tache_Succ::Button2Click(TObject *Sender)
{
 char tmp[50];
  int decal;

  Edit1->GetTextBuf(tmp,20);
  strcpy(m_exchange,"<tache>");
  strcat (m_exchange,tmp);
  strcat (m_exchange,"</tache><tl>");
  int nr1 =StrToInt(Label4->Caption);
  int nr2 =StrToInt(Edit1->Text);

  if  (RadioButton1->Checked) strcat (m_exchange,"0");
    else if (RadioButton2->Checked) strcat(m_exchange,"1");
   //else if (RadioButton3->Checked) strcat(exchange,"2");
    else if (RadioButton4->Checked) strcat(m_exchange,"3");
  strcat (m_exchange,"</tl><decal>");
  Edit2->GetTextBuf(tmp,20);
  decal=atoi(tmp);
 // if ((RadioButton3->Checked) && (decal <0))
 //  {  Application->MessageBoxA("Type de lien AM (Amont) : Le décalage ne peut être négatif",
 //       "Ecoplanning 5.0",MB_OK);
 //       return;   }
if ((RadioButton4->Checked) && (decal <0))
   {  Application->MessageBoxA("Type de lien DD (Début-Début) : Le décalage ne peut être négatif",
        "Ecoplanning 5.0",MB_OK);
       return;
   }

    strcat (m_exchange,tmp);
    strcat (m_exchange,"</decal>");
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TNum_Tache_Succ::UpDown1Click(TObject *Sender,
      TUDBtnType Button)
{
 int decal;
 decal = atoi(Edit2->Text.c_str());
 if (Button == Comctrls::btNext)
   {
    decal++;
   }
 else
   { decal--;
     //if (decal < 0) decal=0;
   }
 Edit2->Text = IntToStr(decal);
}
//---------------------------------------------------------------------------


void __fastcall TNum_Tache_Succ::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TNum_Tache_Succ::FormCreate(TObject *Sender)
{
 Label4->Caption=AnsiString(m_exchange);
}
//---------------------------------------------------------------------------

void __fastcall TNum_Tache_Succ::Button3Click(TObject *Sender)
{
/*
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre27");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
 */
}
//---------------------------------------------------------------------------

