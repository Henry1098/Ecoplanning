//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "liencc.h"
#include "stdio.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLienCoche *LienCoche;
//---------------------------------------------------------------------------
__fastcall TLienCoche::TLienCoche(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLienCoche::Button1Click(TObject *Sender)
{
char tmp[100],tmp1[10];
int dec;
     m_exchange[0]=0;
     strcpy(tmp1,Edit1->Text.c_str()); dec=atoi(tmp1);
     sprintf(tmp,"<decalage>%d</decalage>",dec);
     strcat(m_exchange,tmp);
     if (RadioButton1->Checked == true) strcat(m_exchange,"<tl>0</tl>");
     if (RadioButton2->Checked == true) strcat(m_exchange,"<tl>1</tl>");
     if (RadioButton3->Checked == true) strcat(m_exchange,"<tl>3</tl>");
     if (CheckBox1->Checked == true) strcat(m_exchange,"<decoch>O</decoch>");
        else  strcat(m_exchange,"<decoch>N</decoch>");

  Close();
}
//---------------------------------------------------------------------------
void __fastcall TLienCoche::Button2Click(TObject *Sender)
{
 char tmp[10];
 m_exchange[0]=0;
 strcpy(m_exchange,"<null>TRUE</null>");
 Close();
}
//---------------------------------------------------------------------------


void __fastcall TLienCoche::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre211");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

