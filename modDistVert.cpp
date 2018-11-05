//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modHelp.h"
#include "modDistVert.h"
#include "globals.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDDistH *FDDistH;
//---------------------------------------------------------------------------
__fastcall TFDDistH::TFDDistH(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFDDistH::Button1Click(TObject *Sender)
{
 char tmp[50];  int a;
 strcpy(tmp,Edit1->Text.c_str());
 a = atoi(tmp);
 if (a<=0)
    {
     Application->MessageBoxA("Valeur Incorrecte",m_ecoplan,MB_OK);
     return;
    }
 P_CDV[0]=Edit1->Text;
 P_CDVV[0] = a;
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDDistH::Button2Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFDDistH::FormShow(TObject *Sender)
{
 Edit1->Text = P_CDV[0];
       
}
//---------------------------------------------------------------------------
void __fastcall TFDDistH::Button3Click(TObject *Sender)
{
Thelp *Aide;
 strcpy(m_help,"CreatModif.html#Cre6");
 Aide = new Thelp(Application);
 Aide->ShowModal();
 delete Aide;
}
//---------------------------------------------------------------------------

